#time: O(logMin(n, m))
class Solution:
    def kthElement(self, arr1, arr2, n, m, k):
        if len(arr2) < len(arr2):
            return self.kthElement(arr2, arr1, m, n, k)
        x = len(arr1)
        y = len(arr2)
        start = 0
        if k > x:
            end = x
        else:
            end = k
        maxLeftX = 0
        minRightX = 0
        maxLeftY = 0
        minRightY = 0
        while start <= end:
            partitionX = start + (end - start)//2
            partitionY = k - partitionX
            if partitionY > y:
                start += 1
                continue
            if partitionX == 0:
                maxLeftX = float('-inf')
            else:
                maxLeftX = arr1[partitionX-1]
            if partitionX == x:
                minRightX = float('inf')
            else:
                minRightX = arr1[partitionX]
            if partitionY == 0:
                maxLeftY = float('-inf')
            else:
                maxLeftY = arr2[partitionY-1]
            if partitionY == y:
                minRightY = float('inf')
            else:
                minRightY = arr2[partitionY]
            if maxLeftX <= minRightY and maxLeftY <= minRightX:
                if maxLeftX > maxLeftY:
                    k = k - partitionY
                    return arr1[k-1]
                else:
                    k = k - partitionX
                    return arr2[k-1]
            elif maxLeftX > minRightY:
                end = partitionX - 1
            else:
                start = partitionX + 1

arr1 = [1]
arr2 = [2, 3, 6, 7]
obj = Solution()
print(obj.kthElement(arr1, arr2, len(arr1), len(arr2), 4))
