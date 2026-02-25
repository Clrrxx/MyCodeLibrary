class ListNode:
    def __init__(self, item):
        self.item = item
        self.next = None

class LinkedList:
    def __init__(self):
        self.size = 0
        self.head = None
    
    def findNode(self, index):
        if self.head is None:
            raise ValueError("List is empty")
        if index < 0 or index >= self.size:
            raise ValueError("Invalid position")
            
        cur = self.head
        while index > 0:
            cur = cur.next
            index -= 1
        return cur
  
    def insertNode(self, data, index):
        if index < 0 or index > self.size:
            raise ValueError("Invalid position")
            
        new_node = ListNode(data)
        
        if index == 0:
            new_node.next = self.head
            self.head = new_node
            self.size += 1
            return True
        
        prev_node = self.findNode(index - 1)
        if prev_node is not None:
            new_node.next = prev_node.next
            prev_node.next = new_node
            self.size += 1
            return True
        return False

    def removeNode(self, index):
        if index < 0 or index >= self.size:
            raise ValueError("Invalid position")
            
        if self.head is None:
            return False
            
        if index == 0:
            cur = self.head
            self.head = cur.next
            self.size -= 1
            return True
            
        pre = self.findNode(index - 1)
        if pre is not None and pre.next is not None:
            cur = pre.next
            pre.next = cur.next
            self.size -= 1
            return True
        return False

    def printList(self):
        cur = self.head
        if cur is None:
            print("Empty")
            return
        while cur is not None:
            print(cur.item, end=" -> ")
            cur = cur.next
        print("None")

    def removeAllItems(self):
        self.head = None
        self.size = 0



#edited code
def moveEvenItemsToBack(ll):
    #santiy check
    if ll.head is None or ll.head.next is None:
        return  #dont do anything
    
    #declare our tail this is the final end of the linked list
    #finding the original tail and then storing it so that there are no infinite loops
    tail = ll.head
    while tail.next:
        tail = tail.next
    original_tail = tail #remember where original tail is

    curr = ll.head 
    prev = None

    while curr is not None and curr != original_tail.next:
        if curr.item % 2 == 0:
            if prev is None: 
                ll.head = curr.next
            else:
                prev.next = curr.next
        
            tail.next = curr
            new_tail = curr
            curr = curr.next
            new_tail.next = None
            tail = new_tail
        else:
            prev = curr
            curr = curr.next
#end of code

def movetoback(ll):
    if ll.size < 2:
        return ll       #nothing to move
    
    cur = ll.head
    index = 0
    for _ in range(ll.size):
        if cur.item % 2 == 0:
            even_val = cur.item         #store even val in a temp
            cur = cur.next              #move the pointer
            ll.removeNode(index)        #remove and insert at the end of the linked list
            ll.insertNode(ll.size, even_val)
        else:
            cur = cur.next
            index += 1                  #if not even ignore and move the index up

if __name__ == "__main__":
    ll = LinkedList()

    while True:
        print("1: Insert an integer to the linked list:")
        print("2: Move all even integers to the back of the linked list:")
        print("0: Quit:")

        choice = int(input("Please input your choice (1/2/0): "))

        if choice == 1:
            value = int(input("Input an integer that you want to add to the linked list: "))
            ll.insertNode(value, ll.size)
            print("The resulting linked list is:")
            ll.printList()
        elif choice == 2:
            moveEvenItemsToBack(ll)
            print("The resulting linked list after moving even integers to the back is:")
            ll.printList()
        elif choice == 0:
            ll.removeAllItems()
            break
        else:
            print("Choice unknown;")