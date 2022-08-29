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

void Transaction()
{
    FILE *p;
    int status;
    int pinAttempt=1;
    int choice,eAccountNum,ePincode;
    do
    {
        p=fopen("record.txt","a+");
    printf("Enter your account number: ");
    scanf("%d",&eAccountNum);
    printf("Enter your pincode: ");
    scanf("%d",&ePincode);
    while(fscanf(p,"%d %s %f %d ",&newAccount.acc_no,&newAccount.name,&newAccount.amt,&newAccount.pincode)!=EOF)
    {
        if (newAccount.acc_no==eAccountNum && newAccount.pincode==ePincode)
        {
            printf("\nDetails matched");
            time_t now;
            time(&now);
            printf("\n%s\n",ctime(&now));

            status=1;
            printf("\nEnter\n1 for fast cash\n2 for cash withdraw\n3 for balance enquiry\n4 pin change\n");
		    scanf("%d",&choice);

            if(choice==1)
            {
                fastCash(eAccountNum,ePincode);
            }
            else if(choice==2)
            {
                cashWithdraw();
            }
            else if(choice==3)
            {
                balanceEnquiery(eAccountNum,ePincode);
            }
            else if(choice==4)
            {
                changePin();
            }
                break;
        }
            else
            {
                status=0;
               //printf("Mismatch");
            }
    }
            if(status==0)
            {
                printf("Mismatch");
            }
            pinAttempt++;
            fclose(p);
    }while(pinAttempt<=3 && status==0);

}
void fastCash(eAccountNum,ePincode)
{
    ///////////
}

void cashWithdraw()
{
    ///////////
}

void balanceEnquiery(eAccountNum,ePincode)
{
    /////////////
}

void changePin()
{
    ///////////
}

int main()
{
    int eAccountNum,ePincode,eAccountNum,ePincode;
    Transaction();
    fastCash(eAccountNum,ePincode);
    cashWithdraw();
    balanceEnquiery(eAccountNum,ePincode);
    changePin();
}

