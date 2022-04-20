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
                cin >> operand;
                cin >> frac2;
                
                int num = 0;
                int den = 1;
                if (frac1.find('_') > 0 && frac1.find('_') < 5 ){
                    num = ((frac1[0]-'0') * (frac1[4]-'0')) + (frac1[2] - '0');
                    den = frac1[4] - '0';
                }
                else {
                    num = frac1[0] - '0'; 
                    den = frac1[2] - '0';
                }
                Fraction a (num,den);
                
                num = 0;
                den = 1;
                if (frac2.find('_') > 0 && frac2.find('_') < 5){
                    num = ((frac2[0]-'0') * (frac2[4]-'0')) + (frac2[2] - '0');
                    den = frac2[4] - '0';
                }
                else {
                    num = frac2[0] - '0';
                    den = frac2[2] - '0';
                }
                Fraction b (num,den);
                
                Fraction c (0,1);
                if (operand == "+"){
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
