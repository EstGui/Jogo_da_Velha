#include <iostream>
#include <string>

using namespace std;

template<typename T, size_t N>
size_t contarLinhas(const T (&)[N]) {
    return N;
}


bool defineStatus(string** matriz) {
    if ((matriz[0][0] == matriz[0][1] && matriz[0][1] == matriz[0][2]) ||
        (matriz[1][0] == matriz[1][1] && matriz[1][1] == matriz[1][2]) ||
        (matriz[2][0] == matriz[2][1] && matriz[2][1] == matriz[2][2]) ||
        (matriz[0][0] == matriz[1][0] && matriz[1][0] == matriz[2][0]) ||
        (matriz[0][1] == matriz[1][1] && matriz[1][1] == matriz[2][1]) ||
        (matriz[0][2] == matriz[1][2] && matriz[1][2] == matriz[2][2]) ||
        (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2]) ||
        (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0])) {
        
        return true;
    }
    return false;
}


void showMatriz(string** matriz) {
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            std::cout << matriz[i][j];

            std::cout << ((j != 2) ? "|" : "\n");
        }
    }
}


void inserirJogada(string** matriz, short position, string initialChar) {
    short line = (position - 1) / 3;
    short column = (position - 1) % 3;

    if (matriz[line][column] != "X" && matriz[line][column] != "O") 
        matriz[line][column] = initialChar;
    else
        std::cout << "Opção Inválida";
}


int main() {
    unsigned short size = 3;
    bool status;
    string** matriz = new string*[size];

    for (size_t i = 0; i < size; i++) {
        matriz[i] = new string[size];
    }

    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            matriz[i][j] = to_string(j + 1 + i * 3);
        }
    }

    string initialChar;
    do {
        std::cout << "X ou O?";
        std::cin >> initialChar;
        initialChar = toupper(initialChar[0]);
    } while (initialChar != "X" && initialChar != "O");

    unsigned short position;
    do {
        system("cls");
        showMatriz(matriz);
        cout << "Informe a posicao: ";
        cin >> position;

        inserirJogada(matriz, position, initialChar);

        status = defineStatus(matriz);
        initialChar = (initialChar == "O") ? "X" : "O";
    } while (!status);

    system("cls");
    showMatriz(matriz);

    return 1;
}