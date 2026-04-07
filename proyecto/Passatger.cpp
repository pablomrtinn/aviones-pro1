#include "Passatger.hpp"
using namespace std;

// IMPLEMENTACIÓ DE LA CLASSE PASSATGER
// (implementació del codi de tots els mètodes especificats en el fitxer Passatger.hpp)

        //*********************************************************
		// Constructors
		//*********************************************************


		/* Crea un passatger buit */
		Passatger::Passatger(){
        }

		//*********************************************************
		// Destructor
		//*********************************************************

		/* Esborra automaticament l'objecte en sortir d'un àmbit de visibilitat local */
		Passatger::~Passatger(){
        }
				 
		//*********************************************************
		// Consultors
		//*********************************************************
		
		
		/* Pre: cert */
		/* Post: El resultat és l' objete Passatger implícit */
        Passatger Passatger::getPassatger() const{
			return *this;
		}

		/* Pre: cert */
		/* Post: El resultat és el nom del Passatger paràmetre implícit */
		string Passatger::getNomPassatger() const{
			return nomPassatger;
		}

		/* Pre: cert */
		/* Post: El resultat és l' estat de reserva del Passatger paràmetre implícit */
		string Passatger::getEstatReserva() const{
			return estatReserva;
		}

		/* Pre: cert */
		/* Post: El resultat és el numero de seient del Passatger paràmetre implícit */
		string Passatger::getNumSeient() const{
			return numSeient;
		}

	
		
		//*********************************************************
		// Lectura i escriptura
		//*********************************************************
	
		/* Pre: cert */
		/* Post: S'han escrit al canal estàndard de sortida els atributs del passatger p */
		ostream& operator<<(ostream &os, const Passatger &p){
            os << " Nom passatger: " << p.nomPassatger <<endl;
            os << " Estat reserva: " << p.estatReserva << endl;
            os << " Número seient: " << p.numSeient << endl;
            return os;
        }
		
		/* Pre: cert */
		/* Post: El passatger p passa a tenir els atributs llegits del canal estàndard d'entrada */		
		istream& operator>>(istream &is, Passatger &p){
            is >> p.nomPassatger >> p.estatReserva >> p.numSeient;
            return is;
        }
