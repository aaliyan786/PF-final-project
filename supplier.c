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
	int order_id;
	int qty;
	char name[50];
	char contact[20];
	char address[200] ;	
	char order_type[50];
	char order_subtype[20];
	struct dimensions dim;
	char status[50];	
}s;

int display_rec()
{
	FILE *fp;
		fp = fopen("customer.txt","rb+");
		if (fp==NULL)
		{
			printf("\ncannot open file.\nPress any key to continue...");
			getch();
			fclose(fp);
			return;	
		}
		while (fread(&s,sizeof(s),1,fp)>0)
		{
			if(strcmp(s.status,"Response Pending")==0)
			{
					printf("\n\n\tYour Record Is As Follows:\n\n");
					printf("\nID: %d\nQuantity: %d\nOrder Type: %s\nOrder Sub-type: %s\nOrder Dimensions:\n	Height: %f\n	Length: %f\n	Width: %f\n	Diameter: %f\n	Cavity: %d\nStatus: %s",s.order_id,s.qty,s.order_type,s.order_subtype,s.dim.height,s.dim.length,s.dim.width,s.dim.diameter,s.dim.cavity,s.status);
					printf("\nPress any key to continue...");
					getch();				
			}
		}
		fclose(fp);
		return 0;
}

int search_rec(int id)
{
	int flag=0;
	
		FILE *fp;
		fp = fopen("customer.txt","rb+");
		if (fp==NULL)
		{
			printf("\ncannot open file.\nPress any key to continue...\n");
			getch();
			fclose(fp);
			return;	
		}
		while (fread(&s,sizeof(s),1,fp)>0)
		{
			if(strcmp(s.status,"Response Pending")==0)
			{
				if (s.order_id==id)
				{
					flag = 1;
					printf("\n\n\tYour Record Is As Follows:\n\n");
					printf("\nID: %d\nQuantity: %d\nOrder Type: %s\nOrder Sub-type: %s\nOrder Dimensions:\n	Height: %f\n	Length: %f\n	Width: %f\n	Diameter: %f\n	Cavity: %d\nStatus: %s",s.order_id,s.qty,s.order_type,s.order_subtype,s.dim.height,s.dim.length,s.dim.width,s.dim.diameter,s.dim.cavity,s.status);
					printf("\nPress any key to continue...");
					getch();				
				}
			}
		}
		if(flag == 0)
		{
			printf("\nNo Search Record Found!\n");
			printf("\nPress any key to continue...");
			getch();
		}
		fclose(fp);
		return flag;
}

void update_rec()
{
	char date[10],price[10];
	int id,flag=0,check;
	FILE *fp;
	fp = fopen("customer.txt","rb+");
	if (fp==NULL)
		{
			printf("\ncannot open file.\nPress any key to continue...\n");
			getch();
			fclose(fp);
			return;	
		}
	printf("\nEnter the order ID you want to update: ");
	scanf("%d",&id);
	check = search_rec(id);
	if (check == 0)
	{
		return;
	}
	
	while(fread(&s,sizeof(s),1,fp)>0 && flag == 0)
	{
		if(s.order_id == id)
		{
			flag = 1;
			printf("\nEnter the price of the order: ");
			fflush(stdin);
			gets(price);
			printf("Enter the date of delivery of order in dd/mm/yy format: ");
			fflush(stdin);
			gets(date);
			strcpy(s.status,"Delivery on: ");
			strcat(s.status,date);
			strcat(s.status," . Price is: ");
			strcat(s.status,price);
			
			fseek(fp,-sizeof(s),1);
			fwrite(&s,sizeof(s),1,fp);
			printf("\nRecord Updated Successfully\n");
			printf("\nPress any key to continue...");
			getch();
		}
	}
	if(flag == 0)
	{
		printf("\nRecord Update was Unsuccessfull\n");
		printf("\nPress any key to continue...");
		getch();
	}
	fclose(fp);
}

int main()
{
	
	char ch_1;
	while(ch_1!=4)
	{
		system("cls");
		printf("\t***********************************************\n");
		printf("\t\tPATEL and KHAN Mould Walai\n");
		printf("\t***********************************************\n");
		
			printf("\t\n\n\n***What would you like to do?***\n\n\n");
			printf("\t\t1: Display all orders \n");
			printf("\t\t2: Search for an order\n");
			printf("\t\t3: Update an order\n");
			printf("\t\t4: Exit\n");;
			ch_1 = getch();
			
		switch(ch_1)
		{
			case '1':
				{
					system("cls");
					display_rec();
					break;
				}
			case '2':
				{
					int id;
					system("cls");
					printf("\nEnter the id of customer you want to search for: ");
					scanf("%d",&id);
					search_rec(id);
					break;
				}
			case '3':
				{
					system("cls");
					update_rec();
					break;
				}

			case '4':
				{
					system("cls");
					exit(1);
					break;
				}

			default:
				{
					system("cls");
					printf("Invalid Input.\nPress any key to continue...\n");
					getch();
					break;
				}
		}
		
			
	}
	
	return 0;	
}
