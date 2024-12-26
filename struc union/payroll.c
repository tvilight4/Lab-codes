#include <stdio.h>
#include <string.h>
#define MAX_EMPLOYEES 100
#define NAME_LENGTH 21
struct Date {
int year;
int month;
int day;
};
struct Employee {
char name[NAME_LENGTH];
char gender;
int salary;
struct Date dob;
};
int calculateAge(struct Date dob, struct Date currentDate)
{
int age = currentDate.year - dob.year;
if (currentDate.month < dob.month ||
(currentDate.month == dob.month && currentDate.day <
dob.day)) {
age--;
}
return age;
}
void updateRecords(struct Employee employees[], int
*numEmployees, struct Employee amendments[], int
numAmendments, struct Date currentDate) {
for (int i = 0; i < numAmendments; i++) {
int found = 0;
for (int j = 0; j < *numEmployees; j++) {
if (strcmp(employees[j].name,
amendments[i].name) == 0) {
if (amendments[i].salary == 0) {
for (int k = j; k < *numEmployees - 1;
k++) {
employees[k] = employees[k + 1];
}
(*numEmployees)--;
} else {
employees[j].salary =
amendments[i].salary;
}
found = 1;
break;
}
}
if (!found && amendments[i].salary != 0) {
employees[*numEmployees] = amendments[i];
(*numEmployees)++;
}
}
for (int i = 0; i < *numEmployees; i++) {
if (calculateAge(employees[i].dob, currentDate) >=
60) {
for (int j = i; j < *numEmployees - 1; j++) {
employees[j] = employees[j + 1];
}
(*numEmployees)--;
i--;
}
}
}
int main() {
struct Employee employees[MAX_EMPLOYEES];
struct Employee amendments[5];
struct Date currentDate = {2024, 12, 20};
int numEmployees = 10;
int numAmendments = 5;
for (int i = 0; i < numEmployees; i++) {
printf("Enter details for employee %d:\n", i + 1);
printf("Name: ");
scanf("%s", employees[i].name);
printf("Gender: ");
scanf(" %c", &employees[i].gender);
printf("Salary: ");
scanf("%d", &employees[i].salary);
printf("Date of Birth (YYYY MM DD): ");
scanf("%d %d %d", &employees[i].dob.year,
&employees[i].dob.month, &employees[i].dob.day);
}
for (int i = 0; i < numAmendments; i++) {
printf("Enter amendment %d:\n", i + 1);
printf("Name: ");
scanf("%s", amendments[i].name);
printf("Gender: ");
scanf(" %c", &amendments[i].gender);
printf("Salary: ");
scanf("%d", &amendments[i].salary);
printf("Date of Birth (YYYY MM DD): ");
scanf("%d %d %d", &amendments[i].dob.year,
&amendments[i].dob.month, &amendments[i].dob.day);
}
updateRecords(employees, &numEmployees, amendments,
numAmendments, currentDate);
printf("Updated employee records:\n");
for (int i = 0; i < numEmployees; i++) {
printf("Name: %s, Gender: %c, Salary: %d, Date of Birth: %d-%02d-%02d\n",
employees[i].name, employees[i].gender,
employees[i].salary,
employees[i].dob.year,
employees[i].dob.month, employees[i].dob.day);
}
return 0;
}