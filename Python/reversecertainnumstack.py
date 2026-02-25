class Node():
    def __init__(self, data):
        self.next = None
        self.data = data

class Stack():
    def __init__(self):
        self.top = None
        self.size = 0

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
        curr = self.top
        while curr is not None:
            values.append(curr.data)
            curr = curr.next
        return f"{values}"

def revcertainNum(stack, left, right):
    if stack.is_empty():
        return stack
    
    if right < left:
        raise IndexError("Invalid Index")
    
    totalIn = right - left + 1

    #we are going to pop out the first k items using the left index
    tempstack = Stack()
    while not stack.is_empty() and left > 0:
        tempstack.push(stack.pop())
        left -= 1
    
    #hold them temporarily in a temp stack leave it alone
    #now we are going to use 2 different new stacks to help achieve out goal
    new_stack = Stack()
    rev_stack = Stack()
    while not stack.is_empty() and totalIn > 0:
        new_stack.push(stack.pop())
        totalIn -= 1
    
    #we have now removed our targetted stack for reversal
    #we are going to now put the whole stack into another stack undoing the reversal

    while not new_stack.is_empty():
        rev_stack.push(new_stack.pop())
    
    #at this point rev_stack holds our selected stack that we want to reverse so we are
    #going to put rev stack back into original stack to reverse the order

    while not rev_stack.is_empty():
        stack.push(rev_stack.pop())

    #finish off by pushing the temp stack back into stack

    while not tempstack.is_empty():
        stack.push(tempstack.pop())
    
    return stack

if __name__ == "__main__":
    stack = Stack()

    while True:
        print("1: Insert an integer to the stack:")
        print("2: Reverse Stack:")
        print("0: Quit:")
        choice = int(input("Please input your choice(1/2/0): "))

        if choice == 1:
            value = int(input("Enter the value you want to push in: "))
            stack.push(value)
            print(f"The resulting stack is: {stack}.")
        
        elif choice == 2:
            leftIn = int(input("Enter the left index: "))
            rightIn = int(input("Enter the right index:"))

            revcertainNum(stack, leftIn, rightIn)
            print(f"The resultant stack is: {stack}")
        
        elif choice == 0:
            stack.removeAllItems()
            break
        else:
            print("Invalid Choice")
