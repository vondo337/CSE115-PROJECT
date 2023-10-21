#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include "splash.h"

int main(void)
{
  system("cls"); //for clearing the terminal screen
  for(int i = 0; splash[i] != NULL; i++ )
  {
    printf("%s\n", splash[i]);
    usleep(1000);
  }
  sleep(2);
  system("cls");
  return 0;
}