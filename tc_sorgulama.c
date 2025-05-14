#include <stdio.h>

void kimlik(int tc[]);

int main(void) {
    int tc[11];
    printf("Kimlik no giriniz (11 haneli): ");
    for (int i = 0; i < 11; i++) {
        scanf("%1d", &tc[i]);
    }

    kimlik(tc);

    return 0;
}

void kimlik(int tc[]) {
    if (tc[0] == 0) {
        printf("Gecersiz numara.\n");
        return;
    }

    int x = 0, y = 0;
    for (int i = 0; i < 9; i += 2) {
        x += tc[i];
    }
    for (int i = 1; i < 9; i += 2) {
        y += tc[i];
    }
    int z = (x * 7 - y) % 10;

    if (z != tc[9]) {
        printf("Gecersiz numara.\n");
        return;
    }

    int sonhane = 0;
    for (int i = 0; i < 10; i++) {
        sonhane += tc[i];
    }
    if (sonhane % 10 != tc[10]) {
        printf("Gecersiz numara.\n");
        return;
    }

    printf("Gecerli numara.\n");
}
