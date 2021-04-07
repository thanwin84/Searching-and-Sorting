#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool isPossible(vector<int> &chef, int orderedP, int mid){
        int countPrata = 0;
        int time = 0;
        for (int i = 1; i < chef.size(); i++){
            time = chef[i];
            int j = 2;
            while (time <= mid){
                countPrata += 1;
                time = time + chef[i] * j;
                j ++;
            }
            if (countPrata >= orderedP){
                return true;
            }
        }
        return false;
    }
    int minTime(vector<int> &arr, int totalChef, int orderedP){
        int result = INT_MAX;
        int start = 0;
        int end = 10e8;
        while (start <= end){
            int mid = start + (end - start)/2;
            if (isPossible(arr, orderedP, mid)){
                result = min(result, mid);
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return result;
    }
};

int main()
{
    int T;
    cin>> T;
    vector<int> result;
    while (T--){
        int P;
        cin >> P;
        vector<int> arr;
        int Cnum;
        cin >> Cnum;
        arr.push_back(Cnum);
        int n = Cnum;
        int rank;
        for (int i = 0; i < n; i++){
            cin >> rank;
            arr.push_back(rank);
        }
        Solution obj;
        int output = obj.minTime(arr, Cnum, P);
        result.push_back(output);
    }
    for (int i: result){
        cout << i << endl;
    }
    return 0;
}
