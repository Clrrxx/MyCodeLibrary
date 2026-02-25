public class point {
    protected int xint;
    protected int yint;

    // constructor name must match
    public point(){
        xint = 0;
        yint = 0;
    }

    public point(int x, int y){
        this.xint = x;
        this.yint = y;
    }

    public void setPoint(int x, int y){
        this.xint = x;
        this.yint = y;
    }
    public int getX(){return xint; }

    public int getY(){return yint; }

    public String toString(){return "[" + xint + "," + yint + "]"; }
}
