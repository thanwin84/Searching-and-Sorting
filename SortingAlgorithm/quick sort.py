# quick sort algorithm
from random import randint


def swap(arr, left, right):
    temp = arr[left]
    arr[left] = arr[right]
    arr[right] = temp

class Solution:
    def partition(self, arr, start, end):
        pivotIndex = randint(start, end)
        swap(arr, pivotIndex, end)
        pivot = arr[end]
        i = start
        for currInd in range(start, end):
            if arr[currInd] <= pivot:
                swap(arr, currInd, i)
                i += 1
        swap(arr, i, end)
        return i

    def improvedPartition(self, arr, start, end):
        # all the elements lesser than the pivot will be in left
        # all the elements greater than the pivot will be in end
        # and all the elements equal to the pivot will be in the middle
        # this algorithm is good for handling duplicate keys
        randomNumber = randint(start, end)
        # swap end index element with  the random index
        swap(arr, end, randomNumber)
        pivot = arr[end]
        fowardIndex = start
        # forward pass to scan elements that are lesser than the pivot
        for i in range(start, end):
            if arr[i] < pivot:
                swap(arr, fowardIndex, i)
                fowardIndex += 1
        # backward pass to scan elements that are greater the pivot
        backwardIndex = end
        for i in range(end, -1, -1):
            if arr[i] > pivot:
                swap(arr, i, backwardIndex)
                backwardIndex -= 1
            # we are already in lesser region
            elif arr[i] < pivot:
                break
        result = [fowardIndex, backwardIndex]
        return result

    def quickSortHelper(self, arr, start, end):
        if start >= end:
            return
        indexes = self.improvedPartition(arr,start, end)
        pStart = indexes[0]
        pEnd = indexes[1]
        self.quickSortHelper(arr, start, pStart - 1)
        self.quickSortHelper(arr, pEnd + 1, end)

    def quickSort(self, arr):
        self.quickSortHelper(arr, 0, len(arr) - 1)
        return arr


arr = [70, 5, 10, 6, 4, 6, 8, 1]
ob = Solution()
print(ob.quickSort(arr))
# for i in range(3, -1, -1):
#     print(i)
ob.improvedPartition([0, 1, 2, 0, 2, 1, 1], 0, 6)
