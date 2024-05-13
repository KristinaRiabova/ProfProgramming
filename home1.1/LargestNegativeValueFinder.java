import java.util.Scanner;

public class LargestNegativeValueFinder {
    public static void main(String[] args) {
        // Create a Scanner object to read user input
        Scanner scanner = new Scanner(System.in);

        // Prompt the user to enter a list of numbers separated by spaces
        System.out.println("Enter a list of numbers separated by spaces:");


        String input = getUserInput(scanner);

        // Find and display the largest negative value
        findAndDisplayLargestNegative(input);


        scanner.close();
    }

    // Method to get user input
    public static String getUserInput(Scanner scanner) {
        // Read the input line
        String input = scanner.nextLine();

        // Check if the input is empty
        if (input.isEmpty()) {
            System.out.println("Input is empty");
            System.exit(0);
        }

        return input;
    }

    // Method to find and display the largest negative value
    public static void findAndDisplayLargestNegative(String input) {
        // Split the input into an array of strings
        String[] numbersAsString = input.split(" ");

        // Initialize variables
        int[] negativeNumsArray = new int[numbersAsString.length];
        int j = 0;

        // Populate the array with negative numbers
        for (int i = 0; i < numbersAsString.length; i++) {
            try {
                if (Integer.parseInt(numbersAsString[i]) < 0) {
                    negativeNumsArray[j] = Integer.parseInt(numbersAsString[i]);
                    j++;
                }
            } catch (NumberFormatException e) {
                System.out.println("Not a number, will be skipped: " + numbersAsString[i]);
            }
        }

        // Find the largest negative value
        int largestNegative = 0;
        if (negativeNumsArray[0] == 0) {
            System.out.println("No negative values found in the list. Program closed");
        } else {
            largestNegative = negativeNumsArray[0];
            for (int i = 0; i < negativeNumsArray.length; i++) {
                if (largestNegative < negativeNumsArray[i]) {
                    if (negativeNumsArray[i] == 0) break;
                    largestNegative = negativeNumsArray[i];
                }
            }

                System.out.println("The largest negative value is: " + largestNegative);
        }
    }
}
