class Node():
    def __init__(self, data):
        self.data = data
        self.right = None
        self.left = None

class Stack():
    def __init__(self):
        self.top = None
        self.size = 0

    def push(self, data):
        node = Node(data)
        node.next = self.top
        self.top =node
        self.size += 1

    def pop(self):
        if self.isempty():
            raise IndexError("Error")
        
        popped = self.top
        self.top = self.top.next
        self.size -= 1
        return popped.data
    
    def isempty(self):
        return self.size == 0
    
    def peek(self):
        return self.top.data
    
def preorder(root):
    result = []

    if root is None:
        return result
    
    stack = Stack()
    stack.push(root)

    while not stack.isempty():
        temp = stack.pop()
        result.append(temp.data)
        if temp.right:
            stack.push(temp.right)
        if temp.left:
            stack.push(temp.left)

    return result
            
if __name__ == '__main__':
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)

    preord = preorder(root)
    print(' '.join(map(str, preord)))