# Define operator precedence globally 
PRECEDENCE = {'+': 1, '-': 1, '*': 2, '/': 2, '**': 3}

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Stack:
    def __init__(self):
        self.top = None
        self.size = 0

    def isEmpty(self):
        return self.size == 0
    
    def get_size(self):
        return self.size

    def push(self, data):
        new_node = Node(data)
        new_node.next = self.top
        self.top = new_node
        self.size += 1

    def pop(self):
        if self.isEmpty():
            raise IndexError("Pop from empty stack")
        self.top = self.top.next
        self.size -= 1

    def peek(self):
        if self.isEmpty():
            raise IndexError("Peek from empty stack")
        return self.top.data

def in2preS(expr):
# Write your code here #
    #reverse the expression
    
    result = expr[::-1]
    
    revstr = []
    #handling closed brackets
    for char in result:
        if char == '(':
            revstr.append(')')
        elif char == ')':
            revstr.append('(')
        else:
            revstr.append(char)

    stack = Stack()

    nresult = []
    i = 0
    while i < len(revstr):
        newchar = revstr[i]

        if newchar.isspace():
            i += 1
            continue
    
        if newchar.isalnum():    
            nresult.append(newchar)

        elif newchar == '(':
            stack.push(newchar)
        
        elif newchar == ')':
            while not stack.isEmpty() and stack.peek() != '(':
                nresult.append(stack.peek())
                stack.pop()
            if not stack.isEmpty() and stack.peek() == '(':
                stack.pop()

        elif newchar in PRECEDENCE:
            while (not stack.isEmpty() and stack.peek() != '(' and hasHigherpres(stack.peek(), newchar)): 
                nresult.append(stack.peek())
                stack.pop()
                
            stack.push(newchar)
        
        i+= 1

    while not stack.isEmpty():
        if stack.peek() != '(':
            nresult.append(stack.peek())
            stack.pop()
        else: 
            stack.pop()

    finalstack = Stack()
    

    for char in nresult: 
        finalstack.push(char)
    
    return finalstack

def hasHigherpres(op1, op2, precedence = PRECEDENCE):

    #apparently the model answer is WRONG => presedence to pop out the value should ALWAYS be smaller
    #no 2 values of the same prescedence can exist in the stack at the same time
    return precedence.get(op1, 0) > precedence.get(op2, 0)

if __name__ == "__main__":
    infix = input("Enter infix expression: ")
    prefix = in2preS(list(infix.split(' ')))
    
    # Print the prefix expression
    result = ""
    while not prefix.isEmpty():
        result += prefix.peek()
        prefix.pop()
    
    print(f"Prefix expression: {result}")