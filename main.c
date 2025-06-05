#include <stdatomic.h>
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
    printf("2. Login\n");
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

  userFile = fopen("user.txt", "r");

  if(userFile == NULL){
    userFile = fopen("user.txt", "w");
    
    if(userFile != NULL){
      fprintf(userFile, "%-10s %-16s\n", "Username", "Password");
      fclose(userFile);
    }
  }
  else{
    fclose(userFile);
  }

  while (1) {

    while ((getchar()) != '\n');
    printf("Enter your name: ");
    fgets(users.username, USERLENGTH, stdin);
    users.username[strcspn(users.username, "\n")] = 0;

    userFile = fopen("user.txt", "r");

    char headerLine[100];  // buffer large enough for the header line
    fgets(headerLine, sizeof(headerLine), userFile);

    char findUser[USERLENGTH];
    int userExists = 0;

    while(fscanf(userFile, "%s %*s", findUser) == 1){
      if(strcmp(users.username, findUser) == 0){
        userExists = 1;
        break;
      }
    }

    fclose(userFile);

    if(userExists){
      printf("This username exists! Please try again.");
      continue;
    }
    else{
      break;
    }
  }

  userFile = fopen("user.txt", "a");

  printf("Enter your password: ");
  fgets(users.password, PASSWORDLENGTH, stdin);
  users.password[strcspn(users.password, "\n")] = 0;

  fprintf(userFile, "%-10s %-16s\n", users.username, users.password);

  printf("Registration Successful!\n\nPress any key to continue...");
  getchar();

  fclose(userFile);
}

void loginUser(){
  system("cls");
  printf("~-Login-~\n\n");

  while(1){
    while ((getchar()) != '\n');
    
    printf("Name: ");
    fgets(users.username, USERLENGTH, stdin);
    users.username[strcspn(users.username, "\n")] = 0;

    printf("Password: ");
    fgets(users.password, PASSWORDLENGTH, stdin);
    users.password[strcspn(users.password, "\n")] = 0;
    
    userFile = fopen("user.txt", "r");

    char headerLine[100];
    fgets(headerLine, sizeof(headerLine), userFile);

    char findUser[USERLENGTH];
    char findPassword[PASSWORDLENGTH];

    int userExists = 0;

    while(fscanf(userFile, "%s %s", findUser, findPassword) == 1){
      if(strcmp(users.username, findUser) == 0 && strcmp(users.password, findPassword) == 0){
        userExists = 1;
        break;
      }
      
      else if(strcmp(users.username, findUser) != 0 && strcmp(users.password, findPassword) == 0){
        userExists = 1;
        break;
      }

      else if(strcmp(users.username, findUser) == 0 && strcmp(users.password, findPassword) != 0){
        userExists = 1;
        break;
      } 
    }

    fclose(userFile);

    if(userExists){
      printf("Invalid username or password.\nTry Again\n");
      continue;
    }

    else {
      printf("Login Successful!");
      break;
    }

    
  }
}
