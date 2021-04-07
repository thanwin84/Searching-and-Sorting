#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int count(vector<vector<int>> &mat, int mid){
        int row = mat.size();
        int col = mat[0].size() -1;
        int count =0;
        for (int i = 0; i < row; i++){
            for (int j = col; j >= 0; j--){
                if (mat[i][j] <= mid){
                    count += j + 1;
                    break;
                }
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int start = matrix[0][0];
        int end = matrix[matrix.size()-1][matrix[0].size()-1];
        while (start < end){
            int mid = start + (end - start)/2;
            int cnt = count(matrix, mid);
            if  (cnt >= k){
                end = mid;
            }
            else {
                start = mid + 1;
            }
        }
        return start;

    }
};
int main(){
     Solution obj;
     vector<vector<int>> mat = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
     cout<< obj.kthSmallest(mat, 3);
     return 0;
}
