class Solution:
    def isPossible(self, arr, n, m, _max):
        sum = 0
        student = 1
        for i in arr:
            sum += i
            if sum > _max:
                student += 1
                sum = 0
                sum += i
            if student > m:
                return False
        return True
    def findPages(self,arr, n, m):
        if m > n:
            return -1
        _max = arr[0]
        sum = 0;
        for i in arr:
            sum += i
            if i > _max:
                _max = i
        start = _max
        end = sum
        result = float('inf')
        while start <= end:
            mid = start + (end - start)//2
            if (self.isPossible(arr, n, m, mid)):
                result = min(result, mid)
                end = mid - 1
            else:
                start = mid + 1
                
        return result
        
