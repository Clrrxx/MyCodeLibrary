class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Stack:
    def __init__(self):
        self.top = None
        self.size = 0

    def peek(self):
        if self.is_empty():
            raise IndexError("Peek from empty stack")
        return self.top.data
    
    def push(self, data):
        new_node = Node(data)
        new_node.next = self.top    #new node next points to the self top
        self.top = new_node         #stacks work like a jenga tower, can only stack ontop of each other, therefore a new node needs to be redeclared as the top everytime        
        self.size += 1

    def pop(self):
        if self.is_empty():
            raise IndexError("Pop from empty stack")
        popped_node = self.top      #mentioned above, can only pop from the top, however, as we pop we want to keep the data but the data will be auto deleted
        self.top = self.top.next    #so we put the popped data into a temp val first        #nove top to next node
        self.size -= 1
        return popped_node.data
    
    def is_empty(self):
        return self.top is None
    
    def get_size(self):
        return self.size
    
if __name__ == "__main__":
    s = Stack()

    #adding the data to the stacks
    s.push(10)
    s.push(20)
    s.push(30)

    print(f"Size is {s.get_size()}")

    print(f"Top element is: {s.peek()}")

    print(f"Popped: {s.pop()}")
    print(f"Popped: {s.pop()}")

    print(f"New size is {s.get_size()}")

    print(f"The new top element is {s.peek()}")

    print(f"Is stack empty? {s.is_empty()}")

    print(f"Popped: {s.pop()}")

    print(f"Is it empty now? {s.is_empty()}")




