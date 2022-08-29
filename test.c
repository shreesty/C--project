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
    if(status==1)
    {
        FILE*p;
        p=fopen("record.txt","a+");
        while(fscanf(p,"%d %s %f %d ",&newAccount.acc_no,&newAccount.name,&newAccount.amt,&newAccount.pincode)!=EOF)
        {
            if (newAccount.acc_no==acNt && newAccount.pincode==pincode)
            {
/*
               printf("\n\tSuruma %d %s %f %d",newAccount.acc_no,newAccount.name,newAccount.amt,newAccount.pincode);
                newAccount.amt=newAccount.amt-amountTaken;
                fseek(p,-1,SEEK_CUR);
               fprintf(p,"%d %s %f %d",newAccount.acc_no,newAccount.name,newAccount.amt,newAccount.pincode);
                fseek(p,0,SEEK_CUR);
               //printf("\n\tSuruma %d %s %f %d",newAccount.acc_no,newAccount.name,newAccount.amt,newAccount.pincode);

                //newAccount.amt=amountTaken;
                //fprintf(p,"%d %s %.2f %d\n",add_NewAccount.acc_no,add_NewAccount.name,add_NewAccount.amt,add_NewAccount.pincode);
                */
            }
        }
        fclose(p);
    }
}
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
    break;

    default:
        printf("Invalid");
    }

    printf("\n");
    return 0;
}
