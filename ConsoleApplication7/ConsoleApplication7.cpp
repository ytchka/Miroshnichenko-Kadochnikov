#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <windows.h>
using namespace std;

struct Matrix {
    // двумерный массив с данными.
    int** mp = nullptr;
    // количество столбцов
    size_t str = 0;
    // количество строк
    size_t sto = 0;
};

void Construct(Matrix& matrix, size_t n, size_t m) {
    srand(time(nullptr));
    matrix.str = n;
    matrix.sto = m;
    matrix.mp = new int* [n];
    for (int i = 0; i < n; ++i) {
        matrix.mp[i] = new int[m];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrix.mp[i][j] = rand() % 10;
        }
    }
}
void add(Matrix& mx, Matrix& mx1) {
    Matrix mx2;
    Construct(mx2, mx.str, mx.sto);
    for (int i = 0; i < mx.str; ++i) {
        for (int j = 0; j < mx.sto; ++j) {
            mx2.mp[i][j] = mx.mp[i][j] + mx1.mp[i][j];
        }
    }
    for (int i = 0; i < mx.str; ++i) {
        for (int j = 0; j < mx.sto; ++j) {
            cout << mx2.mp[i][j] << " ";
        }
        cout << endl;
    }
}
void copy(Matrix& mx) {
    Matrix mx2;
    Construct(mx2, mx.str, mx.sto);
    mx2.mp = mx.mp;
    for (int i = 0; i < mx.str; ++i) {
        for (int j = 0; j < mx.sto; ++j) {
            cout << mx2.mp[i][j] << " ";
            }
            cout << endl;
        }
}
void sub(Matrix& mx, Matrix& mx1) {
    Matrix mx2;
    Construct(mx2, mx.str, mx.sto);
    for (int i = 0; i < mx.str; ++i) {
        for (int j = 0; j < mx.sto; ++j) {
            mx2.mp[i][j] = mx.mp[i][j] - mx1.mp[i][j];
        }
    }
    for (int i = 0; i < mx.str; ++i) {
        for (int j = 0; j < mx.sto; ++j) {
            cout << mx2.mp[i][j] << " ";
        }
        cout << endl;
    }
}
void mult(Matrix& mx, Matrix& mx1){
    Matrix mx2;
    Construct(mx2, mx.str, mx.sto);
    for (int i = 0; i < mx.str; ++i) {
        for (int j = 0; j < mx.sto; ++j) {
            for (int k = 0; k < mx2.str; ++k) {
                mx2.mp[i][j] += mx.mp[i][k] * mx1.mp[k][j];
            }
        }
    }
    for (int i = 0; i < mx.str; ++i) {
        for (int j = 0; j < mx.sto; ++j) {
            cout << mx2.mp[i][j] << " ";
        }
        cout << endl;
    }


}
void trans(Matrix& mx) {
    Matrix mx2;
    Construct(mx2, mx.str, mx.sto);
    for (int i = 0; i < mx.str; ++i) {
        for (int j = 0; j < mx.sto; ++j) {
            mx2.mp[i][j] = mx.mp[j][i];
        }
    }
    for (int i = 0; i < mx.str; ++i) {
        for (int j = 0; j < mx.sto; ++j) {
            cout << mx2.mp[i][j] << " ";
        }
        cout << endl;
    }


}



int main() {
    size_t n = 3;
    size_t m = 3;
    Matrix t;
    Construct(t, n, m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << t.mp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    Sleep(1000);
    Matrix t1;
    Construct(t1, n, m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << t1.mp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    Matrix sm;
    add(t, t1);
    cout << endl;
    copy(t);
    cout << endl;
    sub(t, t1);
    cout << endl;
    mult(t, t1);
    cout << endl;
    trans(t);
}
