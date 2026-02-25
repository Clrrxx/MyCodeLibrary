class Node():
    def __init__(self, data):
        self.data = data 
        self.next = None

class Stack():
    def __init__(self):
        self.top = None
        self.size = 0

    def pop(self):
        if self.isEmpty():
            raise IndexError("Empty Stack")
        popped = self.top
        self.top = self.top.next
        self.size -= 1
        return popped.data
    
    def push(self, data):
        newnode = Node(data)
        newnode.next = self.top
        self.top = newnode
        self.size += 1

    def peek(self):
        if self.isEmpty():
            raise IndexError("Empty stack")
        
        return self.top.data
    
    def isEmpty(self):
        return self.size == 0
    
PRESCEDENCE = {'=': 1, '&&': 2, '<<': 3, '>>': 3, '+': 4, '-': 4, '*': 5, '/': 5, '%': 5}

def ishigherpres(op1, op2, prescedence = PRESCEDENCE):
    return prescedence.get(op1, 0) >= prescedence.get(op2, 0)

#prescendence for postfix is to pop operators of equal or higher prescendence

def in2pos(expr):
    result = ""
    i = 0
    stack = Stack()

    while i < len(expr):
        char = expr[i]

        if char.isspace():
            i+=1
            continue
        
        elif char.isalnum():
            if char.isalpha():
                result += char
            else:
                num = ""
                while i < len(expr) and expr[i].isdigit():
                    num+=expr[i]
                    i += 1
                result += num
                i-=1 

        elif char == '(':
            stack.push(char)
        
        elif char == ')':
            while not stack.isEmpty() and stack.peek() != '(':
                result += stack.pop()
    
            while not stack.isEmpty() and stack.peek() == '(':
                stack.pop()
        
        elif char in PRESCEDENCE:
            while not stack.isEmpty() and char != ')' and ishigherpres(stack.peek(), char):
                result += stack.pop()
            stack.push(char)
        i+=1

    while not stack.isEmpty():
        if stack.peek() != '(':
            result += stack.pop()
        else:
            stack.pop()

    return result


if __name__ == "__main__":
    infix_exp = str(input("Enter an infix expression: "))
    try:
        postfix_exp = in2pos(infix_exp)
        print(f"Postfix expression: {postfix_exp}")
    except ValueError as e:
        print(f"Error: {e}")