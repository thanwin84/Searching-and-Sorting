#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 0){
            return nums[0];
        }
        int start = 0;
        int n= nums.size();
        int end = n - 1;
        int result = 0;
        while (start <= end){
            int mid = start + (end - start)/ 2;
            int next = (mid +1) % n;
            int prev = (mid + n -1) % n;
            if (nums[start] < nums[mid] and nums[mid] < nums[end]){
                return nums[start];
            }
            if (nums[mid] < nums[prev] and nums[mid] < nums[next]){
                return nums[mid];
            }
            if (nums[mid] >= nums[start]){
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

    }
};

int main(){
     vector<int> arr = {6, 8, 11, 12, 15, 18, 2, 5};
     Solution obj;
     cout<< obj.findMin(arr);
     return 0;
}
