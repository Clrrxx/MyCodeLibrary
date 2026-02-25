class Node():
    def __init__(self, data):
        self.data = data
        self.next = None

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
        popped = self.top
        self.top = self.top.next
        self.size -= 1

        return popped.data
    
    def isEmpty(self):
        return self.size == 0
    
    def getSize(self):
        return self.size
    
    def peek(self):
        if self.isEmpty():
            raise IndexError("Peek from empty stack")
        return self.top.data
    
PRESCEDENCE = {'=': 1, '&&': 2, '<<': 3, '>>': 3, '+': 4, '-': 4, '*': 5, '/': 5, '%': 5}

def hasHigherpres(op1, op2, prescedence = PRESCEDENCE):
    return prescedence.get(op1, 0) >= prescedence.get(op2, 0)

def pre2pos(expr):
    #reverse the string
    revstr = ""

    #handling reversed()

    for char in reversed(expr):
        if char == '(':
            revstr += ')'
        elif char == ')':
            revstr += '('
        else:
            revstr += char
    
    stack = Stack()
    
    i = 0

    while i < len(revstr):
        car = revstr[i]
        if car.isspace():
            continue

        if car.isalnum():
            stack.push(car)

        elif car in PRESCEDENCE:
            temp = ""
            index = 0
            while (index < 2):
                temp += stack.pop()
                index += 1
            temp += car
            stack.push(temp)
            
        i+=1
    
    return stack

if __name__ == "__main__":
    infix = input("Enter infix expression: ")
    prefix = pre2pos(list(infix.split(' ')))
    
    # Print the prefix expression
    result = ""
    while not prefix.isEmpty():
        result += prefix.peek()
        prefix.pop()
    
    print(f"Prefix expression: {result}")


        



     
    
