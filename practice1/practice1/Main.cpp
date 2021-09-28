#include <iostream>
#include <cmath>
//#include "Array.cpp"
//#include "Matrix.cpp"
using namespace std;
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Matrix {
    int row, col;
    double** matx;

public:
    Matrix(int r, int c) {
        this->row = r;
        this->col = c;


        this->matx = new double* [row];
        for (int i = 0; i < row; i++) {
            this->matx[i] = new double[col];
        }

        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < this->col; j++) {
                this->matx[i][j] = 0;
            }
        }

    }

    int GetR() const { // MUST BE CONST FUNCTION TO ENSURE IT WON'T MODIFY THIS OBJECT (IT IS CALLED FROM THE CONST COPY CONSTRUCTOR)
        return row;
    }
    int GetC() const { // MUST BE CONST FUNCTION TO ENSURE IT WON'T MODIFY THIS OBJECT (IT IS CALLED FROM THE CONST COPY CONSTRUCTOR)
        return col;
    }
    double GetM(int i, int j) const { // MUST BE CONST FUNCTION TO ENSURE IT WON'T MODIFY THIS OBJECT (IT IS CALLED FROM THE CONST COPY CONSTRUCTOR)
        return this->matx[i][j];
    }

    Matrix(const Matrix& m) { //copy constructor THE PARAMETERR MUST BE CONST, BECAUSE THE SOURCE CANNOT BE MODIFIED
        row = m.GetR();
        col = m.GetC();

        this->matx = new double* [row];
        for (int i = 0; i < row; i++) {
            this->matx[i] = new double[col];
        }

        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < this->col; j++) {
                this->matx[i][j] = m.GetM(i, j);
            }
        }
    }

    Matrix(int r, int c, int in) { //conversion
        this->row = r;
        this->col = c;
        if (this->matx != NULL) delete[] & this->matx;
        this->matx = new double* [row];
        for (int i = 0; i < row; i++) {
            this->matx[i] = new double[col];
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                this->matx[i][j] = in;
            }
        }


    }


    void fill(int max) {
        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < this->col; j++) {
                this->matx[i][j] = rand() % max;
            }
        }
    }


    Matrix& operator=(const Matrix& m) { // THE PARAMETER MUST BE CONST TO ENSURE THE FUNCTION WON'T MODIFY THIS OBJECT (RIGHT OPERAND)
        Matrix a(m);
        return a;
    }


    Matrix& operator-() {
        Matrix temp(this->row, this->col);

        for (int i = 0; i < this->row; i++) {
            for (int j = 0; j < this->col; j++) {
                temp.matx[i][j] = (-1) * this->matx[i][j];
            }
        }
        return temp;
    }

    Matrix operator+(Matrix a) const {
        Matrix m(a);
        for (int i = 0; i < a.row; i++) {
            for (int j = 0; j < a.col; j++) {
                m[i][j] = this->matx[i][j] + a.matx[i][j];
            }
            cout << endl;
        }
        return m;
    }

    Matrix operator-(Matrix a) const {
        Matrix m(a);
        for (int i = 0; i < a.row; i++) {
            for (int j = 0; j < a.col; j++) {
                m[i][j] = this->matx[i][j] - a.matx[i][j];
            }
            cout << endl;
        }
        return m;
    }

    Matrix operator*(Matrix a) const {
        Matrix m(a);
        for (int i = 0; i < a.row; i++) {
            for (int j = 0; j < a.col; j++) {
                m[i][j] = this->matx[i][j] * a.matx[i][j];
            }
            cout << endl;
        }
        return m;
    }

    Matrix operator/(Matrix a) const {
        Matrix m(a);
        for (int i = 0; i < a.row; i++) {
            for (int j = 0; j < a.col; j++) {
                m[i][j] = this->matx[i][j] / a.matx[i][j];
            }
            cout << endl;
        }
        return m;
    }

    double* operator[](int i) const {
        return matx[i];
    }

    void inputData(int r, int c, double data) {
        this->matx[r][c] = data;
    }

    friend ostream& operator<<(ostream& out, Matrix& a);


};

ostream& operator<<(ostream& out, Matrix& a) {
    for (int i = 0; i < a.GetR(); i++) {
        for (int j = 0; j < a.GetC(); j++) {
            out << a.matx[i][j] << " ";
        }
        printf("\n");
    }
    return out;
}

Matrix operator+ (const Matrix m, const double x) { //MUST BE CONST TO MAKE THE OPERATOR FUNCTION RECOGNIZBLE
    Matrix a(m);

    for (int i = 0; i < m.GetR(); i++) {
        for (int j = 0; j < m.GetC(); j++) { // ERROR: MUST BE J++
            a[i][j] = m[i][j] + x;
        }
    }

    return a;
}

Matrix operator- (Matrix m, double x) {
    Matrix a(m);

    for (int i = 0; i < m.GetR(); i++) {
        for (int j = 0; j < m.GetC(); j++) { // ERROR: MUST BE J++
            a[i][j] = m[i][j] - x;
        }
    }

    return a;
}

Matrix operator* (Matrix m, double x) {
    Matrix a(m);

    for (int i = 0; i < m.GetR(); i++) {
        for (int j = 0; j < m.GetC(); j++) {
            a[i][j] = m[i][j] * x;
        }
    }

    return a;
}

Matrix operator/ (Matrix m, double x) {
    Matrix a(m);

    for (int i = 0; i < m.GetR(); i++) {
        for (int j = 0; j < m.GetC(); j++) { 
            a[i][j] = m[i][j] / x;
        }
    }

    return a;
}


int main(int argc, char* argv[]) {
	Matrix A(3, 3);
	Matrix B(3, 1);

    for (int i = 0; i < argc; i++) {
        int j = 0;
        int k = 0;
        if (i % 3 != 0) {
            A.inputData(j, k, atof(argv[i]));
            k++;
        }
        else {
            B.inputData(i, 0, atof(argv[i]));
            j++;
            k = 0;
        }
    }
	
    cout << argv << endl;
    cout << A << endl;
    cout << B << endl;

}