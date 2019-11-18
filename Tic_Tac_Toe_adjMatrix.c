#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

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

int main(){
    int adjMatrix[3][3];
    char player1 , player2, board[5][5];
    int i, j, count=0;

    //Creating the board
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            board[i][j]=' ';
            //For even value of i
            if(i%2==0){

                //If j is even, board matrix at that position contains empty space
                if(j%2==0){board[i][j]=' ';}

                //If j is odd, board matrix at that position contains "|"
                else{board[i][j]='|';}

            }

            //For odd values of i
            else{

                //If j is even, board matrix at that position contains "-"
                if(j%2==0){board[i][j]='-';}

                //If j is odd, board matrix at that position contains "+"
                else{board[i][j]='+';}
            }
        }
    }

    //Player 1 gets to choose their character
    printf("Choose: X or O? "); scanf("%c", &player1);

    //If not "X" or "O", ask player 1 to input the choice again
    while(player1!='X' && player1!='O'){
        printf("Please choose only between X or O: "); scanf("%c", &player1);
    }

    if(player1=='X'){player2='O';}
    else{player2='X';}

    //Start of game
    while(count<9){

        //Display board after each iteration
        boardDisplay(board);

        //Accept user input for coordinates
        printf("Coordinates of input:"); scanf("%d %d", &i, &j);

        //Check for invalid input
        if(i<1 || i>3 || j<1 || j>3){
            printf("Invalid input\n");
            continue;
        }

        //Check if position already occupied; don't want to overwrite the value at that position
        if(elementAt(adjMatrix, i, j)==0){

            //If count is even, player 1's turn
            if(count%2==0){

                //Insert the character into board
                board[2*(i-1)][2*(j-1)]=player1;

                //Insert player1's character weight into graph
                insert(adjMatrix, i, j, player1);

                //Start checking for victory condition for 4 or more successful inputs
                if(count>=4){

                    //Victory condition for player 1 (given that they have chosen 'X')
                    if(checkRows(adjMatrix)==player1 || checkCols(adjMatrix)==player1 || checkLeftDiagonal(adjMatrix)==player1 || checkRightDiagonal(adjMatrix)==player1){
                        
                        //Clear the screen
                        printf("\e[1;1H\e[2J"); 
                        printf("Player 1 wins the game\n");
                        boardDisplay(board);
                        break;
                    }
                }

            }
            //If count is odd, player 2's turn
            else{

                //Insert the character into board
                board[2*(i-1)][2*(j-1)]=player2;

                //insert player2's character weight into matrix
                insert(adjMatrix, i, j, player2);

                if(count>=4){
                    if(checkRows(adjMatrix)==player2 || checkCols(adjMatrix)==player2 || checkLeftDiagonal(adjMatrix)==player2 || checkRightDiagonal(adjMatrix)==player2){
                        
                        //Clear the screen
                        printf("\e[1;1H\e[2J"); 
                        printf("Player 2 wins the game\n");
                        boardDisplay(board);
                        break;
                    }
                }

            }

            ++count;

        }else{printf("Position already occupied\n");}

        //A regex expression to clear the screen after every iteration
        printf("\e[1;1H\e[2J"); 

    }

    //Condition for a draw (if all checks for both graphs don't satisfy)
    if(checkRows(adjMatrix)=='r' && checkCols(adjMatrix)=='c' && checkLeftDiagonal(adjMatrix)=='l' && checkRightDiagonal(adjMatrix)=='d'){
        printf("Draw\n");
    }

    return 0;

}