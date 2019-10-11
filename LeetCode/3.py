class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        longest = 1
        current_len = 1
        substr_map = {s[0]: 0} #For fast lookup
        substr = s[0] # To keep track of current substring
        for char in s[1:]:
            if char in substr_map:
                if len(substr) > longest:
                    longest = len(substr)
                idx = substr_map[char]
                substr = substr[idx+1:] + char
                current_len = len(substr)
                substr_map = dict(zip(substr, range(0, current_len)))
            else:
                substr += char
                substr_map[char] = current_len
                current_len += 1
        longest = longest if longest > current_len else current_len
        return longest