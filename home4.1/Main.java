import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        CustomPizzaBuilder builder = new CustomPizzaBuilder();
        PizzaMaker maker = new PizzaMaker();
        Scanner scanner = new Scanner(System.in);

        System.out.println("Do you want to choose a classical pizza or compose a custom one?");
        System.out.println("1. Classical Pizza");
        System.out.println("2. Custom Pizza");
        System.out.print("Enter your choice (1 or 2): ");
        int choice = scanner.nextInt();
        scanner.nextLine(); // Consume newline character

        List<String> toppings = new ArrayList<>();

        if (choice == 1) {
            // Add classical pizza toppings based on provided menu
            addClassicalPizzaToppings(toppings);
        } else if (choice == 2) {
            // Prompt user for custom pizza toppings
            System.out.println("Enter toppings (type 'done' when finished):");
            String input;
            while (true) {
                input = scanner.nextLine();
                if (input.equalsIgnoreCase("done")) {
                    break;
                }
                toppings.add(input);
            }
        } else {
            System.out.println("Invalid choice. Exiting program.");
            return;
        }

        maker.createPizza(builder, toppings);
        CustomPizza pizza = builder.getPizza();
        pizza.display();

        scanner.close();
    }

    private static void addClassicalPizzaToppings(List<String> toppings) {
        
        toppings.add("Pepperoni");
        toppings.add("Stefania");
        toppings.add("BlackPizza");
        toppings.add("Senorita");
        toppings.add("Macaroni");
        toppings.add("Ukrainian");
        toppings.add("Pineapple");
    }
}
