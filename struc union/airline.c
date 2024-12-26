#include <stdio.h>
#include <string.h>
#define MAX_FLIGHTS 20
#define MAX_CODE_LENGTH 4
struct Flight {
char startingPoint[MAX_CODE_LENGTH];
char destination[MAX_CODE_LENGTH];
int startingTime;
int arrivalTime;
int seats;
};
void processQuery(struct Flight flights[], int numFlights,
char queryStart[], char queryDest[]) {
for (int i = 0; i < numFlights; i++) {
if (strcmp(flights[i].startingPoint, queryStart)
== 0 &&
strcmp(flights[i].destination, queryDest) ==
0) {
if (flights[i].seats > 0) {
flights[i].seats--;
printf("Flight found: %s -> %s, Starting: %d, Arrival: %d, Seats left: %d\n",
flights[i].startingPoint,
flights[i].destination,
flights[i].startingTime,
flights[i].arrivalTime, flights[i].seats);
return;
}
}
}
printf("Sorry, no available flight found from %s to %s\n", queryStart, queryDest);
}
int main() {
struct Flight flights[MAX_FLIGHTS];
int numFlights = 20;
for (int i = 0; i < numFlights; i++) {
printf("Enter details for flight %d:\n", i + 1);
printf("Starting point: ");
scanf("%s", flights[i].startingPoint);
printf("Destination: ");
scanf("%s", flights[i].destination);
printf("Starting time: ");
scanf("%d", &flights[i].startingTime);
printf("Arrival time: ");
scanf("%d", &flights[i].arrivalTime);
printf("Seats: ");
scanf("%d", &flights[i].seats);
}
char queryStart[MAX_CODE_LENGTH];
char queryDest[MAX_CODE_LENGTH];
printf("Enter query in the form 'STARTING POINT-DESTINATION' (or 'exit' to stop):\n");
while (1) {
printf("Query: ");
scanf("%s", queryStart);
if (strcmp(queryStart, "exit") == 0) break;
scanf("%s", queryDest);
processQuery(flights, numFlights, queryStart,
queryDest);
}
return 0;
}