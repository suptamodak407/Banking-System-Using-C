
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//Functions
void menu();
void login();
void reset();
void newacc();
void transaction();
void mainMenu();
void checkBalance();
void moneyDeposit();
void moneyWithdraw();
void menuExit();
void errorMessage();
void loginmenu();
void loginmenu2();

//Main Code
void menu() {
    int option;
    int choose;
    bool again = true;
    
    while (again) {
    mainMenu();
    
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("Your Selection:\t");
    scanf("%d", &option);
    
    
        switch (option) {
            case 1:
            	system("CLS");
                checkBalance();
                break;
            case 2:
            	system("CLS");
                moneyDeposit();
                break;
            case 3:
            	system("CLS");
                moneyWithdraw();
                break;
            
            case 4:
            	system("CLS");
                transaction();
                break; 

            case 5:
            	system("CLS");
                reset();
                break; 

            case 6:
                system("CLS");
                menuExit();
                return 0;    
            default:
                errorMessage();
                break;
        }
        
        printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("Would you like to do another transaction:\n");
        printf("< 1 > Yes\n");
        printf("< 2 > No\n");
        scanf("%d", &choose);
        
        system("CLS");
        
        
        
        if (choose == 2) {
            again = false;
            menuExit();
            
        }
    }
    //return 0;
}//main code

//Functions

void mainMenu() {
    
    printf("******************Hello!*******************\n");
    printf("**********Welcome to ATM Banking System***********\n\n");
    printf("****Please choose one of the options below****\n\n");
    printf("< 1 >  Check Balance\n");
    printf("< 2 >  Deposit\n");
    printf("< 3 >  Withdraw\n");
    printf("< 4 >  Transaction\n");
    printf("< 5 >  Change PIN\n");
    printf("< 6 >  Logout\n\n");
    
}//Main Menu

void checkBalance() {
    double bal;
    FILE *fp;
    fp = fopen("balance.txt","r");
    printf("You Choose to See your Balance\n");
    fscanf(fp,"%lf",&bal);
    printf("\n\n****Your Available Balance is:   $%.2f\n\n", bal);
    
    fclose(fp);
}//Check Balance

void moneyDeposit() {
    double bal1;
    double dep;
    double deposit;
    FILE *fp;
    fp = fopen("balance.txt","r");
    fscanf(fp,"%lf",&bal1);
    printf("You choose to Deposit a money\n");
    printf("****Your Balance is: $%.2f\n\n", bal1);
    fclose(fp);
    printf("****Enter your amount to Deposit\n");
    scanf("%lf", &deposit);
    dep=(bal1 += deposit);
    printf("\n****Your New Balance is:   $%.2f\n\n", dep);
    fp = fopen("balance.txt","w");
    fprintf(fp,"%.2f",dep);
    fclose(fp);
    FILE *fp2;
    fp2 = fopen("transactions.txt","a+");
    fprintf(fp2,"%.2f CR\n",deposit);
    fclose(fp2);

}//money deposit

void moneyWithdraw() {
    double withdraw;
    double bal2;
    double with;
    bool back = true;
    FILE *fp;
    fp = fopen("balance.txt","r");
    fscanf(fp,"%lf",&bal2);
    printf("You choose to Withdraw a money\n");
    printf("****Your Balance is: $%.2f\n\n", bal2);
    fclose(fp);
    while (back) {
    printf("Enter your amount to withdraw:\n");
    scanf("%lf", &withdraw);
    if (withdraw < bal2) {
        back = false;
        bal2 -= withdraw;
        printf("\n****Your withdrawing money is:  $%.2f\n", withdraw);
        printf("****Your New Balance is:   $%.2f\n\n", bal2);
    }
        else  {
        
        printf("+++You don't have enough money+++\n");
        printf("Please contact to your Bank Customer Services\n");
        printf("****Your Balance is:   $%.2f\n\n", bal2);
        
    }
    }
    fp = fopen("balance.txt","w");
    fprintf(fp,"%.2f",bal2);
    fclose(fp);
    FILE *fp2;
    fp2 = fopen("transactions.txt","a+");
    fprintf(fp2,"%.2f DR\n",withdraw);
    fclose(fp2);
}//money withdraw

