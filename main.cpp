#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;
// Variables
char gameMatrix[3][3] = {'\0'}; // to store status
char player1 = 'X', player2 = 'O';
int player1score = 0, player2score = 0;
int Xlen = 1000, Ylen = 600;
int Xcordinates[3] = {100, 300, 500}, Ycordinates[3] = {100, 300, 500};

// Functions-Logic
int keyMap(char player);     // mapping to keys to the matrix
int playerInput(int itno);   // to take an input from player turn by turn
int gameLoop();              // game runtime
char winConditionValidate(); // to check the matrix for win conditions
void printMatrix();          // for console print
bool matchResults(
    char re, int counter); // show result of match after winConditionValidate
int exitToMainMenu();      //
int continueMatch();       //
int compareChar(char a, char b, char c);

// Gui function declaration
void startScreen();
int postMatchScreen();
void drawX(int x, int y);
void drawO(int x, int y);
void drawGameBoard();
void fillMatrix();
//-----------------------------------------------
int main()
{
  int gd = DETECT, gm;
  initwindow(Xlen, Ylen);

  startScreen();

  getch();
  closegraph();
  return 0;
}
//----------------------------------------------
// Console Game Logic Functions

int gameLoop()
{
  cleardevice();
  drawGameBoard();

  for (int i = 1; i < 10; i++)
  {
    drawGameBoard();
    playerInput(i);
    printMatrix();
    if (matchResults(winConditionValidate(), i))
    {
      break;
    }
  }
  postMatchScreen();
  return 0;
}

int playerInput(int itno)
{
  if ((itno % 2) == 0)
  {
    settextstyle(9, HORIZ_DIR, 3);
    outtextxy(650, 300, "Player 2's Turn");
    keyMap(player2);
  }
  else
  {
    settextstyle(9, HORIZ_DIR, 3);
    outtextxy(650, 300, "Player 1's Turn");
    keyMap(player1);
  }
}

int keyMap(char player)
{
  while (1)
  {
    getch();
    if (GetAsyncKeyState(VK_NUMPAD1) && gameMatrix[0][2] == '\0')
    {
      gameMatrix[0][2] = player;
      break;
    }
    else if (GetAsyncKeyState(VK_NUMPAD2) && gameMatrix[1][2] == '\0')
    {
      gameMatrix[1][2] = player;
      break;
    }
    else if (GetAsyncKeyState(VK_NUMPAD3) && gameMatrix[2][2] == '\0')
    {
      gameMatrix[2][2] = player;
      break;
    }
    else if (GetAsyncKeyState(VK_NUMPAD4) && gameMatrix[0][1] == '\0')
    {
      gameMatrix[0][1] = player;
      break;
    }
    else if (GetAsyncKeyState(VK_NUMPAD5) && gameMatrix[1][1] == '\0')
    {
      gameMatrix[1][1] = player;
      break;
    }
    else if (GetAsyncKeyState(VK_NUMPAD6) && gameMatrix[2][1] == '\0')
    {
      gameMatrix[2][1] = player;
      break;
    }
    else if (GetAsyncKeyState(VK_NUMPAD7) && gameMatrix[0][0] == '\0')
    {
      gameMatrix[0][0] = player;
      break;
    }
    else if (GetAsyncKeyState(VK_NUMPAD8) && gameMatrix[1][0] == '\0')
    {
      gameMatrix[1][0] = player;
      break;
    }
    else if (GetAsyncKeyState(VK_NUMPAD9) && gameMatrix[2][0] == '\0')
    {
      gameMatrix[2][0] = player;
      break;
    }
  }
  cleardevice();
  drawGameBoard();
  fillMatrix();
}

