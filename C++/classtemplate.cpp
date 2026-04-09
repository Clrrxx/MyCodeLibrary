#include <iostream>
using namespace std;

template <typename T>
class Array{
private:
    T* ptr;
    int size;
public:
    Array(T arr[], int s);
    ~Array();
    void print();
};

template <typename T>
Array <T>::Array(T arr[], int s){
    ptr = new T[s];
    size = s;
    for (int i = 0; i<size; i++)
    ptr[i] = arr[i];
}

template <typename T>
Array<T>::~Array(){delete[] ptr;}   //free allocated memory

template <typename T>               //defining member functions
void Array<T>::print(){
    for (int i = 0; i<size; i++)
    cout << " " <<*(ptr + i);
    cout <<endl;
}

int main(){
    int arr[5] = { 1, 2, 3, 4, 5 };
    Array<int> a(arr, 5);           //using class templates
    a.print();
    return 0;
}