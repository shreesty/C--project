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

void changePin()
{
    int eAccountNum,ePincode;
    FILE*p;
    int old_pincode=1234,old_pin,new_pin;
    int count=1,status=1;
        printf("Enter your account number: ");
        scanf("%d",&eAccountNum);
        printf("Enter your pincode: ");
        scanf("%d",&ePincode);
        do
        {

    p=fopen("record.txt","a+");

    printf("Enter your old pin:");
    scanf("%d",&old_pin);
        while(fscanf(p,"%d %s %f %d ",&newAccount.acc_no,&newAccount.name,&newAccount.amt,&newAccount.pincode)!=EOF)
        {
            if (newAccount.acc_no==eAccountNum && newAccount.pincode==ePincode)
            {

                if(old_pin==newAccount.pincode)
                {
                    printf("\nEnter new pin: ");
                    scanf("%d",&new_pin);
                    printf("Your updated pin code is %d",new_pin);
                    status=2;
                    break;
                }
                else
                {
                    printf("Not matched");
                    status=0;
                }
                count++;
            }

        }
        fclose(p);
        }
        while(status==0 && count<=3);
}
int main()
{
    changePin();
}