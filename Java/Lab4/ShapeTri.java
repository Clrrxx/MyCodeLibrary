public class ShapeTri extends Shapemain {
    public ShapeTri(String thatName, float thatheight, float thatwidth){
        super(thatName, thatheight, thatwidth);
        this.ShapeType = KindofShape.SHAPE_TRI;
    }
    public float calculateArea(){return 0.5f * height * width;}
}

