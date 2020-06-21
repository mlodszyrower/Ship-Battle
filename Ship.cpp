#include <iostream>
#include <ctime>
using namespace std;

const int rows = 10, elements = 10;
int matrix[rows][elements];
int maxShips = 10;

void Clear() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < elements; j++) {
            matrix[i][j] = 0;
        }
    }
}

void Show() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < elements; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int NumberOfShips() {
    int a = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < elements; j++) {
            if (matrix[i][j] == 1)
                a++;
        }
    }

    return a;
}

void SetShips() {
    int s = 0;
    while (s < maxShips) {
        int x = rand() % rows;
        int y = rand() % elements;
        if (matrix[x][y] != 1) {
            s++;
            matrix[x][y] = 1;
        }
    }
}

bool Attack(int x, int y) {
    if (matrix[x][y] == 1) {
        matrix[x][y] = 2;
        return true;
    }
    return false;
}

int main()
{
    srand(time(NULL));

    Clear();
    SetShips();
    int pos1, pos2;
    char prompt;
    while (1) {
        cout << "Please select location: "; cin >> pos1 >> pos2;
        if (Attack(pos1, pos2))
            cout << "Nice shot!" << endl;
        else
            cout << "Miss!" << endl;
        cout << "Number of ships " << NumberOfShips() << endl;
        cout << "Do you want to surrender? (y/n)"; cin >> prompt;
        if (prompt == 'y')
            break;
    }
    cout << "Thanks for playing." << endl;
    Show();
    system("pause");
    return 0;
}