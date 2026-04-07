#include "Aerolinia.hpp"
using namespace std;

//*********************************************************
// Constructors
//*********************************************************
   
/* Pre: cert */
/* Post: Construeix una aerolinia amb el nom, el nombre màxim de vols i 
el nombre màxim de reserves rebuts per paràmetre */ 
Aerolinia::Aerolinia(int mv, int mr){
    maxVols = mv;
    maxReserves = mr;
}


//*********************************************************
// Destructor
//*********************************************************
	   
/* Esborra automaticament l'objecte en sortir d'un ambit de visibilitat local */
Aerolinia::~Aerolinia(){
}
	 
//*********************************************************
// Modificadors
//*********************************************************

/* Pre: cert */
/* Post: Enregistra un vol a l'aerolínia Voling */  
void Aerolinia::enregistrarVol(int &mVols){
    Vol vol;
    cin >> vol;
    cout << "Enregistrament vol: " << vol.getNumVol() << endl;
    bool afegir = true;
    int i = 0;
    unsigned int mida = v.size();
    while (i < mida and afegir) {    
        //Comprova si en el vector v existeix un vol igual al que es vol afegir
        if (vol.getNumVol() == v[i].getNumVol()) afegir = false;
        else ++i;
    }
    
    if(afegir) {
    	if(mVols <= 0) cout << " Error: el vol supera el nombre màxim de vols a Voling, no s'ha afegit el vol" << endl;
        else{
        	v.push_back(vol);
       	 	cout << " OK" << endl;
        	--mVols;
        }
    }
    else cout << " Error: " << vol.getNumVol() << " vol ja existent a Voling, no s'ha afegit el vol" << endl;
    cout << endl;
}

/* Pre: cert */
/* Post: Enregistra una reserva a l'aerolínia Voling*/
void Aerolinia::enregistrarReserva(int &mRes){
    Reserva reserva;
    cin >> reserva;
    bool volTrobat = false;
    int i = 0;
    unsigned int mida = v.size();  
    while (i < mida and not volTrobat){
        //Comprova si en el vector v existeix el vol asociat a la reserva    
        if (v[i].getNumVol() == reserva.getNumVol()) volTrobat = true;
        else ++i;
    }
   
    cout << "Enregistrament reserva: " << reserva.getNumReserva() << endl;
    
    if(volTrobat) {
        bool cond1 = true;
        if (v[i].getNumSeients() <= 0){
        	 cout << " Error: vol " << reserva.getNumVol() << " no disposa de seients disponibles, no s'ha afegit la reserva" << endl;
        	 cond1 = false;
        }         
        
        int i1 = 0;
        unsigned int mida1 = res.size();
        bool cond2 = true;
        while (i1 < mida1 and cond2) { 
            //Comprova si la reserva existeix  
            if(reserva.getNumReserva() == res[i1].getNumReserva()){
            	cond2 = false;
             	cout << " Error: " << reserva.getNumReserva() <<  " reserva ja existent a Voling, no s'ha afegit la reserva" << endl;
            } 
            else ++i1;
        }
        
        if(cond2 and cond1){
            if(mRes <= 0) cout << " Error: la reserva supera el nombre màxim de reserves a Voling, no s'ha afegit la reserva" << endl;
            else{
            	v[i].afegirReserva(reserva);
            	res.push_back(reserva);
            	cout << " OK" << endl;
            	--mRes;
            	v[i].eliminarSeient();
            }
        }
    }
    else cout << " Error: vol " << reserva.getNumVol() << " no existent a Voling, no s'ha afegit la reserva" << endl;
    cout << endl;
}


//*********************************************************
// Consultors
//*********************************************************
	   
/* Pre: cert */
/* Post: El resultat és el número del vol paràmetre implícit */
Aerolinia Aerolinia::getAerolinia() const{
    return *this;
}


/* Pre: cert */
/* Post: El resultat és el vector de vols paràmetre implícit */
vector<Vol> Aerolinia::getVectorVols() const{
    return v;
}

/* Pre: cert */
/* Post: El resultat és el vector de reserves paràmetre implícit */
vector<Reserva> Aerolinia::getVectorReserves() const{
    return res;
}

	   
//*********************************************************
//Lectura i escriptura
//********************************************************
	   
/* Pre: cert */
/* Post: S'han escrit al canal estàndard de sortida les dades dels vols de
l'aerolínia paràmetre implícit, en l'ordre en què han estat enregistrats. 
En el cas que no hi hagués cap vol enregistrat en l'aerolínia p.i., s'ha
mostrat un missatge d'error. */
void Aerolinia::mostrarVols(vector<Vol> v) const{
    cout << "Vols de Voling (per ordre d'enregistrament):" << endl;
    if(v.size() == 0) cout << " Error: No hi ha vols enregistrats a Voling" << endl;
    else {
        int vols = 1;
        for(int i = 0; i < v.size(); ++i){
            //Escriu per pantalla els atributs dels vols
            cout << ' ' << vols << '.' << endl;
            cout << v[i];
            ++vols;
        }
        
    }
    cout << endl;
}
	   
