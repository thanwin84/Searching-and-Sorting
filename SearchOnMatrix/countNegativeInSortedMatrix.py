class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        row = len(grid)
        col = len(grid[0])
        i = 0
        j = 0
        count = 0
        while (i < row and j < col):
            if grid[i][j] < 0:
                count += (col - j)
                i += 1
                j = 0
            elif j == col -1:
                i += 1;
                j = 0
            else:
                j += 1
        return count
class Solution:
    def firstIndex(self, arr):
        start = 0
        end = len(arr) -1
        count = 0
        location = -1
        while start <= end:
            mid = start + (end - start)//2
            if (arr[mid] < 0):
                location = mid
                end = mid - 1;
            else:
                start = mid + 1
        return location
    def countNegatives(self, grid: List[List[int]]) -> int:
        row = len(grid)
        col = len(grid[0])
        i = 0
        j = 0
        count = 0
        while i < row:
            first = self.firstIndex(grid[i])
            if first >= 0:
                count += (col - first)
                i += 1
            else:
                i += 1
        return count
