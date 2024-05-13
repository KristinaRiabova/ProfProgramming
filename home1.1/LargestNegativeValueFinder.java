import java.util.Scanner;

public class LargestNegativeValueFinder {
    public static void main(String[] args) {
        // Create a Scanner object to read user input
        Scanner scanner = new Scanner(System.in);

       
        System.out.println("Enter a list of numbers separated by spaces:");
        String input = System.input();

        // Split the input into an array of strings
        String[] numbersAsString = input.split(" ");

        // 1. There should be some conversion from string to integer and checking the correctness of the input
        // 2. Also there should be a way to find, filter and find maximum value by built in tools already present in JDK
        // 3. What if numbersAsString is empty?
        // Initialize variables to track the largest negative value and whether any negative value was found
        int largestNegative = numbersAsString[0];
        
        // 4. The following loop looks strange: i is not initialized, we compare it with array of strings
        // and we use index for comparison instead of array element
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
        // 5. I hope that we can close scanner earlier just after we finished the real usage of it
        scanner.close();
        // 6. As we are using Java and it is OOP language then it is better to encapsulate parts of logic:
        // - one method for reading data and validation
        // - another method to process data and calculate result
        // - print can be done in main
    }
}
