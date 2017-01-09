#include <stdio.h>
#include <stdlib.h>

void serija(int *niz, int n, int (*s)(int), int **pocetak, int *duzina);
int serija_parnih(int);
int serija_pozitivnih(int);

int main()
{
    int *pocetak, i;
    int duzina;
    int n;
    printf("n = ");scanf("%d",&n);
    int *niz = (int *)malloc(n*sizeof(int));
    for(i=0; i<n; i++)
    {
        printf("niz[%d]: ",i);
        scanf("%d",&niz[i]);
    }

    pocetak = NULL;
    serija(niz, n, serija_parnih, &pocetak,&duzina);
    if(pocetak != NULL)
    {
        printf("Duzina serije parnih: %d\n",duzina);
        printf("Pocetni broj serije parnih: %d\n",*pocetak);
    }
    else
        printf("Parna serija ne postoji");

    printf("\n");

    pocetak = NULL;
    serija(niz, n, serija_pozitivnih, &pocetak,&duzina);
    if(pocetak != NULL)
    {
        printf("Duzina serije pozitivnih: %d\n",duzina);
        printf("Pocetni broj serije pozitivnih: %d\n",*pocetak);
    }
    else
        printf("Pozitivna serija ne postoji");

    free(niz);
    return 0;
}

void serija(int *niz, int n, int (*s)(int), int **pocetak, int *duzina)
{
    int max = 0;
    int i,j;
    int br=0;
    int indeks;
    for(j=0;j<n;j++)
    {
        for(i=j;i<n && (*s)(niz[i])==1;i++)
        {
            br++;
        }
        if(br>max)
        {
            max = br;
            indeks = j;
        }
        br = 0;
    }
    if(max!=0)
    {
        *pocetak = niz+indeks;
        *duzina = max;
    }
}

int serija_pozitivnih(int n)
{
    if(n>0)
        return 1;
    else
        return -1;
}
int serija_parnih(int n)
{
    if(n%2==0)
        return 1;
    else
        return -1;
}
