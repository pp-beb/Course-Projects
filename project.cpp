#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class Team {
private:
    string name;
    int matchesPlayed, wins, draws, losses;
    int goalsScored, goalsConceded, points;

public:
    Team(string n) : name(n), matchesPlayed(0), wins(0), draws(0), losses(0),
                     goalsScored(0), goalsConceded(0), points(0) {}

    void updateMatchResult(int scored, int conceded) {
        matchesPlayed++;
        goalsScored += scored;
        goalsConceded += conceded;
        if (scored > conceded) points += 3; 
        else if (scored == conceded) points += 1; 
        else losses++;
    }

    string getName() const { return name; }
    int getPoints() const { return points; }
    int getGoalDifference() const { return goalsScored - goalsConceded; }

    void display() const {
        cout << name << " " << points << " " << goalsScored << ":" << goalsConceded << endl;
    }
};

class League {
private:
    vector<Team> teams;

    void sortTeams() {
        sort(teams.begin(), teams.end(), [](const Team& a, const Team& b) {
            return a.getPoints() > b.getPoints() || 
                   (a.getPoints() == b.getPoints() && a.getGoalDifference() > b.getGoalDifference());
        });
    }

public:
    void addTeam(const string& name) {
        teams.emplace_back(name);
    }

    void recordMatchResult(const string& team1Name, const string& team2Name, int score1, int score2) {
        auto team1 = find_if(teams.begin(), teams.end(), [&](const Team& t) { return t.getName() == team1Name; });
        auto team2 = find_if(teams.begin(), teams.end(), [&](const Team& t) { return t.getName() == team2Name; });
        if (team1 != teams.end() && team2 != teams.end()) {
            team1->updateMatchResult(score1, score2);
            team2->updateMatchResult(score2, score1);
        }
    }

    void displayLeagueTable() {
        sortTeams();
        for (const auto& team : teams) {
            team.display();
        }
    }

    void saveToFile(const string& filename) {
        ofstream file(filename);
        for (const auto& team : teams) {
            file << team.getName() << " " << team.getPoints() << " " << team.getGoalDifference() << endl;
        }
    }

    void loadFromFile(const string& filename) {
        ifstream file(filename);
        string name;
        int points, goalDifference;
        while (file >> name >> points >> goalDifference) {
            addTeam(name);
            auto team = find_if(teams.begin(), teams.end(), [&](const Team& t) { return t.getName() == name; });
            if (team != teams.end()) {
                
            }
        }
    }
};

int main() {
    League league;
    league.addTeam("Team A");
    league.addTeam("Team B");

    league.recordMatchResult("Team A", "Team B", 2, 1);
    league.displayLeagueTable();

    league.saveToFile("league.txt");
    league.loadFromFile("league.txt");

    return 0;
}
