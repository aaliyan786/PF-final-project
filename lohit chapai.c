#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int login(char user[15] ,char pass[15],char store[30]){
	printf("Enter the username:");
	gets(user);
	printf("Enter the Password:");
	gets(pass);
	system("cls");
	strcat(user,pass);
	puts(user);
	if(strcmp(user,store)==0){
		return 0;
	}
	else{
		return 1;
	} 
}

int main (){
	char user[15]="", pass[15]="",store[20]="lohitmaheshwari/08";
	printf("WELCOME TO FAST LOOTERA BANK \n");
	
	
	printf("%d",login(user,pass,store));
	
	return 0;
}
