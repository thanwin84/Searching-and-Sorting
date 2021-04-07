#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size()==1){
            return 0;
        }
        int start = 0;
        int end = nums.size() - 1;
        int result = 0;
        while (start <= end){
            int mid = start + (end - start) / 2;
            if (mid > 0 and mid < nums.size() - 1){
                if (nums[mid] > nums[mid-1] and nums[mid] > nums[mid+1]){
                    return mid;
                }
                else if (nums[mid + 1] > nums[mid]){
                    start = mid + 1;
                }
                else {
                    end = mid -1;
                }
            }
            else if (mid == 0){
                if (nums[mid] > nums[mid+1]){
                    return mid;
                }
                else {
                    return mid+1;
                }
            }
            else if (mid == nums.size() - 1){
                if (nums[mid] > nums[nums.size()-2]){
                    return mid;
                }
                else {
                    return nums.size() - 2;
                }
            }
        }
        return result;

    }
};
