#pragma once
#include <string>
#include "UJTyp.h"
#include "structures/table/sorted_sequence_table.h"


using namespace std;

class JednotkaUzemna
{
public:
	JednotkaUzemna(string nazov, JednotkaUzemna* jed, UJTyp t, double zast, double vym, int pre, int pro, int po);
	~JednotkaUzemna();

	string getNazov();


	UJTyp getTyp();

	JednotkaUzemna* getTenNadomnou();
	int getPocetObyvatelov();
	double getZastavanost();
	double getZastavne();
	double getVymera();
	int getPreProd();
	int getPoProd();
	int getProd();
	bool jeNizsiCelok();


	void setZastavane(double hodnota);
	void setVymera(double hodnota);
	void setPreProd(int pocet);
	void setPoProd(int pocet);
	void setProd(int pocet);

	void pridajPod(JednotkaUzemna* jed);
	structures::SortedSequenceTable<string, JednotkaUzemna*>* getPodomnou();
	
private:
	structures::SortedSequenceTable<string, JednotkaUzemna*>* patriacePodoMna;
	JednotkaUzemna* tenNadomnou;
	string nazov;
	UJTyp typ;
	double zastavane;
	double vymera;
	int preProduktivni;
	int produktivni;
	int poProduktivni;
	int key;
};

