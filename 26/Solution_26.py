

def removeDuplicateNumber(nums):
    if not nums:
        return 0
    
    slow = 0

    for fast in range(len(nums)):
        if nums[fast] != nums[slow]:
            slow += 1
            nums[slow] = nums[fast]

    return slow + 1;

def main():
    nums = [1,1,2,2,2,3,4,4,5,5,5,6,6]
    result = removeDuplicateNumber(nums)
    print("result = ",result)
    print("last = ",nums[:result])

if __name__ == '__main__':
          main()
