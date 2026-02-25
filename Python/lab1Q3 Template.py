class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def insert(self, data, index):
        new_node = Node(data)
        if self.head is None or index == 0:
            new_node.next = self.head
            self.head = new_node
            return True

        current = self.head
        count = 0

        while current and count < index - 1:
            current = current.next
            count += 1

        if not current:
            print("Index out of range")
            return False

        new_node.next = current.next
        current.next = new_node
        return True

    def printList(self):
        current = self.head
        while current:
            print(current.data, end=" ")
            current = current.next
        print()

    def deleteList(self):
        current = self.head
        while current:
            temp = current.next
            current.next = None
            current = temp
        self.head = None

def split(ll):
    #write your code here
    
    if ll.head is None or ll.head.next is None:
        return 
    
    #creating new Linked lists to prevent original list from being modified
    neweven = LinkedList()
    newodd = LinkedList()
    indexeven, indexodd = 0, 0
    
    #set the pointer at the head of the linked list
    #initialise the index at zero
    curr = ll.head
    index = 0


    #scuffed method of individually incrementing the indexs and making sure that the split functions correctly
    #this occurs as the pointer slowly traverses the linked list
    while curr is not None:
        if index % 2 == 0:

            #if index is even, insert the even index's value into a new linked list
            neweven.insert(curr.data, indexeven)
            indexeven += 1
            
        else:

            #if index is odd, insert the odd index's value into a new linked list
            newodd.insert(curr.data, indexodd)
            indexodd += 1
        
        curr = curr.next
        index += 1

    #return both the even and odd linked list
    return (neweven, newodd)



if __name__ == "__main__":
    linked_list = LinkedList()
    index = 0

    print("Enter one number per line (press Enter after each number).")
    print("Enter any non-digit character to finish input:")
    try:
        while True:
            item = int(input())
            if linked_list.insert(item, index):
                print(f"Successfully inserted {item} at index {index}")
                index += 1
            else:
                print(f"Failed to insert {item}")
    except ValueError:
        pass

    print("\nBefore split() is called:")
    print("Current list:", end=" ")
    linked_list.printList()

    even_list, odd_list = split(linked_list)

    print("\nAfter split() was called:")
    print("Current list:", end=" ")
    linked_list.printList()

    print("Even list:", end=" ")
    even_list.printList()

    print("Odd list:", end=" ")
    odd_list.printList()

    linked_list.deleteList()
    even_list.deleteList()
    odd_list.deleteList()