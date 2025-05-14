
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    int *str;
    int i = 0,k = 0,veri;

    if((fp = fopen("dosya.txt","r")) == NULL){
        printf("Dosya acilmadi...");
        exit(1);

    }
    str = (int*) malloc(sizeof(int));

    while (fscanf(fp, "%d", &veri) != EOF)
    {
        str = (int*) realloc(str,sizeof(int) * ( i + 1));
        str[i] = veri;
        i++;
    }

    fclose(fp);

    for(int j = 0;j<i;j++){
        printf("icinde bulan sayi: %d\n",str[j]);
    }

}