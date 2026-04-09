#include <iostream>
#include <vector>

using namespace std;

int main(){
    const int N = 5;
    vector <int> ivec(N);

    cout <<"Enter 5: ";
    for (int i = 0; i<N; i++){
        cin >> ivec[i];
    }

    cout << "Array contents: ";
    for (int i = 0; i<N; i++){
        cout << ivec[i];
    }
    cout <<endl;
    return 0;
}
