import org.testng.Assert;
import org.testng.annotations.Test;

public class MathTest {

    @Test
    public void testProductInverse() {
        double result = Math.calculateInverse(2, 3, -4);
        Assert.assertEquals(result, -0.08333333333333333, 0.0001);
    }

    @Test
    public void testSumInverse() {
        double result = Math.calculateInverse(0, 3, -4);
        Assert.assertEquals(result, 0.08333333333333333, 0.0001);
    }

    @Test
    public void testDefault() {
        double result = Math.calculateInverse(0, 0, 0);
        Assert.assertEquals(result, -5.0, 0.0001);
    }

    @Test
    public void testZeroProductAndSum() {
        double result = Math.calculateInverse(2, 0, 2);
        Assert.assertEquals(result, -4.0, 0.0001);
    }
}
