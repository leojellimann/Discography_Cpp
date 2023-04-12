#ifndef MUSICIEN_H_INCLUDED
#define MUSICIEN_H_INCLUDED

#include <string>
#include <vector>

using namespace std;

class Musicien: public Membre
{
private:
    Instrument *m_instrument;//Instrument utilisé par le musicien
    bool m_chanteur;//Vrai si le musicien est chanteur
public:
    Musicien(string nom, int naissance, int deces=0);//Constructeur de la classe
    void setChanteur();//Met à vrai l'attribut "chanteur"
    void setInstrument(Instrument *m_instrument);//Initialise la valeur de l'attribut instrument
    void afficher();//Affiche nom du musicien, age, instrument et chanteur ou non

};

#endif // MUSICIEN_H_INCLUDED
