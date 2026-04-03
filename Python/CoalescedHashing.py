TABLESIZE = 37
PRIME = 13
EMPTY = 0
USED = 1

class HashSlot:
    def __init__(self):
        self.key = 0
        self.indicator = EMPTY
        self.next = -1

def hash_func(key):
    return key % TABLESIZE

def hash_insert(key, hash_table):
#write your codes here
    index = hash_func(key)

    #case 1: Slot is empty so insert directly
    if hash_table[index].indicator == EMPTY:
        hash_table[index].key = key
        hash_table[index].indicator = USED
        return index
    

    #case 2: slot is occupied, walk the chain to the tail
    current = index
    while hash_table[current].next != -1:
        if hash_table[current].key == key:
            return -2
        current = hash_table[current].next
    
    if hash_table[current].key == key:
        return -2 #duplicate at the tail

    #find an emptyoverflow slot by linear scan
    overflow = (index + 1) % TABLESIZE
    while overflow != index:
        if hash_table[overflow].indicator == EMPTY:
            hash_table[overflow].key = key
            hash_table[overflow].indicator = USED
            hash_table[current].next = overflow #link the tail to a new slot
            return overflow
        overflow = (overflow + 1) % TABLESIZE
    
    
    return 38 #table is full



def hash_find(key, hash_table):
#write your codes here
    index = hash_func(key)
    current = index

    while current != -1:
        if hash_table[current].indicator == USED and hash_table[current].key == key:
            return current
        current = hash_table[current].next
    return -1

def print_menu():
    print("============= Hash Table ============")
    print("|1. Insert a key to the hash table  |")
    print("|2. Search a key in the hash table  |")
    print("|3. Print the hash table            |")
    print("|4. Quit                            |")
    print("=====================================")
    print("Enter selection: ", end="")


def main():
    import sys
    input = sys.stdin.read
    data = list(map(int, input().split()))

    hash_table = [HashSlot() for _ in range(TABLESIZE)]
    for slot in hash_table:
        slot.key = 0
        slot.indicator = EMPTY
        slot.next = -1

    i = 0
    print_menu()
    while i < len(data):

        opt = data[i]
        i += 1

        if opt == 1:  # Insert
            print("Enter a key to be inserted:")
            if i >= len(data):
                break
            key = data[i]
            i += 1
            index = hash_insert(key, hash_table)
            if index < 0:
                print("Duplicate key")
            elif index < TABLESIZE:
                print(f"Insert {key} at index {index}")
            else:
                print("Table is full.")
            print("Enter selection: ", end="")
        elif opt == 2:  # Search
            print("Enter a key for searching in the HashTable:")
            if i >= len(data):
                break
            key = data[i]
            i += 1
            index = hash_find(key, hash_table)
            if index != -1:
                print(f"{key} is found at index {index}.")
            else:
                print(f"{key} is not found.")
            print("Enter selection: ", end="")
        elif opt == 3:  # Print table
            print("index:\t key \t next")
            for j in range(TABLESIZE):
                print(f"{j}\t{hash_table[j].key}\t{hash_table[j].next}")
            print("Enter selection: ", end="")
        elif opt == 4:
            break
        else:
            print("Enter selection: ", end="")
            continue


if __name__ == "__main__":
    main()