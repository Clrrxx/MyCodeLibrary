#include <stdio.h>
void readIn(int *listprice, int *choice);
void computeFinal(int *listprice, int *choice, double *finalprice);
//coe is not taxed 
//car = 1600 >      => coe is 70000
//car = 1600 <      => coe is 80000
//goods vehi/bus    => coe is 23000
//motorcycle        => coe is 600
//luxury tax will only occur after the discount and if the actual listprice > 100,000


int main(){
    int listprice = 0, choice;
    double finalprice;

    readIn(&listprice, &choice);

    computeFinal(&listprice, &choice, &finalprice);
    printf("The Total price is $%.2lf", finalprice);
    
    return 0;
}

void readIn(int *listprice, int *choice){
    printf("Please enter the list price: \n");
    scanf("%d", listprice);

    printf("Please enter the category: \n");
    scanf("%d", choice);
}

void computeFinal(int *listprice, int *choice, double *finalprice){
    double discount = 0.1;
    double lux = 0.1;
    double gst = 0.03;
    double tempprice, aftergst;

    switch (*choice){
        // case 1 car that is 1600 >  => coe is 70000
        case 1: if (*listprice < 100000){
                    tempprice = *listprice - *listprice * discount;
                    aftergst = tempprice + tempprice * gst;
                    *finalprice = aftergst + 70000;
                }else{
                    tempprice = *listprice - *listprice * discount;
                    aftergst = tempprice + tempprice * gst + tempprice * lux;
                    *finalprice = aftergst + 70000;     
                    }
                break;

        case 2: if (*listprice < 100000){
                    tempprice = *listprice - *listprice * discount;
                    aftergst = tempprice + tempprice * gst;
                    *finalprice = aftergst + 80000;
                }else{
                    tempprice = *listprice - *listprice * discount;
                    aftergst = tempprice + tempprice * gst + tempprice * lux;
                    *finalprice = aftergst + 80000;     
                    }
                break;

        case 3: if (*listprice < 100000){
                    tempprice = *listprice - *listprice * discount;
                    aftergst = tempprice + tempprice * gst;
                    *finalprice = aftergst + 23000;
                }else{
                    tempprice = *listprice - *listprice * discount;
                    aftergst = tempprice + tempprice * gst + tempprice * lux;
                    *finalprice = aftergst + 23000;     
                    }
                break;

        case 4: if (*listprice < 100000){
                    tempprice = *listprice - *listprice * discount;
                    aftergst = tempprice + tempprice * gst;
                    *finalprice = aftergst + 600;
                }else{
                    tempprice = *listprice - *listprice * discount;
                    aftergst = tempprice + tempprice * gst + tempprice * lux;
                    *finalprice = aftergst + 600;     
                    }
                break;
                
        default: printf("Invalid");
        }
    }
