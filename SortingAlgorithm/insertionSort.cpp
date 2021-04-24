//best case: O(n)
//worst case and average case: O(n^2)
vector<int> insertionSort(vector<int> &arr){
    for (int i = 0; i < arr.size(); i++){
        int value = arr[i];
        int hole = i;
        while (hole > 0 and arr[hole-1] > value){
            arr[hole] = arr[hole - 1];
            hole--;
        }
        arr[hole] = value;
    }
    return arr;
}
