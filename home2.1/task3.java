import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Scanner;

public class task3 {

    // Constants for file name and commands
    private static final String HISTORY_FILE = "history.txt";
    private static final String CLEAR_HISTORY_COMMAND = "bread";
    private static final String RESET_STATISTICS_COMMAND = "delete";

    private static HashMap<String, Integer> userHistory;

    public static void main(String[] args) {
        UserHistory userHistoryManager = new UserHistory();
        userHistory = userHistoryManager.getUserHistory();

        if (args.length < 1) {
            System.out.println("Error: Please provide a name as argument.");
            System.exit(1);
        }

        String name = args[0];

        if (name.equals(CLEAR_HISTORY_COMMAND)) {
            userHistoryManager.clearHistory();
            userHistoryManager.saveHistory();
            System.exit(0);
        }

        if (args.length == 2 && args[1].equals(RESET_STATISTICS_COMMAND)) {
            userHistoryManager.resetStatistics(name);
            userHistoryManager.saveHistory();
            System.exit(0);
        }

        userHistoryManager.greetUser(name);
        userHistoryManager.saveHistory();
    }

    static class UserHistory {

        private HashMap<String, Integer> userHistory;

        public UserHistory() {
            userHistory = new HashMap<>();
            loadHistory();
        }

        // Function to load history from file
        private void loadHistory() {
            try {
                File file = new File(HISTORY_FILE);
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
        public void saveHistory() {
            try {
                PrintWriter writer = new PrintWriter(HISTORY_FILE);
                for (String name : userHistory.keySet()) {
                    writer.println(name + " " + userHistory.get(name));
                }
                writer.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        // Function to greet the user
        public void greetUser(String name) {
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
        public void resetStatistics(String name) {
            if (userHistory.containsKey(name)) {
                userHistory.remove(name);
                System.out.println("Statistics for " + name + " reset.");
            }
        }

        // Function to clear all history
        public void clearHistory() {
            userHistory.clear();
            System.out.println("All history cleared.");
        }

        // Getter for userHistory
        public HashMap<String, Integer> getUserHistory() {
            return userHistory;
        }
    }
}
