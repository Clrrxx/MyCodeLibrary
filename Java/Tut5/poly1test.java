public class poly1test {
    /*public void printArea(polygonmain p){
        float area = p.calArea();
        System.out.println(p.getName()+"Area = "+area);
    }*/
    public void printArea(polygonzrect r){
        float area = r.calArea();
        System.out.println(r.getName()+"Area = "+area);
    }
    public void printArea(polygonztri t){
        float area = t.calArea();
        System.out.println(t.getName()+"Area = "+area);
    }
    
    
    
    public static void main(String[] args) {
        poly1test tp = new poly1test();
        //polygonmain tri = new polygonztri("Triangle", 4.0f, 3.0f);
        //polygonmain rect = new polygonzrect("Rectangle", 3.0f, 8.0f); base polymorphism

        //using static binding
        polygonzrect rect = new polygonzrect("Rectangle", 3.0f, 8.0f);
        polygonztri tri = new polygonztri("Triangle", 4.0f, 3.0f);
        tp.printArea(rect);
        tp.printArea(tri);
    }
}
