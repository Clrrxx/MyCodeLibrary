class Node():
    def __init__(self, data):
        self.data = data
        self.right = None
        self.left = None

class stNode():
    def __init__(self, data):
        self.data = data
        self.next = None

class Stack():
    def __init__(self):
        self.top = None
        self.size = 0

    def push(self, data):
        node = stNode(data)
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
    
def postorder(root):
    result = []
    if root is None:
        return result
    stack = Stack()

    #processing until root becomes null

    while root is not None or not stack.isempty():

        #go to the left most node and push into stack
        #node left becomes none, breaks out of the first loop
        while root is not None:
            if root.right is not None:
                stack.push(root.right)
            stack.push(root)
            root = root.left

        #top stack will be popped out, this is the new root in this case (2)
        root = stack.pop()

        #root right is none, skips if statement appends straight to result turn root to none
        if not stack.isempty() and root.right is not None and stack.peek() == root.right:
            stack.pop()
            stack.push(root)
            root = root.right
        else:
            result.append(root.data)
            root = None

    #above follows the first iteration, next iteration root is none = skips first and proceed to pop out the values in the stack
    #until we reach the final level (1) this is our original root 
    #since root left does not exist anymore, the code will push root to be (3) since at 3 the root left will be none, breaking the
    #inner loop 

    #root = 3 follow this first iteration pathway -> causes 4 to be appended
    #then root now becomes 5 -> appends 5 then 3 then finally 1


    return result



#using recursion:
def postorder(root):

    def post(root):
        result = []
        if root is None:
            return result
        
        #post order check left, right then data 
        post(root.left)
        post(root.right)
        result.append(root.data)
    
    post(root)

    return result







def printArray(arr):
    print(" ".join(map(str, arr)))

if __name__ == "__main__":
            
    root = Node(1)
    root.right = Node(2)
    root.right.left = Node(3)

    result = postorder(root)
    printArray(result)