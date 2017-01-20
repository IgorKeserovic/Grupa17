#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void izdavanje_racuna(float osnovica)
{
    int kilometri=rand()%500;//Pseudo-random broj koji predstavlja broj predjenih kilometara
    float cijena_bez_pdv=osnovica*kilometri;//Cijena bez DPV-a
    float cijena_sa_pdv=(cijena_bez_pdv/100)*17+cijena_bez_pdv;//Cijena sa PDV-om
    char postotak='%';
    //Izgled racuna
    printf("---------------------------------------\n");
    printf("|                RACUN!               |\n");
    printf("|       Putevi Republike Srpske       |\n");
    printf("|                                     |\n");
    format_time();
    printf("|                                     |\n");
    printf("|      Presli ste %d kilometara       |\n", kilometri);
    printf("|                                     |\n");
    printf("|    Cijena bez PDV-a: %.4f         |\n", cijena_bez_pdv);
    printf("|    Cijena sa PDV-om (17%c): %.4f   |\n", postotak,cijena_sa_pdv);
    printf("|                                     |\n");
    printf("---------------------------------------\n");
}

void meni()
{
    int i, j;
    do
    {
        printf("Odaberite jednu od opcija:\n");
        printf("[1] Placanje putarine\n");
        printf("[2] Pomoc\n");
        printf("[3] Cjenovnik\n");
        printf("[4] Odjava\n");

        scanf("%d", &i);
        if(i!=1 && i!=2 && i!=3 && i!=4)
        {

            do
            {
                printf("Pogresna opcija, pokusajte ponovo\n");
                scanf("%d", &i);
            }
            while(i!=1 && i!=2 && i!=3 &&i!=4);//Dozvoljene opcije su 1, 2, 3 i 4
        }
        if(i==1)
        {
            printf("Odaberite kategoriju prevoznog sredstva:\n");
            printf("Za I   kategoriju pritisnite 1\n");
            printf("Za II  kategoriju pritisnite 2\n");
            printf("Za III kategoriju pritisnite 3\n");
            printf("Za IV  kategoriju pritisnite 4\n");
            printf("Za V   kategoriju pritisnite 5\n");
            scanf("%d", &j);
            if(j!=1 && j!=2 && j!=3 && j!=4 && j!=5)
            {
                do
                {
                    printf("Pogresna opcija, pokusajte ponovo\n");
                    scanf("%d", &j);
                }
                while(j!=1 && j!=2 && j!=3 && j!=4 && j!=5);//Dozvoljene kategorije vozila su od 1 do 5
            }
            if(j==1)//Cijene za razlicite kategorije vozila
                izdavanje_racuna(0.03);
            else if(j==2)
                izdavanje_racuna(0.035);
            else if(j==3)
                izdavanje_racuna(0.045);
            else if(j==4)
                izdavanje_racuna(0.05);
            else if(j==5)
                izdavanje_racuna(0.07);
        }
        else if (i==2)//Uputstvo
        {
            printf("\nKATEGORIJE VOZILA\n\n");
            printf("1a. kategorija\n\n");
            printf("a) Motorna vozila sa karakteristikama motocikla, motornog trocikla i cetvorocikla\n\n");


            printf("1. kategorija\n\n");
            printf("a) Motorna vozila sa dve osovine i visine jednake ili nize od 1,3m mjereno kod prve osovine\nb) Motorna-kombi vozila sa dve osovine i ukupne visine jednake ili nize od 1,9m, a cija najveca dopustena masa ne prelazi 3.500kg\n\n");

            printf("2. kategorija\n\n");
            printf("a) Motorna vozila sa dve osovine i visine jednake ili nize od 1,3m kod prve osovine, sa prikolicom\nb) Motorna-kombi vozila sa dve osovine i ukupne visine jednake ili nize od 1,9m, a cija najveca dopustena masa ne prelazi 3.500kg sa prikolicom\nc) Motorna-kombi vozila sa dve osovine i ukupne visine vece od 1,9m, a cija najveca dopustena masa ne prelazi 3.500kg\n\n");

            printf("3. kategorija \n\n");
            printf("a) Motorna vozila sa dve ili tri osovine, visine vece od 1,3m mjereno kod prve osovine, a cija najveca dopustena masa prelazi 3.500kg\nb) Motorna-kombi vozila sa dve osovine i ukupne visine veca od 1,9m, a cija najveca dopustena masa ne prelazi 3.500kg sa prikolicom\n\n");
            printf("4. kategorija \n\n");
            printf("a) Motorna vozila sa cetiri i vise osovina (racunajuci i osovine prikolica) visine veca od 1,3m mjereno kod prve osovine a cija najveca dopustena masa prelazi 3.500kg\n\n");

        }
        else if(i==3)//Cjenovnik
        {
            printf("I   kategorija - 0,03KM  po kilometru bez PDVa\n");
            printf("II  kategorija - 0,035KM po kilometru bez PDVa\n");
            printf("III kategorija - 0,045KM po kilometru bez PDVa\n");
            printf("IV  kategorija - 0,05KM  po kilometru bez PDVa\n");
            printf("V   kategorija - 0,07KM  po kilometru bez PDVa\n\n");
        }

        else return printf("Srecan put!\n"), 0;//Izlaz
    }
    while(i!=4);

}

void format_time()//Funkcija koja racuna trenutni datum i vrijeme
{
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    printf("|          %d %d %d %d:%d:%d        |\n",timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
}

int main()
{
    //Baza podataka je tekstualni dokument sa imenom "Baza_Podataka" i ekstenzijom ".exe"
    //Osobe se u bazu podataka unose u formatu ImePrezimeSifra , bez space-eva izmedju kako
    //bi se smanjilo koristenje memorije. Osobe su od drugih odvojene novim redom (enter).
    FILE *fp;
    char ime_prezime_sifra[100];
    int brojac=0;
    char ime[20], prezime[30], sifra[7], login[100]= {};


    if(!(fp=fopen("Baza_Podataka.txt", "r"))) return printf("Baza podataka nije pronadjena"), 0;
    printf("Ukucajte ime:\n");
    scanf("%s", ime);
    printf("Ukucajte prezime:\n");
    scanf("%s", prezime);
    printf("Ukucajte sifru:\n");
    scanf("%s", sifra);

    strcat(login, ime);
    strcat(login, prezime);
    strcat(login, sifra);

    while(fscanf(fp, "%s", ime_prezime_sifra)!=EOF)
    {
        if(strcmp(login,ime_prezime_sifra)==0)
        {
            brojac++;
            meni();
        }
    }
    if (brojac==0) printf("Pogresno Ime, Prezime ili Sifra.\n");
    return 0;
}
