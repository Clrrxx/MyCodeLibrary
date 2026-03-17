public class ShapeRect extends Shapemain {
    public ShapeRect(String thatName, float thatheight, float thatwidth){
        super(thatName, thatheight, thatwidth);
        this.ShapeType = KindofShape.SHAPE_RECT;
    }
    public float calculateArea(){return height*width;}
}
