//
//  main.cpp
//  ch6 exercises
//
//  Created by Drew Giambattista on 6/13/24.
//

#include "std_lib_facilities.h"

//  #4

class Name_value {
public:
    Name_value() : name(""), age(0) {};
    void makename(string enteredName, int enteredAge);
    void addname(Name_value nvp);
//private:
    string name;
    int age;
};

vector<Name_value> name_value_pairs {};

void Name_value::makename(string enteredName, int enteredAge)
{
    name = enteredName;
    age = enteredAge;
}

void Name_value::addname(Name_value nvp)
{
    name_value_pairs.push_back(nvp);
};

//  #6 - sentence grammar checker


vector<string> articles {
    "The", "the"
};

vector<string> conjunctions {
    "and", "or", "but"
};

vector<string> nouns {
    "birds", "fish", "C++"
};

vector<string> verbs {
    "rules", "fly", "swim"
};

bool sentenceFlag = true;

void checkSentence(string word);



//  #9 - char to int problem functions

int charToInt(char input) {
    return input - '0';
}

//  #10 - Permutations and combinations functions

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

int divide(int a, int b) {
    if (b == 0) throw runtime_error("Cannot divide by zero");
    return a/b;
}

int permutation(int a, int b)
{
    int numeratorFactorial = factorial(a);
    int denomFactorial = factorial((a-b));
    
    int perm = divide(numeratorFactorial, denomFactorial);
    
    if (perm <= a || perm <= b) throw runtime_error("Calculation issue--potential integer overload");
    
    return perm;
}

int combination(int a, int b) {
    int numeratorPerm = permutation(a, b);
    int denomFactorial = factorial(b);
    
    int comb = divide(numeratorPerm, denomFactorial);
    
    if (comb <= a || comb <= b) throw runtime_error("Calculation issue--potential integer overload");
    
    return comb;
}



