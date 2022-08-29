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

void balanceEnquiery(int accNt,int pinCodes)
{
    FILE*p;
     p=fopen("record.txt","a+");
     while(fscanf(p,"%d %s %f %d ",&newAccount.acc_no,&newAccount.name,&newAccount.amt,&newAccount.pincode)!=EOF)
    {
        if (newAccount.acc_no==accNt && newAccount.pincode==pinCodes)
        {
            printf("Your balance is %f",newAccount.amt);
        }
    }

}
int main()
{
    int accNt,pinCodes;
    balanceEnquiery(accNt,pinCodes);

}
