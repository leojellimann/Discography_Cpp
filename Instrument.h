#ifndef INSTRUMENT_H_INCLUDED
#define INSTRUMENT_H_INCLUDED

#include <string>
#include <vector>

using namespace std;

class Instrument
{
private:
    string m_nom, m_type;
public:
    Instrument(string nom, string type);//Déclaration du constructeur de la classe
    void afficher();//Déclaration de la fonction d'affichage de l'instrument
};

#endif // INSTRUMENT_H_INCLUDED
