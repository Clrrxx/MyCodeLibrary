import java.util.Scanner;

public class PlaneApp {
    public static void main(String[] args) {
        int choice = 0;
        Plane plane = new Plane();
        
        System.out.println("(1) Show number of empty seats");
        System.out.println("(2) Show the list of empty seats");
        System.out.println("(3) Show the list of seat assignment by seat ID");
        System.out.println("(4) Show the list of seat assignment by customer ID");
        System.out.println("(5) Assign a customer to a seat");
        System.out.println("(6) Remove a Seat assignment");
        System.out.println("(7) Exit \n");
        
        Scanner myObj = new Scanner(System.in);

        while (choice != 7){
            System.out.print("Enter the number of your choice: ");
            choice = myObj.nextInt();

            switch(choice){
                case 1: plane.showEmpySeats();
                        break;
                
                case 2: plane.showEmpySeats();
                        break;

                case 3: plane.showAssignedSeats(true);
                        break;
                    
                case 4: plane.showAssignedSeats(false);
                        break;
                
                case 5: System.out.printf("Assigning Seat. .\n");
                        System.out.printf("Please enter SeatID: \n");
                        int seatID = myObj.nextInt();

                        System.out.printf("Please enter Customer ID: \n");
                        int custID = myObj.nextInt();
                        plane.assignSeats(seatID, custID);
                        break;

                case 6: System.out.println("Enter SeatID to unassign customer from: ");
                        int newseatID = myObj.nextInt();
                        plane.unAssignSeats(newseatID);
                        break;
                
                case 7: break;
            }
        }
        myObj.close();
    }
}
