class Node:
    def __init__(self, key, value=1):
        self.key = key
        self.value = value
        self.next = None


class HashTable:
    def __init__(self, num_data):
        self.load_factor = 3
        self.size = max(10, num_data // self.load_factor)
        self.table = [None] * self.size

    def _hash(self, key):
        return hash(key) % self.size


    def hash_insert(self, key, value=1):
        index = self._hash(key)
        current = self.table[index]

        # If key already exists, update value
        while current:
            if current.key == key:
                current.value += value
                return
            current = current.next

        # Insert new node
        new_node = Node(key, value)
        new_node.next = self.table[index]
        self.table[index] = new_node


    def hash_search(self, key):
        index = self._hash(key)
        current = self.table[index]

        while current:
            if current.key == key:
                return True
            current = current.next

        return False


    def hash_get(self, key):
        index = self._hash(key)
        current = self.table[index]

        while current:
            if current.key == key:
                return current.value
            current = current.next

        return 0


    def hash_print(self):
        print("Hash Table:")
        for i, node in enumerate(self.table):
            print(f"Slot {i}: ", end="")
            current = node
            while current:
                print(f"({current.key}:{current.value}) -> ", end="")
                current = current.next
            print("None")

class Solution:
    def subarray_sum(self, nums, k):
        # nums: integer array.
        # k: the desired sum.
        # Returns:
        # count: The number of subarrays summing to be k.

        # -------- DO NOT MODIFY ANYTHING ABOVE THIS LINE OR YOUR SOLUTION WILL GET 0 MARKS --------
        prefix = {0: 1}
        sum = 0
        count = 0

        for num in nums:
            sum += num
            count += prefix.get(sum - k, 0)
            prefix[count] = prefix.get(sum, 0) + 1
        
        return count

        # -------- DO NOT MODIFY ANYTHING BELOW THIS LINE OR YOUR SOLUTION WILL GET 0 MARKS --------
        