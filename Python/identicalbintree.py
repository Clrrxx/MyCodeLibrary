class BTNode():
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class StackNode():
    def __init__(self, data):
        self.data = data
        self.next = None

class Stack():
    def __init__(self):
        self.top = None
        self.size = 0

    def push(self, data):
        newNode = StackNode(data)
        newNode.next = self.top
        self.top = newNode
        self.size += 1

    def peek(self):
        return self.top.data
    
    def pop(self):
        if self.isEmpty():
            raise IndexError("Empty")
        popped = self.top
        self.top = self.top.next
        self.size -=1
        return popped.data
    
    def isEmpty(self):
        return self.size == 0
    
def printTree(node, level=0, prefix="Root: "):
    if node is None:
        print(" " * level + prefix + str(node.item))
        if node.left or node.right:
            if node.left:
                printTree(node.left, level+4, "L--")
            
            if node.right:
                printTree(node.right, level+4, "R--")

def identicalTree(node1, node2):
    if node1 is None and node2 is None:
        return True
    
    if node1 is None or node2 is None:
        return False
    
    return node1.data == node2.data and identicalTree(node1.right, node2.right) and identicalTree(node1.left, node2.left)

    


if __name__ == "__main__":

    # Representation of input binary tree 1
    #        1
    #       / \
    #      2   3
    #     /
    #    4
    r1 = BTNode(1)
    r1.left = BTNode(2)
    r1.right = BTNode(3)
    r1.left.left = BTNode(4)

    # Representation of input binary tree 2
    #        1
    #       / \
    #      2   3
    #     /
    #    4
    r2 = BTNode(1)
    r2.left = BTNode(2)
    r2.right = BTNode(3)
    r2.left.left = BTNode(4)

    if identicalTree(r1, r2):
        print("true")
    else:
        print("false")
    

        