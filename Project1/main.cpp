/* Program name: rock/paper/scissor and dice roll game
Version: October 16 2015
Programmer name: Tan Do
Purpose: To demonstrate my understanding of creation, compilation, and program submission
*/
// Algorithm:
// 1. User will pick a choice of game based on the menu
// 2. If the user picked the rock, paper, and scissor game than another menu displays
// 3. The user will pick rock paper or scissor
// 4. The user will lose or win based on what the program picks for itself
// 5. If the user picked the dice game than another menu displays
// 6. For the dice game, it will be random and the user will win points based on the rules
// 7. The program will exit if the user picks the "exit the program" option
/* Pseudo code:
    1. Program starts
    2. Displays menu of choice for the user
    3. If choice is 1 than the rock/paper/scissor menu will show
        -else if choice is 3, program will go back to menu
    4. If user picks Rock, than program will randomly pick one out of the 3 choices
    5. If user picks Paper, than program will randomly pick one out of the 3 choices
    6. If user picks Scissor, than program will randomly pick one out of the 3 choices
        else if choice is 4, program will go back to menu
    7. User will win or lose based on the program's choice
    8. If choice is 2 than the dice game menu will show
        -else if choice is 3, program will go back to menu
    9.  The dice game will show rules than start
    10. User will get points based on the rules
    11. Program loops for player to roll again
    12. else program will go back to menu
    13. Program stops
*/
//Headers included for certain data types to work
#include <iostream>
#include<iomanip>
#include<cstdlib>
#include<time.h>

using namespace std;
//This is the prototype
int menu();
int RPSmenu();
int Dicemenu();
int rollDice();
int DiceSum(); //This will calculate the dice sum if user picks to roll two dice


int main()
{  //Declare variables for user input and to hold functions
    int choice;
    //Function call and displays menu
    choice = menu();

}
//Function definition
int menu()
{
    //Declare variable for user input and holding functions
    int choice;
    int RockPaperSiccor;
    int DiceGame;
    cout<< "1. Play rock/paper/scissor game" << endl;
    cout << "2. Play Dice roll game" << endl;
    cout<< "3. Exit"<< endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        //Call function for the rock paper and scissor game
            RockPaperSiccor = RPSmenu();
        break;

    case 2:
        //Call function for dice game
            DiceGame = Dicemenu();
        break;

    case 3:
        cout <<"Program will exit";
        void exit();
        break;
    default :
        cout << "Please pick a choice " << endl;
    }
    return choice;
}
//Function definition
int RPSmenu()
{
    //Declare variable for user input
    int choice;
    int comp; // This represents the computer as a player
    cout <<"*****************************" << endl;
    cout << "  Rock/Paper/Scissors game "<< endl;
    cout <<"*****************************" << endl;
    cout << "The rules are: " << endl;
    cout << "Rock beats Scissors" << endl;
    cout << setw(15) << "--------" << endl;
    cout << "Scissors beat Paper" << endl;
    cout << setw(15) << "--------" << endl;
    cout << "Paper beats rock" << endl << endl;
    cout << "Pick your choice " << endl;
    cout << "1. Rock" << endl;
    cout << "2. Paper" << endl;
    cout << "3. Scissors" << endl;
    cout << "4. Back to main menu" << endl;
    cin >> choice;
    //Statement that will determine outcome of game
    if (choice == 1 )
    {
        cout << "You picked Rock"<<endl;
        //Will need srand and rand so computer will randomly pick a choice
        srand(time(0));
        comp = rand() % 3 + 1;
        //Nesting the case if user passes the fist statement
        if (comp == 1 )
        {
             cout << "I picked rock" << endl;
             cout << "Draw" << endl;
        }
        else if (comp == 2)
        {
            cout << "I picked paper" <<endl;
            cout << "You lose" << endl;
        }
        else if (comp == 3)
        {
            cout << "I picked Scissors" << endl;
            cout << "You win" << endl;
        }

    }
    else if (choice == 2)
    {
        cout << "You picked Paper"<<endl;
        srand(time(0));
        comp = rand() % 3 + 1;
        if (comp == 1 )
        {
             cout << "I picked rock" << endl;
             cout << "You win" << endl;
        }
        else if (comp == 2)
        {
            cout << "I picked paper" <<endl;
            cout << "Draw" << endl;
        }
        else if (comp == 3)
        {
            cout << "I picked Scissors" << endl;
            cout << "You lose" << endl;
        }
    }
    else if (choice == 3)
    {
        cout << "You picked Scissors"<<endl;
        srand(time(0));
        comp = rand() % 3 + 1;
        if (comp == 1 )
        {
             cout << "I picked rock" << endl;
             cout << "You lose" << endl;
        }
        else if (comp == 2)
        {
            cout << "I picked paper" <<endl;
            cout << "You win" << endl;
        }
        else if (comp == 3)
        {
            cout << "I picked Scissors" << endl;
            cout << "Draw" << endl;
        }
    }
    else if (choice == 4 )
    {
        return menu();
    }
    else
    {
        cout << "You did not pick a choice" << endl << endl;
        return RPSmenu();
    }
    return choice;
}
//Function definition
int Dicemenu()
{   //Declare variable for user input
    int choice;
    int dice; //Holds function
    cout <<"****************" << endl;
    cout << " Dice game " << endl;
    cout <<"****************" << endl;
    cout << "The rules are: " << endl;
    cout << "You get 10 points if both of the dice equals to 7" << endl;
    cout << setw(15) << "--------" << endl;
    cout << "You get 5 points of two of the dice are similar" << endl;
    cout << setw(15) << "--------" << endl;
    cout << "Your get 3 points if at least one of the dice is 4" << endl << endl;
    cout << "1. Roll one dice" << endl;
    cout << "2. Roll two dice" << endl;
    cout << "3. Back to main menu" << endl;
    cin >> choice;
    if (choice == 1)
    {
        dice = rollDice();
        if (rollDice() == 4)
        {
            cout << "You rolled a 4! -- 3 points"<< endl;
        }
        else
        {
            cout << "You did not win any points -- you rolled " << rollDice() << endl;
        }
    }
    else if (choice == 2)
    {
        dice = DiceSum();

    }
    else if (choice == 3)
    {
        return menu();
    }
    else
    {
        cout <<" Please input a choice" << endl;
        return Dicemenu();
    }


    return choice;
}
//Used to randomly generate a number
int rollDice()
{
    int number; //Variable use for rand
    srand(time(0));
    number = rand() % 6 + 1;
    return number;

}
int DiceSum()
{
    // Declare variable for dice rolls
    int Dice1 = rollDice();
    int Dice2;
    //This will make the second dice random and not the same as first dice
    Dice2 = rand() % 6 + 1;
    //Displays the dice roll results
    cout <<"Your first roll: " <<  Dice1 << endl;
    cout <<"Your second roll: " << Dice2 << endl;
    if (Dice1 == Dice2)
    {
        cout << "You win 5 points!" << endl;
    }
    else if (Dice1 + Dice2 == 7)
    {
        cout << "You win 10 points!" << endl;
    }
    else
    {
        cout << "Sorry you won zero points" << endl << endl;
    }
    return 0;
}


