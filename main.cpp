#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <iostream>


using namespace std;
//Variables
int gameMatrix[3][3] = {0}; //to store status
int player1=1, player2=2; 


//Functions-Logic 
int gameMenu(); //Initial Game Menu
int keyMap(); //mapping to keys to the matrix
int playerInput(); // to take an input from player turn by turn
int gameLoop(); // game runtime
int winConditionValidate(); //to check the matrix for win conditions
void printMatrix(); // for console print
int matchResults(); // show result of match after winConditionValidate
int exitToMainMenu(); //
int continueMatch(); //

int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
char turn = 'x' ;
int choice;
int player1, player2;
bool  matrixValidate();
int playerSelection();
void printmatrix();
int playerinput();
int keymap();
int gameLoop();

int main() {
  printmatrix();
  playerSelection();

    return 0;
}

void printmatrix(){
    cout<<"Matrix shown below: "
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<matrix[i][j];
            if(j==2){continue;}else{cout<<" | ";}
        }
        if(i==2){continue;}else{cout<<endl<<"----------"<<endl;}
    }
}

 matrixValidate()
{     
    bool winner= false;
    if (matrix[0][j] && matrix[1][j] && matrix[2][j] == 1 )
    {
        cout<<("Player 1 wins ");
        winner = true;
    }
    else if (matrix[0][j] && matrix[1][j] && matrix[2][j] == 2)
    {
        cout<<("Player 2 wins ");
        winner = true;

    }
    else if (matrix[0][0] && matrix[1][1] && matrix[2][2] == 1 && turn=='x')
    {
        cout<<("Player 1 wins ");
        winner = true;
    }
    else if (matrix[0][0] && matrix[1][1] && matrix[2][2] == 2 && ) 
    {
        cout<<("Player 2 wins ");
        winner = true;
    }
    else if (matrix[0][2] && matrix[1][1] && matrix[2][0] == 1 && )
    {
        cout<<("Player 1 wins ");
        winner = true;
    }
    else if (matrix[0][2] && matrix[1][1] && matrix[2][0] == 2 && )
    {
        cout<<("Player 2 wins ");
        winner = true;
    }
    else
    {
        cout<<("its a TIE!");
    }
    return winner;

}

int playerSelection()
{
    cout<<"Player 1 choose 1 or 2";
    cin>>player1<<endl;
    if(player1 = 1)
    {
        player2 = 2;
        cout<<"player2 = 2";
    }
    else if(player1 = 2)
    {
        player2 = 1;
         cout<<"player2 = 1";
    }
    else
    {
        cout<<"Ivalid input";
    }

}
int playerinput()
{
    if(turn=='x')
    {
        cout<<"Player enter input : ";
    }
    else if (turn== 'o')
    {
        cout<<"Player enter input : ";
    }
    cin>>choice;

    switch(choice){

    case 1 :
            board[0][0] ; 
            break;
    case 2 : board[0][1] ; 
            break;
    case 3 : board[0][2] ; 
            break;
    case 4 : board[1][0] ; 
            break;
    case 5 : board[1][1] ; 
            break;
    case 6 : board[1][2] ; 
            break;
    case 7 : board[2][0] ; 
            break;
    case 8 : board[2][1] ; 
            break;
    case 9 : board[2][2] ; 
            break;
    default: cout<<"Invalid move";
    }
}








int gamemenu()
{
    cout<<"Enter choice y or n: ";
    cin>>input;

    switch(input) 
    {
        case 1 : 
        if(input==y)
        {
            printmatrix();
        }
        else
        {
            cout<<"Invalid input";
        }
        case 2 : 
        if(input==n)
        {
            cout<<"Goodbye";

        }
        else
        {
            
        }
        

    }

}