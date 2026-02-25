class Solutions:
    def __init__(self, nums):
        self.nums = nums

    def findmostfreqodd(self):

        #declaring a new hash table (dictionary) for odd values
        odd_count = {}


        #we are going to insert each value of the array as the key and its value as the frequency that it occurs
        #therefore for every odd number if it occurs once, it will be added to the dictionary with its value as the key and its frequency as its data
        #when it dupicates again, the data will be updated with the same val
        for i in self.nums:
            if i % 2 != 0:
                odd_count[i] = odd_count.get(i, 0) + 1
        
        #if no odd return -1
        if not odd_count:
            return -1
        
        #now we are going to find the max of the frequencies, ie how many times it occurs and which is the highest
        max_freq = max(odd_count.values())


        #result will be the min of the numbers 
        result = min(num for num, count in odd_count.items() if count == max_freq)

        return result

def main ():
    user_input = input("Enter: ").strip("[]").split(",")
    nums = [int(x) for x in user_input]
    
            
    answer = Solutions(nums)
    

    print(f"{answer.findmostfreqodd()}")

if __name__ == "__main__":
    main()

