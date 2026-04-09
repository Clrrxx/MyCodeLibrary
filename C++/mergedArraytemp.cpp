#include <iostream>
#include <string>
using namespace std;

template <typename T>
void mergeArrays(const T* arr1, int size1, const T* arr2, int size2, T*& arr3){
    arr3 = new T[size1+size2];
    int i = 0, j = 0, k = 0;

    while (i<size1){
        arr3[k++] = arr1[i++];
    }
    while (j<size2){
        arr3[k++] = arr2[j++];
    }
}

template <typename T>
void printAndDeallocate(T* arr3, int size){
    if (arr3 == nullptr) return;

    cout << "Merged Array: ";
    for (int i = 0; i<size; i++){
        cout << arr3[i] << " ";
    }
    cout <<endl;
    delete [] arr3;
}

int main() {
    double arr1[] = {1.1, 2.2, 3.3};
    double arr2[] = {4.4, 5.5};

    int size1 = 3, size2 = 2;

    double* mergedArray = nullptr;
    mergeArrays(arr1, size1, arr2, size2, mergedArray);
    printAndDeallocate(mergedArray, size1 + size2);
    
    cout << endl;

    int arr3[] = {1, 2, 3};
    int arr4[] = {4, 5};

    int* mergedArray2 = nullptr;
    mergeArrays(arr3, size1, arr4, size2, mergedArray2);
    printAndDeallocate(mergedArray2, size1 + size2);

    return 0;
}