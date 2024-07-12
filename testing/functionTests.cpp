#include <iostream>
#include <cmath>
#include <string>
#include "..//calculationFunctions.h"

bool test(bool input, int &counter)
{
    cout << "count: " << counter << '\t' << input << endl;
    counter++;
    return input;
}

int main( int argc, char* argv[])
{
    int c = 0; //counter

    int i;
    int j;
    string resultString;
    double resultDouble;
    int resultInteger;


    c = 0;
    cout << endl << "Sum, Difference, Product, Division" << endl;
    
    { //grouping
        test(sum(1.05, 1.05) == 2.1, c);        //two pos numbers
        test(sum(-.95, -1.05) == -2, c);        //two neg numbers
        test(sum(-1.5, 1.5) == 0, c);           //one pos one neg
        test(sum(100000, -50000) == 50000, c);  //one pos one neg
        test(sum(0, -1) == -1, c);              //pos and zero
        test(sum(100, 0) == 100, c);            //pos and zero
        test(sum(1, 1) == 2, c);                //pos integers

        test(difference(1.5, 1.5) == 0, c);
        test(difference(1, 1) == 0, c);
        test(difference(123.093, 23.023) - 100.07 <= .000001, c);
        test(difference(-123, 123) == -246, c);
        test(difference(123, -123) == 246, c);
        test(difference(-1.023, 5.23) == -6.253, c);
        test(difference(159632.0235*5, 159632.0235*2) == 159632.0235*3, c);
        test(difference(857.052638, 0) == 857.052638, c);

        test(product(134.16234, 1) == 134.16234, c);
        test(product(134.16234, 0) == 0, c);
        test(product(134.16234, 2) == 2*134.16234, c);
        test(product(10, 10) == pow(10, 2), c);
        test(product(pow(13.2, 45), pow(13.2, 15)) - pow(13.2, 60) <= .00000001, c);
        test(product(pow(13.2, 1.1), pow(13.2, 2.2)) - pow(13.2, 3.3) <= .00000001, c);
        test(product(134.16234, -1) == -134.16234, c);
        test(product(-134.16234, 0) == 0, c);
        test(product(-134.16234, 2) == -2*134.16234, c);
        test(product(-10, -10) == pow(10, 2), c);
        test(product(pow(-13.2, 45), pow(-13.2, 15)) - pow(-13.2, 60) <= .00000001, c);
        
        test(division(2, 1) == 2, c);
        test(division(2, 2) -1 <= .0000001, c);
        test(division(2.123, 1) == 2.123, c);
        test(division(2.123, -2.123) == -1, c);
        test(division(-456, -1) == 456, c);
        test(division(15.9345, 6873.545) -.0023182360776 <= .00000001, c);
        test(division(100.101, .5) == 200.202, c);
        test(division(100.101, -.5) == -200.202, c);
        test(division(.4, 2) == .2, c);
        test(division(321.852, 0) == 0, c);
        test(division(.4, -.2) == -2, c);
    }

    c = 0;
    cout << endl << "removeWhiteSpace" << endl;
    
    { //grouping
        test(removeWhiteSpace("123 hello \n world \t Smile More") == "123helloworldSmileMore", c);
        test(removeWhiteSpace("123") == "123", c);
        test(removeWhiteSpace("") == "", c);
        test(removeWhiteSpace("helloWorld") == "helloWorld", c);
        test(removeWhiteSpace("2+4*5*3/5+5 + cos(3 * x)") == "2+4*5*3/5+5+cos(3*x)", c);
    }

    c = 0;
    cout << endl << "expressionInject" << endl;

    { //grouping
        test(expressionInject("123(56)89", 3, 6, "helloWorld") == "123helloWorld89", c);
        test(expressionInject("12*x+90/2+40*y^2", 3, 3, "(12*y+1)") == "12*(12*y+1)+90/2+40*y^2", c);
        test(expressionInject("12*(12*y+1)+90/2+40*y^2", 7, 7, "10") == "12*(12*10+1)+90/2+40*y^2", c);
        test(expressionInject("12*(12*10+1)+90/2+40*y^2", 3, 11, "(120+1)") == "12*(120+1)+90/2+40*y^2", c);
        test(expressionInject("12*(120+1)+90/2+40*y^2", 3, 9, "121") == "12*121+90/2+40*y^2", c);
        test(expressionInject("12*121+90/2+40*y^2", 15, 15, "10") == "12*121+90/2+40*10^2", c);
        test(expressionInject("12*121+90/2+40*10^2", 15, 18, "100") == "12*121+90/2+40*100", c);
        test(expressionInject("12*121+90/2+40*100", 0, 5, "1452") == "1452+90/2+40*100", c);
        test(expressionInject("1452+90/2+40*100", 5, 8, "45") == "1452+45+40*100", c);
        test(expressionInject("1452+45+40*100", 8, 13, "4000") == "1452+45+4000", c);
        test(expressionInject("1452+45+4000", 0, 6, "1497") == "1497+4000", c);
        test(expressionInject("1497+4000", 0, 8, "5497") == "5497", c);
    }

    c = 0; 
    cout << endl << "countParentheses" << endl;

    { //grouping
        test(countParentheses("") == 0, c);
        test(countParentheses("()") == 1, c);
        test(countParentheses("(())") == 2, c);
        test(countParentheses("(()") == -1, c);
        test(countParentheses("12*(12*y+1)+90/2+40*y^2") == 1, c);
        test(countParentheses("12*121+90/2+40*y^2") == 0, c);
        test(countParentheses("()+)(") == 2, c);
        test(countParentheses(")()(") == 2, c);
        test(countParentheses(")(((((()") == -1, c);
        test(countParentheses("897546132") == 0, c);
    }

    c = 0; 
    cout << endl << "findPrevParenth" << endl;

    { //grouping

        test(findPrevParenth("(1000)", 5) == 0, c);
        test(findPrevParenth("0123(567)910", 8) == 4, c);
        test(findPrevParenth("01234567)910", 8) == 0, c);
        test(findPrevParenth("01234567)910", 7) == 0, c);
        test(findPrevParenth("01(34567891)", 4) == 2, c);
        test(findPrevParenth("01(34567891)", 1) == 0, c);
        test(findPrevParenth("0123()678910", 5) == 4, c);
        test(findPrevParenth("0123()678910", 4) == 0, c);
        test(findPrevParenth("0123()678910", 9) == 4, c);

    }

    c = 0; 
    cout << endl << "isConst" << endl;

    { //grouping
        test(isConst("123") == true, c);
        test(isConst("123.123") == true, c);
        test(isConst("-123") == true, c);
        test(isConst("-123.89658") == true, c);
        test(isConst("123+123") == false, c);
        test(isConst("1-123") == false, c);
        test(isConst("(345+5)*5") == false, c);
        test(isConst("") == false, c);
        test(isConst("-902183518.08008005") == true, c);
        test(isConst("8099.02-8658") == false, c);
        test(isConst("-") == false, c);
    }

    c = 0; 
    cout << endl << "constantBefore" << endl;

    { //grouping
        test(constantBefore("123+567890", 4) == 0, c);

    }

    c = 0; 
    cout << endl << "constantAfter" << endl;

    { //grouping
        test(constantBefore("123+567890", 4) == 10, c);

    }











    return 0;
}