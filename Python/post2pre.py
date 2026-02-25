class Node():
    def __init__(self, data):
        self.data = data
        self.next = None

class Stack():
    def __init__(self):
        self.top = None
        self.size = 0

    def isEmpty(self):
        return self.size == 0
    
    def getsize(self):
        return self.size
    
    def peek(self):
        if self.size == 0 or self.top is None:
            raise IndexError("Empty stack")
        return self.top.data
    
    def push(self, data):
        new_node = Node(data)

        new_node.next = self.top
        self.top = new_node 
        self.size += 1
    
    def pop(self):
        if self.isEmpty():
            raise IndexError("Empty stack")
        popped = self.top
        self.top = self.top.next
        self.size -= 1
        return popped.data
    
PRESCEDENCE = {'=': 1, '&&': 2, '<<': 3, '>>': 3, '+': 4, '-': 4, '*': 5, '/': 5, '%': 5}

def hasHigherpres(op1, op2, prescedence = PRESCEDENCE):
    return prescedence.get(op1, 0) >= prescedence.get(op2, 0)

def pos2pre(expr):
    #reading from left to right

    stack = Stack()
    i = 0
    while i <len(expr):
        chr = expr[i]

        if chr.isspace():
            continue

        if chr.isalnum():
            stack.push(chr)
        
        elif chr in PRESCEDENCE:
            temp = ""
            temp += chr
            hold = stack.pop()
            temp += stack.pop()
            temp += hold

            #lmao what is tis scuffed ass method vro
            stack.push(temp)
        
        i+=1
    
    return stack

if __name__ == "__main__":
    infix = input("Enter infix expression: ")
    prefix = pos2pre(list(infix.split(' ')))
    
    # Print the prefix expression
    result = ""
    while not prefix.isEmpty():
        result += prefix.peek()
        prefix.pop()
    
    print(f"Prefix expression: {result}")

