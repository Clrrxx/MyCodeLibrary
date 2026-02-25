user_input = int(input("Enter: "))

string = "12345678901234567890123456789"

for i in range(1, user_input+1):
    print(i, end="")
    for j in range(i-1):
        print(f"{string[j+i]}", end="")
    print()

