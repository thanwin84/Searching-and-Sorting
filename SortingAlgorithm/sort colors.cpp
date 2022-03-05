// time: O(n) and space: O(1)
class Solution {
public:
    void swap(vector<int> &nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void sortColors(vector<int>& nums) {
        int pivotIndex = 0;
        int midValue = 1;
        // forward pass
        for (int curr = 0; curr < nums.size(); curr++){
            if (nums[curr] < midValue){
                swap(nums, pivotIndex, curr);
                pivotIndex++;
            }
        }
        // backward pass
        pivotIndex = nums.size() - 1;
        for (int curr = nums.size() -1; curr >= 0; curr--){
            if (nums[curr] > midValue){
                swap(nums, pivotIndex, curr);
                pivotIndex--;
            }
            else if (nums[curr] < midValue){
                break;
            }
        }
    }
};
