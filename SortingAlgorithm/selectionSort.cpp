//time: O(n^2)
#include <bits/stdc++.h>
using namespace std;
vector<int> selectionSort(vector<int> &arr){
    for (int i = 0; i < arr.size()-1; i++){
        int mini = i;
        for (int j = i+1; j <arr.size(); j++){
            if (arr[j] < arr[mini]){
                mini= j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[mini];
        arr[mini] = temp;
    }
    return arr;
}
int main(){
    vector<int> arr = {8, 3, 5, 1, 4};
    selectionSort(arr);
    for (auto i: arr){
        cout << i << " ";
    }
    return 0;
}
