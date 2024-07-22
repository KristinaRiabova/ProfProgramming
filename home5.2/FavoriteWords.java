import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

class Configuration {
    private static Configuration instance;
    private final Map<Character, String[]> configMap = new HashMap<>();

    private Configuration() {
        loadConfiguration();
    }

    public static synchronized Configuration getInstance() {
        if (instance == null) {
            instance = new Configuration();
        }
        return instance;
    }

    private void loadConfiguration() {
        try (BufferedReader reader = new BufferedReader(new FileReader("config.txt"))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(" ");
                char rangeStart = parts[0].charAt(0);
                char rangeEnd = parts[0].charAt(2);
                String preWord = parts[1];
                String postWord = parts[2];
                for (char ch = rangeStart; ch <= rangeEnd; ch++) {
                    configMap.put(ch, new String[]{preWord, postWord});
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public String[] getConfiguration(char ch) {
        return configMap.getOrDefault(ch, new String[]{"default-pre", "default-post"});
    }
}

class WordThread implements Runnable {
    private final String word;

    public WordThread(String word) {
        this.word = word;
    }

    @Override
    public void run() {
        try {
            Thread.sleep(1000);
            char firstChar = Character.toLowerCase(word.charAt(0));
            String[] config = Configuration.getInstance().getConfiguration(firstChar);
            System.out.println(config[0] + " " + word + " " + config[1]);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class FavoriteWords {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter your 5 favorite words:");
        String[] favoriteWords = new String[5];
        for (int i = 0; i < 5; i++) {
            favoriteWords[i] = scanner.nextLine();
        }
        scanner.close();

        ExecutorService executor = Executors.newFixedThreadPool(5);
        for (String word : favoriteWords) {
            executor.execute(new WordThread(word));
        }
        executor.shutdown();
    }
}
