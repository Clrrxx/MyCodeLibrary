class Node():
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class LinkedList():
    def __init__(self):
        self.size = 0
        self.head = None
        self.tail = None

    def print_list(self):
        curr = self.head
        while curr:
            print(curr.data, end = " -> ")
            curr = curr.next
        print("None")

    def find_node(self, index):
        if index < 0 or index >= self.size:
            return None
        temp = self.head
        for i in range(index):
            temp = temp.next
        return temp
    
    def search_item(self, data):
        curr = self.head
        while curr:
            if curr.data == data:
                return True
            curr = curr.next
        return False
    
    def insert(self, data, index):
        if index < 0 or index > self.size:
            return None  #sanity check

        #create a new node
        new_node = Node(data)

        #if the node is at the start
        if index == 0:
            new_node.next = self.head
            if self.head:
                self.head.prev = new_node
            self.head = new_node

        #for everything else
        else:
            curr = self.head
            for i in range(index - 1):
                curr= curr.next              #traversing the list to find the index position

            #link the new node
            new_node.prev = curr             #new nodes prev will point to curr
            new_node.next = curr.next        #new node next will point to current's next
            if curr.next:
                curr.next.prev = new_node    #if curr.next exists, curr next's prev will point to new node
            curr.next = new_node             #update the curr next pointer to point at new node
        
        self.size += 1                  #increase size by 1

    def deletenode(self, data):    #using data
        if self.head is None:
            raise ValueError("Invalid")
        
        curr = self.head
        while curr:
            if curr.data == data:
                if curr.prev:
                    curr.prev.next = curr.next
                else:
                    self.head = curr.next
                
                if curr.next:
                    curr.next.prev = curr.prev
            
                self.size -= 1
                return True
            curr = curr.next
        return False


    def deletenodein(self, index):
        if index < 0 or index >= self.size:
            raise ValueError("Invalid")
        
        if self.head is None:
            return False
        
        if index == 0:
            self.head = self.head.next
            if self.head:
                self.head.prev = None
            self.size -= 1
            return True
        
        curr = self.head
        for i in range(index):
            curr = curr.next
        
        curr.prev.next = curr.next
        if curr.next:
            curr.next.prev = curr.prev
        self.size -= 1
        return True



#the benefit of combining both together is that teh stack operations become much easier and u get the benefits of both stacks and linked lists
#only bad is that it becomes really long


class Stack():
    def __init__(self):
        self.ll = LinkedList()
    
    def peek(self):
        if self.is_empty():
            raise IndexError("Peek from an empty stack")
        return self.ll.head.data
    
    def push(self, data):
        self.ll.insert(0, data)

    def pop(self):
        if self.is_empty():
            raise IndexError("Pop from empty stack")
        item = self.ll.head.data
        self.ll.deletenodein(0)
        return item

    def is_empty(self):
        return self.ll.size == 0

    def get_size(self):
        return self.ll.size             

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