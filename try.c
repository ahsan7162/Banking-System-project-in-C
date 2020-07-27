#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<conio.h>

struct log
{
	char string[50],pass[12];
};
struct log a_f;
int c,b,t=0,l_p,loan=0;
long long int c_n;
int lineNum,line;
char p[10];
char username[100] = {0};
void update_r(void)
{
	FILE *fp,*fc;
	char ch;
	int r;
	fp=fopen("source.txt","w");
    fc=fopen("target.txt","r");
    while( ( ch = fgetc(fc) ) != EOF )
      fputc(ch, fp);
      fclose(fp);
      fclose(fc);
      FILE *fr;
      fr=fopen("source.txt","r");
      while ( (fscanf(fr,"%s", a_f.string))== 1 && fscanf(fr,"%s",a_f.pass)==1)
                {
                        if(strcmp(a_f.string, username)==0 &&strcmp(a_f.pass,p)==0 ) 
						{
        				do
							{
								

								fscanf (fr, "%d", &c);
								fscanf(fr,"%d",&r);
								fscanf (fr, "%lld", &c_n);
							}
        				while(fscanf(fr,"%s", a_f.string)==0);
        				}
        		}
        		fclose(fr);
}
        	
void showdata(void)
{
	system("color 4F");
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
	printf("\n\nName: %s\n\n\n",username);
	printf("Balance: %d\n\n\n",c);
	printf("Card no: %lld\n\n",c_n);
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("Press any key.............");
	
}
void deposit(void)
{
	system("color 4F");
	FILE *fp,*fc;
      //stores line number which should be edited.
    int count=0;  //count number lines in source file.
    int ch;   //temporary place to store character of source file(one at a time).
    int edited=0;  //0=false and 1=true
    int dep;   //temporary place to store input which you want to be replaced with error in text file.
    printf("Enter amount of of deposit ");
    scanf("%d",&dep);

    fp=fopen("source.txt","r");
    fc=fopen("target.txt","w");

    if(fp==NULL||fc==NULL)
    {
        printf("\nError...cannot open/create files");
    }

    while((ch=fgetc(fp))!=EOF)
    {
        if(ch=='\n')  //counts number of lines
            count++;
        if(count==lineNum-1 && edited==0)  //if specific line(error line) is found and that line is still not edited. More Explanation:- If we want to edit 3rd line than we should start writing at the end of 2nd line(hence count==lineNum-1) and edited==0 means that error line is still not edited. 
        {

            t=dep+c;  //You can replace this statement with any input operation which you want to replace it with the error line.

            if(count==0)  //if its the first line to edit..
                fprintf(fc,"%d\n",t);   //watch closely,no '\n' before %s,This will copy without creating a extra newline in beginning of new file.
            else 
                fprintf(fc,"\n%d\n",t);  //stores input at error line in file fc(target.txt) from variable t.

            edited=1;  //this prevents loop to execute more than once(as error is already edited),so there will be no need to execute this loop till the end of program

            while( (ch=fgetc(fp))!=EOF )  //Actually this loop will skips the existing line in source.txt(see below)
            {                           //we want to skip this line because this is error line.
                if(ch=='\n')//this will break when next new line(after error line is skipped) is found.
                    break;
            }
       }
       else
          fprintf(fc,"%c",ch);
    }
    fclose(fp);
    fclose(fc);
	system("cls");
    if(edited==1)
    {
		printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("\n\n\nAmount deposited!!!!!!\n\n\n");
		printf("Deposited amount: %d\n\n\n",dep);
		printf("New Balance : %d\n\n\n",dep+c);
    	printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"); 
		printf("Press Any key....... ")	;
	}
    else
        printf("\nNot deposited");
        printf("Press Any key....... ")	;
        update_r();
}

