class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        #checking boundary
        n = len(nums)
        if nums[0] != nums[1]:
            return nums[0]
        elif nums[n-1] != nums[n-2]:
            return nums[n-1]
        start = 0
        end = n -1
        while start <= end:
            mid = start + (end - start)//2
            #checking unique character
            if (nums[mid] != nums[mid-1] and nums[mid]!= nums[mid+1]):
                return nums[mid]
            if nums[mid] == nums[mid-1] and mid % 2 != 0 or nums[mid] == nums[mid+1] and mid % 2 == 0:
                start = mid + 1
            else:
                end = mid - 1
        
