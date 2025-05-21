def twoSum(nums, target):
    num_to_index = {}  # Stores {number: index} pairs
    
    for i, num in enumerate(nums):
        complement = target - num
        if complement in num_to_index:
            return [num_to_index[complement], i]
        num_to_index[num] = i
    
    return []  # Should never reach here per problem statement
