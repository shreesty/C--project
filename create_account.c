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
void accountCreate()
{
    int status_Account=1;
    FILE *p;
    p=fopen("record.txt","a+");
    printf("\nEnter the account number:");
    scanf("%d",&newAccount.acc_no);
    while(fscanf(p,"%d %s %f %d ",&add_NewAccount.acc_no,&add_NewAccount.name,&add_NewAccount.amt,&add_NewAccount.pincode)!=EOF)
    {
        if (newAccount.acc_no==add_NewAccount.acc_no)
        {
            printf("Account no. already in use!");
            status_Account=0;
            //break;
        }
    }
    if(status_Account==1)
    {
        add_NewAccount.acc_no=newAccount.acc_no;
        //fflush(stdin);
        printf("\nEnter the name:");

        scanf("%s",&add_NewAccount.name);
        printf("\nEnter the amount for deposit:");
        scanf("%f",&add_NewAccount.amt);
        printf("Enter the pincode: ");
        scanf("%d",&add_NewAccount.pincode);
        fprintf(p,"%d %s %.2f %d\n",add_NewAccount.acc_no,add_NewAccount.name,add_NewAccount.amt,add_NewAccount.pincode);
        fclose(p);
        printf("\nAccount created successfully!");
    }
}
int main()
{
    accountCreate();   
}