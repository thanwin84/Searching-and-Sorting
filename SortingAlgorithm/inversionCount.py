class Solution:
    # User function Template for python3

    # arr[]: Input Array
    # N : Size of the Array arr[]
    # Function to count inversions in the array.
    def merge(self, arr, start, end, mid):
        count = 0
        n = mid - start + 1
        m = end - mid
        left = []
        right = []
        for i in range(start, mid+1):
            left.append(arr[i])
        for i in range(mid+1, end+1):
            right.append(arr[i])
        i = 0
        j = 0
        k = start
        while i < n and j < m:
            if left[i] <= right[j]:
                arr[k] = left[i]
                k += 1
                i += 1
            else:
                count += n - i
                arr[k] = right[j]
                j += 1
                k += 1
        while i < n:
            arr[k] = left[i]
            i += 1
            k += 1
        while j < m:
            arr[k] = right[j]
            j += 1
            k += 1
        return count

    def mergeSort(self, arr, start, end):
        inv = 0
        if start < end:
            mid = start + (end - start) // 2
            inv += self.mergeSort(arr, start, mid)
            inv += self.mergeSort(arr, mid + 1, end)
            inv += self.merge(arr, start, end, mid)
        return inv

    def inversionCount(self, arr, n):
        return self.mergeSort(arr, 0, n-1)


# Your Code Here

obj = Solution()
print(obj.inversionCount([2, 4, 1, 3, 5], 5))
# print(obj.merge([1, 2, 4, 6, 3, 5, 7, 8], 0, 8, 4))
