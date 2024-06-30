//
//  main.cpp
//  ch7
//
//  Created by Drew Giambattista on 6/27/24.
//

//#include <iostream>
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token{
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full {false};        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
    :full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback()
const char number = '8';

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
//        buffer =
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case '=':    // for "print"
    case 'x':    // for "quit"
    case '(': case ')': case '{': case '}':  case '+': case '-': case '*': case '/': case '!':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);         // put digit back into the input stream
        double val;
        cin >> val;              // read a floating-point number
        return Token(number, val);   // let '8' represent "a number"
    }
    default:
        error("Bad token");
        return Token(' ');
    }
}

int factorial(int num) {
    if (num == 0) {
        return 1;
    }
    else {
        for (int i = num; i > 0; --i) {
            if (i > 1) num *= i-1;
//            cout<<"num in f: "<<num<<endl;
        }
//        cout<<"num in res: "<<num<<endl;
        return num;
    }
}


double expression();    // declaration so that primary() can call expression()



//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '{':
    {
        double d = expression();
        t = ts.get();
        if (t.kind != '}') error("'}' expected");
            return d;
    }
            
    case '(':    // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
            return d;
    }
    case number:           // we use '8' to represent a number
    {
//      Int conversion for factorial
        int num = t.value;
        int result = num;
        
//      Checking for factorial suffix
        t = ts.get();
        if (t.kind == '!') {
            result = factorial(num);
        } else {
            ts.putback(t);
        }
        cout<<"result: "<<result<<endl;
        return result;  // return the number's value
    }
    case '-':
        return - primary();
    case '+':
        return primary();
    default:
        error("primary expected");
        return 1;
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '*':
            cout<<"* case entered!"<<endl;
            left *= primary();
//            cout<<"left in * case: "<<left<<endl;
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        case '%':
        {
            double d = primary();
            if (d==0) error("divide by zero");
            left = fmod(left,d);
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

double val = 0;
const char quit = 'q';
const char print = ';';
const string prompt = "> ";
const string result = "= ";

void calculate()
{
    while (cin) {
        cout<<prompt;
        Token t = ts.get();

        while (t.kind == print) t = ts.get();
        if (t.kind == quit) return;
        ts.putback(t);
        cout << result << expression() << '\n';
    }
}

int main() {
    
    try
    {
//        cout << "Welcome to our simple calculator. Please enter expressions using floating-point numbers." << endl;
//        cout << "The available operators are: +, -, *, / \nUse '=' after an expression to print and 'x' to quit.\n" << endl;
        calculate();
        keep_window_open();
        return 0;
    }
    catch (exception& e) {
        cerr << "error: " << e.what() << '\n';
        keep_window_open("~~");
        return 1;
    }
    catch (...) {
        cerr << "Oops: unknown exception!\n";
        keep_window_open();
        return 2;
    }
    
    return 0;
}
