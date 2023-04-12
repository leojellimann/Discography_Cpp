#ifndef GROUPE_H_INCLUDED
#define GROUPE_H_INCLUDED

#include <string>
#include <vector>

using namespace std;

class Groupe
{
private:
    string m_nom;
    int m_creation, m_fin;//Année de création du groupe et année de fin ou 0 s'il existe toujours
    vector<Album *>albums;//Liste des albums du groupe
    vector<Membre *>membres;//Liste des membres du groupe
public:
    Groupe(string nom, int creation, int fin=0);
    void addAlbum(Album *album);//Ajoute un album au groupe
    void addMembre(Membre *membre);//Ajoute un membre au groupe
    void afficher();//Affiche nom du groupe, date de création et de fin, liste des membres, des albums et des chansons
};

#endif // GROUPE_H_INCLUDED
