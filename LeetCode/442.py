#Source: https://leetcode.com/problems/find-all-duplicates-in-an-array

def findDuplicates(nums):
        output = []
        for _num in nums:
            index = abs(_num)-1
            if nums[index] < 0:
                output.append(index+1)
            else:
                nums[index] = -1*nums[index]
        return output 

print(findDuplicates([4,3,2,7,8,2,3,1]))