class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 0
        n = len(nums)
        start = 0
        end = n -1;
        result = 0
        while start <= end:
            mid = start + (end - start)// 2
            if mid > 0 and mid < n -1:
                if nums[mid] > nums[mid+1] and nums[mid] > nums[mid-1]:
                    return mid
                elif nums[mid+1] > nums[mid]:
                    start = mid + 1
                else:
                    end = mid - 1
            elif mid == 0:
                if nums[mid] > nums[mid+1]:
                    return mid
                return mid + 1
            elif mid == n -1:
                if nums[mid] > nums[n-2]:
                    return mid
                return  n -2
        return result
            
