/*
File:        driver.cpp
Author:      L Veselova
*/

#include "fraction_exception.h"
#include "fraction.h"

int main() {
    try
    {
        string frac1;
        string operand;
        string frac2;
        string label;


        while (true){
            cout << "\n? ";
            cin >> frac1;
            if (frac1 == "exit"){
                break;
            }
            cin >> operand;
            cin >> frac2;

            int whole = 0; //read in numbers from fraction 1
            int num = 0;
            int den = 0;
            int i = 0;
            if (frac1.find('_') > 0 && frac1.find('_') < 9 ){ // if number has a whole part process whole number
                for (i = 0; i < frac1.find('_'); i++){
                    whole = whole * 10 + (frac1[i] - '0');
                }
                for (i = i+1; i < frac1.find('/'); i++){
                    num = num * 10 + (frac1[i] - '0');
                }
                for (i = i+1 ; i < frac1.size(); i++){
                    den = den * 10 + (frac1[i] - '0');
                }
                num += whole * den;
            }

            else if (frac1.find('/') > 0 && frac1.find('/') < 9 ){ // for fraction entries
                for (i = 0; i < frac1.find('/'); i++){
                    num = num * 10 + (frac1[i] - '0');
                }
                for (i = i; i < frac1.size(); i++){
                    den = den * 10 + (frac1[i] - '0');
                }
            }
            else { // for whole numbered entries
                for (i = 0; i < frac1.size(); i++){
                    num = num * 10 + (frac1[i] - '0');
                }
                den = 1;
            }
            Fraction a (num,den);

            //repeat same steps for second fraction
            whole = 0;
            num = 0;
            den = 0;
            if (frac2.find('_') > 0 && frac2.find('_') < 5 ){ //for mixed numbers
                for (i = 0; i < frac2.find('_'); i++){
                    whole = whole * 10 + (frac2[i] - '0');
                }
                for (i = i+1; i < frac2.find('/'); i++){
                    num = num * 10 + (frac2[i] - '0');
                }
                for (i = i+1 ; i < frac2.size(); i++){
                    den = den * 10 + (frac2[i] - '0');
                }
                num += whole * den;
            }

            else if (frac2.find('/') > 0 && frac2.find('/') < 9 ){ // for fractions
                for (i = 0; i < frac2.find('/'); i++){
                    num = num * 10 + (frac2[i] - '0');
                }
                for (i = i; i < frac2.size(); i++){
                    den = den * 10 + (frac2[i] - '0');
                }

            }
            else { // for whole numbered entries
                for (i = 0; i < frac2.size(); i++) {
                    num = num * 10 + (frac2[i] - '0');
                }
                den = 1;
            }
            Fraction b (num,den);

            Fraction c (0,1);
            if (operand == "+"){ //select correct operation provided and calculate outuput
                c = a + b;
            }
            if (operand == "-"){
                c = a - b;
            }
            if (operand == "*"){
                c = a * b;
            }
            if (operand == "/"){
                c = a / b;
            }

            cout << "= " << c;
        }




    }
    catch (FractionException& e)
    {
        std::cout << "Division by Zero" << std::endl;
        std::cout << e.what() << std::endl;
    }


    return 0;
}
