#pragma once

void LesFraBrukerOgSkrivTilFil(string Filnavn);
void LesFraFilOgSkrivTilFilMedLinjenummer(string LesFraFilnavn, string SkrivTilFilnavn);
void TegnstatisikkIEnFil(string Filnavn);
void LagTekst100charPerBokstav();
void LesTempsFraFil(string Filnavn, bool print);

class CourseCatalog {
public:
	void addCourseold(string emnekode, string emnenavn);
	void removeCourse(string emnekode);
	string getCourse(string emnekode);
	void addCourse(string emnekode, string emnenavn);
	void getCourseCatalogFromFile(string Filnavn);
	void saveCourseCatalogToFile(string Filnavn);

private:
	map<string, string> emne { {"TDT4110", "Informasjonsteknologigrunnkurs"},{"TDT4102", "Prosedyre - og objektorientert programmering"},
			{"TMA4100", "Matematikk 1"} };
	friend ostream& operator<<(ostream& ost, const CourseCatalog& Fag);
};

typedef struct { double max, min; } Temps;

