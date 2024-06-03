public class Math {
    
    public static double calculateInverse(double x, double y, double z) {
        double product = x * y * z;
        double sum = x + y + z;
        
        // Check if the product is not zero to avoid division by zero
        if (product != 0) {
            return 1 / product; // Return inverse of the product
        } else if (sum != 0) {
            return 1 / sum; // Return inverse of the sum
        } else {
            return x + (y + 1) * (z - 1); // Return default value
        }
    }
    
    public static void main(String[] args) {
        // Example usage
        double result = calculateInverse(2.0, 3.0, 4.0);
        System.out.println("Result: " + result);
    }
}
