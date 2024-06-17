//
//  main.cpp
//  ch6
//
//  Created by Drew Giambattista on 6/4/24.
//

#include <iostream>
#include "std_lib_facilities.h"

double expression();
double term();
double primary();
char get_token();

int main() {
//   Calculator first attempt
    
    try {
        while (cin)
            cout<<expression()<<'\n';
        keep_window_open();
    }
    catch (exception& e) {
        cerr<<e.what()<<'\n';
        keep_window_open();
        return 1;
    }
    catch (...) {
        cerr<<"exception \n";
        keep_window_open();
        return 2;
    }
    
    
    
    
    
    
    
    
    
    return 0;
}

class Token {
public:
    char kind;
    double value;
};

char get_token()
{
    char tmp;
    cin>>tmp;
    return tmp;
}

double expression()
{
    double left = term();
    Token t = get_token();
    while (true) {
        switch (t.kind) {
            case '+':
                left += term();
                t = get_token();
                break;
            case '-':
                left -= term();
                t = get_token();
                break;
            default:
                return left;
        }
    }
}

double term()
{
    double left = primary();
    Token t = get_token();
    while (true) {
        switch (t.kind) {
            case '*':
                left *= primary();
                t = get_token();
                break;
            case '/':
                left /= primary();
                t = get_token();
                break;
            default:
                return left;
        }
    }
}

double primary()
{
    Token t = get_token();
    switch (t.kind) {
        case '(':
            {
                double d = expression();
                t = get_token();
                if (t.kind != ')') error("')' expected");
                return d;
                
            }
        case '8':
            return t.value;
            
        default:
            error("primary exprected");
    }
}
