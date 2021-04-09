#time: O(n+m)
// find the first negative index in every row
// suppose we have [5, 4, -1, -2, -3] ->we will start from rightmost corner and check if we  meet with negative, if we meet negative at first, it is gueranteed that right
//after this first index all element will be negative since it's sorted.Here the first negative index is 2, so the negative count will be col - first negative index(5-2=3).
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
//O(n + log(m))
// in this optimized approach we will just the first index using binary search.
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstIndex(vector<int> &arr){
        int start = 0;
        int end = arr.size()-1;
        int location = -1;
        while (start <= end){
            int mid = start + (end - start)/2;
            if (arr[mid] < 0){
                end = mid - 1;
                location = mid;
            }
            else {
                start = mid + 1;
            }
        }
        return location;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int i = 0;
        int count = 0;
        while (i < row){

            int first = firstIndex(grid[i]);
            if (first >= 0){
                count += (col - first);
                i ++;
            }
            else {
                i++;
            }

        }
        return count;
    }
};
