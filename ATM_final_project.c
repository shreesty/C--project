#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>

void accountCreate();
void fastCash();
void cashWithdraw();
void balanceEnquiery();
void changePin();
void Transaction();

int main()
{
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
int amount_in_ATM=500000,amount_in_account=50000, amount_to_withdraw;
typedef struct
{
    char first_name[60];
    char last_name[60];
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
    srand(time(0));
    newAccount.acc_no= rand()%10000 + 1;   
    printf("Account number: %d\n",newAccount.acc_no);
    
    while(fscanf(p,"%d %s %s %f %d ",&add_NewAccount.acc_no,&add_NewAccount.first_name,&add_NewAccount.last_name,&add_NewAccount.amt,&add_NewAccount.pincode)!=EOF)
    {
        if (newAccount.acc_no==add_NewAccount.acc_no)
        {
            printf("Account no. already in use!\n");
            status_Account=0;
            //break;
        }
    }
    if(status_Account==1)
    {
        add_NewAccount.acc_no=newAccount.acc_no;
        printf("\nEnter the first name:");
        //scanf("%[^\n]%*c", &add_NewAccount.name);
        //fgets(add_NewAccount.name,60,stdin);
        //getchar();
        //scanf("%[^\n]*c",&add_NewAccount.name);
        scanf("%s",add_NewAccount.first_name);
        printf("\nEnter the last name:");
        scanf("%s",add_NewAccount.last_name);
        printf("\nEnter the amount for deposit:");
        //fflush(stdin);
        scanf("%f",&add_NewAccount.amt);
        printf("Enter the pincode: ");
        scanf("%d",&add_NewAccount.pincode);
        fprintf(p,"%d %s %s %.2f %d\n",add_NewAccount.acc_no,add_NewAccount.first_name,&add_NewAccount.last_name,add_NewAccount.amt,add_NewAccount.pincode);
        fclose(p);
        system("cls");/*clear output screen*/
        printf("\nAccount created successfully!\n");
    }
}

void fastCash()
{
    fflush(stdin);
    int option,status=1,amountTaken;
    FILE *old,*newrec;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");
    

    while(fscanf(old,"%d %s %s %f %d ",&newAccount.acc_no,&newAccount.first_name,newAccount.last_name,&newAccount.amt,&newAccount.pincode)!=EOF)
    {
            printf(" 1: 1000\n 2: 2000 \n 3: 5000\n 4: 15000\n");
            printf("Choose one of the options for what amount of money you wanna get: \n");
            scanf("%d",&option);
            switch(option)
            {
            case 1:
                
                transaction.amt=1000;
                if(transaction.amt<=newAccount.amt)
                {
                    printf("RS 1000\n");
                    printf("Collect RS 1000 and your card\n");
                    printf("Thankyou for banking with us, Please visit again.\n");
                }
                else
                {
                    status=0;
                    printf("Insufficient Balance");
                }
                break;

            case 2:
                transaction.amt=2000;
                if(transaction.amt<newAccount.amt)
                {
                    printf("RS 2000\n");
                    printf("Collect RS 2000 and your card\n");
                    printf("Thankyou for banking with us, Please visit again.\n");
                }
                else
                {
                    status=0;
                    printf("Insufficient Balance");
                }
                break;

            case 3:
                transaction.amt=5000;
                if(transaction.amt<newAccount.amt)
                {
                    printf("RS 5000\n");
                    printf("Collect RS 5000 and your card\n");
                    printf("Thankyou for banking with us, Please visit again.\n");
                }
                else
                {
                    status=0;
                    printf("Insufficient Balance");
                }
                break;

            case 4:
                transaction.amt=15000;
                if(transaction.amt<newAccount.amt)
                {
                printf("RS 15000\n");
                printf("Collect RS 15000 and your card\n");
                printf("Thankyou for banking with us, Please visit again.\n");
                }
                else
                {
                    status=0;
                    printf("Insufficient Balance");
                } 
                break;

            default:
                printf("Invalid option.\n");
                status=0;
                break;
            }
            if(status!=0)
            {
                newAccount.amt-=transaction.amt;
            fprintf(newrec,"%d %s %s %f %d ",newAccount.acc_no,newAccount.first_name,newAccount.last_name,newAccount.amt,newAccount.pincode);
        
            }
            
        else
        {
            printf("\nInvalid");
            status=0;
        }
    }
    fclose(old);
    fclose(newrec);
    if(status!=0)
    {
        remove("record.txt");
        rename("new.txt","record.txt");
    }
}

void cashWithdraw()
{
    fflush(stdin);
    int status=1;
    FILE *old,*newrec;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");
    while(fscanf(old,"%d %s %s %f %d ",&newAccount.acc_no,&newAccount.first_name,newAccount.last_name,&newAccount.amt,&newAccount.pincode)!=EOF)
    {
            printf("Enter the amount you want to withdraw:Rs. ");
                    scanf("%f",&transaction.amt);
             if((int)transaction.amt %500==0)
             {
                if((int)transaction.amt<newAccount.amt)
                {
                    newAccount.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %s %f %d ",newAccount.acc_no,newAccount.first_name,newAccount.last_name,newAccount.amt,newAccount.pincode);
                    status=1;
                    printf("Collect your money and card\n");
                    printf("Please visit again");
                }
                else
                {
                    status=0;
                    printf("\nInsufficient Balance");
                }
             }
             else
             {
                 printf("\nOnly divisible by 500 is supported!");
                 status=0;
             }
    }
    fclose(old);
   fclose(newrec);
   if(status!=0)
   {
       remove("record.txt");
   rename("new.txt","record.txt");
   }
}
void balanceEnquiery()
{
   FILE *old;
    old=fopen("record.txt","r");
    //newrec=fopen("new.txt","w");
    while(fscanf(old,"%d %s %s %f %d ",&newAccount.acc_no,&newAccount.first_name,newAccount.last_name,&newAccount.amt,&newAccount.pincode)!=EOF)
    {
            printf("\nBalance is %.2f",newAccount.amt);
        
    }
    fclose(old);
}
void changePin()
{
    FILE *old,*newrec;
    old=fopen("record.txt","r");
    newrec=fopen("new.txt","w");
    while(fscanf(old,"%d %s %s %f %d ",&newAccount.acc_no,&newAccount.first_name,newAccount.last_name,&newAccount.amt,&newAccount.pincode)!=EOF)
    {
            printf("Enter your old pincode: ");
            scanf("%d",&transaction.pincode);
            if(transaction.pincode==newAccount.pincode)
            {
                printf("Enter your new pincode: ");
                scanf("%d",&transaction.pincode);
                fprintf(newrec,"%d %s %s %f %d ",newAccount.acc_no,newAccount.first_name,newAccount.last_name,newAccount.amt,transaction.pincode);
		        printf("Pincode Sucessfully changed\n");

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
    while(fscanf(p,"%d %s %s %f %d ",&newAccount.acc_no,&newAccount.first_name,newAccount.last_name,&newAccount.amt,&newAccount.pincode)!=EOF)
    {
        if (newAccount.acc_no==eAccountNum && newAccount.pincode==ePincode)
        {
            printf("\nDetails matched");
            system("cls");/*clear output screen*/
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
              system("cls");/*clear output screen*/
                printf("Pin code Mismatch\n");
              
            }
            pinAttempt++;
            fclose(p);
    }
    while(pinAttempt<=3 && status==0);
}

