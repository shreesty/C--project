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

void fastCash(int acNt,int pincode)
{
    int option,status=1,amountTaken;
    printf("1: 1000\n \2: 2000 \n 3: 5000\n 4: 15000\n");
    printf("Choose one of the options for what amount of money you wanna get: \n");
    scanf("%d",&option);
    switch(option)
    {
        case 1:
            printf("RS 1000\n");
            printf("Collect RS 1000 and your card\n");
            printf("Thankyou for banking with us, Please visit again.\n");
            amountTaken=1000;
            break;

        case 2:
            printf("RS 2000\n");
            printf("Collect RS 2000 and your card\n");
            printf("Thankyou for banking with us, Please visit again.\n");
            amountTaken=2000;
            break;

        case 3:
            printf("RS 5000\n");
            printf("Collect RS 5000 and your card\n");
            printf("Thankyou for banking with us, Please visit again.\n");
            amountTaken=5000;
            break;

        case 4:
            printf("RS 15000\n");
            printf("Collect RS 15000 and your card\n");
            printf("Thankyou for banking with us, Please visit again.\n");
            amountTaken=15000;
            break;

        default:
            printf("Invalid option.\n");
            status=0;
            break;
    }
}
int main()
{
    int eAccountNum,ePincode;
    fastCash(eAccountNum,ePincode);
}