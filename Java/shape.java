public class shape{
    private double XPos;
    private double YPos;        //defining instance variables for the shape superclass

    public shape(){
        XPos = 0;
        YPos = 0;
    }
    public shape(double xCoor, double yCoor){
        XPos = xCoor;
        YPos = yCoor;   
    }                           //define constructors in the shape superclass

    public double getXPos() {return XPos;}      //defining the get methods in the shape superclass
    public double getYPos() {return YPos;}
    public void print(){
        System.out.println("[x, y] = [" + XPos + ", " + YPos + "]");
    }
}
