public class ECommerceApp {
    public static void main(String[] args) {
        // Old payment system instance
        OldPaymentSystem oldPaymentSystem = new OldPaymentSystem();
        
        // Adapter instance
        NewPaymentSystem newPaymentSystem = new PaymentAdapter(oldPaymentSystem);


        newPaymentSystem.makePayment("100 GRN");
    }
}
//The Adapter pattern is useful for integrating old code with new systems. 
//For instance, if you have an old payment system 
//and you want to use it in a new e-commerce platform that expects a different interface,
// you can create an adapter.