/* Pre: cert */
/* Post: S'han escrit al canal estàndard de sortida les dades de les reserves
del paràmetre implícit, ordenades per número de reserva de forma creixent. 
En el cas que no hi hagués cap reserva enregistrada en l'aerolínia p.i., s'ha
mostrat un missatge d'error. */
void Aerolinia::mostrarReserves(vector<Reserva> r) {
    cout << "Reserves de Voling (per número de reserva):" << endl;
    unsigned int mida = r.size();
    if (mida == 0) cout << " Error: No hi ha reserves enregistrades a Voling" << endl;
    else { 
        for(unsigned int i = 1; i < mida; ++i) {
            // Inv: v[0..i-1] està ordenat de manera creixent.
            Reserva x = r[i];
            int j = i;
            while (j > 0 and r[j-1].getNumReserva() > x.getReserva().getNumReserva()) {
                // Inv: v[0..j-1] i v[j+1..i] està ordenat de manera creixent.
                r[j] = r[j-1];
                --j;
            }
            r[j] = x;
        }
        
        int reserves = 1;
        for(int i = 0; i < mida; ++i){
            //Mostra per pantalla els atributs de les reserves de l' Aerolinia
            cout << ' ' << reserves << '.' <<endl;
            cout << r[i];
            ++reserves;
        }    
        
    }
    cout << endl;
}    
	   
/* Pre: cert */
/* Post: S'han escrit al canal estàndard de sortida les dades dels passatgers
que tenen una reserva de vol, enregistrada  en l'aerolínia paràmetre implícit,
amb el número de vol donat per paràmetre. L'ordre dels passatgers és alfabètic.
En el cas que no hi hagués cap vol enregistrat en l'aerolínia p.i. amb el número
de vol donat o que no hi hagués cap reserva feta per aquest número de vol, s'ha 
mostrat un missatge d'error segons el cas */
void Aerolinia::mostrarPassatgersVol(string numVol, vector<Vol>v) const {
    cout << "Passatgers del vol " << numVol << " de Voling (en ordre alfabètic):" << endl;
    bool exitVol = false;
    int i = 0;
    unsigned int mida = v.size();
    while (i < mida and not exitVol) {
        //Comprova si en el vector v existeix un vol igual a "num"   
        if (numVol == v[i].getNumVol()) exitVol = true;
        else ++i;
    }
    
    if(exitVol) {
        vector<Reserva> copia = v[i].getVectorReserves();
        unsigned int mida1 = copia.size();
        if(mida1 == 0) cout << " Error: No hi ha passatgers amb reserves pel vol " <<  v[i].getNumVol() << endl;
        else{
        	for(unsigned int i = 1; i < mida1; ++i) {
            	// Inv: v[0..i-1] està ordenat de manera creixent.
            	Reserva x = copia[i];
            	int j = i;
            	while (j > 0 and copia[j-1].getNomPassatger() > x.getNomPassatger()) {
                	// Inv: v[0..j-1] i v[j+1..i] està ordenat de manera creixent.
               	 	copia[j] = copia[j-1];
                	--j;
            	}
            copia[j] = x;
       	 	}	
    
        	int j = 0;
        	int passatger = 1;
        	while (j < mida1) {
                //Mostra per pantalla els atributs dels passatgers del vol "numVol"
            	cout << ' ' << passatger << '.' <<endl;
            	cout << copia[j].getPassatger();
            	++passatger;
            	++j;
        	} 
        }
        
    }
    else cout << " Error: " << numVol << " vol no existent a Voling" << endl;
    cout << endl;
}
	   
/* Pre: cert */
/* Post: S'han escrit al canal estàndard de sortida les dades de les reserves
enregistrades en l'aerolínia p.i. que es troben en l'estat rebut per paràmetre. 
Les reserves s'han escrit ordenades per número de reserva de forma creixent. 
En el cas que no hi hagués cap reserva enregistrada en l'aerolínia p.i. o que no
hi hagués cap reserva que es trobés en l'estat rebut per paràmetre, s'ha mostrat
un missatge d'error segons el cas */
void Aerolinia::mostrarReservesEstat(string estatReserva, vector<Reserva>res) const{
    cout << "Reserves de Voling amb estat " << '"' << estatReserva << '"' << " (per número de reserva):" << endl;
    unsigned int mida = res.size();
    if (mida == 0) cout << " Error: No hi ha reserves enregistrades a Voling" << endl;
    else { 
        for(unsigned int i = 1; i < mida; ++i){
            // Inv: v[0..i-1] està ordenat de manera creixent.
            Reserva x = res[i];
            int j = i;
            while (j > 0 and res[j-1].getNumReserva() > x.getNumReserva()) {
                // Inv: v[0..j-1] i v[j+1..i] està ordenat de manera creixent.
                res[j] = res[j-1];
                --j;
            }
            res[j] = x;
        }
        
        int reserves = 1;
        for(int i = 0; i < mida; ++i){
            //Mostra per pantalla els atributs de les reserves iguals a "estatReserves"
            string estat = res[i].getPassatger().getEstatReserva();
            if (estat == estatReserva){
                cout << ' ' << reserves << '.' <<endl;
                cout << res[i];
                ++reserves;
            }
        }    
    }
    cout << endl;
}



