
class Solution_217:
    def __init__(self):
        pass

    def containsDuplicate(self, nums :list[int]) -> bool:
        nums.sort()
        for i in range( 1 , len(nums)):
            if nums[i] == nums[i-1]:
                return True
        return False
    
    def containsDuplicate_dict(self , nums: list[int]) -> bool:
        seen = {}
        for num in nums:
            if num in seen:
                return True
            seen[num] = True
        return False
    def containsDuplicate_set(self , nums: list[int]) -> bool:
        return len(nums) != len(set(nums))

if __name__ == "__main__":
    s: Solution_217 = Solution_217()
    nums: list[int] = [1,2,3,4,4,5,6,7]
    print(s.containsDuplicate(nums))
    print(s.containsDuplicate_dict(nums))
    print(s.containsDuplicate_set(nums))