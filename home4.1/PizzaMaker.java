import java.util.List;

public class PizzaMaker {
    public void createPizza(CustomPizzaBuilder builder, List<String> toppings) {
        for (String topping : toppings) {
            builder.addTopping(topping);
        }
    }
}
