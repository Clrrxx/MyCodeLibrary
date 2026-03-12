
public class polygonmain {
    public enum KindofPolygon{POLY_PLAIN, POLY_RECT, POLY_TRI};
    protected String name;
    protected float width, height;
    protected KindofPolygon polytype;
    public polygonmain(String theName, float theHeight, float theWidth){
        name = theName;
        width = theWidth;
        height = theHeight;
        polytype = KindofPolygon.POLY_PLAIN;

    }
    public KindofPolygon getPolytype(){
        return polytype;
    }
    public void setpolytype(KindofPolygon value){
        polytype = value;
    }
    public String getName(){return name;}
    public float calArea(){return 0;}
    public void printWidthHeight(){
        System.out.println("Width = "+width+"Height = "+height);
    }
}
