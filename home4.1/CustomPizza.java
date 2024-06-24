import java.util.ArrayList;
import java.util.List;

public class CustomPizza {
    private List<String> toppings;
    private double totalCost;

    public CustomPizza() {
        this.toppings = new ArrayList<>();
        this.totalCost = 0.0;
    }

    public void addTopping(String topping, double cost) {
        toppings.add(topping);
        totalCost += cost;
    }

    public void display() {
        System.out.println("Toppings:");
        for (String topping : toppings) {
            System.out.println("- " + topping);
        }
        System.out.println("Total cost: $" + totalCost);
    }

    public double getTotalCost() {
        return totalCost;
    }
}
