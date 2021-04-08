#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<int> arr, int mid, int m, int k){
        int bouquets = 0;
        int total = 0;
        for (auto &i: arr){
            if (total == k){
                bouquets += 1;
                total = 0;
            }
            if (bouquets >= m){
                return true;
            }

            if (i <= mid){
                total ++;
            }
            else if (i > mid){
                if (total < k){
                    total = 0;
                }
            }

        }
        if (total == k){
            bouquets += 1;
        }
        if (bouquets >= m){
            return true;
        }
        else {
            return false;
        }
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()){
            return -1;
}
        int _max = bloomDay[0];
        for (int i = 1; i < bloomDay.size(); i++){
            if (bloomDay[i] > _max){
                _max = bloomDay[i];
            }
        }
        int start = 1;
        int end = _max;
        int result = _max;
        while (start <= end){
            int mid = start + (end - start)/2;
//            cout << start << " "<< mid << " "<< end <<" "<<check(bloomDay, mid, m, k)<< endl;
            if (check(bloomDay, mid, m, k)){
                end = mid - 1;
                result = min(result, mid);
            }
            else {
                start = mid + 1;
            }
        }
        return result;

    }
};
int main() {
    vector<int> arr = {1000000000,1000000000};
    Solution obj;
    cout << obj.minDays(arr,9, 1 );
//    cout << obj.check(arr, 9, 4, 2);

    return 0;
}