void withdraw(void)
{
	system("color 4F");
	FILE *fp,*fc;
    int count=0;  
    int ch;   
    int edited=0;  
    int wit;   
    printf("Enter amount to withdraw ");
    scanf("%d",&wit);

    fp=fopen("source.txt","r");
    fc=fopen("target.txt","w");

    if(fp==NULL||fc==NULL)
    {
        printf("\nError...cannot open/create files");
    }
	if(c-wit>=0)
	{
    while((ch=fgetc(fp))!=EOF)
    {
        if(ch=='\n')  
            count++;
        if(count==lineNum-1 && edited==0)   
        {
            
            t=c-wit;
            if(count==0)  
                fprintf(fc,"%d\n",t);
            else 
                fprintf(fc,"\n%d\n",t);

            edited=1;

            while( (ch=fgetc(fp))!=EOF )  
            {
                if(ch=='\n')
                    break;
            }
       }
       else
          fprintf(fc,"%c",ch);
    }
}
    fclose(fp);
    fclose(fc);
	system("cls");
    if(edited==1)
    {
    	printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\n\n\nAmount Withdrawed\n!!!!!!!\n\n\n");
        printf("Withdrawed Amount : %d\n\n\n",wit);
        printf("Remaianig Balance : %d\n\n\n",c-wit);
        printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
  		printf("Press any key.........");
		update_r();
    }
    else
    {
        printf("\nbalance insufficient!!!!!!!!!!!!!\n");
        printf("Press Any key....... ")	;
    }
}
void bill_p(void)
{
	system("color 4F");
	FILE *fp,*fc;
    int count=0;  
    int ch;   
    int edited=0;  
    int b_p;
	char b_n[20];
	long long int a_n;
	printf("Enter bill name(E.g Gas,Electric,Wter,PTCL) : ");
	scanf("%s",&b_n);
	printf("Enter account No. : ");
	scanf("%lld",&a_n);   
    printf("Enter Bill amount : ");
    scanf("%d",&b_p);

    fp=fopen("source.txt","r");
    fc=fopen("target.txt","w");

    if(fp==NULL||fc==NULL)
    {
        printf("\nError...cannot open/create files");
    }
	if(c-b_p>=0)
	{
    while((ch=fgetc(fp))!=EOF)
    {
        if(ch=='\n')  
            count++;
        if(count==lineNum-1 && edited==0)   
        {
            
            t=c-b_p;
            if(count==0)  
                fprintf(fc,"%d\n",t);
            else 
                fprintf(fc,"\n%d\n",t);

            edited=1;

            while( (ch=fgetc(fp))!=EOF )  
            {
                if(ch=='\n')
                    break;
            }
       }
       else
          fprintf(fc,"%c",ch);
    }
	}
    fclose(fp);
    fclose(fc);
    system("cls");
    if(edited==1)
    {
    	printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\n\n\nBill Payed!!!!!!\n\n\n");
        printf("Bill Name : %s\n\n\n",b_n);
        printf("Account No. : %lld\n\n\n",a_n);
        printf("Amount payed: %d\n\n\n",b_p);
        printf("Remaining Balance : %d\n\n\n",c-b_p);
        printf("\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("Press Any key........");
		update_r();    
	}
    else
        printf("\nBalance insufficient!!!!!!!!!!!!!!!!\n");
        printf("Press Any key....... ")	;
        
}

void login(void)
{
	system("color 1E");
	  int num =0,used=0,r;
        char word[2000];
        int a=0,choice;
        char s_n[200],cho;
	FILE *in_file = fopen("source.txt", "r");
	rewind(in_file);
	printf("Username : ");
        scanf("%s",&username);
        printf("Enter your pin : ");
        scanf("%s",p);
                
                if (in_file == NULL)
                {
                        printf("Error file missing\n");
                        exit(-1);
                }

                
                while ( (fscanf(in_file,"%s", a_f.string))== 1 && fscanf(in_file,"%s",a_f.pass)==1)
                {
                        line+=2;
                        if(strcmp(a_f.string, username)==0 &&strcmp(a_f.pass,p)==0 ) 
						{//if match found	
                        a=5;
                        lineNum=line+=1;
        				do
							{
								printf("login successful\n");
								printf("Press Any key....... \n")	;
								getch();
								system("cls");
								fgets(s_n,200,in_file);
								time_t t = time(NULL);
   								struct tm *tm = localtime(&t);
    							char s[64];
    							strftime(s, sizeof(s), "%c", tm);
   							 	printf("\t\t\t\t\t\t\t%s\n\n\n", s);
   							 	printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
   							 	printf("\n\nName: %s\n\n",username);
								fscanf (in_file, "%d", &c);
								printf("balance: %d\n\n",c);
								fscanf(in_file,"%d",&r);
								fscanf (in_file, "%lld", &c_n);
								printf("Card no: %lld\n\n",c_n);
								printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
								printf("for operations\nEnter\n1 to deposit\n\n2 to withdraw\n\n3 to pay bill\n\n5 to logout\nChoice: ");
				scanf("%d",&choice);
				while(choice<=4)
				{
					switch(choice)
					{
					case 1:
						{
							system("cls");
							deposit();
							getch();
							system("cls");
							break;
						}
					case 2:
						{
							system("cls");
							withdraw();
							getch();
							system("cls");
							break;
						}
					case 3:
						{
							system("cls");
							bill_p();
							getch();
							system("cls");
							break;
						}
					case 4:
						{
							system("cls");
							showdata();
							getch();
							system("cls");
							break;
						}
						default:
							{
								break;
							}
					}
					printf("do you want to perform any other operation (Y/N) ");
					scanf(" %c",&cho);
					if(cho=='Y'||cho=='y')
					{
						system("color 1E");			
						printf("for operations\nEnter\n1 to deposit\n\n2 to withdraw\n\n3 to pay bill\n\n4 to show data\n\n5 to logout\nChoice: ");
						scanf("%d",&choice);
					}
					else
					{
						system("color 1E");	
						system("cls");
						break;
					}
				}
     						}
        				while(fscanf(in_file,"%s", a_f.string)==0);
						}
                        }
                if(a<5)
                 {
				 printf("Username or password not found!\n");
				 getch();
				}
			
                num = 0;
                fclose(in_file);
	
}
void signup(void)
{
	system("color 1E");
	char string1[100];
	FILE *fp;
	int num,ba;
	char s[40];
   fp = fopen("source.txt", "a+");
   printf("Enter username: ");
   scanf("%s",s);
   while ( (fscanf(fp,"%s", string1))==1)
   {
   	if(strcmp(string1,s)==0)
   	{
   		printf("Username already exist!\n");
   		printf("please enter a New username: ");
   		scanf("%s",s);
   		rewind(fp);
	   }
   }
   fprintf(fp, "e\n%s\n",s);
   
   FILE *fr;
    printf("Enter pin : ");
   scanf("%d", &num); /*read from keyboard*/
   fprintf(fp, "%d\n", num); /*  write to file*/
   printf("Enter balance you want to enter into the account = ");
   scanf("%d",&ba);
   fprintf(fp,"%d\n",ba);
   fprintf(fp,"%d\n",0);
   srand(time(NULL));
   long long int card = rand();
   card = card*1111111111111;
   fprintf(fp,"%lld\n",card);
   printf("signup is succesful");
   printf("Press Any key....... \n")	;
   getch();
   system("cls");
   rewind(fp);
   fclose(fp);
   
}

main()
{
	printf("*****************************************************************************************************************************************************************************************************");
		printf("\n\t\t\t\t\t*           * ***** *        *****  ******  *     * *****    *****    ******");
		printf("\n\t\t\t\t\t *         *  *     *      *       *      * * * * * *          *     *      *");
		printf("\n\t\t\t\t\t  *   *   *   ***** *      *       *      * *  *  * *****      *     *      *");
		printf("\n\t\t\t\t\t   * * * *    *     *      *       *      * *     * *          *     *      *");
		printf("\n\t\t\t\t\t    *   *     ***** ******   *****  ******  *     * ******     *      ******\n");
		printf("*****************************************************************************************************************************************************************************************************");
		printf("\n\t\t\t\t\t\t\t     *     *    *    * * *      *     *    * *  *");
		printf("\n\t\t\t\t\t\t\t    * *    * *  *    *    *    * *    * *  * * *");
		printf("\n\t\t\t\t\t\t\t   * * *   *  * *    * * *    * * *   *  * * **");
		printf("\n\t\t\t\t\t\t\t  *     *  *   **    *    *  *     *  *   ** * *");
		printf("\n\t\t\t\t\t\t\t *       * *    *    * * *  *       * *    * *  *\n");
		printf("*****************************************************************************************************************************************************************************************************\n");
		printf("AN BANK offers you convenience of banking from home or your office because we understand that your time is important.\n");
		printf("We provide you the secured banking experience.\n");
		printf("We are trusted all over the country.\n");
		printf("We will provide you the best possible service posssible\n");
		printf("For any complaints please contact administration 0311-0237524\n");
		getch();
		system("cls");
        int choice;
        printf("\t\t\t\t\t\t\tMain Page\n");
        printf(" 1 for login\n\n 2 for signup\n\n 3 for exit : ");
        scanf("%d",&choice);
        while(choice<4)
        {
        	switch(choice)
        	{
        		case 1:
        			{
        		        login();
        		        line=0;
        		        lineNum=0;
        		        
                break;
                	}
				case 2:
					{
						signup();
						line=0;
						lineNum=0;
						break;
					}
				case 3:
					{
						system("cls");
						printf("Thank you for using AN Bank! ");
						getch();
						exit(-1);
					break;
					}
				default:
					{
				printf("you have inputed wrong no");
					}
			}
			system("cls");
			printf("\t\t\t\t\t\t\tMAIN PAGE\n");
			printf(" 1 for login\n\n 2 for signup\n\n 3 for exit : ");
        scanf("%d",&choice);
    	}
        
    
}
