#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <cmath>

using namespace std;

/* Constants */

#define E 2.71828182845904523536028747135266249775724709369995
#define PI 4 * atan(1)


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

double sum(double input1, double input2)
{
    return input1 + input2;
}

double difference(double input1, double input2)
{
    return input1 - input2;
}

double product(double input1, double input2)
{
    return input1 * input2;
}

double division(double input1, double input2)
{
    double result = 0;

    if(input2)
    {
        result = input1 / input2;
    }
    else
    {
        cout << "divide by 0 error" << endl << "answer will not be accurate" << endl;
    }

    return result;
}

double naturalExp(double input)
{
    return pow(E, input);
}

double baseTenExp(double input)
{
    return pow(10, input);
}

double logBase(double base, double input)
{
    double result = 0;

    if(base > 0 && input > 0)
    {
        result = log(input)/log(base);
    }
    
    return result;
}

/* Parsing/evalutation*/

string removeWhiteSpace(string input)
{
    // Creating a string containing multiple whitespaces.
    string alteredString = input;

    // Using the erase, remove_if, and ::isspace functions.
    alteredString.erase(
        remove_if(alteredString.begin(), alteredString.end(), ::isspace), 
        alteredString.end());

    return alteredString;
}

// arguments: the start of the expression, the end of the expression, and the string it is to be replaced with
string expressionInject(string inputString, int BOE, int EOE, string injection)
{
    BOE++;
    EOE++;
    int i = 0;
    int sizeOfInj = injection.size();
    string returnString = "";
    returnString[0] = ' ';
    
    //copy the beginning of the expression
    returnString.append(inputString, 0, BOE-1);
    //copy the injection in place of the phrase
    returnString.append(injection); // -1 so the end byte doesn't carry into the string (prematurely)
    //copy the rest of the expression
    returnString.append(inputString, EOE);
    // just in case it isn't given otherwise... look into when testing
    returnString.append("\0"); 

    return returnString;
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

int findPrevParenth(string inputString, int closeParenth)
{
    int closeLocation = closeParenth;
    int i;

    if(inputString.size() < closeLocation)
    {
        closeLocation = inputString.size()-1;
    }

    for(i = closeLocation - 1; inputString.at(i) != '(' && i != 0; i--)
    {

    }
    return i;
}

bool isConst(string input)
{
    if(input.size() == 0)
    {
        return false;
    }

    int i = 0;
    for(i = 0; i < input.size(); i++)
    {
        if(i == 0 && input.at(i) == '-')
        {
            i++;
        }

        if(i >= input.size() || !isdigit(input.at(i)) && input.at(i) != '.')
        {
            return false;
        }
    }
    return true;
}

int constantBeforeLocation(string input, int place)
{
    //this is assuming there is a constant and all subtract operators are turned into +-
    int i;
    int beginningOfNumber;

    for(i = place-1; i >= 0; i--)
    {
        // cout << endl << i << '\t' << input.at(i) << endl;
        if(isdigit(input.at(i)) || input.at(i) == '-' || input.at(i) == '.')
        {
            beginningOfNumber = i;
        }
        else
        {
            return beginningOfNumber;
        }
    }

    return beginningOfNumber;
}

double constantBefore(string input, int place)
{
    double constant = stod(input.substr(constantBeforeLocation(input, place), place));
    return constant;
}

int constantAfterLocation(string input, int place)
{
    string number;
    int i;
    int endOfNumber;

    for(i = place+1; i < input.size(); i++)
    {

        if(isdigit(input.at(i)) || input.at(i) == '-' || input.at(i) == '.')
        {
            endOfNumber = i;
        }
        else
        {
            return endOfNumber;
        }
    }

    return endOfNumber;
}

double constantAfter(string input, int place)
{
    double constant = stod(input.substr(place, constantAfterLocation(input, place)));
    return constant;
}

string subToAddNeg(string input)
{
    string evaluation = input;
    int i = 0;
    if(evaluation.at(0) == '+')
    {
        evaluation = expressionInject(evaluation, 0, 0, "");
    }
    if(evaluation.at(evaluation.size()-1) == '+' || evaluation.at(evaluation.size()-1) == '-')
    {
        evaluation = expressionInject(evaluation, evaluation.size()-1, evaluation.size()-1, "");
    }

    for(i = 1; i < evaluation.size()-1; i++)
    {
        if(isdigit(evaluation.at(i-1)) && evaluation.at(i) == '-' && (isdigit(evaluation.at(i+1)) || 
                                                                                evaluation.at(i+1) == '.'))
        {
            evaluation = expressionInject(evaluation, i, i, "+-");

        }
    }

    return evaluation;
}

string addEval(string input)
{
    string evaluation = input;
    int i;

    evaluation = subToAddNeg(input);

    for(i = 0; i < input.size(); i++)
    {
        if(input.at(i) == '+')
        {
            evaluation = expressionInject(evaluation, i, i, to_string(sum(constantBefore(evaluation, i), constantAfter(evaluation, i))));
        }
    }

    return evaluation;
}

string multAndDivEval(string input)
{
    string evaluation = input;

    return evaluation;
}

string powerEval(string input)
{
    string evaluation = input;

    return evaluation;
}

string primOpEval(string input)
{
    string evaluation = input;
    //search for all power symbols
    //search for all multiply and divide
    //search for all addition

    return evaluation;
}

string evaluate(string str2eval)
{
    string input = str2eval;
    int i;
    int currentExpressionStart = 0;
    int currentExpressionEnd = 0;
    string tempStr;
    double injectionDouble;
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
                            injectionDouble = stod(tempStr);
                            tempStr = to_string(atan(injectionDouble));
                            expressionInject(input, currentExpressionStart, currentExpressionEnd, tempStr);
                       }
                    else if(input.substr(currentExpressionStart-4, currentExpressionStart-1)  
                       == "ACOS")
                       {
                            injectionDouble = stod(tempStr);
                            tempStr = to_string(acos(injectionDouble));
                            expressionInject(input, currentExpressionStart, currentExpressionEnd, tempStr);
                       }
                    else if(input.substr(currentExpressionStart-4, currentExpressionStart-1)  
                       == "ASIN")
                       {
                            injectionDouble = stod(tempStr);
                            tempStr = to_string(asin(injectionDouble));
                            expressionInject(input, currentExpressionStart, currentExpressionEnd, tempStr);
                       }
                    else if(input.substr(currentExpressionStart-3, currentExpressionStart-1)  
                       == "TAN")
                       {
                            injectionDouble = stod(tempStr);
                            tempStr = to_string(tan(injectionDouble));
                            expressionInject(input, currentExpressionStart, currentExpressionEnd, tempStr);
                       }
                    else if(input.substr(currentExpressionStart-3, currentExpressionStart-1)  
                       == "COS")
                       {
                            injectionDouble = stod(tempStr);
                            tempStr = to_string(cos(injectionDouble));
                            expressionInject(input, currentExpressionStart, currentExpressionEnd, tempStr);
                       }
                    else if(input.substr(currentExpressionStart-3, currentExpressionStart-1)  
                       == "SIN")
                       {
                            injectionDouble = stod(tempStr);
                            tempStr = to_string(sin(injectionDouble));
                            expressionInject(input, currentExpressionStart, currentExpressionEnd, tempStr);
                       }
                    else if(input.substr(currentExpressionStart-3, currentExpressionStart-1)  
                       == "EXP")
                       {
                            injectionDouble = stod(tempStr);
                            tempStr = to_string(exp(injectionDouble));
                            expressionInject(input, currentExpressionStart, currentExpressionEnd, tempStr);
                       }
                    else if(input.substr(currentExpressionStart-3, currentExpressionStart-1)  
                       == "LOG")
                       {
                            injectionDouble = stod(tempStr);
                            tempStr = to_string(logBase(10, injectionDouble));
                            expressionInject(input, currentExpressionStart, currentExpressionEnd, tempStr);
                       }
                    else if(input.substr(currentExpressionStart-2, currentExpressionStart-1)  
                       == "LN")
                       {
                            injectionDouble = stod(tempStr);
                            tempStr = to_string(logBase(E, injectionDouble));
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
    string returnString = "";
    return returnString;
}
























































