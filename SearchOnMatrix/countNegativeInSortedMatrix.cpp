#time: O(n+m)
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
            else if (j == col -1){
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
int main() {
    vector<vector<int>> mat = {{5,1,0},{-5,-5,-5}};
    Solution obj;
    cout<< obj.countNegatives(mat);


    return 0;
}