void transaction() {
    char bal3;
    FILE *fp2=NULL;
    fp2 = fopen("transactions.txt","r");
    
    printf("Previous Transactions:-\n\n");
    while(bal3!=EOF){
        printf("%c",bal3);
        bal3=fgetc(fp2);
    }
    fclose(fp2);
}
// money transaction

void loginmenu() {
    int option;
    printf("******************Hello!*******************\n");
    printf("**********Welcome to ATM Banking System***********\n\n");
    printf("****Please choose one of the options below****\n\n");
    printf("< 1 >  Create New Account\n");
    printf("< 2 >  Login\n");
    printf("< 3 >  Logout\n\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("Your Selection:\t");
    scanf("%d", &option);
    
    
        switch (option) {
            case 1:
            	system("CLS");
                newacc();
                break;
            case 2:
            	system("CLS");
                login();
                break;
            case 3:
                system("CLS");
                menuExit();
                return 0;    
            default:
                errorMessage();
                break;
        }
        system("CLS");
    //return 0;
}//loginmenu

void loginmenu2() {
    int option;
    printf("******************Hello!*******************\n");
    printf("**********Welcome to ATM Banking System***********\n\n");
    printf("****Please choose one of the options below****\n\n");
    printf("< 1 >  Login\n");
    printf("< 2 >  Logout\n\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("Your Selection:\t");
    scanf("%d", &option);
    
    
        switch (option) {
            case 1:
            	system("CLS");
                login();
                break;
            case 2:
                system("CLS");
                menuExit();
                return 0;    
            default:
                errorMessage();
                break;
        }
        system("CLS");
    //return 0;
}//loginmenu2


void newacc(){
    FILE *fp4;
    int i=2,e=0000;
    double bal5,c;
    fp4=fopen("admin.txt","w");
    fprintf(fp4,"%d",e);
    fclose(fp4);
    fp4=fopen("admin.txt","r");
    fscanf(fp4,"%lf",&bal5);
    d:
    printf("Enter admin PIN:-");
    scanf("%lf",&c);
    system("CLS");
    if(bal5==c){
        double pin=1234,balance = 15000;;
        FILE *fp3;
        fp3 = fopen("login.txt","w");
        fprintf(fp3,"%.f",pin);
        fclose(fp3);
        
        FILE *fp;
        fp = fopen("balance.txt","w");
        fprintf(fp,"%.f",balance);
        fclose(fp);

        FILE *fp2;
        fp2 = fopen("transactions.txt","w");
        fclose(fp2);
        loginmenu2();
    }
    else
    {
        printf("\nYou entered a wrong PIN!\n\n");
        printf("You have %d chances left.\n\n",i);

        if( i > 0 ){
            i--; 
            goto d;
        }
        else
            loginmenu();
    }
    fclose(fp4);
}//newacc

void login(){
    int i = 2;
    double bal4, a;
    FILE *fp3;
    fp3=fopen("login.txt","r");
    fscanf(fp3,"%lf",&bal4);
    b:
    printf("Enter your PIN:-");
    scanf("%lf",&a);
    system("CLS");
    if (bal4==a)
    {
        menu();
    }
    else
    {
        printf("\nYou entered a wrong PIN!\n\n");
        printf("You have %d chances left.\n\n",i);

        if( i > 0 ){
            i--; 
            goto b;
        }
        else
            loginmenu();
    }
    fclose(fp3);
}//login

void reset(){
    double a;
    printf("Enter Your New PIN:-");
    FILE *fp3;
    scanf("%lf",&a);
    fp3 = fopen("login.txt","w");
    fprintf(fp3,"%.f",a);
    fclose(fp3);
    system("CLS");
    printf("\nYou PIN is successfully changed!\n\n");
}//reset pin

void menuExit() {
    printf("--------------Take your receipt!!!------------------\n");
    printf("-----Thank you for using Banking System!!!-----\n"); 
}//exit menu

void errorMessage() {;
    printf("+++!!!You selected invalid number!!!+++\n");
}//error message

int main(){
    loginmenu();
    return 0;
}
