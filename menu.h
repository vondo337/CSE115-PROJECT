    void depositmoney() {
    int account_number;
    double amount;

    printf("Enter the account number: ");
    scanf("%d", &account_number);
    printf("Enter the amount to deposit: ");
    scanf("%lf", &amount);

    FILE* file = fopen("accounts.txt", "r");  //// For finding the account the txt file is in read mode
    if (file == NULL) 
    {
        printf("Error opening the file for reading!\n");
        return;
    }
    FILE* tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) 
    {
        printf("Error opening the temp file for writing!\n");
        fclose(file);
        return;
    }
    BankAccount account;
    int found = 0;
    while (fscanf(file, "%s %d %lf", account.name, &account.account_number, &account.balance) != EOF) 
    {
        if (account.account_number == account_number) 
        {
            account.balance += amount;
            found = 1;
        }
        fprintf(tempFile, "%s %d %.2lf\n", account.name, account.account_number, account.balance);
    }

    fclose(file);
    fclose(tempFile);

    if (!found) 
    {
        remove("temp.txt");
        printf("Account not found!\n");
        return;
    }

    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");
    printf("Deposit completed successfully!\n");
}

void withdrawmoney() 
{
    int account_number;
    double amount;

    printf("Enter the account number: ");
    scanf("%d", &account_number);
    printf("Enter the amount to withdraw: ");
    scanf("%lf", &amount);

    FILE* file = fopen("accounts.txt", "r"); //For finding the account the txt file is opened in read mode
    if (file == NULL) 
    {
        printf("Error opening the file for reading!\n");
        return;
    }
    FILE* tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) 
    {
        printf("Error opening the temp file for writing!\n");
        fclose(file);
        return;
    }

    BankAccount account;
    int found = 0;
    while (fscanf(file, "%s %d %lf", account.name, &account.account_number, &account.balance) != EOF) 
    {
        if (account.account_number == account_number) 
        {
            if (account.balance >= amount) 
            {
                account.balance -= amount;
                found = 1;
            } 
            else 
            {
                printf("Insufficient balance to withdraw!\n");
            }
        }
        fprintf(tempFile, "%s %d %.2lf\n", account.name, account.account_number, account.balance);
    }

    fclose(file);
    fclose(tempFile);

    if (!found) 
    {
        remove("temp.txt");
        printf("Account not found!\n");
        return;
    }
    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");
    printf("Withdrawal completed successfully!\n");
}

void transfermoney() 
{
    int from_account, to_account;
    double amount;

    printf("Enter the account number to transfer from: ");
    scanf("%d", &from_account);
    printf("Enter the account number to transfer to: ");
    scanf("%d", &to_account);
    printf("Enter the amount to transfer: ");
    scanf("%lf", &amount);

    FILE* file = fopen("accounts.txt", "r");   // For finding the accounts the txt file is opened in read mode
    if (file == NULL) 
    {
        printf("Error opening the file for reading!\n");
        return;
    }

    FILE* tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) 
    {
        printf("Error opening the temp file for writing!\n");
        fclose(file);
        return;
    }

    BankAccount account;
    int from_found = 0, to_found = 0;
    while (fscanf(file, "%s %d %lf", account.name, &account.account_number, &account.balance) != EOF) 
    {
        if (account.account_number == from_account) 
        {
            if (account.balance >= amount) 
            {
                account.balance -= amount;
                from_found = 1;
            } 
            else 
            {
                printf("Insufficient balance to transfer!\n");
            }
        } 
        else if (account.account_number == to_account) 
        {
            account.balance += amount;
            to_found = 1;
        }
        fprintf(tempFile, "%s %d %.2lf\n", account.name, account.account_number, account.balance);
    }

    fclose(file);
    fclose(tempFile);

    if (!from_found || !to_found) 
    {
        remove("temp.txt");
        printf("One or both accounts not found!\n");
        return;
    }
    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");
    printf("Transfer completed successfully!\n");
}

void checkbalance() 
{
    int account_number;
    printf("Enter the account number: ");
    scanf("%d", &account_number);
    FILE* file = fopen("accounts.txt", "r"); // For finding the account the file is opened in read mode
    if (file == NULL) 
    {
        printf("Error opening the file for reading!\n");
        return;
    }

    BankAccount account;
    int found = 0;
    while (fscanf(file, "%s %d %lf", account.name, &account.account_number, &account.balance) != EOF) 
    {
        if (account.account_number == account_number) 
        {
            printf("Account Holder: %s\n", account.name);
            printf("Account Balance: %.2lf\n", account.balance);
            found = 1;
        }
    }

    fclose(file);

    if (!found) 
    {
        printf("Account not found!\n");
    }
}

void accountdeletion() 
{
    int account_number;

    printf("Enter the account number to delete: ");
    scanf("%d", &account_number);

    FILE* file = fopen("accounts.txt", "r");   // For finding the account the file is opened in read mode
    if (file == NULL) 
    {
        printf("Error opening the file for reading!\n");
        return;
    }

    FILE* tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) 
    {
        printf("Error opening the temp file for writing!\n");
        fclose(file);
        return;
    }

    BankAccount account;
    int found = 0;
    while (fscanf(file, "%s %d %lf", account.name, &account.account_number, &account.balance) != EOF) 
    {
        if (account.account_number == account_number) 
        {
            found = 1;
        } else 
        {
            fprintf(tempFile, "%s %d %.2lf\n", account.name, account.account_number, account.balance);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (!found) 
    {
        remove("temp.txt");
        printf("Account not found!\n");
        return;
    }

    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");

    printf("Account deleted successfully!\n");
}



