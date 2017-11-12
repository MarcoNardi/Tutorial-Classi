#include <iostream>
#include <string>

using namespace std;

class persona {
//accessibile solo dentro la classe stessa
private://access specifiers controllori di visibilità ENCAPSULATION/DATA HIDING
	int a;
//accessibile sia dentro che fuori la classe
public:
	//getters e setters
	//getters restituiscono la variabile
	string getNome() { return nome; }
	string getCognome() {return cognome;}
	int getOre() { return ore; }
	//setters modifica la varibile
	void setNome(string n) { nome = n; }
	void setCognome(string c) { cognome = c; }
	void setOre(int h) { ore = h; }

	//Costruttore 
	//viene chiamato solo quando viene creata la variabile
	//viene fornito un costruttore denominato "di default"
	persona() { nome = ""; cognome = ""; ore = 0; }
	persona(string n, string c, int h) { nome = n; cognome = c; ore = h; }
	//distruttore
	//viene chiamato quando la variabile viene distrutta, cioè quando esce di scope
	//anche qua c'è quello di default
	~persona() { cout << "questo è il distruttore"; }
	//Costruttore di copia 
	//ne esiste uno di default
	persona(persona& p) {
		nome = p.getNome();
		cognome = p.getCognome();
		ore = p.getOre();
	}
	void mandaAVideo();
	void controllaSePromosso();
	
//accessibile sia dentro la classe stessa che nelle classi figlie
protected:
	string nome;
	string cognome;
	int ore;
};

class studente:public persona{
private:
	string hobby;
	int eta;
public:
	//costruttori
	studente():persona() {
		hobby = ""; eta = 10; 
	}
	//lista di inizializzazione
	studente(string n, string c, int h, string ho, int e) :persona(n, c, h), hobby(ho), eta(e) { }
	void mandaAVideo();

};



/*
struct persona {
	string nome;
	string cognome;
	int ore;
};

*/

//overloading
int somma(int n1, int n2) {
	return n1 + n2;
}

float somma(float f1, float f2) {
	return f1 + f2;
}

int somma(int n1, int n2, int n3) {
	return n1 + n2 + n3;
}

int main() {

	float b = 7;
	float a(b);
	cout << "la somma e' " << somma(5,7,10) << endl;



	studente s1("luca", "rossi", 15, "giocare con le macchinette", 5);


	persona p1("gianni", "uibabusbvn", 45);
	persona p2();
	p1.setNome("sacaca");

	
	
	
	
	/*
	persona p;
	cout << "dammi cognome e nome della persona participante" << endl;
	cin >> p.nome >> p.cognome;
	cout << "dammi il numero di ore di partecipazione" << endl;
	cin >> p.ore;
	if (p.ore >= 8) {
		cout << p.nome << " e' promosso" << endl;
	}
	else {
		cout << p.nome << " e' bocciato" << endl;
	}
			*/

	return 0;
}



void persona::mandaAVideo() {
	cout << "il nome  e" << nome << endl;
	cout << "il cognome  e" << cognome << endl;
	cout << "le ore sono " << ore << endl;
	cout << " a e' " << a << endl;
}



//overriding=sovrascrivere
void studente::mandaAVideo() {
	persona::mandaAVideo();
	cout << "l'hobby e' " << hobby << endl;
	cout << "l'eta e' " << eta;
}
