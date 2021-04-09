#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int j = 0;
        int i = 0;
        int count = 0;
        while (j < col and i < row){
            if (grid[i][j] < 0){
                count += (col - j);
                i ++;
                j = 0;
            }
            else {
                j ++;
            }
        }
        return count;


    }
};
