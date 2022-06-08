#include <random>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

bool testRandomSelector(string (*RandomSelector)(int)){
    return false;
}

bool testValidateUserInput(string (*GetUserInput)(string input)){
    return false;
}

bool testDefineWinningPlayer(string (*DefineWinningPlayer)(string playerChoice, string computerChoice)){
    string playerChoices[3] = {"rock", "paper", "scissors"};
    string computerChoices[3] = {"rock", "paper", "scissors"};
    string playerChoice;
    string computerChoice;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            playerChoice = playerChoices[i];
            computerChoice = computerChoices[j];
            if (i == j){
                if (DefineWinningPlayer(playerChoice, computerChoice) != "tie"){
                    return false;
                }
            }
            if (j == (i + 1) % 3){
                if (DefineWinningPlayer(playerChoice, computerChoice) != "computer"){
                    return false;
                }
            }
            if (j == (i + 2) % 3){
                if (DefineWinningPlayer(playerChoice, computerChoice) != "player"){
                    return false;
                }
            }
        }
    }
    return true;
}

string DefineWinningPlayer(string playerChoice, string computerChoice){
    return "abuble";
}

string RandomSelector(int seed){
    return "abuble";
}

string ValidateUserInput(string input){
    return "abuble";
}

int runTests(){
    bool test = testDefineWinningPlayer(DefineWinningPlayer);
    int testsPassed = 0;
    int testsFailed = 0;
    if (test == false){
        cout << "test failed in DefineWinningPlayer function" << endl;
        testsFailed++;
    }
    else{
        testsPassed++;
    }
    test = testValidateUserInput(ValidateUserInput);
    if (test == false){
        cout << "test failed in ValidateUserInput function" << endl;
        testsFailed++;
    }
    else{
        testsPassed++;
    }
    test = testRandomSelector(RandomSelector);
    if (test == false){
        cout << "test failed in RandomSelector function" << endl;
        testsFailed++;
    }
    else{
        testsPassed++;
    }

    cout << "Tests passed: " << testsPassed << endl;
    cout << "Tests failed: " << testsFailed << endl;
    return testsFailed;
}

int main(){

    int testsFailed = runTests();
    if (testsFailed > 0){
        exit(0);
    }
}