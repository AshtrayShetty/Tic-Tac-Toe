#include<stdio.h>
#include<stdlib.h>
#include "functions_adjMatrix.h"

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
    printf("Player 1:\nChoose: X or O? "); scanf("%c", &player1);

    //If not "X" or "O", ask player 1 to input the choice again
    while(player1!='X' && player1!='O'){
        printf("Please choose only between X or O: "); scanf("\r%c", &player1);
    }

    if(player1=='X'){player2='O';}
    else{player2='X';}

    //Start of game
    while(count<9){

        //Display board after each iteration
        boardDisplay(board);

        //Accept user input for coordinates
        if(count%2==0){printf("Player 1's turn:\n");}
        else{printf("Player 2's turn:\n");}
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

            //A regex expression to clear the screen after every iteration
            printf("\e[1;1H\e[2J");

            /*
            Alternatively you can use:
                system("clear"); //for Linux systems
                system("cls"); //for Windows 
            */

        }else{
            printf("\e[1;1H\e[2J");
            printf("Position already occupied\n");
        } 

    }

    //Condition for a draw (if all checks for both graphs don't satisfy)
    if(checkRows(adjMatrix)=='r' && checkCols(adjMatrix)=='c' && checkLeftDiagonal(adjMatrix)=='l' && checkRightDiagonal(adjMatrix)=='d'){
        printf("Draw\n");
    }

    return 0;

}