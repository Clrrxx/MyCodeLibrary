def piglatin(strin):

    latin = " "
    vowels = ['a', 'e', 'i', 'o', 'u', 'y']

    if strin[0] not in vowels:
        temp = strin[0]
        latin = strin[1::] + temp + "ay"
    
    else:
        latin = strin + "ay"
    
    return latin

strin = str(input("Enter: "))
latin = piglatin(strin)
print(f"Original: {strin}")
print(f"Pig: {latin}")
