public class ShapeCylin extends Shapemain{
    public ShapeCylin(float thatradius, String thatName, float thatheight){
        super(thatradius, thatName, thatheight);
        this.ShapeType = KindofShape.SHAPE_CYLN;
    }
    public float calculateArea(){
        return 2 * (float)Math.PI *radius*radius + 2 * (float)Math.PI*radius*height;
    }
}
