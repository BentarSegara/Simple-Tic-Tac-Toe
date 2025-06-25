#include <iostream>

using namespace std;

void show_papan(char papan[3][3]) {
    cout << "                ";
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            if (column == 2 ) {
                cout << papan[row][column];
            }else {
                cout << papan[row][column] << " | ";
            }
        }
        cout << endl;
        if (row < 2) {
            cout << "                ---------" << endl;

        }cout << "                ";

    }cout << endl;

}


bool is_coordinate_valid(int baris, int kolom) {
    if (baris < 0 || baris > 2 || kolom < 0 || kolom > 2) {
        return false;
    }else {
        return true;
    }
}

void turn(char papan[3][3], char symbol) {
    int baris;
    int kolom;
    cout << "input baris (0 - 2): ";cin >> baris;
    cout << "input kolom (0 - 2): ";cin >> kolom;
    if (! is_coordinate_valid(baris, kolom)) {
        cout << "Invalid Input." << endl;
        turn(papan, symbol);
    }else {
        if (papan[baris][kolom] == 'X' || papan[baris][kolom] == 'O') {
            cout << "This position has been filled" << endl;
            return turn(papan, symbol);
        }else {
            papan[baris][kolom] = symbol;
        }

    }
}


bool check_winner(char papan[3][3]) {
    //cek vertical and horizontal
    for (int i = 0; i < 3; i++) {
        if ( (papan[0][i] != ' ' && (papan[0][i] == papan[1][i] && papan[1][i] == papan[2][i])) ||
            (papan[i][0] != ' ' && (papan[i][0] == papan[i][1] && papan[i][1] == papan[i][2])) ) {
                return true;
            }
    // cek diagonal
    }if ( (papan[0][0] != ' ' && (papan[0][0] == papan[1][1] && papan[1][1] == papan[2][2]) ) ||
         (papan[0][2] != ' ' && (papan[0][2] == papan[1][1] && papan[1][1] == papan[2][0])) ) {
            return true;
         }else {
            return false;
         }
}


void start_the_game(char papan[3][3]) {
    int isi_papan = 0;
    string Player1 = "Player 1 win.";
    string Player2 = "Player 2 win.";
    string Draw = "Draw.";

    while (isi_papan <= 9 ){
        show_papan(papan);
        cout << "Player 1 Turn ( X )" << endl;
        turn(papan, 'X');
        isi_papan++;
        system("cls");

        if (check_winner(papan) == true) {
            show_papan(papan);
            cout << Player1;
            break;
        }else {
           if (isi_papan == 9) {
            show_papan(papan);
            cout << Draw;
            break;
           }else {
            show_papan(papan);
            cout << "Player 2 Turn ( O )" << endl;
            turn(papan, 'O');
            isi_papan++;
            system("cls");
            
            if (check_winner(papan) == true) {
                show_papan(papan);
                cout << Player2;
                break;
                }
           }

        }
    }
}

int main() {
    int point = 0;
    char papan[3][3] = {{' ', ' ', ' '}, // 0
                        {' ', ' ', ' '}, // 1
                        {' ', ' ', ' '}}; //2

    start_the_game(papan);

    
    return 0;
}
