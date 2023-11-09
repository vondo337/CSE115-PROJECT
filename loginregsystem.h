#define MAX_USERS 100

struct User 
{
    char username[50];
    char password[50];
};
void registerUser(struct User users[], int *userCount, const char username[], const char password[]) 
{
    if (*userCount < MAX_USERS) 
    {
        strcpy(users[*userCount].username, username);
        strcpy(users[*userCount].password, password);
        (*userCount)++;
        FILE *file = fopen("users.txt", "a");
        if (file) 
        {
            fprintf(file, "%s %s\n", username, password);
            fclose(file);
        } 
        else 
        {
            printf("Failed to write user data to the file.\n");
        }
    }
}
int loginUser(struct User users[], int userCount, const char username[], const char password[]) 
{
    for (int i = 0; i < userCount; i++) 
    {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) 
        {
            return i; // User found, return the index
        }
    }
    return -1; // User not found
}