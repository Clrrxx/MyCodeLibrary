class Node():
    def __init__(self, data):
        self.data = data
        self.next = None
        
    
class Stack():
    def __init__(self):
        self.top = None
        self.size = 0

    def peek(self):
        if self.is_empty():
            raise IndexError("Empty stack")
        return self.top.data
    
    def push(self, data):
        new_node = Node(data)
        new_node.next = self.top
        self.top = new_node
        self.size += 1

    def pop(self):
        if self.is_empty():
            raise IndexError("Empty stack")
        popped_node = self.top
        self.top = self.top.next
        self.size -= 1
        return popped_node.data
    
    def getSize(self):
        return self.size
    
    def is_empty(self):
        if self.top is None:
            return True
        return False
    
    def removeAllItems(self):
        self.top = None
        self.size = 0
    
    def __str__(self):
        if self.is_empty():
            return "[]"
        
        values = []
        current = self.top
        while current is not None:
            values.append(current.data)
            current = current.next
        return f"{values}"
    

def reverseStack(stack):
    # the idea here is to create a new stack, pop out everything from the old stack and push it into the new stack since stacks are first in, last out
    if stack.is_empty():
        return stack
    
    new_stack = Stack()

    while not stack.is_empty():
        new_stack.push(stack.pop())

    stack.top = new_stack.top
    stack.size = new_stack.size
    return stack




if __name__ == "__main__":
    stack = Stack()

    while True:
        print("1: Insert an integer to the stack:")
        print("2: Reverse Stack:")
        print("0: Quit:")
        choice = int(input("Please input your choice(1/2/0): "))

        if choice == 1:
            value = int(input("Input an integer that you want to insert into the stack: "))
            stack.push(value)  
            print(f"The resulting stack is: {stack}.")
             
        elif choice == 2:
            reverseStack(stack)
            print(f"The resulting stack is: {stack}.")
              
        elif choice == 0:
            stack.removeAllItems() 
            break
        else:
            print("Choice unknown;")
