#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<dos.h>
int num=1;
char A1='*',B1='*',C1='*',D1='*',E1='*';
char A2='*',B2='*',C2='*',D2='*',E2='*';
char A3='*',B3='*',C3='*',D3='*',E3='*';
char A4='*',B4='*',C4='*',D4='*',E4='*';
char A5='*',B5='*',C5='*',D5='*',E5='*';
char A6='*',B6='*',C6='*',D6='*',E6='*';
char A7='*',B7='*',C7='*',D7='*',E7='*';
char A8='*',B8='*',C8='*',D8='*',E8='*';
char A9='*',B9='*',C9='*',D9='*',E9='*';
char A10='*',B10='*',C10='*',D10='*',E10='*';
//Function Prototype
void admin_pass();
void welcome();
void welcome1();
void entry();
void booking();
void seats_avai();
void seats_seen();
void timetable();
void cancel();
void news_add();
void news_dis();
void savefile();
void display();
void details();
void cus_login();
void reserve(int x);
void exit1();
void seat_display(int s);
void gotoxy(int x,int y){
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

struct airport
{
	int passport;
	char name[15];
    char destination[15];
	int seat_num;
	char email[15];
    int seat_total;
    int seat_select;
	struct airport *counter;
}
*begin, *stream;
struct airport *sample;

//Execution Started
int main(){
    system("cls");
    system("color B");
    Sleep(1850);
    welcome();
     gotoxy(55,24);
     for(int j=0;j<=100;j++){
		Sleep(5);
		printf("\xDB");
	}
    gotoxy(85,27);
    printf("Press any key to continue ....");
    getch();
    welcome1();
    return 0;
}
void welcome1(){
    int i;    
     system("cls");
    gotoxy(83,12);
    Sleep(50);
    printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Welcome to VIPROS Airport: \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
    gotoxy(99,15);
    printf("Login:");
    gotoxy(84,18);
    printf("1.Admin");
    gotoxy(84,21);
    printf("2.Customer");
    gotoxy(84,24);
    printf("3.Exit");
    gotoxy(84,27);
    printf("Choose anyone option from above:\t");
    scanf("%d",&i);
    switch (i)
    {
    case 1:
    gotoxy(55,34);
    for(int j=0;j<=100;j++){
		Sleep(5);
		printf("\xDB");
	}
        admin_pass();
        break;
    case 2:
    gotoxy(55,34);
    for(int j=0;j<=100;j++){
		Sleep(5);
		printf("\xDB");
	}
        cus_login();
        break;
    default:
    exit1();
    break;    
    }
    
}

void welcome(){
    printf("\n\n\n");
    printf("\t\t\t\t\t*       *    *     * * * *    * * * *   * * * *   * * * *            *      * * * * *   * * * *  * * * *  * * * *  * * * *  * * * * *       \n");
    printf(" \t\t\t\t\t*     *     *     *     *    *     *   *     *   *                 * *         *       *     *  *     *  *     *  *     *      *        \n");
    printf("  \t\t\t\t\t*   *      *     * * * *    * * * *   *     *   * * * *          * * *        *       * * * *  * * * *  *     *  * * * *      *       \n");
    printf("   \t\t\t\t\t* *       *     *          * *       *     *         *         *     *       *       * *      *        *     *  * *          *     \n");
    printf("    \t\t\t\t\t*        *     *          *   *     * * * *   * * * *        *       *  * * * * *   *   *    *        * * * *  *   *        *     ");
}
//Admin Login
void admin_pass(){
    char password[26]="Sujay-Deshpande";
    char enter_pass[26],pass1,w='*';
    int again,i=0;
    system("cls");
    welcome();
    gotoxy(83,12);
    printf("Welcome, Admin!");
    gotoxy(90,14);
    printf("Enter password:");
	while(pass1!=13){
		pass1=getch();
		if(pass1!=13 && pass1!=8){
			printf("%c",w);
			enter_pass[i]=pass1;
			i++;
		}
		}
        enter_pass[i]='\0';
    if(strcmp(password,enter_pass)==0)
    {
        printf("\nEntered successfully!");
        entry();
    }
    else{
        gotoxy(92,19);
        printf("Try again!");
        getch();
        main();
    }
    
}
//Customer Login
void cus_login(){
char password[21]="customer";
    char enter_pass[21],pass1,w='*',user[20];
    int again,i=0;
    system("cls");
    welcome();
    gotoxy(83,14);
    printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Customer Login: \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
   gotoxy(84,17);
    printf("Enter Username:");
    scanf("%s",user);
    gotoxy(84,18);
    if(strcmp(user,"vipros")==0){
    // After completion
    printf("Enter password:");
	while(pass1!=13){
		pass1=getch();
		if(pass1!=13 && pass1!=8){
			printf("%c",w);
			enter_pass[i]=pass1;
			i++;
		}
		}
        enter_pass[i]='\0';
    if(strcmp(password,enter_pass)==0)
    {
        printf("\nEntered successfully!");
        system("cls");
        timetable();
        getch();
    }
    else{
        printf("\nTry again!");
        getch();
        welcome1();
    }}
    else{
        printf("\nEnter correct username.");
        printf("\nTry again!");
        getch();
        welcome1();
    }
    
    
}
//Entry into Admin's Login
void entry(){
    void cancel();
    int op;
    FILE *f2;
    char c;
    system("cls");
    gotoxy(81,2);
    printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Admin \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
    gotoxy(90,4);
    printf("Options:\t");
    gotoxy(81,6);
    printf("1.Booking Counting");
    gotoxy(81,8);
    printf("2.Cancellation of Booking");
    gotoxy(81,10);
    printf("3.Changes in Timetable");
    gotoxy(81,12);
    printf("4.News Announcing");
    gotoxy(81,14);
    printf("5.exit");
    gotoxy(81,17);
    printf("Enter Options:\t");
    scanf("%d",&op);
    switch(op){
        case 1:
        seats_avai();
        break;
        case 2:
        cancel();
        break;
        case 3:
        printf("Enter a Timetable:\n");
        f2=fopen("timetable","r+");
        while((c=getchar()) != EOF)
        putc(c,f2);
        fclose(f2);
        printf("The Time-table has been displayed successfully!!");
        getch();
        entry();
        break;
        case 4:
        news_add();
        break;

        default:
        welcome1();
        break;
    }   
}
//Booking into Customer
void booking(){
    void reserve(int x), display(), savefile();
    begin = stream = NULL; 
    int op,seats=50;
    system("cls");
     gotoxy(81,7);
        reserve(num);
        num++;
    gotoxy(81,14);
    printf("For returning to Main Menu");
    printf("Press Any Key:\t");
    getch();
    timetable();
    
}
void seats_avai(){
    int op,seat_no;
    system("cls");
    gotoxy(82,2);
    printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Seat selction Section: \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
    display();
    printf("\nEnter Options any key to go back:\t");
    getch();
    entry();
}
void seats_seen(){
        int i=1;
        stream->seat_select=0;
        seat_display(stream->seat_select);    
        printf("\n\n('*' for vacancy seats\n'|' for booked seats)\n\tDeclaimer : Seats' arrangement may be actually get changed but seat number will be same");
        printf("\n\nSelect seat:");
        scanf("%d",&stream->seat_select);
        stream->seat_num=stream->seat_select;
        printf("\n\t Seat booking successful!");
		printf("\n\t your seat number is: Seat %d", stream->seat_num);
        seat_display(stream->seat_select);
}

void seat_display(int s){
    int i=1;
    int seat_select;   
    switch(s)
    {
        case 11:
        A1='|';
        break;
        case 12:
        B1='|';
        break;
        case 13:
        C1='|';
        break;
        case 14:
        D1='|';
        break;
        case 15:
        E1='|';
        break;
        case 21:
        A2='|';
        break;
        case 22:
        B2='|';
        break;
        case 23:
        C2='|';
        break;
        case 24:
        D2='|';
        break;
        case 25:
        E2='|';
        break;
        case 31:
        A3='|';
        break;
        case 32:
        B3='|';
        break;
        case 33:
        C3='|';
        break;
        case 34:
        D3='|';
        break;
        case 35:
        E3='|';
        break;
        case 41:
        A4='|';
        break;
        case 42:
        B4='|';
        break;
        case 43:
        C4='|';
        break;
        case 44:
        D4='|';
        break;
        case 45:
        E4='|';
        break;
        case 51:
        A5='|';
        break;
        case 52:
        B5='|';
        break;
        case 53:
        C5='|';
        break;
        case 54:
        D5='|';
        break;
        case 55:
        E5='|';
        break;
        case 61:
        A6='|';
        break;
        case 62:
        B6='|';
        break;
        case 63:
        C6='|';
        break;
        case 64:
        D6='|';
        break;
        case 65:
        E6='|';
        break;
        case 71:
        A7='|';
        break;
        case 72:
        B7='|';
        break;
        case 73:
        C7='|';
        break;
        case 74:
        D7='|';
        break;
        case 75:
        E7='|';
        break;
        case 81:
        A8='|';
        break;
        case 82:
        B8='|';
        break;
        case 83:
        C8='|';
        break;
        case 84:
        D8='|';
        break;
        case 85:
        E8='|';
        break;
        case 91:
        A9='|';
        break;
        case 92:
        B9='|';
        break;
        case 93:
        C9='|';
        break;
        case 94:
        D9='|';
        break;
        case 95:
        E9='|';
        break;
        case 101:
        A10='|';
        break;
        case 102:
        B10='|';
        break;
        case 103:
        C10='|';
        break;
        case 104:
        D10='|';
        break;
        case 105:
        E10='|';
        break;
        default:
        break;
    }
   gotoxy(80,16);
    printf("The seats avialable:");
    gotoxy(80,18);
    printf(" \t1 \t2 \t\t3 \t4 \t5");
    gotoxy(80,20);
    printf("%d \t%c \t%c \t\t%c \t%c \t%c",i,A1,B1,C1,D1,E1);
    gotoxy(80,21);
    printf("%d \t%c \t%c \t\t%c \t%c \t%c",i+1,A2,B2,C2,D2,E2);
     gotoxy(80,22);
    printf("%d \t%c \t%c \t\t%c \t%c \t%c",i+2,A3,B3,C3,D3,E3);
     gotoxy(80,23);
    printf("%d \t%c \t%c \t\t%c \t%c \t%c",i+3,A4,B4,C4,D4,E4);
     gotoxy(80,24);
    printf("%d \t%c \t%c \t\t%c \t%c \t%c",i+4,A5,B5,C5,D5,E5);
     gotoxy(80,25);
    printf("%d \t%c \t%c \t\t%c \t%c \t%c",i+5,A6,B6,C6,D6,E6);
     gotoxy(80,26);
    printf("%d \t%c \t%c \t\t%c \t%c \t%c",i+6,A7,B7,C7,D7,E7);
     gotoxy(80,27);
    printf("%d \t%c \t%c \t\t%c \t%c \t%c",i+7,A8,B8,C8,D8,E8);
     gotoxy(80,28);
    printf("%d \t%c \t%c \t\t%c \t%c \t%c",i+8,A9,B9,C9,D9,E9);
     gotoxy(80,29);
    printf("%d \t%c \t%c \t\t%c \t%c \t%c",i+9,A10,B10,C10,D10,E10);
     gotoxy(80,30);
}
void timetable(){
    void reserve(int x), display(), savefile();  //function prototypes
	int choice;
	begin = stream = NULL;  //initialize the struct pointers to NULL 
		FILE *f2;
    char c;
	do
	{
         system("cls");
        printf("\n\n");
        f2=fopen("timetable","r");
        while((c=getc(f2)) != EOF)
        printf("%c",c);
        fclose(f2);
		gotoxy(82,16);
		printf("Please enter your choice from below (1-4):");
        gotoxy(84,18);
		printf("1. Booking");
        gotoxy(84,19);
		printf("2. News");
        gotoxy(84,20);
		printf("3. EXIT");
        gotoxy(84,23);
		printf("Enter your choice :");
		scanf("%d", &choice); fflush(stdin);
		system("cls");
		switch (choice)
		{
		case 1:
			reserve(num);
			num++;
			break;
		case 2:
			news_dis();
			break;
		
		case 3:
		{
			savefile();
            welcome1();
			break;
		}
		default:
			printf("\n\n\t SORRY INVALID CHOICE!");
			printf("\n\n\t PLEASE CHOOSE FROM 1-4");
			printf("\n\n\t Do not forget to chose from 1-4");
		}
		getch();
	} while (choice != 5);
}
void details()
{
    gotoxy(82,6);
    printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Booking \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3 ");
    gotoxy(80,8);
	printf("Enter your passport number:");
	scanf("%d",&stream->passport); fflush(stdin);   //reads a line from stdin and stores it into the string pointed
	gotoxy(80,10);
    printf("Enter your  name:");
	gets(stream->name); fflush(stdin);
    gotoxy(80,12);
	printf("Enter your email address:");
	gets(stream->email); fflush(stdin);
    gotoxy(80,14);
    printf("Enter the Destination : ");
    gets(stream->destination); fflush(stdin);
}
void reserve(int x)
{
	stream = begin;
	if (begin == NULL)
	{
		// first user
		begin = stream = (struct airport*)malloc(sizeof(struct airport));
		details();
		seats_seen();
		stream->counter = NULL;
		stream->seat_num;
		return;
	}
	else if (x > 50) // FULL SEATS
	{
        gotoxy(81,7);
		printf("Seat Full.");
		return;
	}
	else
	{
		// next user
		while (stream->counter)
			stream = stream->counter;
		stream->counter = (struct airport *)malloc(sizeof(struct airport));
		stream = stream->counter;
		details();
		stream->counter = NULL;
		seats_seen();
		stream->seat_num= x;
		return;
	}
} 
void savefile()
{
	FILE *fpointer = fopen("airport record", "w");
	if (!fpointer)
	{
		printf("\n Error in opening file!");
		return;
		
	}
	stream = begin;
	while (stream)
	{
		fprintf(fpointer, "%-6d", stream->passport);
		fprintf(fpointer, "%-15s", stream->name);
		fprintf(fpointer, "%-15s", stream->email);
        fprintf(fpointer, "%-15s", stream->destination);
        fprintf(fpointer, "\n"); 
		stream = stream->counter;
	}
	
	fclose(fpointer);
}
void display()
{
	stream = begin;
	while (stream)
	{
        
		printf("\n Passport Number   : %-6d", stream->passport);
		printf("\n         name      : %-15s", stream->name);
		printf("\n      email address: %-15s", stream->email);
		printf("\n      Seat number  : %d", stream->seat_num);
        printf("\n     Destination   :%-15s", stream->destination);
		printf("\n\n++=====================================================++");
		stream = stream->counter;
	}

}
void cancel()
{
    int op,y;
	stream = begin;
	system("cls");
	int passport;
    gotoxy(41,3);
	printf("Enter passort number to delete record?:");
    scanf("%d",&passport); fflush(stdin);
	if (begin->passport==passport)
	{
   sample = begin;
		begin = begin->counter;
        stream->seat_total++;
		free(sample);
		printf("Your booking has been deleted from the record.");
		entry();
		return;
	}

	while (stream->counter)
	{
		if (strcmp(stream->counter->passport, passport) == 0)
		{
			sample = stream->counter;
			stream->counter = stream->counter->counter;
			free(sample);
			printf("has been deleted ");
			getch();
			entry();
			return;
		}
		stream = stream->counter;
	}
    getch();
    
    }


void news_add(){
    FILE *f1;
    char c;
    int op;
    printf("Enter a news:\n");
    f1=fopen("news","r+");
    while((c=getchar()) != EOF)

    putc(c,f1);
    fclose(f1);
    printf("The news has been displayed successfully!!");
    
    printf("\n\nFor returning to Main Menu");
    printf("\nPress Any Key:\t");
    getch();
    entry();
}
void news_dis(){
    FILE *f1;
    char c;
    int op;
    gotoxy(81,2);
    printf("\xB3\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Notice: \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB3");
    f1=fopen("news","r");
    gotoxy(81,4);
    while((c=getc(f1)) != EOF)
    printf("%c",c);
    fclose(f1);
    gotoxy(81,15);
    printf("For returning to Main Menu");
    gotoxy(81,17);
    printf("Press Any Key:\t");
    getch();
    timetable();
}
void exit1(){
    char name[]=" CREATED BY ";
    int z=strlen(name);
    system("cls");
     gotoxy(81,2);
    printf("\xB3");
     for(int j=0;j<=8;j++){
		Sleep(30);
		printf("\xDB");
	}
   for(int j=0;j<=z;j++){
		Sleep(50);
		printf(" %c",name[j]);
	}
    for(int j=0;j<=8;j++){
		Sleep(30);
		printf("\xDB");
	}
    printf("\xB3");
     gotoxy(97,4);
    printf("Deshpande Sujay Hemantkumar");
    gotoxy(90,15);
    printf("For exit press any key:");
    Beep(750, 800);
    getch();
    // exit();
}
