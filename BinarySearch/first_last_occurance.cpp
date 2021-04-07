class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = get_index(nums, target, true);
        int second = get_index(nums, target, false);
        vector<int> result;
        result.push_back(first);
        result.push_back(second);
        return result;


    }
    int get_index(vector<int> & nums, int target, bool flag){
        if (nums.size() == 0){
            return -1;
        }
        int start = 0;
        int result = -1;
        int end = nums.size() - 1;
        while (start <= end){
            int mid = start + (end - start) / 2;
            if (target == nums[mid] and flag){
                result = mid;
                end = mid - 1;
            }
            else if (target == nums[mid] and !flag){
                result = mid;
                start = mid + 1;
            }
            else if (target < nums[mid]){
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return result;
    }

};
int main(){
    vector <int> arr = {2, 10, 10, 10, 10, 10, 11, 12, 15};
    Solution obj;
    vector<int> result = obj.searchRange(arr, 10);
    cout<< result[0] << result[1] << endl;
}
