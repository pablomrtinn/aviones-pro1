#ifndef AEROLINIA_HPP
#define AEROLINIA_HPP
#include "Vol.hpp"
#include "Passatger.hpp"
#include "Reserva.hpp"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Aerolinia {
// Tipus de modul: dades
// Descripcio del tipus: Una aerolínia té un nom que la identifica i està 
// formada per un conjunt de vols i un conjunt de reserves. El nombre de vols i
// el de reserves estan limitats. Ofereix les operacions necessàries per a un
// sistema de gestió de reserves de vols.

	private:
		// IMPLEMENTACIÓ DE LA CLASSE AEROLINIA 
		// (definició del tipus i nom de cada atribut)
		// (poden definir-se mètodes privats que actuïn com a funcions auxiliars)
		string nomAerolinia = "Voling";
		int maxVols;
		int maxReserves;
		
		vector<Vol> v;
		vector<Reserva> res;
	
	public:
	
	   //*********************************************************
	   // Constructors
	   //*********************************************************
   
	   /* Pre: cert */
	   /* Post: Construeix una aerolinia amb el nombre màxim de vols i 
	   el nombre màxim de reserves rebuts per paràmetre */ 
	   Aerolinia(int mv, int mr);

	   //*********************************************************
	   // Destructor
	   //*********************************************************
	   
	   /* Esborra automaticament l'objecte en sortir d'un ambit de visibilitat local */
	   ~Aerolinia();
	 
   	   //*********************************************************
	   // Modificadors
	   //*********************************************************
	   
	   /* Pre: cert */
	   /* Post: Enregistra un vol a l'aerolínia Voling */
	   void enregistrarVol(int &maxVols);

	   /* Pre: cert */
       /* Post: Enregistra una reserva a l'aerolínia Voling*/
	   void enregistrarReserva(int &maxReserves);
	   
	   //*********************************************************
	   // Consultors
	   //*********************************************************
	   
	   	/* Pre: cert */
		/* Post: El resultat és el nom de l' aerolínia en paràmetre implícit */
        Aerolinia getAerolinia() const;

		/* Pre: cert */
		/* Post: El resultat és el vector de vols paràmetre implícit */
        vector<Vol> getVectorVols() const;

		/* Pre: cert */
		/* Post: El resultat és el vector de reserves paràmetre implícit */
        vector<Reserva> getVectorReserves() const;

	   //*********************************************************
	   //Lectura i escriptura
	   //********************************************************
	   
	   /* Pre: cert */
	   /* Post: S'han escrit al canal estàndard de sortida les dades dels vols de
	   l'aerolínia paràmetre implícit, en l'ordre en què han estat enregistrats. 
	   En el cas que no hi hagués cap vol enregistrat en l'aerolínia p.i., s'ha
	   mostrat un missatge d'error. */
	   void mostrarVols(vector<Vol> v) const;
	   
	   /* Pre: cert */
	   /* Post: S'han escrit al canal estàndard de sortida les dades de les reserves
	   del paràmetre implícit, ordenades per número de reserva de forma creixent. 
	   En el cas que no hi hagués cap reserva enregistrada en l'aerolínia p.i., s'ha
	   mostrat un missatge d'error. */
	   void mostrarReserves(vector<Reserva> r);
	   
	   /* Pre: cert */
	   /* Post: S'han escrit al canal estàndard de sortida les dades dels passatgers
	   que tenen una reserva de vol, enregistrada  en l'aerolínia paràmetre implícit,
	   amb el número de vol donat per paràmetre. L'ordre dels passatgers és alfabètic.
	   En el cas que no hi hagués cap vol enregistrat en l'aerolínia p.i. amb el número
	   de vol donat o que no hi hagués cap reserva feta per aquest número de vol, s'ha 
	   mostrat un missatge d'error segons el cas */
	   void mostrarPassatgersVol(string numVol, vector<Vol>v) const;
	   
	   /* Pre: cert */
	   /* Post: S'han escrit al canal estàndard de sortida les dades de les reserves
	   enregistrades en l'aerolínia p.i. que es troben en l'estat rebut per paràmetre. 
	   Les reserves s'han escrit ordenades per número de reserva de forma creixent. 
	   En el cas que no hi hagués cap reserva enregistrada en l'aerolínia p.i. o que no
	   hi hagués cap reserva que es trobés en l'estat rebut per paràmetre, s'ha mostrat
	   un missatge d'error segons el cas */
	   void mostrarReservesEstat(string estatReserva, vector<Reserva>res) const;

};
#endif
