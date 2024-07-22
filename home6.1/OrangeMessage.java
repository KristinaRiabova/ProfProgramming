public class OrangeMessage {
    private String str1;
    private String str2;
    private int number;
    private double value;

    public OrangeMessage(String str1, String str2, int number, double value) {
        this.str1 = str1;
        this.str2 = str2;
        this.number = number;
        this.value = value;
    }

    public String getStr1() {
        return str1;
    }

    public String getStr2() {
        return str2;
    }

    public int getNumber() {
        return number;
    }

    public double getValue() {
        return value;
    }
}