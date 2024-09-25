#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// Declaring Global Variables

char board[3][3]; //board of 3 rows and 3 columns

//Read only, global variables
const char PLAYER = 'O'; // the players symbol
const char COMPUTER = 'X'; // the computers symbol


// Function Prototypes --> help avoid errors down the line when calling functions

void resetBoard(); // Resets board (2D character array)
void printBoard(); // Prints the 2D character array

int checkFreeSpaces(); // Checks free spaces on the board, if 0 game is OVER

void playerMove(); // Players turn to move
void computerMove(); // Computers turn to move

char checkWinner();
void printWinner(char);



int main()
{

    char winner = ' '; // X if computer wins, O if player wins
    char response;

    do
    {

    winner = ' ';
    response = ' ';


    resetBoard();

    while(winner == ' ' && checkFreeSpaces() != 0) // if there is no winner AND free spaces remain, printboard.
    {
        printBoard();

        playerMove();
        winner = checkWinner();
        if (winner != ' ' || checkFreeSpaces() == 0)
        {
            break;
        } // if there is a winner or no spaces available break out of while loop

        computerMove();
        winner = checkWinner();
        if (winner != ' ' || checkFreeSpaces() == 0)
        {
            break;
        } 
    }

    printBoard();
    printWinner(winner);

    printf("\n Do you want to play again? (y/n): ");
    // scanf("%c"); //clearing buffer
    scanf(" %c", &response);
    response = tolower(response);


    } while (response == 'y');

    printf("Thanks For Playing!!");


    return 0;
}

void resetBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = ' '; // each element within the 2D array will be replaced with a blank character
        }
    }
}


void printBoard()
{
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    
    // Drawing the Screen on the terminal/command prompt

}


int checkFreeSpaces()
{
    int freeSpaces = 9; // there are initially 9 free spaces in a 3x3 grid

    for (int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ') //check if spot on board is occupied
            freeSpaces--; // if occupied, decrement freespaces by 1
        }
    }

    return freeSpaces; // if freespaces returns 0, the game is over as there is no more places to move
}


void playerMove()
{
    int x;
    int y;


    do{

    printf("Enter row #(1 - 3): \n"); // in reality rows range from 0-2
    scanf("%d", &x); // thus decrement user input by 1
    x--;

    printf("Enter column #(1 - 3): \n"); // same for columns and y
    scanf("%d", &y);
    y--;


    if (board[x][y] != ' ') // if spot chosen is occupied inform the user
    {
        printf("Invalid move! Please select a spot that is not currently occupied");
    }
    else
    {
        board[x][y] = PLAYER; // if spot is not occupied update board with players symbol
        break; // once updated break out the loop
    }
    }while(board[x][y] != ' '); //continue prompting user to select a valid move


}


void computerMove()
{
    // Computers move will be randomly generated
    // This function will create a seed based on current time

    srand(time(0));
    int x;
    int y;

    //check for free spaces

    if (checkFreeSpaces() > 0)
    {
        do
        {
            x = rand() % 3; //generate random number between 0 and 2
            y = rand() % 3;

        }while(board[x][y] != ' ');
        
        board[x][y] = COMPUTER;
    }
    else
    {
        printWinner(' '); // if there are no more spaces available it is a draw
    }
}


char checkWinner() // Must check all potential win conditions
{
    // Checking for Rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) //if all elements in the row are the same
        {
            return board[i][0]; // return the winning character
        }

    // Checking for Columns
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) //if all elements in the column are the same
        {
            return board[0][i]; // return the winning character
        }
    }

    // Checking diagonals
        if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) //if all elements in the column are the same
        {
            return board[0][0]; // return the winning character
        }

        if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) //if all elements in the column are the same
        {
            return board[0][2]; // return the winning character
        }

        return ' ';

   
}




void printWinner(char Winner)
{
    if(Winner == PLAYER)
    {
        printf("You WIN!!");
    }
    else if (Winner == COMPUTER)
    {
        printf("You LOSE!!");
    }
    else
    {
        printf("It's a TIE.");
    }
}