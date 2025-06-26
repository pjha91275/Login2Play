#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include <ctype.h>
#define BCKSPC 8
#define TAB 9
#define ENTER 13


struct user
{
	char fullName[50];
	char phone[50];
	char email[50];
	char password[50];
	char username[50];	
};

void takeinput(char ch[50]) 
{
    do{
        fgets(ch, 50, stdin);
        if (ch[strlen(ch) - 1] == '\n') 
		{
            ch[strlen(ch) - 1] = '\0';
        }
        if (strlen(ch) == 0) 
		{
            printf("This field cannot be empty. Please enter again:\t");
        }
    }while (strlen(ch) == 0);
}

int isValidPhone(char phone[50]) 
{
    if (strlen(phone) != 10) 
	{
        return 0;
    } 
    int i ;
    for ( i = 0; i < 10; i++) 
	{
        if (!isdigit(phone[i])) 
		{
            return 0;
        }
    }
    return 1;
}

int isValidEmail(char email[50]) 
{
    int len = strlen(email);
    return (len > 10 && strcmp(email + len - 10 , "@gmail.com") == 0);
}

void takepassword(char pwd[50]){
	int i = 0;
	char ch;
	while(1){
		ch = getch();
		if(ch == ENTER || ch == TAB)
		{
			pwd[i] = '\0';
			break;
		}
		else if(ch == BCKSPC)
		{
			if(i>0)
			{
				i--;
				printf("\b \b");
			}
		}
		else
		{
			pwd[i] = ch;   
			i++;
			printf("*");
		}
	}
}

void generateUsername(char email[50],char username[50]){
	//abc123@gmail.com
	int i;
	for(i=0;i<strlen(email);i++)
	{
		if(email[i] == '@') break;
		else username[i] = email[i];
	}
	username[i] = '\0';  // Null-terminate the string
}

void progressBar() 
{
    printf("Processing: ");
    int i;
    for(i=1 ; i<=10 ; i++)
	{
        printf("_");
        fflush(stdout);
        Sleep(300); // 0.3 seconds delay
    }
    printf(" Done!\n");
}


