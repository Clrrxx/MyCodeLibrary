public class myfirst {
    public static void main(String[] args){
        class Base {
    int x = 5;
    int getX() { return x; }
}
class Derived extends Base {
    int x = 10;
    int getX() { return x; }
}
Base obj = new Derived();
System.out.println(obj.x + " " + obj.getX());}
}
