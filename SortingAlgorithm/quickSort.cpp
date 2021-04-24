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
// suppose we  all have  repeating character in array [4, 4, 4, 4, 4, 4]. if we use single partition method, in the first partition we will get 2 groups, one is empty and
//another is n-1, the next will be n-2, n-3  and so on which makes O(n^2). We can can handle duplicate keys by using three ways partitioning method such as Dutch national flag
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
//improved quicksort to handle repeating keys
class Solution
{
public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if (low < high){
            pair<int, int> p = dNL_partition(arr, low, high);
            quickSort(arr, low, p.first-1);
            quickSort(arr, p.second + 1, high);
        }
    }

public:

    pair<int, int> dNL_partition(int arr[], int low, int high){
        srand(time(nullptr));
        int random = low + rand() % (high - low);
        int pivot = arr[high];
        int firstPIndex = low;
        //forward pass to check if arr[i] is less than the pivot
        for(int i = low; i < high; i++){
            if(arr[i] < pivot){
                int temp = arr[i];
                arr[i] = arr[firstPIndex];
                arr[firstPIndex] = temp;
                firstPIndex += 1;
            }
        }
        int secondPINdex = high;
        //backward pass to check if arr[i] is greater than pivot
        // if we get arr[i] < pivot, it means we are in the lesser region. In this case, we break the loop
        for(int i = high; i >= low; i--){
            if (arr[i] > pivot){
                int temp = arr[i];
                arr[i] = arr[secondPINdex];
                arr[secondPINdex] = temp;
                secondPINdex--;
            }
            else if (arr[i] < pivot){
                break;
            }
        }
        return {firstPIndex, secondPINdex};
    }
};
