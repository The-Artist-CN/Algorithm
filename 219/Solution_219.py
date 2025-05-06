
class Solution_219:
    
    def containsNearbyDuplicate(self, nums: list[int], k: int) -> bool:
        seen = {}
        for i, num in enumerate(nums):
            if num in seen and i - seen[num] <= k:
                return True
            seen[num] = i
        return False
    
    def containsNearbyDuplicate_Set(self, nums: list[int], k: int) -> bool:
        s = set()
        for i, num in enumerate(nums):
            if i > k:
                s.remove(nums[i - k - 1])
            if num in s:
                return True
            s.add(num)
        return False