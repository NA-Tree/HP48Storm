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

    // int i;
    // int j;
    // string resultString;
    long double resultLD;
    // int resultInteger;


    // c = 0;
    // cout << endl << "Sum, Difference, Product, Division" << endl;
    
    // { //grouping
    //     test(sum(1.05, 1.05) == 2.1, c);        //two pos numbers
    //     test(sum(-.95, -1.05) == -2, c);        //two neg numbers
    //     test(sum(-1.5, 1.5) == 0, c);           //one pos one neg
    //     test(sum(100000, -50000) == 50000, c);  //one pos one neg
    //     test(sum(0, -1) == -1, c);              //pos and zero
    //     test(sum(100, 0) == 100, c);            //pos and zero
    //     test(sum(1, 1) == 2, c);                //pos integers

    //     test(product(134.16234, 1) == 134.16234, c);
    //     test(product(134.16234, 0) == 0, c);
    //     test(product(134.16234, 2) == 2*134.16234, c);
    //     test(product(10, 10) == pow(10, 2), c);
    //     test(product(pow(1.2, 45), pow(1.2, 15)) - pow(1.2, 60) <= EPSILON, c);
    //     //this specific test is not currently working and will be looked into
    //     test(product(pow(9.1, 1.1), pow(9.1, 2.2)) - pow(9.1, 3.3) <= EPSILON, c);
    //     test(product(134.16234, -1) == -134.16234, c);
    //     test(product(-134.16234, 0) == 0, c);
    //     test(product(-134.16234, 2) == -2*134.16234, c);
    //     test(product(-10, -10) == pow(10, 2), c);
    //     test(product(pow(-1.2, 45), pow(-1.2, 15)) - pow(-1.2, 60) <= EPSILON, c);
        
    //     test(division(2, 1) == 2, c);
    //     test(division(2, 2) -1 <= .0000001, c);
    //     test(division(2.123, 1) == 2.123, c);
    //     test(division(2.123, -2.123) == -1, c);
    //     test(division(-456, -1) == 456, c);

    //     test(division(15.9345, 6873.545) -.0023182360776 <= EPSILON, c);
    //     test(division(100.101, .5) == 200.202, c);
    //     test(division(100.101, -.5) == -200.202, c);
    //     test(division(.4, 2) == .2, c);
    //     test(division(321.852, 0) == 0, c);
    //     test(division(.4, -.2) == -2, c);
    // }

    // c = 0;
    // cout << endl << "removeWhiteSpace" << endl;
    
    // { //grouping
    //     test(removeWhiteSpace("123 hello \n world \t Smile More") == "123helloworldSmileMore", c);
    //     test(removeWhiteSpace("123") == "123", c);
    //     test(removeWhiteSpace("") == "", c);
    //     test(removeWhiteSpace("helloWorld") == "helloWorld", c);
    //     test(removeWhiteSpace("2+4*5*3/5+5 + cos(3 * x)") == "2+4*5*3/5+5+cos(3*x)", c);
    // }

    // c = 0;
    // cout << endl << "expressionInject" << endl;

    // { //grouping
    //     test(expressionInject("123(56)89", 3, 6, "helloWorld") == "123helloWorld89", c);
    //     test(expressionInject("12*x+90/2+40*y^2", 3, 3, "(12*y+1)") == "12*(12*y+1)+90/2+40*y^2", c);
    //     test(expressionInject("12*(12*y+1)+90/2+40*y^2", 7, 7, "10") == "12*(12*10+1)+90/2+40*y^2", c);
    //     test(expressionInject("12*(12*10+1)+90/2+40*y^2", 3, 11, "(120+1)") == "12*(120+1)+90/2+40*y^2", c);
    //     test(expressionInject("12*(120+1)+90/2+40*y^2", 3, 9, "121") == "12*121+90/2+40*y^2", c);
    //     test(expressionInject("12*121+90/2+40*y^2", 15, 15, "10") == "12*121+90/2+40*10^2", c);
    //     test(expressionInject("12*121+90/2+40*10^2", 15, 18, "100") == "12*121+90/2+40*100", c);
    //     test(expressionInject("12*121+90/2+40*100", 0, 5, "1452") == "1452+90/2+40*100", c);
    //     test(expressionInject("1452+90/2+40*100", 5, 8, "45") == "1452+45+40*100", c);
    //     test(expressionInject("1452+45+40*100", 8, 13, "4000") == "1452+45+4000", c);
    //     test(expressionInject("1452+45+4000", 0, 6, "1497") == "1497+4000", c);
    //     test(expressionInject("1497+4000", 0, 8, "5497") == "5497", c);
    // }

    // c = 0; 
    // cout << endl << "countParentheses" << endl;

    // { //grouping
    //     test(countParentheses("") == 0, c);
    //     test(countParentheses("()") == 1, c);
    //     test(countParentheses("(())") == 2, c);
    //     test(countParentheses("(()") == -1, c);
    //     test(countParentheses("12*(12*y+1)+90/2+40*y^2") == 1, c);
    //     test(countParentheses("12*121+90/2+40*y^2") == 0, c);
    //     test(countParentheses("()+)(") == 2, c);
    //     test(countParentheses(")()(") == 2, c);
    //     test(countParentheses(")(((((()") == -1, c);
    //     test(countParentheses("897546132") == 0, c);
    // }

    // c = 0; 
    // cout << endl << "findPrevParenth" << endl;

    // { //grouping

    //     test(findPrevParenth("(1000)", 5) == 0, c);
    //     test(findPrevParenth("0123(567)910", 8) == 4, c);
    //     test(findPrevParenth("01234567)910", 8) == 0, c);
    //     test(findPrevParenth("01234567)910", 7) == 0, c);
    //     test(findPrevParenth("01(34567891)", 4) == 2, c);
    //     test(findPrevParenth("01(34567891)", 1) == 0, c);
    //     test(findPrevParenth("0123()678910", 5) == 4, c);
    //     test(findPrevParenth("0123()678910", 4) == 0, c);
    //     test(findPrevParenth("0123()678910", 9) == 4, c);

    // }

    // c = 0; 
    // cout << endl << "isConst" << endl;

    // { //grouping
    //     test(isConst("123") == true, c);
    //     test(isConst("123.123") == true, c);
    //     test(isConst("-123") == true, c);
    //     test(isConst("-123.89658") == true, c);
    //     test(isConst("123+123") == false, c);
    //     test(isConst("1-123") == false, c);
    //     test(isConst("(345+5)*5") == false, c);
    //     test(isConst("") == false, c);
    //     test(isConst("-902183518.08008005") == true, c);
    //     test(isConst("8099.02-8658") == false, c);
    //     test(isConst("-") == false, c);
    //     test(isConst("123.6.5") == false, c);
    //     test(isConst("-1.2.3") == false, c);
    // }

    // c = 0; 
    // cout << endl << "prevConstStrtLoc" << endl;

    // { //grouping
    //     test(prevConstStrtLoc("0123+567890", 3) == 0, c);
    //     test(prevConstStrtLoc("0123+567890", 6) == 5, c);
    //     test(prevConstStrtLoc(".123+567890", 4) == 0, c);
    //     test(prevConstStrtLoc("1.23+567890", 4) == 0, c);
    //     test(prevConstStrtLoc("-123+567890", 4) == 0, c);
    //     test(prevConstStrtLoc("-.123+567890", 5) == 0, c);
    //     test(prevConstStrtLoc("-1.23+567890", 5) == 0, c);
    //     test(prevConstStrtLoc("100+-123+567890", 8) == 4, c);
    //     test(prevConstStrtLoc("100+-.123+567890", 9) == 4, c);
    // }

    // c = 0; 
    // cout << endl << "postConstEndLoc" << endl;

    // { //grouping
    //     test(postConstEndLoc("0123+567890", 4) == 10, c);
    //     test(postConstEndLoc("0123+567890", 6) == 10, c);
    //     test(postConstEndLoc("0123+.567890", 4) == 11, c);
    //     test(postConstEndLoc("0123+-567890", 4) == 11, c);
    //     test(postConstEndLoc("0123+-.567890", 4) == 12, c);
    //     test(postConstEndLoc("0123+5.67890", 4) == 11, c);
    //     test(postConstEndLoc("0123+-5.678+590", 4) == 10, c);
    //     test(postConstEndLoc("0123+5678+90", 4) == 8, c);
    //     test(postConstEndLoc("0123+-56.0+7890", 4) == 9, c);
    // }    
    
    // c = 0; 
    // cout << endl << "constantBefore" << endl;

    // { //grouping
    //     test(constantBefore("123+567890", 3) == 123, c);
    //     test(constantBefore("0123+567890", 10) == 567890, c);
    //     test(constantBefore(".123+567890", 4) - .123 <= EPSILON, c);
    //     test(constantBefore("1.23+567890", 4) - 1.23 <= EPSILON, c);
    //     test(constantBefore("-123+567890", 4) == -123, c);
    //     test(constantBefore("-.123+567890", 5) + 0.123 <= EPSILON, c);
    //     test(constantBefore("-1.23+567890", 5) + 1.23 <= EPSILON, c);
    //     test(constantBefore("100+-123+567890", 8) == -123, c);
    //     test(constantBefore("100+-.123+567890", 9) + .123 <= EPSILON, c);
    //     test(constantBefore(".5+.5", 2) == 0.5, c);
    // }

    // c = 0; 
    // cout << endl << "constantAfter" << endl;

    // { //grouping
    //     test(constantAfter("0123+567890", 4) == 567890, c);
    //     test(constantAfter("0123+.567890", 4) - .567890 <= EPSILON, c);
    //     test(constantAfter("0123+-567890", 4) == -567890, c);
    //     test(constantAfter("0123+-.567890", 4) + .567890 <= EPSILON, c);
    //     test(constantAfter("0123+5.67890", 4) - 5.67890 <= EPSILON, c);
    //     test(constantAfter("0123+-5.678+590", 4) + 5.678 <= EPSILON, c);
    //     test(constantAfter("0123+5678+90", 4) == 5678, c);
    //     test(constantAfter("0123+-56.0+7890", 4) == -56.0, c);
    // }

    // c = 0; 
    // cout << endl << "negativeFix" << endl;

    // { //grouping
    //     test(negativeFix("0123+567890") == "0123+567890", c);
    //     test(negativeFix("0123-567890") == "0123+-567890", c);
    //     test(negativeFix("0123+.567890") == "0123+.567890", c);
    //     test(negativeFix("0123-.567890") == "0123+-.567890", c);
    //     test(negativeFix("0123+-567890") == "0123+-567890", c);
    //     test(negativeFix("+23+567890") == "23+567890", c);
    //     test(negativeFix("0123+56-678-90") == "0123+56+-678+-90", c);
    //     test(negativeFix("+.123+.567-.890") == ".123+.567+-.890", c);
    //     test(negativeFix("01-2/3.58-45.6*78/90") == "01+-2/3.58+-45.6*78/90", c);
    //     test(negativeFix("0123+567890+") == "0123+567890", c);
    //     test(negativeFix("0123+567890-") == "0123+567890", c);
    //     cout << endl;

    //     test(negativeFix("") == "", c);
    //     test(negativeFix("--8") == "8", c);
    //     test(negativeFix("1--8") == "1+8", c);
    //     test(negativeFix("2*--8") == "2*8", c);
    //     test(negativeFix("--2*8") == "2*8", c);
    //     test(negativeFix("(--2)") == "(2)", c);
    //     test(negativeFix("3+--18*6") == "3+18*6", c);
    //     test(negativeFix("3--18*6") == "3+18*6", c);

    // }

    // c = 0; 
    // cout << endl << "addEval" << endl;

    // { //grouping
    //     test(addEval("0123+567890") == "568013", c);
    //     test(addEval("10-5") == "5", c);
    //     test(addEval(".5+.5") == "1", c);
    //     test(addEval("-1+.5") == "-0.5", c);
    //     test(addEval("1+1+1") == "3", c);
    //     test(addEval("5-2-1") == "2", c);
    //     test(addEval("10+2-1.5-2-.25+.25-10") == "-1.5", c);
    //     test(addEval("10-5.00000000001") == "4.99999999999", c);
    // }

    // c = 0; 
    // cout << endl << "multAndDivEval" << endl;

    // { //grouping
    //     test(multAndDivEval(".5*2") == "1", c);
    //     test(multAndDivEval("5*2") == "10", c);
    //     test(multAndDivEval("12*5") == "60", c);
    //     test(multAndDivEval("1*1") == "1", c);
    //     test(multAndDivEval("2*2") == "4", c);
    //     test(multAndDivEval("0*6") == "0", c);
    //     test(multAndDivEval("0/5") == "0", c);
    //     test(multAndDivEval("1/1") == "1", c);
    //     test(multAndDivEval("100/1") == "100", c);
    //     test(multAndDivEval(".5/2") == "0.25", c);
    //     test(multAndDivEval("5/.5") == "10", c);
    //     test(multAndDivEval("1/3") == "0.333333333333333", c);
    //     test(multAndDivEval("1*1/1") == "1", c);
    //     test(multAndDivEval("2*3/3") == "2", c);
    //     test(multAndDivEval("-1*5") == "-5", c);
    //     test(multAndDivEval("-1*2*-3*4") == "24", c);
    //     test(multAndDivEval("-1.2*2") == "-2.4", c);
    //     test(multAndDivEval(".5*.5*4") == "1", c);
    //     test(multAndDivEval("1-4/2") == "1+-2", c);
    //     test(multAndDivEval("1*2-4/2") == "2+-2", c);
    //     test(multAndDivEval("1*2-4/2+1*1") == "2+-2+1", c);
    // }

    // c = 0; 
    // cout << endl << "powerEval" << endl;

    // { //grouping
    //     test(powerEval("1^0") == "1", c);
    //     test(powerEval("1^1") == "1", c);
    //     test(powerEval("5^0") == "1", c);
    //     test(powerEval("5^1") == "5", c);
    //     test(powerEval("5*2^3") == "5*8", c);
    //     test(powerEval("3^4*1^2-2^-1") == "81*1+-0.5", c);
    //     test(powerEval("10^2") == "100", c);
    //     test(powerEval("123^1.5") == "1364.135990288358311", c);
    //     test(powerEval("300^2") == "90000", c);
    //     test(powerEval("1.5+2^3/-5^3") == "1.5+8/-125", c);
    //     test(powerEval("121^.5") == "11", c);
    //     test(powerEval("27^.333333333333333333333") == "3", c);
    //     test(powerEval("100^.5") == "10", c);
    //     test(powerEval("7^2") == "49", c);
    //     test(powerEval(".5^2") == "0.25", c);
    //     test(powerEval(".25^.5") == "0.5", c);
    //     test(powerEval("2^-2") == "0.25", c);
    //     //because of the precision of to_string, 0^x for some x may be a weird string but will still be 0
    //     test(powerEval("0^5") == "0-0", c);
    //     test(stold(powerEval("0^65986258")) == 0, c);
    //     test(stold(powerEval("0^100")) == 0, c);
    // }

    // c = 0; 
    // cout << endl << "round" << endl;

    // { //grouping
    //     test(round("3.000000000000") == "3", c);
    //     test(round("35.89650000000000") == "35.8965", c);
    //     test(round("10.000000000001") == "10.000000000001", c);
    //     test(round("3.0006900000000") == "3.00069", c);
    //     test(round("0.000000000000") == "0", c);
    //     test(round("0.9999999999") == "1", c);
    //     test(round("12.249999999999") == "12.249999999999", c);
    //     test(round("101.99990000000000") == "101.9999", c);
    //     test(round("85.999899999999999") == "85.999899999999999", c);
    //     test(round("85.998999999999999") == "85.999", c);
    //     test(round("85.9997999") == "85.9997999", c);
    //     test(round("85.999899") == "85.999899", c);
    //     test(round("0.0099999899") == "0.0099999899", c);
    //     test(round("0.9167951795245") == "0.9167951795245", c);
    //     test(round("101.99990000000000") == "101.9999", c);
    //     test(round("4.99999999999") == "5", c);

    // }

    // c = 0; 
    // cout << endl << "primOpEval" << endl;

    // { //grouping
    //     test(primOpEval("1^0") == "1", c);
    //     test(primOpEval("1^1") == "1", c);
    //     test(primOpEval("5^0") == "1", c);
    //     test(primOpEval("5^1") == "5", c);
    //     test(primOpEval("5*2^3") == "40", c);
    //     test(primOpEval("3^4*1^2-2^-1") == "80.5", c);
    //     test(primOpEval("10^2") == "100", c);
    //     test(primOpEval("123^1.5") == "1364.135990288358311", c);
    //     test(primOpEval("300^2") == "90000", c);
    //     test(primOpEval("1.5+2^3/-5^3") == "1.436", c);
    //     test(primOpEval("121^.5") == "11", c);
    //     test(primOpEval("27^.33333333333333333") == "3", c);
    //     test(primOpEval("100^.5") == "10", c);
    //     test(primOpEval("7^2") == "49", c);
    //     test(primOpEval(".5^2") == "0.25", c);
    //     test(primOpEval(".25^.5") == "0.5", c);
    //     test(primOpEval("2^-2") == "0.25", c);
    //     test(primOpEval("0^5") == "0", c);
    //     test(stold(primOpEval("0^65986258")) == 0, c);
    //     test(stold(primOpEval("0^100")) == 0, c);
    //     test(primOpEval("-100+2*5-2^2^2+6-100*2.5*4/10+2500^.5") == "-150", c);
    //     test(primOpEval("325+85/5+1*6-5.5-9.8*68/2+0.5-9^2/3-105.0595") == "-122.2595", c);
    //     //this test should only end in .35 but the way long doubles work makes the last 3 digits inaccurate
    //     test(primOpEval("2346^2+54-5.95+6.55-100*.555-10^0+2^-2") == "5503714.350000000000364", c);
    //     //this test should be -2932.284391915784257 but because of the rounding of each number, it's off by .01
    //     test(primOpEval("505/36.5+9^-2.5+90-435^1.32+9-5.598428") == "-2932.284391915784258", c);
    // }


    c = 0; 
    cout << endl << "evaluate" << endl;

    { //grouping

        //copy of some of the primOpEval problems
        // test(evaluate("1^0") == "1", c);    
        // test(evaluate("1^1") == "1", c);
        // test(evaluate("5^0") == "1", c);
        // test(evaluate("5^1") == "5", c);
        // test(evaluate("5*2^3") == "40", c);
        // test(evaluate("3^4*1^2-2^-1") == "80.5", c);
        // test(evaluate("10^2") == "100", c);
        // test(evaluate("123^1.5") == "1364.135990288358311", c);
        // test(evaluate("300^2") == "90000", c);
        // test(evaluate("1.5+2^3/-5^3") == "1.436", c);
        // test(evaluate("121^.5") == "11", c);
        // test(evaluate("27^.33333333333333333") == "3", c);
        // test(evaluate("100^.5") == "10", c);
        // test(evaluate("7^2") == "49", c);
        // test(evaluate(".5^2") == "0.25", c);
        // test(evaluate(".25^.5") == "0.5", c);
        // test(evaluate("2^-2") == "0.25", c);
        // test(evaluate("0^5") == "0", c);
        // //testing simple recursion
        // test(evaluate("2*(3-1)") == "4", c);
        // test(evaluate("1+(6)+7*(5+5-1)*-2/2+(4*6)") == "-32", c);
        // test(evaluate("(3+5*(3+5*(3+5)))+9*(5-3+(2*1))") == "254", c);
        // test(evaluate("3-(9*-2)*6") == "111", c);
        // test(evaluate("(123+159)/2 + 5+9*(1/9)") == "147", c);
        // test(evaluate("2^2^3") == "64", c);
        // testing worded functions 
        test(evaluate("ATAN(1)")  == "0.785398163397448", c);
        test(evaluate("ATAN(-1)") == "-0.785398163397448", c);
        test(evaluate("ATAN(1.557407724654902)")  == "1", c);
        test(evaluate("ATAN(-1.557407724654902)") == "-1", c);
        test(evaluate("ATAN(-5.68)") == "-1.396525895543263", c);
        test(evaluate("ACOS(1)") == "0", c);
        test(evaluate("ACOS(-1)") == "3.141592653589793", c);
        test(evaluate("ACOS(.5)") == "1.047197551196597", c);
        test(evaluate("ACOS(-5.5)") == outOfDomainErrorMessage, c);
        test(evaluate("ACOS(0.707106781186547)") == "0.785398163397448", c);
        test(evaluate("ASIN(1)") == "1.570796326794896", c);
        test(evaluate("ASIN(-1)") == "-1.570796326794896", c);
        test(evaluate("ASIN(.5)") == "0.523598775598298", c);
        test(evaluate("ASIN(-5.5)") == outOfDomainErrorMessage, c);
        test(evaluate("ASIN(0.707106781186547)") == "0.785398163397448", c);
        test(evaluate("TAN(0.785398163397448)") == "1", c);
        test(evaluate("TAN(-0.785398163397448)") == "-1", c);
        test(evaluate("TAN(1)") == "1.557407724654902", c);
        test(evaluate("TAN(-1)") == "-1.557407724654902", c);
        test(evaluate("TAN(-1.396525895543263)") == "-5.68", c);
        test(evaluate("COS(0)") == "1", c);
        test(evaluate("COS(3.141592653589793)") == "-1", c);
        test(evaluate("COS(1.047197551196597)") == ".5", c);
        test(evaluate("COS(0.785398163397448)") == "0.707106781186547", c);
        test(evaluate("SIN(1.570796326794896)") == "1", c);
        test(evaluate("SIN(-1.570796326794896)") == "-1", c);
        test(evaluate("SIN(0.523598775598298)") == ".5", c);
        test(evaluate("SIN(0.785398163397448)") == "0.707106781186547", c);
        test(evaluate("EXP(1)") == "2.718281828459045", c);
        test(evaluate("EXP(2)") == "7.389056098930650", c);
        test(evaluate("EXP(3)") == "20.085536923187667", c);
        test(evaluate("EXP(4)") == "54.598150033144239", c);
        test(evaluate("EXP(.2)") == "1.221402758160169", c);
        test(evaluate("EXP(-.22)") == "0.802518797962478", c);
        test(evaluate("EXP(-2)") == "0.135335283236612", c);
        test(evaluate("EXP(-1)") == "0.367879441171442", c);
        test(evaluate("EXP(20)") == "485165195.409790277969106", c);
        test(evaluate("EXP(10)") == "22026.465794806716516", c);
        test(evaluate("EXP(.5)") == "1.648721270700128", c);
        test(evaluate("EXP(4.25)") == "70.105412346687858", c);
        test(evaluate("EXP(-27.3333333333333333)") == "0.000000000001346", c);
        test(evaluate("LOG(1)") == "0", c);
        test(evaluate("LOG(5)") == "0.698970004336018", c);
        test(evaluate("LOG(.5)") == "-0.301029995663981", c);
        test(evaluate("LOG(0)") == outOfDomainErrorMessage, c);
        test(evaluate("LOG(-1)") == outOfDomainErrorMessage, c);
        test(evaluate("LOG(-5.5)") == outOfDomainErrorMessage, c);
        test(evaluate("LOG(8658.56)") == "3.937445670763918", c);
        test(evaluate("LOG(123.123)") == "2.090339188918716", c);
        test(evaluate("LN(1)") == "0", c);
        test(evaluate("LN(5)") == "1.609437912434100", c);
        test(evaluate("LN(.5)") == "-0.693147180559945", c);
        test(evaluate("LN(0)") == outOfDomainErrorMessage, c);
        test(evaluate("LN(-1)") == outOfDomainErrorMessage, c);
        test(evaluate("LN(-5.5)") == outOfDomainErrorMessage, c);
        test(evaluate("LN(8658.56)") == "9.066303705974940", c);
        test(evaluate("LN(123.123)") == "4.813183855705501", c);
        // test(evaluate("") == "", c);
        // test(evaluate("") == "", c);
        // test(evaluate("") == "", c);
        // test(evaluate("") == "", c);
        // test(evaluate("") == "", c);
        // test(evaluate("") == "", c);
        // test(evaluate("") == "", c);
        // test(evaluate("") == "", c);
        // test(evaluate("") == "", c);
        // test(evaluate("") == "", c);
        // test(evaluate("") == "", c);
        // test(evaluate("") == "", c);
        // test(evaluate("") == "", c);
        // test(evaluate("") == "", c);
        // test(evaluate("") == "", c);
        // test(evaluate("") == "", c);





    }






    return 0;
}