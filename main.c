/*CSE115 PROJECT
Name: Ahmed Ishmam Arefin
ID: 2322035642
Section: 9
Project Name: Bank Management System*/
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<windows.h>
#include "loginregsystem.h"
#include "splash.h"

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
  int choice; 
  int usercount = 0;
  struct User user[MAX_USERS];

  // For loading user data from the text file
  FILE *file = fopen("users.txt", "r");
  if(file)
  {
    while(fscanf(file, "%s %s", user[usercount].username, user[usercount].pin) == 2)
    {
      usercount++;
    }
    fclose(file);
  }
  
  while(1)
  {
  printf("                      ---------------------------Welcome to TND Bank ---------------------------\n");
  printf("1. Login\n2. Register\n3. Exit \n");
  printf("Enter your choice: ");
  scanf("%d", &choice);
  if(choice == 1)
  {
    char username[50];
    int pin[4];
    system("cls");
    printf("Username: ");
    scanf("%s", username);
    printf("PIN CODE: ");
    scanf("%4d", pin);
    int index = account(user, usercount, username, pin );
    if(index != -1)
    {
      printf("Login successful. Welcome, %s!\n", user[index].username);
    }
    else
    {
      printf("Login failed. Invalid username or PIN.\n");
    }
  }
  else if(choice == 2)
  {
    char username[50]; 
    int pin[4];
    system("cls");
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your 4-digit PIN: ");
    scanf("%d", pin);
    registeraccount(user, &usercount, username, pin);
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