#ifndef LOGIN_H
#define LOGIN_H

#define MAX_USERS 10

struct User
{
  char username[50];
  char pin[5];
};
void userregister(struct User user[], int *usercount, const char username[], const char pin[]);
int userlogin(const struct User user[], int usercount, const char username[], const char pin[]);

#endif
