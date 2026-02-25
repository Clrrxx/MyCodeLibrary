class Node():
    def __init__(self, data):
        self.next = None
        self.data = data

class LinkedList():
    def __init__(self):
        self.head = None
        self.size = 0
        self.tail = None

    def printll(self):
        temp = self.head
        while temp:
            print(temp.data, end="")
            temp = temp.next
        print()

    def insertNode(self, index, data):
        if index < 0 or index > self.size:
            raise IndexError("Invalid Index")
        
        new_node = Node(data)

        #inserting for the front
        if index == 0:
            new_node.next = self.head
            self.head = new_node
            if self.size == 0:
                self.tail = new_node

        #inserting at the end
        elif index == self.size:
            self.tail.next = new_node
            self.tail = new_node 

        #inserting whereever else
        else:
            prev = self.findnode(index - 1)
            new_node.next = prev.next
            prev.next = new_node
        self.size += 1
    
    def findnode(self, index):
        if index < 0 or index >= self.size:
            return None
        temp = self.head

        for _ in range(index):
            temp = temp.next

        return temp
    
    def removeNode(self, index):
        if index < 0 or index >= self.size:
            return -1
        
        #removing of the top
        if index == 0:
            self.head = self.head.next
            if self.size == 1:
                self.tail = None
        else:
            prev = self.findnode(index - 1)
            prev.next = prev.next.next
            if index == self.size - 1:
                self.tail = prev
        self.size -= 1
        return 0

class Stack():
    def __init__(self):
        self.ll = LinkedList()
    
    def push(self, data):
        return self.ll.insertNode(0, data)
    
    def pop(self):
        if self.is_empty():
            return None
        
        popped_node = self.ll.head.data
        self.ll.removeNode(0)
        return popped_node
    
    def is_empty(self):
        return self.ll.size == 0

def holding(stack, val):
    if stack.is_empty():
        stack.push(val)
        return
    
    #holds the first top val
    top = stack.pop()

    #recursively calls to reach the bottom
    holding(stack, val)

    #insert back into the stack
    stack.push(top)
        
def recursiveStack(stack):
    if stack.is_empty():
        return
    
    data = stack.pop()

    recursiveStack(stack)

    holding(stack, data)


if __name__ == "__main__":
    stack = Stack()
    for i in range(10):
        stack.push(i)
    
    print("Original Stack:")
    stack.ll.printll()
    recursiveStack(stack)
    print("Stack after recursive_reverse:")
    stack.ll.printll()
