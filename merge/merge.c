#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int A[16],B[16];
int s,ds,m;
int Asize,Bsize;

void print_array(int A[],int B[],int s, int ds);
void insert_A(int A[]);
void merge(int A[],int m,int mid,int s);
void print(int M[],int size);
void mergesort(int A[],int m,int Asize);


int main(void)
{
	int s=NULL;
	int ds=Asize+Bsize;
	char c='a';
	while (c!='q'||c!='Q')
	{
		printf("\nPress: \n\ti to Insert Array.\n\tp to Print.\n\ts to Mergesort \n\tq to Quit.\n");
		fflush(stdin);
		scanf("%c",&c);
		switch (c)
		{
			case 'i':
			case 'I':
				insert_A(A);
				break;
			case 'p':
			case 'P':
				print_array(A,B,Asize,Bsize);
				break;
			case 's':
			case 'S':
				if(A[0]==NULL)
					printf("\nThere are NO arrays to sort");
				else
					mergesort(A,0,Asize);
				c=='a';
				break;
			case 'q':
			case 'Q':
				printf("\nGoodbye\n\n");
				return 0;
			default:
				printf("\nPlease use an allowed character\n\n");
				break;
		}
	}
	return 0;
}

void print_array(int A[],int B[],int s, int ds)
{
	int j;
	if(A[0]==NULL)
		printf("\nThe A array is empty");
	else
	{
		printf("\nThe A Array consists of:\n");
		for(j=0;j<=s-1;j++)
		{
			printf("A[%d]=%d \n",j,A[j]);
		}
	}
	if(B[0]==NULL)
		printf("\nThe B array is empty");
	else
	{
		printf("\nThe B Array consists of:\n");
		for(j=0;j<=s-1;j++)
		{
			printf("B[%d]=%d \n",j,B[j]);
		}
	}
}

void insert_A(int A[])
{
	int s;
	int i=0;
	int j=0;
	printf("\nPlease insert how many numbers are in the A array (until 16 numbers):\t");
	fflush(stdin);
	scanf("%d",&s);
	printf("\nPlease insert %d numbers in the A array\n",s);
	for(i=0;i<=s-1;i++)
	{
		scanf("%d",&A[i]);
		printf("New number added! Value= %d\n",A[i]);
	}
	Asize=s;
}

void merge(int A[],int m,int mid,int s)
{
	int i,j,k,p;
	int c1=((s-m+1)/2);
	k=mid;
	i=m;
	p=m;
	while((p<=mid-1)&&(k<=s))
	{
		printf("mpika stin while m=%d, mid=%d, s=%d\n",m,mid,s);
		if(A[p]<=A[k])
		{
			B[i]=A[p];
			i++;
			p++;
		}
		else
		{
			B[i]=A[k];
			i++;
			k++;
		}
	}
	if(p>mid-1)
	{
		printf("mpika stin if m=%d, mid=%d, s=%d, i=%d\n",m,mid,s,i);
		for(j=k;j<=s;j++)
		{
			B[j]=A[j];
		}	
	}
	if(k>s)
	{
		printf("mpika stin if2 m=%d, mid=%d, s=%d, k=%d\n",m,mid,s,k);
		for(j=p;j<=mid-1;j++)
		{
			B[j+c1]=A[j];
		}
	}
	for(j=m;j<=s;j++)
		A[j]=B[j];
}


void mergesort(int A[],int m,int Msize)
{
	if(m<Msize)
	{
		int mid=((Msize+m+1)/2);
		mergesort(A,m,mid-1);
		mergesort(A,mid,Msize);
		merge(A,m,mid,Msize);
	}
}