// tareaADAIvan.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

//



#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;



int maxContenedores(int k, int n, vector<int> pesos, vector<int> &resu, float &fraccion) {

    int suma = 0, contenedores=0;

    sort(pesos.begin(), pesos.end());

    for (int i = 0; i < n; i++) {

        if (pesos[i] + suma <= k) {

            suma += pesos[i];

            resu[i] = pesos[i];

            contenedores++;

        }

        else {

            fraccion = (float)((pesos[i]+suma - k) / (float)pesos[i]);

            cout << endl << fraccion << endl;

            break;

        }

    }

    return contenedores;

}



int main()

{

    int k, n;

    float fraccion=0;

    cout << "ingrese cantidad maxima de carga:";

    cin >> k;

    cout << "ingrese cantidad de contenedores:";

    cin >> n;

    vector<int> pesos(n);

    vector<int> resu(n);

    for (int i = 0; i < n; i++) {

        cout << "ingrese peso:";

        cin >> pesos[i];

    }

    int cantMax = maxContenedores(k, n, pesos, resu, fraccion);

    cout << "cantidad maxima de contenedores: " << cantMax;

    if (fraccion != 0) cout << " + fraccion " << fraccion;

    /*for (int i = 0; i < n; i++) {

        if (pesos[i] == resu[i]) {

            cout << "contenedor No" << 

        }

    }*/



}