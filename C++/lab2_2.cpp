#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Product{
private:
    string name;
    double price;

public:
    //Constructor
    Product(string productname, double productprice){
        this->name = productname;
        this->price = productprice;
    }

    //destructor
    ~Product(){}

    //getters
    string getName(){return name;}
    int getPrice(){return price;}

    //setters
    void setPrice(double newPrice){
        if (newPrice>0){
            this->price = newPrice;
        }else{
            cout<<"ERRROR!";
        }
    }
};

int main(){
    vector<Product> products;

    cout<< "1) Create new product" <<endl;
    cout<< "2) Print product" <<endl;
    cout<< "3) Update Price" <<endl;
    cout<< "4) Exit" <<endl;

    int cmd;
    do{
        cout<<"Enter command: "<<endl;
        cin>>cmd;
        switch(cmd){
            case 1:{
                cout << "Enter product name and price: "<<endl;
                string name;
                double price;
                cin >> name >> price;
                products.emplace_back(Product(name, price));
                cout << "Product created: "<< name << " ($" <<price << ")" <<endl;
            }break;
            case 2:{
                cout << "Enter product id: " << endl;
                size_t index;
                cin >> index;
                if (index >= products.size()){
                    cout << " selected index "<< index << " is out of bounds" <<endl;
                    break;
                }
                cout << "The name of Product " << index <<": " << products[index].getName() <<endl;
                cout <<"The price of Product " << index <<": " << products[index].getPrice() <<endl;
            }break;
            case 3:{
                cout <<"Enter product id and new price: " <<endl;
                size_t index;
                double price;
                cin >> index >> price;
                if (index >= products.size()){
                    cout << "selected index " << index << " is out of bounds" << endl;
                    break;
                }

                products[index].setPrice(price);
            }break;
            case 4:break;
            default:
                cout<<"Unknown cmd" << cmd <<endl;
        }
    }while (cmd!= 4);
    return 0;
}