//picking the last element as pivot
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
