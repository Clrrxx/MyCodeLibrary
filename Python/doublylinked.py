class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class Linkedlist:
    def __init__(self):
        self.head = None
        self.size = 0
    
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
            raise ValueError("Invalid")  #sanity check

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


if __name__ == "__main__":
    ll = Linkedlist()
    ll.insert(10, 0)
    ll.insert(20, 1)
    ll.insert(30, 2)

    print("The list: ")
    ll.print_list()

    print(f"Size of the list is {ll.size}")
    ll.insert(25, 1)
    ll.print_list()

    print(f"Size of the new linked list {ll.size}")


            
        