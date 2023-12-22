#include<stdio.h>

int array[10];
int Hsize;
char c;

void print_array() //prints array
{
		int j;
		printf("\nArray consists of:\n");
		for(j=0;j<=9;j++)
		{
			printf("A[%d]=%d \n",j,array[j]);
		}
}

void insert_heap() //inserts numbers in the heap
{
	int i,k;
	printf("\nInsert 10 numbers in the array\n");
	for(i=0;i<=9;i++)
	{
		scanf("%d",&k);
		array[i]=k;
		printf("\nYou inserted: %d\n",array[i]);
	}
	Hsize=9;
}

void heapify(int i) //reorganises the numbers in a heap data structure recursively
{
	int l,k,r,largest;
	l=2*i+1;
	r=l+1;
	if((l<=Hsize)&&(array[l]>=array[i]))
		largest=l;
	else
		largest=i;
	if((r<=Hsize)&&(array[r]>array[largest]))
		largest=r;
	if(largest!=i)
	{
		k=array[i];
		array[i]=array[largest];
		array[largest]=k;
		heapify(k);
	}
}

void build_heap() //builds heap with heapify function
{
	int m;
	for(m=0;m<=Hsize;m++)
	{
		heapify(m);
	}
}

void heapsort() //sorts and prints the array
{
	int q,p;
	for(q=Hsize;q>=0;q--)
	{
		p=array[0];
		array[0]=array[q];
		array[q]=p;
		Hsize=Hsize-1;
		heapify(0);
	}
	printf("\nArray has been sorted");
	print_array();
}

int main(void)
{
	char c='a';
	while (c!='q'||c!='Q')
	{
		printf("------------------------------------------------");
		printf("\nPress: \n\ti to Insert.\n\tb to Build heap.\n\ts to Heapsort.\n\tp to Print.\n\tq to Quit.\n");
		fflush(stdin);
		scanf("%c",&c);
		switch(c)
		{
			case 'i':
			case 'I':
				insert_heap();
				break;
			case 'b':
			case 'B':
				build_heap();
				break;
			case 's':
			case 'S':
				heapsort();
				break;
			case 'p':
			case 'P':
				print_array();
				break;
			case 'q':
			case 'Q':
				return 0;
			default:
				printf("\nPlease insert one of the characters provided\n");
		}
	}
	return 0;
}