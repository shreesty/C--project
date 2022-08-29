#include<stdio.h>
#include<windows.h>
#include<time.h>
int amount_in_ATM=500000,amount_in_account=50000, amount_to_withdraw;
struct account_details
{
    //Account details:
    float amount;
    int account_number,pincode;
    char account_holder_name[20];
    int account_holder_age;
};
void fastCash()
{   
    int option;
    printf("1: 1000\n 2: 2000 \n 3: 5000\n 4: 15000\n");
    printf("Choose one of the options for what amount of money you wanna get: \n");
    scanf("%d",&option);
    switch(option)
    {
        case 1:
            printf("RS 1000\n");
            printf("Collect RS 1000 and your card\n");
            printf("Thankyou for banking with us, Please visit again.\n");
            break;

        case 2:
            printf("RS 2000\n");
            printf("Collect RS 2000 and your card\n");
            printf("Thankyou for banking with us, Please visit again.\n");
            break;

        case 3:
            printf("RS 5000\n");
            printf("Collect RS 5000 and your card\n");
            printf("Thankyou for banking with us, Please visit again.\n");
            break;

        case 4:
            printf("RS 15000\n");
            printf("Collect RS 15000 and your card\n");
            printf("Thankyou for banking with us, Please visit again.\n");
            break;

        default:
            printf("Invalid option.\n");
            break;
    }
}
void cashWithdraw()
{
    while(amount_to_withdraw % 500!=0)
    {
        printf("Enter the amount to withdraw: ");
        scanf("%d",&amount_to_withdraw);

        if(amount_to_withdraw % 500!=0)
        {
            printf("The amount of money to be withdraw must be multiple of 500\n.");
        }
    }
    if(amount_to_withdraw > amount_in_ATM)
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
        amount_in_account = amount_in_account - amount_to_withdraw;   
    }
}
void balanceEnquiery()
{
    printf("%d",amount_in_account);
    /////////////////////////////////////////////////////////
    printf("\nYo ho balanceEquiery");
}
void changePin()
{
    int old_pincode=1234,old_pin,new_pin;
    
while(old_pincode != old_pin)
    {
        printf("Enter your old pin:");
        scanf("%d",&old_pin);
        if(old_pincode != old_pin)
        {
            printf("Wrong pin.\n");
            Beep(610,1000);
        }
    }

    if(old_pin==old_pincode)
    {
        printf("Enter your new pin:");
        scanf("%d",&new_pin);
        printf("Your updated pin code is %d",new_pin);
    }
    else
    {
        printf("Try again");
    }
}
void accountCreate()
{
    struct account_details s[10];
    int i;
    for(i=0; i<10; i++)
    {
        printf("Enter the account number");
        scanf("%d",&s[i].account_number);
        printf("Entered account number is %d\n",s[i].account_number);

        printf("Enter the account holder's name");
        scanf("%s",&s[i].account_holder_name);
        printf("Entered account_holders name is %s\n",s[i].account_holder_name);

        printf("Enter the account holder's age");
        scanf("%d",&s[i].account_holder_age);
        printf("Entered account holder's age is %d\n",s[i].account_holder_age);
    }
}
int main()
{
    system("color 3F");
    int attempt=1;
    //Creating new bank account

    struct account_details s[10];
    int i=0,j,status=0,pinCode=1234,choice;
    int choiceTransaction;
    printf("Enter\n1 for account creating\n2 for amt transaction\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        accountCreate();
        break;

    case 2:
        do
        {
            printf("Enter the pincode");
            scanf("%d",&s[i].pincode);
            printf("Entered pin code is %d\n",s[i].pincode);
            if(pinCode==s[i].pincode)
            {
                status=1;

                printf("Pincode match!\n");
                time_t now;
                time(&now);
                printf("\n%s\n",ctime(&now));

                printf("------------------------------- Welcome to Global IME bank Limited!--------------------------\n");
                printf("\n1 for fast cash\n2 for cash withdraw\n3 for balanceEnquiery\n4 for changing pincode");
                printf("\n\nEnter a number from 1 to 4: ");
                scanf("%d",&choiceTransaction);
                switch(choiceTransaction)
                {
                case 1:
                    fastCash();
                break;

                case 2:
                    cashWithdraw();
                break;

                case 3:
                    balanceEnquiery();
                    break;

                case 4:
                    changePin();
                    break;
                }
            }
            else
            {
                status=0;
                Beep(610,500);
                printf("\nPincode mismatch!\n");
            }
            attempt++;
            i++;
        }
        while(attempt<=3 && status==0);
    break;
    default:
        printf("Invalid");
    }
}