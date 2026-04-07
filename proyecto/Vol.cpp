#include "Vol.hpp"
using namespace std;

// IMPLEMENTACIÓ DE LA CLASSE VOL
// (implementació del codi de tots els mètodes especificats en el fitxer Vol.hpp)

    //*********************************************************
    // Constructors
    //*********************************************************
    
    //Es crea un vol buit
    Vol::Vol(){
    }

    //*********************************************************
    // Destructors
    //*********************************************************

    /* Esborra automaticament l'objecte en sortir d'un àmbit de visibilitat local */
    Vol::~Vol(){
    }

    //*********************************************************
	// Modificadors
	//*********************************************************

    //Pre: Cert
	//Post: Elimina 1 seient al vol asignat quan es crea una reserva
    void Vol::eliminarSeient(){
        --seientsDisp;
    }

    //Pre: Cert
	//Post: Afegeix al vector r la reserva creada
    void Vol::afegirReserva(Reserva reserva){
        r.push_back(reserva);
    }

    //*********************************************************
    // Consultors
    //*********************************************************

    //* Pre: cert */
	/* Post: El resultat és l'objecte vol paràmetre implícit */
    Vol Vol::getVol() const{
       return *this;
    }

    /* Pre: cert */
	/* Post: El resultat és el número del vol paràmetre implícit */
    string Vol::getNumVol() const{
       return vol;
    }
    
    /* Pre: cert */
	/* Post: El resultat és el número de seients paràmetre implícit */
    int Vol::getNumSeients() const{
        return seientsDisp;
    }

    /* Pre: cert */
	/* Post: El resultat és l'estat del vol paràmetre implícit */
    string Vol::getEstatVol() const{
        return estatVol;
    }

    /* Pre: cert */
	/* Post: El resultat és el vector de reserves paràmetre implícit */
    vector<Reserva> Vol::getVectorReserves() const{
        return r;
    }


	//*********************************************************
	// Lectura i escriptura
	//*********************************************************
		
	/* Pre: cert */
	/* Post: S'han escrit al canal estàndard de sortida els atributs del vol v */
	ostream& operator<<(ostream &os, const Vol &v){
        os << " Número vol: " << v.vol <<endl;
        os << " Ciutat origen: " << v.origen << endl;
        os << " Ciutat destinació: " << v.desti << endl;
        os << " Hora sortida: " << v.horaSortida << endl;
        os << " Hora arribada: " << v.horaArribada << endl;
        os << " Estat vol: " << v.estatVol << endl;
        os << " Seients disponibles: " << v.seientsDisp << endl;
        return os;
    }
		
	/* Pre: cert */
	/* Post: El vol v passa a tenir els atributs llegits del canal estàndard d'entrada */		
    istream& operator>>(istream &is, Vol &v){
        is >> v.vol >> v.origen >> v.desti >> v.horaSortida >> v.horaArribada >> v.estatVol >> v.seientsDisp;
        return is;
    }