// Function to display a bigger, centered Tic-Tac-Toe board
void displayBoard(char board[3][3]) {
    system("cls");
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t         TIC-TAC-TOE\n");
    printf("\t\t\t\t\t\t  Player 1 (X) - Player 2 (O)\n\n");
    int i,j;
    for ( i = 0; i < 3; i++) {
        printf("\t\t\t\t\t\t      ");
        for ( j = 0; j < 3; j++) {
            printf("  %c  ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");

        if (i < 2) {
            printf("\t\t\t\t\t\t     ");
            printf("------|-----|------\n");
        }
    }
}

// Function to check if a player has won
int checkWinner(char board[3][3]) {
	int i;
    for ( i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
    return 0;
}


// Tic-Tac-Toe Game
void ticTacToe() {
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int move, turn = 0;
    char mark;

    while (turn < 9) {
        displayBoard(board);
        mark = (turn % 2 == 0) ? 'X' : 'O';
        printf("\n\t\t\t\t\t\t  Player %c, enter position (1-9): ", mark);
        scanf("%d", &move);

        if (move < 1 || move > 9) continue;
        int row = (move - 1) / 3, col = (move - 1) % 3;
        if (board[row][col] == 'X' || board[row][col] == 'O') continue;
        board[row][col] = mark;
        turn++;

        if (checkWinner(board)) {
            displayBoard(board);
            printf("\n\t\t\t\t\t\t  Player %c wins!\n", mark);
            return;
        }
    }
    displayBoard(board);
    printf("\n\t\t\t\t\t\t  It's a draw!\n");
}


int main()
{
	system("color B0");
	FILE *fp;
	int opt,usrFound = 0;
	char password2[50];
	struct user user;
	
    printf("\n");
    printf(" +----------------------------------------------------+\n");
    printf(" |             WELCOME TO TIC TAC TOE                 |\n");
    printf(" |----------------------------------------------------|\n");
    printf(" |                                                    |\n");
    printf(" |   1. Register                                      |\n");
    printf(" |   2. Login                                         |\n");
    printf(" |   3. Exit                                          |\n");
    printf(" |                                                    |\n");
    printf(" +----------------------------------------------------+\n");
    printf("\n Your choice : ");
	scanf("%d",&opt);
	fgetc(stdin);
	
	switch(opt)
	{
		case 1:
			system("cls");
            printf("\n Enter your full name :  ");
            takeinput(user.fullName);
            
            do{
                  printf("\n Enter your contact no : ");
                  takeinput(user.phone);
                  if (!isValidPhone(user.phone)) 
				  {
                     printf("\n Invalid phone number! It must be exactly 10 digits. Try again.\n");
                  }
            }while (!isValidPhone(user.phone));
            
            do{
                  printf("\n Enter your email : \t ");
                  takeinput(user.email);
                  if (!isValidEmail(user.email)) 
				  {
                     printf("\n Invalid email! It must end with @gmail.com. Try again.\n");
                  }
            }while (!isValidEmail(user.email));

			printf("\n Enter your password : \t ");
			takepassword(user.password);
			
			printf("\n\n Confirm your password : ");
			takepassword(password2);
			
			if(!strcmp(user.password,password2))
			{
				generateUsername(user.email,user.username);
				fp = fopen("Users.dat","a+");
                if (fp == NULL) 
				{
                    printf("\n Error accessing data base for storing the SignUp details!");
                    return 0;
                }
                fwrite(&user,sizeof(struct user),1,fp);
				if (fwrite(&user, sizeof(struct user), 1, fp) == 1)
                {
                	printf("\n\n User registration success, Your username is %s",user.username);
				}
				else 
				{
					printf("\n\n Sorry! Something went wrong :(");
				}
				fclose(fp);
			}
			else
			{
				printf("\n\n Password do not matched");
				Beep(900,500);
			}
		    break;
		
		case 2:
			{
			char username[50], pword[50];
			struct user usr;
			
			printf("\n Enter your username :\t");
			takeinput(username);
			printf("\n Enter your password :\t");
			takepassword(pword);
			
			fp = fopen("Users.dat","a+");
            if (fp == NULL) 
			{
                printf("\n Error accessing data base for verfying login credentials!");
                return 0;
            }
            while(fread(&usr, sizeof(struct user),1,fp) == 1)
			{
				if(!strcmp(usr.username,username))
				{
					if(!strcmp(usr.password,pword))
					{
						system("cls");
						progressBar();
						printf("\n\t\t\t\t\t\tWelcome %s",usr.fullName);
						printf("\n\n|Full Name:\t%s",usr.fullName);
						printf("\n|Email:\t\t%s",usr.email);
						printf("\n|Username:\t%s",usr.username);
						printf("\n|Contact no.:\t%s",usr.phone);
						printf("\n");
						printf("\n YOU HAVE SUCCESSFULLY LOGGED IN , ABOVE ARE YOUR DETAILS!!!\n");
                       
                         // Option to play Tic-Tac-Toe
                        int play;
                        printf("\n Do you want to play Tic-Tac-Toe? (1-Yes, 0-No): ");
                        scanf("%d", &play);
                        if (play == 1) {
                        system("cls");
                        ticTacToe();
                    }
                    
						usrFound = 1;
						fclose(fp);
						break;
					}
					else 
					{
						printf("\n\n Invalid Password!");
						fclose(fp);
						Beep(900,500);
					}
					usrFound = 1;
				}
			}
			if(!usrFound)
			{
				printf("\n\n User is not registered!");
				Beep(800,300);
			}
			fclose(fp);
			break;	
			}
			
		case 3:
			printf("\t\t\tBye Bye :)");
			break;
			
	    default:
	    	printf("\n Invalid input! ");
	    	break;
    }
    return 0;
}
