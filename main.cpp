#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <iostream>

using namespace std;
// Variables
char gameMatrix[3][3] = {""}; // to store status
char player1 = 'X', player2 = 'O';
int player1score = 0, player2score = 0;

// Functions-Logic
int gameMenu();             // Initial Game Menu
int keyMap(char player);               // mapping to keys to the matrix
int playerInput(int itno);          // to take an input from player turn by turn
int gameLoop();             // game runtime
int winConditionValidate(); // to check the matrix for win conditions
void printMatrix();         // for console print
int matchResults();         // show result of match after winConditionValidate
int exitToMainMenu();       //
int continueMatch();        //



int main() {
  printmatrix();

  return 0;
}


int gameMenu() {
  int userChoice;
  cout << "1.Start a New Game" << endl;
  cout << "2.Exit" << endl;
  cin >> userChoice;
  if (userChoice == 1) {
    gameLoop(); // Start a New Match
  } else {
    return 0; // otherwise Exit.
  }
}

int gameLoop(){
  for(int i=1;i<10;i++){
    playerInput(i);
  }
}

int playerInput(int itno){
  if((itno%2)==0){
    keyMap(player2);
  }else {
    keyMap(player1)
  }

}


int keyMap(char player){
  int userInput;
  cin>>userInput;
  
  if (userInput==1) {gameMatrix[2][0]=player}
  else if (userInput==2) {gameMatrix[2][1]=player}
  else if (userInput==3) {gameMatrix[2][2]=player}
  else if (userInput==4) {gameMatrix[1][0]=player}
  else if (userInput==5) {gameMatrix[1][1]=player}
  else if (userInput==6) {gameMatrix[1][2]=player}
  else if (userInput==7) {gameMatrix[0][0]=player}
  else if (userInput==8) {gameMatrix[0][1]=player}
  else if (userInput==9) {gameMatrix[0][2]=player}
}               


int winConditionValidate(); 

int matchResults();         
int exitToMainMenu();      
int continueMatch();   

    /*  matrixValidate()
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

    } */

void printmatrix() {
  cout << "Matrix shown below: " for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << matrix[i][j];
      if (j == 2) {
        continue;
      } else {
        cout << " | ";
      }
    }
    if (i == 2) {
      continue;
    } else {
      cout << endl << "----------" << endl;
    }
  }
}