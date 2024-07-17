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
    //     //this test case is having an odd problem where everything should wor but isn't
    //     //this could be from values outside the range of the memory size of a long double
    //     test(product(pow(13.2, 45), pow(13.2, 15)) - pow(13.2, 60) <= .00000001, c);
    //     test(product(pow(13.2, 1.1), pow(13.2, 2.2)) - pow(13.2, 3.3) <= .00000001, c);
    //     test(product(134.16234, -1) == -134.16234, c);
    //     test(product(-134.16234, 0) == 0, c);
    //     test(product(-134.16234, 2) == -2*134.16234, c);
    //     test(product(-10, -10) == pow(10, 2), c);
    //     //this test case is having an odd problem where everything should wor but isn't
    //     //this could be from values outside the range of the memory size of a long double
    //     test(product(pow(-13.2, 45), pow(-13.2, 15)) - pow(-13.2, 60) <= .00000001, c);
        
    //     test(division(2, 1) == 2, c);
    //     test(division(2, 2) -1 <= .0000001, c);
    //     test(division(2.123, 1) == 2.123, c);
    //     test(division(2.123, -2.123) == -1, c);
    //     test(division(-456, -1) == 456, c);

    //     test(division(15.9345, 6873.545) -.0023182360776 <= .00000001, c);
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
    // }

    // c = 0; 
    // cout << endl << "constantBeforeLocation" << endl;

    // { //grouping
    //     test(constantBeforeLocation("0123+567890", 3) == 0, c);
    //     test(constantBeforeLocation("0123+567890", 6) == 5, c);
    //     test(constantBeforeLocation(".123+567890", 4) == 0, c);
    //     test(constantBeforeLocation("1.23+567890", 4) == 0, c);
    //     test(constantBeforeLocation("-123+567890", 4) == 0, c);
    //     test(constantBeforeLocation("-.123+567890", 5) == 0, c);
    //     test(constantBeforeLocation("-1.23+567890", 5) == 0, c);
    //     test(constantBeforeLocation("100+-123+567890", 8) == 4, c);
    //     test(constantBeforeLocation("100+-.123+567890", 9) == 4, c);
    // }

    // c = 0; 
    // cout << endl << "constantAfterLocation" << endl;

    // { //grouping
    //     test(constantAfterLocation("0123+567890", 4) == 10, c);
    //     test(constantAfterLocation("0123+567890", 6) == 10, c);
    //     test(constantAfterLocation("0123+.567890", 4) == 11, c);
    //     test(constantAfterLocation("0123+-567890", 4) == 11, c);
    //     test(constantAfterLocation("0123+-.567890", 4) == 12, c);
    //     test(constantAfterLocation("0123+5.67890", 4) == 11, c);
    //     test(constantAfterLocation("0123+-5.678+590", 4) == 10, c);
    //     test(constantAfterLocation("0123+5678+90", 4) == 8, c);
    //     test(constantAfterLocation("0123+-56.0+7890", 4) == 9, c);
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
    // cout << endl << "subToAddNeg" << endl;

    // { //grouping
    //     test(subToAddNeg("0123+567890") == "0123+567890", c);
    //     test(subToAddNeg("0123-567890") == "0123+-567890", c);
    //     test(subToAddNeg("0123+.567890") == "0123+.567890", c);
    //     test(subToAddNeg("0123-.567890") == "0123+-.567890", c);
    //     test(subToAddNeg("0123+-567890") == "0123+-567890", c);
    //     test(subToAddNeg("+23+567890") == "23+567890", c);
    //     test(subToAddNeg("0123+56-678-90") == "0123+56+-678+-90", c);
    //     test(subToAddNeg("+.123+.567-.890") == ".123+.567+-.890", c);
    //     test(subToAddNeg("01-2/3.58-45.6*78/90") == "01+-2/3.58+-45.6*78/90", c);
    //     test(subToAddNeg("0123+567890+") == "0123+567890", c);
    //     test(subToAddNeg("0123+567890-") == "0123+567890", c);
    // }

    // c = 0; 
    // cout << endl << "addEval" << endl;

    // { //grouping
    //     test(addEval("0123+567890") == "568013.000000", c);
    //     test(addEval("10-5") == "5.000000", c);
    //     test(addEval(".5+.5") == "1.000000", c);
    //     test(addEval("-1+.5") == "-0.500000", c);
    //     test(addEval("1+1+1") == "3.000000", c);
    //     test(addEval("5-2-1") == "2.000000", c);
    //     test(addEval("10+2-1.5-2-.25+.25-10") == "-1.500000", c);

    // }

    // c = 0; 
    // cout << endl << "multAndDivEval" << endl;

    // { //grouping
    //     test(multAndDivEval(".5*2") == "1.000000", c);
    //     test(multAndDivEval("5*2") == "10.000000", c);
    //     test(multAndDivEval("12*5") == "60.000000", c);
    //     test(multAndDivEval("1*1") == "1.000000", c);
    //     test(multAndDivEval("2*2") == "4.000000", c);
    //     test(multAndDivEval("0*6") == "0.000000", c);
    //     test(multAndDivEval("0/5") == "0.000000", c);
    //     test(multAndDivEval("1/1") == "1.000000", c);
    //     test(multAndDivEval("100/1") == "100.000000", c);
    //     test(multAndDivEval(".5/2") == "0.250000", c);
    //     test(multAndDivEval("5/.5") == "10.000000", c);
    //     test(multAndDivEval("1/3") == "0.333333", c);
    //     test(multAndDivEval("1*1/1") == "1.000000", c);
    //     test(multAndDivEval("2*3/3") == "2.000000", c);
    //     test(multAndDivEval("-1*5") == "-5.000000", c);
    //     test(multAndDivEval("-1*2*-3*4") == "24.000000", c);
    //     test(multAndDivEval("-1.2*2") == "-2.400000", c);
    //     test(multAndDivEval(".5*.5*4") == "1.000000", c);
    //     test(multAndDivEval("1-4/2") == "1+-2.000000", c);
    //     test(multAndDivEval("1*2-4/2") == "2.000000+-2.000000", c);
    //     test(multAndDivEval("1*2-4/2+1*1") == "2.000000+-2.000000+1.000000", c);
    // }

    // c = 0; 
    // cout << endl << "powerEval" << endl;

    // { //grouping
    //     test(powerEval("1^0") == "1.000000", c);
    //     test(powerEval("1^1") == "1.000000", c);
    //     test(powerEval("5^0") == "1.000000", c);
    //     test(powerEval("5^1") == "5.000000", c);
    //     test(powerEval("5*2^3") == "5*8.000000", c);
    //     test(powerEval("3^4*1^2-2^-1") == "81.000000*1.000000+-0.500000", c);
    //     test(powerEval("10^2") == "100.000000", c);
    //     test(powerEval("123^1.5") == "1364.135990", c);
    //     test(powerEval("300^2") == "90000.000000", c);
    //     test(powerEval("1.5+2^3/-5^3") == "1.5+8.000000/-125.000000", c);
    //     test(powerEval("121^.5") == "11.000000", c);
    //     test(powerEval("27^.3333333333333") == "3.000000", c);
    //     test(powerEval("100^.5") == "10.000000", c);
    //     test(powerEval("7^2") == "49.000000", c);
    //     test(powerEval(".5^2") == "0.250000", c);
    //     test(powerEval(".25^.5") == "0.500000", c);
    //     test(powerEval("2^-2") == "0.250000", c);
    //     //because of the precision of to_string, 0^x for some x may be a weird string but will still be 0
    //     test(powerEval("0^5") == "0-0.000000", c);
    //     test(powerEval("0^65986258") == "00.000000", c);
    //     test(powerEval("0^100") == "00.000000", c);

    // }

    // c = 0; 
    // cout << endl << "primOpEval" << endl;

    // { //grouping
    //     test(primOpEval("1^0") == "1.000000", c);
    //     test(primOpEval("1^1") == "1.000000", c);
    //     test(primOpEval("5^0") == "1.000000", c);
    //     test(primOpEval("5^1") == "5.000000", c);
    //     test(primOpEval("5*2^3") == "40.000000", c);
    //     test(primOpEval("3^4*1^2-2^-1") == "80.500000", c);
    //     test(primOpEval("10^2") == "100.000000", c);
    //     test(primOpEval("123^1.5") == "1364.135990", c);
    //     test(primOpEval("300^2") == "90000.000000", c);
    //     test(primOpEval("1.5+2^3/-5^3") == "1.436000", c);
    //     test(primOpEval("121^.5") == "11.000000", c);
    //     test(primOpEval("27^.3333333333333") == "3.000000", c);
    //     test(primOpEval("100^.5") == "10.000000", c);
    //     test(primOpEval("7^2") == "49.000000", c);
    //     test(primOpEval(".5^2") == "0.250000", c);
    //     test(primOpEval(".25^.5") == "0.500000", c);
    //     test(primOpEval("2^-2") == "0.250000", c);
    //     test(primOpEval("0^5") == "0.000000", c);
    //     //because of the precision of to_string, 0^x for some x may be a weird string but will still be 0
    //     //this can be solved with a cleanup function that can be developed during refactoring
    //     test(primOpEval("0^65986258") == "00.000000", c);
    //     test(primOpEval("0^100") == "00.000000", c);
    //     test(primOpEval("-100+2*5-2^2^2+6-100*2.5*4/10+2500^.5") == "-150.000000", c);
    //     test(primOpEval("325+85/5+1*6-5.5-9.8*68/2+0.5-9^2/3-105.0595") == "-122.259500", c);
    //     test(primOpEval("2346^2+54-5.95+6.55-100*.555-10^0+2^-2") == "5503714.350000", c);
    //     //this test should be -2932.284392 but because of the rounding of each number, it's off by .000001
    //     //this can be solved during refactoring when we shift to a long double system and use custom precision
    //     test(primOpEval("505/36.5+9^-2.5+90-435^1.32+9-5.598428") == "-2932.284393", c);
        
    // }





    return 0;
}