#include <iostream>
#include <string>

using namespace std;

int main() {
    int MaxCandidatos; 
    int numVotos;
    string candidatos[100];
    string partidos[100];
    int votos[100] = {0};
    int votosNulos = 0; 

    
    cout << "Ingrese el numero de candidatos: ";
    cin >> MaxCandidatos;
    cin.ignore(); 

    
    cout << "Ingrese el numero de votos que desea registrar: ";
    cin >> numVotos;  
    cin.ignore(); 

    
    for (int i = 0; i < MaxCandidatos; ++i) {
        cout << "\nIngrese los datos del candidato " << (i + 1) << ":\n";
        cout << "Nombre: ";
        getline(cin, candidatos[i]);

        cout << "Partido politico: ";
        getline(cin, partidos[i]); 
    }


    cout << "\nCandidatos registrados:\n";
    for (int i = 0; i < MaxCandidatos; ++i) {
        cout << "- " << candidatos[i] << " (" << partidos[i] << ")\n";
    }

    
    int totalVotos = 0; 
    for (int i = 0; i < numVotos; ++i) {
        string voto;
        cout << "\nIngrese el nombre del candidato al que desea votar: ";
        getline(cin, voto);

        bool encontrado = false;

    
        for (int j = 0; j < MaxCandidatos; ++j) {
            if (candidatos[j] == voto) {
                votos[j]++;  
                totalVotos++; 
                cout << "Voto registrado para: " << voto << endl;
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            cout << "Candidato no encontrado, voto nulo.\n"; 
            votosNulos++; 
            totalVotos++;
        }
    }


    cout << "\nReporte de resultados:\n";
    for (int i = 0; i < MaxCandidatos; ++i) {
        double porcentaje = (totalVotos > 0) ? (double)votos[i] / totalVotos * 100 : 0.0;
        cout << candidatos[i] << " (" << partidos[i] << "): " << votos[i] << " votos (" << porcentaje << "%)\n";
    }

    
    double porcentajeVotosNulos = (totalVotos > 0) ? (double)votosNulos / totalVotos * 100 : 0.0;
    cout << "\nVotos nulos: " << votosNulos << " votos (" << porcentajeVotosNulos << "%)\n";

    
    int maxVotos = 0;
    string ganador;
    bool empate = false;
    for (int i = 0; i < MaxCandidatos; ++i) {
        if (votos[i] > maxVotos) {
            maxVotos = votos[i];
            ganador = candidatos[i];
            empate = false; 
        } else if (votos[i] == maxVotos) {
            empate = true; 
        }
    }

    if (empate) {
        cout << "\nHay un empate entre los candidatos con mas votos.\n";
    } else {
        cout << "\nGanador de la eleccion: " << ganador << " con " << maxVotos << " votos.\n";
    }

    return 0;
}

