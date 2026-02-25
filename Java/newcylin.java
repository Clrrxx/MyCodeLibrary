public class newcylin extends circling{
    private double height;

    public newcylin(){super(); height = 5.0;}

    public newcylin(double h){super(); height = h;}

    public newcylin(double h, double radius, int xint, int yint){
        super(radius, xint, yint);
        height = h;
    }
    public double getheight() {return height; }

    public void setheight(double h){this.height = h;}

    public double area(){
        return 2 * Math.PI * super.getradius() * height + 2 * super.area();
    }
    
    public double volume(){
        return super.area() * height;
    }

    public String toString(){
        return "Cylinder of height" + height + "at" + "["+getX()+getY()+"]"; 
    }
}
