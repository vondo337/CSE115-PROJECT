void createaccount() 
{
    BankAccount account;
    printf("Enter the account holder's name: ");
    scanf("%s", account.name);
    printf("Enter the account number: ");
    scanf("%d", &account.account_number);
    printf("Enter the initial balance: ");
    scanf("%lf", &account.balance);

    
    FILE* file = fopen("accounts.txt", "a"); //For opening the file to add new account in append mode
    if (file == NULL) 
    {
        printf("Error opening the file for writing!\n");
        return;
    }
    fprintf(file, "%s %d %.2lf\n", account.name, account.account_number, account.balance);
    fclose(file);
    printf("Account created successfully!\n");
    system("cls");
}