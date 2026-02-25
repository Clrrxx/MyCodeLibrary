public class disc extends round{
    private double thickness;
    public disc() {super(); thickness = 0;}
    public disc(double xCoor, double yCoor, double rad, double t){
        super(xCoor, yCoor, rad); thickness = t;
    }               //inheriting xcoor, ycoor and radius from the round class which inherits from the shapes class
    
    public double getThickness() {return thickness;}
    public double findArea() {return 2 * super.findArea() + 2 * Math.PI * getRadius() * thickness; }
                    //retrieve method from the super class
    public double findVol() {return super.findArea() * thickness;}
                    //retrieve method from the super class

    public void print(){
        System.out.println("Disc print() method: ");
        super.print();    //method overrriding the print in the round class and then refining it by calling it from the round method

        System.out.println( "Radius = " + getRadius());
        System.out.println( "Thickness = " + thickness);
        System.out.println( "Area = " + findArea());
        System.out.println(" Volume = " + findVol());

    }
    
}
