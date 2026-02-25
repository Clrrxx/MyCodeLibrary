import java.util.Scanner;

class Circle{   
    private double radius;
    private static final double PI = 3.14159;

    public Circle(double rad){
        this.radius = rad;
    }
    public void setRadius(double rad){
        this.radius = rad;
    }
    public double getRadius(){
        return this.radius;
    }
    public double area(){
        return PI * radius * radius;
    }
    public double circumference(){
        return 2 * PI * radius;
    }
    public void printArea(){
        System.out.printf("Area: %.2f. \n", area());
    }
    public void printCircum(){
        System.out.printf("Circumference: %.2f. \n", circumference());
    }
}   


class Circletest{
    public static void main(String[] args){

        System.out.printf("==== Circle Computation ====\n");
        System.out.printf("|1. Create a new circle    |\n");
        System.out.printf("|2. Print Area             |\n");
        System.out.printf("|3. Print Circumference    |\n");
        System.out.printf("|4. Quit                   |\n");
        System.out.printf("============================\n");

        Circle circle1 = null;
        Scanner myObj = new Scanner(System.in);

        while (true){

            System.out.println("Choose option: ");
            
            int choice = myObj.nextInt();
                
            switch (choice) {
                case 1: System.out.println("Enter the radius to compute the area and circumference: ");
                        double radius = myObj.nextDouble();
                        circle1 = new Circle(radius);
                        
                        System.out.println("A new circle is created"); break;

                case 2: if (circle1 != null){
                            System.out.println("Area of circle");
                            circle1.printArea();
                        }
                        else{
                            System.out.printf("Please have a valid circle first.\n");
                        }
                        break;
                
                case 3: if (circle1 != null){
                            System.out.println("Circumference of circle");
                            circle1.printCircum();
                        }
                        else{
                            System.out.printf("Please have a valid circle first.\n");
                        }
                        break;
                        
                case 4: System.out.println("Thank You");
                        myObj.close();
                        return;
                
                default: System.out.println("Try again");
                        break;
            }
        }
    }
}