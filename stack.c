#include<stdio.h>
#include<stdlib.h>
void push();
void goster();
void pop();
void top();
void size();
void isempty();

struct stack{
int data;
struct stack *next;
};
struct stack *son;

int  main()
{
    
isempty();
push();
push();
push();
size();
top();
goster();
size();
pop();
size();
goster();
top();
isempty();

return 0;
}

void push()
{
    struct stack *tmp;
    tmp=(struct stack *)malloc(sizeof(struct stack));
    tmp->next=NULL;
   if(tmp == NULL)
   {
    printf("bellek yetersiz");
    return;
   }
   printf("veriyi girin:\n");
   scanf("%d",&tmp->data);
   if(son == NULL)
   {
     son=tmp;
     return;
   }
   tmp->next=son;
   son=tmp;
}
void goster()
{ if(son==NULL)
    {
        printf("liste bos\n");
        return;
    }
  struct stack *ptr;
  ptr=son;
while(ptr->next != NULL)
{
 printf("%d ",ptr->data);
 ptr=ptr->next;
}
printf("%d\n",ptr->data);
}
void pop()
{
  if(son == NULL)
  {
   printf("liste bos\n");
   return;
  }
  struct stack *ptr;
  ptr=son;
  son=son->next;
  printf("cikarilan veri:%d\n",ptr->data);
  free(ptr);
}
void top()
{
 if(son == NULL)
 {
    printf("liste bos\n");
    return;

}
  printf("%d\n",son->data);

}


void size()
{

if (son == NULL)
{
    printf("liste bos\n");
    return;
}

struct stack *ptr;
ptr=son;
int size=0;
   while (ptr != NULL)
 {
    ptr=ptr->next;
    size++;
    
 }
 printf("%d\n",size);
}
void isempty()
{
    if(son == NULL){
        printf("liste bos\n");
        return;
    
    }
    printf("liste dolu");
}