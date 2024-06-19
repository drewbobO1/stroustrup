//
//  main.cpp
//  ch5
//
//  Created by Drew Giambattista on 5/4/24.
//

#include <iostream>
#include "std_lib_facilities.h"

int area(int length, int width) {
    if (length <= 0 || width <= 0) error("area() pre-condition");
    int a = width*length;
    cout<<"a: "<<a<<'\n';
    if (a <= 0) error("area() post-condition");
    return a;
}

int framed_area(int x, int y) {
    return area(x-2,y-2);
}

int f(int x, int y, int z) {
    int area1 = area(x,y);
    if (area1<=0) error("non-positive area");
//    int area2 = framed_area(1, z);
    int area3 = framed_area(y, z);
    double ratio = double(area1)/area3;
    return ratio;
//    ??? Can't deduce how the example is supposed to play out
}

//  Ex. #2-5

//    Broken function
    
//    double ctok(double c) {
//    int k = c + 273.15;
//    return int }
    
//    Fixed function

double convertCK(char unit, double amt) {
//    try {
    if (unit == 'c') {
        if (amt < -273.15) {
            error("Temperature is too low");
        }
        double k = amt + 273.15;
        return k;
    } else if (unit == 'k') {
        if (amt < 0) {
            error("Temperature is too low");
        }
        double c = amt - 273.15;
        return c;
    } else {
        cout<<"Please enter a unit abbreviation ('c' or 'k') and a corresponding temperature as prompted.\n";
        return 1;
    }
    
    
//    Tried to do handling in the function as specified for #4 but it proved too challenging (currently) to try to do a proper catch inside the function.
//    }
//    catch (runtime_error& e) {
//        cerr<<"error: "<<e.what()<<'\n';
//        keep_window_open();
//        return 1;
//    }
}

double convertFC(char unit, double amt) {
    if (unit == 'c') {
//      Conversion process
        double f = ((9.0/5)*amt)+32;
        
//      Estimation check
        if (f > amt*2 + 32) error("post-check -- result is too big");
        
        return f;
    } else if (unit == 'f') {
//      Conversion process
        double c = 5.0/9*amt-32;
        
//      Estimation check
        if (c > amt*.7 + 32) error("post-check -- result is too big");
        
        return c;
    } else {
        cout<<"Please enter a unit abbreviation ('c' or 'f') and a corresponding temperature as prompted.\n";
        return 1;
    }
}