int main() {
//    #19 - Name and age exercise modified for ch 6 ex 4

//    vector<string> names;
//    vector<int> ages;
//    
//    string enteredName = "";
//    int enteredAge = 0;
//    
//    cout<<"Please enter a name followed by an age separated by whitespace: ";
//    
//    while (cin>>enteredName>>enteredAge) {
//
// //      Does name already exist?
//        for (string name:names) {
//            if (enteredName == name) {
//                cout<<"Error: "<<enteredName<<" already exists in the names list.\n";
//                return 1;
//            }
//        }
//        
// //      Checking for terminating input
//        if (enteredName == "NoName" && enteredAge == 0) {
//            break;
//        }
//        Name_value n;
//        n.makename(enteredName, enteredAge);
//        n.addname(n);
//        
//    }
//    
//    for (int i = 0; i < name_value_pairs.size(); ++i) {
//        cout<<name_value_pairs[i].name<<", "<<name_value_pairs[i].age<<'\n';
//    }
    
//    #6 - English "grammar" checker
//    cout<<"Please enter a sentence!\n";
//    string newWord;
//    
//    while (cin>>newWord) {
//        checkSentence(newWord);
//    }
//    
//    if (sentenceFlag) cout<<"Is a sentence\n";
//    else if (!sentenceFlag) cout<<"Is not a sentence\n";

//  #8 - Bulls and cows but for letters
    
//    string key = "";
//    string usrGuess = "";
//
//    bool perfectMatch = false;
//    bool endGame = true;
//
//    int seed = 0;
//
//    while (true) {
//        if (endGame) {
//            endGame = false;
//            cout<<"Please roll for a random set of numbers by entering any number here: ";
//            cin>>seed;
//
//            for (int i = 0; i < 4; ++i) {
//                char letter = 97 + randint(seed);
//                key.push_back(letter);
//            }
//        }
//
//        bool mismatchDetected = false;
//        int bullCount = 0;
//        int cowCount = 0;
//
//        cout<<"Please attempt to guess the 4 letta word (must be in order): ";
//        cin>>usrGuess;
//
//        for (int i = 0; i < key.size(); ++i) {
//
//            //      If position and digit are correct
//            if (usrGuess[i] == key[i]) {
//                bullCount += 1;
//                if (i == (key.size()-1.0) && !mismatchDetected) perfectMatch = true;
//            } else {
//                mismatchDetected = true;
//                for (char letter : usrGuess) {
//                    if (letter == key[i]) {
//                        cowCount += 1;
//                    }
//                }
//            }
//        }
//
//        if (perfectMatch) {
//            cout<<bullCount<<" correct guesses - Perfect score!\n";
//            endGame = true;
//        }
//        else {
//            cout<<bullCount<<" bulls and "<<cowCount<<" cows.\n";
//            usrGuess = "";
//        }
//    }
    
//    #9 - Messing around with char int conversion
    
//    cout<<"Please enter a 1-4 digit number"<<endl;
//    string usrInput;
//    cin>>usrInput;
//    
//    int fullUsrInt = 0;
//    
//    int ones = 0;
//    int tens = 0;
//    int hundreds = 0;
//    int thousands = 0;
//    
//    switch (usrInput.size()) {
//        case 1: {
//            int newInt = charToInt(usrInput[0]);
//            cout<<newInt<<" is "<<newInt<<" ones."<<endl;
//            break;
//        }
//        case 2: {
//            cout<<"Size: "<<usrInput.size()<<endl;
//            for (long i = usrInput.size(); i > 0; --i) {
//                cout<<"i: "<<i<<endl;
//                switch (i) {
//                    case 2: {
//                        ones = charToInt(usrInput[i-1]);
//                        fullUsrInt += ones * 1;
//                        break;
//                    }
//                    case 1: {
//                        tens = charToInt(usrInput[i-1]);
//                        fullUsrInt += tens * 10;
//                        break;
//                    }
//                    default:
//                        break;
//                }
//            }
//            
//            cout<<fullUsrInt<<" is "<<tens<<" tens and "<<ones<<" ones."<<endl;
//        }
//            break;
//        case 3: {
//            for (long i = usrInput.size(); i > 0; --i) {
//                switch (i) {
//                    case 3: {
//                        ones = charToInt(usrInput[i-1]);
//                        fullUsrInt += ones * 1;
//                        break;
//                    }
//                    case 2: {
//                        tens = charToInt(usrInput[i-1]);
//                        fullUsrInt += tens * 10;
//                        break;
//                    }
//                    case 1: {
//                        hundreds = charToInt(usrInput[i-1]);
//                        fullUsrInt += hundreds * 100;
//                        break;
//                    }
//                    default:
//                        break;
//                }
//            }
//            
//            cout<<fullUsrInt<<" is "<<hundreds<<" hundreds and "<<tens<<" tens and "<<ones<<" ones."<<endl;
//        }
//            break;
//        case 4: {
//            for (long i = usrInput.size(); i > 0; --i)
//            {
//                switch (i) {
//                    case 4: {
//                        ones = charToInt(usrInput[i-1]);
//                        fullUsrInt += ones * 1;
//                        break;
//                    }
//                    case 3: {
//                        tens = charToInt(usrInput[i-1]);
//                        fullUsrInt += tens * 10;
//                        break;
//                    }
//                    case 2: {
//                        hundreds = charToInt(usrInput[i-1]);
//                        fullUsrInt += hundreds * 100;
//                        break;
//                    }
//                    case 1: {
//                        thousands = charToInt(usrInput[i-1]);
//                        fullUsrInt += thousands * 1000;
//                        break;
//                    }
//                    default:
//                        break;
//                }
//            }
//            
//            cout<<fullUsrInt<<" is "<<thousands<<" thousands and "<<hundreds<<" hundreds and "<<tens<<" tens and "<<ones<<" ones."<<endl;
//        }
//            break;
//            
//        default:
//            break;
//    }
    
    
    
//    #10 - Permutations and combinations
    
    
    try {
        cout<<"Do you want to calculate a permutation or a combination? (respond 'p' or 'c'): ";
        char calcType = ' ';
        cin>>calcType;
        
        switch (calcType) {
            case 'p': {
                cout<<"Please enter the two numbers for your permuatation: ";
                int a;
                int b;
                cin>>a>>b;
                
                int ans = permutation(a, b);
                cout<<"P: "<<ans<<endl;
                break;
            }
            case 'c': {
                cout<<"Please enter the two numbers for your combination: ";
                int a;
                int b;
                cin>>a>>b;
                
                int ans = combination(a, b);
                cout<<"C: "<<ans<<endl;
                break;
            }
            default:
                throw runtime_error("Invalid calculation type");
                break;
        }
    } catch (exception& e) {
        cerr << "error: " << e.what() << '\n';
        keep_window_open();
        return 1;
    }
    catch (...) {
        cerr << "Oops: unknown exception!\n";
        keep_window_open();
        return 2;
    }
    
    
    
    
    
    
    
    
    
}



