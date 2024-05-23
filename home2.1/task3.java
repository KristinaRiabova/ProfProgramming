import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Scanner;
//In this code, Scanner is used to read data from a file.

public class task3 {

    // Global variable to track user interaction history
    private static HashMap<String, Integer> userHistory = new HashMap<>();

    // Function to load history from file
    private static void loadHistory() {
        try {
            File file = new File("history.txt");
            if (file.exists()) {
                Scanner scanner = new Scanner(file);
                while (scanner.hasNext()) {
                    String name = scanner.next();
                    int count = scanner.nextInt();
                    userHistory.put(name, count);
                }
                scanner.close();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // Function to save history to file
    private static void saveHistory() {
        try {
            PrintWriter writer = new PrintWriter("history.txt");
            for (String name : userHistory.keySet()) {
                writer.println(name + " " + userHistory.get(name));
            }
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // Function to greet the user
    private static void greetUser(String name) {
        if (!userHistory.containsKey(name)) {
            System.out.println("Welcome, " + name + "!");
            userHistory.put(name, 1);
        } else {
            int count = userHistory.get(name);
            System.out.println("Hello again(x" + count + "), " + name);
            userHistory.put(name, count + 1);
        }
    }

    // Function to reset statistics for a user
    private static void resetStatistics(String name) {
        if (userHistory.containsKey(name)) {
            userHistory.remove(name);
            System.out.println("Statistics for " + name + " reset.");
        }
    }

    // Function to clear all history
    private static void clearHistory() {
        userHistory.clear();
        System.out.println("All history cleared.");
    }

    public static void main(String[] args) {
        loadHistory();

        if (args.length < 1) {
            System.out.println("Error: Please provide a name as argument.");
            System.exit(1);
        }

        String name = args[0];

        if (name.equals("bread")) {
            clearHistory();
            saveHistory();
            System.exit(0);
        }

        if (args.length == 2 && args[1].equals("delete")) {
            resetStatistics(name);
            saveHistory();
            System.exit(0);
        }

        greetUser(name);
        saveHistory();
    }
}
