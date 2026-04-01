public class Plane{
    private PlaneSeat[] seat;
    private int numEmptySeat;

    public Plane(){
        seat = new PlaneSeat[12];   //creates the array with 12 seats
        numEmptySeat = 12;

        for (int i=0; i<12; i++){
            seat[i] = new PlaneSeat(i+1); //each seat[i] is initialised as a planeseat obj
        }
    }
    private PlaneSeat[] sortSeats(){
        //make a copy
        PlaneSeat[] copy = new PlaneSeat[12];

        for (int i = 0; i<12; i++){
            copy[i] = seat[i];
        }
        
        //bubble sort 
        for (int i = 0; i<12; i++){
            for (int j = 0; j<11-i; j++){
                if (copy[j].getCustomerID() > copy[j+1].getCustomerID()){
                    PlaneSeat temp = copy[j];
                    copy[j] = copy[j+1];
                    copy[j+1] = temp;
                }
            }
        }
        return copy;
    }

    public void showNumEmptySeats(){
        System.out.println("Number of Empty Seats: " + numEmptySeat);
    }

    public void showEmpySeats(){
        System.out.printf("The following seats are emopty: \n");
        for (int i = 0; i<12; i++){
            // if seat is empty then print out the seat num
            if (!seat[i].isOccupied()){
                System.out.println("SeatID "+ seat[i].getSeatID());
            }
        }
    }

    public void assignSeats(int seatID, int cust_id){
        for (int i = 0; i<12; i++){
            if (seat[i].getSeatID() == seatID){
                if (seat[i].isOccupied()){
                    System.out.println("Seat already assigned.\n");
                } else {
                    seat[i].assign(cust_id);
                    numEmptySeat --;
                    System.out.println("Seat Assigned.\n");
                }
                break;
            }
        }
    }

    public void unAssignSeats(int seatID){
        for (int i = 0; i<12; i++){
            if (seat[i].getSeatID() == seatID){
                if (!seat[i].isOccupied()){
                    System.out.println("Empty Seat.\n");
                } else {
                    seat[i].unAssign();
                    numEmptySeat ++;
                    System.out.println("Seat Unassigned.\n");
                }
                break;
            }
        }
    }

    public void showAssignedSeats(boolean bySeatID){
        PlaneSeat[] display;
        //new PlaneSeat array


        if (bySeatID){
            display = seat;}
            //use original array
        else{
            display = sortSeats();}
            //use copied array 

        System.out.println("The seat assignments are as follows: \n");

        for (int i = 0; i<12; i++){
            if (display[i].isOccupied()){
                System.out.printf("SeatID %d assigned to Customer ID %d\n", display[i].getSeatID(), display[i].getCustomerID());    
            }
        }
    }
}
