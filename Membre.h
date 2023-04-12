#ifndef MEMBRE_H_INCLUDED
#define MEMBRE_H_INCLUDED

#include <string>
#include <vector>

using namespace std;

class Membre
{
protected:
    string m_nom, m_role;
    int m_naissance, m_deces;//deces =0 si le membre est en vie
public:
    Membre(string nom, string role, int naissance, int deces=0);//Constructeur de la classe
    int getAge();//Methode qui calcul et retourne l'âge du membre
    void afficher();//Déclaration de la fonction d'affichage du membre
};

#endif // MEMBRE_H_INCLUDED
