import java.util.Scanner;
import java.util.Random;

public class lab2{
    public static void main(String[] args){
        int choice;
        Scanner sc = new Scanner(System.in);
        do {
            System.out.println("Perform the following methods:" );
            System.out.println("1: multiplication test");
            System.out.println("2: quotient using division by subtraction");
            System.out.println("3: remainder using division by subtraction");
            System.out.println("4: count the number of digits");
            System.out.println("5: position of a digit");
            System.out.println("6: extract all odd digits");
            System.out.println("7: quit");
            choice = sc.nextInt();

            switch (choice) {
                case 1: mulTest();
                    break;

                case 2: 
                        System.out.printf("Enter m: ");
                        int m = sc.nextInt();

                        System.out.printf("Enter n: ");
                        int n = sc.nextInt();
                        int quo = divide(m, n);
                        System.out.printf("%d/%d=%d\n", m, n, quo);
                        
                    break;

                case 3: 
                        System.out.printf("Enter m: ");
                        int k = sc.nextInt();

                        System.out.printf("Enter n: ");
                        int l = sc.nextInt();
                        int modu = modulus(k, l);
                        System.out.printf("%d mod %d = %d\n", k, l, modu);
                        
                    break;

                case 4: System.out.printf("Enter the Number: ");
                        int num = sc.nextInt();
                        int fin = countDigit(num);

                        if (num < 0){
                            System.out.printf("n: %d - Error input!!\n", num);
                        } else {
                            System.out.printf("n: %d - count: %d\n", num, fin);
                        }
                    break;

                case 5: System.out.printf("Enter the number: ");
                        int total = sc.nextInt();

                        System.out.printf("Enter the digit to find: ");
                        int digit = sc.nextInt();
                        
                        int posi = position(total, digit);
                        System.out.printf("position = %d\n", posi);
                    break;

                case 6: System.out.printf("Enter the number: ");
                        long valnum = sc.nextInt();

                        long odd = extractOddDigits(valnum);
                        System.out.printf("oddDigit: %d\n", odd);

                    break;
                case 7: System.out.println("Program terminating");
                }
        } while (choice < 7);
        sc.close();
    }
/* add method code here */
    public static void mulTest(){
        Scanner myObj = new Scanner(System.in);

        int score = 0, r1, r2, ans;
        int max = 9;
        int min = 1;
        Random r = new Random();

        for (int i = 0; i<5; i++){
            r1 = r.nextInt(max - min + 1) + min;
            r2 = r.nextInt(max - min + 1) + min;
            System.out.printf("How much is %d times %d ", r1, r2);
            ans = myObj.nextInt();

            if (ans == r1 * r2){
                score++;
            }
        }
        System.out.printf("%d answers out of 5 are correct \n", score);
        myObj.close();
    }
    public static int divide(int m, int n){
        int quotient = 0;
        int newval = m;

        if (m == n){
            return 1;
        } else {
            while(newval > 0){
                newval = newval - n;
                quotient++;
            }
            return quotient-1;
        }
    }
    public static int modulus(int k, int l){
        if (k<l){
            return k;
        }else if (k==l){
            return 0;
        } else {
            while(k>l){
                k = k - l;}
            return k;
        }
    }
    public static int countDigit(int n){
        int count = 0;
        while (n>0){
            n /= 10;
            count ++;
        }
        return count;
    }
    public static int position(int n, int digit){
        int app = 1;
        while (n>0){
            int temp = modulus(n, 10);
            if (temp != digit){
                app++;
                n/=10;
            } else {
                return app;
            }
        }
        return -1;
    }
    public static long extractOddDigits(long n){
        int multi = 1;
        long newodd = 0;

        long numb = n;
        while (numb>0){
            long tempd = numb % 10;
            if (tempd % 2 == 1){
                newodd = newodd + (multi * tempd);
                multi *= 10;
            }
            numb/=10;
        }
        if (n>0){
            return newodd;
        } else{
            return -1;
        }
    }
}