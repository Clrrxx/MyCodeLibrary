public class newclinapp {
    public static void main(String[] args) {
        circling circle = new circling(4, 5, 5);
        System.out.print( "Circle: ");
        System.out.println("Center Coords [x, y] = ["+ circle.getX() + "," + circle.getY()+"]");

        System.out.println("Radius = "+ circle.getradius());
        System.out.println("Area = "+ circle.area());
        circle.toString();

        newcylin cylin = new newcylin(5, 4, 5, 5);
        System.out.println("Cylinder: ");
        System.out.println("Center Coords [x, y] = ["+ cylin.getX() + "," + cylin.getY()+"]");

        System.out.println("Radius = "+ cylin.getradius());
        System.out.println("Height: "+ cylin.getheight());
        System.out.println("Area = "+ cylin.area());
        System.out.println("Volume = "+ cylin.volume());
        cylin.toString();
    }
}
