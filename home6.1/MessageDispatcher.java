import java.util.Map;
import java.util.UUID;
import java.util.concurrent.ConcurrentHashMap;


public class MessageDispatcher {
    private Map<UUID, MessageSubscriber> subscribers;

    public MessageDispatcher() {
        this.subscribers = new ConcurrentHashMap<>();
    }


    public UUID subscribe(MessageSubscriber subscriber) {
        UUID subscriptionId = UUID.randomUUID();
        subscribers.put(subscriptionId, subscriber);
        return subscriptionId;
    }


    public void unsubscribe(UUID subscriptionId) {
        subscribers.remove(subscriptionId);
    }


    public void publish(GreenMessage message) {
        for (MessageSubscriber subscriber : subscribers.values()) {
            subscriber.handleMessage(message);
        }
    }

 
    public void publish(BlueMessage message) {
        for (MessageSubscriber subscriber : subscribers.values()) {
            subscriber.handleMessage(message);
        }
    }


    public void publish(OrangeMessage message) {
        for (MessageSubscriber subscriber : subscribers.values()) {
            subscriber.handleMessage(message);
        }
    }
}
