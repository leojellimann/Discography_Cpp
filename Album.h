#ifndef ALBUM_H_INCLUDED
#define ALBUM_H_INCLUDED

#include <string>
#include <vector>

using namespace std;

class Album
{
private:
    string m_titre;//Titre de l'album
    int m_parution;
    vector<Chanson> chansons;//Vecteur contenant la liste des chansons de l'album
    string *m_listechansons;
public:
    Album(string titre, int parution);
    Album(string titre, int parution, string *listechansons);//Permet d'ajouter les titres
    void addChanson(string titre_chanson);//Ajoute une chanson au vecteur chansons de l'alubm
    void afficher();
};

#endif // ALBUM_H_INCLUDED
