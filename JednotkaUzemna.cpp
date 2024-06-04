#include "JednotkaUzemna.h"

using namespace std;
using namespace structures;

JednotkaUzemna::JednotkaUzemna(string naz, JednotkaUzemna* jed,UJTyp t, double zast,
    double vym, int pre, int pro, int po):
    nazov(naz), tenNadomnou(jed),typ(t), zastavane(zast), vymera(vym), preProduktivni(pre), produktivni(pro), poProduktivni(po)
{
    patriacePodoMna = new SortedSequenceTable<std::string, JednotkaUzemna*>();
}

JednotkaUzemna::~JednotkaUzemna()
{
    delete patriacePodoMna;
}

string JednotkaUzemna::getNazov()
{
    return nazov;
}

double JednotkaUzemna::getZastavne()
{
    return zastavane;
}

double JednotkaUzemna::getVymera()
{
    return vymera;
}

int JednotkaUzemna::getPreProd()
{
    return preProduktivni;
}

int JednotkaUzemna::getProd()
{
    return produktivni;
}

int JednotkaUzemna::getPoProd()
{
    return poProduktivni;
}

bool JednotkaUzemna::jeNizsiCelok()
{
    return tenNadomnou != nullptr;
}

void JednotkaUzemna::setZastavane(double hodnota)
{
    zastavane = hodnota;
}

void JednotkaUzemna::setVymera(double hodnota)
{
    vymera = hodnota;
}

void JednotkaUzemna::setPreProd(int pocet)
{
    preProduktivni = pocet;
}

void JednotkaUzemna::setPoProd(int pocet)
{
    poProduktivni = pocet;
}

void JednotkaUzemna::setProd(int pocet)
{
    produktivni = pocet;
}

void JednotkaUzemna::pridajPod(JednotkaUzemna* jed)
{
    patriacePodoMna->insert(jed->getNazov(),jed);
}

structures::SortedSequenceTable<string, JednotkaUzemna*>* JednotkaUzemna::getPodomnou()
{
    return patriacePodoMna;
}

UJTyp JednotkaUzemna::getTyp()
{
    return typ;
}

JednotkaUzemna* JednotkaUzemna::getTenNadomnou() {
    return tenNadomnou;
}

int JednotkaUzemna::getPocetObyvatelov()
{
    return produktivni + poProduktivni + preProduktivni;
}

double JednotkaUzemna::getZastavanost()
{
    return 100 * (zastavane / vymera);
}
