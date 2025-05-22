#include <iostream>
#include <vector>
using namespace std;

int mergeCount(vector<int>& VectorL, int izq, int der, int mitad) {
    int inve = 0;
    int s1 = mitad - izq + 1;
    int s2 = der -mitad;
    vector<int> Izqu(s1), Dere(s2);

    for (int i = 0; i < s1; i++) 
        Izqu[i] = VectorL[izq + i];
    
    for (int i = 0; i < s2; i++)
        Dere[i] = VectorL[i + mitad+ 1];

    int i = 0, j = 0, k = izq;
    while (i < s1 && j < s2) {
        if (Izqu[i] <= Dere[j])
            VectorL[k++] = Izqu[i++];
        else{
            VectorL[k++] = Dere[j++];
            inve += s1 - i;;
        }
    }

    while (i < s1) 
       VectorL[k++] = Izqu[i++];
    while (j < s2) 
        VectorL[k++] = Dere[j++];

    return inve;
}

int SortCount(vector<int>& VectorL, int izq, int der) {
    if (izq >= der) return 0;
    int inve = 0;
    int mitad = izq + (der - izq) / 2;
    inve += SortCount(VectorL, izq, mitad);
    inve += SortCount(VectorL, mitad+1, der);
    inve += mergeCount(VectorL, izq,der, mitad);
    return inve;
}

int main()
{
    vector<int> VectorL = { 1, 5, 4, 8, 10, 2, 6, 9, 12, 11, 3, 7 };
    int izq = 0, der = VectorL.size() - 1;
    
    cout << "# inversiones: " << SortCount(VectorL, izq, der) << "  "  << endl;
    cout << "vector  ";
    for (int i = 0; i < VectorL.size(); i++)
        cout << VectorL[i] << " ";
    cout << endl;
    return 0;
}



