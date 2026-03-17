public class ShapeSquare extends Shapemain {
    public ShapeSquare(String thatName, int thatlength){
        super(thatName, thatlength);
        this.ShapeType = KindofShape.SHAPE_SQU;
    }
    public float calculateArea(){return length * length;}
}
