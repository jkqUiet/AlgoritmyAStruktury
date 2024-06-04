#include "MyForm.h"
#include "Manager.h"
#include "structures/table/sorted_sequence_table.h"
#include "JednotkaUzemna.h"
#include "UJTyp.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

// array<String^>^ args
int main() {
	initHeapMonitor();

	structures::SortedSequenceTable<string, JednotkaUzemna*>* obce = new structures::SortedSequenceTable<string, JednotkaUzemna*>();
	structures::SortedSequenceTable<string, JednotkaUzemna*>* okresy = new structures::SortedSequenceTable<string, JednotkaUzemna*>();
	structures::SortedSequenceTable<string, JednotkaUzemna*>* kraje = new structures::SortedSequenceTable<string, JednotkaUzemna*>();
	structures::SortedSequenceTable<string, JednotkaUzemna*>* slovensko = new structures::SortedSequenceTable<string, JednotkaUzemna*>();

	JednotkaUzemna* svk = new JednotkaUzemna("Slovensko", nullptr, UJTyp::Slovensko, 0, 0, 0, 0, 0);
	slovensko->insert("Slovensko", svk);

	Nacitavac* n = new Nacitavac(*obce, *okresy, *kraje, *slovensko);
	n->nacitaj("CSV/2uzemneclenenie.csv", "CSV/1_obce_SR.csv");

	Manager* man = new Manager(*kraje, *okresy, *obce, *slovensko);

	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	AUSsemestralka2::MyForm frm(man);
	Application::Run(% frm);

	delete man;
	man = nullptr;

	delete n;
	n = nullptr;

	for (auto a : *obce) {
		delete a->accessData();
	}
	delete obce;
	for (auto a : *okresy) {
		delete a->accessData();
	}
	delete okresy;
	for (auto a : *kraje) {
		delete a->accessData();
	}
	delete kraje;
	for (auto a : *slovensko) {
		delete a->accessData();
	}
	delete slovensko;

	return 0;
}