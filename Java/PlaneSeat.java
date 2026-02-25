public class PlaneSeat {
    private int seatID; private int customerID;
    private boolean assigned;

    public PlaneSeat(int seat_ID){
        seatID = seat_ID;
        assigned = false;
        customerID = 0;
    }

    public int getSeatID(){return seatID;}

    public int getCustomerID(){return customerID;}

    public boolean isOccupied(){return assigned;}

    public void assign(int cust_id){
        customerID = cust_id;
        assigned = true;
    }

    public void unAssign(){
        assigned = false;
        customerID = 0;
    }

}
