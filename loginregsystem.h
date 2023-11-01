#ifndef LOGIN_H
#define LOGIN_H

#define MAX_USERS 10

struct User
{
  char username[50];
  char pin[5];    // 4-digit pin
};
void registeraccount(struct User user[], int *usercount, const char username[], const char pin[]);
int account(const struct User user[], int usercount, const char username[], const char pin[]);

void registeraccount(struct User user[], int *usercount, const char username[], const char pin[])
{
  if(*usercount < MAX_USERS)
  {
    strcpy(user[*usercount].username, username);
    strcpy(user[*usercount].pin, pin);
    (*usercount)++;
  }
}

int account(const struct User user[], int usercount, const char username[], const char pin[])
{
  for(int i = 0; i < usercount; i++)
  {
    if(strcmp(user[i].username, username))
      return 1; // User found
  }
  return -1; // User not found
}

#endif
