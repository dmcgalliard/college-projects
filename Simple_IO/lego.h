#ifndef LEGO_H
#define LEGO_H


typedef struct 
{ 
    int pieces;
    char setName[50];
    char theme[50];
} Lego;

void saveLego(const char *filename, Lego* lego);
void loadLego(const char *filename, Lego* lego);

#endif
