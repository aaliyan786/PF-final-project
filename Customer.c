#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct order
{
	char[name];
	int order_id_number;
	char order_type[50];
	char order_subtype[50];
	char address[100];
	char contact[15];
}s;
void insert_record()
{
	FILE *fp;
	fp=fopen("customerdata.txt","a+");
	if(fp==NULL)
	{
		printf("\n\tError: Record is unable to be stored!!!");
		return;
	}
	
	fwrite(&s,sizeof(s),1,fp);
}
int main()
{
	
	
	
	int ch_1,ch_2,ch_3;
	while(ch_1!=4)
	{
		system("cls");
		printf("\t***********************************************\n");
		printf("\t\tPATEL and KHAN Mould Walai\n");
		printf("\t***********************************************\n");
		
			printf("\t\n\n\n***What would you like to do?***\n\n\n");
			printf("\t\t1: Buy\n");
			printf("\t\t2: Check order status\n");
			printf("\t\t3: Exit\n");
			scanf("%d",&ch_1);
			
		switch(ch_1)
		{
			case 1:
				{
					system("cls");
					printf("What would you like to buy?\n\n");
					printf("\t\t1: Buy mould of caps\n ");
					printf("\t\t2: Buy mould of basket\n ");
					printf("\t\t3: Buy mould of Simple air-tight container\n ");
					scanf("%d",&ch_2);
					
					switch(ch_2)
					{
						case 1:
							{
								system("cls");
								printf("Which kind of cap mould would you like to buy?\n\n");
								printf("\t\t1:Flip-top \n ");
								printf("\t\t2:Screw-cap \n ");
								scanf("%d",&ch_3);
								system("cls");
								printf("Enter the height of mould:");
								scanf("%d",&ch_3);
								printf("Enter the diameter of mould:");
								scanf("%d",&ch_3);
								printf("Would you like 8 or 16 cavities in mould?");
								scanf("%d",&ch_3);
								break;
							}
							case 2:
							{
								system("cls");
								printf("Which kind of basket mould would you like to buy?\n\n");
								printf("\t\t1:acrylic-design basket \n ");
								printf("\t\t2:simple-plastic basket \n ");
								scanf("%d",&ch_3);
								break;
							}
							case 3:
							{
								system("cls");
								printf("What shape of simple air-tight container mould would you like to buy?\n\n");
								printf("\t\t1:Round \n ");
								printf("\t\t2:Rectangle \n ");
								scanf("%d",&ch_3);
								break;
							}
							default:
								{
									system("cls");
									printf("Invalid Input");
									break;
								}
					}
					break;
				}
			case 2:
				{
					system("cls");
					
					break;
				}
			case 3:
				{
					system("cls");
					exit(1);
					break;
				}

			default:
				{
					system("cls");
					printf("Invalid Input");
					break;
				}
		}
		
			
	}
}

