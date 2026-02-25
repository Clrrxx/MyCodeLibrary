public class shapesapp {
    public static void main(String[] args) {
        round round = new round(5, 10, 5);
        System.out.print("Circle: ");
        System.out.println("Center Coords [x, y] = [" + round.getXPos() + ", " + round.getYPos() + "]");

        System.out.println("Radius = " + round.getRadius());
        System.out.println("Perimeter: " + round.findPerimeter());
        System.out.println("Area: " + round.findArea());
        round.print();
    }
}
