#include <bits/stdc++.h>
using namespace std;
int checkPair(vector<int> &arr, int target){
    unordered_map<int, int> lookup;
    for (auto & i: arr){
        lookup[i] = 1;
    }
    int ans = -1;
    for (auto &i: arr){
        int y = target + i;
        if (lookup[y]){
            ans = 1;
            break;
        }
    }
    return ans;
}
int main(){
    int t;
    cin >> t;
    vector<int> result;
    while (t--){
        int L, N;
        cin >> L>> N;
        int item;
        vector<int> arr;
        for (int i = 0; i < L; i++){
            cin >> item;
            arr.push_back(item);
        }
        int output = checkPair(arr, N);
        result.push_back(output);
    }
    for (auto &i: result){
        cout << i << endl;
    }
    return 0;
}
