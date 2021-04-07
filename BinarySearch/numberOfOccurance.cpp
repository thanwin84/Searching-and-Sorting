class Solution{
public:
    /* if x is present in arr[] then returns the count
        of occurrences of x, otherwise returns 0. */
    int count(int arr[], int n, int x) {
        int first = getindex(arr,n,  x, 'f');
        int last = getindex(arr, n, x, 'l');
        if (first == -1 and last == -1){
            return 0;
        }
        int result = last - first + 1;
        return result;
    }
    int getindex(int arr[], int n, int target, char c){
        int start = 0;
        int end = n - 1;
        int location = -1;
        while (start <= end){
            int mid = start + (end - start) / 2;
            if (target == arr[mid] and c == 'f'){
                location = mid;
                end = mid - 1;
            }
            else if (target == arr[mid] and c == 'l'){
                location = mid;
                start = mid + 1;
            }
            else if (target < arr[mid]){
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return location;
    }
};
