#include <stdio.h>

// Hanoi çözüm fonksiyonu
void hanoi(int n, char kaynak, char hedef, char gecici) {
    if (n == 1) {
        printf("Diski %c'den %c'ye taşı\n", kaynak, hedef);
    } else {
        hanoi(n - 1, kaynak, gecici, hedef);
        printf("Diski %c'den %c'ye taşı\n", kaynak, hedef);
        hanoi(n - 1, gecici, hedef, kaynak);
    }
}

int main() {
    int disk_sayisi;

    printf("Disk sayısını girin: ");
    scanf("%d", &disk_sayisi);

    printf("\nAdımlar:\n");
    hanoi(disk_sayisi, 'A', 'C', 'B'); // A: kaynak, C: hedef, B: ara çubuk

    return 0;
}
