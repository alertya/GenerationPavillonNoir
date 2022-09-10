#include "Origine.h"
#include "Comp.h"
#include "Profession.h"
#define _XOPEN_SOURCE_EXTENDED 1
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <Windows.h>
/*
-Evenement solitaire bugue
-Non prise en compte des avantages faiblesse
-Competence pouvant etre au dessus de 3 a la creation
-Habitant et planteur bug
-Amuseurs bug
*/
char* Copy(char *source);
int RecupMetier(char* filename,char **m);
void RempliOri(Origine t,Competence* g);
void RempliFini(int nb, Competence* g);
void SaveFile(int i,char* name, Competence* g, char *Ori, char *Eve1,char *Eve2);
void CalculMetier(char* filename, char** m,Competence *g,char *Ori,char * nom);
char *ScoreProfession(Competence*g, char*Ori);
char *AddProfession(Competence*g, char*Ori);
void clrBuffer(void);
char *AddProfessionChoose(Competence *g,char * Ori, char *met);
char* RemoveChars(char *str, char c);
int main()
{
    int i;

    int j;
    int k=0;
    char* name="metier.txt";

    char **prof=(char**)malloc(1000*(sizeof(char*)));
    for(i=0; i<1000; i++)
    {
        prof[i]=(char*)malloc(40*sizeof(char));
    }
    char *metiers[24];
    for(i=0; i<24; i++)
    {
        metiers[i]=(char*)malloc(40*sizeof(char));
    }



    RecupMetier(name,metiers);

    fflush(stdout);
    fflush(stdin);
    char ** Metiers[20];
//INITIALISATION METIERS DISPOS EN FONCTION ORIGINE
    Metiers[0]=(char**)malloc(3*sizeof(char*));
    Metiers[0][0]="Lire";
    Metiers[0][1]="Art1";
    Metiers[0][2]="Art2";

    Metiers[1]=(char**)malloc(2*sizeof(char*));
    Metiers[1][0]="Ballistique";
    Metiers[1][1]="Escrime";
    Metiers[2]=(char**)malloc(7*sizeof(char*));
    Metiers[2][0]="Droit";
    Metiers[2][1]="Ballistique";
    Metiers[2][2]="Etiquette";
    Metiers[2][3]="Hydrographie";
    Metiers[2][4]="Lire";
    Metiers[2][5]="Politique";
    Metiers[2][6]="Sciences";
    Metiers[3]=(char**)malloc(3*sizeof(char*));
    Metiers[3][0]="Artisanat1";
    Metiers[3][1]="Hydrographie";
    Metiers[3][2]="Survie";
    Metiers[4]=(char**)malloc(13*sizeof(char*));
    Metiers[4][0]="Droit";
    Metiers[4][1]="Ballistique";
    Metiers[4][2]="Etiquette";
    Metiers[4][3]="Hydrographie";
    Metiers[4][4]="Lire";
    Metiers[4][5]="Politique";
    Metiers[4][6]="Sciences";
    Metiers[4][7]="ConnSpe1";
    Metiers[4][8]="ConnSpe2";
    Metiers[4][9]="Intendance";
    Metiers[4][10]="IngenierieNavale";
    Metiers[4][11]="Medecine";
    Metiers[4][12]="Navigation";
    Metiers[5]=(char**)malloc(1*sizeof(char*));
    Metiers[5][0]="Larcins";
    Metiers[6]=(char**)malloc(7*sizeof(char*));
    Metiers[6][0]="Voilerie";
    Metiers[6][1]="Ballistique";
    Metiers[6][2]="Cartographie";
    Metiers[6][3]="Hydrographie";
    Metiers[6][4]="ConnaissancesNautiques";
    Metiers[6][5]="ConnaissanceSignalisation";
    Metiers[6][6]="Navigation";
    Metiers[7]=(char**)malloc(7*sizeof(char*));
    Metiers[7][0]="Etiquette";
    Metiers[7][1]="Ballistique";
    Metiers[7][2]="Escrime";
    Metiers[7][3]="Hydrographie";
    Metiers[7][4]="Lire";
    Metiers[7][5]="Politique";
    Metiers[7][6]="Navigation";
    Metiers[8]=(char**)malloc(2*sizeof(char*));
    Metiers[8][0]="Artisanat1";
    Metiers[8][1]="Artisanat2";
    Metiers[9]=(char**)malloc(5*sizeof(char*));
    Metiers[9][0]="Art1";
    Metiers[9][1]="Art2";
    Metiers[9][2]="Charpenterie";
    Metiers[9][3]="Herboristerie";
    Metiers[9][4]="Survie";
    Metiers[10]=(char**)malloc(1*sizeof(char*));
    Metiers[10][0]="Etiquette";
    Metiers[12]=(char**)malloc(4*sizeof(char*));
    Metiers[12][0]="Art1";
    Metiers[12][1]="Art2";
    Metiers[12][2]="Etiquette";
    Metiers[12][3]="Lire";
    Metiers[11]=(char**)malloc(0*sizeof(char*));
    Metiers[13]=(char**)malloc(2*sizeof(char*));
    Metiers[13][0]="Artisanat1";
    Metiers[13][1]="Artisanat2";
    Metiers[14]=(char**)malloc(1*sizeof(char*));
    Metiers[14][0]="Larcins";
    Metiers[15]=(char**)malloc(2*sizeof(char*));
    Metiers[15][0]="Droit";
    Metiers[15][1]="Larcins";
    Metiers[16]=(char**)malloc(3*sizeof(char*));
    Metiers[16][0]="Art1";
    Metiers[16][1]="Lire";
    Metiers[16][2]="Sciences";
    Metiers[17]=(char**)malloc(10*sizeof(char*));
    Metiers[17][0]="Ballistique";
    Metiers[17][1]="Cartographie";
    Metiers[17][2]="ConnSpe1";
    Metiers[17][3]="ConnSpe2";
    Metiers[17][4]="Ingenierie navale";
    Metiers[17][5]="Hydrographie";
    Metiers[17][6]="Lire";
    Metiers[17][7]="Medecine";
    Metiers[17][8]="Navigation";
    Metiers[17][9]="Sciences";
    Metiers[18]=(char**)malloc(5*sizeof(char*));
    Metiers[18][0]="Voilerie";
    Metiers[18][1]="ConnaissancesNautiques";
    Metiers[18][2]="ConnaissancesSignalisation";
    Metiers[18][3]="Hydrographie";
    Metiers[18][4]="Navigation";
    Metiers[19]=(char**)malloc(1*sizeof(char*));
    Metiers[19][0]="Larcins";
    int pts=10;
    int Nb=0;

    char *cat=(char*)malloc(40*sizeof(char));
    Origine ListeOri[20]= {{0,1,0,2,2,1,"Amuseurs\n",Metiers[0],2,3},{1,1,1,1,1,2,"Armee\n",Metiers[1],2,2},{2,0,0,0,3,0,"Bourgeoisie\n",Metiers[2],2,7},{0,2,1,3,0,1,"Colons\n",Metiers[3],2,3},{3,0,1,0,1,0,"Intellectuels\n",Metiers[4],2,13},{0,0,0,3,1,1,"Malandrins\n",Metiers[5],2,1},{1,1,3,1,0,0,"Marine\n",Metiers[6],2,7},{1,0,1,1,3,1,"Noblesse\n",Metiers[7],2,7},{0,2,0,2,2,0,"Paysannerie\n",Metiers[8],2,2},{1,1,0,2,1,1,"Tribu\n",Metiers[9],2,5},{0,0,0,1,3,1,"Amoureuse\n",Metiers[10],1,1},{0,0,1,1,2,1,"Autoritaire\n",Metiers[11],1,0},{2,0,0,0,3,0,"Choyee\n",Metiers[12],1,4},{0,2,1,1,1,1,"Laborieuse\n",Metiers[13],1},{1,1,0,2,1,1,"Orpheline\n",Metiers[14],1,1},{1,0,0,0,2,2,"Rebelle\n",Metiers[15],1,2},{2,1,0,1,1,1,"Solitaire\n",Metiers[16],1,4},{3,0,2,0,0,0,"Studieuse\n",Metiers[17],1,10},{1,2,3,1,0,1,"Mer\n",Metiers[18],1,5},{0,0,0,2,2,1,"Turbulente\n",Metiers[19],1,1}};
    char* Noms[78]= {"Ballistique","Cartographie","Commerce","Droit","Geographie","Histoire","ConnSpe1","ConnSpe2","Herboristerie","IngenierieNavale","Intendance","Lire","Medecine","Religion1","Religion2","Sciences","Tactique","Art1","Art2","Pointage","Recharge","Calfatage","Charpenterie","Voilerie","Cuisine","Artisanat1","Artisanat2","Chasse","Chirurgie","Dressage","PremiersSoins","ConnaissancesNautiques","ConnaissancesNavires","ConnaissanceSignalisation","Hydrographie","Navigation","Peche","PratiqueNautique","Timonerie","Acrobatie","Athletisme","Discretion","Equitation","Larcins","Natation","Survie","Vigilance","Comedie","Colons1","Colons2","Colons3","Marins1","Marins2","Marins3","Empathie","Enseignement","Etiquette","Intimidation","Jeu","Langue1","Langue2","Langue3","Meneur","Persuasion","Politique","Seduction","Arme1","Arme2","Arme3","Arme4","Mousquet","Pistolet","Grenade","Jet1","Jet2","Mains","Escrime","Esquive"};
    Competence* liste;
    liste=(Competence *)malloc(78*sizeof(Competence));
    srand(time(NULL));


    for(i=0; i<78; i++)
    {
        liste[i].incremented=0;
        memset (cat, 0, sizeof (cat));
        if(i<17)
            liste[i].appartenance=0;
        else if(i<31)
            liste[i].appartenance=1;
        else if(i<39)
            liste[i].appartenance=2;
        else if(i<47)
            liste[i].appartenance=3;
        else if(i<66)
            liste[i].appartenance=4;
        else if(i<77)
            liste[i].appartenance=5;
        liste[i].valeur=0;
        liste[i].Nom=Noms[i];
        strcat(cat,liste[i].Nom);
        strcat(cat,"\n");

        liste[i].metier=0;

        liste[i].indice=i;
        if(i==0)
        {
            liste[i].indice=78;
        }
        for(j=0; j<24; j++)
        {


            if(strcmp(metiers[j],cat)==0)
            {

                liste[i].metier=1;

            }
        }
        //printf("%i \n", liste[i].metier);

    }

    int a,b,c;

    char* Ori=(char*)malloc(100*sizeof(char));
    char* Eve1=(char*)malloc(100*sizeof(char));
    char* Eve2=(char*)malloc(100*sizeof(char));
    char* met=(char*)malloc(100*sizeof(char));
    k=0;
    printf("Veuillez entrez le nombre de perso a generer");

    scanf("%d", &Nb);
    fflush(stdin);

    fflush(stdout);
    fflush(stdin);
    printf("Veuillez entrez votre origine sociale parmi ceux ci (saisissez r pour determiner une origine sociale de maniere aleatoire) \n");
    for(k=0; k<10; k++)
    {
        printf("%s",ListeOri[k].Nom);
    }
    k=0;
    fflush(stdout);
    fflush(stdin);
    fgets(Ori, 100, stdin);
    /*printf("Veuillez entrez votre evenement jeunesse");
    fgets(Eve1, 100, stdin);
    printf("Veuillez entrez votre evenement jeunesse");
    fgets(Eve2, 100, stdin);

    */
    char* Ori1=Ori;
    fflush(stdout);
    fflush(stdin);
    printf("Veuillez entrez votre metier (saisissez r pour determiner un métier de maniere aleatoire\n");
    fflush(stdout);
    fflush(stdin);
    fgets(met, 100, stdin);
    //RemoveChars(met, '\n');
    //met="Artilleur\n";
    do
    {


        do
        {

            b=rand()%10;
            c=rand()%10;

        }
        while(b==c || b==6 || c==6);

        if(strcmp(Ori1,"r\n")==0)
        {

            a=rand()%10;
            Ori=ListeOri[a].Nom;

        }
        printf("%s \n",Ori);
        Eve1=ListeOri[b+10].Nom;
        Eve2=ListeOri[c+10].Nom;
        char * Meti=(char*)malloc(sizeof((strlen(met))*sizeof(char)));



        //printf("%c \n",Meti[strlen(Meti)-9]);
        //strcpy(met,Meti);


        for(i=0; i<20; i++)
        {
            if(strcmp(Ori,ListeOri[i].Nom)==0)
            {

                RempliOri(ListeOri[i],liste);



            }

            if(strcmp(Eve1,ListeOri[i].Nom)==0)
            {

                RempliOri(ListeOri[i],liste);


            }
            if(strcmp(Eve2,ListeOri[i].Nom)==0)
            {

                RempliOri(ListeOri[i],liste);

            }


        }
        pts=10;

        //CalculMetier(name1,prof,liste,Ori,work);
        if(strcmp(met,"r\n")==0)
            name=AddProfession(liste, Ori);
        else
            name=AddProfessionChoose(liste, Ori,met);


        if(strcmp(Ori,"Noblesse\n")==0)
        {
            pts=pts-5; ///Si avantage noblesse alors on baisse 5 points de compétences
        }

        RempliFini(pts,liste);



        SaveFile(k,name,liste,Ori,Eve1,Eve2);

        k++;
        for(i=0; i<78; i++)
        {
            liste[i].valeur=0;
            liste[i].profession=0;
        }
        printf("%i",k);
    }
    while(k<Nb);
    printf("\nPRESS ANY KEY TO CLOSE THE PROGRAM");
    getc(stdin);

    return 0;
}
char *ScoreProfession(Competence*g, char*Ori)
{

    float maxi=0.0000;
    int indic=0;
    int cpt;
    if(strcmp(Ori,"Armee\n")==0)
    {
        char *profs[15];
        for(cpt=0; cpt<15; cpt++)
        {
            profs[cpt]=(char*)malloc(100*sizeof(char));
        }


        profs[0]="Artilleur";
        profs[1]="Cadet";
        profs[2]="Cavalier";
        profs[3]="Geolier";
        profs[4]="Lancier";
        profs[5]="MaitreArme";
        profs[6]="MaitreEscrime";
        profs[7]="Mousquetaire";
        profs[8]="OfficerArtillerie";
        profs[9]="LieutenantInfanterie";
        profs[10]="OfficierCavalerie";
        profs[11]="SergentRecruteur";
        profs[12]="SousOfficierArtillerie";
        profs[13]="SousOfficierInfanterie";
        profs[14]="Stratege";

        int i;
        int Scores[15];
        Scores[0]=(float)(g[40].valeur+g[77].valeur+g[70].valeur+g[71].valeur)/4;
        Scores[1]=(float)(g[40].valeur+g[77].valeur+g[70].valeur+g[72].valeur+g[19].valeur+g[20].valeur+g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur)/10;
        Scores[2]=(float)(g[29].valeur+g[42].valeur+g[71].valeur+g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[45].valeur)/8;
        Scores[3]=(float)(g[75].valeur+g[57].valeur+g[30].valeur+g[46].valeur+g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur)/8;
        Scores[4]=(float)(g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[40].valeur+g[70].valeur+g[46].valeur+g[58].valeur+g[77].valeur+g[48].valeur+g[49].valeur+g[50].valeur+g[51].valeur+g[52].valeur+g[53].valeur)/15;
        Scores[5]=(float)(g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[16].valeur+g[77].valeur+g[70].valeur)/7;
        Scores[6]=(float)(g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[11].valeur+g[77].valeur+g[76].valeur+g[55].valeur)/8;
        Scores[7]=(float)(g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[70].valeur+g[40].valeur+g[62].valeur+g[76].valeur+g[77].valeur+g[16].valeur+g[56].valeur)/11;
        Scores[8]=(float)(g[0].valeur+g[62].valeur+g[55].valeur+g[56].valeur+g[19].valeur+g[20].valeur+g[16].valeur)/7;
        Scores[9]=(float)(g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[71].valeur+g[76].valeur+g[4].valeur+g[62].valeur+g[16].valeur)/9;
        Scores[10]=(float)(g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[16].valeur+g[71].valeur+g[62].valeur+g[4].valeur+g[76].valeur+g[42].valeur)/10;
        Scores[11]=(float)(g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[75].valeur+g[47].valeur+g[40].valeur+g[54].valeur+g[55].valeur+g[58].valeur+g[63].valeur+g[77].valeur+g[71].valeur)/13;
        Scores[12]=(float)(g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[0].valeur+g[62].valeur+g[55].valeur+g[57].valeur+g[19].valeur+g[20].valeur)/10;
        Scores[13]=(float)(g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[71].valeur+g[16].valeur+g[62].valeur+g[4].valeur+g[76].valeur+g[42].valeur)/10;
        Scores[14]=(float)(g[0].valeur+g[62].valeur+g[42].valeur+g[4].valeur+g[64].valeur+g[16].valeur+g[51].valeur+g[52].valeur+g[53].valeur)/9;


        for(i=0; i<14; i++)
        {
            if(Scores[i]>maxi)
            {
                maxi=Scores[i];
                indic=i;
            }
        }

        return profs[indic];
    }
    if(strcmp(Ori,"Tribu\n")==0)
    {

        char *profs[7];
        for(cpt=0; cpt<7; cpt++)
        {
            profs[cpt]=(char*)malloc(100*sizeof(char));
        }

        profs[0]="Chasseur\n";
        profs[1]="Chef\n";
        profs[2]="Griot\n";
        profs[3]="Guerrier\n";
        profs[4]="Pecheur\n";
        profs[5]="PecheurCaraibe";
        profs[6]="PecheurMosquiton";
        int i;
        int Scores[7];
        Scores[0]=(float)(g[73].valeur+g[74].valeur+g[40].valeur+g[27].valeur+g[41].valeur+g[4].valeur+g[46].valeur+g[45].valeur+g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur)/12;
        Scores[1]=(float)(g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[73].valeur+g[74].valeur+g[62].valeur+g[54].valeur+g[57].valeur+g[63].valeur+g[64].valeur+g[16].valeur)/12;
        Scores[2]=(float)(g[55].valeur+g[51].valeur+g[52].valeur+g[53].valeur+g[59].valeur+g[60].valeur+g[61].valeur+g[63].valeur+g[64].valeur+g[13].valeur+g[14].valeur)/11;
        Scores[3]=(float)(g[39].valeur+g[40].valeur+g[41].valeur+g[45].valeur+g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[73].valeur+g[74].valeur)/10;
        Scores[4]=(float)(g[73].valeur+g[74].valeur+g[41].valeur+g[4].valeur+g[34].valeur+g[37].valeur+g[36].valeur+g[45].valeur)/8;
        Scores[5]=(float)(g[73].valeur+g[74].valeur+g[41].valeur+g[4].valeur+g[34].valeur+g[37].valeur+g[36].valeur+g[45].valeur+g[46].valeur)/9;
        Scores[6]=(float)(g[73].valeur+g[74].valeur+g[4].valeur+g[34].valeur+g[37].valeur+g[38].valeur+g[36].valeur+g[45].valeur)/8;
        for(i=0; i<7; i++)
            if(Scores[i]>maxi)
            {
                maxi=Scores[i];
                indic=i;
            }

        return profs[indic];
    }
    if(strcmp(Ori,"Amuseurs\n")==0)
    {

        char *profs[7];
        for(cpt=0; cpt<7; cpt++)
        {
            profs[cpt]=(char*)malloc(100*sizeof(char));
        }

        profs[0]="Acrobate";
        profs[1]="Chansnnier";
        profs[2]="Comedien";
        profs[3]="Dresseur";
        profs[4]="Ecrivain";
        profs[5]="Musicien";
        profs[6]="PeintreMarine";

        int i;
        int Scores[7];
        Scores[0]=(float)(g[39].valeur+g[40].valeur+g[4].valeur+g[77].valeur+g[46].valeur+g[66].valeur+g[47].valeur)/7;
        Scores[1]=(float)(g[4].valeur+g[5].valeur+g[17].valeur+g[18].valeur+g[54].valeur+g[55].valeur+g[56].valeur+g[65].valeur+g[11].valeur+g[43].valeur)/10;
        Scores[2]=(float)(g[47].valeur+g[51].valeur+g[52].valeur+g[53].valeur+g[5].valeur+g[54].valeur+g[55].valeur+g[65].valeur+g[63].valeur)/9;
        Scores[3]=(float)(g[47].valeur+g[54].valeur+g[56].valeur+g[57].valeur+g[63].valeur+g[62].valeur+g[29].valeur)/7;
        Scores[4]=(float)(g[51].valeur+g[52].valeur+g[53].valeur+g[4].valeur+g[59].valeur+g[60].valeur+g[61].valeur+g[64].valeur+g[63].valeur+g[11].valeur)/10;
        Scores[5]=(float)(g[17].valeur+g[18].valeur+g[54].valeur+g[55].valeur+g[56].valeur+g[59].valeur+g[60].valeur+g[61].valeur+g[46].valeur+g[11].valeur)/10;
        Scores[6]=(float)(g[17].valeur+g[18].valeur+g[1].valeur+g[31].valeur+g[32].valeur+g[4].valeur+g[5].valeur+g[55].valeur+g[16].valeur+g[46].valeur)/10;
        for(i=0; i<7; i++)
            if(Scores[i]>maxi)
            {
                maxi=Scores[i];
                indic=i;
            }

        return profs[indic];
    }
    if(strcmp(Ori,"Intellectuels\n")==0)
    {

        char *profs[6];
        for(cpt=0; cpt<6; cpt++)
        {
            profs[cpt]=(char*)malloc(100*sizeof(char));
        }

        profs[0]="Architecte";
        profs[1]="Cartographe";
        profs[2]="Chirurgien\n";
        profs[3]="Ingenieur";
        profs[4]="Medecin";
        profs[5]="Philosophe";

        int i;
        int Scores[6];
        Scores[0]=(float)(g[17].valeur+g[18].valeur+g[1].valeur+g[4].valeur+g[11].valeur+g[55].valeur+g[15].valeur)/7;
        Scores[1]=(float)(g[17].valeur+g[18].valeur+g[1].valeur+g[4].valeur+g[11].valeur+g[35].valeur+g[15].valeur)/7;
        Scores[2]=(float)(g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[28].valeur+g[30].valeur+g[12].valeur+g[8].valeur)/8;
        Scores[3]=(float)(g[22].valeur+g[31].valeur+g[32].valeur+g[9].valeur+g[16].valeur+g[15].valeur+g[62].valeur)/7;
        Scores[4]=(float)(g[28].valeur+g[54].valeur+g[9].valeur+g[12].valeur+g[30].valeur+g[15].valeur)/6;
        Scores[5]=(float)(g[54].valeur+g[55].valeur+g[11].valeur+g[63].valeur+g[15].valeur+g[5].valeur+g[64].valeur)/7;

        for(i=0; i<6; i++)
            if(Scores[i]>maxi)
            {
                maxi=Scores[i];
                indic=i;
            }

        return profs[indic];
    }
    if(strcmp(Ori,"Bourgeoisie\n")==0)
    {

        char *profs[9];
        for(cpt=0; cpt<9; cpt++)
        {
            profs[cpt]=(char*)malloc(100*sizeof(char));
        }

        profs[0]="Armateur";
        profs[1]="Banquier";
        profs[2]="Commis";
        profs[3]="Negociant";
        profs[4]="Notaire";
        profs[5]="PetitMarchand";
        profs[6]="RicheMarchand";
        profs[7]="Speculateur";
        profs[8]="Tenanciers";

        int i;
        int Scores[9];
        Scores[0]=(float)(g[2].valeur+g[11].valeur+g[9].valeur+g[32].valeur+g[62].valeur)/5;
        Scores[1]=(float)(g[2].valeur+g[3].valeur+g[10].valeur+g[11].valeur+g[64].valeur+g[63].valeur+g[59].valeur+g[60].valeur+g[61].valeur)/9;
        Scores[2]=(float)(g[2].valeur+g[3].valeur+g[10].valeur+g[59].valeur+g[60].valeur+g[61].valeur+g[11].valeur+g[64].valeur+g[46].valeur)/9;
        Scores[3]=(float)(g[2].valeur+g[4].valeur+g[10].valeur+g[59].valeur+g[60].valeur+g[61].valeur+g[11].valeur+g[54].valeur)/8;
        Scores[4]=(float)(g[2].valeur+g[3].valeur+g[10].valeur+g[63].valeur+g[56].valeur)/5;
        Scores[5]=(float)(g[47].valeur+g[10].valeur+g[59].valeur+g[60].valeur+g[61].valeur+g[63].valeur+g[65].valeur+g[46].valeur)/8;
        Scores[6]=(float)(g[2].valeur+g[32].valeur+g[4].valeur+g[54].valeur+g[11].valeur+g[62].valeur)/6;
        Scores[7]=(float)(g[40].valeur+g[47].valeur+g[2].valeur+g[3].valeur+g[54].valeur+g[10].valeur+g[58].valeur)/7;
        Scores[8]=(float)(g[24].valeur+g[47].valeur+g[54].valeur+g[10].valeur+g[57].valeur+g[58].valeur+g[63].valeur)/7;
        for(i=0; i<9; i++)
            if(Scores[i]>maxi)
            {
                maxi=Scores[i];
                indic=i;
            }

        return profs[indic];
    }
    if(strcmp(Ori,"Colons\n")==0)
    {

        char *profs[6];
        for(cpt=0; cpt<6; cpt++)
        {
            profs[cpt]=(char*)malloc(100*sizeof(char));
        }

        profs[0]="Boucanier";
        profs[1]="Contremaitre";
        profs[2]="Engage";
        profs[3]="Flibustier";
        profs[4]="Habitant";
        profs[5]="Planteur";

        int i;
        int Scores[6];
        Scores[0]=(float)(g[66].valeur+g[67].valeur+g[69].valeur+g[68].valeur+g[70].valeur+g[39].valeur+g[10].valeur+g[41].valeur+g[45].valeur+g[30].valeur)/10;
        Scores[1]=(float)(g[66].valeur+g[67].valeur+g[69].valeur+g[68].valeur+g[70].valeur+g[75].valeur+g[46].valeur+g[57].valeur)/8;
        Scores[2]=(float)(g[24].valeur+g[40].valeur+g[54].valeur+g[46].valeur+g[45].valeur+g[41].valeur)/6;
        Scores[3]=(float)(g[66].valeur+g[67].valeur+g[69].valeur+g[68].valeur+g[70].valeur+g[41].valeur+g[58].valeur+g[62].valeur+g[16].valeur+g[30].valeur+g[37].valeur)/11;
        Scores[4]=(float)(g[25].valeur+g[26].valeur+g[66].valeur+g[67].valeur+g[69].valeur+g[68].valeur+g[58].valeur+g[62].valeur+g[10].valeur+g[40].valeur+g[45].valeur)/11;
        Scores[5]=(float)(g[25].valeur+g[26].valeur+g[2].valeur+g[4].valeur+g[10].valeur+g[57].valeur+g[58].valeur+g[62].valeur)/8;

        for(i=0; i<6; i++)
            if(Scores[i]>maxi)
            {
                maxi=Scores[i];
                indic=i;
            }

        return profs[indic];
    }
    if(strcmp(Ori,"Malandrins\n")==0)
    {

        char *profs[11];
        for(cpt=0; cpt<11; cpt++)
        {
            profs[cpt]=(char*)malloc(100*sizeof(char));
        }

        profs[0]="Agitateur";
        profs[1]="Assassin";
        profs[2]="Bourreau";
        profs[3]="Escroc";
        profs[4]="Espion";
        profs[5]="Joueur";
        profs[6]="Prostituee";
        profs[7]="Spadassin";
        profs[8]="Trafiquant";
        profs[9]="TrafiquantEbene";
        profs[10]="Voleur";
        int i;
        int Scores[11];
        Scores[0]=(float)(g[71].valeur+g[54].valeur+g[55].valeur+g[62].valeur+g[64].valeur+g[63].valeur+g[41].valeur)/7;
        Scores[1]=(float)(g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[47].valeur+g[41].valeur+g[56].valeur+g[8].valeur+g[16].valeur+g[64].valeur+g[43].valeur)/11;
        Scores[2]=(float)(g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[54].valeur+g[56].valeur+g[57].valeur+g[64].valeur)/8;
        Scores[3]=(float)(g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[40].valeur+g[47].valeur+g[41].valeur+g[56].valeur+g[43].valeur+g[63].valeur)/10;
        Scores[4]=(float)(g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[40].valeur+g[47].valeur+g[41].valeur+g[54].valeur+g[56].valeur+g[2].valeur+g[43].valeur+g[64].valeur)/12;
        Scores[5]=(float)(g[71].valeur+g[40].valeur+g[47].valeur+g[41].valeur+g[58].valeur+g[75].valeur)/6;
        Scores[6]=(float)(g[54].valeur+g[43].valeur+g[63].valeur+g[65].valeur+g[30].valeur+g[51].valeur+g[52].valeur+g[53].valeur+g[75].valeur)/9;
        Scores[7]=(float)(g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[71].valeur+g[40].valeur+g[41].valeur+g[77].valeur)/8;
        Scores[8]=(float)(g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[70].valeur+g[40].valeur+g[3].valeur+g[41].valeur+g[57].valeur+g[43].valeur+g[37].valeur+g[59].valeur+g[60].valeur+g[61].valeur)/14;
        Scores[9]=(float)(g[70].valeur+g[40].valeur+g[47].valeur+g[4].valeur+g[57].valeur+g[30].valeur+g[59].valeur+g[60].valeur+g[61].valeur)/9;
        Scores[10]=(float)(g[39].valeur+g[40].valeur+g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[41].valeur+g[77].valeur+g[43].valeur+g[46].valeur)/10;
        for(i=0; i<11; i++)
        {

            if(Scores[i]>maxi)
            {

                maxi=Scores[i];
                indic=i;
            }
        }
        return profs[indic];
    }
    if(strcmp(Ori,"Paysannerie\n")==0)

    {

        char *profs[6];
        for(cpt=0; cpt<6; cpt++)
        {
            profs[cpt]=(char*)malloc(100*sizeof(char));
        }

        profs[0]="Artisan";
        profs[1]="Bucheron";
        profs[2]="Laquais";
        profs[3]="Paysan";
        profs[4]="Pecheur";
        profs[5]="Serveuse";

        int i;
        int Scores[6];
        Scores[0]=(float)(g[25].valeur+g[26].valeur+g[55].valeur+g[46].valeur+g[10].valeur)/5;
        Scores[1]=(float)(g[4].valeur+g[45].valeur+g[57].valeur+g[39].valeur+g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur)/8;
        Scores[2]=(float)(g[24].valeur+g[47].valeur+g[54].valeur+g[63].valeur+g[64].valeur+g[46].valeur+g[56].valeur+g[42].valeur)/8;
        Scores[3]=(float)(g[25].valeur+g[26].valeur+g[34].valeur+g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[37].valeur+g[41].valeur+g[42].valeur+g[29].valeur)/11;
        Scores[4]=(float)(g[31].valeur+g[34].valeur+g[37].valeur+g[36].valeur+g[44].valeur)/5;
        Scores[5]=(float)(g[54].valeur+g[65].valeur+g[56].valeur+g[43].valeur+g[47].valeur+g[51].valeur+g[52].valeur+g[53].valeur+g[76].valeur)/9;

        for(i=0; i<6; i++)
            if(Scores[i]>maxi)
            {
                maxi=Scores[i];
                indic=i;
            }
        return profs[indic];
    }

    if(strcmp(Ori,"Noblesse\n")==0)

    {

        char *profs[4];
        for(cpt=0; cpt<4; cpt++)
        {
            profs[cpt]=(char*)malloc(100*sizeof(char));
        }

        profs[0]="Bretteur";
        profs[1]="Conspirateur";
        profs[2]="Courtisan";
        profs[3]="Mecene";


        int i;
        int Scores[4];
        Scores[0]=(float)(g[40].valeur+g[27].valeur+g[76].valeur+g[56].valeur+g[57].valeur+g[71].valeur+g[64].valeur+g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur)/11;
        Scores[1]=(float)(g[47].valeur+g[40].valeur+g[62].valeur+g[42].valeur+g[16].valeur+g[71].valeur+g[64].valeur+g[63].valeur+g[56].valeur)/9;
        Scores[2]=(float)(g[42].valeur+g[56].valeur+g[63].valeur+g[64].valeur+g[65].valeur+g[46].valeur)/6;
        Scores[3]=(float)(g[17].valeur+g[18].valeur+g[54].valeur+g[2].valeur+g[11].valeur+g[64].valeur)/6;
        for(i=0; i<4; i++)
            if(Scores[i]>maxi)
            {
                maxi=Scores[i];
                indic=i;
            }
        return profs[indic];
    }
    if(strcmp(Ori,"Marine\n")==0)
    {

        char *profs[19];
        for(cpt=0; cpt<19; cpt++)
        {
            profs[cpt]=(char*)malloc(100*sizeof(char));
        }


        profs[0]="Capitaine";
        profs[1]="Second";
        profs[2]="Canonnier";
        profs[3]="Cambusier";
        profs[4]="ChefDePiece";
        profs[5]="Coq";
        profs[6]="Enseigne";
        profs[7]="Gabier";
        profs[8]="MaitreCalfat";
        profs[9]="MaitreCanonnier";
        profs[10]="MaitreCharpentier";
        profs[11]="MaitreEquipage";
        profs[12]="MaitreVoilier";
        profs[13]="Matelot";
        profs[14]="Pilote";
        profs[15]="QuartierMaitre";
        profs[16]="ServantPiece";
        profs[17]="Vigie";
        profs[18]="Mousse";

        int i;
        int Scores[19];
        Scores[0]=(float)(g[0].valeur+g[62].valeur+g[31].valeur+g[4].valeur+g[34].valeur+g[11].valeur+g[35].valeur+g[71].valeur+g[16].valeur+g[33].valeur+g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur)/14;
        Scores[1]=(float)(g[62].valeur+g[31].valeur+g[34].valeur+g[11].valeur+g[35].valeur+g[71].valeur+g[16].valeur+g[33].valeur+g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[37].valeur+g[32].valeur)/14;
        Scores[2]=(float)(g[0].valeur+g[62].valeur+g[31].valeur+g[19].valeur+g[20].valeur+g[11].valeur+g[71].valeur+g[16].valeur+g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[70].valeur)/13;
        Scores[3]=(float)(g[32].valeur+g[24].valeur+g[57].valeur+g[63].valeur+g[10].valeur)/5;
        Scores[4]=(float)(g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[0].valeur+g[70].valeur+g[19].valeur+g[20].valeur+g[77].valeur+g[37].valeur+g[62].valeur)/11;
        Scores[5]=(float)(g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[24].valeur+g[10].valeur+g[46].valeur+g[8].valeur)/8;
        Scores[6]=(float)(g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[71].valeur+g[19].valeur+g[20].valeur+g[0].valeur+g[31].valeur+g[33].valeur+g[51].valeur+g[52].valeur+g[53].valeur+g[54].valeur+g[77].valeur+g[34].valeur+g[62].valeur+g[37].valeur)/18;
        Scores[7]=(float)(g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[71].valeur+g[40].valeur+g[51].valeur+g[52].valeur+g[53].valeur+g[31].valeur+g[41].valeur+g[37].valeur+g[70].valeur+g[77].valeur)/14;
        Scores[8]=(float)(g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[75].valeur+g[46].valeur+g[32].valeur+g[31].valeur+g[9].valeur+g[21].valeur)/10;
        Scores[9]=(float)(g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[70].valeur+g[54].valeur+g[55].valeur+g[30].valeur+g[57].valeur+g[19].valeur+g[20].valeur+g[77].valeur+g[71].valeur)/13;
        Scores[10]=(float)(g[31].valeur+g[32].valeur+g[9].valeur+g[22].valeur+g[46].valeur+g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[75].valeur)/10;
        Scores[11]=(float)(g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[70].valeur+g[54].valeur+g[55].valeur+g[31].valeur+g[57].valeur+g[37].valeur+g[40].valeur+g[77].valeur+g[71].valeur)/13;
        Scores[12]=(float)(g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[75].valeur+g[39].valeur+g[32].valeur+g[31].valeur+g[9].valeur+g[46].valeur+g[23].valeur)/11;
        Scores[13]=(float)(g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[70].valeur+g[31].valeur+g[77].valeur+g[44].valeur+g[37].valeur+g[71].valeur+g[51].valeur+g[52].valeur+g[53].valeur)/13;
        Scores[14]=(float)(g[1].valeur+g[31].valeur+g[32].valeur+g[4].valeur+g[34].valeur+g[11].valeur+g[35].valeur)/7;
        Scores[15]=(float)(g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[70].valeur+g[31].valeur+g[77].valeur+g[62].valeur+g[3].valeur+g[71].valeur+g[54].valeur+g[55].valeur+g[63].valeur+g[38].valeur+g[37].valeur)/15;
        Scores[16]=(float)(g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[70].valeur+g[37].valeur+g[77].valeur+g[19].valeur+g[20].valeur+g[71].valeur+g[46].valeur)/11;
        Scores[17]=(float)(g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[70].valeur+g[37].valeur+g[77].valeur+g[39].valeur+g[40].valeur+g[71].valeur+g[46].valeur+g[32].valeur)/12;
        Scores[18]=(float)(g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[75].valeur+g[51].valeur+g[52].valeur+g[19].valeur+g[20].valeur+g[53].valeur+g[31].valeur+g[32].valeur+g[40].valeur+g[77].valeur+g[37].valeur+g[36].valeur+g[44].valeur)/17;


        for(i=0; i<19; i++)
        {
            if(Scores[i]>maxi)
            {
                maxi=Scores[i];
                indic=i;
            }
        }

        return profs[indic];
    }
    printf("IN THE BOX");
    return "none";
}
void SaveFile(int i,char* name, Competence* g,char *Ori, char *Eve1,char *Eve2)
{

    int j=0;
    float Scores[6];
    float maxi=0.000000;
    printf("%s",name);

    Scores[0]=((float)(g[0].valeur+g[31].valeur+g[34].valeur+g[35].valeur+g[33].valeur+g[16].valeur+g[4].valeur+g[11].valeur+g[62].valeur+g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[71].valeur+12)*13/14);
    Scores[1]=((float)(g[62].valeur+g[31].valeur+g[32].valeur+g[34].valeur+g[11].valeur+g[37].valeur+g[35].valeur+g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[71].valeur+g[33].valeur+g[16].valeur+12)*13/14);
    Scores[2]=((float)(g[0].valeur+g[62].valeur+g[31].valeur+g[11].valeur+g[16].valeur+g[19].valeur+g[20].valeur+g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[71].valeur+g[70].valeur+12));
    Scores[3]=((float)(g[62].valeur+g[31].valeur+g[3].valeur+g[54].valeur+g[55].valeur+g[63].valeur+g[37].valeur+g[38].valeur+g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[71].valeur+g[70].valeur+g[77].valeur+12)*13/15);
    Scores[4]=((float)(g[31].valeur+g[40].valeur+g[54].valeur+g[55].valeur+g[57].valeur+g[37].valeur+g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[71].valeur+g[70].valeur+g[77].valeur+12));
    Scores[5]=((float)(g[54].valeur+g[55].valeur+g[57].valeur+g[19].valeur+g[20].valeur+g[30].valeur+g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[71].valeur+g[70].valeur+g[77].valeur+12));
    for(j=0; j<6; j++)
    {
        if(Scores[j]>maxi)
            maxi=Scores[j];
    }
    char *poste;

    if(maxi==Scores[0])
        poste="./Capitaine/";
    else if(maxi==Scores[1])
        poste="./Second/";
    else if(maxi==Scores[2])
        poste="./Canonnier/";
    else if(maxi==Scores[3])
        poste="./QuartierMaitre/";
    else if(maxi==Scores[4])
        poste="./MaitreEquipage/";
    else if(maxi==Scores[5])
        poste="./MaitreCanonnier/";
    char nombre[100];
    sprintf(nombre,"%f",maxi);
    char s[100];
    sprintf(s, "%i", i); // Conversion de l'entier

    char str1[100];
    char d[600];
    getcwd(d,600);
    strcpy(str1,poste);
    char str2[] = ".txt";

    //concatenates str1 and str2 and resultant string is stored in str1.

    float ada=g[4].valeur+g[5].valeur+g[7].valeur+g[9].valeur+g[10].valeur+g[15].valeur+g[16].valeur+g[23].valeur+g[28].valeur+g[30].valeur+g[32].valeur+g[33].valeur+g[37].valeur+g[38].valeur+g[39].valeur+g[41].valeur+g[43].valeur+g[45].valeur+g[54].valeur+g[56].valeur+g[58].valeur+g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[77].valeur;
    float adr=g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur+g[72].valeur+g[73].valeur+g[74].valeur+g[56].valeur+g[39].valeur+g[41].valeur+g[42].valeur+g[43].valeur+g[44].valeur+g[37].valeur+g[30].valeur+g[28].valeur+g[23].valeur+g[21].valeur+g[22].valeur+g[11].valeur+g[9].valeur+g[1].valeur;
    float eru=g[0].valeur+g[1].valeur+g[3].valeur+g[4].valeur+g[5].valeur+g[6].valeur+g[7].valeur+g[8].valeur+g[9].valeur+g[10].valeur+g[11].valeur+g[12].valeur+g[13].valeur+g[14].valeur+g[15].valeur+g[16].valeur+g[20].valeur+g[31].valeur+g[32].valeur+g[33].valeur+g[34].valeur+g[45].valeur+g[55].valeur+g[64].valeur;
    float exp=g[2].valeur+g[3].valeur+g[11].valeur+g[13].valeur+g[14].valeur+g[16].valeur+g[17].valeur+g[18].valeur+g[29].valeur+g[31].valeur+g[55].valeur+g[56].valeur+g[57].valeur+g[59].valeur+g[60].valeur+g[61].valeur+g[62].valeur+g[63].valeur+g[64].valeur;
    float force=g[20].valeur+g[22].valeur+g[40].valeur+g[42].valeur+g[44].valeur+g[57].valeur+g[75].valeur+g[66].valeur+g[67].valeur+g[68].valeur+g[69].valeur;
    float per=g[0].valeur+g[1].valeur+g[8].valeur+g[10].valeur+g[12].valeur+g[19].valeur+g[24].valeur+g[27].valeur+g[32].valeur+g[33].valeur+g[35].valeur+g[36].valeur+g[39].valeur+g[45].valeur+g[46].valeur+g[48].valeur+g[49].valeur+g[50].valeur+g[51].valeur+g[52].valeur+g[53].valeur+g[54].valeur+g[59].valeur+g[60].valeur+g[61].valeur+g[70].valeur+g[71].valeur+g[73].valeur+g[74].valeur;
    float pou=g[0].valeur+g[2].valeur+g[4].valeur+g[8].valeur+g[13].valeur+g[14].valeur+g[36].valeur+g[34].valeur+g[41].valeur+g[43].valeur+g[45].valeur+g[58].valeur+g[77].valeur;
    float res=g[21].valeur+g[22].valeur+g[24].valeur+g[27].valeur+g[40].valeur+g[42].valeur+g[44].valeur+g[46].valeur;
    float cha=g[29].valeur+g[41].valeur+g[42].valeur+g[47].valeur+g[48].valeur+g[49].valeur+g[50].valeur+g[51].valeur+g[52].valeur+g[53].valeur+g[54].valeur+g[57].valeur+g[56].valeur+g[65].valeur+g[63].valeur+g[62].valeur;
    float tot=cha+ada+adr+exp+eru+force+pou+res+per;
    ada=ada/tot*45;
    adr=adr/tot*45;
    eru=eru/tot*45;
    force=force/tot*45;
    per=per/tot*45;
    pou=pou/tot*45;
    res=res/tot*45;
    cha=cha/tot*45;
    exp=exp/tot*45;
    char *OK=(char*)malloc((strlen(name)-1)*sizeof(char));
    memset(OK,0,sizeof(OK));

    OK=RemoveChars(name,'\n');

    strcat(str1,OK);
    strcat(str1,nombre);

    strcat(str1,s);

    strcat(str1,str2);
    printf("%s",str1);

    FILE *fp;
    fp=fopen(str1, "w");
    if(fp == NULL)
    {
        printf("Ferme");
        exit(-1);
    }
    int somme=0;
    for(i=0; i<78; i++)
    {
        if(g[i].incremented>0)
        {
            if(g[i].profession>0)
            {
                fprintf(fp, "%s %i Pr %i X\n", g[i].Nom, g[i].valeur,g[i].profession);
            }
            else
            {
                fprintf(fp, "%s %i X\n", g[i].Nom, g[i].valeur);
            }
        }

        else
        {
            if(g[i].profession>0)
            {
                fprintf(fp, "%s %i Pr %i \n", g[i].Nom, g[i].valeur,g[i].profession);
            }
            else
            {
                fprintf(fp, "%s %i \n", g[i].Nom, g[i].valeur);
            }
            //printf("%i     \n",g[i].valeur);

            //printf("WROTE\n");
        }

        somme+=g[i].valeur;
        g[i].incremented=0;
    }
    fprintf(fp,"%s \n",Ori);
    fprintf(fp,"%s \n",Eve1);
    fprintf(fp,"%s \n",Eve2);
    fprintf(fp,"%i \n",somme);
    fprintf(fp,"ADA : %f \n",ada);
    fprintf(fp,"ADR : %f \n",adr);
    fprintf(fp,"FOR : %f \n",force);
    fprintf(fp,"RES : %f \n",res);
    fprintf(fp,"POU : %f \n",pou);
    fprintf(fp,"EXP : %f \n",exp);
    fprintf(fp,"ERU : %f \n",eru);
    fprintf(fp,"CHA : %f \n",cha);
    fprintf(fp,"PER : %f \n",per);
    /*fprintf(fp,"Capitaine : %.6f \n",Scores[0]);
    fprintf(fp,"Second : %f\n",Scores[1]);
    fprintf(fp,"Cannonier : %f\n",Scores[2]);
    fprintf(fp,"Quartier-maitre : %f\n",Scores[3]);
    fprintf(fp,"Maitre d'equipage : %f\n",Scores[4]);
    fprintf(fp,"Maitre canoonier : %f\n",Scores[5]);
    */

    printf("\n JOB DONE");

    fclose(fp);
}
void RempliFini(int nb, Competence* g)
{

    int i=0;
    while(i<nb)
    {
        int x=rand()%78;
        if(g[x].valeur<3 && g[x].valeur>0 && g[x].incremented==0)
        {
            g[x].valeur++;
            i=i+1;
            g[x].incremented=1;
        }
        else if(g[x].metier==0 && g[x].valeur<3 && g[x].incremented==0)
        {
            g[x].valeur++;
            i=i+1;
            g[x].incremented=1;
        }
    }


}
int RecupMetier(char* filename, char** m)
{
    int i=0;


    i=0;
    char* line=(char*)malloc(40*sizeof(char));
    FILE *file = fopen ( filename, "r" );
    if(file!=NULL)
    {


        while(fgets(line, 40*sizeof(char), file) != NULL )/* read a line */
        {

            //tampon[i]=Copy(line);
            strcpy(m[i],line);

            i++;


        }

    }





    fclose(file);
//printf("%s\n",Buffer[0]);
    return i;

}
char* Copy(char *source)
{

    int i=0;
    int nb;

    nb=strlen(source);

    char* Buffer=(char*)malloc((nb-1)*sizeof(char));
    //char Buffer[nb];
    for(i=0; i<nb-1; i++)
    {

        Buffer[i]=source[i];

        //printf("%c\n",Buffer[i]);

    }
    return Buffer;
}
void RempliOri(Origine t,Competence* g)
{
    int i=0;
    int x;
    int j=0;
    int Comp[5];
    //char* jobs;
    int bonus=t.type;

    Competence* Buffer=(Competence*)malloc(78*sizeof(Competence));

    //int NbComp=78;

    while(i<5)
    {

        x=rand()%78;
        //jobs=job[x];

        //printf("%i\n",x);  ////Infinite loop

        if(x<17 && g[x].valeur==0)
        {

            if(g[x].metier==0 && t.conn>0)
            {

                g[x].valeur=bonus;
                Comp[i]=x;
                t.conn=t.conn-1;
                i=i+1;


            }
            else if(g[x].metier==1)
            {

                for(j=0; j<t.nbmetier; j++)
                {

                    if(strcmp(g[x].Nom,t.Metiers[j])==0)
                    {
                        g[x].valeur=bonus;
                        Comp[i]=x;

                        i=i+1;
                    }

                }

            }
        }
        else if(x<31 && g[x].valeur==0)
        {

            if(g[x].metier==0 && t.tech>0)
            {
                g[x].valeur=bonus;
                Comp[i]=x;
                t.tech=t.tech-1;
                i=i+1;

            }
            else if(g[x].metier==1)
            {

                for(j=0; j<t.nbmetier; j++)
                {
                    if(strcmp(g[x].Nom,t.Metiers[j])==0)
                    {
                        g[x].valeur=bonus;
                        Comp[i]=x;

                        i=i+1;
                    }

                }

            }
        }
        else if(x<39 && g[x].valeur==0)
        {

            if(g[x].metier==0 && t.mari>0 )
            {
                g[x].valeur=bonus;
                Comp[i]=x;
                t.mari=t.mari-1;

                i=i+1;
            }
            else if(g[x].metier==1)
            {

                for(j=0; j<t.nbmetier; j++)
                {
                    if(strcmp(g[x].Nom,t.Metiers[j])==0)
                    {
                        g[x].valeur=bonus;
                        Comp[i]=x;

                        i=i+1;
                    }

                }

            }
        }
        else if(x<47  && g[x].valeur==0)
        {

            if(g[x].metier==0 && t.phys>0)
            {
                g[x].valeur=bonus;
                Comp[i]=x;
                t.phys=t.phys-1;

                i=i+1;
            }
            else if(g[x].metier==1)
            {

                for(j=0; j<t.nbmetier; j++)
                {
                    if(strcmp(g[x].Nom,t.Metiers[j])==0)
                    {
                        g[x].valeur=bonus;
                        Comp[i]=x;

                        i=i+1;
                    }

                }

            }
        }
        else if(x<66  && g[x].valeur==0)
        {

            if(g[x].metier==0 && t.soci>0)
            {
                g[x].valeur=bonus;
                Comp[i]=x;
                t.soci=t.soci-1;

                i=i+1;
            }
            else if(g[x].metier==1)
            {

                for(j=0; j<t.nbmetier; j++)
                {
                    if(strcmp(g[x].Nom,t.Metiers[j])==0)
                    {
                        g[x].valeur=bonus;
                        Comp[i]=x;

                        i=i+1;
                    }

                }

            }
        }
        else if(x<78 && g[x].valeur==0)
        {

            if(g[x].metier==0 && t.comb>0)
            {
                g[x].valeur=bonus;
                Comp[i]=x;
                t.comb=t.comb-1;

                i=i+1;
            }
            else if(g[x].metier==1)
            {

                for(j=0; j<t.nbmetier; j++)
                {

                    if(strcmp(g[x].Nom,t.Metiers[j])==0)
                    {
                        g[x].valeur=bonus;
                        Comp[i]=x;

                        i=i+1;
                    }

                }

            }
        }

    }
    for(j=0; j<78; j++)
    {
        Buffer[i]=g[i];


    }

    for(i=0; i<5; i++)
    {
        Buffer[Comp[i]].valeur=bonus;

    }


}

