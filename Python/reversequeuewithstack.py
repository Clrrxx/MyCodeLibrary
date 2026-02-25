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
        if self.is_empty():
            raise IndexError("Empty Stack")
        popped_node = self.top
        self.top = self.top.next
        self.size -= 1
        return popped_node.data
    
    def is_empty(self):
        return self.top is None
    
    def get_size(self):
        return self.size
    
class Queue():
    def __init__(self):
        self.front = None
        self.size = 0
        self.rear = None
    
    def isEmpty(self):
        return self.front is None
    
    def enqueue(self, data):
        new_node = Node(data)
        if self.isEmpty():
            self.front = new_node
        else:
            self.rear.next = new_node
        self.rear = new_node
        self.size += 1

    def dequeue(self):
        if self.isEmpty():
            raise IndexError("Empty Queue")
        
        dequeued = self.front
        self.front = self.front.next
        if self.front is None:
            self.rear = None        #if the dequeued node is the last node in the queue
        self.size -= 1
        return dequeued.data
    
    def getfront(self):
        if self.isEmpty():
            raise IndexError("Empty queue")
        return self.front.data
    
    def getsize(self):
        return self.size
    
    def printQueue(self):
        if self.isEmpty():
            print("Empty Queue")
            return
        current = self.front
        while current: 
            print(current.data, end="")
            current = current.next
        print()


def reversequeue(queue):
    new_stack = Stack()

    while not queue.isEmpty():
        new_stack.push(queue.dequeue())
    
    while not new_stack.is_empty():
        queue.enqueue(new_stack.pop())

    return queue

if __name__ == "__main__":
    queue = Queue()

    queue.enqueue(10)
    queue.enqueue(20)
    queue.enqueue(30)

    print("Original Queue:", end="")
    queue.printQueue()

    queue = reversequeue(queue)

    print("Reversed Queue:", end="")
    queue.printQueue()
