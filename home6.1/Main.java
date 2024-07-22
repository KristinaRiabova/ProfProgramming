import java.util.UUID;

public class Main {
    public static void main(String[] args) {
        MessageDispatcher dispatcher = new MessageDispatcher();

        MessageSubscriber subscriber = new MessageSubscriber() {
            @Override
            public void handleMessage(GreenMessage msg) {
                System.out.println("Received GreenMessage: " + msg.getMessage() + " " + msg.getCounter());
            }

            @Override
            public void handleMessage(BlueMessage msg) {
                System.out.println("Received BlueMessage: " + msg.getValue1() + " " + msg.getValue2());
            }

            @Override
            public void handleMessage(OrangeMessage msg) {
                System.out.println("Received OrangeMessage: " + msg.getStr1() + " " + msg.getStr2() +
                        " " + msg.getNumber() + " " + msg.getValue());
            }
        };

        UUID subscriptionId = dispatcher.subscribe(subscriber);
        System.out.println("Subscriber subscribed with ID: " + subscriptionId);

        dispatcher.publish(new GreenMessage("Hello Green", 36));
        dispatcher.publish(new BlueMessage(1.5, 3.7));
        dispatcher.publish(new OrangeMessage("Orange", "Message", 127, 3.16));

        dispatcher.unsubscribe(subscriptionId);
        System.out.println("Subscriber unsubscribed");

        // Stop the dispatcher gracefully
        dispatcher.stopDispatcher();
    }
}