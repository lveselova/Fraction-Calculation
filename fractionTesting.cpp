

#include "fraction_exception.h"
#include "fraction.h"
#include <iostream>




void arithmeticTesting (){
    int pass = 0;
    Fraction a;
    Fraction b;
    Fraction c;
    Fraction d;
    int trueNum = 0;
    int trueDen = 1;
    int arr[11][4] = {{287,70,168,12},
                      {2,12,23,53},
                      {12,124,10,2},
                      {13,1,10,2},
                      {5,-2,15,20},
                      {-13,21,-10,11},
                      {8,9,37,-11},
                      {83,-9,17,20},
                      {45,32,16,18},
                      {63,1,1,74},
                      {2,3,168,12}};
    
    int i =sizeof(arr)/sizeof(*arr)-1;
    // Addition Testing
    while (i > 0){
        a.setNumbers(arr[i][0], arr[i][1]);
        b.setNumbers(arr[i][2], arr[i][3]);
        trueNum = a.getNum() * b.getDen() + b.getNum() * a.getDen();
        trueDen = a.getDen() * b.getDen();
        c.setNumbers(trueNum, trueDen);
        c.reduceFraction();
        d = a + b;
        cout << "Testing Addition: " << a << " + " << b << " = ";
        if (d == c){
            cout << "..passed " << d << "\n";
            pass++;
        }
        else 
            cout << "..FAIL";
        i--;
    }
    
    
    
    i =sizeof(arr)/sizeof(*arr)-1;
    // Subtraction Testing
    while (i > 0){
        a.setNumbers(arr[i][0], arr[i][1]);
        b.setNumbers(arr[i][2], arr[i][3]);
        trueNum = a.getNum() * b.getDen() - b.getNum() * a.getDen();
        trueDen = a.getDen() * b.getDen();
        c.setNumbers(trueNum, trueDen);
        c.reduceFraction();
        d = a - b;
        cout << "Testing Subtraction: " << a << " - " << b << " = ";
        if (d == c){
            cout << "..passed " << d << "\n";
            pass++;
        }
        else 
            cout << "..FAIL";
        i--;
    }
    
    
    i =sizeof(arr)/sizeof(*arr)-1;
    // Multiplication Testing
    while (i > 0){
        a.setNumbers(arr[i][0], arr[i][1]);
        b.setNumbers(arr[i][2], arr[i][3]);
        trueNum = a.getNum() * b.getNum();
        trueDen = a.getDen() * b.getDen();
        c.setNumbers(trueNum, trueDen);
        c.reduceFraction();
        d = a * b;
        cout << "Testing Multiplication: " << a << " * " << b << " = ";
        if (d == c){
            cout << "..passed " << d << "\n";
            pass++;
        }
        else 
            cout << "..FAIL";
        i--;
    }
    
    i =sizeof(arr)/sizeof(*arr)-1;
    // Division Testing
    while (i > 0){
        a.setNumbers(arr[i][0], arr[i][1]);
        b.setNumbers(arr[i][2], arr[i][3]);
        trueNum = a.getNum() * b.getDen();
        trueDen = a.getDen() * b.getNum();
        c.setNumbers(trueNum, trueDen);
        c.reduceFraction();
        d = a / b;
        cout << "Testing Multiplication: " << a << " / " << b << " = ";
        if (d == c){
            cout << "..passed " << d << "\n";
            pass++;
        }
        else 
            cout << "..FAIL";
        i--;
    }
    
    if (pass == 40)
        cout << "ALL TESTS PASSED \n";
}

