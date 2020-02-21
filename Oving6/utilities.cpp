#include "std_lib_facilities.h"
#include "utilities.h"


void LesFraBrukerOgSkrivTilFil(string Filnavn) {
	ofstream ost{ Filnavn }; //åpne fil for skriving
	if (!ost) error("Kan ikke åpne filen", Filnavn);

	string ord; 
	while (true) {
		cout << "Skriv inn et ord, \"quit\" avslutter: ";
		cin >> ord;
		if (ord != "quit") {
			ost << ord << endl;
			cout << endl;
		}
		else {
			break;
		}
		
	}
	ost.close(); //lukker fil
}

void LesFraFilOgSkrivTilFilMedLinjenummer(string LesFraFilnavn, string SkrivTilFilnavn) {
	ifstream ist{ LesFraFilnavn }; //åpne fil for lesing
	if (!ist) error("Kan ikke åpne filen", LesFraFilnavn);
	ofstream ost{ SkrivTilFilnavn }; //åpne fil for skriving
	if (!ost) error("Kan ikke åpne filen", SkrivTilFilnavn);

	int i = 0; //telle variabel
	string line;
	string s;
	while (ist>>s) {
		if (!ist.bad() || ist.good()) {
			getline(ist, line);
			line = to_string(i)  + s + line;
			ost << line << endl;
			i += 1;
		}
		else {
			break;
		}
	}
	
	ist.close(); //lukker filer
	ost.close();
}

void LagTekst100charPerBokstav() {
	ofstream ost{ "test4.txt" }; //åpne fil for skriving
	if (!ost) error("Kan ikke åpne filen", "test4");

	char c = 'a';
	for (int x = 0; x < 26; ++x) {
		for (int i = 0; i < 20; ++i) {
			for (int j = 0; j < 5; ++j) {
				ost << c;
			}
			ost << endl;
		}
		c += 1;

	}
	ost.close();
}

void TegnstatisikkIEnFil(string Filnavn) {
	
	vector<int> characterCount(26,0);

	ifstream ist{ Filnavn }; //åpne fil for lesing
	if (!ist) error("Kan ikke åpne filen", Filnavn);

	for (string s; ist >> s; ) {
		for (char c : s) {
			c = tolower(c);
			if (c >= 'a' && c <= 'z') {
				int indeks = static_cast<int>(c - 'a');
				characterCount.at(indeks) += 1;
			}
			else {
				break;
			}
		}
	}

	char k = 'a';
	int i = 0; //telle variabl
	for (int x : characterCount) {
		cout << k << ':' << setw(5) << x << setw(2) << ' ';
		k += 1;
		if (i == 2) {
			cout << endl;
			i = -1;
		}
		i += 1;
	}
	ist.close();
	cout << endl << endl;
}

ostream& operator<<(ostream& ost, const CourseCatalog& Fag) {
	string print ="";
	string s;
	for (const pair<string, string> & p : Fag.emne) {// without auto
		s = p.first + ":" + p.second + "\n";
		print += s;
	}
	return ost << print;
}

void CourseCatalog::addCourseold(string emnekode, string emnenavn) {
	emne[emnekode, emnenavn]; //brukes ikke
}

void CourseCatalog::removeCourse(string emnekode) {
	emne.erase(emnekode);
}

string CourseCatalog::getCourse(string emnekode) {
	return emne.at(emnekode);
}

void CourseCatalog::addCourse(string emnekode, string emnenavn) {
	removeCourse(emnekode);
	pair<string, string> nyttemne = { emnekode, emnenavn };
	emne.insert(nyttemne);
}

void CourseCatalog::getCourseCatalogFromFile(string Filnavn) {
	ifstream ist{ Filnavn }; //åpne fil for lesing
	if (!ist) error("Kan ikke åpne filen", Filnavn);

	string line;
	string s;
	int pos;
	int maxpos;
	while (ist >> s) {
		string emnekode = "";
		string emnenavn = "";
		if (!ist.bad() || ist.good()) {
			getline(ist, line);
			line = s + line;
			pos = line.find(':');
			maxpos = line.size();
			for (int i = 0; i < pos; ++i) {
				emnekode += line.at(i);
			}
			for (int i = pos+1; i < maxpos; ++i) {
				emnenavn += line.at(i);
			}
			addCourse(emnekode, emnenavn);
		}
		else {
			break;
		}
	}

	ist.close(); //lukker filer
}

void CourseCatalog::saveCourseCatalogToFile(string Filnavn) {
	ofstream ost{ Filnavn }; //åpne fil for skriving
	if (!ost) error("Kan ikke åpne filen", Filnavn);

	string s;
	for (const pair<string, string> & p : emne) {// without auto
		s = p.first + ":" + p.second;
		ost << s;
	}
	ost.close();
}

istream& operator>>(istream& is, Temps& t) {
	double min;
	double max;
	is >> min >> max;
	t.min = min;
	t.max = max;
	return is;
}

void LesTempsFraFil(string Filnavn, bool print) {
	ifstream temp_file{ Filnavn }; 
	if (!temp_file) error("Kan ikke åpne filen", Filnavn);

	Temps t; 
	vector<Temps> TempsVector;

	while (temp_file >> t) {
		TempsVector.push_back(t);
	}
	temp_file.close();

	if (print) {
		for (Temps t2 : TempsVector) {
			cout << "t.max = " << t2.max << ", t.min = " << t2.min << endl;
		}
	}
}



