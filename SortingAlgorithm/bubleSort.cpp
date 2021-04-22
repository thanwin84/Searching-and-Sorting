#include <bits/stdc++.h>
using namespace std;
vector<int> bubleSort(vector<int> &arr){
   for(int i = arr.size()-1; i >= 0; i--){
       for(int j = 0; j < i; j++){
           if (arr[j] > arr[j+1]){
               int temp = arr[j+1];
               arr[j+1] = arr[j];
               arr[j] = temp;
           }
       }

   }
   return arr;
}
