import java.util.Scanner;

class bubble{
    static void bubbleS(int arr[], int n) {
        int i, j, temp;
        for (i = 0; i < n-1; i++){
            for (j = 0; j < n-i-1; j++){
                if (arr[j] > arr[j+1]){
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }
    static void printarr(int arr[], int size){
        int i;
        for (i = 0; i < size; i++){
            System.out.println(arr[i] + " ");
        System.out.println();
        }
    }
    public static void main(String args[]){
        System.out.println("Enter number of integer elements to be sorted: ");
        Scanner myObj = new Scanner(System.in);
        int n = myObj.nextInt();

        System.out.println("Enter number of integer value to be sorted: ");
        int [] arr = new int[n];

        for (int i = 0; i < n; i++ ){
            arr[i]  = myObj.nextInt();
        }

        bubbleS(arr, n);
        System.out.print("Final sorted array is: ");
        printarr(arr, n);

        myObj.close();
    }


    
}