char* AddProfession(Competence*g, char*Ori)
{


    int cpt;
    if(strcmp(Ori,"Armee\n")==0)
    {
        char *profs[15];
        for(cpt=0; cpt<15; cpt++)
        {
            profs[cpt]=(char*)malloc(100*sizeof(char));
        }


        profs[0]="Artilleur\n";
        profs[1]="Cadet\n";
        profs[2]="Cavalier\n";
        profs[3]="Geolier\n";
        profs[4]="Lancier\n";
        profs[5]="MaitreArme\n";
        profs[6]="MaitreEscrime\n";
        profs[7]="Mousquetaire\n";
        profs[8]="OfficerArtillerie\n";
        profs[9]="LieutenantInfanterie\n";
        profs[10]="OfficierCavalerie\n";
        profs[11]="SergentRecruteur\n";
        profs[12]="SousOfficierArtillerie\n";
        profs[13]="SousOfficierInfanterie\n";
        profs[14]="Stratege\n";


        int Scores[15][18]= {[0]{g[40].indice,g[77].indice,g[70].indice,g[71].valeur},
                             [1]{g[40].indice,g[77].indice,g[70].indice,g[72].indice,g[19].indice,g[20].indice,g[66].indice,g[67].indice,g[68].indice,g[69].valeur},
                             [2]={g[29].indice,g[42].indice,g[71].indice,g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[45].valeur},
                             [3]={g[75].indice,g[57].indice,g[30].indice,g[46].indice,g[66].indice,g[67].indice,g[68].indice,g[69].valeur},
                             [4]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[40].indice,g[70].indice,g[46].indice,g[58].indice,g[77].indice,g[48].indice,g[49].indice,g[50].indice,g[51].indice,g[52].indice,g[53].valeur},
                             [5]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[16].indice,g[77].indice,g[70].valeur},
                             [6]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[11].indice,g[77].indice,g[76].indice,g[55].valeur},
                             [7]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[70].indice,g[40].indice,g[62].indice,g[76].indice,g[77].indice,g[16].indice,g[56].valeur},
                             [8]={g[0].indice,g[62].indice,g[55].indice,g[56].indice,g[19].indice,g[20].indice,g[16].valeur},
                             [9]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[71].indice,g[76].indice,g[4].indice,g[62].indice,g[16].valeur},
                             [10]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[16].indice,g[71].indice,g[62].indice,g[4].indice,g[76].indice,g[42].valeur},
                             [11]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[75].indice,g[47].indice,g[40].indice,g[54].indice,g[55].indice,g[58].indice,g[63].indice,g[77].indice,g[71].valeur},
                             [12]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[0].indice,g[62].indice,g[55].indice,g[57].indice,g[19].indice,g[20].valeur},
                             [13]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[71].indice,g[16].indice,g[62].indice,g[4].indice,g[76].indice,g[42].valeur},
                             [14]={g[0].indice,g[62].indice,g[42].indice,g[4].indice,g[64].indice,g[16].indice,g[51].indice,g[52].indice,g[53].valeur}
                            };
        int x=rand()%15;
        int y;
        int i=0;
        while(i<12)
        {
            y=rand()%18;
            if(Scores[x][y]!=0)
            {
                if(Scores[x][y]==78)
                {
                    Scores[x][y]=0;
                }
                g[Scores[x][y]].valeur++;
                i++;
            }
        }

        return profs[x];
    }
    if(strcmp(Ori,"Tribu\n")==0)
    {

        char *profs[7];
        for(cpt=0; cpt<7; cpt++)
        {
            profs[cpt]=(char*)malloc(100*sizeof(char));
        }

        profs[0]="Chasseur\n";
        profs[1]="Chef\n";
        profs[2]="Griot\n";
        profs[3]="Guerrier\n";
        profs[4]="Pecheur\n";
        profs[5]="PecheurCaraibe\n";
        profs[6]="PecheurMosquito\n";


        int Scores[7][18]= {[0]={g[73].indice,g[74].indice,g[40].indice,g[27].indice,g[41].indice,g[4].indice,g[46].indice,g[45].indice,g[66].indice,g[67].indice,g[68].indice,g[69].valeur},
                            [1]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[73].indice,g[74].indice,g[62].indice,g[54].indice,g[57].indice,g[63].indice,g[64].indice,g[16].valeur},
                            [2]={g[55].indice,g[51].indice,g[52].indice,g[53].indice,g[59].indice,g[60].indice,g[61].indice,g[63].indice,g[64].indice,g[13].indice,g[14].valeur},
                            [3]={g[39].indice,g[40].indice,g[41].indice,g[45].indice,g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[73].indice,g[74].valeur},
                            [4]={g[73].indice,g[74].indice,g[41].indice,g[4].indice,g[34].indice,g[37].indice,g[36].indice,g[45].valeur},
                            [5]={g[73].indice,g[74].indice,g[41].indice,g[4].indice,g[34].indice,g[37].indice,g[36].indice,g[45].indice,g[46].valeur},
                            [6]={g[73].indice,g[74].indice,g[4].indice,g[34].indice,g[37].indice,g[38].indice,g[36].indice,g[45].valeur}
                           };
        int x=rand()%7;
        int y;
        int i=0;
        while(i<12)
        {
            y=rand()%18;
            if(Scores[x][y]!=0)
            {
                if(Scores[x][y]==78)
                {
                    Scores[x][y]=0;
                }
                g[Scores[x][y]].valeur++;
                i++;
            }
        }

        return profs[x];
    }

    if(strcmp(Ori,"Amuseurs\n")==0)
    {

        char *profs[7];
        for(cpt=0; cpt<7; cpt++)
        {
            profs[cpt]=(char*)malloc(100*sizeof(char));
        }

        profs[0]="Acrobate\n";
        profs[1]="Chansonnier\n";
        profs[2]="Comedien\n";
        profs[3]="Dresseur\n";
        profs[4]="Ecrivain\n";
        profs[5]="Musicien\n";
        profs[6]="PeintreMarine\n";

        int i;

        int Scores[7][18]= {[0]={g[39].indice,g[40].indice,g[4].indice,g[77].indice,g[46].indice,g[66].indice,g[47].valeur},
                            [1]={g[4].indice,g[5].indice,g[17].indice,g[18].indice,g[54].indice,g[55].indice,g[56].indice,g[65].indice,g[11].indice,g[43].valeur},
                            [2]={g[47].indice,g[51].indice,g[52].indice,g[53].indice,g[5].indice,g[54].indice,g[55].indice,g[65].indice,g[63].valeur},
                            [3]={g[47].indice,g[54].indice,g[56].indice,g[57].indice,g[63].indice,g[62].indice,g[29].valeur},
                            [4]={g[51].indice,g[52].indice,g[53].indice,g[4].indice,g[59].indice,g[60].indice,g[61].indice,g[64].indice,g[63].indice,g[11].valeur},
                            [5]={g[17].indice,g[18].indice,g[54].indice,g[55].indice,g[56].indice,g[59].indice,g[60].indice,g[61].indice,g[46].indice,g[11].valeur},
                            [6]={g[17].indice,g[18].indice,g[1].indice,g[31].indice,g[32].indice,g[4].indice,g[5].indice,g[55].indice,g[16].indice,g[46].valeur}
                           };
        int x=rand()%7;
        int y;
        i=0;
        while(i<12)
        {
            y=rand()%18;
            if(Scores[x][y]!=0)
            {
                if(Scores[x][y]==78)
                {
                    Scores[x][y]=0;
                }
                g[Scores[x][y]].valeur++;
                i++;
            }
        }

        return profs[x];
    }

    if(strcmp(Ori,"Intellectuels\n")==0)
    {

        char *profs[6];
        for(cpt=0; cpt<6; cpt++)
        {
            profs[cpt]=(char*)malloc(100*sizeof(char));
        }

        profs[0]="Architecte\n";
        profs[1]="Cartographe\n";
        profs[2]="Chirurgien\n";
        profs[3]="Ingenieur\n";
        profs[4]="Medecin\n";
        profs[5]="Philosophe\n";

        int i;

        int Scores[6][18]= {[0]={g[17].indice,g[18].indice,g[1].indice,g[4].indice,g[11].indice,g[55].indice,g[15].valeur},
                            [1]={g[17].indice,g[18].indice,g[1].indice,g[4].indice,g[11].indice,g[35].indice,g[15].valeur},
                            [2]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[28].indice,g[30].indice,g[12].indice,g[8].valeur},
                            [3]={g[22].indice,g[31].indice,g[32].indice,g[9].indice,g[16].indice,g[15].indice,g[62].valeur},
                            [4]={g[28].indice,g[54].indice,g[9].indice,g[12].indice,g[30].indice,g[15].valeur},
                            [5]={g[54].indice,g[55].indice,g[11].indice,g[63].indice,g[15].indice,g[5].indice,g[64].valeur}
                           };
        int x=rand()%6;
        int y;
        i=0;
        while(i<12)
        {
            y=rand()%18;
            if(Scores[x][y]!=0)
            {
                if(Scores[x][y]==78)
                {
                    Scores[x][y]=0;
                }
                g[Scores[x][y]].valeur++;
                i++;
            }
        }

        return profs[x];
    }

    if(strcmp(Ori,"Bourgeoisie\n")==0)
    {

        char *profs[9];
        for(cpt=0; cpt<9; cpt++)
        {
            profs[cpt]=(char*)malloc(100*sizeof(char));
        }

        profs[0]="Armateur\n";
        profs[1]="Banquier\n";
        profs[2]="Commis\n";
        profs[3]="Negociant\n";
        profs[4]="Notaire\n";
        profs[5]="PetitMarchand\n";
        profs[6]="RicheMarchand\n";
        profs[7]="Speculateur\n";
        profs[8]="Tenanciers\n";

        int i;

        int Scores[9][18]= {[0]={g[2].indice,g[11].indice,g[9].indice,g[32].indice,g[62].valeur},
                            [1]={g[2].indice,g[3].indice,g[10].indice,g[11].indice,g[64].indice,g[63].indice,g[59].indice,g[60].indice,g[61].valeur},
                            [2]={g[2].indice,g[3].indice,g[10].indice,g[59].indice,g[60].indice,g[61].indice,g[11].indice,g[64].indice,g[46].valeur},
                            [3]={g[2].indice,g[4].indice,g[10].indice,g[59].indice,g[60].indice,g[61].indice,g[11].indice,g[54].valeur},
                            [4]={g[2].indice,g[3].indice,g[10].indice,g[63].indice,g[56].valeur},
                            [5]={g[47].indice,g[10].indice,g[59].indice,g[60].indice,g[61].indice,g[63].indice,g[65].indice,g[46].valeur},
                            [6]={g[2].indice,g[32].indice,g[4].indice,g[54].indice,g[11].indice,g[62].valeur},
                            [7]={g[40].indice,g[47].indice,g[2].indice,g[3].indice,g[54].indice,g[10].indice,g[58].valeur},
                            [8]={g[24].indice,g[47].indice,g[54].indice,g[10].indice,g[57].indice,g[58].indice,g[63].valeur}
                           };
        int x=rand()%9;
        int y;
        i=0;
        while(i<12)
        {
            y=rand()%18;
            if(Scores[x][y]!=0)
            {
                if(Scores[x][y]==78)
                {
                    Scores[x][y]=0;
                }
                g[Scores[x][y]].valeur++;
                i++;
            }
        }
        return profs[x];

    }

    if(strcmp(Ori,"Colons\n")==0)
    {

        char *profs[6];
        for(cpt=0; cpt<6; cpt++)
        {
            profs[cpt]=(char*)malloc(100*sizeof(char));
        }

        profs[0]="Boucanier\n";
        profs[1]="Contremaitre\n";
        profs[2]="Engage\n";
        profs[3]="Flibustier\n";
        profs[4]="Habitant\n";
        profs[5]="Planteur\n";

        int i;


        int Scores[6][18]= {[0]={g[66].indice,g[67].indice,g[69].indice,g[68].indice,g[70].indice,g[39].indice,g[10].indice,g[41].indice,g[45].indice,g[30].valeur},
                            [1]={g[66].indice,g[67].indice,g[69].indice,g[68].indice,g[70].indice,g[75].indice,g[46].indice,g[57].valeur},
                            [2]={g[24].indice,g[40].indice,g[54].indice,g[46].indice,g[45].indice,g[41].valeur},
                            [3]={g[66].indice,g[67].indice,g[69].indice,g[68].indice,g[70].indice,g[41].indice,g[58].indice,g[62].indice,g[16].indice,g[30].indice,g[37].valeur},
                            [4]={g[25].indice,g[26].indice,g[66].indice,g[67].indice,g[69].indice,g[68].indice,g[58].indice,g[62].indice,g[10].indice,g[40].indice,g[45].valeur},
                            [5]={g[25].indice,g[26].indice,g[2].indice,g[4].indice,g[10].indice,g[57].indice,g[58].indice,g[62].valeur}
                           };
        int x=rand()%6;
        int y;
        i=0;
        while(i<12)
        {
            y=rand()%18;
            if(Scores[x][y]!=0)
            {
                if(Scores[x][y]==78)
                {
                    Scores[x][y]=0;
                }
                g[Scores[x][y]].valeur++;
                i++;
            }
        }

        return profs[x];
    }

    if(strcmp(Ori,"Malandrins\n")==0)
    {

        char *profs[11];
        for(cpt=0; cpt<11; cpt++)
        {
            profs[cpt]=(char*)malloc(100*sizeof(char));
        }

        profs[0]="Agitateur\n";
        profs[1]="Assassin\n";
        profs[2]="Bourreau\n";
        profs[3]="Escroc\n";
        profs[4]="Espion\n";
        profs[5]="Joueur\n";
        profs[6]="Prostituee\n";
        profs[7]="Spadassin\n";
        profs[8]="Trafiquant\n";
        profs[9]="TrafiquantEbene\n";
        profs[10]="Voleur\n";



        int Scores[11][18]= {[0]={g[71].indice,g[54].indice,g[55].indice,g[62].indice,g[64].indice,g[63].indice,g[41].valeur},
                             [1]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[47].indice,g[41].indice,g[56].indice,g[8].indice,g[16].indice,g[64].indice,g[43].valeur},
                             [2]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[54].indice,g[56].indice,g[57].indice,g[64].valeur},
                             [3]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[40].indice,g[47].indice,g[41].indice,g[56].indice,g[43].indice,g[63].valeur},
                             [4]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[40].indice,g[47].indice,g[41].indice,g[54].indice,g[56].indice,g[2].indice,g[43].indice,g[64].valeur},
                             [5]={g[71].indice,g[40].indice,g[47].indice,g[41].indice,g[58].indice,g[75].valeur},
                             [6]={g[54].indice,g[43].indice,g[63].indice,g[65].indice,g[30].indice,g[51].indice,g[52].indice,g[53].indice,g[75].valeur},
                             [7]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[71].indice,g[40].indice,g[41].indice,g[77].valeur},
                             [8]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[70].indice,g[40].indice,g[3].indice,g[41].indice,g[57].indice,g[43].indice,g[37].indice,g[59].indice,g[60].indice,g[61].valeur},
                             [9]={g[70].indice,g[40].indice,g[47].indice,g[4].indice,g[57].indice,g[30].indice,g[59].indice,g[60].indice,g[61].valeur},
                             [10]={g[39].indice,g[40].indice,g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[41].indice,g[77].indice,g[43].indice,g[46].valeur}
                            };
        int x=rand()%11;
        int y;
        int i=0;
        while(i<12)
        {
            y=rand()%18;
            if(Scores[x][y]!=0)
            {
                if(Scores[x][y]==78)
                {
                    Scores[x][y]=0;
                }
                g[Scores[x][y]].valeur++;
                i++;
            }
        }

        return profs[x];
    }

    if(strcmp(Ori,"Paysannerie\n")==0)

    {

        char *profs[6];
        for(cpt=0; cpt<6; cpt++)
        {
            profs[cpt]=(char*)malloc(100*sizeof(char));
        }

        profs[0]="Artisan\n";
        profs[1]="Bucheron\n";
        profs[2]="Laquais\n";
        profs[3]="Paysan\n";
        profs[4]="Pecheur\n";
        profs[5]="Serveuse\n";



        int Scores[6][18]= {[0]={g[25].indice,g[26].indice,g[55].indice,g[46].indice,g[10].valeur},
                            [1]={g[4].indice,g[45].indice,g[57].indice,g[39].indice,g[66].indice,g[67].indice,g[68].indice,g[69].valeur},
                            [2]={g[24].indice,g[47].indice,g[54].indice,g[63].indice,g[64].indice,g[46].indice,g[56].indice,g[42].valeur},
                            [3]={g[25].indice,g[26].indice,g[34].indice,g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[37].indice,g[41].indice,g[42].indice,g[29].valeur},
                            [4]={g[31].indice,g[34].indice,g[37].indice,g[36].indice,g[44].valeur},
                            [5]={g[54].indice,g[65].indice,g[56].indice,g[43].indice,g[47].indice,g[51].indice,g[52].indice,g[53].indice,g[76].valeur}
                           };
        int x=rand()%6;
        int y;
        int i=0;
        while(i<12)
        {
            y=rand()%18;
            if(Scores[x][y]!=0)
            {
                if(Scores[x][y]==78)
                {
                    Scores[x][y]=0;
                }
                g[Scores[x][y]].valeur++;
                i++;
            }
        }
        return profs[x];

    }


    if(strcmp(Ori,"Noblesse\n")==0)

    {

        char *profs[4];
        for(cpt=0; cpt<4; cpt++)
        {
            profs[cpt]=(char*)malloc(100*sizeof(char));
        }

        profs[0]="Bretteur\n";
        profs[1]="Conspirateur\n";
        profs[2]="Courtisan\n";
        profs[3]="Mecene\n";


        int i;

        int Scores[4][18]= {[0]={g[40].indice,g[27].indice,g[76].indice,g[56].indice,g[57].indice,g[71].indice,g[64].indice,g[66].indice,g[67].indice,g[68].indice,g[69].valeur},
                            [1]={g[47].indice,g[40].indice,g[62].indice,g[42].indice,g[16].indice,g[71].indice,g[64].indice,g[63].indice,g[56].valeur},
                            [2]={g[42].indice,g[56].indice,g[63].indice,g[64].indice,g[65].indice,g[46].valeur},
                            [3]={g[17].indice,g[18].indice,g[54].indice,g[2].indice,g[11].indice,g[64].valeur}
                           };
        int x=rand()%4;
        int y;
        i=0;
        while(i<12)
        {
            y=rand()%18;
            if(Scores[x][y]!=0)
            {
                if(Scores[x][y]==78)
                {
                    Scores[x][y]=0;
                }
                g[Scores[x][y]].valeur++;
                i++;
            }
        }

        return profs[x];
    }

    if(strcmp(Ori,"Marine\n")==0)
    {

        char *profs[19];
        for(cpt=0; cpt<19; cpt++)
        {
            profs[cpt]=(char*)malloc(100*sizeof(char));
        }


        profs[0]="Capitaine\n";
        profs[1]="Second\n";
        profs[2]="Canonnier\n";
        profs[3]="Cambusier\n";
        profs[4]="ChefDePiece\n";
        profs[5]="Coq\n";
        profs[6]="Enseigne\n";
        profs[7]="Gabier\n";
        profs[8]="MaitreCalfat\n";
        profs[9]="MaitreCanonnier\n";
        profs[10]="MaitreCharpentier\n";
        profs[11]="MaitreEquipage\n";
        profs[12]="MaitreVoilier\n";
        profs[13]="Matelot\n";
        profs[14]="Pilote\n";
        profs[15]="QuartierMaitre\n";
        profs[16]="ServantPiece\n";
        profs[17]="Vigie\n";
        profs[18]="Mousse\n";

        int i;

        int Scores[19][18]= {[0]={g[0].indice,g[62].indice,g[31].indice,g[4].indice,g[34].indice,g[11].indice,g[35].indice,g[71].indice,g[16].indice,g[33].indice,g[66].indice,g[67].indice,g[68].indice,g[69].valeur},
                             [1]={g[62].indice,g[31].indice,g[34].indice,g[11].indice,g[35].indice,g[71].indice,g[16].indice,g[33].indice,g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[37].indice,g[32].valeur},
                             [2]={g[0].indice,g[62].indice,g[31].indice,g[19].indice,g[20].indice,g[11].indice,g[71].indice,g[16].indice,g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[70].valeur},
                             [3]={g[32].indice,g[24].indice,g[57].indice,g[63].indice,g[10].valeur},
                             [4]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[0].indice,g[70].indice,g[19].indice,g[20].indice,g[77].indice,g[37].indice,g[62].valeur},
                             [5]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[24].indice,g[10].indice,g[46].indice,g[8].valeur},
                             [6]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[71].indice,g[19].indice,g[20].indice,g[0].indice,g[31].indice,g[33].indice,g[51].indice,g[52].indice,g[53].indice,g[54].indice,g[77].indice,g[34].indice,g[62].indice,g[37].valeur},
                             [7]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[71].indice,g[40].indice,g[51].indice,g[52].indice,g[53].indice,g[31].indice,g[41].indice,g[37].indice,g[70].indice,g[77].valeur},
                             [8]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[75].indice,g[46].indice,g[32].indice,g[31].indice,g[9].indice,g[21].valeur},
                             [9]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[70].indice,g[54].indice,g[55].indice,g[30].indice,g[57].indice,g[19].indice,g[20].indice,g[77].indice,g[71].valeur},
                             [10]={g[31].indice,g[32].indice,g[9].indice,g[22].indice,g[46].indice,g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[75].valeur},
                             [11]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[70].indice,g[54].indice,g[55].indice,g[31].indice,g[57].indice,g[37].indice,g[40].indice,g[77].indice,g[71].valeur},
                             [12]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[75].indice,g[39].indice,g[32].indice,g[31].indice,g[9].indice,g[46].indice,g[23].valeur},
                             [13]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[70].indice,g[31].indice,g[77].indice,g[44].indice,g[37].indice,g[71].indice,g[51].indice,g[52].indice,g[53].valeur},
                             [14]={g[1].indice,g[31].indice,g[32].indice,g[4].indice,g[34].indice,g[11].indice,g[35].valeur},
                             [15]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[70].indice,g[31].indice,g[77].indice,g[62].indice,g[3].indice,g[71].indice,g[54].indice,g[55].indice,g[63].indice,g[38].indice,g[37].valeur},
                             [16]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[70].indice,g[37].indice,g[77].indice,g[19].indice,g[20].indice,g[71].indice,g[46].valeur},
                             [17]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[70].indice,g[37].indice,g[77].indice,g[39].indice,g[40].indice,g[71].indice,g[46].indice,g[32].valeur},
                             [18]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[75].indice,g[51].indice,g[52].indice,g[19].indice,g[20].indice,g[53].indice,g[31].indice,g[32].indice,g[40].indice,g[77].indice,g[37].indice,g[36].indice,g[44].valeur}
                            };

        int x=rand()%19;
        int y;
        i=0;
        while(i<12)
        {
            y=rand()%18;
            if(Scores[x][y]!=0)
            {
                if(Scores[x][y]==78)
                {
                    Scores[x][y]=0;
                }
                g[Scores[x][y]].valeur++;
                i++;
            }
        }

        return profs[x];
    }
    return "none";
}
char* AddProfessionChoose(Competence*g, char*Ori, char *met)
{


    int cpt;
    if(strcmp(Ori,"Armee\n")==0)
    {
        char *profs[15];
        for(cpt=0; cpt<15; cpt++)
        {
            profs[cpt]=(char*)malloc(100*sizeof(char));
        }


        profs[0]="Artilleur\n";
        profs[1]="Cadet\n";
        profs[2]="Cavalier\n";
        profs[3]="Geolier\n";
        profs[4]="Lancier\n";
        profs[5]="MaitreArme\n";
        profs[6]="MaitreEscrime\n";
        profs[7]="Mousquetaire\n";
        profs[8]="OfficerArtillerie\n";
        profs[9]="LieutenantInfanterie\n";
        profs[10]="OfficierCavalerie\n";
        profs[11]="SergentRecruteur\n";
        profs[12]="SousOfficierArtillerie\n";
        profs[13]="SousOfficierInfanterie\n";
        profs[14]="Stratege\n";


        int Scores[15][18]= {[0]{g[40].indice,g[77].indice,g[70].indice,g[71].valeur},
                             [1]{g[40].indice,g[77].indice,g[70].indice,g[72].indice,g[19].indice,g[20].indice,g[66].indice,g[67].indice,g[68].indice,g[69].valeur},
                             [2]={g[29].indice,g[42].indice,g[71].indice,g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[45].valeur},
                             [3]={g[75].indice,g[57].indice,g[30].indice,g[46].indice,g[66].indice,g[67].indice,g[68].indice,g[69].valeur},
                             [4]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[40].indice,g[70].indice,g[46].indice,g[58].indice,g[77].indice,g[48].indice,g[49].indice,g[50].indice,g[51].indice,g[52].indice,g[53].valeur},
                             [5]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[16].indice,g[77].indice,g[70].valeur},
                             [6]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[11].indice,g[77].indice,g[76].indice,g[55].valeur},
                             [7]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[70].indice,g[40].indice,g[62].indice,g[76].indice,g[77].indice,g[16].indice,g[56].valeur},
                             [8]={g[0].indice,g[62].indice,g[55].indice,g[56].indice,g[19].indice,g[20].indice,g[16].valeur},
                             [9]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[71].indice,g[76].indice,g[4].indice,g[62].indice,g[16].valeur},
                             [10]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[16].indice,g[71].indice,g[62].indice,g[4].indice,g[76].indice,g[42].valeur},
                             [11]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[75].indice,g[47].indice,g[40].indice,g[54].indice,g[55].indice,g[58].indice,g[63].indice,g[77].indice,g[71].valeur},
                             [12]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[0].indice,g[62].indice,g[55].indice,g[57].indice,g[19].indice,g[20].valeur},
                             [13]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[71].indice,g[16].indice,g[62].indice,g[4].indice,g[76].indice,g[42].valeur},
                             [14]={g[0].indice,g[62].indice,g[42].indice,g[4].indice,g[64].indice,g[16].indice,g[51].indice,g[52].indice,g[53].valeur}
                            };
        int p=0;
        int x=rand()%15;
        for(p=0; p<15; p++)
        {
            if(strcmp(profs[p], met)==0)
            {
                x=p;
                printf("%d",p);
            }
        }

        int y;
        int i=0;
        while(i<12)
        {
            y=rand()%18;
            if(Scores[x][y]!=0)
            {
                if(Scores[x][y]==78)
                {
                    Scores[x][y]=0;
                }
                g[Scores[x][y]].valeur++;
                g[Scores[x][y]].profession++;
                i++;
            }
        }

        return profs[x];
    }
    if(strcmp(Ori,"Tribu\n")==0)
    {

        char *profs[7];
        for(cpt=0; cpt<7; cpt++)
        {
            profs[cpt]=(char*)malloc(100*sizeof(char));
        }

        profs[0]="Chasseur\n";
        profs[1]="Chef\n";
        profs[2]="Griot\n";
        profs[3]="Guerrier\n";
        profs[4]="Pecheur\n";
        profs[5]="PecheurCaraibe\n";
        profs[6]="PecheurMosquito\n";


        int Scores[7][18]= {[0]={g[73].indice,g[74].indice,g[40].indice,g[27].indice,g[41].indice,g[4].indice,g[46].indice,g[45].indice,g[66].indice,g[67].indice,g[68].indice,g[69].valeur},
                            [1]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[73].indice,g[74].indice,g[62].indice,g[54].indice,g[57].indice,g[63].indice,g[64].indice,g[16].valeur},
                            [2]={g[55].indice,g[51].indice,g[52].indice,g[53].indice,g[59].indice,g[60].indice,g[61].indice,g[63].indice,g[64].indice,g[13].indice,g[14].valeur},
                            [3]={g[39].indice,g[40].indice,g[41].indice,g[45].indice,g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[73].indice,g[74].valeur},
                            [4]={g[73].indice,g[74].indice,g[41].indice,g[4].indice,g[34].indice,g[37].indice,g[36].indice,g[45].valeur},
                            [5]={g[73].indice,g[74].indice,g[41].indice,g[4].indice,g[34].indice,g[37].indice,g[36].indice,g[45].indice,g[46].valeur},
                            [6]={g[73].indice,g[74].indice,g[4].indice,g[34].indice,g[37].indice,g[38].indice,g[36].indice,g[45].valeur}
                           };
        int p=0;
        int x=rand()%15;
        for(p=0; p<7; p++)
        {
            if(strcmp(profs[p], met)==0)
            {
                x=p;
            }
        }

        int y;
        int i=0;
        while(i<12)
        {
            y=rand()%18;
            if(Scores[x][y]!=0)
            {
                if(Scores[x][y]==78)
                {
                    Scores[x][y]=0;
                }
                g[Scores[x][y]].valeur++;
                g[Scores[x][y]].profession++;
                i++;
            }
        }

        return profs[x];
    }

    if(strcmp(Ori,"Amuseurs\n")==0)
    {

        char *profs[7];
        for(cpt=0; cpt<7; cpt++)
        {
            profs[cpt]=(char*)malloc(100*sizeof(char));
        }

        profs[0]="Acrobate\n";
        profs[1]="Chansonnier\n";
        profs[2]="Comedien\n";
        profs[3]="Dresseur\n";
        profs[4]="Ecrivain\n";
        profs[5]="Musicien\n";
        profs[6]="PeintreMarine\n";

        int i;

        int Scores[7][18]= {[0]={g[39].indice,g[40].indice,g[4].indice,g[77].indice,g[46].indice,g[66].indice,g[47].valeur},
                            [1]={g[4].indice,g[5].indice,g[17].indice,g[18].indice,g[54].indice,g[55].indice,g[56].indice,g[65].indice,g[11].indice,g[43].valeur},
                            [2]={g[47].indice,g[51].indice,g[52].indice,g[53].indice,g[5].indice,g[54].indice,g[55].indice,g[65].indice,g[63].valeur},
                            [3]={g[47].indice,g[54].indice,g[56].indice,g[57].indice,g[63].indice,g[62].indice,g[29].valeur},
                            [4]={g[51].indice,g[52].indice,g[53].indice,g[4].indice,g[59].indice,g[60].indice,g[61].indice,g[64].indice,g[63].indice,g[11].valeur},
                            [5]={g[17].indice,g[18].indice,g[54].indice,g[55].indice,g[56].indice,g[59].indice,g[60].indice,g[61].indice,g[46].indice,g[11].valeur},
                            [6]={g[17].indice,g[18].indice,g[1].indice,g[31].indice,g[32].indice,g[4].indice,g[5].indice,g[55].indice,g[16].indice,g[46].valeur}
                           };
        int p=0;
        int x=rand()%15;
        for(p=0; p<7; p++)
        {
            if(strcmp(profs[p], met)==0)
            {
                x=p;
            }
        }

        int y;
        i=0;
        while(i<12)
        {
            y=rand()%18;
            if(Scores[x][y]!=0)
            {
                if(Scores[x][y]==78)
                {
                    Scores[x][y]=0;
                }
                g[Scores[x][y]].valeur++;
                g[Scores[x][y]].profession++;
                i++;
            }
        }

        return profs[x];
    }

    if(strcmp(Ori,"Intellectuels\n")==0)
    {

        char *profs[6];
        for(cpt=0; cpt<6; cpt++)
        {
            profs[cpt]=(char*)malloc(100*sizeof(char));
        }

        profs[0]="Architecte\n";
        profs[1]="Cartographe\n";
        profs[2]="Chirurgien\n";
        profs[3]="Ingenieur\n";
        profs[4]="Medecin\n";
        profs[5]="Philosophe\n";

        int i;

        int Scores[6][18]= {[0]={g[17].indice,g[18].indice,g[1].indice,g[4].indice,g[11].indice,g[55].indice,g[15].valeur},
                            [1]={g[17].indice,g[18].indice,g[1].indice,g[4].indice,g[11].indice,g[35].indice,g[15].valeur},
                            [2]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[28].indice,g[30].indice,g[12].indice,g[8].valeur},
                            [3]={g[22].indice,g[31].indice,g[32].indice,g[9].indice,g[16].indice,g[15].indice,g[62].valeur},
                            [4]={g[28].indice,g[54].indice,g[9].indice,g[12].indice,g[30].indice,g[15].valeur},
                            [5]={g[54].indice,g[55].indice,g[11].indice,g[63].indice,g[15].indice,g[5].indice,g[64].valeur}
                           };
        int p=0;
        int x=rand()%15;
        for(p=0; p<6; p++)
        {
            if(strcmp(profs[p], met)==0)
            {
                x=p;
            }
        }

        int y;
        i=0;
        while(i<12)
        {
            y=rand()%18;
            if(Scores[x][y]!=0)
            {
                if(Scores[x][y]==78)
                {
                    Scores[x][y]=0;
                }
                g[Scores[x][y]].valeur++;
                g[Scores[x][y]].profession++;
                i++;
            }
        }

        return profs[x];
    }

    if(strcmp(Ori,"Bourgeoisie\n")==0)
    {

        char *profs[9];
        for(cpt=0; cpt<9; cpt++)
        {
            profs[cpt]=(char*)malloc(100*sizeof(char));
        }

        profs[0]="Armateur\n";
        profs[1]="Banquier\n";
        profs[2]="Commis\n";
        profs[3]="Negociant\n";
        profs[4]="Notaire\n";
        profs[5]="PetitMarchand\n";
        profs[6]="RicheMarchand\n";
        profs[7]="Speculateur\n";
        profs[8]="Tenanciers\n";

        int i;

        int Scores[9][18]= {[0]={g[2].indice,g[11].indice,g[9].indice,g[32].indice,g[62].valeur},
                            [1]={g[2].indice,g[3].indice,g[10].indice,g[11].indice,g[64].indice,g[63].indice,g[59].indice,g[60].indice,g[61].valeur},
                            [2]={g[2].indice,g[3].indice,g[10].indice,g[59].indice,g[60].indice,g[61].indice,g[11].indice,g[64].indice,g[46].valeur},
                            [3]={g[2].indice,g[4].indice,g[10].indice,g[59].indice,g[60].indice,g[61].indice,g[11].indice,g[54].valeur},
                            [4]={g[2].indice,g[3].indice,g[10].indice,g[63].indice,g[56].valeur},
                            [5]={g[47].indice,g[10].indice,g[59].indice,g[60].indice,g[61].indice,g[63].indice,g[65].indice,g[46].valeur},
                            [6]={g[2].indice,g[32].indice,g[4].indice,g[54].indice,g[11].indice,g[62].valeur},
                            [7]={g[40].indice,g[47].indice,g[2].indice,g[3].indice,g[54].indice,g[10].indice,g[58].valeur},
                            [8]={g[24].indice,g[47].indice,g[54].indice,g[10].indice,g[57].indice,g[58].indice,g[63].valeur}
                           };
        int p=0;
        int x=rand()%15;
        for(p=0; p<9; p++)
        {
            if(strcmp(profs[p], met)==0)
            {
                x=p;
            }
        }

        int y;
        i=0;
        while(i<12)
        {
            y=rand()%18;
            if(Scores[x][y]!=0)
            {
                if(Scores[x][y]==78)
                {
                    Scores[x][y]=0;
                }
                g[Scores[x][y]].valeur++;
                g[Scores[x][y]].profession++;
                i++;
            }
        }
        return profs[x];

    }

    if(strcmp(Ori,"Colons\n")==0)
    {

        char *profs[6];
        for(cpt=0; cpt<6; cpt++)
        {
            profs[cpt]=(char*)malloc(100*sizeof(char));
        }

        profs[0]="Boucanier\n";
        profs[1]="Contremaitre\n";
        profs[2]="Engage\n";
        profs[3]="Flibustier\n";
        profs[4]="Habitant\n";
        profs[5]="Planteur\n";

        int i;


        int Scores[6][18]= {[0]={g[66].indice,g[67].indice,g[69].indice,g[68].indice,g[70].indice,g[39].indice,g[10].indice,g[41].indice,g[45].indice,g[30].valeur},
                            [1]={g[66].indice,g[67].indice,g[69].indice,g[68].indice,g[70].indice,g[75].indice,g[46].indice,g[57].valeur},
                            [2]={g[24].indice,g[40].indice,g[54].indice,g[46].indice,g[45].indice,g[41].valeur},
                            [3]={g[66].indice,g[67].indice,g[69].indice,g[68].indice,g[70].indice,g[41].indice,g[58].indice,g[62].indice,g[16].indice,g[30].indice,g[37].valeur},
                            [4]={g[25].indice,g[26].indice,g[66].indice,g[67].indice,g[69].indice,g[68].indice,g[58].indice,g[62].indice,g[10].indice,g[40].indice,g[45].valeur},
                            [5]={g[25].indice,g[26].indice,g[2].indice,g[4].indice,g[10].indice,g[57].indice,g[58].indice,g[62].valeur}
                           };
        int p=0;
        int x=rand()%15;
        for(p=0; p<6; p++)
        {
            if(strcmp(profs[p], met)==0)
            {
                x=p;

                printf("%d",p);
            }
        }

        int y;
        i=0;
        while(i<12)
        {
            y=rand()%18;
            if(Scores[x][y]!=0)
            {
                if(Scores[x][y]==78)
                {
                    Scores[x][y]=0;
                }
                g[Scores[x][y]].valeur++;
                g[Scores[x][y]].profession++;
                i++;
            }
        }

        return profs[x];
    }

    if(strcmp(Ori,"Malandrins\n")==0)
    {

        char *profs[11];
        for(cpt=0; cpt<11; cpt++)
        {
            profs[cpt]=(char*)malloc(100*sizeof(char));
        }

        profs[0]="Agitateur\n";
        profs[1]="Assassin\n";
        profs[2]="Bourreau\n";
        profs[3]="Escroc\n";
        profs[4]="Espion\n";
        profs[5]="Joueur\n";
        profs[6]="Prostituee\n";
        profs[7]="Spadassin\n";
        profs[8]="Trafiquant\n";
        profs[9]="TrafiquantEbene\n";
        profs[10]="Voleur\n";



        int Scores[11][18]= {[0]={g[71].indice,g[54].indice,g[55].indice,g[62].indice,g[64].indice,g[63].indice,g[41].valeur},
                             [1]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[47].indice,g[41].indice,g[56].indice,g[8].indice,g[16].indice,g[64].indice,g[43].valeur},
                             [2]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[54].indice,g[56].indice,g[57].indice,g[64].valeur},
                             [3]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[40].indice,g[47].indice,g[41].indice,g[56].indice,g[43].indice,g[63].valeur},
                             [4]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[40].indice,g[47].indice,g[41].indice,g[54].indice,g[56].indice,g[2].indice,g[43].indice,g[64].valeur},
                             [5]={g[71].indice,g[40].indice,g[47].indice,g[41].indice,g[58].indice,g[75].valeur},
                             [6]={g[54].indice,g[43].indice,g[63].indice,g[65].indice,g[30].indice,g[51].indice,g[52].indice,g[53].indice,g[75].valeur},
                             [7]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[71].indice,g[40].indice,g[41].indice,g[77].valeur},
                             [8]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[70].indice,g[40].indice,g[3].indice,g[41].indice,g[57].indice,g[43].indice,g[37].indice,g[59].indice,g[60].indice,g[61].valeur},
                             [9]={g[70].indice,g[40].indice,g[47].indice,g[4].indice,g[57].indice,g[30].indice,g[59].indice,g[60].indice,g[61].valeur},
                             [10]={g[39].indice,g[40].indice,g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[41].indice,g[77].indice,g[43].indice,g[46].valeur}
                            };
        int p=0;
        int x=rand()%15;
        for(p=0; p<11; p++)
        {
            if(strcmp(profs[p], met)==0)
            {
                x=p;
            }
        }

        int y;
        int i=0;
        while(i<12)
        {
            y=rand()%18;
            if(Scores[x][y]!=0)
            {
                if(Scores[x][y]==78)
                {
                    Scores[x][y]=0;
                }
                g[Scores[x][y]].valeur++;
                g[Scores[x][y]].profession++;
                i++;
            }
        }

        return profs[x];
    }

    if(strcmp(Ori,"Paysannerie\n")==0)

    {

        char *profs[6];
        for(cpt=0; cpt<6; cpt++)
        {
            profs[cpt]=(char*)malloc(100*sizeof(char));
        }

        profs[0]="Artisan\n";
        profs[1]="Bucheron\n";
        profs[2]="Laquais\n";
        profs[3]="Paysan\n";
        profs[4]="Pecheur\n";
        profs[5]="Serveuse\n";



        int Scores[6][18]= {[0]={g[25].indice,g[26].indice,g[55].indice,g[46].indice,g[10].valeur},
                            [1]={g[4].indice,g[45].indice,g[57].indice,g[39].indice,g[66].indice,g[67].indice,g[68].indice,g[69].valeur},
                            [2]={g[24].indice,g[47].indice,g[54].indice,g[63].indice,g[64].indice,g[46].indice,g[56].indice,g[42].valeur},
                            [3]={g[25].indice,g[26].indice,g[34].indice,g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[37].indice,g[41].indice,g[42].indice,g[29].valeur},
                            [4]={g[31].indice,g[34].indice,g[37].indice,g[36].indice,g[44].valeur},
                            [5]={g[54].indice,g[65].indice,g[56].indice,g[43].indice,g[47].indice,g[51].indice,g[52].indice,g[53].indice,g[76].valeur}
                           };
        int p=0;
        int x=rand()%15;
        for(p=0; p<6; p++)
        {
            if(strcmp(profs[p], met)==0)
            {
                x=p;
            }
        }

        int y;
        int i=0;
        while(i<12)
        {
            y=rand()%18;
            if(Scores[x][y]!=0)
            {
                if(Scores[x][y]==78)
                {
                    Scores[x][y]=0;
                }
                g[Scores[x][y]].valeur++;
                g[Scores[x][y]].profession++;
                i++;
            }
        }
        return profs[x];

    }


    if(strcmp(Ori,"Noblesse\n")==0)

    {

        char *profs[4];
        for(cpt=0; cpt<4; cpt++)
        {
            profs[cpt]=(char*)malloc(100*sizeof(char));
        }

        profs[0]="Bretteur\n";
        profs[1]="Conspirateur\n";
        profs[2]="Courtisan\n";
        profs[3]="Mecene\n";


        int i;

        int Scores[4][18]= {[0]={g[40].indice,g[27].indice,g[76].indice,g[56].indice,g[57].indice,g[71].indice,g[64].indice,g[66].indice,g[67].indice,g[68].indice,g[69].valeur},
                            [1]={g[47].indice,g[40].indice,g[62].indice,g[42].indice,g[16].indice,g[71].indice,g[64].indice,g[63].indice,g[56].valeur},
                            [2]={g[42].indice,g[56].indice,g[63].indice,g[64].indice,g[65].indice,g[46].valeur},
                            [3]={g[17].indice,g[18].indice,g[54].indice,g[2].indice,g[11].indice,g[64].valeur}
                           };
        int p=0;
        int x=rand()%15;
        for(p=0; p<4; p++)
        {
            if(strcmp(profs[p], met)==0)
            {
                x=p;
            }
        }

        int y;
        i=0;
        while(i<12)
        {
            y=rand()%18;
            if(Scores[x][y]!=0)
            {
                if(Scores[x][y]==78)
                {
                    Scores[x][y]=0;
                }
                g[Scores[x][y]].valeur++;
                g[Scores[x][y]].profession++;
                i++;
            }
        }

        return profs[x];
    }

    if(strcmp(Ori,"Marine\n")==0)
    {

        char *profs[19];
        for(cpt=0; cpt<19; cpt++)
        {
            profs[cpt]=(char*)malloc(100*sizeof(char));
        }


        profs[0]="Capitaine\n";
        profs[1]="Second\n";
        profs[2]="Canonnier\n";
        profs[3]="Cambusier\n";
        profs[4]="ChefDePiece\n";
        profs[5]="Coq\n";
        profs[6]="Enseigne\n";
        profs[7]="Gabier\n";
        profs[8]="MaitreCalfat\n";
        profs[9]="MaitreCanonnier\n";
        profs[10]="MaitreCharpentier\n";
        profs[11]="MaitreEquipage\n";
        profs[12]="MaitreVoilier\n";
        profs[13]="Matelot\n";
        profs[14]="Pilote\n";
        profs[15]="QuartierMaitre\n";
        profs[16]="ServantPiece\n";
        profs[17]="Vigie\n";
        profs[18]="Mousse\n";

        int i;

        int Scores[19][18]= {[0]={g[0].indice,g[62].indice,g[31].indice,g[4].indice,g[34].indice,g[11].indice,g[35].indice,g[71].indice,g[16].indice,g[33].indice,g[66].indice,g[67].indice,g[68].indice,g[69].valeur},
                             [1]={g[62].indice,g[31].indice,g[34].indice,g[11].indice,g[35].indice,g[71].indice,g[16].indice,g[33].indice,g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[37].indice,g[32].valeur},
                             [2]={g[0].indice,g[62].indice,g[31].indice,g[19].indice,g[20].indice,g[11].indice,g[71].indice,g[16].indice,g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[70].valeur},
                             [3]={g[32].indice,g[24].indice,g[57].indice,g[63].indice,g[10].valeur},
                             [4]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[0].indice,g[70].indice,g[19].indice,g[20].indice,g[77].indice,g[37].indice,g[62].valeur},
                             [5]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[24].indice,g[10].indice,g[46].indice,g[8].valeur},
                             [6]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[71].indice,g[19].indice,g[20].indice,g[0].indice,g[31].indice,g[33].indice,g[51].indice,g[52].indice,g[53].indice,g[54].indice,g[77].indice,g[34].indice,g[62].indice,g[37].valeur},
                             [7]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[71].indice,g[40].indice,g[51].indice,g[52].indice,g[53].indice,g[31].indice,g[41].indice,g[37].indice,g[70].indice,g[77].valeur},
                             [8]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[75].indice,g[46].indice,g[32].indice,g[31].indice,g[9].indice,g[21].valeur},
                             [9]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[70].indice,g[54].indice,g[55].indice,g[30].indice,g[57].indice,g[19].indice,g[20].indice,g[77].indice,g[71].valeur},
                             [10]={g[31].indice,g[32].indice,g[9].indice,g[22].indice,g[46].indice,g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[75].valeur},
                             [11]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[70].indice,g[54].indice,g[55].indice,g[31].indice,g[57].indice,g[37].indice,g[40].indice,g[77].indice,g[71].valeur},
                             [12]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[75].indice,g[39].indice,g[32].indice,g[31].indice,g[9].indice,g[46].indice,g[23].valeur},
                             [13]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[70].indice,g[31].indice,g[77].indice,g[44].indice,g[37].indice,g[71].indice,g[51].indice,g[52].indice,g[53].valeur},
                             [14]={g[1].indice,g[31].indice,g[32].indice,g[4].indice,g[34].indice,g[11].indice,g[35].valeur},
                             [15]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[70].indice,g[31].indice,g[77].indice,g[62].indice,g[3].indice,g[71].indice,g[54].indice,g[55].indice,g[63].indice,g[38].indice,g[37].valeur},
                             [16]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[70].indice,g[37].indice,g[77].indice,g[19].indice,g[20].indice,g[71].indice,g[46].valeur},
                             [17]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[70].indice,g[37].indice,g[77].indice,g[39].indice,g[40].indice,g[71].indice,g[46].indice,g[32].valeur},
                             [18]={g[66].indice,g[67].indice,g[68].indice,g[69].indice,g[75].indice,g[51].indice,g[52].indice,g[19].indice,g[20].indice,g[53].indice,g[31].indice,g[32].indice,g[40].indice,g[77].indice,g[37].indice,g[36].indice,g[44].valeur}
                            };

        int p=0;
        int x=rand()%15;
        for(p=0; p<19; p++)
        {
            if(strcmp(profs[p], met)==0)
            {
                x=p;
            }
        }

        int y;
        i=0;
        while(i<12)
        {
            y=rand()%18;
            if(Scores[x][y]!=0)
            {
                if(Scores[x][y]==78)
                {
                    Scores[x][y]=0;
                }
                g[Scores[x][y]].valeur++;
                g[Scores[x][y]].profession++;
                i++;
            }
        }

        return profs[x];
    }
    return "none";
}


void clrBuffer(void)
{
    int c;
    while((c=getchar()) != '\n' && c != EOF);
}

char* RemoveChars(char str[], char c)
{

    int n = strlen(str);
    int i;

    char *s=(char*)malloc((n-1)*sizeof(char));
    for(i=0; str[i]!='\0'; i++)
    {

        if(str[i]!='\n')
        {

            s[i]=str[i];
        }

    }
    s[i-1]='\0';



    return s;

}


