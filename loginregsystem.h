void createaccount() {
    BankAccount account;
    printf("Enter the account holder's name: ");
    scanf("%s", account.name);
    printf("Enter the account number: ");
    scanf("%d", &account.account_number);
    printf("Enter the initial balance: ");
    scanf("%lf", &account.balance);

    // Open the file in append mode to add the new account
    FILE* file = fopen("accounts.txt", "a");
    if (file == NULL) {
        printf("Error opening the file for writing!\n");
        return;
    }
    fprintf(file, "%s %d %.2lf\n", account.name, account.account_number, account.balance);
    fclose(file);
    printf("Account created successfully!\n");
}