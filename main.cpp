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


//Functions-GUI

int main() {
  printmatrix();
  playerSelection();
}

void printmatrix() {
  for (int i = 0; i < 3; i++) {
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

/*int matrixValidate()
{
    if (matrix[0][j] && matrix[1][j] && matrix[2][j] == 1)
    {
        cout<<("Player 1 wins ");
    }
    else if (matrix[0][j] && matrix[1][j] && matrix[2][j] == 2)
    {
        cout<<("Player 2 wins ");
    }
    else if (matrix[0][0] && matrix[1][1] && matrix[2][2] == 1)
    {
        cout<<("Player 1 wins ");
    }
    else if (matrix[0][0] && matrix[1][1] && matrix[2][2] == 2)
    {
        cout<<("Player 2 wins ");
    }
    else if (matrix[0][2] && matrix[1][1] && matrix[2][0] == 1)
    {
        cout<<("Player 1 wins ");
    }
    else if (matrix[0][2] && matrix[1][1] && matrix[2][0] == 2)
    {
        cout<<("Player 2 wins ");
    }
    else
    {
        cout<<("its a TIE!");
    }

}*/

int playerSelection() {
  cout << "Player 1 choose 1 or 2";
  cin >> player1 << endl;
  if (player1 = 1) {
    player2 = 2;
    cout << "player2 = 2";
  } else if (player1 = 2) {
    player2 = 1;
    cout << "player2 = 1";
  } else {
    cout << "Invalid input";
  }
}