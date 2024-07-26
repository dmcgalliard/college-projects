#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "lego.h"

void saveLego(const char* filename, Lego* lego)
{
    FILE *file = fopen(filename, "wb");
    if(file == NULL) 
    { 
        perror("Error opening file");
        exit(1);
    }

    fwrite(lego, sizeof(Lego), 1, file);
    fclose(file);
}

void loadLego(const char* filename, Lego* lego)
{
    FILE *file = fopen(filename, "rb");
    if(file == NULL)
    {
        perror("Error opening file");
        exit(1);
    }
    fread(lego, sizeof(Lego), 1, file);
    fclose(file);
}

int main() 
{
    Lego l1;
   

    printf("Enter set name please: \n");
    fgets(l1.setName, sizeof(l1.setName), stdin);
    l1.setName[strcspn(l1.setName, "\n")] =0;

    printf("Enter number of pieces please: \n");
    scanf("%d", &l1.pieces);
    while(getchar() != '\n');

    printf("Enter theme please \n");
    fgets(l1.theme, sizeof(l1.theme), stdin);
    l1.theme[strcspn(l1.theme, "\n")] =0;

    saveLego("lego.dat", &l1);

    Lego l2;
    loadLego("lego.dat", &l2);

   /* Lego l1 = {pieces, setName, theme};
    saveLego("lego.dat", &l1);

    Lego l2;
    loadLego("lego.dat", &l2);
    */

    printf("Set: %s, Pieces: %d, Theme: %s", l2.setName, l2.pieces, l2.theme);

    return 0;

}



