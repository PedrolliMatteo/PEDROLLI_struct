#include <stdio.h>
#include <stdlib.h>

typedef struct      //senza typedef dovrei scrivere struct Cocktail{} e
{                   //dovrei scrivere ogni volta struct Cocktail variabile
    char *nome;
    float prezzo;
    short int percentualeAlcol;
}
Cocktail;

void stampa(Cocktail *cocktail);

int main(void)
{
    //creo l'identità mojito
    Cocktail *mojito = malloc(sizeof(Cocktail));
    //per usare gli attributi dei puntatori devo usare
    //la freccetta al posto del punto
    mojito -> nome = "Mojito";
    mojito -> prezzo = 5.50f;
    mojito -> percentualeAlcol = 10;

    Cocktail *caipirina = malloc(sizeof(Cocktail));
    caipirina -> nome = "Caipirina";
    caipirina -> prezzo = 8.50f;
    caipirina -> percentualeAlcol = 15;

    Cocktail * listino_malloc = malloc(sizeof(Cocktail) * 10);
    listino_malloc[0] = *mojito;
    listino_malloc[1] = *caipirina;

    for (int i = 0; i < 2; i++)
    {
        stampa(listino_malloc + i);
    }

    free(listino_malloc);
    listino_malloc = NULL;
    free(mojito);
    mojito = NULL;
    free(caipirina);
    caipirina = NULL;
    return 0;
}

void stampa (Cocktail *cocktail)
{
    printf("Nome:\t%s\n", cocktail -> nome);
    printf("Prezzo:\t%.2f\n", cocktail -> prezzo);
    printf("Alcol:\t%d%\n", cocktail -> percentualeAlcol);
}