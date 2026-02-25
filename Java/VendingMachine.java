import java.util.Scanner;

public class VendingMachine{
    Scanner sc = new Scanner(System.in);
    public VendingMachine(){}

    public double selectDrink(){
        
        int choice;
        double drinkCost = 0;

        System.out.printf("====== Vending Machine ======\n");
        System.out.printf("|1. Buy Beer ($3.00)        |\n");
        System.out.printf("|2. Buy Coke ($1.00)        |\n");
        System.out.printf("|3. Buy Green Tea ($5.00)   |\n");
        System.out.printf("|============================\n");
        do{
            System.out.println("Please enter the selection: ");
            choice = sc.nextInt();
            sc.nextLine();
        } while (choice < 1 || choice > 3);
            if (choice == 1){
                drinkCost = 3.00;
            } else if (choice == 2){
                drinkCost = 1.00;
            } else if (choice == 3){
                drinkCost = 5.00;
            }
        return drinkCost;
    }
    public double insertCoins(double drinkCost){
        System.out.printf("Please insert coins: \n");
        System.out.printf("========== Coins Input ===========\n");
        System.out.printf("|Enter 'Q' for ten cents input   |\n");
        System.out.printf("|Enter 'T' for twenty cents input|\n");
        System.out.printf("|Enter 'F' for fifty cents input |\n");
        System.out.printf("|Enter 'N' for a dollar input    |\n");
        System.out.printf("==================================\n");
        char coinchoice;
        double amount = 0.0;

        do{
            coinchoice = sc.next().charAt(0);
            switch (coinchoice){
                case 'Q': 
                case 'q': amount += 0.10;
                    break;
                case 'T': 
                case 't': amount += 0.20;
                    break;
                case 'F': 
                case 'f': amount += 0.50;
                    break;
                case 'N': 
                case 'n': amount += 1.00;
                    break;
                }
                System.out.printf("Coins inserted: %.2f\n", amount);
                
            } while (amount < drinkCost);
        return amount;
    }
    public void checkChange(double amount, double drinkCost){
        double change = 0.0;
        if (amount > drinkCost){
            change = amount - drinkCost;
        }
        System.out.printf("Change: %.2f\n", change);
    }
    public void printReceipt(){
        System.out.println("Please collect your drink.");
        System.out.printf("\nThank You");
    }
}
