//
//  main.cpp
//  ch7
//
//  Created by Drew Giambattista on 6/27/24.
//

//#include <iostream>
#include "std_lib_facilities.h"
//#include "stdlib.h"

double val = 0;
const char quit = 'q';
const char print = ';';
const string prompt = "> ";
const string result = "= ";
const char name = 'a';
const char let = 'l';
const string declkey = "let";


//------------------------------------------------------------------------------

class Token{
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value
    string name;
    Token(char ch)    // make a Token from a char
        :kind{ch} { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind{ch}, value{val} { }
    Token(char ch, string n)
        :kind{ch}, name{n} { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
    void ignore(char c);
private:
    bool full {false};        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

class Variable {
public:
    string name;
    double value;
    
//    Variable(string givenName, double givenValue) {
//        this->name = givenName;
//        this->value = givenValue;
//    }
    Variable(string givenName, double givenValue)
        :name(givenName), value(givenValue) { }
    

};

//------------------------------------------------------------------------------

vector <Variable> var_table;

//------------------------------------------------------------------------------

double get_value(string s)
{
//    cout<<"s (input arg to get_value): "<<s<<endl;
    for (const Variable& v : var_table) {
//        cout<<"v.name: "<<v.name<<endl;
        if (v.name==s) return v.value;
    }
    error("get: undefined variable ", s);
    return 1;
}

void set_value(string s, double d)
{
    for (Variable& v : var_table)
        if (v.name==s) {
            v.value = d;
            return;
        }
    error("set: undefined variable ", s);
}

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
//  Read characters from cin and compose/make a Token
{
    if (full) {       // check if we already have a Token ready
        // remove token from buffer
//        buffer =
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case quit:
    case print:
    case '(': 
    case ')': 
    case '{':
    case '}':
    case '+':
    case '-':
    case '*':
    case '/':
    case '!':
    case '%':
    case '=':
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
            if (isalpha(ch)) {
                cin.putback(ch);
                string s;
                cin >> s;
                if (s == declkey) return Token(let);
//                if (s == name) return Token(name);
                return Token{name,s};
            }
        error("Bad token");
        return Token(' ');
    }
}

void Token_stream::ignore(char c)
{
    if (full && c==buffer.kind) {
        full = false;
        return;
    }
    full = false;
    
    char ch = 0;
    while (cin>>ch)
        if (ch==c) return;
}

void clean_up_mess()
{
    ts.ignore(print);
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


//------------------------------------------------------------------------------

double declaration();
double expression();    // declaration so that statement() and primary() can call expression()

double statement()
{
    Token t = ts.get();
    switch (t.kind) {
        case let:
//            cout<<"Triggered the 'let' case"<<endl;
            return declaration();
        default:
            ts.putback(t);
            return expression();
    }
}

bool is_declared(string var)
{
    for (const Variable& v : var_table) {
        if (var == v.name) return true;
    }
    return false;
}

double define_name(string var, double val)
{
    if (is_declared(var)) error(var, "declared twice");
    var_table.push_back(Variable(var, val));
    return val;
}

double declaration()
{
    Token t = ts.get();
    if (t.kind != name) error("name expected in declaration");
//    cout<<"Name was detected: "<<t.name<<endl;
    string var_name = t.name;
    
    Token t2 = ts.get();
//    cout<<"t2 should be '=': "<<t2.kind<<endl;
    if (t2.kind != '=') error("= missing in declaration of ", var_name);
    
    double d = expression();
    define_name(var_name,d);
    return d;
}

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
//    if (isalpha(t.kind))
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
//        cout<<"result: "<<result<<endl;
        return result;  // return the number's value
    }
    case '-':
        return - primary();
    case '+':
        return primary();
//    case '=':
//        return primary();
    default:
//        cout<<"t.kind: "<<t.name<<endl;
        if (isalpha(t.kind)) {
//            cout<<"TOP: t.name: "<<t.name<<endl;
            string name = t.name;
//            cout<<"name: "<<name<<endl;
            double val = get_value(t.name);
//            cout<<"t.value: "<<t.value<<endl;
//            cout<<"BTM: val: "<<val<<endl;
            return val;
        }
        error("primary expected");
        return 1;
    }
}

//------------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = primary();
//    cout<<"Left primary call in term func: "<<left<<endl;
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
//        case '=':
//            left = expression();
            
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

void calculate()
{
    while (cin) {
        cout<<prompt;
        Token t = ts.get();

        while (t.kind == print) t = ts.get();
        if (t.kind == quit) return;
        ts.putback(t);
        cout << result << statement() << '\n';
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
