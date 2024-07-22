import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class BookRecommender {
    private static void proposeBook(List<String> books, String name) {
        if (books.isEmpty()) {
            System.out.println("Au revoir, " + name + "!");
            System.exit(0);
        }

        Random rand = new Random();
        int index = rand.nextInt(books.size());
        String book = books.get(index);

        System.out.println("How about this book: " + book + "? (yes/no)");

        Scanner scanner = new Scanner(System.in);
        String response = scanner.next();

        if (response.equalsIgnoreCase("yes")) {
            System.out.println("Enjoy your book, " + name + "!");
            System.exit(0);
        } else if (response.equalsIgnoreCase("no")) {
            books.remove(index);
        } else {
            System.out.println("Invalid response. Please type 'yes' or 'no'.");
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter your name: ");
        String name = scanner.nextLine();

        List<String> books = new ArrayList<>();
        books.add("The Topographer’s Clown");
        books.add("The Chamber of Beaver");
        books.add("The Ironer of Kanban");
        books.add("The Piglet of Tire");
        books.add("The Border of the Unix");
        books.add("The Half-Time Convince");
        books.add("The Earthly Pillows");
        books.add("The Censorship of the Ping");
        books.add("The True Powers");
        books.add("The Overturn of the Ling");

        while (true) {
            proposeBook(books, name);
        }
    }
}
