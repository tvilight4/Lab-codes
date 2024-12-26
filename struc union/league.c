#include <stdio.h>
#include <string.h>
#define MAX_TEAMS 100
#define MAX_NAME_LENGTH 50
struct Team {
char name[MAX_NAME_LENGTH];
int gamesPlayed;
int gamesWon;
int gamesDrawn;
int gamesLost;
int goalsScored;
int points;
};
void updateTeamRecord(struct Team *team, int goalsScored,
int goalsConceded) {
team->gamesPlayed++;
team->goalsScored += goalsScored;
if (goalsScored > goalsConceded) {
team->gamesWon++;
team->points += 2;
} else if (goalsScored == goalsConceded) {
team->gamesDrawn++;
team->points += 1;
} else {
team->gamesLost++;
}
}
int findTeamIndex(struct Team teams[], int numTeams, char
name[]) {
for (int i = 0; i < numTeams; i++) {
if (strcmp(teams[i].name, name) == 0) {
return i;
}
}
return -1;
}
int main() {
struct Team teams[MAX_TEAMS] = {
{"TeamA", 10, 5, 2, 3, 20, 12},
{"TeamB", 10, 6, 1, 3, 18, 13},
{"TeamC", 10, 4, 3, 3, 15, 11},
{"TeamD", 10, 2, 4, 4, 10, 8},
{"TeamE", 10, 7, 1, 2, 25, 15}
};
int numTeams = 5;
int M;
printf("Enter the number of games: ");
scanf("%d", &M);
for (int i = 0; i < M; i++) {
char team1[MAX_NAME_LENGTH],
team2[MAX_NAME_LENGTH];
int goals1, goals2;
printf("Enter result of game %d:\n", i + 1);
printf("Team1 name: ");
scanf("%s", team1);
printf("Goals scored by %s: ", team1);
scanf("%d", &goals1);
printf("Team2 name: ");
scanf("%s", team2);
printf("Goals scored by %s: ", team2);
scanf("%d", &goals2);
int index1 = findTeamIndex(teams, numTeams,
team1);
int index2 = findTeamIndex(teams, numTeams,
team2);
if (index1 != -1 && index2 != -1) {
updateTeamRecord(&teams[index1], goals1,
goals2);
updateTeamRecord(&teams[index2], goals2,
goals1);
}
}
printf("Updated league table:\n");
for (int i = 0; i < numTeams; i++) {
printf("Team: %s, Played: %d, Won: %d, Drawn: %d, Lost: %d, Goals: %d, Points: %d\n",
teams[i].name, teams[i].gamesPlayed,
teams[i].gamesWon, teams[i].gamesDrawn,
teams[i].gamesLost, teams[i].goalsScored,
teams[i].points);
}
return 0;
}