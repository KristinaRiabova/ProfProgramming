#include <concepts>
#include <iostream>


template<typename T>
concept HasPricingMethods = requires(T obj) {
    { obj.getCoefficient() } -> std::same_as<double>;
    { obj.getBasePrice() } -> std::same_as<double>;
};


template<std::size_t PRIORITY>
class PricePresenter {
public:
    template<HasPricingMethods T1, HasPricingMethods T2>
    void printTotalPrice(const T1& obj1, const T2& obj2) const {
        double totalPrice = PRIORITY * obj1.getCoefficient() * obj1.getBasePrice() + obj2.getCoefficient() * obj2.getBasePrice();
        std::cout << "Total Price: " << totalPrice << std::endl;
    }
};


class Milk {
public:
    double getCoefficient() const {
        return 2.2;
    }

    double getBasePrice() const {
        return 2.5;
    }
};

class Cookies {
public:
    double getCoefficient() const {
        return 1.7;
    }

    double getBasePrice() const {
        return 4.0;
    }
};

class Pineapple {
public:
    double getCoefficient() const {
        return 3.0;
    }

    double getBasePrice() const {
        return 5.0;
    }
};


int main() {
    Milk milk;
    Cookies cookies;
    Pineapple pineapple;

    PricePresenter<10> presenter;
    presenter.printTotalPrice(milk, cookies);       
    presenter.printTotalPrice(cookies, pineapple);  
    presenter.printTotalPrice(milk, pineapple);     

    return 0;
}
