#ifndef CHANSON_H_INCLUDED
#define CHANSON_H_INCLUDED

#include <string>
#include <vector>

using namespace std;
class Chanson
{
private:
    string m_titre;//Titre de la chanson
public:
    Chanson(string titre);
    string getTitre();//Retourne le titre de la musique
};

#endif // CHANSON_H_INCLUDED
