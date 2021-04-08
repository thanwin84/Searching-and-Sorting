#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<int> &pile, int H, int k){
        int totalH = 0;
        for (auto &i: pile){
            totalH += ceil(i/(k * 1.0));

            if (totalH > H){
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int _max= 0;
        for (auto &i: piles){
            if (i > _max){
                _max = i;
            }
        }
        int start = 1;
        int end = _max;
        int result = _max;
        while (start <= end){
            int mid = start + (end - start)/2;
//            cout << start << " "<< mid << " "<< end <<" " << check(piles, h, mid)<<endl;
            if (check(piles, h, mid)){
                result = min(result, mid);
                end = mid -1;
            }
            else {
                start = mid + 1;
            }
        }
        return result;

    }
};

int main(){
    vector<int> arr = {30,11,23,4,20};

    Solution obj;
    cout << obj.minEatingSpeed(arr, 6);
//    cout<< obj.check(arr, 8, 23);
//    cout << ceil(30/23.0);


    return 0;
}
