public class Triangle {
    private double sideA, sideB, sideC;

    public Triangle(double a, double b, double c) {
        sideA = a;
        sideB = b;
        sideC = c;
    }

    public double calculateArea() {
        double s = (sideA + sideB + sideC) / 2.0;
        return Math.sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
    }

    public double getHeight(char side) {
        double area = calculateArea();
        switch (side) {
            case 'a':
                return 2 * area / sideA;
            case 'b':
                return 2 * area / sideB;
            case 'c':
                return 2 * area / sideC;
            default:
                throw new IllegalArgumentException("Invalid side: " + side);
        }
    }
}
