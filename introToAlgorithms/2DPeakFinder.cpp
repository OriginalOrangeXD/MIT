#include<iostream>
#include<vector>

using namespace std;

int findPeak(vector<vector<int>> arr)
{
    float bestScore = -10000;
    vector<int> optimal;
    for(unsigned int i = 0; i < arr.size(); i++)
    {
        if(arr[i][(arr[0].size()-1)/2] > bestScore)
        {
            bestScore = arr[i][(arr[0].size()-1)/2];
            cout << bestScore << endl;
            optimal.clear();
            optimal.push_back(i);
            optimal.push_back((arr[0].size()-1)/2);
        }
    }
    if(bestScore >= arr[optimal[0]][optimal[1]+1] && bestScore >= arr[optimal[0]][optimal[1]-1])
    {
        return bestScore;
    }
    return 900;
}



int main()
{
    vector<vector<int>> arr {{1,2,3},
                             {3,4,5},
                             {7,8,7}};

    cout << findPeak(arr) << endl;
    return 1;
}
