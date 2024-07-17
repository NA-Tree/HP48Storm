#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <cmath>

using namespace std;

/* Constants */

#define E 2.71828182845904523536028747135266249775724709369995
#define PI 4 * atan(1)
#define EPSILON 0.000000000000001


/* Modes */

// 0: degrees
// 1: radians
// 2: gradians
int trigMode = 0;

// 0: Cartesian
// 1: Polar
// 2: Shperical
// 3: Hyperbolic
int coordMode = 0;

// 0: Decimal
// 1: Hexidecimal
// 2: Binary
// 3: Octal
// 4: Custom
int baseMode = 0;


/* Elementary Functions */

long double sum(long double input1, long double input2)
{
    //adding the inputs and returning the result
    return input1 + input2;
}

long double product(long double input1, long double input2)
{
    //multiplying the two inputs and returning the result
    return input1 * input2;
}

long double division(long double input1, long double input2)
{
    long double result = 0;
    // checking for 0, if it is, then result will still be 0 upon return
    if(input2)
    {
        //returning the division of the two inputs
        result = input1 / input2;
    }
    else
    {
        cout << "divide by 0 error" << endl << "answer will not be accurate" << endl;
    }

    return result;
}

long double naturalExp(long double input)
{
    // returning the exponentiation of e^input
    return pow(E, input);
}

long double baseTenExp(long double input)
{
    // returning the exponentiation of 10^input
    return pow(10, input);
}

long double logBase(long double base, long double input)
{
    long double result = 0;

    //checking for inputs above 0 for a real solution
    //this function will not return complex results
    if(base > 0 && input > 0)
    {
        //returns the result of log_base(input)
        result = log(input) / log(base);
    }

    return result;
}

/* Parsing/evalutation*/

string removeWhiteSpace(string input)
{
    // Creating a string containing multiple whitespaces.
    string evaluation = input;

    // Using the erase, remove_if, and ::isspace functions.
    evaluation.erase(remove_if(evaluation.begin(), evaluation.end(), ::isspace), evaluation.end());

    return evaluation;
}

// arguments: the start of the expression, the end of the expression, and the string it is to be replaced with
string expressionInject(string inputString, int BOE, int EOE, string injection)
{
    // because the functions start at 1 instead of 0, we shift up by one place
    BOE++;
    EOE++;

    int i = 0;
    int sizeOfInj = injection.size();
    string evaluation = "";
    evaluation[0] = ' ';
    
    //copy the beginning of the expression and exclude 
    //the beginning of the expression that is to be replaced
    evaluation.append(inputString, 0, BOE - 1);
    //copy the injection in place of the phrase
    evaluation.append(injection);
    //copy the rest of the expression
    evaluation.append(inputString, EOE);
    // add an end byte for enssurance of the string ending
    evaluation.append("\0"); 

    return evaluation;
}

//returns amount of open and closed parentheses
int countParentheses(string input)
{
    int opened = 0;
    int closed = 0;
    int amount = -1;

    int i = 0;
    for(i = 0; i < input.size(); i++)
    {
        if(input.at(i) == '(')
        {
            opened++;
        }
        else if(input.at(i) == ')')
        {
            closed++;
        }
    }

    if(opened == closed)
    {
        amount = closed;
    }

    return amount;
}

// arguments: the input string and the place of the closing parentheses 
// that you want the place of it's matching open parentheses
int findPrevParenth(string input, int closeParenthPlace)
{
    int closeLoc = closeParenthPlace;
    int i;

    if(input.size() < closeLoc)
    {
        //if the evaluation place is out of bounds, 
        //it will evaluate with the largest in bound location
        closeLoc = input.size()-1;
    }
    
    //if closeLoc is the close parenth. the largest it can be is closLoc - 1
    i = closeLoc - 1;

    while(input.at(i) != '(' && 0 != i)
    {  
        i--;
    }

    return i;
}

