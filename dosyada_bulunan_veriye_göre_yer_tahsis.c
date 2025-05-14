
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fp;
    char ch,veri[100];
    int satir_sayisi = 0;
    
    if((fp = fopen("veri.txt","r"))== NULL){
        printf("dosyaya ulasilamiyor\n");
        exit(1);
    }

    while ((ch = getc(fp)) != EOF) {
        if (ch == '\n') {
            satir_sayisi++;
        }
    }

    char **isim = (char**) malloc(sizeof(char*) * satir_sayisi);
    rewind(fp);

    for(int i = 0 ;i < satir_sayisi ;i++){
        if (fgets(veri, 100, fp) != NULL) {
            veri[strcspn(veri, "\n")] = '\0';
            isim[i] = (char*) malloc(strlen(veri) + 1);
            strcpy(isim[i],veri);
        }
    }

    for(int i =0; i < satir_sayisi;i++){
        printf("%d. satirda bulana isim : %s\n", i+1 , isim[i]);
        free(isim[i]);
    }
    free(isim);

    fclose(fp);
    return 0;

}