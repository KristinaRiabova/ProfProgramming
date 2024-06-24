#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

namespace {
    constexpr auto defaultUserHistoryFile = "history.txt";
    constexpr auto clearHistoryCommand = "bread";
    constexpr auto resetStatisticsCommand = "delete";
}

class UserHistory {
public:
    explicit UserHistory(const string& filePath) : filePath(filePath) {
        loadHistory();
    }

    ~UserHistory() {
        saveHistory();
    }

    void loadHistory() {
        ifstream file(filePath);
        string name;
        int count;
        while (file >> name >> count) {
            history[name] = count;
        }
    }

    void saveHistory() const {
        ofstream file(filePath);
        for (const auto& entry : history) {
            file << entry.first << " " << entry.second << endl;
        }
    }

    void greetUser(const string& name) {
        int& count = history[name];
        if (count == 0) {
            cout << "Welcome, " << name << "!" << endl;
        } else {
            cout << "Hello again(x" << count << "), " << name << endl;
        }
        ++count;
    }

    void resetStatistics(const string& name) {
        history.erase(name);
        cout << "Statistics for " << name << " reset." << endl;
    }

    void clearHistory() {
        history.clear();
        cout << "All history cleared." << endl;
    }

private:
    map<string, int> history;
    string filePath;
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Error: Please provide a name as argument." << endl;
        return 1;
    }

    string name = argv[1];
    UserHistory userHistory(defaultUserHistoryFile);

    if (name == clearHistoryCommand) {
        userHistory.clearHistory();
        return 0;
    }

    if (argc == 3 && string(argv[2]) == resetStatisticsCommand) {
        userHistory.resetStatistics(name);
        return 0;
    }

    userHistory.greetUser(name);

    return 0;
}
