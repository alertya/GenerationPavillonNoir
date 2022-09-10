#ifndef COMP_H_INCLUDED
#define COMP_H_INCLUDED
typedef struct Competence
{
    int indice;
    int appartenance;
    int valeur;
    char* Nom;
    int metier;
    int incremented; //Si la compétence a été augmenté lors de l'étape finale ou non
    int profession; //Si la compétence a été augmenté lors de l'étape de l'attribution des 12 points de compétence de la profession ou non

}Competence;
#endif // COMP_H_INCLUDED
