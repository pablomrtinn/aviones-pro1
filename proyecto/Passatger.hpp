#ifndef PASSATGER_HPP
#define PASSATGER_HPP
#include <string>
#include <iostream>
using namespace std;

class Passatger {
// Tipus de mòdul: dades
// Descripció del tipus: Representa un passatger que ha fet la reserva
// d'un vol, del que s'indiquen el seu nom, l'estat de la reserva i el
// número de seient assignat.
	
    private:
		// IMPLEMENTACIÓ DE LA CLASSE PASSATGER 
		// (definició del tipus i nom de cada atribut)
		string nomPassatger; 
		string estatReserva;
		string numSeient;
		
    public:

		// ESPECIFICACIÓ DE LA CLASSE PASSATGER
		// (especificació Pre/Post de tots els mètodes)
		
		//*********************************************************
		// Constructors
		//*********************************************************

		/* Crea un passatger buit */
		Passatger();

		//*********************************************************
		// Destructor
		//*********************************************************

		/* Esborra automaticament l'objecte en sortir d'un àmbit de visibilitat local */
		~Passatger();
				 
		//*********************************************************
		// Consultors
		//*********************************************************

		/* Pre: cert */
		/* Post: El resultat és l' objete Passatger implícit */
        Passatger getPassatger() const;

		/* Pre: cert */
		/* Post: El resultat és el nom del Passatger paràmetre implícit */
		string getNomPassatger() const;

		/* Pre: cert */
		/* Post: El resultat és l' estat de reserva del Passatger paràmetre implícit */
		string getEstatReserva() const;

		/* Pre: cert */
		/* Post: El resultat és el numero de seient del Passatger paràmetre implícit */
		string getNumSeient() const;
		
		//*********************************************************
		// Lectura i escriptura
		//*********************************************************
	
		/* Pre: cert */
		/* Post: S'han escrit al canal estàndard de sortida els atributs del passatger p */
		friend ostream& operator<<(ostream &os, const Passatger &p);
		
		/* Pre: cert */
		/* Post: El passatger p passa a tenir els atributs llegits del canal estàndard d'entrada */		
		friend istream& operator>>(istream &is, Passatger &p);
};
#endif