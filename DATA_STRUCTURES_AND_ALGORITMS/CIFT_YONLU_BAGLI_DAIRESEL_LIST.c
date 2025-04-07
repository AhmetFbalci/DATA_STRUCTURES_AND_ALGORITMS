#include <stdio.h>
#include <stdlib.h>
void sonaekle();
void goster();
void terstengoster();
void bastansil();
void sondansil();
void konumaekle();
void konumdansil();

struct node{
struct node *pre;
struct node *next;
int data;
};
struct node *head=NULL;
struct node *tail=NULL;
int main() {
    int secim;

    printf("--------------------------------------------------\n");
    printf("| 1 - Sona Ekleme\n");
    printf("| 2 - Tersten goster\n");
    printf("| 3 - Listeyi Goster\n");
    printf("| 4 - Bastan Sil\n");
    printf("| 5 - Sondan Silme\n");
    printf("| 6 - Konuma Ekleme\n");
    printf("| 7 - Konumdan silme\n");
    printf("| 8 - Programdan Cikis\n");
    printf("--------------------------------------------------\n");

    while (1) {
        printf("Seciminizi yapin: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                sonaekle();
                break;
            case 2:
                terstengoster();
                break;
            case 3:
                goster();
                break;
            case 4:
                bastansil();
                break;
            case 5:
                sondansil();
                break;
            case 6:
                konumaekle();
                break;
            case 7:
                konumdansil();
                break;
            case 8:
                printf("Programdan cikiliyor...\n");
                return 0;    
            default:
                printf("Gecersiz secim! Tekrar deneyin.\n");
        }
    }
    return 0;
}


void sonaekle()
{ 
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
     
    if(tmp== NULL)
    {

    printf("Bellekte yeterli alan yok");
    return;

    }
    printf("Eklenecek veriyi girin: ");
    scanf("%d", &tmp->data);
    tmp->next = NULL;
    tmp->pre=NULL;
    if(head == NULL)
    {
      head=tmp;
      tail=tmp;
      head->next=tail;
      head->pre=tail;
      tail->next=head;
      tail->pre=head;
      return;
    }
    tail->next=tmp;
    tmp->pre=tail;
    tail=tmp;
    tail->next=head;
    head->pre=tail;
}
void goster()
{
   struct node *ptr;
   if(head == NULL)
   {
    printf("liste bos");
    return;
   }
   ptr=head;
   while(ptr->next!=head)
   { 
    printf("%d ",ptr->data);
    ptr=ptr->next;


   }
   printf("%d\n ",ptr->data);
   
}

void terstengoster()
{
  if(head==NULL)
  {
    printf("liste bos");
    return;
  }
struct node *ptr;
ptr = tail;
while(ptr->pre!=tail)
{
   printf("%d ",ptr->data);
   ptr=ptr->pre;
}
printf("%d\n",ptr->data);
}

void sondansil()
{  
  struct node *ptr;
  if(head == NULL)
  {
    printf("listte bos");
    return;
  }
   if(head == tail)
  {
    printf("silinen veri:%d\n",head->data);
    head=NULL;
    tail=NULL;
    return;
  }
  
    ptr = tail;
    tail=tail->pre;
    tail->next=head;
    head->pre=tail;
    free(ptr); 
}
void bastansil()
{
  struct node *ptr;
  if(head == NULL)
  {
    printf("listte bos");
    return;
  }
  if(head == tail)
  {
    printf("silinen veri:%d\n",head->data);
    head=NULL;
    tail=NULL;
    return;
  }
  ptr=head;
  head=head->next;
  head->pre=tail;
  tail->next=head;
  printf("silinen veri:%d\n",ptr->data);
  free(ptr);
}
void konumaekle()
{
    struct node *tmp, *ptr;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->next = NULL;
    tmp->pre = NULL;

    int konum, i = 0;
    printf("Eklenecek konumu girin (0'dan başlayarak): ");
    scanf("%d", &konum);

    printf("Veriyi girin: ");
    scanf("%d", &tmp->data);

    if (head == NULL) {
        if (konum != 0) {
            printf("Liste boş, sadece 0. konuma eklenebilir.\n");
            free(tmp);
            return;
        }
        head = tmp;
        head->next = head;
        head->pre = head;
        tail = head;
        return;
    }

    if (konum == 0) {
        tmp->next = head;
        tmp->pre = tail;
        tail->next = tmp;
        head->pre = tmp;
        head = tmp;
        return;
    }

    ptr = head;
    while (i < konum - 1 && ptr->next != head) {
        ptr = ptr->next;
        i++;
    }

    if (i < konum - 1) {
        printf("Girilen konum listeden büyük!\n");
        free(tmp);
        return;
    }

    tmp->next = ptr->next;
    tmp->pre = ptr;
    ptr->next->pre = tmp;
    ptr->next = tmp;

    // tail güncellemesi (eğer sona eklendiyse)
    if (ptr == tail) {
        tail = tmp;
    }
}

void konumdansil()
{
  struct node *tmp, *ptr;
  int konum, i = 0;
    printf("silinecek konumu girin (0'dan başlayarak): ");
    scanf("%d", &konum);
    if(head ==NULL)
    {
      printf("liste bos");
      return;
    }
    if(konum == 0)
    {
     printf("silinen veri:%d\n",head->data);
     ptr=head;
     head=head->next;
     tail->next=head;
     head->pre=tail;
     free(ptr);
     return;
    }
    ptr=tmp=head;
    while(i < konum && ptr->next != head)
    {
      tmp=ptr;
      ptr=ptr->next;
      i++;
    }
    if(i < konum){
    printf("gecersiz konum\n");
    return;
    }
    printf("silinen veri:%d\n",ptr->data);
    tmp->next=ptr->next;
    ptr->next->pre=tmp;
    if (ptr == tail)
    tail = tmp;

free(ptr);



}
