public class round extends shape {      //extends stretch to the superclass rounds will allow it to call upon the superclass's constructor using the super() keyword
    private double radius;

    public round(){
        super(); radius = 0;
    }
    public round(double xCoor, double yCoor, double rad){
        super(xCoor, yCoor); radius = rad;          
    }                                   //using the super() to get methods from the shape superclass

    public double getRadius()           {return radius;}
    public double findPerimeter()       {return 2*Math.PI*radius;}
    public double findArea()            {return Math.PI*radius*radius;}

    public void print(){
        System.out.println("Circle print() method: ");
        System.out.println("Center:                ");
        super.print();                  //print xpos and ypos by calling print from superclass

        System.out.println("Radius       =" + radius);
        System.out.println("Perimeter    =" + findPerimeter());
        System.out.println("Radius       =" + findArea());
    }








}