// This is trickier than I first imagined. Need the function to work for each new word being fed into it. So, look behind/look ahead is requisite. Just need to only assign the last word to a variable once all its tests are passed.

string lastWord = "";

bool isArticle(string input) {
    for (string article : articles)
    {
        if (input == article) {
//            cout<<"this guy: "<<article<<" is an article :)"<<endl;
            return true;
        }
    }
    return false;
}

bool isNoun(string input) {
    for (string noun : nouns)
    {
        if (input == noun) {
//            cout<<"this guy: "<<noun<<" is a noun :)"<<endl;
            return true;
        }
    }
    return false;
}

bool isVerb(string input) {
    for (string verb : verbs)
    {
        if (input == verb) {
            return true;
        }
    }
    return false;
}

bool isConjunction(string input) {
    for (string conjunction : conjunctions)
    {
        if (input == conjunction) {
            return true;
        }
    }
    return false;
}

bool isEnd (string input) {
//    for (string verb : verbs) {
        if (input == ".") {
            return true;
        }
//    }
    return false;
}

void checkSentence(string word)
{
    bool articleStatus = isArticle(word);
    if (articleStatus) {
        cout<<"entered articleStatus:\n";
        cout<<"SENTENCE FLAG AT TOP: "<<sentenceFlag<<endl;
        articleStatus = false;
        bool conjunctionFound = false;
        
        for (string conjunction : conjunctions) {
            if (lastWord == "" || lastWord == conjunction) {
                conjunctionFound = true;
                lastWord = word;
                break;
            }
        }
        if (!conjunctionFound) sentenceFlag = false;
        cout<<"SENTENCE FLAG AT BTM: "<<sentenceFlag<<endl;
    }

    bool nounStatus = isNoun(word);
    if (nounStatus) {
        cout<<"entered nounStatus:\n";
        cout<<"SENTENCE FLAG AT TOP: "<<sentenceFlag<<endl;
        nounStatus = false;
        bool articleFound = false;
        
        for (string article : articles) {
            if (lastWord == "" || lastWord == article) {
                articleFound = true;
                lastWord = word;
                break;
            }
        }
        if (!articleFound) sentenceFlag = false;
        cout<<"SENTENCE FLAG AT BTM: "<<sentenceFlag<<endl;
    }
    
    bool verbStatus = isVerb(word);
    if (verbStatus) {
        cout<<"entered verbStatus:\n";
        cout<<"SENTENCE FLAG AT TOP: "<<sentenceFlag<<endl;
        verbStatus = false;
        bool nounFound = false;
        
        for (string noun : nouns) {
            if (lastWord == noun) {
                nounFound = true;
                lastWord = word;
                break;
            }
        }
        if (!nounFound) sentenceFlag = false;
        cout<<"SENTENCE FLAG AT BTM: "<<sentenceFlag<<endl;
    }
    
    bool conjunctionStatus = isConjunction(word);
    if (conjunctionStatus) {
        cout<<"entered conjunctionStatus:\n";
        cout<<"SENTENCE FLAG AT TOP: "<<sentenceFlag<<endl;
        conjunctionStatus = false;
        bool verbFound = false;
        
        for (string verb : verbs) {
            if (lastWord == verb) {
                verbFound = true;
                lastWord = word;
                break;
            }
        }
        if (!verbFound) sentenceFlag = false;
        cout<<"SENTENCE FLAG AT BTM: "<<sentenceFlag<<endl;
    }

    bool endStatus = isEnd(word);
    if (endStatus) {
        cout<<"entered endStatus:\n";
        cout<<"SENTENCE FLAG AT TOP: "<<sentenceFlag<<endl;
        endStatus = false;
        bool endVerbFound = false;
        
        for (string verb : verbs) {
            if (lastWord == verb) {
                endVerbFound = true;
                break;
            }
        }
        if (!endVerbFound) sentenceFlag = false;
        cout<<"SENTENCE FLAG AT BTM: "<<sentenceFlag<<endl;
    }
}
