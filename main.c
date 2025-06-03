#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USERLENGTH 10
#define PASSWORDLENGTH 16

typedef struct{
  char username[USERLENGTH];
  char password[PASSWORDLENGTH];
} User;

User users;

FILE *userFile;

void registerUser();
void loginUser();

int main(){
  
  while (1) {
    int choice;
    system("cls");
    printf("~-User Management System-~\n\n");
    printf("1. Register\n");
    printf("2. Logoin\n");
    printf("3. exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        registerUser();
        break;
      case 2:
        loginUser();
        break;
      case 3:
        exit(0);
      default:
        printf("Wrong input! Press any key to try again...");
        while ((getchar()) != '\n');
        getchar();
        break;
    }
 
  }

  return 0;
}

void registerUser(){
  system("cls");
  printf("~-Register-~\n\n");

  userFile = fopen("user.txt", "a");

  while ((getchar()) != '\n');
  printf("Enter your name: ");
  fgets(users.username, USERLENGTH, stdin);
  users.username[strcspn(users.username, "\n")] = 0;


  fprintf(userFile, "%s\n", users.username);

  fclose(userFile);
}

void loginUser(){

}
