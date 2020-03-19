#include <iostream>
#include <string>

int main(void){
    int column,row;
    int loopCount=0; 
    cin >> column >> row;
    while(column != 0 &&　row !=0 ){
        loopCount++;
        printf("Field #%d",loopCount);

        char inputMatrix[row][column];outputMatrix[row][column];
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                cin >> inputMatrix[i][j] ;
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                for(int tmp_i=-1;tmp_i<=1;tmp_i++){
                    for(int tmp_j=-1;tmp_j<=1;tmp_j++){
                        int tmp_row=i+tmp_i;
                        int tmp_col=j+tmp_j;
                        int count=0;
                        if(tmp_row >= 0 && tmp_col >= 0 ){
                            if(inputMatrix[tmp_row][tmp_col] == '*'){
                                count++;
                            }
                        }
                    }
                }
                if(inputMatrix[i][j]=='*'){
                    outputMatrix[i][j]='*';
                }
                else{
                    outputMatrix[i][j]=count;
                }
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
               cout << outputMatrix[i][j];
            }
            puts("");
        }

    }



}
/*
int findAdjMean(char** matrix,int row,int col,int colSize){
    char* position;
    position = matrix + row*colSize + col;

    for(int i=-1;i<=1;i++){ 
        for(int j=-1;j<=1;j++){

        }
    }


}
*/