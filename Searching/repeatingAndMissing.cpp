 
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int repeating = 0;
        int missing = 0;
        for (int i = 0; i < n; i++){
            if (arr[abs(arr[i])-1] < 0){
                repeating = abs(arr[i]);
            }
            else {
                arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];

            }
        }
        for (int i = 0; i < n; i++){
            if (arr[i] > 0){
                missing = i+1;
            }
        }
        int *v = new int[2];
        v[0] = repeating;
        v[1] = missing;
        return v;
    }
};
