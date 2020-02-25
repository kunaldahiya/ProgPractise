import math

class Solution:
    def maxArea(self, height):
        i = 0
        j = len(height)-1
        ans = -math.inf        
        while i<j:
            ans = max(ans, min(height[i], height[j])*(j-i))
            if height[i] < height[j]:
                i+=1
            else:
                j-=1
        return ans
        # Worst case solution


if __name__ == "__main__":
    x = [1, 8, 6, 2, 5, 4, 8, 3, 7]
    sol = Solution()
    print(sol.maxArea(x))
