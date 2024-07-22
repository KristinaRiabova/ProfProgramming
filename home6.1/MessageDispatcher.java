import java.util.Map;
import java.util.UUID;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.LinkedBlockingQueue;


public class MessageDispatcher {
    private Map<UUID, MessageSubscriber> subscribers;
    private BlockingQueue<Object> messageQueue;
    private Thread dispatcherThread;

    public MessageDispatcher() {
        this.subscribers = new ConcurrentHashMap<>();
        this.messageQueue = new LinkedBlockingQueue<>();
        startDispatcherThread();
    }

    private void startDispatcherThread() {
        dispatcherThread = new Thread(() -> {
            while (true) {
                try {
                    Object message = messageQueue.take(); // Blocking call to wait for new messages
                    dispatchMessage(message);
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                    break;
                }
            }
        });
        dispatcherThread.start();
    }

    private void dispatchMessage(Object message) {
        if (message instanceof GreenMessage) {
            for (MessageSubscriber subscriber : subscribers.values()) {
                subscriber.handleMessage((GreenMessage) message);
            }
        } else if (message instanceof BlueMessage) {
            for (MessageSubscriber subscriber : subscribers.values()) {
                subscriber.handleMessage((BlueMessage) message);
            }
        } else if (message instanceof OrangeMessage) {
            for (MessageSubscriber subscriber : subscribers.values()) {
                subscriber.handleMessage((OrangeMessage) message);
            }
        }
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
        messageQueue.offer(message); // Non-blocking add to queue
    }

    public void publish(BlueMessage message) {
        messageQueue.offer(message); // Non-blocking add to queue
    }

    public void publish(OrangeMessage message) {
        messageQueue.offer(message); // Non-blocking add to queue
    }

    // Stop the dispatcher thread
    public void stopDispatcher() {
        dispatcherThread.interrupt(); // Interrupt the dispatcher thread to stop
    }
}
