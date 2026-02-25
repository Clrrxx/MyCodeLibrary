import java.util.Scanner;

class dice {
    private int valueofdice;
    
    public dice(int val){
        this.valueofdice = val;
    }

    public void setDice(){
        int min = 1;
        int max = 6;
        this.valueofdice = (int)(Math.random() * (max-min)+1) + min;
    }

    public int getDice(){
        return this.valueofdice;
    }

    public void prinfDiceValue(){
        System.out.printf("Current value is %d. \n", valueofdice);
    }
}

class dicetest{
    public static void main(String[] args) {

        int totaldice = 0;
        Scanner myObj = new Scanner(System.in);

        System.out.printf("Press <key> to roll the first dice\n");
        myObj.nextInt();
        dice dice1 = new dice(1);

        dice1.setDice();
        dice1.prinfDiceValue();
        totaldice += dice1.getDice();

        System.out.printf("Press <key> to roll the second dice\n");
        myObj.nextInt();
        dice dice2 = new dice(1);

        dice2.setDice();
        dice2.prinfDiceValue();
        totaldice += dice2.getDice();

        
        System.out.printf("Your total number is: %d", totaldice);
        myObj.close();
    }
}