bool isConst(string input)
{
    int i = 0;

    //used to check for more than one '.'
    int decimalCounter = 0;

    //an empty string is not a constant
    if(input.size() == 0)
    {
        return false;
    }

    //check each character in the string
    for(i = 0; i < input.size(); i++)
    {

        //ignore the '-' at the beginnning of a negative number
        if(i == 0 && input.at(i) == '-')
        {
            i++;
        }

        // checks for multiple decimal points 
        // confirms that the character it is checking is within bounds
        if(i < input.size() && input.at(i) == '.')
        {
            if(decimalCounter)
            {
                return false;
            }
            else
            {
                decimalCounter++;
            }
        }

        // "i >= input.size()" would only occur if the string was literally "-"
        // checks each character to see if it's a valid character type
        if(i >= input.size() || !isdigit(input.at(i)) && input.at(i) != '.')
        {
            return false;
        }

    }

    //if nothing was flagged to be false, return true
    return true;

}

//finds the position of the beginning character of the constant 
//before the operator (which is located at operatorPlace) for string input
int prevConstStrtLoc(string input, int operatorPlace)
{
    // this functions assumes there are constants on both side of the operator
    // and all '-' operators are turned into '+-'
    int i;
    int beginningOfNumber;

    //goes backwards and finds the moment the string is no longer just a constant
    for(i = operatorPlace - 1; i >= 0; i--)
    {
        if(isdigit(input.at(i)) || input.at(i) == '-' || input.at(i) == '.')
        {
            beginningOfNumber = i;
        }
        else
        {
            // returns the location of the beginning of the number early
            return beginningOfNumber;
        }
    }

    // returns the location of the beginning of the number
    return beginningOfNumber;
}

//finds the constant before an operator (which is located at operatorPlace) for string input
//retured as a long double
long double constantBefore(string input, int operatorPlace)
{
    // finds the constant a
    long double constant = stold(input.substr(prevConstStrtLoc(input, operatorPlace), operatorPlace));
    return constant;
}

//finds the position of the end character of the constant 
//after the operator (which is located at operatorPlace) for string input
int prevConstEndLoc(string input, int operatorPlace)
{
    string number;
    int i;
    int endOfNumber;

    //goes through the string and finds the moment the string is no longer just a constant
    for(i = operatorPlace + 1; i < input.size(); i++)
    {

        if(isdigit(input.at(i)) || input.at(i) == '-' || input.at(i) == '.')
        {
            endOfNumber = i;
        }
        else
        {
            // returns the location of the beginning of the number early
            return endOfNumber;
        }

    }

    // returns the location of the beginning of the number
    return endOfNumber;
}

//finds the constant before an operator (which is located at operatorPlace) for string input
//retured as a long double
long double constantAfter(string input, int operatorPlace)
{
    //isolates the constant in string form
    string substr = input.substr(operatorPlace + 1, prevConstEndLoc(input, operatorPlace));
    //appends an end byte to ensure saftey
    substr = substr.append(1u, '\0');
    //returns the constant after it's converted to a long double
    return stold(substr);
}

//converts all - operators into +- (the addition of a negative)
string subToAddNeg(string input)
{
    string evaluation = input;
    int i = 0;
    
    //checks if there is a random '+' with nothing on it's left side (and corrects it)
    if(evaluation.at(0) == '+')
    {
        evaluation = expressionInject(evaluation, 0, 0, "");
    }

    //checks if there is a random '+' or '-' with nothing on it's right side (and corrects it)
    if(evaluation.at(evaluation.size()-1) == '+' || evaluation.at(evaluation.size()-1) == '-')
    {
        evaluation = expressionInject(evaluation, evaluation.size()-1, evaluation.size()-1, "");
    }

    //looks at each character and looks to see if it's a minus operator
    //with characters indicative of constants on both sides
    for(i = 1; i < evaluation.size() - 1; i++)
    {
        if(isdigit(evaluation.at(i - 1)) && evaluation.at(i) == '-' && (isdigit(evaluation.at(i+1)) || 
                                                                        evaluation.at(i+1) == '.'))
        {
            // replaces the '-' character with "+-"
            evaluation = expressionInject(evaluation, i, i, "+-");
        }
    }

    //returns the original expressions with the corrections made
    return evaluation;
}

