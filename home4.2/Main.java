public class Main {
    public static void main(String[] args) {
        BaseMegaCalculator calculator = new MyCoolCalculator(6.0, 12.1, 3.2);
        printResults(calculator);

        calculator = new ConstantCalculator();
        printResults(calculator);

        calculator = new MegaAdapter(new LegacyCalculator(1.34, 5.4));
        printResults(calculator);
    }

    private static void printResults(BaseMegaCalculator calculator) {
        System.out.println("Current price: " + calculator.getPrice());
        System.out.println("Current minimal value: " + calculator.getMinimalValue());
        System.out.println("Current report: " + calculator.getReport());
    }
}
//The Adapter pattern is useful for integrating old code with new systems. 
//For instance, if you have an old payment system 
//and you want to use it in a new e-commerce platform that expects a different interface,
// you can create an adapter.