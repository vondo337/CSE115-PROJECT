/*CSE115 PROJECT
Name: Ahmed Ishmam Arefin
ID: 2322035642
Section: 9
Project Name: Bank Management System*/
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<windows.h>
#include "splash.h"
#include "loginregsystem.h"
#include "menu.h"


int main(void)
{
  system("cls");      //for clearing the terminal screen
  for(int i = 0; splash[i] != NULL; i++ )
  {
    printf("%s\n", splash[i]);
    usleep(1000);
  }
  sleep(2);
  system("cls");
  struct User users[MAX_USERS];
    int userCount = 0;
    int choice;
    FILE *file = fopen("users.txt", "r");
    if (file) 
    {
        while (fscanf(file, "%s %s", users[userCount].username, users[userCount].password) == 2) 
        {
            userCount++;
        }
        fclose(file);
    }

    while (1) 
    {
        printf("                      ---------------------------Welcome to the Bank of TND ---------------------------\n");
        printf("1. Register\n2. Login\n3. Quit\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) 
        {
            char ch;
            int i = 0;
            char username[50], password[50];
            printf("Enter a username: ");
            scanf("%s", username);
            printf("Enter a password: ");
            while((ch = _getch()) != 13)
            {
                password[i] = ch;
                i++;
                printf("*");
            }
            password[i] = '\0';
            registerUser(users, &userCount, username, password);
        } 
        else if(choice == 2) 
        {
            char ch;
            int i = 0;
            char username[50], password[50];
            printf("Enter your username: ");
            scanf("%s", username);
            printf("Enter your password: ");
            while((ch = _getch()) != 13)
            {
                password[i] = ch;
                i++;
                printf("*");
            }
            password[i] = '\0';
            int index = loginUser(users, userCount, username, password);
            if (index != -1) 
            {
                printf("\nLogin successful. Welcome, %s!\n", users[index].username);
                sleep(1);        
                system("cls");
                printf("       ---------------------------Main Menu---------------------------\n");
                printf("1. Withdraw Money\n2. Deposit Money\n3. Check Balance\n4. Transfer money\n5. Delete your account\n6. Exit\nEnter your choice: ");
                scanf("%d", &choice);
                if(choice == 1)
                {
                    void withdrawmoney();
                }
                else if(choice == 2)
                {
                    void depositmoney();
                }
                else if(choice == 3)
                {
                    void checkbalance();
                }
                else if(choice == 4)
                {
                    void transfermoney();
                }
                else if(choice == 5)
                {
                    void accountdeletion();
                }
                else if(choice == 6)
                {
                    break;
                }
                else
                {
                    printf("Invalid choice. Please try again.");
                }
            } 
            else 
            {
                printf("Login failed. Invalid username or password.\n");
                sleep(1);
                system("cls");
            }
        } 
        else if(choice == 3) 
        {
            break;
        } 
        else 
        {
            printf("Invalid choice. Please try again.\n");
        }
    }  
  return 0;
}