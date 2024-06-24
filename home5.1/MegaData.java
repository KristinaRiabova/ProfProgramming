import java.util.Arrays;

public class MegaData {
    private float[] smallArray = new float[1024];
    private double[] bigArray = new double[1024 * 1024];

    public MegaData() {
        reset();
    }

    public void reset() {
        Arrays.fill(smallArray, 42.0f);
        Arrays.fill(bigArray, 42.0);
    }

    public float[] getSmallArray() {
        return smallArray;
    }

    public double[] getBigArray() {
        return bigArray;
    }
}
