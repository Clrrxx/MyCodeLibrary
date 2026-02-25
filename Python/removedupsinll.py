class Node():
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class LinkedList():
    def __init__(self):
        self.head = None
        self.size = 0

    def findnode(self, index):
        if self.head is None:
            raise ValueError("Empty List")
        
        if index < 0 or index >= self.size:
            raise ValueError("invalid Index")
        
        curr = self.head
        while index > 0:
            curr = curr.next
            index -= 1
        return curr
    
    def insertnode(self, data, index):
        if index < 0 or index > self.size:
            raise ValueError("invalid Index")
        
        new_node = Node(data)

        if index == 0:
            new_node.next = self.head
            self.head = new_node
            self.size += 1
            return True

        prev_node = self.findnode(index - 1)
        if prev_node is not None:
            new_node.next = prev_node.next
            prev_node.next = new_node
            self.size += 1
            return True
        return False
    
    def removenode(self, index):
        if self.head is None:
            raise ValueError("Empty List")
        
        if index < 0 or index >= self.size:
            raise ValueError("invalid Index")
        
        if index == 0:
            self.head = self.head.next
            self.size -= 1
            return True
        
        prev = self.findnode(index - 1)
        if prev and prev.next:
            prev.next = prev.next.next
            self.size -= 1
            return True
        return False
    
    def removeAllitems(self):
        self.head = None
        self.size = 0

    def printList(self):
        cur = self.head
        if cur is None:
            print("Empty")
            return
        while cur is not None:
            print(cur.data, end=" -> ")
            cur = cur.next
        print("None")

def sortlinked(linked):
    if linked.head is None:
        return False
    
    value = []
    curr = linked.head
    while curr is not None:
        value.append(curr.data)
        curr = curr.next
    
    value.sort()

    curr = linked.head

    #put the sorted values back into the linked list

    for val in value:
        curr.data = val
        curr = curr.next

    return True


def removedups(linked):
    if linked.head is None:
        return False
    
    sortlinked(linked)

    count = {}
    curr = linked.head

    #for the first pass we are going to count all the occurences that happens in the linked list

    while curr is not None:

        #putting the data into a dictionary 
        count[curr.data] = count.get(curr.data, 0) + 1
        curr = curr.next
    
    #second pass remove the nodes

    curr = linked.head
    prev = None

    while curr is not None:
        if count[curr.data] > 1:

            #handling for the head
            if prev is None:
                linked.head = curr.next
                if linked.head:
                    linked.head.prev = None #if linked head exists, then the prev will be none, making it the head
            else:
                prev.next = curr.next
                if curr.next:
                    curr.next.prev = prev
            linked.size -= 1
            curr = curr.next
        else: 
            prev = curr
            curr = curr.next
    return True


if __name__ == "__main__":
    ll = LinkedList()

    while True:
        print("1: Insert an integer to the linked list:")
        print("2: Remove duplicates from a sorted linked list:")
        print("0: Quit:")
        choice = int(input("Please input your choice(1/2/0): "))

        if choice == 1:
            value = int(input("Input an integer that you want to add to the linked list: "))
            ll.insertnode(value, ll.size)  
            print("The resulting linked list is: ")
            ll.printList()  
        elif choice == 2:
            removedups(ll)
            print("The resulting linked list after removing duplicate values from the sorted linked list is: ")
            ll.printList()  
        elif choice == 0:
            ll.removeAllitems() 
            break
        else:
            print("Choice unknown;")






        
        






