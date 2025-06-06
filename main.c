#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
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
void maskPassword(char *password);

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
  maskPassword(users.password);
  
  fprintf(userFile, "%-10s %-16s\n", users.username, users.password);

  printf("\nRegistration Successful!\n\nPress any key to continue...");
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
    maskPassword(users.password);

    userFile = fopen("user.txt", "r");

    char headerLine[100];
    fgets(headerLine, sizeof(headerLine), userFile);

    char findUser[USERLENGTH];
    char findPassword[PASSWORDLENGTH];

    int loginSuccessful = 0;

    while(fscanf(userFile, "%s %s", findUser, findPassword) == 2){
      if(strcmp(users.username, findUser) == 0 && strcmp(users.password, findPassword) == 0){
        loginSuccessful = 1;
        break;
      }
    }

    fclose(userFile);

    if(loginSuccessful){
      printf("\nLogin Successful!\n");
      printf("Press any key to continue...");
      getchar();
      break;
    }

    else {
      printf("\nInvalid username or password.\nTry Again\n");
      continue;
    }
 
  }
}

void maskPassword(char *password){
  int i = 0;

  while(1){
    char passInp = _getch();
    
    if(passInp == '\r'){
      break;
    }
    
    else if(passInp == '\b'){
      if(i > 0){
        i--;
        printf("\b \b");
      }
    }

    else if(i < 16){
      password[i++] = passInp;
      printf("*");
    }
  }

  password[i] = '\0';

}
