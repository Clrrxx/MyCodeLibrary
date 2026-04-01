import time #to be used to measure execution time
import random # to be used to generate random numbers
import matplotlib.pyplot as plt # to be used to plot execution times
import copy

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        swapped = False
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:
            break


def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left_half = arr[:mid]
        right_half = arr[mid:]

        merge_sort(left_half)
        merge_sort(right_half)

        i = j = k = 0
        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1

        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1

        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1

if __name__ == "__main__":
    sizes = [100, 1000, 10000]
    bubble = []
    merge = []

    for size in sizes:
        arr = random.sample(range(size*10), size)

        arr_bubble = copy.copy(arr)
        start = time.time()
        bubble_sort(arr_bubble)
        bubble.append(time.time()-start)

        arr_merge = copy.copy(arr)
        start = time.time()
        merge_sort(arr_merge)
        merge.append(time.time()-start)

        print(f"n = {size}: Bubble = {bubble[-1]:.4f} | Merge = {merge[-1]:.4f}")

    plt.plot(sizes, bubble, label="Bubble Sort O(n²)", marker='o')
    plt.plot(sizes, merge, label="Merge Sort O(n log n)", marker='o')
    plt.xlabel("Input Size (n)")
    plt.ylabel("Execution Time (seconds)")
    plt.title("Bubble Sort vs Merge Sort")
    plt.legend()
    plt.grid(True)
    plt.show()  
