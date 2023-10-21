#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include "splash.h"

int main(void)
{
  system("clear"); //for clearing the terminal screen
  for(int i = 0; splash[i] != NULL; i++ )
  {
    printf("%s\n", splash[i]);
    usleep(100000);
  }
  sleep(3);
  system("clear");
  return 0;
}