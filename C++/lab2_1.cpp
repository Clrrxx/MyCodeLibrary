#include <iostream>
using namespace std;
class Complex{
private:
    double real;
    double imag;

public:
    //constructor
    Complex(double r, double i): real(r), imag(i){}

    Complex operator+(const Complex& obj)const{
        return Complex(real + obj.real, imag + obj.imag);
    }

    //overload 
    Complex operator-(const Complex& obj)const{
        return Complex(real - obj.real, imag - obj.imag);
    }

    //Overloading with friend function
    friend std::ostream& operator<<(std::ostream& out, const Complex& c);
};
    std::ostream& operator<<(std::ostream& out, const Complex& c){
        if (c.imag <= 0){
            out<<c.real << " - " << -c.imag<<"i";
        }else{
            out<<c.real << " + " << c.imag<<"i";
        }
        return out;
    }

int main(){
    double d1, d2;

    cout<<"Enter first num: "<< endl;
    cin >> d1 >> d2;
    Complex c1(d1, d2);

    cout<<"Enter second num: "<<endl;
    cin >>d1 >> d2;
    Complex c2(d1, d2);

    Complex sum = c1+c2;
    Complex diff = c1 - c2;

    cout << "Sum: "<<sum <<endl;
    cout <<"Diff: "<<diff<<endl;

    return 0;
}