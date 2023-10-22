/*CSE115 PROJECT
Name: Ahmed Ishmam Arefin
ID: 2322035642
Section: 9
Project Name: Bank Management System*/
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<dos.h>
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
  
  
  printf("                      ---------------------------Welcome to TND Bank ---------------------------\n");
  printf("1. Login\n2. Register\n3. Exit ");

  
  return 0;
}