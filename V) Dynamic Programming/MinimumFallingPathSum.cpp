// Question Details:
// Problem Statement Description: 
// Given an n x n integer matrix arr, return the minimum sum of a falling path with non-zero elements.
// A falling path starts at any element in the first row and chooses one element from each row. The next element in the path must be in a column that is one to the left, the same, or one to the right of the current element.
// Constraints:
// 1 <= n <= 100
// -100 <= arr[i][j] <= 100

// Input:
// An n x n integer matrix arr.

// Output:
// The minimum sum of a falling path in the matrix.

#include <iostream>     
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int f(int i, int j, vector<vector<int>> arr) {
        int n = arr.size();
        if(j < 0 || i >= n || j >= n) {
            return 1e8;
        }
        if(i == n - 1) {
            return arr[i][j];
        }
        int dl = f(i + 1, j - 1, arr);
        int d = f(i + 1, j, arr);
        int dr = f(i + 1, j + 1, arr);
        return arr[i][j] + min(d, min(dl, dr));
    }

    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        if(n == 1) {
            return arr[0][0];
        }
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0) {
                    dp[i][j] = arr[i][j];
                } else {
                    if(j == 0) {
                        dp[i][j] = arr[i][j] + min(dp[i-1][j], dp[i-1][j+1]);
                    } else if(j == n-1) {
                        dp[i][j] = arr[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
                    } else {
                        dp[i][j] = arr[i][j] + min(dp[i-1][j], min(dp[i-1][j+1], dp[i-1][j-1]));
                    }
                }
            }
        }

        int min2 = 1e8;
        for(int i = 0; i < n; i++) {
            min2 = min(min2, dp[n-1][i]);
        }
        return min2;
    }
};

int main() 
{ 
    Solution solution;
    vector<vector<int>> arr = {
        {2,1,3},
        {6,5,4},
        {7,8,9}
    };
    cout << "Minimum Falling Path Sum: " << solution.minFallingPathSum(arr) << endl;
    return 0;
}  
