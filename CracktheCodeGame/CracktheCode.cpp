/*--------------------------------------------------------------------
File: CracktheCode.cpp
Description: N/A
Compiler: Min gw c++ compiler  
Notes: N/A
--------------------------------------------------------------------*/
#include <iostream> 
#include <ctime> //Used for seeding rand()

using std::cout; 
using std::endl;
using std::cin; 

//Prototypes 
bool GamePlay(int GameDifficulty); //Contains all the gameplay functionality
void PrintIntro(int GameDifficulty); //Prints game message to user

/*---------------------------------------------
Function: main()
Description: Runs the main loop of program so that the game runs properly. It
manages the game's difficulty as well as ending. 
Returns: 0 
Notes: N/A
----------------------------------------------*/ 
int main() 
{ 
    srand(time(NULL)); //Seeds rand() so that the numbers are truely random 
    int GameDifficulty {1}; 
    const int MaxDifficulty {6}; 

    while(GameDifficulty <= MaxDifficulty) //Loops game until max level reached
    { 
        bool gameLevelComplete = GamePlay(GameDifficulty); 
        std::cin.clear(); //Clears any errors put into cin
        std::cin.ignore(); //Clears the cin buffer 

        if(gameLevelComplete)
        {
            ++GameDifficulty; 
        }

    } 
        if(MaxDifficulty == 6)
        {
            cout << "\nYou've won and the robot flees in terror! Enjoy your car...\n";
        }
    return 0; 
}

/*---------------------------------------------
Function: PrintIntro()
Description: Displays starting message and game to user. 
Returns: Nothing (Void)
Notes: N/A
----------------------------------------------*/ 
void PrintIntro(int GameDifficulty)
{ 
    //Displays intro message to user
    cout << "\nA robot has locked your keys in your car!\n"; 
    cout << "He's a level " << GameDifficulty << " robot.\n";
    cout << "You must answer the robot's secret code " 
    << "correctly in order to get your keys back.\n"; 
    cout << "The robot will give you hints as to what the code is, " 
    << "if you fail, you'll never see your keys again....\n"; 
    cout << endl; 
    cout << "HINT: He's a robot so he can only do riddles with numbers...\n";
}

/*---------------------------------------------
Function: GamePlay()
Description: Contains the main game logic such as the randomized numbers and if/else 
logic that makes the game run correctly. It also seeds the numbers used for the game.
Returns: Nothing (Void)
Notes: N/A
----------------------------------------------*/ 
bool GamePlay(int GameDifficulty) 
{
    PrintIntro(GameDifficulty); //Shows start message
    
    /*Numbers for 3 number code 
    Range of numbers is 0 to n-1 of the modulus number, GameDifficulty
    Adding GameDifficulty to itself removes 0 from range*/
    const int CodeFirstNumber {rand() % GameDifficulty + GameDifficulty}; 
    const int CodeSecondNumber {rand() % GameDifficulty + GameDifficulty}; 
    const int CodeThirdNumber {rand() % GameDifficulty + GameDifficulty}; 

    const int CodeSum = CodeFirstNumber + CodeSecondNumber + CodeThirdNumber; 
    const int CodeProduct = CodeFirstNumber * CodeSecondNumber * CodeThirdNumber; 

    cout << "\n*There are 3 numbers in the code."; 
    cout << "\n*The code adds up to: " << CodeSum; 
    cout << "\n*The product of the code is: " << CodeProduct;
    cout << "\nPlease enter your guess below...\n"; 

    //User input
    int PlayerGuessOne, PlayerGuessTwo, PlayerGuessThree {};  
    cin >> PlayerGuessOne >> PlayerGuessTwo >> PlayerGuessThree; 
 
    int GuessSum = PlayerGuessOne + PlayerGuessTwo + PlayerGuessThree; 
    int GuessProduct = PlayerGuessOne * PlayerGuessTwo * PlayerGuessThree; 

    //Done so win message not displayed with endgame message
    if(GameDifficulty < 6)
    {
        //Checks if player guess matches true answer
        if(GuessSum == CodeSum && GuessProduct == CodeProduct) 
            {
                cout << "You've won this time and the robot will return!\n";   
                cout << "Loading next level...\n";
                return true;
            }
        else 
            { 
                cout << "I'm sorry but the robot wins and you will never get your keys back.\n"; 
                cout << "The robot laughs at you..." << "He taunts you to try again.\n";
                return false;
            }
    }
    else
    {
        return true; //Makes it where win message doesn't display again
    }
}
