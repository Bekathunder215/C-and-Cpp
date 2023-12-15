#include <iostream>
#include <cmath>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#define num 12
double A[num];
double B[num];

void *square(void *arg)
{
	
	int c;
	int q = *((int *) arg);
	
	if (q==1)
	{
	
		for (c=0; c<num/4; c++)
		{
			B[c]=(A[c]*A[c]);
		}
	}
	if (q==2)
	{
	
		for (c=num/4; c<(2*(num/4)); c++)
		{
			B[c]=(A[c]*A[c]);
		}
	}
	if (q==3)
	{
		for (c=2*(num/4); c<(3*(num/4)); c++)
		{
			B[c]=(A[c]*A[c]);
		}
	}
	
	if (q==4)
	{
		for (c=(3*(num/4)); c<num; c++)
		{
			B[c]=(A[c]*A[c]);
		}
	}
}

int main()
{
	pthread_t t1,t2,t3,t4;
	int a=1;
	int b=2;
	int d=3;
	int e=4;
	for (int i=1; i<num+1; i++)
	{
		A[i]=i;
	}
	
	
	cout<<"Creating Threads\n";
	pthread_create(&t1, NULL, square, &a);
	pthread_create(&t2, NULL, square, &b);
	pthread_create(&t3, NULL, square, &d);
	pthread_create(&t4, NULL, square, &e);
	
	cout<<"Joining Threads\n";
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	pthread_join(t4, NULL);
	
	cout<<"	exiting\n";
	
	return 0;
}

