#include "Reserva.hpp"
using namespace std;

    //*********************************************************
	// Constructors
	//*********************************************************

	/* Pre: cert */
	/* Post: Construeix una reserva sense número de reserva, 
	passatger, número de vol ni mètode de pagament */
	Reserva::Reserva(){
	}

	//*********************************************************
	// Destructor
	//*********************************************************
		
	/* Esborra automaticament l'objecte en sortir d'un àmbit de visibilitat local */
	Reserva::~Reserva(){
    }
		
	//*********************************************************
	// Consultors
	//*********************************************************

	/* Pre: cert */
	/* Post: Retorna l'objecte reserva */
    Reserva Reserva::getReserva() const{
        return *this;
    }
	
	/* Pre: cert */
	/* Post: El resultat és el número de reserva paràmetre implícit */
	string Reserva::getNumReserva() const{
		return numReserva;
	}
	
	/* Pre: cert */
	/* Post: El resultat és el número del vol paràmetre implícit */
	string Reserva::getNumVol() const{
		return numVol;
	}

	/* Pre: cert */
	/* Post: El resultat és el nom de passatger paràmetre implícit */
	string Reserva::getNomPassatger() const{
		return nomPassatger;
	}

	/* Pre: cert */
	/* Post: El resultat és l' objete Passatger paràmetre implícit */
	Passatger Reserva::getPassatger() const{
		return passatger;
	}

	//*********************************************************
	// Lectura i escriptura
	//*********************************************************
	
	/* Pre: cert */
	/* Post: S'han escrit al canal estàndard de sortida els atributs del passatger p */
	ostream& operator<<(ostream &os, const Reserva &r){
        os << " Número reserva: " << r.numReserva << endl;
        os << " Nom passatger: " << r.nomPassatger << endl;
        os << " Número vol: " << r.numVol << endl;
        os << " Pagament: " << r.pagament << endl;
        return os;
    }
		
	/* Pre: cert */
	/* Post: El passatger p passa a tenir els atributs llegits del canal estàndard d'entrada */	
	istream& operator>>(istream &is, Reserva &r){
        is >> r.numReserva;
		cin >> r.passatger;
		r.nomPassatger = r.passatger.getNomPassatger();
		is >> r.numVol >> r.pagament;
        return is;
    }
