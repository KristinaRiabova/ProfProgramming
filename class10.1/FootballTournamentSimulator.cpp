#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <random>
#include <ctime>
#include <cstddef> 
#include <ranges>


class Team {
private:
    std::string name;
    int goalsScored;
    int yellowCards;
    int redCards;
    double topHeight;

public:
    Team(const std::string& name) 
        : name(name), goalsScored(0), yellowCards(0), redCards(0), topHeight(0.0) {}


    std::string getName() const { return name; }
    int getGoalsScored() const { return goalsScored; }
    int getYellowCards() const { return yellowCards; }
    int getRedCards() const { return redCards; }
    double getTopHeight() const { return topHeight; }


    void scoreGoal(int goals = 1) { goalsScored += goals; }
    void receiveYellowCard() { yellowCards++; }
    void receiveRedCard() { redCards++; }
    void setTopHeight(double height) { topHeight = std::max(topHeight, height); }
};


class Match {
private:
    Team& team1;
    Team& team2;
    int goalsTeam1;
    int goalsTeam2;
    double topHeightTeam1;
    double topHeightTeam2;

public:
    Match(Team& team1, Team& team2) 
        : team1(team1), team2(team2), goalsTeam1(0), goalsTeam2(0), topHeightTeam1(0.0), topHeightTeam2(0.0) {}

    void playMatch() {
       
        goalsTeam1 = rand() % 5; 
        goalsTeam2 = rand() % 5;

        topHeightTeam1 = static_cast<double>(rand() % 30) / 10.0; 
        topHeightTeam2 = static_cast<double>(rand() % 30) / 10.0;

       
        team1.scoreGoal(goalsTeam1);
        team2.scoreGoal(goalsTeam2);
        team1.setTopHeight(topHeightTeam1);
        team2.setTopHeight(topHeightTeam2);
    }

    
    int getGoalsTeam1() const { return goalsTeam1; }
    int getGoalsTeam2() const { return goalsTeam2; }
    double getTopHeightTeam1() const { return topHeightTeam1; }
    double getTopHeightTeam2() const { return topHeightTeam2; }

    
    const Team& getTeam1() const { return team1; }
    const Team& getTeam2() const { return team2; }
};


class Tournament {
private:
    std::vector<Team> teams;
    std::vector<Match> matches;
    std::map<std::string, double> points;
    std::map<std::string, int> goalsDelta;
    std::map<std::string, int> goalsScored;
    std::map<std::string, int> redCards;
    std::map<std::string, int> yellowCards;
    std::map<std::string, double> topHeights;

public:
    Tournament(const std::vector<std::string>& teamNames) {
        for (const auto& name : teamNames) {
            teams.emplace_back(name);
            points[name] = 0.0;
            goalsDelta[name] = 0;
            goalsScored[name] = 0;
            redCards[name] = 0;
            yellowCards[name] = 0;
            topHeights[name] = 0.0;
        }
       
        for (size_t i = 0; i < teams.size(); ++i) {
            for (size_t j = i + 1; j < teams.size(); ++j) {
                matches.emplace_back(teams[i], teams[j]);
            }
        }
    }

    void playTournament() {
       
        for (auto& match : matches) {
            match.playMatch();

           
            updateStatistics(match);
        }

        
        calculatePoints();
    }

    void printResults() const {
      
        auto sortedTeams = teams;
        std::ranges::sort(sortedTeams, [&](const Team& t1, const Team& t2) {
            if (points.at(t1.getName()) != points.at(t2.getName())) {
                return points.at(t1.getName()) > points.at(t2.getName());
            } else if (goalsDelta.at(t1.getName()) != goalsDelta.at(t2.getName())) {
                return goalsDelta.at(t1.getName()) > goalsDelta.at(t2.getName());
            } else if (goalsScored.at(t1.getName()) != goalsScored.at(t2.getName())) {
                return goalsScored.at(t1.getName()) > goalsScored.at(t2.getName());
            } else if (redCards.at(t1.getName()) != redCards.at(t2.getName())) {
                return redCards.at(t1.getName()) < redCards.at(t2.getName());
            } else if (yellowCards.at(t1.getName()) != yellowCards.at(t2.getName())) {
                return yellowCards.at(t1.getName()) < yellowCards.at(t2.getName());
            } else {
                return topHeights.at(t1.getName()) > topHeights.at(t2.getName());
            }
        });

       
        std::cout << "Final Tournament Results:" << std::endl;
       
        std::cout << "| Team Name | Points | Goals Delta | Goals Scored | Red Cards | Yellow Cards | Top Heights |" << std::endl;
        
        for (const auto& team : sortedTeams) {
            std::cout << "| " << team.getName() << " | ";
            std::cout << points.at(team.getName()) << " | ";
            std::cout << goalsDelta.at(team.getName()) << " | ";
            std::cout << goalsScored.at(team.getName()) << " | ";
            std::cout << redCards.at(team.getName()) << " | ";
            std::cout << yellowCards.at(team.getName()) << " | ";
            std::cout << topHeights.at(team.getName()) << " | ";
            std::cout << std::endl;
        }
       
    }

private:
    void updateStatistics(const Match& match) {
        const Team& team1 = match.getTeam1();
        const Team& team2 = match.getTeam2();

       
        goalsScored[team1.getName()] += match.getGoalsTeam1();
        goalsScored[team2.getName()] += match.getGoalsTeam2();
        goalsDelta[team1.getName()] += match.getGoalsTeam1() - match.getGoalsTeam2();
        goalsDelta[team2.getName()] += match.getGoalsTeam2() - match.getGoalsTeam1();

       
        redCards[team1.getName()] += team1.getRedCards();
        redCards[team2.getName()] += team2.getRedCards();
        yellowCards[team1.getName()] += team1.getYellowCards();
        yellowCards[team2.getName()] += team2.getYellowCards();

      
        topHeights[team1.getName()] += match.getTopHeightTeam1();
        topHeights[team2.getName()] += match.getTopHeightTeam2();
    }

    void calculatePoints() {
        for (auto& team : teams) {
            points[team.getName()] = calculateTeamPoints(team);
        }
    }

    double calculateTeamPoints(const Team& team) {
        return pointsForWinLossDraw(goalsDelta.at(team.getName())) +
               goalsScored.at(team.getName()) +
               (redCards.at(team.getName()) * -1) +
               (yellowCards.at(team.getName()) * -1) +
               topHeights.at(team.getName());
    }

    double pointsForWinLossDraw(int deltaGoals) {
        if (deltaGoals > 0) {
            return 3.14; 
        } else if (deltaGoals == 0) {
            return 2.71828; 
        } else {
            return -0.5; 
        }
    }
};

int main() {
  
    srand(static_cast<unsigned int>(time(nullptr)));

  
    std::vector<std::string> teamNames = {"Team1", "Team2", "Team3", "Team4"};
    Tournament tournament(teamNames);

   
    tournament.playTournament();

    
    tournament.printResults();

    return 0;
}
