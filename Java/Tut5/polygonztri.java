

public class polygonztri extends polygonmain {
    public polygonztri(String theName, float theHeight, float theWidth){
        super(theName, theHeight, theWidth);
        this.polytype = KindofPolygon.POLY_TRI;
    }
    public float calArea(){return 0.5f*height*width;}
}
