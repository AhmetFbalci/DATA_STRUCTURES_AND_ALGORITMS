#include <stdio.h>
#include <stdlib.h>

void sonaekle();
void basaekle();
void goster();
void bastansilme();
void sondansilme();
void konumaekle();
void konumdansilme();

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

int main() {
    int secim;

    printf("--------------------------------------------------\n");
    printf("| 1 - Sona Eklemee\n");
    printf("| 2 - Basa Ekleme\n");
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
                basaekle();
                break;
            case 3:
                goster();
                break;
            case 4:
                bastansilme();
                break;
            case 5:
                sondansilme();
                break;
            case 6:
                konumaekle();
                break;
            case 7:
                konumdansilme();
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

void sonaekle() {
    struct node *ptr, *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));

    if (tmp == NULL) {
        printf("Yetersiz bellek!\n");
        return;
    }
    printf("Eklenecek veriyi girin: ");
    scanf("%d", &tmp->data);
    tmp->next = NULL;

    if (start == NULL) {
        start = tmp;
    } else {
        ptr = start;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = tmp;
    }
    printf("Veri sona eklendi.\n");
}

void goster() {
    struct node *ptr;
    if (start == NULL) {
        printf("Liste bos.\n");
        return;
    }
    printf("Liste: ");
    ptr = start;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void basaekle() {
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL) {
        printf("Yetersiz bellek!\n");
        return;
    }
    printf("Eklenecek veriyi girin: ");
    scanf("%d", &tmp->data);
    tmp->next = NULL;

    if (start == NULL) {
        start = tmp;
    } else {
        tmp->next = start;
        start = tmp;
    }
    printf("Veri basa eklendi.\n");
}

void bastansilme() {
    struct node *ptr;
    if (start == NULL) {
        printf("Liste bos.\n");
        return;
    } else {
        ptr = start;
        printf("Silinen veri: %d\n", ptr->data);
        start = start->next;
        free(ptr);
        printf("Bastan silme islemi tamamlandi.\n");
    }
}

void sondansilme() {
    struct node *tmp, *ptr;
    if (start == NULL) {
        printf("Liste bos.\n");
        return;
    } else if (start->next == NULL) {
        printf("Silinen veri: %d\n", start->data);
        free(start);
        start = NULL;
        printf("Sondan silme islemi tamamlandi.\n");
        return;
    } else {
        ptr = start;
        while (ptr->next != NULL) {
            tmp = ptr;
            ptr = ptr->next;
        }
        tmp->next = NULL;
        printf("Silinen veri: %d\n", ptr->data);
        free(ptr);
        printf("Sondan silme islemi tamamlandi.\n");
    }
}

void konumaekle() {
    struct node *tmp, *ptr;
    int konum;
    tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL) {
        printf("Yetersiz bellek!\n");
        return;
    }
    printf("Eklenecek konumu girin (0'dan baslayarak): ");
    scanf("%d", &konum);
    printf("Eklenecek veriyi girin: ");
    scanf("%d", &tmp->data);
    tmp->next = NULL;

    if (konum == 0) {
        tmp->next = start;
        start = tmp;
        printf("Veri bas konuma eklendi.\n");
        return;
    }
    ptr = start;
    for (int i = 0; ptr != NULL && i < konum - 1; i++) {
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Gecersiz konum!\n");
        free(tmp);
        return;
    }
    tmp->next = ptr->next;
    ptr->next = tmp;
    printf("Veri %d. konuma eklendi.\n", konum);
}
void konumdansilme()
{
    struct node  *ptr,*tmp;
    int konum;
    printf("silinecek konumu girin (0'dan baslayarak): ");
    scanf("%d", &konum);
    if(konum == 0)
    {
       ptr=start;
       start=start->next;
       
       printf("Silinen veri: %d\n", ptr->data);
       free(ptr);
       printf("konumdan silme islemi tamamlandi.\n"); 
       return;
    }
    ptr=start;
    for (int i = 0; ptr != NULL && i < konum; i++) {
        tmp = ptr;
        ptr = ptr->next;
    }
    tmp->next=ptr->next;
    ptr->next=NULL;
    printf("Silinen veri: %d\n", ptr->data);
    free(ptr);
    printf("konumdan silme islemi tamamlandi.\n");  
}