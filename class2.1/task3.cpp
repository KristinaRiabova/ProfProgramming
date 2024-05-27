#include <iostream>
#include <fstream>
#include <map>
#include <string>
//I create history.txt file for saving data.
using namespace std;

map<string, int> userHistory;

void loadHistory() {
    ifstream file("history.txt");
    string name;
    int count;
    while (file >> name >> count) {
        userHistory[name] = count;
    }
    file.close();
}

void saveHistory() {
    ofstream file("history.txt");
    for (const auto& entry : userHistory) {
        file << entry.first << " " << entry.second << endl;
    }
    file.close();
}

void greetUser(const string& name) {
    if (userHistory.find(name) == userHistory.end()) {
        cout << "Welcome, " << name << "!" << endl;
        userHistory[name] = 1;
    } else {
        cout << "Hello again(x" << userHistory[name] << "), " << name << endl;
        userHistory[name]++;
    }
}

void resetStatistics(const string& name) {
    userHistory.erase(name);
    cout << "Statistics for " << name << " reset." << endl;
}

void clearHistory() {
    userHistory.clear();
    cout << "All history cleared." << endl;
}

int main(int argc, char* argv[]) {
    loadHistory();

    if (argc < 2) {
        cout << "Error: Please provide a name as argument." << endl;
        return 1;
    }

    string name = argv[1];

    if (name == "bread") {
        clearHistory();
        saveHistory();
        return 0;
    }

    if (argc == 3 && string(argv[2]) == "delete") {
        resetStatistics(name);
        saveHistory();
        return 0;
    }

    greetUser(name);
    saveHistory();

    return 0;
}
