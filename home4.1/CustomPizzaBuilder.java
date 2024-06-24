import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class CustomPizzaBuilder {
    private CustomPizza pizza;
    private Map<String, Double> toppingPrices;

    public CustomPizzaBuilder() {
        this.pizza = new CustomPizza();
        this.toppingPrices = new HashMap<>();
        loadToppings("ingredients.txt"); // Load default toppings and prices from file
    }

    public void addTopping(String topping) {
        if (toppingPrices.containsKey(topping)) {
            pizza.addTopping(topping, toppingPrices.get(topping));
        } else {
            System.err.println("Topping not found: " + topping);
        }
    }

    public CustomPizza getPizza() {
        return pizza;
    }

    private void loadToppings(String filename) {
        try (Scanner scanner = new Scanner(new File(filename))) {
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] parts = line.split("\\s+");
                if (parts.length == 2) {
                    String topping = parts[0];
                    double cost = Double.parseDouble(parts[1]);
                    toppingPrices.put(topping, cost);
                }
            }
        } catch (FileNotFoundException e) {
            System.err.println("Error: File not found - " + filename);
        }
    }
}