int main(void) {
//    ==================
//            5.3
//    ==================
    
//    int s1 = area(7;
//    int s2 = area(7)
//    Int s3 = area(7);
//    int s4 = area('7);
                  
//    ==================
//            5.5
//    ==================
    
//    Defined area and framed_area functions above main
    
//    ==================
//            5.6
//    ==================
    
//    int x = -1;
//    int y = 2;
//    int z = 4;
//    
//    int area1 = area(x,y);
//    int area2 = framed_area(1, z);
//    int area3 = framed_area(y, z);
//    double ratio = double(area1)/area3;
    
//    try {
//     // <<your code here>>
//        cout << "Success!\n";
//        return 0;
//    }
//    catch (exception& e) {
//        cerr << "error: " << e.what() << '\n';
//        keep_window_open();
//        return 1;
//    }
//    catch (...) {
//        cerr << "Oops: unknown exception!\n";
//        keep_window_open();
//        return 2;
//    }
    
//    try {
//        bool testVal = false;
//        
//        if (testVal) {
//            cout<<"Working hurray";
//        } else {
//            error("Error in ", "testVal");
//        }
//    }
//    catch (runtime_error& e) {
//        cerr<<"error: "<<e.what()<<'\n';
//        keep_window_open();
//        return 1;
//    }
    
//    ==================
//            5.7
//    ==================
    
//    vector<double> temps;
    
//  Flawed version
    
//    for (double temp; cin>>temp; )
//        temps.push_back(temp);
    
//    double sum = 0;
//    double high_temp = 0;
//    double low_temp = 0;
//    
//    for (int x : temps)
//    {
//        if (x > high_temp) high_temp = x;
//        if (x < low_temp) low_temp = x;
//        sum += x;
//    }

//  Better version
    
//    double sum = 0;
//    double high_temp = -200;
//    double low_temp = 200;
//    int no_of_temps = 0;
//    
//    for (double temp; cin>>temp; ) {
//        ++no_of_temps;
//        sum+= temp;
//        if (temp > high_temp) high_temp = temp;
//        if (temp < low_temp) low_temp = temp;
//    }
//    
//    cout<<"High tempurature: "<<high_temp<<'\n';
//    cout<<"Low temp: "<<low_temp<<'\n';
//    cout<<"Average temp: "<<sum/no_of_temps<<'\n';
    
//    return 0;
    
//    ==================
//            5.10
//    ==================
    
//    int a = 0;
//    int b = 0;
//    
//    cin>>a>>b;
//    
//    try {
//        int dingus = area(a, b);
//        cout<<dingus<<'\n';
//    }
//    catch (runtime_error& e) {
//        cerr<<"error: "<<e.what()<<'\n';
//        keep_window_open();
//        return 1;
//    }
    
    
    
//    ==================
//         Exercises
//    ==================
    
//  #2
    
//    double amt = 0;
//    char unit;
//    
//    cout<<"Please enter either 'f' or 'c' for the unit type you'd like to convert from: ";
//    cin >> unit;
//    cout<<"\nNow, please enter the measurement you'd like converted: ";
//    cin>>amt;
    
//    Pass unit type as arg to conversion function and modify it to handle that
    
//    try {
// //        double result = convertCK(unit, amt);
//        double result = convertFC(unit, amt);
//        cout<<result<<'\n';
//    }
//    catch (runtime_error& e) {
//        cerr<<"error: "<<e.what()<<'\n';
//        keep_window_open();
//        return 1;
//    }
//   
    
    
    
//  #8
    
//    int sumQty = 0;
//    vector<int> numbas;
//    
//    cout<<"Please enter the number of values you want to sum: ";
//    cin>>sumQty;
//    
//    cout<<"Please enter some integers (press '|' to stop): ";
//    
//    int tmp;
//    while (cin>>tmp)
//    {
//        numbas.push_back(tmp);
//    }
//    
//    try {
//        if (sumQty > numbas.size()) {
//            error("cannot sum more numbers than are present");
//        } else if (sumQty < numbas.size()) {
//            int sum = 0;
//            cout<<"The sum of the first "<<sumQty<<" numbers ( ";
//            for (int i = 0; i < sumQty; ++i) {
//                sum += numbas[i];
//                cout<<numbas[i]<<' ';
//            }
//            
//            int castInt = narrow_cast<int>(sum);
//            
//            cout<<") is "<<castInt<<".\n";
//        }
//    }
//    catch (runtime_error& e) {
//        cerr<<"error: "<<e.what()<<'\n';
//        keep_window_open();
//        return 1;
//    }
    
    
    
//  #9
    
//    int sumQty = 0;
//    vector<double> numbas;
//    vector<double> differences;
//    
//    cout<<"Please enter the number of values you want to sum: ";
//    cin>>sumQty;
//    
//    cout<<"Please enter some integers (press '|' to stop): ";
//    
//    double tmp;
//    while (cin>>tmp)
//    {
//        numbas.push_back(tmp);
//    }
//    
//    try {
//        if (sumQty > numbas.size()) {
//            error("cannot sum more numbers than are present");
//        } else if (sumQty < numbas.size()) {
//            int sum = 0;
// //            cout<<"The sum of the first "<<sumQty<<" numbers ( ";
//            for (int i = 0; i < sumQty; ++i) {
//                sum += numbas[i];
// //                cout<<numbas[i]<<' ';
//            }
//            
// //            int castInt = narrow_cast<int>(sum);
//
//            for (int j = 0; j<numbas.size(); ++j) {
//                if (j>0) {
//                    double dif = numbas[j-1] - numbas[j];
// //                    cout<<"Dif: "<<dif<<'\n';
//                    differences.push_back(dif);
//                }
//            }
//            
// //            cout<<") is "<<castInt<<".\n";
//        }
//    }
//    catch (runtime_error& e) {
//        cerr<<"error: "<<e.what()<<'\n';
//        keep_window_open();
//        return 1;
//    }
// //    cout<<"Wowow";
//    for (double dif : differences) {
//        if (dif < 0) dif = dif*-1;
//        cout<<"Difference: "<<dif<<'\n';
//    }
    
    
    
//    #11 - Fibonacci sequence
    
//    int limit = 0;
//    vector<int> fiboSeq;
//    
//    cout<<"Please enter an upper limit for the Fibonacci sequence: ";
//    cin>>limit;
//    
//    int startingNum = 1;
//    
//    while (fiboSeq.size() < limit) {
//        if (fiboSeq.size() < 2) {
//            fiboSeq.push_back(startingNum);
//        }
//        else if (fiboSeq.size() >= 2) {
//            int nextEl = fiboSeq.back() + fiboSeq[fiboSeq.size()-2.0];
//            fiboSeq.push_back(nextEl);
//        }
//    }
//    
//    for (int el : fiboSeq) {
//        cout<<el<<'\n';
//    }
    
    

//    #12 & 13- Bulls and cows
    
    vector<int> key;
    vector<int> guess;
    int usrGuess = 0;
    
    bool perfectMatch = false;
    bool endGame = true;
    
    int seed = 0;
    
    while (true) {
        if (endGame) {
            endGame = false;
            cout<<"Please roll for a random set of numbers by entering any number here: ";
            cin>>seed;
            
            key.clear();
            for (int i = 0; i < 4; ++i) {
                key.push_back(randint(seed));
            }
        }
        
        bool mismatchDetected = false;
        int bullCount = 0;
        int cowCount = 0;
        
        cout<<"Please attempt to guess the 4 digit number (must be in order): ";
        cin>>usrGuess;
        
        
        //  Converts guess to vector
        while (usrGuess)
        {
            //      Get last digit
            int lastDigit = usrGuess%10;
            
            //      Add to vector for inputted guess
            guess.push_back(lastDigit);
            
            //      Remove last digit from answer
            usrGuess /= 10;
        }
        
        for (int i = 0; i < key.size(); ++i) {
            int guessDigit = guess[((guess.size()-1.0)-i)];
            
            //      If position and digit are correct
            if (guessDigit == key[i]) {
                bullCount += 1;
                if (i == (key.size()-1.0) && !mismatchDetected) perfectMatch = true;
            } else {
                mismatchDetected = true;
                for (int keyDigit : key) {
                    if (keyDigit == guessDigit) {
                        cowCount += 1;
                    }
                }
            }
        }
        
        if (perfectMatch) {
            cout<<bullCount<<" correct guesses - Perfect score!\n";
            endGame = true;
        }
        else cout<<bullCount<<" bulls and "<<cowCount<<" cows.\n";
    }

    
    
//    #14 - Days of the week
    
//    vector<string> dayList;
//    vector<int> donutList;
//    
//    vector<string> validDays = {"Monday", "monday", "MON", "Mon", "mon", "Tuesday", "tuesday", "TUE", "Tue", "tue", "Wednesday", "wednesday", "WED", "Wed", "wed", "Thursday", "thursday", "THU", "Thu", "thu", "Friday", "friday", "FRI", "Fri", "fri", "Saturday", "saturday", "SAT", "Sat", "sat", "Sunday", "sunday", "SUN", "Sun", "sun"};
//    
//    int invalidDaysQty = 0;
//    
// //    int dayValSum = 0; -- What is this? Does he want me to add the int values of the strings? Actually that could make sense, they could be fed into a sorting algorithm then maybe? Except the days of the week aren't in alphabetical order, a different algorithm not relying on this would be more practical perhaps?
//
//    int donutValSum = 0;
//    
//    string enteredDay = "";
//    int donutQty = 0;
//        
//    while (static_cast<void>(cout<<"Please enter a day of the week (enter | to quit): "), cin>>enteredDay) {
//        try {
//            bool dayIsValid = false;
//            
//            for (string day : validDays) {
//                if (day == enteredDay) {
//                    dayIsValid = true;
//                }
//            }
//            
//            if (dayIsValid) {
//                cout<<"Now please enter a corresponding integer: ";
//                cin>>donutQty;
//                
//                dayList.push_back(enteredDay);
//                donutList.push_back(donutQty);
//                
//            }
//            else {
//                if (enteredDay == "|") break;
//                invalidDaysQty += 1;
//                cerr<<"Invalid day name - Please enter a valid day: \n";
//                continue;
//            }
//        } catch (runtime_error& e) {
//            cerr<<"error: "<<e.what()<<'\n';
//            return 1;
//        }
//    }
//    
//
//    
//    for (int i = 0; i < dayList.size(); ++i) {
//        string day = dayList[i];
//        
//        int count = donutList[i];
//        donutValSum += count;
//        
//        cout<<day<<": "<<count<<'\n';
//    }
//    
//    cout<<invalidDaysQty<<" invalid days entered.\n";

}

void error (string s1, string s2)
{
    throw runtime_error(s1+s2);
}
