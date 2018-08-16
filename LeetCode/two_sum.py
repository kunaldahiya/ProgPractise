# Link: https://leetcode.com/problems/two-sum

__author__ = 'KD'

class BruteForce:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for idx_1, item_1 in enumerate(nums):
            for idx_2, item_2 in enumerate(nums[idx_1+1:]):
                if item_1 + item_2 == target:
                    return [idx_1, idx_1+idx_2+1]

class HashTwoPass:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # Create hash from number to indices
        mapping = dict(zip(nums, range(len(nums))))
        # Look for compliments in Hash table
        for idx, num in enumerate(nums):
            temp = target - num
            # Ensure that number is not compliment to itself
            if temp in mapping:
                idx_comp = mapping[temp]
                if idx != idx_comp:
                    return [idx, idx_comp]

class HashOnePass:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        mapping = {nums[0]: 0}
        # Look for compliments in Hash table
        for idx, num in enumerate(nums[1:]):
            temp = target - num
            # Ensure that number is not compliment to itself
            if temp in mapping:
                return [mapping[temp], idx+1]
            mapping[num] = idx+1
