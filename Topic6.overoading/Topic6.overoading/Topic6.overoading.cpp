// Topic6.overoading.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

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

    friend ostream& operator<<(ostream& out, Matrix& a);


};

ostream& operator<<(ostream& out, Matrix& a) {
    for (int i = 0; i < a.row; i++) {
        for (int j = 0; j < a.col; j++) {
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
        for (int j = 0; j < m.GetC(); j++) { // ERROR: MUST BE J++
            a[i][j] = m[i][j] * x;
        }
    }

    return a;
}

Matrix operator/ (Matrix m, double x) {
    Matrix a(m);

    for (int i = 0; i < m.GetR(); i++) {
        for (int j = 0; j < m.GetC(); j++) { // ERROR: MUST BE J++
            a[i][j] = m[i][j] / x;
        }
    }

    return a;
}


int main()
{
    Matrix A(3, 4), B(3, 4), C(3, 4);
    A.fill(20);
    B.fill(20);
    C.fill(20);

    C = A + B;
   // C = -A + B + 3 + B[1][2];
    cout << A << endl << B << endl << C << endl;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
