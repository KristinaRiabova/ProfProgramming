#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void proposeBook(std::vector<std::string>& books) {
    if (books.empty()) {
        std::cout << "Adios amigo!" << std::endl;
        exit(0);
    }

    int index = rand() % books.size();
    std::string book = books[index];
    
    std::cout << "How about this book: " << book << "? (yes/no)" << std::endl;
    
    std::string response;
    std::cin >> response;

    if (response == "yes") {
        std::cout << "Enjoy your book!" << std::endl;
        exit(0);
    } else if (response == "no") {
        books.erase(books.begin() + index);
    } else {
        std::cout << "Invalid response. Please type 'yes' or 'no'." << std::endl;
    }
}

int main() {
    std::srand(std::time(0));
    std::vector<std::string> books = {
        "The Topographer’s Clown",
        "The Chamber of Beaver",
        "The Ironer of Kanban",
        "The Piglet of Tire",
        "The Border of the Unix",
        "The Half-Time Convince",
        "The Earthly Pillows",
        "The Censorship of the Ping",
        "The True Powers",
        "The Overturn of the Ling"
    };

    while (true) {
        proposeBook(books);
    }

    return 0;
}
