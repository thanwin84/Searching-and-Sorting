class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        first = self.get_index(nums, target, 'f')
        second = self.get_index(nums, target, 'l')
        result = [first, second]
        return result
    
    def get_index(self, nums, target, flag):
        if len(nums) == 0:
            return -1
        start = 0
        end = len(nums) - 1
        location = -1
        while start <= end:
            mid = start + (end - start)//2
            if target == nums[mid] and flag == 'f':
                location = mid
                end = mid - 1
            elif target == nums[mid] and flag == 'l':
                location = mid
                start = mid + 1
            elif target < nums[mid]:
                end = mid - 1
            else:
                start = mid + 1
        return location
