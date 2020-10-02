#include<stdio.h>
#include<stdlib.h>
#include "functions_adjMatrix.h"

//Function to create graph
void createGraph(int adjMatrix[][3]){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){adjMatrix[i][j]=0;}
    }
}

//Function to insert into the graph
void insert(int adjMatrix[][3],int vertex_from,int vertex_to, char player){
   
    //Weight of 1 given to 'X'
    if(player=='X'){adjMatrix[vertex_from-1][vertex_to-1]=1;}

    //Weight of 2 given to 'O'
    else{adjMatrix[vertex_from-1][vertex_to-1]=2;}

}

//Function to check if all 3 vertices of a given row are occupied in the given graph
char checkRows(int adjMatrix[][3]){
    int i,j;

    for(i=0;i<3;i++){
        //Initializing counting variables for both 'X' and 'O' to 0 for each row
        int countX=0,countO=0;

        for(j=0;j<3;j++){
            if(adjMatrix[i][j]==1){++countX;}
            else if(adjMatrix[i][j]==2){++countO;}
        }

        //If all the elements in the given row are 'X', then return 'X'
        if(countX==3){return 'X';}

        //If all the elements in the given row are 'O', then return 'O'
        if(countO==3){return 'O';}
    }

    //Returning 'r' otherwise
    return 'r';
}

//Function to check if all 3 vetices of a given column are occupied for a given graph
char checkCols(int adjMatrix[][3]){
    int i,j;

    for(i=0;i<3;i++){

        int countX=0,countO=0;
        for(j=0;j<3;j++){
            if(adjMatrix[j][i]==1){++countX;}
            else if(adjMatrix[j][i]==2){++countO;}
        }
        
        if(countX==3){return 'X';}
        if(countO==3){return 'O';}
    }

    //Else return 'c'
    return 'c';
}

//Function to check if the vertices along the left diagonal [(0,0),(1,1),(2,2)] are occupied
char checkLeftDiagonal(int adjMatrix[][3]){
    int i,countX=0,countO=0;

    for(i=0;i<3;i++){

        if(adjMatrix[i][i]==1){++countX;}
        if(adjMatrix[i][i]==2){++countO;}

    }

    if(countX==3){return 'X';}
    if(countO==3){return 'O';}

    //Else return 'l'
    return 'l';
}

//Function to check if the elements along the right diagonal [(0,2),(1,1),(2,0)] are occupied
char checkRightDiagonal(int adjMatrix[][3]){
    int i,countX=0,countO=0;

    for(i=0;i<3;i++){

        if(adjMatrix[i][2-i]==1){++countX;}
        if(adjMatrix[i][2-i]==2){++countO;}

    }

    if(countX==3){return 'X';}
    if(countO==3){return 'O';}

    //Else return 'd'
    return 'd';
}

//Check if the given coordinates are already occupied
int elementAt(int adjMatrix[][3], int vertex_from, int vertex_to){

    //If occupied by either an 'X' or an 'O'(weights 1 and 2 respectively), return 1
    if(adjMatrix[vertex_from-1][vertex_to-1]==1 || adjMatrix[vertex_from-1][vertex_to-1]==2){return 1;}

    //Else return 0
    return 0;
}

//Function to display the board
void boardDisplay(char board[][5]){
    int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){printf("%c",board[i][j]);}
        printf("\n");
    }
}

//Function to check for invalid input of coordinates (character input)
void cleanBuffer(void){
    int n;
    while((n=getchar())!=EOF && n!='\n');
}
