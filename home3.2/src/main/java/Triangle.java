public class Triangle {
    private double side1;
    private double side2;
    private double side3;

    public Triangle(double side1, double side2, double side3) {
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }

    public double calculateArea() {
        double s = (side1 + side2 + side3) / 2.0;
        return Math.sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    public double getHeight(char side) {
        double s = (side1 + side2 + side3) / 2.0;
        double area = calculateArea();
        double height;
        switch (side) {
            case 'a':
                height = (2.0 * area) / side1;
                break;
            case 'b':
                height = (2.0 * area) / side2;
                break;
            case 'c':
                height = (2.0 * area) / side3;
                break;
            default:
                throw new IllegalArgumentException("Invalid side character: " + side);
        }
        return height;
    }
}
