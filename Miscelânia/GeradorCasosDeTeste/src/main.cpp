#include <bits/stdc++.h>
#include "../include/InstanceGenerator.hpp"
#include "../include/Random.hpp"
#include "../include/Utils.hpp"

using namespace std;

int main(){
    int n, m, y;
    cin >> n >> m >> y;
    Random::SetSeed();
    InstanceGenerator* ig = new InstanceGenerator();
    // Altere aqui os atributos da instancia que deseja criar
    //gera estância com  valores vértices, arestas, gulosa
    cout << ig->NewInstance(n, m, !y);
    delete ig;
}