# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = 0
        ans = None
        begin_node = None
        while True:
            # Handle the terminating condition
            if (l1 is None) and (l2 is None):
                if carry == 1:
                    ans.next = ListNode(1)
                break
            # Handle if both are not same in length
            curr_num_1 = 0 if l1 is None else l1.val
            curr_num_2 = 0 if l2 is None else l2.val

            # Handle carry
            curr_num_ans = curr_num_1 + curr_num_2 + carry
            carry = 0
            if curr_num_ans > 9:
                carry = 1
                curr_num_ans = curr_num_ans % 10
            node = ListNode(curr_num_ans)
            # Handle the beginning
            if ans is None:
                ans = node
                begin_node = ans
            else:
                ans.next = node
                ans = ans.next
            
            l1 = None if l1 is None else l1.next
            l2 = None if l2 is None else l2.next

        return begin_node
