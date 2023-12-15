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
		printf("\n The head was null, and you input was inserted on head pointer\n");
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
		printf("This am already exists in the list\n");
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
		printf("Current student with am %d is at position %d\n",aux->am,i);
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
	printf("Student with am:%d\n",h->am);
	h=h->n;
	pa(h);
    }
}

void diag(tp *h, tp *t)
{
	int am1;
	printf("Give the am that you want to delete\n");
	fflush(stdin);
	scanf("%d",&am1);
	getchar();
	if(((*h)!=NULL)&&((*h)->am==am1)&&((*h)->n==NULL))
	{
		printf("The am you gave is the only am on the list, hence the list is now empty");
		aux=(*h);
		(*h)=(*h)->n;
		free(aux);
		return;
	}
	if(((*h)!=NULL)&&((*h)->am!=am1)&&((*h)->n==NULL))
		{
			printf("The list has one am and it is not it");
			return;
		}
	if(((*h)!=NULL)&&((*h)->n!=NULL)&&((*h)->am!=am1))
	{
		aux=(*h);
		while((aux->n->am!=am1)&&(aux->n!=*t))
		{
		aux=aux->n;
		}
		if((aux->n->am!=am1)&&(aux->n==*t))
		{
			printf("There is no such am in this list");
			return;
		}
		tp aux2=aux->n;
		if(aux2==*t)
		{
			*t=aux;
		}
		aux->n=aux->n->n;
		free(aux2);
		printf("bruh fixed the tail\n");
		return;
	}
}
	
void menu()
{
	char fry='a', fry2='a';
	int check=0;
	tp h, t, aux, temp;
	h=NULL;
	t=NULL;
	while (fry!='Q')
	{
		printf("\nWELCOME\nPress input \nP for print\nS for special print\nI for inserting student\nD for deleting\nQ to quit program:\t");
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
		if (fry=='D' || fry=='d')
		{
			if (h==NULL)
			{
				printf("\n There is no list\n");
				check=1;
			}
			else
			{	
			printf("Deleting\n");
			diag(&h, &t);
			check=1;
			}
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
		fry2='a';
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
		check=1;
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
		check=1;
		 }
		if (!check)
		{
			printf("\nInvalid input try again\n");
			fry='E';
		}
	}
}



int main(void){
menu();
return 0;
}


