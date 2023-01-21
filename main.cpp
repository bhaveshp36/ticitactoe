#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

using namespace std;

int matrix[3][3]={0};


int matrixValidate();
int playerSelection();
int printmatrix();
int playerinput();
int keymap();

int main(){
    printmatrix();
    
}



void 

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