public class Main {
    public static void main(String[] args) {
        Milk milk = new Milk();
        Cookies cookies = new Cookies();
        Pineapple pineapple = new Pineapple();

        PricePresenter<Integer> presenter = new PricePresenter<>(10);

        presenter.printTotalPrice(milk, cookies);       
        presenter.printTotalPrice(cookies, pineapple);  
        presenter.printTotalPrice(milk, pineapple);     
    }
}