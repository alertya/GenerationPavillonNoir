#ifndef COMP_H_INCLUDED
#define COMP_H_INCLUDED
typedef struct Competence
{
    int indice;
    int appartenance;
    int valeur;
    char* Nom;
    int metier;
    int incremented; //Si la comp�tence a �t� augment� lors de l'�tape finale ou non
    int profession; //Si la comp�tence a �t� augment� lors de l'�tape de l'attribution des 12 points de comp�tence de la profession ou non

}Competence;
#endif // COMP_H_INCLUDED
