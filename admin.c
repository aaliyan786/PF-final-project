#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct dimensions
{
	float length,width,height,diameter;
	int cavity;
};


struct order
{
	int customer_id;
	
	char name[50];
	char contact[20];
	char address[200] ;	
	char order_type[50];
	char order_subtype[20];
	struct dimensions dim;
	char status[50];	
}s;

void sign_in()
 {
 	system("cls");
	printf("\t***********************************************\n");
	printf("\t\tPATEL and KHAN Mould Walai\n");
	printf("\t***********************************************\n");
 	char user_name[13];
 	int pass;
 	printf("Enter Username:\n ");
 	fflush(stdin);
 	gets(user_name);
 	fflush(stdin);
 	printf("Enter the 5 digit Password:\n ");
	scanf("%d",&pass);
	if (strcmp(user_name,"Administrator")==0 && pass==9110)
	{
		return;
	}
	else
	{
		printf("Incorrect user name or password! \nPress any key to continue...");
		getch();
		sign_in();
	}
	 
 }

void display_rec
{
	FILE *fp;
		fp = fopen("customer.txt","rb+");
		if (fp==NULL)
		{
			printf("cannot open file.\nPress any key to continue...");
			getch();
			fclose(fp);
			return;	
		}
		while (fread(&s,sizeof(s),1,fp)>0)
		{
			printf("ID: %d\nName: %s\nContact: %s\nAddress: %s\nOrder Type: %s\nOrder Sub-type: %s\nOrder Dimensions:\n	Height: %f\n	Length: %f\n	Width: %f\n	Diameter: %f\n	Cavity: %d\nStatus: %s\n\n\n",s.customer_id,s.name,s.contact,s.address,s.order_type,s.order_subtype,s.dim.height,s.dim.length,s.dim.width,s.dim.diameter,s.dim.cavity,s.status);
			printf("\nPress any key to continue...");
			getch();				
		}

		fclose(fp);
		return;
}

void search_rec()
{
	int flag=0,id;
	printf("Enter the id of customer you want to search for: ");
	scanf("%d",&id);
		FILE *fp;
		fp = fopen("customer.txt","rb+");
		if (fp==NULL)
		{
			printf("cannot open file.\nPress any key to continue...");
			getch();
			fclose(fp);
			return;	
		}
		while (fread(&s,sizeof(s),1,fp)>0)
		{
			if (s.customer_id==id)
			{
				flag = 1;
				printf("\n\n\tYour Record Is As Follows:\n\n");
				printf("ID: %d\nName: %s\nContact: %s\nAddress: %s\nOrder Type: %s\nOrder Sub-type: %s\nOrder Dimensions:\n	Height: %f\n	Length: %f\n	Width: %f\n	Diameter: %f\n	Cavity: %d\nStatus: %s",s.customer_id,s.name,s.contact,s.address,s.order_type,s.order_subtype,s.dim.height,s.dim.length,s.dim.width,s.dim.diameter,s.dim.cavity,s.status);
				printf("\nPress any key to continue...");
				getch();				
			}
		}
		if(flag == 0)
		{
			printf("No Search Record Found!");
		}
		fclose(fp);
		return;
}

void del_rec()
{
	return;
}

void update_rec()
{
	return;
}

int main()
{
	sign_in();
		
	char ch_1;
	while(ch_1!=4)
	{
		system("cls");
		printf("\t***********************************************\n");
		printf("\t\tPATEL and KHAN Mould Walai\n");
		printf("\t***********************************************\n");
		
			printf("\t\n\n\n***What would you like to do?***\n\n\n");
			printf("\t\t1: Display all customer records \n");
			printf("\t\t2: Search for a customer record\n");
			printf("\t\t3: Delete a customer record\n");
			printf("\t\t4: Update a customer record\n");
			printf("\t\t5: Exit\n");
			ch_1 = getch();
			
		switch(ch_1)
		{
			case '1':
				{
					system("cls");
;					display_rec();
					break;
				}
			case '2':
				{
					system("cls");
					search_rec();
					break;
				}
			case '3':
				{
					system("cls");
					delete_rec();
					break;
				}
			case '4':
				{
					system("cls");
					update_record;
					break;
				}
			case '5':
				{
					system("cls");
					exit(1);
					break;
				}

			default:
				{
					system("cls");
					printf("Invalid Input.\nPress any key to continue...");
					getch();
					break;
				}
		}
		
			
	}
	
	return 0;	
}
