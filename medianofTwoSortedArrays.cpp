#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }
        int x = nums1.size();
        int y = nums2.size();
        int start = 0;
        int end = x;
        int maxLeftX, minRightX, maxLeftY, minRightY;
        while (start <= end){
            int partitionX = start + (end - start)/2;
            int partitionY = (x + y + 1)/2 - partitionX;
            //if partitionX is 0, there is nothing on the left side, use -inf
            if (partitionX == 0)  maxLeftX = INT_MIN;
            else  maxLeftX = nums1[partitionX-1];
            //if partitionX is equal ot x, it means there is nothing on the right side, use +inf
            if (partitionX == x) minRightX = INT_MAX;
            else minRightX = nums1[partitionX];
            //if partitionY is 0 means nothing on the left side, so use -inf
            if(partitionY == 0) maxLeftY = INT_MIN;
            else maxLeftY = nums2[partitionY-1];
            if (partitionY == y) minRightY = INT_MAX;
            else minRightY = nums2[partitionY];
            if (maxLeftX <= minRightY && maxLeftY <= minRightX){
                if ((x + y) % 2 == 0){
                    cout << max(maxLeftX, maxLeftY) << " " <<min(minRightX, minRightY) << endl;
                    return (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2;
                }
                else{

                    return (double)max(maxLeftX, maxLeftY);
                }
            }
            else if (maxLeftX > minRightY) end = partitionX -1;//we are too far on right side, so go left
            else start = partitionX + 1; //we are too far on left side for partX, so go right
        }
        return -1;

    }
};
