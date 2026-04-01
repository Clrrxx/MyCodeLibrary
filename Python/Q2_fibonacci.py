import time #to be used to measure execution time
import matplotlib.pyplot as plt # to be used to plot execution times


def recursive_fibonacci(n):
    if n <= 0:
        return 0
    if n == 1 or n == 2:
        return 1
    return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2)

def iterative_fibonacci(n):
    if n <= 0:
        return 0
    if n == 1 or n == 2:
        return 1
    a = 1
    b = 1
    for _ in range(3, n + 1):
        c = a+b
        b = a
        a = c
    return c


if __name__ == "__main__":
    values = [20, 30, 40]
    recur = []
    iter = []

    for val in values:
        start = time.time()
        recursive_fibonacci(val)
        recur.append(time.time()-start)

        start = time.time()
        iterative_fibonacci(val)
        iter.append(time.time()-start)
        #iterative happens way too fast 


        print(f"n = {val}: Recursive = {recur[-1]:.4f} | Iterative = {iter[-1]:.4f}")

    plt.plot(values, recur, label="Recursive O(2^n)", marker='o')
    plt.plot(values, iter, label="Iterative O(n)", marker='o')
    plt.xlabel("Input Size (n)")
    plt.ylabel("Execution Time (seconds)")
    plt.title("Recursion vs Iterative")
    plt.legend()
    plt.grid(True)
    plt.show()  