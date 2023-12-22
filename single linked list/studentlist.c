#include<stdio.h>
#include<stdlib.h>

typedef struct tf *tp;
    struct tf
    {   int am;
        double gr;
        tp n;
    };

tp h,t,temp,aux;

void insert(tp *h,tp *t);
void print1(tp h);
void print2(tp h);
void delstud(tp *h,tp *t);

char fry;

int main(void){
    fry='a';
    h=NULL;
    t=NULL;
    printf("\nWelcome to pro_list \n");
    while(fry!='q')
    {
        fry='a';
        printf("\nPress\ti:to INSERT or d:to DELETE a student and p:to PRINT1 or t:to PRINT2  all students from our list or q:QUIT\n",fry);
        fflush(stdin);
        fry=getchar();
        getchar();
        switch (fry)
        {
            case 'q':
            case 'Q':
                printf("QUIT\n");
                return 0;
                break;
            case 'i':
            case 'I':
                printf("INSERT\n");
                insert(&h,&t);
                break;
            case 'd':
            case 'D':
                printf("DELETE\n");
                if((h)==NULL)
                    printf("The list is empty");
                if(h!=NULL)
                    delstud(&h,&t);
                break;
            case 'p':
            case 'P':
                printf("PRINT_1\n");
                if(h==NULL)
                    printf("The list is empty\n");
                if(h!=NULL)
                    print1(h);
                break;
            case 't':
            case 'T':
                printf("PRINT_2\n");
                if(h==NULL)
                    printf("The list is empty\n");
                if(h!=NULL)
                    print2(h);
            
            default:
                printf("Please insert a character that is allowed\n");
                break;
        }
    }
    return 0;
}

void insert(tp *h,tp *t)
{
    tp temp,aux;
    int da;
    temp=(tp)malloc(sizeof(struct tf));
    printf("Give me the AM integer\n");
    scanf("%d",&da);
    getchar();
    temp->am=da;
    temp->n=NULL;
    printf("Using temp=%d as the am you gave.\n",temp->am);
    if((*h!=NULL)&&((*h)->am==temp->am))
       {printf("That am already exists\n");return;}
    if((*h!=NULL) && (temp->am < (*h)->am))
    {
        printf("The am you inserted is the lowest of our list.\n");
        temp->n=*h;
        *h=temp;
        printf("The am now is at first position of our list.\n");
    }
    if((*h!=NULL) && ((*h)->n!=NULL) && (temp->am > (*h)->am))
    {
        int i=2;
        aux=*h;
        printf("The am you gave is bigger than headers of list.\n");
        while((aux->n!=NULL) && (aux->n->am < temp->am))
        {
            i++;
            printf("Checking for next\nThe am is bigger from next.\n");
            aux=aux->n;
        }
        if(aux->n!=NULL)
        {
            if(aux->n->am==temp->am)
            {
                do
                {
                    aux=aux->n;
                }
                while(aux->n!=NULL);
                 *t=aux;
                 printf("After checking that am already exists\n");
                 return;
            }

                printf("inserting at position %d\n",i);
                temp->n=aux->n;
                aux->n=temp;
        }
        if(aux->n==NULL)
        {
            printf("We found the last am from list and our am is bigger. So inserting last.\n");
            temp->n=aux->n;
            aux->n=temp;
            *t=temp;
        }
    }
    if((*h!=NULL) && ((*h)->n==NULL) && (temp->am > (*h)->am))
    {
        printf("That was the second am inserting at list, and the last one\n");
        (*h)->n=temp;
        *t=temp;
    }
    if((*h)==NULL)
    {
        printf("The HEAD is NULL, the list was empty we insert the first\n");
        *h=temp;
        *t=temp;
        printf("First %d\n",temp->am);
    }
}

void print1(tp h)
{
    tp aux;
    aux=h;
    int i=1;
    while(aux!=NULL)
    {
        printf("Student:%d at Position in list:%d\n",aux->am,i);
        aux=aux->n;
        i++;
    }
}

void print2(tp h)
{
	if(h==NULL)
    {
        return;
    }
	if(h!=NULL)
	{
		printf("Student with am=%d\n",h->am);
		h=h->n;
		print2(h);
	}

}

void delstud(tp *h,tp *t)
{
	int AM;
	printf("Give the am that you want to delete\n");
	scanf("%d",&AM);
	getchar();
	if(((*h)!=NULL)&&((*h)->am==AM))
    {
        printf("This am was our header and does not exist at our list now\n");
        if((*h)->n==NULL)
        printf("The list now is empty\n");
        aux=*h;
		*h=(*h)->n;
		free(aux);
		return;
    }
    if((*h!=NULL)&&((*h)->am!=AM)&&((*h)->n==NULL))
    {
        printf("Our list has only one am and isnt that.\n ");
    }
    if((*h!=NULL)&&((*h)->am!=AM)&&((*h)->n!=NULL))
    {
        aux=*h;
        while((aux->n->am!=AM)&&(aux->n!=*t))
        {
            aux=aux->n;
        }
        if((aux->n->am!=AM)&&(aux->n==*t))
        {
            printf("This am does not exist at our list.\n");
            return;
        }
        tp aux2=aux->n;
        if(aux2==*t)
        {
            *t=aux;
        }
        aux->n=aux->n->n;
        free(aux2);
        printf("Fixed the tail and the am deleted.\n");
    }
}


