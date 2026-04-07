#ifndef RESERVA_HPP
#define RESERVA_HPP
#include "Passatger.hpp"
#include <string>
#include <iostream>
using namespace std;

class Reserva {
// Tipus de mòdul: dades
// Descripció del tipus: Representa una reserva d'un vol de la que
// s'indiquen el seu número, el passatger que ha fet la reserva
// el número de vol que ha reservat i el mètode de pagament que ha
// fer servir en reservar.
	
    private:
 		
		// IMPLEMENTACIÓ DE LA CLASSE RESERVA
		// (definició del tipus i nom de cada atribut)
		string numReserva;
		string nomPassatger;
		string numVol;
		string pagament;
		
		Passatger passatger;
		
    public:
	
		//*********************************************************
		// Constructors
		//*********************************************************

		/* Pre: cert */
		/* Post: Construeix una reserva sense número de reserva, 
		passatger, número de vol ni mètode de pagament */
		Reserva();
		
		//*********************************************************
		// Destructor
		//*********************************************************
		
		/* Esborra automaticament l'objecte en sortir d'un àmbit de visibilitat local */
		~Reserva();
		
		//*********************************************************
		// Consultors
		//*********************************************************

		/* Pre: cert */
		/* Post: Retorna l'objecte reserva */
        Reserva getReserva() const;

		/* Pre: cert */
		/* Post: El resultat és el número de reserva paràmetre implícit */
		string getNumReserva() const;

		/* Pre: cert */
		/* Post: El resultat és el número del vol paràmetre implícit */
		string getNumVol() const;

		/* Pre: cert */
		/* Post: El resultat és el nom de passatger paràmetre implícit */
		string getNomPassatger() const;
		
		/* Pre: cert */
		/* Post: El resultat és l' objete Passatger paràmetre implícit */
		Passatger getPassatger() const;
		
		//*********************************************************
		// Lectura i escriptura
		//*********************************************************
	
		/* Pre: cert */
		/* Post: S'han escrit al canal estàndard de sortida els atributs del passatger p */
		friend ostream& operator<<(ostream &os, const Reserva &r);
		
		/* Pre: cert */
		/* Post: El passatger p passa a tenir els atributs llegits del canal estàndard d'entrada */		
		friend istream& operator>>(istream &is, Reserva &r);
};
#endif
