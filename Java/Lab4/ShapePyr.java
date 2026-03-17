public class ShapePyr extends Shapemain {
    public ShapePyr(String thatName, float thatheight, float thatwidth, float thatdepth){
        super(thatName, thatheight, thatwidth, thatdepth);
        this.ShapeType = KindofShape.SHAPE_PYR;
    }
    public float calculateArea(){
        float sum = (0.5f*depth) * (0.5f*depth) + height * height;
        
        float slanted = (float)Math.sqrt(sum);
        
        float sqbase = depth * width;

        float face1 = 0.5f*depth * slanted;
        float face2 = 0.5f*width * slanted;

        return 2 * face1 + 2 * face2 + sqbase;
    }
}
