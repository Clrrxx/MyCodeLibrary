public class ShapeCir extends Shapemain {
    
    public ShapeCir(String thatName, float thatradius){
        super(thatName, thatradius);

        this.ShapeType = KindofShape.SHAPE_CIR;
    }
    public float calculateArea(){return (float)Math.PI * radius * radius;}
}
