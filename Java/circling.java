public class circling extends point {
    private double radius;

    //jave automatically adds an invisible super() call at the beginning
    //therefore our super class needs to have a parameterless Point constructor -> Point(){ blah }

    public circling(){ radius = 1;}
    
    public circling(double radius){this.radius = radius;}

    public circling(double radius, int xint, int yint){
        super(xint, yint); this.radius = radius;
    }
    public double getradius(){return radius;}

    public void setradius(double radius){ this.radius = radius; }

    public double area(){return Math.PI*radius * radius; }

    public String toString(){return "Circle of raidus" + radius + "at point" + "["+ getX() + getY() +"]";}
}

