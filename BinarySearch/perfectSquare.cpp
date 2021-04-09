//time: O(√n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1){
            return true;
        }
        long long res = 0;
        for (long long i =0; i < num; i++){
            if (i*i >= num){
                res = i;
                break;
            }
        }
        if (res *res == num){
            return true;
        }
        else{
            return false;
        }
    }
};
//time: O(log√n)
class Solution {
public:
    bool isPerfectSquare(int num) {
        long sq;
        long start = 0;
        long end = 50000;
        while (start <= end){
            long mid = start + (end - start)/2;
            sq = mid * mid;
            if (sq == num){
                return true;
            }
            else if (sq < num){
                start = mid + 1;
            }
            else if (sq > num){
                end = mid - 1;
            }
        }
        return false;
        
    }
};
