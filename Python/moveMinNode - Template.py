class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
        self.size = 0
        
    def findNode(self, index):
        if index < 0 or index >= self.size:
            raise ValueError("Invalid position")
        if self.head is None:
            raise ValueError("List is empty")
            
        cur = self.head
        while index > 0:
            cur = cur.next
            index -= 1
        return cur
        
    def insertNode(self, data, index):
        if index < 0 or index > self.size:
            raise ValueError("Invalid position")
            
        new_node = Node(data)
        
        if index == 0:
            new_node.next = self.head
            self.head = new_node
            self.size += 1
            return True
        
        prev_node = self.findNode(index - 1)
        new_node.next = prev_node.next
        prev_node.next = new_node
        self.size += 1
        return True
    
    def printList(self):
        cur = self.head
        if cur is None:
            print("Empty")
            return
        while cur is not None:
            print(cur.data, end=" -> ")
            cur = cur.next
        print("None")

def moveMinNode(head):
# Write your code here #
    if head is None or head.next is None:
        return head
    
    curr = head
    absolutemin = head.data

    while curr is not None:
        if curr.data < absolutemin:
            absolutemin = curr.data
        curr = curr.next

    #initialising 2 new lists
    min_head = None
    min_tail = None

    rest_head = None
    rest_tail = None
    curr = head

    while curr is not None:
        #save the node
        next_node = curr.next
        curr.next = None    #disconnect current

        if curr.data == absolutemin:
            if min_head is None:    #first node of min
                min_head = min_tail = curr
            else:
                min_tail.next = curr
                min_tail = curr
        else:
            if rest_head is None:
                rest_head = rest_tail = curr
            else:
                rest_tail.next = curr
                rest_tail = curr
        
        curr = next_node
    
    if min_tail is not None:
        min_tail.next = rest_head
        return min_head
    
    return rest_head #if nothing happens 


if __name__ == "__main__":
    linked_list = LinkedList()
    
    print("Enter a list of numbers, terminated by any non-digit character: ", end="")
    input_string = input()
    numbers = input_string.split()
    
    counter = 0
    for num in numbers:
        try:
            linked_list.insertNode(int(num), counter)
            counter += 1
        except ValueError:
            break
    
    print("\nBefore:", end=" ")
    linked_list.printList()
    
    linked_list.head = moveMinNode(linked_list.head)
    print("After:", end=" ")
    linked_list.printList()