#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
using namespace std;
int debug=1;
int main(void)
{
    /*
    ofstream outfile;
    outfile.open("hw1.output");
    */
    int column, row;
    int loopCount = 0;
    int count = 0;

    cin >> row >> column;
     // cout << "#################result output" << endl;
    while (column != 0 && row != 0)
    {
        loopCount++;
        /*
        if(debug){
            outfile << "Field #" << loopCount << ":" << endl;
        }
        */
        printf("Field #%d:\n", loopCount);

        char inputMatrix[row][column];
        char outputMatrix[row][column];
        //scan input
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                cin >> inputMatrix[i][j];
            }
        }
        //convert to output matrix
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                for (int tmp_i = -1; tmp_i <= 1; tmp_i++)
                {
                    for (int tmp_j = -1; tmp_j <= 1; tmp_j++)
                    {
                        int tmp_row = i + tmp_i;
                        int tmp_col = j + tmp_j;
                        if (tmp_row >= 0 && tmp_col >= 0 && tmp_row < row && tmp_col < column )
                        {
                            if (inputMatrix[tmp_row][tmp_col] == '*')
                            {
                                count++;
                            }
                        }
                    }
                }
                if (inputMatrix[i][j] == '*')
                {
                    outputMatrix[i][j] = '*';
                }
                else
                {
                    outputMatrix[i][j] = count + 48;
                }
                count=0;
            }
        }
        //print out result
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                /*
                if(debug){
                    outfile << outputMatrix[i][j];
                }
                */
                cout << outputMatrix[i][j];
            }
            /*
            if(debug){
                outfile << "" << endl;

            }
            */
            cout << "" << endl;
        }
        // next loop initial
        count=0;
        cin >> row >> column;
        //if(!(row == 0 && column == 0)) outfile << "" << endl;
        if(!(row == 0 && column == 0)) cout << "" << endl;
        
        
    }
    //outfile.close();
}