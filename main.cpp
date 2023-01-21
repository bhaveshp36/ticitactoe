#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

using namespace std;

int matrix[3][3]={0};

int player1, player2;
bool 
int matrixValidate();
int playerSelection();
void printmatrix();
int playerinput();
int keymap();
int gameLoop();

int main(){
    printmatrix();
    playerSelection();
}

void printmatrix(){
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