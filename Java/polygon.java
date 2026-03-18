public class polygon {
    public enum KindofPolygon{ POLY_PLAIN, POLY_RECT, POLY_TRI};
    protected String name;
    protected float width;
    protected float height;
    protected KindofPolygon polytype;

    public polygon(String theName, float theWidth, float theHeight){
        name = theName;
        width = theWidth;
        height = theHeight;
        polytype = KindofPolygon.POLY_PLAIN;
    }

    public KindofPolygon getpolytype(){
        return polytype;
    }

    public void setpolytype(KindofPolygon value){
        polytype = value;
    }

    public String getname(){return name;}
    public float calArea(){return 0;}
    public void printWidthHeight(){
        System.out.println("Width = "+width+". Height = "+ height);
    }
}
