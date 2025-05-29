#include <iostream>
#include <vector>
using namespace std;

int returnMonedas(){
    int n;
    cout<< "ingrese cantidad\n";
    cin >> n;
    cout<< "moneda:\n";
    vector<int> monedas(n);
    for (int i=0 ; i < n; i++){
        int m;
        cin >> m;
        monedas[i] = m;
    }
    int suma =0,contador=0;
    sort(monedas.begin(), monedas.end());
    for (int i=0 ; i <= n-1; i++){
        if (suma + monedas[i] < monedas[i+1]){
            contador++;
            suma += monedas[i];
        }
    }
    contador++;

    return contador;
}
int main(){
    int t = returnMonedas();
    cout << endl << "numero total: " << t;
    return 0;
}