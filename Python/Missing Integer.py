#original regular python

def array():
    user_input = input("Enter: ").strip("[]").split(",")
    nums = [int(x) for x in user_input]
    
    for i in range(len(nums)-1):
        if abs(nums[i+1]-nums[i]) != 1:
            if nums[i+1]-nums[i] > 0:
                return nums[i] + 1
            else:
                return nums[i] - 1
    
newnum = array()
print(newnum)



#object orientated programming

class Solution:

    #define objects
    def __init__(self, nums):
        self.nums = sorted(nums)
        self.min_val = min(nums)
        self.max_val = max(nums)
        self.length = len(nums)


    #define the method
    def find_missing(self) -> int:
        #expected length if no numbers are missing is max - min + 1 (7-3+1)
        expected_len = self.max_val - self.min_val + 1
        expected_sum = (expected_len * (self.max_val+self.min_val)) // 2

        actual_sum = sum(self.nums)
        
        return expected_sum - actual_sum
    
def main():
    user_input = input("Enter: ").strip("[]").split(",")
    nums = [int(x) for x in user_input]

    #creating an obj
    answer = Solution(nums)
    print(f"{answer.find_missing()}")

if __name__ == "__main__":
    main()
    