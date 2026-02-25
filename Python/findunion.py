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
            print(cur.data, end=" -> ")
            cur = cur.next
        print("None")
def findUnion(head1, head2):
# Write your code here #

#naive approach:
    #use 2 while loops to iterate through each list to insert the unique values in both lists into a new list
    #then sort the list


    result = None
    tail = None
    curr1, curr2 = head1, head2

    #insert all the results for list 1 into result list
    while curr1 is not None:
        if not ispresent(result, curr1.data):
            newNode = Node(curr1.data)
            
            #for the fist element
            if result is None:
                result = newNode
                tail = newNode

            else:       #for every other element
                tail.next = newNode
                tail = newNode
        curr1 = curr1.next

    #compare if the value is not present in result    
    while curr2 is not None:
        if not ispresent(result, curr2.data):
            newNode = Node(curr2.data)
            if result is None:
                result = newNode
                tail = newNode
            else:
                tail.next = newNode
                tail = newNode
        curr2 = curr2.next
    
    result = sortlist(result)
    return result

#define function sortlist to sort the list in ascending order
def sortlist(head):
    if head is None or head.next is None:
        return None
    
    swapped = True
    while swapped:
        swapped = False
        curr = head
        while curr is not None:
            if curr.next is not None and curr.data > curr.next.data:
                curr.data, curr.next.data = curr.next.data, curr.data
                swapped = True
            curr = curr.next
    return head

#define additional function ispresent to iterate through the whole list and return true if element exists in the list
def ispresent(head, value):
    curr = head
    while curr is not None:
        if curr.data == value:
            return True
        curr = curr.next
    return False



def intersect(head1, head2):

    #using brute force find the elements that are present in both list
    result = None
    tail = None
    curr1, curr2 = head1, head2

    while curr1 is not None:
        #for each element in curr1, check if it is present in curr2 if it is -> insert into result (not present in result is to ensure no duplicates)
        if ispresent(curr2, curr1.data) and not ispresent(result, curr1.data):
            newNode = Node(curr1.data)
            if result is None:
                result = newNode
                tail = newNode
            else:
                tail.next = newNode
                tail = newNode
        
        result = sortlist(result)
        return result


if __name__ == "__main__":
    # Helper function to create a linked list from a string of space-separated numbers
    def create_linked_list_from_input(input_string):
        linked_list = LinkedList()
        numbers = []
        for item in input_string.split():
            try:
                numbers.append(int(item))
            except ValueError:
                continue
       
        for i, num in enumerate(numbers):
            linked_list.insertNode(num, i)
       
        return linked_list
   
    # Read input from file (or stdin if redirect is used)
    try:
        # Read first line for first linked list
        input_str1 = input()
        list1 = create_linked_list_from_input(input_str1)
       
        # Read second line for second linked list
        input_str2 = input()
        list2 = create_linked_list_from_input(input_str2)
       
        # Find the union
        result = findUnion(list1.head, list2.head)
       
        # Print the union list
        if result is None:
            print("No elements")
        else:
            temp = result
            while temp:
                print(temp.data, end=" ")
                temp = temp.next
            print()
   
    except EOFError:
        print("Error: Input file should contain at least two lines with the linked lists data.")