string addEval(string input)
{
    string evaluation = input;
    int i;

    evaluation = subToAddNeg(input);

    for(i = 0; i < evaluation.size(); i++)
    {
        if(evaluation.at(i) == '+')
        {
            evaluation = expressionInject(evaluation, prevConstStrtLoc(evaluation, i), prevConstEndLoc(evaluation, i), 
            to_string(sum(constantBefore(evaluation, i), constantAfter(evaluation, i))));
            i = 0;
        }
    }

    return evaluation;
}

string multAndDivEval(string input)
{
    string evaluation = input;
    int i;

    evaluation = subToAddNeg(input);

    for(i = 0; i < evaluation.size(); i++)
    {
        if(evaluation.at(i) == '*')
        {
            evaluation = expressionInject(evaluation, prevConstStrtLoc(evaluation, i), prevConstEndLoc(evaluation, i), 
            to_string(product(constantBefore(evaluation, i), constantAfter(evaluation, i))));
            i = 0;
        }
        else if(evaluation.at(i) == '/')
        {
            evaluation = expressionInject(evaluation, prevConstStrtLoc(evaluation, i), prevConstEndLoc(evaluation, i), 
            to_string(division(constantBefore(evaluation, i), constantAfter(evaluation, i))));
            i = 0;
        }
    }

    return evaluation;
}

string powerEval(string input)
{
    string evaluation = input;
    int i;

    evaluation = subToAddNeg(input);

    for(i = 0; i < evaluation.size(); i++)
    {
        if(evaluation.at(i) == '^')
        {
            if(constantBefore(evaluation, i) > 0)
            {
            evaluation = expressionInject(evaluation, prevConstStrtLoc(evaluation, i), prevConstEndLoc(evaluation, i), 
            to_string(pow(constantBefore(evaluation, i), constantAfter(evaluation, i))));
            }
            else 
            {
            evaluation = expressionInject(evaluation, prevConstStrtLoc(evaluation, i)+1, prevConstEndLoc(evaluation, i), 
            to_string(pow(constantBefore(evaluation, i)*(-1), constantAfter(evaluation, i))));
            }

            i = 0;
        }
    }

    return evaluation;
}

string primOpEval(string input)
{
    string evaluation = input;
    //search for all power symbols
    evaluation = powerEval(evaluation);
    //search for all multiply and divide
    evaluation = multAndDivEval(evaluation);
    //search for all addition
    evaluation = addEval(evaluation);

    return evaluation;
}

