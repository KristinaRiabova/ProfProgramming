public interface MessageSubscriber {
    void handleMessage(GreenMessage msg);
    void handleMessage(BlueMessage msg);
    void handleMessage(OrangeMessage msg);
}