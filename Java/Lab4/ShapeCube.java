public class ShapeCube extends Shapemain {
    public ShapeCube(String thatName, int thatlength){
        super(thatName, thatlength);
        this.ShapeType = KindofShape.SHAPE_CUB;
    }
    public float calculateArea(){return 6*length*length;}
}
