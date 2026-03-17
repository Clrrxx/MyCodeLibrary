import java.util.Scanner;
public class Shape2Dapp {
    public void printShapeArea(Shapemain S){
        float area = S.calculateArea();
        System.out.println(S.getname() + "Area: " + area);
    }

    public static void main(String[] args) {
        Shape2Dapp sp = new Shape2Dapp();
        Scanner myObj = new Scanner(System.in);
        float sum = 0;

        System.out.println("Enter the total number of shapes: ");
        int num = myObj.nextInt();

        for (int i = 0; i<num; i++){
            System.out.println("Choose the shape: ");
            System.out.println("1. Circle ");
            System.out.println("2. Square ");
            System.out.println("3. Rectangle ");
            System.out.println("4. Triangle ");
            int choice = myObj.nextInt();
            System.out.println();

            switch(choice){
                case 1: System.out.println("Enter the radius: ");
                        float radius = myObj.nextFloat();
                        Shapemain circle = new ShapeCir("Circle", radius);
                        sum = sum + circle.calculateArea();
                        System.out.println();
                        sp.printShapeArea(circle);
                        break;
                
                case 2: System.out.println("Enter the length: ");
                        int length = myObj.nextInt();
                        Shapemain Square = new ShapeSquare("Square", length);
                        sum = sum + Square.calculateArea();
                        System.out.println();
                        sp.printShapeArea(Square);
                        break;
                
                case 3: System.out.println("Enter the height: ");
                        float height = myObj.nextFloat();
                        System.out.println("Enter the width: ");
                        float width = myObj.nextFloat();

                        Shapemain rect = new ShapeRect("rectangle", height, width);
                        sum = sum + rect.calculateArea();
                        System.out.println();
                        sp.printShapeArea(rect);
                        break;
                
                case 4: System.out.println("Enter the height: ");
                        float tall = myObj.nextFloat();
                        System.out.println("Enter the breadth: ");
                        float breadth = myObj.nextFloat();

                        Shapemain tri = new ShapeTri("Triangle", tall, breadth);
                        sum = sum+tri.calculateArea();
                        System.out.println();
                        sp.printShapeArea(tri);
                        break;
            }
        }
        System.out.println("Total Area: "+sum);
        myObj.close();
    }
}
