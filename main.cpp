#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "Instrument.h"
#include "Membre.h"
#include "Musicien.h"
#include "Chanson.h"
#include "Album.h"
#include "Groupe.h"
using namespace std;

int cmptr=0;//Permet d'afficher correctement Musicien sans afficher des caractères non voulus de Membre
//Permet également d'afficher une seule fois Musicien ====== et non pas à chaque appel de la méthode afficher de musicien


Instrument::Instrument(string nom, string type)//Initialisation du constructeur pour la classe Instrument
{
    m_nom = nom;
    m_type = type;
}

Membre::Membre(string nom, string role, int naissance, int deces)//Initialisation du constructeur pour la classe Membre
{
    m_nom = nom;
    m_role = role;
    m_naissance = naissance;
    m_deces = deces;
}

Musicien::Musicien(string nom,int naissance, int deces): Membre(nom,"musicien",naissance,deces)//On initialise le role à musicien
{

}

Chanson::Chanson(string titre)
{
    m_titre = titre;
}

Album::Album(string titre, int parution)
{
    m_titre = titre;
    m_parution = parution;
}


Album::Album(string titre, int parution, string *listechansons)
{
    m_titre = titre;
    m_parution = parution;
    m_listechansons = listechansons;
}

Groupe::Groupe(string nom, int creation, int fin)
{
    m_nom = nom;
    m_creation = creation;
    m_fin = fin;
}



void Musicien::setInstrument(Instrument *instrument)
{
    m_instrument = instrument;
}

void Musicien::setChanteur()
{
    m_chanteur = 1;
}


int Membre::getAge()//Initialisation de la fonction qui récupère l'âge du membre
{
    if(m_deces != 0)
    {
        return m_deces - m_naissance;
    }
    else
    {
        return 2020 - m_naissance;
    }

}

string Chanson::getTitre()//Retourne le titre de la chanson
{
    return m_titre;
}

void Album::addChanson(string titre_chanson)
{
    chansons.push_back(Chanson(titre_chanson));//Récupère la chanson de tr->addChanson(""); et la place dans le vecteur chansons
}

void Groupe::addAlbum(Album *album)
{
    albums.push_back(album);

}

void Groupe::addMembre(Membre *membre)
{

}



void Instrument::afficher()//Initialisation de l'affichage quand on fait appelle quelconque instrument
{
    if(cmptr == 0 )
    {
      cout<<"Instrument"<<endl<<"=========="<<endl<<endl;
    }

    cout<<"   Instrument: "<<m_nom<<"("<<m_type<<")"<<endl;
}

void Membre::afficher()
{
    if(m_role != "musicien")//On affichera Membre pour tous les rôles sauf quand on a un musicien car un affichage est dédié au musicien
    {
        cout<<"Membre"<<endl<<"=========="<<endl<<endl;
    }

    if (m_deces != 0)
    {
        cout<<m_nom<<"("<<getAge()<<" ans, rip) : "<<m_role<<endl;
    }
    else
    {
        cout<<m_nom<<"("<<getAge()<<" ans) : "<<m_role<<endl;
    }
}

void Musicien::afficher()
{
        if(m_role=="musicien" && cmptr == 0)//Permet d'afficher une seule fois "Musicien =============="
        {
            cout<<"Musicien"<<endl<<"=========="<<endl<<endl;
            cmptr=cmptr+1;//Permet de ne pas afficher "Musicien ============" à chaque fois qu'on rentre dans la boucle
        }


        Membre::afficher();//On demande d'affcher les cas du membre

        m_instrument -> afficher();//Affiche Instrument: nom (type)

        if(m_chanteur == 1)
        {
            cout<<"   C'est le chanteur"<<endl;
        }
}

void Album::afficher()
{
    int surcharge = 0;

    if(m_listechansons == 0)
    {
        cout<<"Album"<<endl<<"=========="<<endl<<endl;
    }
    else
    {
        surcharge ++;
        cout<<"Album (surcharge)"<<endl<<"=========="<<endl<<endl;
    }
    cout<<m_titre<<" ("<<m_parution<<")"<<endl;//Affiche le titre et l'année de parution de l'album



    for (int i=0; i<chansons.size();i++)//Permet de réaliser la boucle temps qu'il y a des chansons
    {
        cout<<"    "<<i+1 <<". "<<chansons[i].getTitre()<<endl;//On affiche le titre retourné par la fonction geTitre au rang i du vecteur

    }

    if(surcharge == 1)
    {
        for (int j=0; j<10;j++)
        {
        cout<<"    "<<j+1 <<". "<<m_listechansons[j]<<endl;//On affiche le titre retourné par la fonction geTitre au rang i du vecteur
        }
    }

}

void Groupe::afficher()
{
    cout<<"Groupe"<<endl<<"=========="<<endl<<endl;
    if(m_fin == 0)
    {
        cout<<m_nom<<"("<<m_creation<<" - aujourd'hui)"<<endl;
    }
    else
    {
        cout<<m_nom<<"("<<m_creation<<" - "<<m_fin<<")"<<endl;
    }

    for (int i=0; i<albums.size();i++)
    {
        cout<<"    "<<i+1 <<". "<<albums[i]<<endl;//On affiche le titre retourné par la fonction geTitre au rang i du vecteur

    }


}


int main()
{
Instrument *guitare = new Instrument("guitare", "cordes");//Création de l'objet guitare de la classe Instrument à qui on donne les paramètres guitare et cordes
Instrument *basse = new Instrument("basse", "cordes");
Instrument *batterie = new Instrument("batterie", "percussion");
Instrument *synth = new Instrument("synthetiseur", "electronique");
guitare->afficher();  //Affiche l'instrument choisi


Membre *ing = new Membre("Martin Hannet", "ingenieur du son", 1948,1991);//Création de l'objet ing de la classe Membre a qui on donne les paramètres nom role naissance et deces
ing->afficher();//Demande à la fonction afficher d'afficher les caractéristiques de l'objet ing faisant parti de la classe membre


Musicien *mus1 = new Musicien("Ian Curtis", 1956, 1980);//Création de l'objet mus1 de la classe Musicien à qui on donne les paramètres nom, naissance et deces
mus1->setChanteur();
mus1->setInstrument(guitare);
Musicien *mus2 = new Musicien("Peter Hook", 1956);
mus2->setInstrument(basse);
Musicien *mus3 = new Musicien("Bernard Summer", 1956);
mus3->setInstrument(guitare);
Musicien *mus4 = new Musicien("Stephen Morris", 1957);
mus4->setInstrument(basse);
mus1->afficher();
mus2->afficher();
mus3->afficher();
mus4->afficher();


Album *tr = new Album("Transmission", 1979);//Création de l'objet tr de la classe Album à qui on donne les paramètres titre et année parution
tr->addChanson("Transmission");
tr->addChanson("Novelty");
tr->afficher();


string listechansons[] = { "Disorder" , "Day of the Lords",
"Candidate", "Insight", "New Dawn Fades",
"She's Lost Control", "Shadowplay", "Wilderness",
"Interzone", "I Remember Nothing", "" };

Album *up = new Album("Unknown Pleasure", 1979, listechansons);
up->afficher();

Groupe *jd = new Groupe("Joy Division", 1976, 1980);
jd->addAlbum(up);
jd->addMembre(ing);
jd->addMembre(mus1);
jd->addMembre(mus2);
jd->addMembre(mus3);
jd->addMembre(mus4);
jd->afficher();

    return 0;
}
