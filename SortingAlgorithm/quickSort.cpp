//picking the last element as pivot
//O(nlogn) - average case running time
//O(n^2) - worst case but it can be avoided using ramdomized version
//randomized version gives high probability of o(nlogn)
using namespace std;
class Solution
{
public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if (low < high){
            int pindex= partition(arr, low, high);
            quickSort(arr, low, pindex -1);
            quickSort(arr, pindex + 1, high);
        }
    }

public:
    int partition (int arr[], int low, int high)
    {
        // Your code here
        int pindex = 0;
        int pivot = arr[high];
        for (int i = 0; i < high; i++){
            if (arr[i] <= pivot){
                int temp = arr[i];
                arr[i] = arr[pindex];
                arr[pindex] = temp;
                pindex++;
            }
        }
        int temp = arr[pindex];
        arr[pindex] = arr[high];
        arr[high] = temp;
        return pindex;
    }
};
## Randomized quicksort
## Since the partition procedure has linear time complexity, the overall time complexity, in this case, is quadratic. This is the worst-case scenario for our input array.
class Solution
{
public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if (low < high){
            int pindex= RandomizedPartition(arr, low, high);
            quickSort(arr, low, pindex -1);
            quickSort(arr, pindex + 1, high);
        }
    }

public:


    int RandomizedPartition(int arr[], int low, int high){
        srand(time(nullptr));
        int random = low + rand() % (high - low);
        int pindex = 0;
        int pivot = arr[high];
        for (int i = 0; i < high; i++){
            if (arr[i] <= pivot){
                int temp = arr[i];
                arr[i] = arr[pindex];
                arr[pindex] = temp;
                pindex++;
            }
        }
        int temp = arr[pindex];
        arr[pindex] = arr[high];
        arr[high] = temp;
        return pindex;
    }
};
