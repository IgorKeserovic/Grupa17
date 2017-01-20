#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void meni()
{
    int i;
    do
    {
        printf("Odaberite jednu od opcija:\n");
        printf("[1] Izdavanje kartice\n");
        printf("[2] Pomoc\n");
        printf("[3] Odjava\n");

        scanf("%d", &i);
        if(i!=1 && i!=2 && i!=3)
        {

            do
            {
                printf("Pogresna opcija, pokusajte ponovo\n");
                scanf("%d", &i);
            }
            while(i!=1 && i!=2 && i!=3);//Jedine dozvoljene opcije su 1,2 i 3
        }
        if(i==1)
        {
            printf("Stampanje kartice....molimo Vas da sacekate\n");//Izgled kartice
            printf("-------------------------------\n");
            printf("|         DOBRODOSLI!         |\n");
            printf("|   Putevi Republike Srpske   |\n");
            printf("|                             |\n");
            format_time();
            printf("|                             |\n");
            printf("|      Mjesto: Gradiska       |\n");
            printf("|                             |\n");
            printf("-------------------------------\n");

        }
        else if (i==2)//Pomoc
        {
            printf("Kako biste dobili karticu i nastavili sa putovanjem molimo Vas da uradite sljedece:\n");
            printf("-Odaberite opciju [1]\n");
            printf("-Sacekajte nekoliko sekundi\n");
            printf("-Preuzmite karticu\n");
            printf("-Odjavite se pomocu opcije [3]\n\n");
        }
        else return printf("Srecan put!\n"), 0;//Za opciju 3, posto su 1 i 2 vec definisane a sve ostale nisu dozvoljene
    }
    while(i!=3);//Dok god korisnik kuca bilo koji broj osim '3' meni mu se pojavljuje

}

void format_time()//Funkcija koja ispisuje trenutni datum i vrijeme
{
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    printf("|     %d %d %d %d:%d:%d     |\n",timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
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


    if(!(fp=fopen("Baza_Podataka.txt", "r"))) return printf("Baza podataka nije pronadjena"), 0;//Ako ne postoji tekstualni dokument sa imenom "Baza_Podakata"
    printf("Ukucajte ime:\n");
    scanf("%s", ime);
    printf("Ukucajte prezime:\n");
    scanf("%s", prezime);
    printf("Ukucajte sifru:\n");
    scanf("%s", sifra);
    //Ime, prezime i sifra se spajaju u jedan string posto je takav format upisa u bazu podataka
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
    if (brojac==0) printf("Pogresno Ime, Prezime ili Sifra.\n");//Ako ne postoji odredjena osoba sa tom sifrom u bazi podataka
    return 0;
}
