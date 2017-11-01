public class Rectangle {
    /*
     * Define two public attributes width and height of type int.
     */
    public int width;
    public int height;

    /*
     * Define a constructor which expects two parameters width and height here.
     */
    Rectangle(int a, int b) {
        width = a;
        height = b;
    }
    
    /*
     * Define a public method `getArea` which can calculate the area of the
     * rectangle and return.
     */
    public int getArea() {
        return width * height;
    }
}
