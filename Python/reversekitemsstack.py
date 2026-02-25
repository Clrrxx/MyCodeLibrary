class Node():
    def __init__(self, data):
        self.data = data
        self.next = None

class Stack():
    def __init__(self):
        self.size = 0
        self.top = None

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
    
def reversekitem(stack, index):
    if stack.top is None:
        return stack
    
    new_stack = Stack()
    aux_stack = Stack()

    #remove first k items
    while not stack.is_empty() and index > 0:
        new_stack.push(stack.pop())
        index -= 1
    
    #the undo the reversal into a different stack
    while not new_stack.is_empty():
        aux_stack.push(new_stack.pop())

    #return aux stack back to original => this will reverse the items taken out
    while not aux_stack.is_empty():
        stack.push(aux_stack.pop())
    
    return stack


if __name__ == "__main__":
    stack = Stack()

    while True:
        print("1: Insert an integer to the stack:")
        print("2: Reverse the elements of the queue until the given number")
        print("0: Quit:")
        choice = int(input("Please input your choice(1/2/0): "))

        if choice == 1:
            value = int(input("Input an integer that you want to insert into the stack: "))
            stack.push(value)  
            print(f"The resulting stack is: {stack}.")
             
        elif choice == 2:
            index = int(input("Enter an integer to reverse the queue until that number: "))
            reversekitem(stack, index)
            print(f"The resulting stack after reversing first {index} elements is: {stack}")
              
        elif choice == 0:
            stack.removeAllItems() 
            break
        else:
            print("Choice unknown;")