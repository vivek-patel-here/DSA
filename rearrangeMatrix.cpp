#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printMatrix(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int column = matrix[0].size();
    for (int i = 0; i < row; i++)
    {
        cout << "[ ";
        for (int j = 0; j < column; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "]" << endl;
    }
    cout << endl;
}

void arrangeMatrix(vector<vector<int>> &grid)
{
    int size = grid.size();

    //Arranging the bottom-left part
    for (int i = 0; i < size; i++)
    {
        int indx1 = i;
        int indx2 = 0;
        vector<int> diagonal;
        while (indx2 < size - i)
        {
            diagonal.push_back(grid[indx1][indx2]);
            indx1++;
            indx2++;
        }
        sort(diagonal.begin(), diagonal.end());
        indx1 = i;
        indx2 = 0;
        while (indx2 < size - i)
        {
            grid[indx1][indx2] = diagonal[diagonal.size() - 1 - indx2];
            indx1++;
            indx2++;
        }
    }

    //Arranging the top-right half
    for (int i = 1; i < size; i++)
    {
        int indx1 = 0;
        int indx2 = i;
        vector<int> diagonal;
        while (indx2 < size)
        {
            diagonal.push_back(grid[indx1][indx2]);
            indx1++;
            indx2++;
        }

        sort(diagonal.begin(), diagonal.end());
        indx1 = 0;
        indx2 = i;
        while (indx2 < size)
        {
            grid[indx1][indx2] = diagonal[indx1];
            indx1++;
            indx2++;
        }
    }
}

int main()
{
    // vector<vector<int>> grid = {{1, 7, 3}, {9, 8, 2}, {4, 5, 6}};
    vector<vector<int>> grid = {{0,1},{1,2}};
    printMatrix(grid);
    arrangeMatrix(grid);
    printMatrix(grid);

    return 0;
}