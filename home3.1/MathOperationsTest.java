import static org.junit.Assert.*;
import org.junit.Test;

public class MathOperationsTest {

    @Test
    public void testInverseOfProduct() {
        assertEquals(0.16666666666666666, Math.calculateInverse(2.0, 3.0, 4.0), 0.0001);
    }

    @Test
    public void testInverseOfSum() {
        assertEquals(0.1, Math.calculateInverse(0.1, 0.2, 0.3), 0.0001);
    }

    @Test
    public void testDefaultCalculation() {
        assertEquals(6.0, Math.calculateInverse(0.0, 0.0, 0.0), 0.0001);
    }

    @Test
    public void testZeroProduct() {
        assertEquals(0.1, Math.calculateInverse(0.0, 10.0, 0.0), 0.0001);
    }
}
