import org.junit.Test;
import static org.junit.Assert.assertEquals;

public class TriangleTest {

    @Test
    public void testAreaCalculation() {
        Triangle triangle1 = new Triangle(3, 4, 5);
        assertEquals(6.0, triangle1.calculateArea(), 0.001);

        Triangle triangle2 = new Triangle(7, 8, 9);
        assertEquals(26.83281573, triangle2.calculateArea(), 0.001);

        Triangle triangle3 = new Triangle(10, 10, 10);
        assertEquals(43.3012701892, triangle3.calculateArea(), 0.001);
    }

    @Test
    public void testGetHeight() {
        Triangle triangle = new Triangle(3, 4, 5);
        assertEquals(4.0, triangle.getHeight('a'), 0.001);
        assertEquals(3.0, triangle.getHeight('b'), 0.001);
        assertEquals(2.4, triangle.getHeight('c'), 0.001);
    }
}
