#pragma once
#include <string>

using namespace std;

bool readDataFromFile(const string& file, double& S, int& n, double*& w, double*& r); //dichiara la funzione che legge i dati dal file
double computeRateOfReturn(const double* w, const double* r, const int n); //dichiara la funzione che calcola il tasso di interesse
double computeValue(const double* w, const double* r, const int n, const double S); //dichiara la funzione che calcola il valore finale del portfolio
void printResults(const double* w, const double* r, const int n, const double S, const double RoR, const double V, const string filename); //stampa i risultati su file e su compiler
