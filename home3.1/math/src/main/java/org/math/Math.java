/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package org.math;

/**
 *
 * @author ubuntu
 */
public class Math {
    
    // Function to calculate the inverse value
    public static double calculateInverse(double x, double y, double z) {
        double product = x * y * z;
        double sum = x + y + z;
        
        if (product != 0) {
            return 1 / product; // Return inverse of product if it exists
        } else if (sum != 0) {
            return 1 / sum; // Return inverse of sum if product is not valid
        } else {
            return x + (y + 1) * (z - 1); // Return the default value if neither product nor sum is valid
        }
    }
}
