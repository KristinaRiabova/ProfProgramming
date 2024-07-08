public class Triangle {
    private double side1;
    private double side2;
    private double side3;

    public enum Side {
        A, B, C
    }

    public Triangle(double side1, double side2, double side3) {
        if (!isValidTriangle(side1, side2, side3)) {
            throw new IllegalArgumentException("The given sides do not form a valid triangle");
        }
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }

    private boolean isValidTriangle(double side1, double side2, double side3) {
        return (side1 + side2 > side3) && (side1 + side3 > side2) && (side2 + side3 > side1);
    }

    public double calculateArea() {
        double s = (side1 + side2 + side3) / 2.0;
        return Math.sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    public double getHeight(Side side) {
        double s = (side1 + side2 + side3) / 2.0;
        double area = calculateArea();
        double height;
        switch (side) {
            case A:
                height = (2.0 * area) / side1;
                break;
            case B:
                height = (2.0 * area) / side2;
                break;
            case C:
                height = (2.0 * area) / side3;
                break;
            default:
                throw new IllegalArgumentException("Invalid side: " + side);
        }
        return height;
    }

    // Getters for the sides if needed
    public double getSide1() {
        return side1;
    }

    public double getSide2() {
        return side2;
    }

    public double getSide3() {
        return side3;
    }
}