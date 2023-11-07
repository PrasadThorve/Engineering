#include <iostream>
using namespace std;

#define N 4

void printSolution(int board[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[i][j]){
                cout<<1<<" ";
            }
            else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
}

bool isSafe(int board[N][N],int row, int col){
    // checking for the same row

    int i,j;

    for(j=col-1;j>=0;j--){
        if(board[row][j]){
            return false;
        }
    }

    //check for upper diagonal
    for(i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j]){
            return false;
        }
    }

    //checking for lower diagonal
    for(i=row, j=col; i>=0 && j<N; i--,j++){
        if(board[i][j]){
            return false;
        }
    }

    return true;
}

// recursive utility function to solve n queen problem
bool solveNQutil(int board[N][N], int col){
    // base condition : all queens are placed
    if(col>=N){
        return true;
    }

    // check if the queen can be placed on the board[n][n]
    for(int i=0;i<N;i++){
        
        if(isSafe(board,i,col)){
            board[i][col] = 1;

            //recursion to place rest of the queens
            if(solveNQutil(board,col+1)){
                return true;
            }

            //if it doesn't lead to solution
            board[i][col] = 0;  //backtrack
        }
    }

    return false;
}

bool solveNQ(){
    int board[N][N] = {{0,0,0,0},
                   {0,0,0,0},
                   {0,0,0,0},
                   {0,0,0,0}};
    
    if(solveNQutil(board,0)==false){
        cout<<"Solution Does not exist";
        return false;
    }
    
    printSolution(board);
    return true;

}

int main(){
    solveNQ();
    return 0;

}