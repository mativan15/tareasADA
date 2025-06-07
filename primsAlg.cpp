#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

class Grafo {
public:
    map<string, vector<pair<string,int>>> adj; //l. adyacencia

    void agregarArista(const string& u, const string& v, int peso) {
        adj[u].push_back({v, peso});
        adj[v].push_back({u, peso}); 
    }
    void mostrar() {
        for (auto& [nodo, vecinos] : adj) {
            cout << nodo << " -> ";
            for (auto& [vecino, peso] : vecinos) {
                cout << "(" << vecino << ", " << peso << ") ";
            }
            cout << endl;
        }
    }
};

void primsAlgorithm(Grafo& g) {
    priority_queue< pair<int, string>, vector<pair<int, string>>, greater< pair<int, string>> > pq;
    map<string, int> key;
    map<string, bool> usado;
    map<string, string> pi;
    int pesoTotal =0;
    for (auto& [vertice, vecinos] : g.adj) {
        key[vertice] = INT_MAX; //  claves = infinito
        usado[vertice] = false; // todos los nodos no usados
    }
    key[g.adj.begin()->first] = 0;
    pq.push({0, g.adj.begin()->first}); 
    while(!pq.empty()){
        pair<int, string> menor = pq.top();
        cerr << " " << menor.first << " " << menor.second << endl;
        pq.pop();
        if (usado[menor.second]) continue;
        pesoTotal += menor.first;
        usado[menor.second] = true;
        for (auto &[vecino, peso] : g.adj[menor.second]){
            if (!usado[vecino] && peso < key[vecino]){
                key[vecino] = peso;
                pi[vecino] = menor.second;
                pq.push({key[vecino], vecino});
            }
        }
    }
    cout << "\nMST:\n";
    for(auto &[nodo1, nodo2] : pi){
        cout << nodo1 << "--" << nodo2 << endl;
    }
    cout << "\nPeso Total: " << pesoTotal;
}

int main() {
    Grafo g;
    g.agregarArista("A", "B", 1);
    g.agregarArista("A", "C", 4);
    g.agregarArista("A", "D", 3);
    g.agregarArista("B", "C", 2);
    g.agregarArista("B", "E", 2);
    g.agregarArista("C", "D", 5);
    g.agregarArista("C", "E", 5);
    g.agregarArista("D", "E", 7);

    g.mostrar();
    primsAlgorithm(g);
    return 0;
}