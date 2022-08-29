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
Account add_NewAccount,newAccount,transaction,add;
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
void fastCash()
{
     fflush(stdin);
     int option,status=1,amountTaken;
    FILE *old,*newrec;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");
    printf("Enter your account number: ");
    scanf("%d",&add.acc_no);
    printf("Enter your pincode: ");
    scanf("%d",&add.pincode);
    while(fscanf(old,"%d %s %f %d ",&newAccount.acc_no,&newAccount.name,&newAccount.amt,&newAccount.pincode)!=EOF)
    {
        if (newAccount.acc_no==add.acc_no && newAccount.pincode==add.pincode)
        {
            printf("1: 1000\n \2: 2000 \n 3: 5000\n 4: 15000\n");
    printf("Choose one of the options for what amount of money you wanna get: \n");
    scanf("%d",&option);
    switch(option)
    {
        case 1:
            printf("RS 1000\n");
            printf("Collect RS 1000 and your card\n");
            printf("Thankyou for banking with us, Please visit again.\n");
            transaction.amt=1000;
            break;

        case 2:
            printf("RS 2000\n");
            printf("Collect RS 2000 and your card\n");
            printf("Thankyou for banking with us, Please visit again.\n");
            transaction.amt=2000;
            break;

        case 3:
            printf("RS 5000\n");
            printf("Collect RS 5000 and your card\n");
            printf("Thankyou for banking with us, Please visit again.\n");
            transaction.amt=5000;
            break;

        case 4:
            printf("RS 15000\n");
            printf("Collect RS 15000 and your card\n");
            printf("Thankyou for banking with us, Please visit again.\n");
            transaction.amt=15000;
            break;

        default:
            printf("Invalid option.\n");
            status=0;
            break;
    }
                    newAccount.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %f %d ",newAccount.acc_no,newAccount.name,newAccount.amt,newAccount.pincode);
        }
    }
    fclose(old);
   fclose(newrec);
   remove("record.txt");
   rename("new.txt","record.txt");



}
void cashWithdraw()
{
    fflush(stdin);
    FILE *old,*newrec;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");
    printf("Enter your account number: ");
    scanf("%d",&add.acc_no);
    printf("Enter your pincode: ");
    scanf("%d",&add.pincode);
    while(fscanf(old,"%d %s %f %d ",&newAccount.acc_no,&newAccount.name,&newAccount.amt,&newAccount.pincode)!=EOF)
    {
        if (newAccount.acc_no==add.acc_no && newAccount.pincode==add.pincode)
        {
            printf("Enter the amount you want to withdraw:$ ");
                    scanf("%f",&transaction.amt);
                    newAccount.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %f %d ",newAccount.acc_no,newAccount.name,newAccount.amt,newAccount.pincode);
        }
    }
    fclose(old);
   fclose(newrec);
   remove("record.txt");
   rename("new.txt","record.txt");
}

void balanceEnquiery()
{
   FILE *old;
    old=fopen("record.txt","r");
    //newrec=fopen("new.txt","w");
    printf("Enter your account number: ");
    scanf("%d",&add.acc_no);
    printf("Enter your pincode: ");
    scanf("%d",&add.pincode);
    while(fscanf(old,"%d %s %f %d ",&newAccount.acc_no,&newAccount.name,&newAccount.amt,&newAccount.pincode)!=EOF)
    {
        if (newAccount.acc_no==add.acc_no && newAccount.pincode==add.pincode)
        {
            printf("\nBalance is %.2f",newAccount.amt);
        }
    }
    fclose(old);
}

void changePin()
{
    FILE *old,*newrec;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");
    printf("Enter your account number: ");
    scanf("%d",&add.acc_no);
    printf("Enter your pincode: ");
    scanf("%d",&add.pincode);
    while(fscanf(old,"%d %s %f %d ",&newAccount.acc_no,&newAccount.name,&newAccount.amt,&newAccount.pincode)!=EOF)
    {
        if (newAccount.acc_no==add.acc_no && newAccount.pincode==add.pincode)
        {
            printf("Enter your old pincode: ");
            scanf("%d",&transaction.pincode);
            if(transaction.pincode==newAccount.pincode)
            {
                printf("Enter your new pincode: ");
                scanf("%d",&transaction.pincode);
                fprintf(newrec,"%d %s %f %d ",newAccount.acc_no,newAccount.name,newAccount.amt,transaction.pincode);
		        printf("Pincode Sucessfully changed\n");

            }
        }
    }
    fclose(old);
   fclose(newrec);
   remove("record.txt");
   rename("new.txt","record.txt");


}
void transact()
{
    FILE *old,*newrec;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");
    printf("Enter your account number: ");
    scanf("%d",&add.acc_no);
    printf("Enter your pincode: ");
    scanf("%d",&add.pincode);
    while(fscanf(old,"%d %s %f %d ",&newAccount.acc_no,&newAccount.name,&newAccount.amt,&newAccount.pincode)!=EOF)
    {
        if (newAccount.acc_no==add.acc_no && newAccount.pincode==add.pincode)
        {
            printf("Enter the amount you want to withdraw:$ ");
                    scanf("%f",&transaction.amt);
                    newAccount.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %f %d ",newAccount.acc_no,newAccount.name,newAccount.amt,newAccount.pincode);
        }
    }
    fclose(old);
   fclose(newrec);
   remove("record.txt");
   rename("new.txt","record.txt");
}
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
            fclose(p);
            if(choice==1)
            {
                fastCash();
            }
            else if(choice==2)
            {
                cashWithdraw();
            }
            else if(choice==3)
            {
                balanceEnquiery();
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
//*/
int main()
{
    system("color 3F");
    int choice;
    printf("Enter\n1 for account creation\n2 for transaction\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        accountCreate();
    break;

    case 2:
        Transaction();
        //transact();
        //changePin();
        //balanceEnquiery();
    break;

    default:
        printf("Invalid");
    }

    printf("\n");
    return 0;
}
