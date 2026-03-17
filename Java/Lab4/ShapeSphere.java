public class ShapeSphere extends Shapemain {
    public ShapeSphere(String thatName, float thatradius){
        super(thatName, thatradius);

        this.ShapeType = KindofShape.SHAPE_SPH;
    }
    public float calculateArea(){
        return 4* (float)Math.PI * radius * radius;}
}
