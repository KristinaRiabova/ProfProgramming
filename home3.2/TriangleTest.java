import org.testng.annotations.Test;
import org.testng.Assert;

public class TriangleTest {

    @Test
    public void testAreaCalculation() {
        Triangle triangle1 = new Triangle(3, 4, 5);
        Assert.assertEquals(triangle1.calculateArea(), 6.0, 0.001);

        Triangle triangle2 = new Triangle(7, 8, 9);
        Assert.assertEquals(triangle2.calculateArea(), 26.83281573, 0.001);

        Triangle triangle3 = new Triangle(10, 10, 10);
        Assert.assertEquals(triangle3.calculateArea(), 43.3012701892, 0.001);
    }

    @Test
    public void testGetHeight() {
        Triangle triangle = new Triangle(3, 4, 5);
        Assert.assertEquals(triangle.getHeight('a'), 4.0, 0.001);
        Assert.assertEquals(triangle.getHeight('b'), 3.0, 0.001);
        Assert.assertEquals(triangle.getHeight('c'), 2.4, 0.001);
    }
}
