class BTNode:
    def __init__(self, data, left=None, right=None):
        self.data = data  # Store the data (integer)
        self.left = left  # Reference to the left child node
        self.right = right  # Reference to the right child node

def insertBSTNode(root, value):
    """ Recursive approach to insert a node into a BST. """
    if root is None:
        return BTNode(value)
    if value < root.data:
        root.left = insertBSTNode(root.left, value)
    elif value > root.data:
        root.right = insertBSTNode(root.right, value)
    return root  # Ensure the modified node is returned

def findMin(node):
    """ Find the node with the smallest value in a subtree. """
    while node.left is not None:
        node = node.left
    return node

def printBSTInOrder(node):
    """ Print BST items in sorted order using in-order traversal. """
    if node:
        printBSTInOrder(node.left)
        print(node.data, end=" ")
        printBSTInOrder(node.right)

def printTree(node, level=0, prefix="Root: "):
    """ Pretty prints the tree structure for better visualization """
    if node is not None:
        print(" " * level + prefix + str(node.data))
        if node.left or node.right:
            if node.left:
                printTree(node.left, level + 4, "L--- ")
            if node.right:
                printTree(node.right, level + 4, "R--- ")

class Solution:
    def removeBSTNode(self, root, value):
        # -------- DO NOT MODIFY ANYTHING ABOVE THIS LINE OR YOUR SOLUTION WILL GET 0 MARKS --------
        # Write your code here #


        """Using in order predecssor so we invert the way the tree traverse
        instead of curr = curr.right do curr.left instead"""
        def getsuccessor(curr):
            while curr.right is not None:
                curr = curr.right
            return curr

        
        if root is None:
            return root

        if root.data > value:
            #root is larger go left
            root.left = self.removeBSTNode(root.left, value)
        
        elif root.data < value:
            #root is smaller go right
            root.right = self.removeBSTNode(root.right, value)

        else:
            #we have found the node now time to remove it based on children count
            if root.left is None:
                #no/1 children
                return root.right

            if root.right is None:
                #1 child 
                return root.left
            
            succ = getsuccessor(root.left)
            #get successor

            root.data = succ.data
            #replace the node data with successor's data

            root.left = self.removeBSTNode(root.left, succ.data)

        return root
        # -------- DO NOT MODIFY ANYTHING BELOW THIS LINE OR YOUR SOLUTION WILL GET 0 MARKS --------

if __name__ == "__main__":
    root = None
    print("Binary Search Tree Node Removal Program")
    print("=====================================")
    print("\nFirst, let's build the BST:")
    while True:
        try:
            value = input("\nEnter a value to insert (-1 to quit): ")
            if not value:
                continue  # Ignore empty inputs
            i = int(value)
            if i == -1:
                break
            root = insertBSTNode(root, i)
            print("\nCurrent BST structure:")
            printTree(root)
            print("\nIn-order traversal: ", end="")
            printBSTInOrder(root)
            print()
        except ValueError:
            print("Invalid input! Please enter an integer.")

    print("\nNow let's remove nodes:")
    while True:
        try:
            value = input("\nEnter a value to remove (-1 to quit): ")
            if not value:
                continue  # Ignore empty inputs
            i = int(value)
            if i == -1:
                break
            result = Solution().removeBSTNode(root, i)
            if result is not None:
                print("\nBST structure after removal:")
                printTree(root)
                print("\nIn-order traversal: ", end="")
                printBSTInOrder(root)
                print()
            else:  # result == -1
                print("Value not found in the tree!")
        except ValueError:
            print("Invalid input! Please enter an integer.")