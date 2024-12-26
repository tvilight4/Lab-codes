#include <stdio.h>
#include <string.h>
#define MAX_MEMBERS 100
#define MAX_CHILDREN 10
#define MAX_NAME_LENGTH 100
struct Child {
char name[MAX_NAME_LENGTH];
};
struct Wife {
char name[MAX_NAME_LENGTH];
int numChildren;
struct Child children[MAX_CHILDREN];
};
struct Member {
char name[MAX_NAME_LENGTH];
int age;
char address[MAX_NAME_LENGTH];
int isActive;
int isMarried;
struct Wife wife;
};
void printWivesOfActiveMembers(struct Member members[],
int numMembers) {
for (int i = 0; i < numMembers; i++) {
if (members[i].isActive && members[i].isMarried) {
printf("Wife of %s: %s\n", members[i].name,
members[i].wife.name);
}
}
}
int main() {
struct Member members[MAX_MEMBERS];
int numMembers;
printf("Enter the number of members: ");
scanf("%d", &numMembers);
getchar(); // Consume newline character
for (int i = 0; i < numMembers; i++) {
printf("Enter details for member %d:\n", i + 1);
printf("Name: ");
fgets(members[i].name, MAX_NAME_LENGTH, stdin);
members[i].name[strcspn(members[i].name, "\n")] = '\0';
printf("Age: ");
scanf("%d", &members[i].age);
getchar(); 
printf("Address: ");
fgets(members[i].address, MAX_NAME_LENGTH, stdin);
members[i].address[strcspn(members[i].address, "\n")] = '\0'; 
printf("Is active playing member? (1 for Yes, 0 for No): ");
scanf("%d", &members[i].isActive);
getchar(); 
printf("Is married? (1 for Yes, 0 for No): ");
scanf("%d", &members[i].isMarried);
getchar();
if (members[i].isMarried) {
printf("Wife's Name: ");
fgets(members[i].wife.name, MAX_NAME_LENGTH, stdin);
members[i].wife.name[strcspn(members[i].wife.name, "\n")] = '\0'; // Remove newline
printf("Number of children: ");
scanf("%d", &members[i].wife.numChildren);
getchar(); 
for (int j = 0; j <members[i].wife.numChildren; j++) {
printf("Name of child %d: ", j + 1);
fgets(members[i].wife.children[j].name,
MAX_NAME_LENGTH, stdin);
members[i].wife.children[j].name[strcspn(members[i].wife.children[j].name, "\n")] = '\0';
}
}
printf("\n");
}
printWivesOfActiveMembers(members, numMembers);
return 0;
}