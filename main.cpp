#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
// Variables
char gameMatrix[3][3] = {""}; // to store status
char player1 = 'X', player2 = 'O';
int player1score = 0, player2score = 0;

// Functions-Logic
int gameMenu();              // Initial Game Menu
int keyMap(char player);     // mapping to keys to the matrix
int playerInput(int itno);   // to take an input from player turn by turn
int gameLoop();              // game runtime
char winConditionValidate(); // to check the matrix for win conditions
void printMatrix();          // for console print
bool matchResults(char re, int counter); // show result of match after winConditionValidate
int exitToMainMenu();      //
int continueMatch();       //
int compareChar(char a, char b, char c);

//Functions GUI

int main() {
  gameMenu();
  return 0;
}

int gameMenu() {
  int userChoice;
  cout << "1.Start a New Game" << endl;
  cout << "2.Exit" << endl;
  cin >> userChoice;
  switch (userChoice) {
  case 1:
    gameLoop();
    break;
  default:
    return 0;
  }
}

int gameLoop() {
  for (int i = 1; i < 10; i++) {
    playerInput(i);
    printMatrix();
    if (matchResults(winConditionValidate(), i)) {
      break;
    }}
    cout<<"press Y to continue to next match"<<endl;
    cout<<"press X to exit to main menu"<<endl;
    char userChoice;
    cin>>userChoice;
    // if (userChoice == 'y') {
    // continueMatch();
    // }else if (userChoice == 'x') {
    //   exitToMainMenu();
    // }
    switch (userChoice) {
      case 'y':continueMatch();
      break;
      case 'x':exitToMainMenu();
      break;
  }
}

int playerInput(int itno) {
  if ((itno % 2) == 0) {
    cout << "Player 2:"<<endl;
    keyMap(player2);
  } else {
    cout << "Player 1:"<<endl;
    keyMap(player1);
  }
}

int keyMap(char player) {
  int userInput;
  cin >> userInput;

  if (userInput == 1 && gameMatrix[2][0] == '\0') {
    gameMatrix[2][0] = player;
  } else if (userInput == 2 && gameMatrix[2][1] == '\0') {
    gameMatrix[2][1] = player;
  } else if (userInput == 3 && gameMatrix[2][2] == '\0') {
    gameMatrix[2][2] = player;
  } else if (userInput == 4 && gameMatrix[1][0] == '\0') {
    gameMatrix[1][0] = player;
  } else if (userInput == 5 && gameMatrix[1][1] == '\0') {
    gameMatrix[1][1] = player;
  } else if (userInput == 6 && gameMatrix[1][2] == '\0') {
    gameMatrix[1][2] = player;
  } else if (userInput == 7 && gameMatrix[0][0] == '\0') {
    gameMatrix[0][0] = player;
  } else if (userInput == 8 && gameMatrix[0][1] == '\0') {
    gameMatrix[0][1] = player;
  } else if (userInput == 9 && gameMatrix[0][2] == '\0') {
    gameMatrix[0][2] = player;
  } else {
    cout << "Invalid Input";
    keyMap(player);
  }
  system("cls");
}
int compareChar(char a, char b, char c) {
  if (a == b && a == c && a != '\0' && b != '\0' && c != '\0') {
    return 1;
  } else {
    return 0;
  }
}
char winConditionValidate() {

  for (int i = 0; i < 3; i++) { // row
    if (compareChar(gameMatrix[i][0], gameMatrix[i][1], gameMatrix[i][2])) {
      return gameMatrix[i][0];
    }
  }
  for (int i = 0; i < 3; i++) { // column
    if (compareChar(gameMatrix[0][i], gameMatrix[1][i], gameMatrix[2][i])) {
      return gameMatrix[0][i];
    }
  }
  // diagonal
  if (compareChar(gameMatrix[0][0], gameMatrix[1][1], gameMatrix[2][2])) {
    return gameMatrix[0][0];
  }
  if (compareChar(gameMatrix[0][2], gameMatrix[1][1], gameMatrix[2][0])) {
    return gameMatrix[1][1];
  }
}

bool matchResults(char re, int counter) {
  if (re == 'X') {
    cout << "Player 1 Win";
    player1score+=1;
    return 1;
  } else if (re == 'O') {
    cout << "Player 2 Win";
    player2score+=1;
    return 1;
  } else if (counter == 9) {
    cout << "TIE!";
    return 1;
  }
  return 0;
}

int exitToMainMenu(){
  player1score=player2score=0;
  for (int i=0; i<3; i++) {
  for (int j=0; j<3; j++) {gameMatrix[i][j]='\0';}}
  system("cls");
  gameMenu();
}
int continueMatch(){
  for (int i=0; i<3; i++) {
  for (int j=0; j<3; j++) {gameMatrix[i][j]='\0';}}
  gameLoop();
}



void printMatrix() {
    cout<<"Scores Are: Player-1: "<<player1score<<"  ,Player-2: "<<player2score<<endl;
  cout << "Game Matrix shown below: " << endl;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << gameMatrix[i][j];
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
  cout << endl;
}