string evaluate(string str2eval)
{
    string input = str2eval;
    int i;
    int currentExpressionStart = 0;
    int currentExpressionEnd = 0;
    string tempStr;
    long double injectionLongDouble;
    // int ammountOfOperators = 0;

    //if there are no parentheses in the expression
    if(countParentheses(input) == 0 || 
      (countParentheses(input) == 1 && 
       input.at(0) == '(' && 
       input.at(input.size()-1) == ')'))
    {

    }
    else
    {
        for(i = 0; i < input.size(); i++)
        {
            if(input.at(i) == ')')
            {
                currentExpressionStart = findPrevParenth(input, i);
                currentExpressionEnd = i;
                tempStr = input.substr(currentExpressionStart+1, currentExpressionEnd-1);
                if(isConst(tempStr))
                {
                    if(!isalpha(input.at(currentExpressionStart-1)))
                    {
                    }
                    else if(input.substr(currentExpressionStart-4, currentExpressionStart-1)  
                       == "ATAN")
                       {
                            injectionLongDouble = stold(tempStr);
                            tempStr = to_string(atan(injectionLongDouble));
                            expressionInject(input, currentExpressionStart, currentExpressionEnd, tempStr);
                       }
                    else if(input.substr(currentExpressionStart-4, currentExpressionStart-1)  
                       == "ACOS")
                       {
                            injectionLongDouble = stold(tempStr);
                            tempStr = to_string(acos(injectionLongDouble));
                            expressionInject(input, currentExpressionStart, currentExpressionEnd, tempStr);
                       }
                    else if(input.substr(currentExpressionStart-4, currentExpressionStart-1)  
                       == "ASIN")
                       {
                            injectionLongDouble = stold(tempStr);
                            tempStr = to_string(asin(injectionLongDouble));
                            expressionInject(input, currentExpressionStart, currentExpressionEnd, tempStr);
                       }
                    else if(input.substr(currentExpressionStart-3, currentExpressionStart-1)  
                       == "TAN")
                       {
                            injectionLongDouble = stold(tempStr);
                            tempStr = to_string(tan(injectionLongDouble));
                            expressionInject(input, currentExpressionStart, currentExpressionEnd, tempStr);
                       }
                    else if(input.substr(currentExpressionStart-3, currentExpressionStart-1)  
                       == "COS")
                       {
                            injectionLongDouble = stold(tempStr);
                            tempStr = to_string(cos(injectionLongDouble));
                            expressionInject(input, currentExpressionStart, currentExpressionEnd, tempStr);
                       }
                    else if(input.substr(currentExpressionStart-3, currentExpressionStart-1)  
                       == "SIN")
                       {
                            injectionLongDouble = stold(tempStr);
                            tempStr = to_string(sin(injectionLongDouble));
                            expressionInject(input, currentExpressionStart, currentExpressionEnd, tempStr);
                       }
                    else if(input.substr(currentExpressionStart-3, currentExpressionStart-1)  
                       == "EXP")
                       {
                            injectionLongDouble = stold(tempStr);
                            tempStr = to_string(exp(injectionLongDouble));
                            expressionInject(input, currentExpressionStart, currentExpressionEnd, tempStr);
                       }
                    else if(input.substr(currentExpressionStart-3, currentExpressionStart-1)  
                       == "LOG")
                       {
                            injectionLongDouble = stold(tempStr);
                            tempStr = to_string(logBase(10, injectionLongDouble));
                            expressionInject(input, currentExpressionStart, currentExpressionEnd, tempStr);
                       }
                    else if(input.substr(currentExpressionStart-2, currentExpressionStart-1)  
                       == "LN")
                       {
                            injectionLongDouble = stold(tempStr);
                            tempStr = to_string(logBase(E, injectionLongDouble));
                            expressionInject(input, currentExpressionStart, currentExpressionEnd, tempStr);
                       }
                }
                else
                {
                    //inject the parenteses with the evaluation of the internals
                    expressionInject(input, currentExpressionStart, currentExpressionEnd, 
                    evaluate(input.substr(currentExpressionStart, currentExpressionEnd)));
                }
            }
        }
    }

    //comb through the string looking for a function call
    //append all of previous part of the string into the final string
    //find the translation of the operator and append to the final string
    //repeat until the end

    /*
    General Rules

    1+1 >> 2        //does the operation
    1+(123 + 123)+(3+3) >> 1+246+6 //evaluates the parentheses elements first and deletes them
    2*(1+1+1) >> 2*(3) //should evaluate inside the parentheses first
    (1+x) >> (1+1) //supposing we know that x=1, sub it in, if we don't know it, return an error for now
    exp(0)+7 >> 1+7 //evaluate function with letters
    1+2*3 >> 1+6 or 1+(6) //have various passes over the string evaluating in order of operations
    cos(1-1) >> cos(0) //when you are about to evaluate a family of operation, you may need to evaluate it's arguments

    */

    //repeat everything until you are left with only a constant or variables if a constant is undefined

    //symbols and the way things look in the calculator (and thus the final product) 
    //will have it's own translations only at the display level
    string evaluation = "";
    return evaluation;
}
























































