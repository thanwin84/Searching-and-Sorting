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
//improve quicksort using randomized
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
        srand(time(nullptr));
        int random = low + rand() % (high - low);
        int temp = arr[random];
        arr[random] = arr[high];
        arr[high] = temp;
        int pindex = partition2(arr, low, high);
        return pindex;

    }
    int partition2(int arr[], int low, int high){
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
