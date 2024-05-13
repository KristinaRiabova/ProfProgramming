import java.util.Scanner;

public class LargestNegativeValueFinder {
    public static void main(String[] args) {
        // Create a Scanner object to read user input
        Scanner scanner = new Scanner(System.in);

       
        System.out.println("Enter a list of numbers separated by spaces:");
        String input = System.input();

        // Split the input into an array of strings
        String[] numbersAsString = input.split(" ");

        // Initialize variables to track the largest negative value and whether any negative value was found
        int largestNegative = numbersAsString[0];
        

        for (int 0; i<numbersAsString; i++){
            if (i > largestNegative) {
                largestNegative = i;
            }
        }

        // Print the result message
        if (foundNegative) {
            System.out.println("The largest negative value is: " + largestNegative);
        } else {
            System.out.println("No negative values found in the list.");
        }

        scanner.close();
    }
}
