#include <stdio.h>
#include <stdlib.h>

void registeruser();
void logoutuser();


int main(){
  
  int choice;

  while (1) {
    system("cls");
    printf("~-User Management System\n\n");
    printf("1. Register\n");
    printf("2. Logout\n");
    printf("3. exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        registeruser();
        break;
      case 2:
        logoutuser();
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

void registeruser(){

}

void logoutuser(){

}
