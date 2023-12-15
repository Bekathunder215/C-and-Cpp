#include <stdio.h>
#include <stdlib.h>

typedef struct tf* tp;
	struct tf
	{
	int am;
	double gr;
	tp n;
	};
	
tp h,t,aux,temp;
char fry;

void insert (tp *h, tp *t, int da)
{
	tp temp,aux,h1= *h,t1= *t;
	temp=(tp)malloc(sizeof(struct tf));
	temp->am=da;
	temp->n=NULL;
	
	int b1=(h1==NULL);
	int b2=((h1!=NULL)&&(temp->am<h1->am));
	int b3=((h1!=NULL)&&(t1->am<temp->am));
	int b4=((h1!=NULL)&&(h1->am<=temp->am)&&(temp->am<=t1->am));
	
	if (b1==1) 
	{
		printf("\n the head is null \n");
		h1=temp;
		t1=temp;
	}
	if (b2==1)
	{
		temp->n=h1;
		h1=temp;
	}
	if (b3==1)
	{
		t1->n=temp;
		t1=temp;
		if (h1->n==NULL)
		h1->n=t1;
	}
	if (b4==1)
	{
		aux=(tp)malloc(sizeof(struct tf));
		aux->n=h1;
		while ((aux->n!=NULL) && (aux->n->am<temp->am))
		aux=aux->n;
		if (aux->n->am==temp->am)
		printf("\n this am already exists in the list");
		if ((aux->am<temp->am) && (aux->n->am>temp->am))
		{ temp->n=aux->n;
		aux->n=temp;
		}
	}
	*h=h1;
	*t=t1;
}

void pri (tp h)
{
	tp aux;
	aux=h;
	int i=1;
	while (aux!=NULL)
	{
		printf("\nCurrent student with am %d is at position %d",aux->am,i);
		aux=aux->n;
		i++;		
	}
}
void pa (tp h)
{
	if(h==NULL)
    {
        return;
    }
	if (h!=NULL);
	{
	printf("\nStudent with am:%d",h->am);
	h=h->n;
	pa(h);
};


void menu()
{
	char fry='a', fry2='a';
	int check=0;
	tp h, t, aux, temp;
	h=NULL;
	t=NULL;
	while (fry!='Q')
	{
		printf("\nWELCOME\n press input \nP for print\nS for special print\nI for inserting student\nQ to quit program:\t");
		fry='a';
		fflush(stdin);
		fry=getchar();
		getchar();
		check=0;
		if (fry=='Q' || fry=='q')
		{ 
			fry='Q';
			check=1;
		}
		if (fry=='I' || fry=='i')
		{
			while(fry2!='e')
			{
				fry2='a';
				printf("\n INSERT\n give me the am integer:\t");
				int da=0;
				fflush(stdin);
				scanf("%d",&da);
				getchar();
				insert(&h, &t ,da);
				check=1;
				printf("Do you want to insert another one y/n?\n");
				fflush(stdin);
				fry2=getchar();
				getchar();
				if (fry2=='y' || fry2=='Y')
				{
					fry2='h';
				}
				if (fry2=='n' || fry2=='N')
				{
					fry2='e';
				}
				if ((fry2!='h') && (fry2!='e'))
					printf("\nInvalid input try again!");

			}
		check=1;
		}
		if (fry=='P' || fry=='p')
		{ 
		  if (h==NULL)
		  printf("\n There is no list\n");
		  else 
		  {
			printf("\n PRINTING\n\n");
			pri(h);
			check=1;
		  }
		}
		  if (fry=='S' || fry=='s')
		  {
			  if (h==NULL)
			  printf("\n there is no list\n");
			  else 
			 {
				printf("\n PRINTING\n\n");
				pa(h);
				check=1;
			 }
		 }
		if (!check)
		{
			printf("\n invalid input try again\n");
			fry='E';
		}
	}
};



int main(void){
menu();
return 0;
};