int compareChar(char a, char b, char c)
{
  if (a == b && a == c && a != '\0' && b != '\0' && c != '\0')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

char winConditionValidate()
{

  for (int i = 0; i < 3; i++)
  { // row
    if (compareChar(gameMatrix[i][0], gameMatrix[i][1], gameMatrix[i][2]))
    {
      return gameMatrix[i][0];
    }
  }
  for (int i = 0; i < 3; i++)
  { // column
    if (compareChar(gameMatrix[0][i], gameMatrix[1][i], gameMatrix[2][i]))
    {

      return gameMatrix[0][i];
    }
  }
  // diagonal
  if (compareChar(gameMatrix[0][0], gameMatrix[1][1], gameMatrix[2][2]))
  {
    return gameMatrix[0][0];
  }
  if (compareChar(gameMatrix[0][2], gameMatrix[1][1], gameMatrix[2][0]))
  {
    return gameMatrix[1][1];
  }
}

bool matchResults(char re, int counter)
{
  if (re == 'X')
  {
    player1score += 1;
    settextstyle(9, HORIZ_DIR, 3);
    outtextxy(700, 200, "Tic-Tac-Toe");
    outtextxy(650, 300, "Player 1 WON");
    outtextxy(625, 350, "Press Spacebar to Continue");
    getch();
    return 1;
  }
  else if (re == 'O')
  {
    player2score += 1;
    settextstyle(9, HORIZ_DIR, 3);
    outtextxy(700, 200, "Tic-Tac-Toe");
    outtextxy(650, 300, "Player 2 WON");
    outtextxy(625, 350, "Press Spacebar to Continue");
    getch();
    return 1;
  }
  else if (counter == 9)
  {
    settextstyle(9, HORIZ_DIR, 3);
    outtextxy(700, 200, "Tic-Tac-Toe");
    outtextxy(650, 300, "Its a TIE!");
    outtextxy(625, 350, "Press Spacebar to Continue");
    getch();
    return 1;
  }
  return 0;
}

int exitToMainMenu()
{
  player1score = player2score = 0;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      gameMatrix[i][j] = '\0';
    }
  }
  cleardevice();
  startScreen();
}

int continueMatch()
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      gameMatrix[i][j] = '\0';
    }
  }
  gameLoop();
}

void printMatrix()
{
  cout << "Scores Are: Player-1: " << player1score
       << "  ,Player-2: " << player2score << endl;
  cout << "Game Matrix shown below: " << endl;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cout << gameMatrix[i][j];
      if (j == 2)
      {
        continue;
      }
      else
      {
        cout << " | ";
      }
    }
    if (i == 2)
    {
      continue;
    }
    else
    {
      cout << endl
           << "----------" << endl;
    }
  }
  cout << endl;
}
//------------------------------------------------------------------------
// GUI Functions Definitions
void startScreen()
{
  drawGameBoard();
  settextstyle(9, HORIZ_DIR, 3);
  outtextxy(700, 200, "Tic-Tac-Toe");
  outtextxy(650, 300, "(Enter)Start New Game");
  outtextxy(650, 400, "(Esc)Exit");
  while (1)
  {
    if (GetAsyncKeyState(VK_RETURN))
    {
      gameLoop();
    }
    else if (GetAsyncKeyState(VK_ESCAPE))
    {
      closegraph();
    }
  }
}


void drawGameBoard()
{
  rectangle(0, 0, 600, 600);
  line(200, 0, 200, 600);
  line(400, 0, 400, 600);
  line(0, 200, 600, 200);
  line(0, 400, 600, 400);
  //draw score board
  settextstyle(9, HORIZ_DIR, 3);
}

void fillMatrix()
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      char element = gameMatrix[i][j];
      if (element == 'X')
      {
        drawX(Xcordinates[i], Ycordinates[j]);
      }
      else if (element == 'O')
      {
        drawO(Xcordinates[i], Ycordinates[j]);
      }
    }
  }
}

int postMatchScreen()
{
  cleardevice();
  drawGameBoard();
  fillMatrix();
  settextstyle(9, HORIZ_DIR, 3);
  outtextxy(700, 200, "Tic-Tac-Toe");
  outtextxy(650, 300, "Continue Match");
  outtextxy(700,320,"(Enter)");
  outtextxy(650, 400, "Exit to Main Menu");
  outtextxy(700,420,"(Backspace)");
  while (1)
  {
    if (GetAsyncKeyState(VK_RETURN))
    {
      continueMatch();
      break;
    }
    else if (GetAsyncKeyState(VK_BACK))
    {
      exitToMainMenu();
      break;
    }
  }
  return 0;
}
void drawX(int x, int y)
{
  settextstyle(3, HORIZ_DIR, 7);
  outtextxy(x-50, y-50, "X");
}
void drawO(int x, int y)
{
  settextstyle(3, HORIZ_DIR, 7);
  outtextxy(x-50, y-50, "O");
}
