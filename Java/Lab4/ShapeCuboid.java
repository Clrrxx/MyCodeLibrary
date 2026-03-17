public class ShapeCuboid extends Shapemain {
    public ShapeCuboid(String thatName, float thatheight, float thatwidth, float thatdepth){
        super(thatName, thatheight, thatwidth, thatdepth);
        this.ShapeType = KindofShape.SHAPE_CUBO;
    }
    public float calculateArea(){
        return 2*(depth * width + width * height) + 2*(depth*height);
    }
}
