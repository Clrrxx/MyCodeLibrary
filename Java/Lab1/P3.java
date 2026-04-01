import java.util.Scanner;

class P3{
    public static void main(String[] args){
        Scanner myObj = new Scanner(System.in);
        
        System.out.print("Starting: ");
        int start = myObj.nextInt();

        System.out.print("Ending: ");
        int end = myObj.nextInt();

        System.out.print("Increment: ");
        int increment = myObj.nextInt();

        if (start <= end){
            System.out.println("--------Table 1--------");
            System.out.println("US$                SGD$");
            System.out.println("-----------------------");
            
            for (int i = start; i <= end; i += increment){
                int usd = i;
                double sgd = usd * 1.82d;
                System.out.printf("%d                   %.2f\n", usd, sgd);
            }
            
            System.out.println("--------Table 2--------");
            System.out.println("US$                SGD$");
            System.out.println("-----------------------");
            int j = start;
            while (j <= end){
                int usd1 = j;
                double sgd1 = usd1 * 1.82d;
                System.out.printf("%d                  %.2f\n", usd1, sgd1);
                j += increment;
            }
            
            System.out.println("--------Table 3--------");
            System.out.println("US$                SGD$");
            System.out.println("-----------------------");
        
            int k = start;
            if (increment>0 && start <= end){
                do{
                    int usd2 = k;
                    double sgd2 = usd2 * 1.82d;
                    System.out.printf("%d                  %.2f\n", usd2, sgd2);
                    k += increment;
                    }
                while(k <= end);
            }
        }
        else{
            System.out.println("Error!");
        }

    myObj.close();
        //start + increment
        //do until start <= end

    }
}
