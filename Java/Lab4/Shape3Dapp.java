import java.util.Scanner;
public class Shape3Dapp {
    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);
        float sum = 0;

        System.out.println("Enter the total number of shapes: ");
        int num = myObj.nextInt();

        for (int i = 0; i<num; i++){
            System.out.println("Choose the shape: ");
            System.out.println("1. Sphere ");
            System.out.println("2. Cube ");
            System.out.println("3. Cylinder ");
            System.out.println("4. Cone ");
            int choice = myObj.nextInt();
            System.out.println();
            
            switch(choice){
                case 1: System.out.println("Enter the radius: ");
                        float radius = myObj.nextFloat();
                        Shapemain sphere = new ShapeSphere("Sphere", radius);
                        sum = sum + sphere.calculateArea();

                        System.out.println();
                        System.out.println("Sphere: " + sphere.calculateArea());
                        break;
                
                case 2: System.out.println("Enter the length: ");
                        int length = myObj.nextInt();
                        Shapemain cube = new ShapeCube("Cube", length);
                        sum += cube.calculateArea();

                        System.out.println();
                        System.out.println("Cube: " + cube.calculateArea());
                        break;
                
                case 3: System.out.println("Enter the height: ");
                        float height = myObj.nextFloat();
                        //System.out.println("Enter the width: ");
                        //float width = myObj.nextFloat();
                        System.out.println("Enter the radius: ");
                        radius = myObj.nextFloat();

                        //Shapemain cubeoid = new ShapeCuboid("Cuboid", height, width, breadth);
                        //float cuboidarea = cubeoid.calculateArea();
                        //sum += cuboidarea;

                        Shapemain cylinder = new ShapeCylin(radius, "Cylin", height);
                        sum += cylinder.calculateArea();

                        System.out.println();
                        System.out.println("Cylinder: "+cylinder.calculateArea());
                        //System.out.println("Cuboid: "+cuboidarea);
                        break;
                
                case 4: System.out.println("Enter the height: ");
                        height = myObj.nextFloat();
                        System.out.println("Enter the radius: ");
                        radius = myObj.nextFloat();
                        
                        /*System.out.println("Enter the breadth: ");
                        breadth = myObj.nextFloat();
                        System.out.println("Enter the depth: ");
                        float depth = myObj.nextFloat();
                        
                        Shapemain Pyramid = new ShapeTri("Pyramid", height, breadth, depth);
                        */
                        Shapemain cone = new ShapeCone(radius, "Cone", height); 

                        sum += cone.calculateArea();
                        System.out.println();
                        //System.out.println("Pyramid: "+Pyramid.calculateTriArea());
                        System.out.println("Cone: "+ cone.calculateArea());
                        break;
            }
        }
        System.out.println("Total Area: "+sum);
        myObj.close();
    }
}
