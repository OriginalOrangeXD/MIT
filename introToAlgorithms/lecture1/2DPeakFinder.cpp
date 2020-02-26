#include<iostream>
#include<vector>

using namespace std;

int findPeak(vector<vector<int>> arr, int row, int col)
{
    float bestScore = -10000;
    vector<int> optimal;
    for(unsigned int i = 0; i < row; i++)
    {
        if(arr[i][col/2] > bestScore)
        {
            bestScore = arr[i][col/2];
            //cout << bestScore << endl;
            optimal.clear();
            optimal.push_back(i);
            optimal.push_back(col/2);
        }
    }
    if(bestScore >= arr[optimal[0]][optimal[1]+1] && bestScore >= arr[optimal[0]][optimal[1]-1])
    {
        return bestScore;
    }else
    {
        return findPeak(arr, row, col+1);
    }
}



int main()
{
    vector<vector<int>> arr {{1,2,3},
                             {3,4,10},
                             {7,8,9}};
    int cols = arr[0].size();
    int rows = arr.size();
    //cout << cols << endl << rows << endl;
    cout << findPeak(arr, rows, cols) << endl;
    return 1;
}
