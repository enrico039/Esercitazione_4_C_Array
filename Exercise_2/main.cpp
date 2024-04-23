#include <iostream>
#include <fstream>
#include "Utils.hpp"
#include <string>

using namespace std;

int main()
{
    const string filein = "data.csv";

    double S;
    int n;
    double* w;
    double* r;

    readDataFromFile(filein, S, n, w, r); //chiama la funzione che legge i dati dal file

    double RoR = computeRateOfReturn(w, r, n); //calcola il tasso di interesse

    double V = computeValue(w, r, n, S); //calcola il valore finale

    const string fileout = "result.txt"; //definisce il nome del file in uscita

    printResults(w, r, n, S, RoR, V, fileout); //stampa su file e compiler

    //cancello w ed r che ho creato con new in readDataFromFile
    delete[] w;
    delete[] r;

    return 0;
}
