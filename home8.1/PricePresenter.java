class PricePresenter<PRIORITY> {
    private final int priority;

    public PricePresenter(int priority) {
        this.priority = priority;
    }

    public <T1 extends PricingMethods, T2 extends PricingMethods> void printTotalPrice(T1 obj1, T2 obj2) {
        double totalPrice = priority * obj1.getCoefficient() * obj1.getBasePrice() +
                            obj2.getCoefficient() * obj2.getBasePrice();
        System.out.println("Total Price: " + totalPrice);
    }
}