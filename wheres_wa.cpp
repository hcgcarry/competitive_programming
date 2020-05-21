#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm> // std::transform
#include <fstream>
#define debug 0
//#define cout debugfile


using namespace std;

#ifdef debug

    ofstream debugfile;
#endif 
class characterMatrix
{
    int row;
    int col;
    char matrix[50][50]={'c'};

public:
    void printMatrix(){
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j <this-> col; j++)
            {
                cout << this->matrix[i][j] ;
            }
            cout << endl;
        }
    }
    characterMatrix()
    {
    }
    void initial()
    {
        cin >> this->row >> this->col;
        //read matrix
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->col; j++)
            {
                char tmp;
                cin >> tmp;
                this->matrix[i][j] = tolower(tmp);
            }
        }
    }

    void searchName(string name)
    {
        int *position = new int(2);
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->col; j++)
            {
                bool hasFound;
                hasFound = searchEightDirection(i, j, name);
                if (hasFound == true)
                {
                    /*
                    cout << "name:" << name << " found:";
                    */
                    cout << i+1 << " " << j+1 << endl;
                    return;
                }
            }
        }
    }

    bool searchEightDirection(int curRow, int curCol, string name)
    {
        bool result = false;

        for (int i = 0; i < name.size(); i++)
        {
            if (curCol + i < this->col)
            {

                if (this->matrix[curRow][curCol + i] != name[i])
                {
                    break;
                }
                else if (i == name.size() - 1)
                {
                    result = true;
                }
            }
        }
        for (int i = 0; i < name.size(); i++)
        {
            if (curCol - i >= 0)
            {

                if (this->matrix[curRow][curCol - i] != name[i])
                {
                    break;
                }
                else if (i == name.size() - 1)
                {
                    result = true;
                }
            }
        }
        for (int i = 0; i < name.size(); i++)
        {
            if (curRow + i < this->row)
            {
                if (this->matrix[curRow + i][curCol] != name[i])
                {
                    break;
                }
                else if (i == name.size() - 1)
                {
                    result = true;
                }
            }
        }
        for (int i = 0; i < name.size(); i++)
        {
            if (curRow - i >= 0)
            {

                if (this->matrix[curRow - i][curCol] != name[i])
                {
                    break;
                }
                else if (i == name.size() - 1)
                {
                    result = true;
                }
            }
        }
        for (int i = 0; i < name.size(); i++)
        {
            if (curRow + i < this->row && curCol + i < this->col)
            {

                if (this->matrix[curRow + i][curCol + i] != name[i])
                {
                    break;
                }
                else if (i == name.size() - 1)
                {
                    result = true;
                }
            }
        }
        for (int i = 0; i < name.size(); i++)
        {
            if (curRow + i < this->row && curCol - i >= 0)
            {

                if (this->matrix[curRow + i][curCol - i] != name[i])
                {
                    break;
                }
                else if (i == name.size() - 1)
                {
                    result = true;
                }
            }
        }
        for (int i = 0; i < name.size(); i++)
        {
            if (curRow - i >= 0 && curCol - i >= 0)
            {

                if (this->matrix[curRow - i][curCol - i] != name[i])
                {
                    break;
                }
                else if (i == name.size() - 1)
                {
                    result = true;
                }
            }
        }
        for (int i = 0; i < name.size(); i++)
        {
            if (curRow - i >= 0 && curCol + i < this->col)
            {

                if (this->matrix[curRow - i][curCol + i] != name[i])
                {
                    break;
                }
                else if (i == name.size() - 1)
                {
                    result = true;
                }
            }
        }
        return result;
    }
};

int main(void)
{
    #ifdef debug
        debugfile.open("wheres_wa.dat", ios::out | ios::trunc );
    #endif

    int loop;
    cin >> loop;
    cin.ignore();
    while (loop--)
    {
        // read matrix
        characterMatrix matrixObject;
        matrixObject.initial();

        //read name
        int searchNameCount;
        cin >> searchNameCount;
        string tmp;

        for (int i = 0; i < searchNameCount; i++)
        {
            cin >> tmp;
            transform(tmp.begin(), tmp.end(), tmp.begin(), [](unsigned char c) { return std::tolower(c); });
            matrixObject.searchName(tmp);
        }
        if (loop)
        {
            cin.ignore();
            cout << endl;
        }
    }
}