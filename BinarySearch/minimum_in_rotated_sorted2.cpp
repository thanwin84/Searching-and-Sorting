#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        while (start < end){
            int mid = start + (end - start)/ 2;
            if (nums[mid] == nums[end]){
                if (nums[mid] == nums[start]){
                    start += 1;
                }
                else {
                    end = mid;
                }
            }
            else if (nums[mid] > nums[end]){
                start = mid + 1;
            }
            else {
                end = mid;
            }
        }
        return nums[start];
    }
};

int main(){
     vector<int> arr = {1};
     Solution obj;
     cout<< obj.findMin(arr);
     return 0;
}
