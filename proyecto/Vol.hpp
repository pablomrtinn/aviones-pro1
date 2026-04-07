#ifndef VOL_HPP
#define VOL_HPP
#include <vector>
#include <string>
#include <iostream>
#include "Reserva.hpp"
using namespace std;

class Vol {
// Tipus de mòdul: dades
// Descripció del tipus: Representa un vol del que s'indiquen 
// el seu número, ciutat origen, ciutat destinació, hora de
// sortida, hora d'arribada, estat del vol i nombre de seients
// disponibles.
	
    private:

		// IMPLEMENTACIÓ DE LA CLASSE VOL
		// (definició del tipus i nom de cada atribut)
		string vol;
		string origen;
		string desti;
		string horaSortida;
		string horaArribada;
		string estatVol;
		// Ha de valer entre 1 i el nombre màx de seients.
		int seientsDisp;
		
		vector<Reserva> r;
		
				
    public:
	
		// ESPECIFICACIÓ DE LA CLASSE VOL
		// (especificació Pre/Post de tots els mètodes)

		//*********************************************************
		// Constructors
		//*********************************************************

		//Es crea un vol buit
		Vol();
		
		//*********************************************************
		// Destructor
		//*********************************************************
		
		/* Esborra automaticament l'objecte en sortir d'un àmbit de visibilitat local */
		~Vol();
   
   		//*********************************************************
		// Modificadors
		//*********************************************************
		
		//Pre: Cert
		//Post: Elimina 1 seient al vol asignat quan es crea una reserva
		void eliminarSeient();

		//Pre: Cert
		//Post: Afegeix al vector r la reserva creada
		void afegirReserva(Reserva reserva);
		
		//*********************************************************
		// Consultors
		//*********************************************************

		/* Pre: cert */
		/* Post: El resultat és l'objecte vol paràmetre implícit */
        Vol getVol() const;

		/* Pre: cert */
		/* Post: El resultat és el número del vol paràmetre implícit */
		string getNumVol() const;
		
		/* Pre: cert */
		/* Post: El resultat és el número de seients paràmetre implícit */
	 	int getNumSeients() const;

		/* Pre: cert */
		/* Post: El resultat és l'estat del vol paràmetre implícit */
		string getEstatVol() const;

		/* Pre: cert */
		/* Post: El resultat és el vector de reserves paràmetre implícit */
		vector<Reserva> getVectorReserves() const;
		
		//*********************************************************
		// Lectura i escriptura
		//*********************************************************
		
		/* Pre: cert */
		/* Post: S'han escrit al canal estàndard de sortida els atributs del vol v */
		friend ostream& operator<<(ostream &os, const Vol &v);
		
		/* Pre: cert */
		/* Post: El vol v passa a tenir els atributs llegits del canal estàndard d'entrada */		
		friend istream& operator>>(istream &is, Vol &v);
};
#endif