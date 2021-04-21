//time: O(n+m) and space: O(1)
class Solution{
public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i = 0;
        int j = 0;
        int f = 0;
        while (i < n and j < m){
            if (arr1[i] < arr2[j]){
                f++;
                if (f == k){
                    return arr1[i];
                }
                i++;
            }
            else {
                f++;
                if(f == k){
                    return arr2[j];
                }
                j++;
            }
        }
        while (i < n){
            f++;
            if (f ==  k){
                return arr1[i];
            }
            i++;
        }
        while (j < m){
            f++;
            if (f == k){
                return arr2[j];
            }
        }

    }
};
