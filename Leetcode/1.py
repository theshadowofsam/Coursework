"""
Samuel Lee
07/15/2024
1.py
Leetcode problem 1
"""

# Definition for singly-linked list.
# Straight from the Leetcode problem
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        remainder = 0
        result = ListNode()
        a = result
        
        # Theres probably a syntactically better way to write this block
        while l1 or l2 or remainder:
            v1 = 0
            v2 = 0
            if l1:
                v1 = l1.val
                l1 = l1.next
            if l2:
                v2 = l2.val
                l2 = l2.next
            a.val = (v1 + v2 + remainder) % 10
            remainder = (v1 + v2 + remainder) // 10
            if l1 or l2 or remainder:
                a.next = ListNode()
                a = a.next
        
        # I find it interesting that pylance thinks this return is unreachable, i guess it cant account for everything
        return result 
    
def test(l):
    result = ListNode()
    a = result
    for i in range(len(l)):
        a.val = l[i]
        if i != len(l) - 1:
            a.next = ListNode()
            a = a.next
    return result

# I just manually did testing here
if __name__ == '__main__':
    tl1 = test([9,9,9,9,9,9,9])
    tl2 = test([9,9,9,9])
    result = Solution().addTwoNumbers(tl1, tl2)
    while result:
        print(result.val)
        result = result.next
    