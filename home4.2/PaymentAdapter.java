// Adapter class that allows the old system to be used in the new application
public class PaymentAdapter implements NewPaymentSystem {
    private OldPaymentSystem oldPaymentSystem;

    public PaymentAdapter(OldPaymentSystem oldPaymentSystem) {
        this.oldPaymentSystem = oldPaymentSystem;
    }

    @Override
    public void makePayment(String paymentDetails) {
        // Redirect the call to the old method
        oldPaymentSystem.processPayment(paymentDetails);
    }
}