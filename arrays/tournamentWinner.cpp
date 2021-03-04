/***
 * There's an algorithms tournament taking place in which teams of programmers
 * compete against each other to solve algorithmic problems as fast as possible.
 * Teams compete in a round robin, where each team faces off against all other
 * teams. Only two teams compete against each other at a time, and for each
 * competition, one team is designated the home team, while the other team is
 * the away team. In each competition there's always one winner and one loser;
 * there are no ties. A team receives 3 points if it wins and 0 points if it
 * loses. The winner of the tournament is the team that receives the most amount
 * of points.
 *
 * Given an array of pairs representing the teams that have competed against
 * each other and an array containing the results of each competition, write a
 * function that returns the winner of the tournament. The input arrays are
 * named competitions and results, respectively. The competitions array has
 * elements in the form of [homeTeam, awayTeam], where each team is a string of
 * at most 30 characters representing the name of the team. The results array
 * contains information about the winner of each corresponding competition in
 * the competitions array. Specifically, results[i] denotes the winner of
 * competitions[i], where a 1 in the results array means that the home team in
 * the corresponding competition won and a 0  means that the away team won.
 *
 * It's guaranteed that exactly one team will win the tournament and that each
 * team will compete against all other teams exactly once. It's also guaranteed
 * that the tournament will always have at least two teams.
 *
 *
 * ********************************************
 * OPTIMAL TIME & SPACE COMPLEXITY: O(n) time | O(k) space - where n is the
 * number of competitions and k is the number of teams
 * ********************************************
 * **/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

string tournamentWinner(vector<vector<string>> competitions,
                        vector<int> results) {
  string bestTeam = "";
  unordered_map<string, int> scores = {{bestTeam, 0}};

  for (int i = 0; i < results.size(); i++) {
    int result = results[i];
    vector<string> competition = competitions[i];
    string homeTeam = competition[0];
    string awayTeam = competition[1];
    string winningTeam = result == 1 ? homeTeam : awayTeam;

    if (scores.find(winningTeam) == scores.end()) {
      scores[winningTeam] = 0;
    }
    scores[winningTeam] += 3;

    if (scores[winningTeam] > scores[bestTeam]) {
      bestTeam = winningTeam;
    }
  }

  return bestTeam;
}

int main() {
  vector<vector<string>> competitions = {
      {"HTML", "C#"}, {"C#", "Python"}, {"Python", "C#"}};
  vector<int> results = {0, 0, 1};

  cout << tournamentWinner(competitions, results) << endl;  // Python

  vector<vector<string>> competitions2 = {
      {"HTML", "Java"}, {"Java", "Python"}, {"Python", "HTML"},
      {"C#", "Python"}, {"Java", "C#"},     {"C#", "HTML"},
      {"SQL", "C#"},    {"HTML", "SQL"},    {"SQL", "Python"},
      {"SQL", "Java"}};
  vector<int> results2 = {0, 1, 1, 1, 0, 1, 0, 1, 1, 0};

  cout << tournamentWinner(competitions2, results2) << endl;  // C#
  return 0;
}
