#ifndef PROFESSION_H_INCLUDED
#define PROFESSION_H_INCLUDED

typedef struct Profession
{
    char*Nom;
    char* Origine;
    int nb;
    char **Competences;
    int indice;
    struct  Profession *suivant;

}Profession;
typedef struct Professions
{
    struct Profession *premier;

}Professions;
#endif // PROFESSION_H_INCLUDED
