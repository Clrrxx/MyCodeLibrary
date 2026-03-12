

public class polygonzrect extends polygonmain{
    public polygonzrect(String theName, float theHeight, float theWidth) {
        super(theName, theHeight, theWidth);
        this.polytype = KindofPolygon.POLY_RECT;
    }
    public float calArea(){return height*width;}
    
}
