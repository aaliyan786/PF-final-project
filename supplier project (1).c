#include <stdio.h>
typedef struct 
{
        float heights, widths,lenghts;
}stock;
   
int main()
{
	int n;
	float stcost;
	stock x[500];
	FILE *fp;
	fprintf(fp,"%f %f %f %d %d", len, width, height, i, quant);
	printf("Enter today's price steel");
	scanf("\f",&stcost);
	pritnf("Enter the amount of stock you got");
	scanf("%d",n);
	cost(len, width, height,stcost);
	mould(x, quant);
	return 0;
}

float cost(float len, float width, float height,float stcost)
{
	bill = (len * width * height) * (7.85*10^-6) * (stcost);
}

int mould(stock *x,len,width,height, int q,n)
{
	int i,c;
	for(i=0;i<n;i++)
	{
		printf("Enter lenght,width and height for the mould");
		scanf("%d %d %d",&(x+i)->lenghts,&(x+i)->widths,&(x+i)->heights);
	}
	for(i=0;i<n;i++)
	{
		if(((x+i)->lenghts)==len&&((x+i)->widths)==width&&((x+i)->heights)==height)
		{
			c++;
		}
		if(c==q)
		{
			printf("quantity found it will take 2 days");
		}
		elseif(i==n-1&&c!=q)
		{
			printf("it will take 10 days");
		}
	}
}


