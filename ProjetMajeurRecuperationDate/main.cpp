#pragma warning(disable:4996)

#include <stdio.h>
#include <ctime> // used to work with date and time



//using namespace std;

int main() {
	time_t t; // t passed as argument in function time()
	struct tm* tt; // decalring variable for localtime()
	time(&t); //passing argument to time()
	tt = localtime(&t);

	int heure = tt->tm_hour;
	printf("\nheure %i\n", heure);

	int annee = tt->tm_year + 1900;
	printf("\nAnnee %i\n", annee);

	return 0;
}
