public class discapp {
    public static void main(String[] args) {
        round round = new round(1, 5, 10);
        disc disc= new disc(10, 20, 5, 10);

        round.print();
        disc.print();

        System.out.println(" Volume = " + disc.findVol());
        System.out.println(" XPos = " + round.getXPos() + " YPos = " + round.getYPos());
        System.out.println(" XPos = " + disc.getXPos() + " YPos = " + disc.getYPos());
        //getXPos is implemented in the shape class which can be accessed from its subclasses since they inherit it
        //when getYPos gets summoned, it will first search through disc subclass first, if it cant find the method, it will go to it's superclass (round). if they still cant find it, 
        //this will repeat until we reach the shape class(root class/ super class) where xpos is defined. if we cannot find in this final superclass, the porgram will flag and error
    }
    
}
