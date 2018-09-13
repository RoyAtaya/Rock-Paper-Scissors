/**
 * @file RockPaperScissors.cpp
 * @author Farid Roy Ataya
 * @Date   5/26/2018
 * @version 1.0
 * @section LA03
 * <This is a game for rock, paper, and scissors>
 */
// I declare that this assignment is my own work and that I have correctly acknowledged the
// work of others. I acknowledged that I have read and followed the Academic Honesty and
// Integrity related policies as outlined in the syllabus.
//
// Name: Farid Roy Ataya    Date:2018-05-26
// Student ID: 301161512
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Rps{
public:
    int player = 0;  // stores the value for the player's choice
    int cpu = 0;     // stores the value for the cpu's choice
    int result = 0;  // stores the value for the result of the game
    
    int PlayerChoice(void);                // gets choice from player and verifies that it is valid input and returns the choice
    int CpuChoice(void);                   // generates a choice for the cpu randomly using a random number generator
    int PlayGame(int player, int cpu);     // plays the game and determines who wins or if it is a tie
};

const int ROCK = 1;                 // Variable for rock
const int PAPER = 2;                // Variable for paper
const int SCISSORS = 3;             // Variable for scissors

int main(){
    Rps Human, Computer, Outcome; // Class variables
    cout << "Welcome to rock, paper, scissors" << endl; // title statement
    
    do {
        Human.player = Human.PlayerChoice();                               // calls the PlayerChoice function to ask the user to make a choice
        Computer.cpu = Computer.CpuChoice();                                  // calls the CpuChoice function to generate the cpu's choice
        Outcome.result = Outcome.PlayGame(Human.player, Computer.cpu);                     // plays the game and determines who wins or if it is a tie
        cout << endl;
    } while (Outcome.result == 0);
    
    return 0;
}


/**
 *   @brief  This function asks the player what their choice is and verfies that it is a valid input.
 *           It also returns the choice the player made as an integer.
 *
 *   @return int
 */
int Rps::PlayerChoice(void){
    string userInput = " "; // variable stores user input
    int userChoice = 0;     // variable to convert text choice to integer value
    int index = 0;
    bool isChar = false;    // used to exit do while loop in valid character entered
    
    // gets input from user
    do {
        isChar = false;
        cout << "Enter your choice for rock, paper, or scissors (as the first letter of the word ex: r for rock): ";
        cin >> userInput;
        cin.clear();
        cin.ignore(10000,'\n');
        
        // checks to make sure input is valid
        for (index = 0; index < userInput.length(); index++)
        {
            userInput[0] = tolower(userInput[0]); // converts the first character to lower case.
            // checks to see if what the user inputed is an alphabetic character
            if (isalpha(userInput[index]))
            {
                // checks to make sure the user only entered 1 character
                if (userInput.length() == 1)
                {
                    // assigns an integer value for user input for rock, paper, and scissors
                    if (userInput[0] == 'r')
                    {
                        userChoice = ROCK;
                        isChar = true;
                    }
                    else if (userInput[0] == 's')
                    {
                        userChoice = SCISSORS;
                        isChar = true;
                    }
                    else if (userInput[0] == 'p')
                    {
                        userChoice = PAPER;
                        isChar = true;
                    }
                    else
                    {
                        cerr << "ERROR: you entered: "<< userInput<< " which is not one of the allowed inputs." << endl << endl;
                        isChar = false;
                        break;
                    }
                }
                else
                {
                    cerr << "ERROR: you entered: "<< userInput<< " please only enter 1 character" << endl << endl;
                    isChar = false;
                    break;
                }
            }
            else
            {
                cerr << "ERROR: you entered: "<< userInput<< " which is not one of the allowed inputs." << endl << endl;
                break;
            }
        }
    } while (isChar == false);
    
    return userChoice;
}


/**
 *   @brief  This function generates a choice for the cpu randomly using a random number generator
 *           It also returns the choice the cpu made as an integer; and displays it onto the screen.
 *
 *   @return int
 */
int Rps::CpuChoice(void){
    int cpuChoice = 0;
    srand(time(NULL)); // using the time function to get a seed for the srand function allows me to have a truly somewhat randomn number generated by rand()
    cpuChoice = rand() % 3 + 1; // generates a random number between 1 and 3
    // the if-else block of code prints the choice of the computer
    if (cpuChoice == ROCK)
    {
        cout << "The computer chose rock." << endl;
        
    }
    else if (cpuChoice == SCISSORS)
    {
        cout << "The computer chose scissors." << endl;
        
    }
    else if (cpuChoice == PAPER)
    {
        cout << "The computer chose paper." << endl;
        
    }
    return cpuChoice;
}


/**
 *   @brief  This function plays the game and determines who wins or if it is a tie
 *
 *   @param  player is an initialized integer variable
 *   @param  cpu is an initialized integer variable
 *   @return int
 */
int Rps::PlayGame(int player, int cpu){
    // prints player won
    if ((cpu == ROCK && player == PAPER) || (cpu == PAPER && player == SCISSORS) || (cpu == SCISSORS && player == ROCK))
    {
        cout << "The player won" << endl;
        return 1;
    }
    // prints cpu won
    else if ((player == ROCK && cpu == PAPER) || (player == PAPER && cpu == SCISSORS) || (player == SCISSORS && cpu == ROCK))
    {
        cout << "The cpu won" << endl;
        return 1;
    }
    // prints out that it is a tie
    else {
        cout << "It's a tie, play again to see who will win" << endl;
    }
    return 0;
}
