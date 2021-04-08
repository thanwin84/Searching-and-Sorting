class Solution:
    def isPossible(self, arr, D, max_capacity):
        countDays = 1
        countW = 0
        for i in arr:
            countW += i
            if i > max_capacity:
                return False
            elif countDays > D:
                return False
            elif countW > max_capacity:
                countDays += 1
                countW = i
        if countDays <= D:
            return True
        else:
            return False
        
    def shipWithinDays(self, weights: List[int], D: int) -> int:
        total = sum(weights)
        start = weights[0]
        end = total
        result = float('inf')
        while start <= end:
            mid = start + (end - start)//2
            if (self.isPossible(weights, D, mid)):
                result = min(result, mid)
                end = mid -1
            else:
                start = mid + 1
        return result
        
