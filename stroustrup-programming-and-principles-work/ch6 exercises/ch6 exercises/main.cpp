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

//  #6


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

//  #8 - Bulls and cows
    
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
