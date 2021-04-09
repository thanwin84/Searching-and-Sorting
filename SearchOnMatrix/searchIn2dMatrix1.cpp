#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int i = 0;
        int j = col - 1;
        while (i >= 0 and i < row and j >= 0 and j < col){
            if (matrix[i][j] == target){
                return true;
            }
            else if (target < matrix[i][j]){
                j --;
            }
            else if (target > matrix[i][j]){
                i ++;
            }
        }
        return false;

    }
};
int main(){
     vector<vector<int>> mat = {{10, 20, 30, 40},
                                {15, 25, 35, 45},
                                {27, 29, 32, 45},
                                {32, 33, 39, 50}};
     Solution obj;

     cout<< obj.searchMatrix(mat, 10);
     return 0;
}
