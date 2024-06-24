public class MyCoolCalculator extends BaseMegaCalculator {
    private double coef1;
    private double coef2;
    private double coef3;

    private static final double VAL1 = 12.0;
    private static final double VAL2 = 3.0;
    private static final double VAL3 = 0.05;

    public MyCoolCalculator(double coef1, double coef2, double coef3) {
        this.coef1 = coef1;
        this.coef2 = coef2;
        this.coef3 = coef3;
    }

    @Override
    public double getPrice() {
        return coef1 * VAL1 + coef2 * VAL2 - coef3 * VAL3;
    }

    @Override
    public double getMinimalValue() {
        return Math.min(coef1 * VAL1, coef2 * VAL2);
    }

    @Override
    public String getReport() {
        return "Some1 " + coef1 + ", another2 " + coef2 + ", and3 " + coef3 * VAL2;
    }
}
