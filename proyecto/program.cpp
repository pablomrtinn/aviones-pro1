#include "Passatger.hpp"
#include "Vol.hpp"
#include "Reserva.hpp"
#include "Aerolinia.hpp"
#include <iostream>
#include <string>
using namespace std;

int main() {
	// llegir_dades_aerolínia (nombre màxim vols, nombre màxim reserves)
	int maxVols, maxReserves;
	cin >> maxVols >> maxReserves;
	// crear_aerolínia
	Aerolinia aero(maxVols, maxReserves);
	// llegir_opció
	string opcio;
	// while (opció != acabar) {
    //		tractar_opció
	//
	//  	llegir_opció
	// }
	cin >> opcio;
	while(opcio != "acabar"){
		//Inv: Tracta la opció sempre i quan no sigui "acabar"
		if(opcio == "enregistrarVol"){
			aero.enregistrarVol(maxVols);	
		}
		else if(opcio == "enregistrarReserva"){
			aero.enregistrarReserva(maxReserves);
		}
		else if(opcio == "mostrarVols"){
			aero.mostrarVols(aero.getVectorVols());
		}
		else if(opcio == "mostrarReserves"){
			aero.mostrarReserves(aero.getVectorReserves());
		}
		else if(opcio == "mostrarPassatgersVol"){
			string numVol;
			cin >> numVol;
			aero.mostrarPassatgersVol(numVol, aero.getVectorVols());
		}
		else if(opcio == "mostrarReservesEstat"){
			string estatReserves;
			cin >> estatReserves;
			aero.mostrarReservesEstat(estatReserves, aero.getVectorReserves());
		}
		else{
			cout << '"' << opcio << '"' << endl;
			cout << " Error: Opció no vàlida" << endl;
			cout << endl;
		}
		cin >> opcio;
	}
}
