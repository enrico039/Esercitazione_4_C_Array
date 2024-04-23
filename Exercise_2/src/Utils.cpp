#include "Utils.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

bool readDataFromFile(const string& filename, double& S, int& n, double*& w, double*& r)
{
    ifstream file(filename); //apre il file
    if(file.fail())
    {
        cerr << "File not found" << endl;
        return 1;
    }

    string header;
    stringstream ss;  //stringstream è utile per convertire stringhe in altri tipi di dati
    string token;

    getline(file, token, ';'); //leggo il primo pezzo della prima riga
    getline(file, token); //leggo il valore di S
    ss << token; //inserisco il valore in ss
    ss >> S; // estraggo il numero da ss, inserendolo in S
    ss.clear(); //svuoto stringstream

    getline(file, token, ';'); //leggo il primo pezzo della seconda riga
    getline(file, token); //leggo il valore di n
    ss << token; //inserisco il valore riga in ss
    ss >> n; //estraggo il numero da ss, inserendolo in n
    ss.clear(); //svuoto ss

    getline(file, header); //leggo la terza riga e la metto in header

    w = new double[n]; //definisco l'array dinamico w di lunghezza n
    r = new double[n]; //definisco l'array dinamico r di lunghezza n
    int count = 0;
    double wtoken;
    double rtoken;
    string line;

    while (count < n)
    {
        getline(file, line, ';');
        ss << line;
        ss >> wtoken;
        w[count] = wtoken;
        ss.clear();

        getline(file, line);
        ss << line;
        ss >> rtoken;
        r[count] = rtoken;
        ss.clear();

        count++;
    }

    return 0;
}

double computeRateOfReturn(const double* w, const double* r, const int n)
{
    double RateOfReturn = 0.0;
    for (int i = 0; i < n; i++) {
        RateOfReturn += w[i] * r[i];
    }
    return RateOfReturn;
}

double computeValue(const double* w, const double* r, const int n, const double S)
{
    double V = 0.0;
    for (int i=0; i<n; i++)
    {
        V += (1 + r[i])*w[i]*S;
    }
    return V;
}

void printResults(const double* w, const double* r, const int n, const double S, const double RoR, const double V, const string filename)
{
    //Stampa su file:
    ofstream outfile(filename); //apre il file di scrittura

    outfile << fixed << setprecision(2); //imposta la rappresentazione decimale fissa a 2 cifre

    outfile << "S = " << S << ", n = " << n << endl; //scrive S ed n
    outfile << defaultfloat << "w = [ ";
    for (int i = 0; i<n; i++) //scrive w
    {
        outfile << w[i] << " ";
    }
    outfile << "] " << endl << "r = [ ";
    for (int i = 0; i<n; i++) //scrive r
    {
        outfile << r[i] << " ";
    }
    outfile << "] " << endl;

    outfile << fixed << setprecision(4) << "Rate of return of the portfolio: " << RoR << endl;
    outfile << setprecision(2) << "V: " << V << endl;

    outfile.close(); //chiude il file di scrittura


    //Stampa su compiler:
    cout << fixed << setprecision(2);

    cout << "S = " << S << ", n = " << n << endl; //scrive S ed n
    cout << defaultfloat << "w = [ ";
    for (int i = 0; i<n; i++) //scrive w
    {
        cout << w[i] << " ";
    }
    cout << "] " << endl << "r = [ ";
    for (int i = 0; i<n; i++) //scrive r
    {
        cout << r[i] << " ";
    }
    cout << "] " << endl;

    cout << fixed << setprecision(4) << "Rate of return of the portfolio: " << RoR << endl;
    cout << setprecision(2) << "V: " << V << endl;
}
