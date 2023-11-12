/*CSE115 PROJECT
Name: Ahmed Ishmam Arefin
ID: 2322035642
Section: 9
Project Name: Bank Management System*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<windows.h>
typedef struct 
{
    char name[50];
    int account_number;
    double balance;
} BankAccount;
void screen();
void createaccount();
void transfermoney();
void checkbalance();
void depositmoney();
void withdrawmoney();
void accountdeletion();
#include "splash.h"
#include "loginsystem.h"
#include "menu.h"


int main(void)
{
    screen();
    int choice;
    //Main Menu
    do {
        printf("                      ---------------------------Welcome to the Bank of TND ---------------------------\n");
        printf("\n\t\t\t\t\t\t\tMain Menu\n");
        printf("\t\t\t\t\t\t1. Create Account\n");
        printf("\t\t\t\t\t\t2. Deposit\n");
        printf("\t\t\t\t\t\t3. Withdraw\n");
        printf("\t\t\t\t\t\t4. Transfer\n");
        printf("\t\t\t\t\t\t5. Check Balance\n");
        printf("\t\t\t\t\t\t6. Delete Account\n");
        printf("\t\t\t\t\t\t7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createaccount();
                break;
            case 2:
                depositmoney();
                break;
            case 3:
                withdrawmoney();
                break;
            case 4:
                transfermoney();
                break;
            case 5:
                checkbalance();
                break;
            case 6:
                accountdeletion();
                break;
            case 7:
                printf("Thank you for using our banking system!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

  return 0;
}