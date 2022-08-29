#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<time.h>

int amount_in_ATM=500000,amount_in_account=50000, amount_to_withdraw;
typedef struct
{
    char name[60];
    int acc_no;
    int pincode;
    float amt;
}Account;
Account add_NewAccount,newAccount;

void cashWithdraw()
{
    printf("Enter the amount to withdraw: ");
    scanf("%d",&amount_to_withdraw);

    if(amount_to_withdraw % 500!=0)
    {
        printf("The amount of money to be withdraw must be multiple of 500\n.");
    }
    else if(amount_to_withdraw > amount_in_ATM)
    {
        printf("Sorry for inconvinence. We cannot process your request\n");
    }

    else if(amount_in_account< amount_to_withdraw)
    {
        printf("Insufficient balance\n");
    }

    else if(amount_to_withdraw >20000)
    {
        printf("Amount can not be more than 20k.\n");
    }
    else
    {
        printf("Collect RS %d and your card\n",amount_to_withdraw);
        printf("Thankyou for banking with us, Please visit again.\n");
    }
    amount_in_account = amount_in_account - amount_to_withdraw;
}
int main()
{
    cashWithdraw();
}