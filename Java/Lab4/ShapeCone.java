public class ShapeCone extends Shapemain {
    public ShapeCone(float thatradius, String thatName, float thatheight){
        super(thatradius, thatName, thatheight);
        this.ShapeType = KindofShape.SHAPE_CONE;
    }
    public float calculateArea(){
        float sum = height * height + radius * radius;
        float slanted = (float)Math.sqrt(sum);
        return (float) (Math.PI * radius *radius + Math.PI *radius*slanted); 
    }
}
