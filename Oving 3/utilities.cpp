#include "std_lib_facilities.h"
#include "utilities.h"

//generer tilfeldig tall med grenser
int randomWithLimits(int nedreGrense, int ovreGrense) {
	while (true) {
		int tilfeldig_tall = rand();
		if ((tilfeldig_tall > nedreGrense) and (tilfeldig_tall < ovreGrense)) {
			return tilfeldig_tall;
		}
	}
}




