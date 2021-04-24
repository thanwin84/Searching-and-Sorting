class Solution {
private:
public:
    void swap(vector<int> &arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
}
    int minSwaps(vector<int>&arr){
        // Code here
        vector<int> mainArr = arr;
        int count = 0;
        sort(mainArr.begin(), mainArr.end());
        unordered_map<int, int> lookup;
        for (int i = 0; i < mainArr.size(); i++){
            lookup[mainArr[i]] = i;
        }
        //arr[i] != mainArr[i] means, arr[i] is not in the correct position
        // if arr[i] isn't in the correct position swap until it comes to right position
        for (int i = 0; i < arr.size(); i++){
            if (arr[i] != mainArr[i]){
                swap(arr, i, lookup[arr[i]]);
                count++;
                i--; // to check again if it is in the right position
            }
        }

        return count;
    }
};
