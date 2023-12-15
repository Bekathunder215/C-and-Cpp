#include<stdio.h>
#include<stdlib.h>

int pinakas[10];
int Hsize;
char c;

void print_array()
{
		int j;
		printf("\no pinakas apoteleitai apo:\n");
		for(j=0;j<=9;j++)
		{
			printf("A[%d]=%d \n",j,pinakas[j]);
		}
}

void insert_heap()
{
	int i,k;
	printf("\nvale 10 nea stoixeia ston pinaka\n");
	for(i=0;i<=9;i++)
	{
		scanf("%d",&k);
		pinakas[i]=k;
		printf("\nto neo stoixeio pou evales einai to: %d\n",pinakas[i]);
	}
	Hsize=9;
}

void heapify(int i)
{
	int l,k,r,largest;
	l=2*i+1;
	r=l+1;
	if((l<=Hsize)&&(pinakas[l]>pinakas[i]))
		largest=l;
	else
		largest=i;
	if((r<=Hsize)&&(pinakas[r]>pinakas[largest]))
		largest=r;
	if(largest!=i)
	{
		k=pinakas[i];
		pinakas[i]=pinakas[largest];
		pinakas[largest]=k;
		heapify(k);
	}
}

void build_heap()
{
	int m;
	for(m=10;m>=0;m--)
	{
		heapify(m);
	}
}

void heapsort()
{
	int q,p;
	for(q=9;q>=0;q--)
	{
		p=pinakas[0];
		pinakas[0]=pinakas[q];
		pinakas[q]=p;
		Hsize=Hsize-1;
		heapify(0);
	}
	printf("\no pinakas taksinomithike");
	print_array();
}

int main(void)
{
	char c='a';
	while (c!='q'||c!='Q')
	{
		printf("\nPress: \n\ti to Insert.\n\tb to Build heap.\n\ts to Heapsort.\n\tp to Print.\n\tq to Quit.\n");
		fflush(stdin);
		scanf("%c",&c);
		if(c=='i'||c=='I')
			insert_heap();
		if(c=='b'||c=='B')
			build_heap();
		if(c=='s'||c=='S')
			heapsort();
		if(c=='p'||c=='P')
			print_array();
		if(c=='q'||c=='Q')
			{
				printf("\nGoodbye");
				return 0;
			}
	}
	return 0;
}