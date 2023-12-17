#include <stdio.h>
#include <stdlib.h>

typedef struct tf* tp;
	struct tf
	{
	int am;
	double gr;
	tp n;
	};
	
tp s,b,aux,temp;
char fry;

void push (tp *s, tp *b, int da) //this creates a stack "block"
{
	tp temp,aux,s1= *s,b2= *b;
	temp=(tp)malloc(sizeof(struct tf));
	temp->am=da;
	temp->n=NULL;
	printf("Using temporary stack with am=%d\n",temp->am);
	if ((*s)==NULL)
	{
		printf("The stack is empty, made the first stack\n");
		*s=temp;
		*b=temp;
	}
	if((*s)!=NULL)
	{
		printf("Stacking\n");
		temp->n=*s;
		*s=temp;		
	}
}

void pri (tp s) //this prints with pointer traverse
{
	tp aux;
	aux=s;
	int i=1;
	while (aux!=b)
	{
		printf("Current student with am %d is at position %d\n",aux->am,i);
		aux=aux->n;
		i++;		
	}
}

void pa (tp s) //this prints recursively
{
	if(s==NULL)
    {
        return;
    }
	if (s!=NULL);
	{
	printf("Student with am:%d\n",s->am);
	s=s->n;
	pa(s);
    }
}

void pop(tp *s, tp *b) //this deletes the stack "block"
{
	tp aux=*s;
	if((*s)==NULL)
	printf("There is NO stack/n");
	if((*s)->n==NULL)
	{
		printf("Popping the only Stack!\n");
		*s=(*s)->n;
		free(aux);
		printf("Stack is empty\n");
		return;
	}
	if((*s)!=*b)
	{
		printf("Popping the top stack\nMinus one stack\n");
		*s=(*s)->n;
		free(aux);
		return;
	}
}
	
void menu()
{
	char fry='a', fry2='a';
	int check=0;
	tp h, t, aux, temp;
	s=NULL;
	b=NULL;
	printf("WELCOME to Stack incorporated!\n");
	while (fry!='Q')
	{
		printf("\nPress input \nP for print\nS for recursive print\nI to push\nD to pop\nQ to quit program:\t");
		fry='a';
		fflush(stdin);
		fry=getchar();
		getchar();
		check=0;
		if (fry=='Q' || fry=='q')
		{
			fry='Q';
			check=1;
			return;
		}
		if (fry=='D' || fry=='d')
		{
			if (s==NULL)
			{
				printf("\n There is no Stack\n");
				check=1;
			}
			else
			{	
			printf("Popping\n");
			pop(&s, &b);
			check=1;
			}
		check=1;
		}
		if (fry=='I' || fry=='i')
		{
			while(fry2!='e')
			{
				fry2='a';
				printf("\nPUSH\nGive me the am integer to stack:\t");
				int da=0;
				fflush(stdin);
				scanf("%d",&da);
				getchar();
				push(&s, &b ,da);
				check=1;
				printf("\nDo you want to stack another one y/n?\n");
				fflush(stdin);
				fry2=getchar();
				getchar();
				if (fry2=='y' || fry2=='Y')
				{
					fry2='h';
				}
				else if (fry2=='n' || fry2=='N')
				{
					fry2='e';
				}
				else
					((fry2!='h') && (fry2!='e'));
					printf("\nInvalid input try again!");
			}
		fry2='a';
		check=1;
		}
		if (fry=='P' || fry=='p')
		{ 
		  if (h==NULL)
		  printf("\nThere is no Stack\n");
		  else 
		  {
			printf("\nPRINTING\n\n");
			pri(s);
			check=1;
		  }
		check=1;
		}
		if (fry=='S' || fry=='s')
		{
			  if (h==NULL)
			  printf("\nThere is no Stack\n");
			  else 
			 {
				printf("\nPRINTING\n\n");
				pa(s);
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


int main(void)
{
	menu();
	return 0;
}

