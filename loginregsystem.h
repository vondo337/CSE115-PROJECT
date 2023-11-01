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

#endif
