public abstract class Shapemain {
    public enum KindofShape{SHAPE_NORM, SHAPE_RECT, SHAPE_CIR, SHAPE_TRI, SHAPE_SQU, SHAPE_CUB, SHAPE_CUBO, SHAPE_PYR, SHAPE_SPH, SHAPE_CONE, SHAPE_CYLN};
    protected float height, width, radius, depth;
    protected int length;
    protected String ShapeName;
    protected KindofShape ShapeType;

    public Shapemain(String thatName, int thatlength){
        ShapeName = thatName;
        length = thatlength;
        ShapeType = KindofShape.SHAPE_NORM;
    }
    public Shapemain(String thatName, float thatradius){
        ShapeName = thatName;
        radius = thatradius;
        ShapeType = KindofShape.SHAPE_NORM;
    }
    public Shapemain(String thatName, float thatheight, float thatwidth){
        ShapeName = thatName;
        height = thatheight;
        width = thatwidth;
        ShapeType = KindofShape.SHAPE_NORM;
    }
    public Shapemain(float thatradius, String thatName, float thatheight){
        ShapeName = thatName;
        height = thatheight;
        radius = thatradius;
        ShapeType = KindofShape.SHAPE_NORM;
    }
    public Shapemain(String thatName, float thatheight, float thatwidth, float thatdepth){
        ShapeName = thatName;
        height = thatheight;
        width = thatwidth;
        depth = thatdepth;
        ShapeType = KindofShape.SHAPE_NORM;
    }

    public KindofShape getShapetype(){
        return ShapeType;
    }
    public String getname(){
        return ShapeName;
    }
    public void printWidthHeight(){
        System.out.println("Width = "+width+"Height = "+height);
    }

    public abstract float calculateArea();
    //abstract method to force each one to implement their own separate area
}