void relationalOperatorTesting (){
    int pass = 0;
    int count = 0;
    Fraction a;
    Fraction b;
    Fraction c;
    Fraction d;
    
    int arr[13][2] = {{287,70}, {2,12}, {63,1},{12,124}, {13,1}, {5,-2}, {-13,21}, {8,9}, {83,-9}, {5,-2}, {45,38}, {63,1}, {287,70}};
    
    
    int i =sizeof(arr)/sizeof(*arr)-1;
    // eqality operator Testing
    while (i > 0){
        a.setNumbers(arr[i][0], arr[i][1]);
        for (int k = 0; k< sizeof(arr)/sizeof(*arr)-1; k++){
            b.setNumbers(arr[k][0], arr[k][1]);
            cout << "Testing Equality: " << a << " == " << b;
            count++;
            if ((a == b) == (a.getFloat() == b.getFloat())){
                cout << "..passed " << "\n";
                pass++;
            }
            else 
                cout << "..FAIL";
        }
        i--;
    }
    
    
    i =sizeof(arr)/sizeof(*arr)-1;
    // ineqality operator Testing
    while (i > 0){
        a.setNumbers(arr[i][0], arr[i][1]);
        for (int k = 0; k< sizeof(arr)/sizeof(*arr)-1; k++){
            b.setNumbers(arr[k][0], arr[k][1]);
            cout << "Testing InEquality: " << a << " != " << b;
            count++;
            if ((a != b) == (a.getFloat() != b.getFloat())){
                cout << "..passed " << "\n";
                pass++;
            }
            else 
                cout << "..FAIL";
        }
        i--;
    }



    
    i =sizeof(arr)/sizeof(*arr)-1;
    // Less Than Testing
    while (i > 0){
        a.setNumbers(arr[i][0], arr[i][1]);
        for (int k = 0; k< sizeof(arr)/sizeof(*arr)-1; k++){
            b.setNumbers(arr[k][0], arr[k][1]);
            cout << "Testing Less Than: " << a << " < " << b;
            count++;
            if ((a < b) == (a.getFloat() < b.getFloat())){
                cout << "..passed " << "\n";
                pass++;
            }
            else 
                cout << "..FAIL" << a << ' '<< b << ' '<< a.getFloat() << ' ' << b.getFloat() << "\n";
        }
        i--;
    }
    
    i =sizeof(arr)/sizeof(*arr)-1;
    // Less Than Testing
    while (i > 0){
        a.setNumbers(arr[i][0], arr[i][1]);
        for (int k = 0; k< sizeof(arr)/sizeof(*arr)-1; k++){
            b.setNumbers(arr[k][0], arr[k][1]);
            cout << "Testing Less Than Equal To: " << a << " <= " << b;
            count++;
            if ((a <= b) == (a.getFloat() <= b.getFloat())){
                cout << "..passed " << "\n";
                pass++;
            }
            else 
                cout << "..FAIL" << a << ' '<< b << ' '<< a.getFloat() << ' ' << b.getFloat() << "\n";
        }
        i--;
    }
    
    i =sizeof(arr)/sizeof(*arr)-1;
    // Greater Than Testing
    while (i > 0){
        a.setNumbers(arr[i][0], arr[i][1]);
        for (int k = 0; k< sizeof(arr)/sizeof(*arr)-1; k++){
            b.setNumbers(arr[k][0], arr[k][1]);
            cout << "Testing Less Than: " << a << " > " << b;
            count++;
            if ((a > b) == (a.getFloat() > b.getFloat())){
                cout << "..passed " << "\n";
                pass++;
            }
            else 
                cout << "..FAIL" << a << ' '<< b << ' '<< a.getFloat() << ' ' << b.getFloat() << "\n";
        }
        i--;
    }
    
    i =sizeof(arr)/sizeof(*arr)-1;
    // Greater Than Equal To Testing
    while (i > 0){
        a.setNumbers(arr[i][0], arr[i][1]);
        for (int k = 0; k< sizeof(arr)/sizeof(*arr)-1; k++){
            b.setNumbers(arr[k][0], arr[k][1]);
            cout << "Testing Greater Than Equal To: " << a << " >= " << b;
            count++;
            if ((a >= b) == (a.getFloat() >= b.getFloat())){
                cout << "..passed " << "\n";
                pass++;
            }
            else 
                cout << "..FAIL" << a << ' '<< b.getNum() << b.getDen() << ' '<< a.getFloat() << ' ' << b.getFloat() << (a >= b) << (a.getFloat() >= b.getFloat()) << "\n";
        }
        i--;
    }
    if (pass == count)
        cout << "ALL TESTS PASSED\n";

    
    
}



int main (){
    arithmeticTesting();
    relationalOperatorTesting();
}