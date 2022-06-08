#include <random>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

default_random_engine generator;
uniform_int_distribution<int> distribution(0,2);

bool testRandomSelector(string (*RandomSelector)()){
    string retval;
    int rock_counter = 0;
    int paper_counter = 0;
    int scissors_counter = 0;
    
    for (int i = 0; i < 1000; i++){
        retval = RandomSelector();
        if (retval != "rock" && retval != "scissors" && retval != "paper"){
            return false;
        }
        if (retval == "rock"){
            rock_counter++;
        }
        if (retval == "scissors"){
            scissors_counter++;
        }
        if (retval == "paper"){
            paper_counter++;
        }
    }
    if (rock_counter < 250 || paper_counter < 250 || scissors_counter < 250){
        return false;
    }
    return true;
}

bool testValidateUserInput(string (*ValidateUserInput)(string input)){
    string userInputs[3] = {"rock", "scissors", "paper"};
    string jokerInputs[3] = {"shacoTank", "HAHAHAHA", "why so serious"};
    for (int i = 0; i < 3; i++){
        string input = userInputs[i];
        string testResult = ValidateUserInput(input);
        if (testResult != "valid"){
            return false;
        } 
    }
    for (int i = 0; i < 3; i++){
        string input = jokerInputs[i];
        string testResult = ValidateUserInput(input);
        if (testResult != "invalid"){
            return false;
        }
    }
    return true;
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
    if (playerChoice == "scissors"){
        if (computerChoice == "rock"){
            return "computer";
        }
        if (computerChoice == "scissors"){
            return "tie";
        }
        if (computerChoice == "paper"){
            return "player";
        }
    }
    else if (playerChoice == "rock"){
        if (computerChoice == "scissors"){
            return "player";
        }
        if (computerChoice == "rock"){
            return "tie";
        }
        if (computerChoice == "paper"){
            return "computer";
        }
    }
    else{ //paper
        if (computerChoice == "scissors"){
            return "computer";
        }
        if (computerChoice == "paper"){
            return "tie";
        }
        else{
            return "player";
        }
    }
    return "none";
}

string RandomSelector(){
    int num = distribution(generator);
    if (num == 0){
        return "rock";
    }
    if (num == 1){
        return "scissors";
    }
    if (num == 2){
        return "paper";
    }
    return "abuble";
}

string ValidateUserInput(string input){
    if (input == "rock" || input == "scissors" || input == "paper"){
        return "valid";
    }
    else{
        return "invalid";
    }
}

int runTests(){
    int testsPassed = 0;
    int testsFailed = 0;

    string (*defWinningPlayer)(string a, string b);
    defWinningPlayer = &DefineWinningPlayer;
    bool test = testDefineWinningPlayer(defWinningPlayer);
    if (test == false){
        cout << "test failed in DefineWinningPlayer function" << endl;
        testsFailed++;
    }
    else{
        testsPassed++;
    }
    test = testValidateUserInput(&ValidateUserInput);
    if (test == false){
        cout << "test failed in ValidateUserInput function" << endl;
        testsFailed++;
    }
    else{
        testsPassed++;
    }
    test = testRandomSelector(&RandomSelector);
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