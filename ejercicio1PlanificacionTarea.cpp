#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Tuple {
    int beneficio;
    int plazo;
    int id;
    Tuple(): beneficio(0), plazo(0), id(0) {}
};

bool compararBeneficio(const Tuple &a, const Tuple &b) {
    return a.beneficio > b.beneficio;
}

void maxBeneficio(vector<Tuple> &tareas, int n) {
    sort(tareas.begin(), tareas.end(), compararBeneficio);
    int maxPlazo = 0;
    for (const auto &t : tareas) 
        maxPlazo = max(maxPlazo, t.plazo);
    
    vector<bool> ocupado(maxPlazo + 1, false); 
    vector<Tuple> seleccionadas;
    int beneficioTotal = 0;

    for (const auto &t : tareas) {
        for (int d = t.plazo; d >= 1; --d) {
            if (!ocupado[d]) {
                ocupado[d] = true;
                seleccionadas.push_back(t);
                beneficioTotal += t.beneficio;
                break;
            }
        }
    }

    cout << "\ntareass: ";
    for (const auto &t : seleccionadas) {
        cout << t.id << " ";
    }
    cout << "\nbeneficio máximo: " << beneficioTotal << endl;
}

int main() {
    int n;
    cout << "ingrese número de tareas: ";
    cin >> n;
    vector<Tuple> tareas(n);
    cout << "ingrese beneficio y plazo límite de cada tarea:\n";
    for (int i = 0; i < n; i++) {
        cin >> tareas[i].beneficio >> tareas[i].plazo;
        tareas[i].id = i + 1;
    }
    maxBeneficio(tareas, n);
    return 0;
}