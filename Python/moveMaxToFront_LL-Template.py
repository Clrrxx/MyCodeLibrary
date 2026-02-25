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

def moveMaxToFront(ll):
   # write your code here #
    if ll.head is None or ll.head.next is None:
        return
    
    tail = ll.head
    while tail.next:
        tail = tail.next
    original_tail = tail #remember where original tail is

    #declare that the first item is our largest so we have a baseline to compare with
    curr = ll.head
    prev = None
    maxVal = ll.head.item
    maxNode = ll.head
    maxprev = None

    #logic here is as we traverse the list, we are going to compare each value with the "maxVal". If it is larger, do nothing. If it is smaller we will redeclare maxVal as that val

    while curr is not None and curr != original_tail.next:
        if maxVal < curr.item:
            maxVal = curr.item
            maxNode = curr
            maxprev = prev
        prev = curr
        curr = curr.next

    #if max node is already at the front do nothing
    if maxNode == ll.head:
        return
    
    #now cut away max node
    maxprev.next = maxNode.next #this makes it so maxprev.next is None maxNode is not cut away from the LL

    #move maxnode to the front
    maxNode.next = ll.head #maxnode is now before the LL

    #"connect" maxNode to the front by redeclaring ll.head
    ll.head = maxNode

def maxtofront(ll):
    if ll.head is None or ll.head.next is None:
        return -1
    
    pre_max = None
    max_node = ll.head
    curr = ll.head

    while curr.next is not None:
        if curr.next.item > max_node.item:      #value of next node is bigger
            pre_max = curr              
            max_node = curr.next        #store current and max node
        curr = curr.next
    
    if pre_max is None:         #max node is already at the front
        return 0
    
    pre_max.next = max_node.next    #adjust pointer to move to the max node to the front
    max_node.next = ll.head
    ll.head = max_node

    return 0


if __name__ == "__main__":
    ll = LinkedList()

    while True:
        print("1: Insert an integer to the linked list:")
        print("2: Move the largest stored value to the front of the list:")
        print("0: Quit:")

        choice = int(input("Please input your choice (1/2/0): "))

        if choice == 1:
            value = int(input("Input an integer that you want to add to the linked list: "))
            ll.insertNode(value, ll.size)  
            print("The resulting linked list is:")
            ll.printList()  
        elif choice == 2:
            moveMaxToFront(ll)
            print("The resulting linked list after moving the largest stored value to the front of the list is:")
            ll.printList()  
        elif choice == 0:
            ll.removeAllItems()  
            break
        else:
            print("Choice unknown.")