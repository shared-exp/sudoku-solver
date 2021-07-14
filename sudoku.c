#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int sudoku[9][9];


void input(int suoku[9][9]){
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            printf("from left [%d][%d]:",i+1,j+1);
            scanf("%d",&sudoku[i][j]);
        }
    }

}


void print_out(){
    int i,j;
    printf("-------------------------------\n");
    for(i=0;i<9;i++){
        printf("|");
        for(j=0;j<9;j++){
            printf(" %d ",sudoku[i][j]);
            if(((j+1) % 3) == 0){
                printf("|");
            }
        }
        printf("\n");
        if(((i+1) % 3) == 0){
            printf("-------------------------------\n");
        }
    }
}


int free_square(int* row,int* coulmn){
    int i,j;
    for (i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(sudoku[i][j]==0){
                *row = i;
                *coulmn = j;
                return 1;
            }
        }
    }
    return 0;
} 


int check(int n,int row,int column){
    int i,j;
    for(i=0;i<9;i++)
        if(sudoku[row][i]==n || sudoku[i][column]==n)
            return 0;

    int row_squares = (row/3) * 3;
    int column_squares = (column/3) * 3;
    for(i=row_squares;i<row_squares+3;i++)
        for(j=column_squares;j<column_squares+3;j++)
            if(sudoku[i][j]==n)
                return 0;
    return 1;
}


int solve(){
    int row,column;
    if(free_square(&row,&column)==0)
        return 1;
    
    for(int i=1;i<=9;i++)
        if(check(i,row,column)){
            sudoku[row][column] = i;
            if(solve())
                return 1;
            sudoku[row][column] = 0;
        }
    return 0;

}


int main(int args,char * argv[]){
    if(!(strcmp(argv[1],"i"))){
        input(sudoku);
        if (solve())
            print_out();
        else
            printf("it's incorrect sudoku !");
    } else if(!strcmp(argv[1],"f")) {
        if (solve())
            print_out();
        else
            printf("it's incorrect sudoku !");
    }
    return 0;
}
