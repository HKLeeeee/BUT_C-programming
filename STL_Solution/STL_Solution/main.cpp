#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <complex>
using namespace std;

template <typename T> class Matrix {
private:
	int row, col;
	vector<vector<T>> matx;

public:
	Matrix(int x, int y) {
		this->row = x;
		this->col = y;

		matx.resize(x);

		for (int i = 0; i < this->row; i++) {
			matx[i].resize(y);
		}
	}

	//destructor?

	int GetR() const {
		return row;
	}

	int GetC() const {
		return col;
	}


	Matrix(const Matrix& m) { // copy constructor

		this->row = m.row;
		this->col = m.col;

		matx.resize(this->row);

		for (int i = 0; i < this->row; i++) {
			matx[i].resize(this->col);
		}

		for (int i = 0; i < m.GetR(); i++) {
			for (int j = 0; j < m.GetC(); j++) {
				this->matx[i][j] = m.matx[i][j];
			}
		}
	}

	vector<T> operator[](int i) {
		return matx[i];
	}

	//Matrix& operator=(const Matrix& m) {
	//	Matrix a(m);
	//	return a;
	//}

	void fill(int max) {
		srand((unsigned)time(NULL));
		for (int i = 0; i < this->row; i++) {
			for (int j = 0; j < this->col; j++) {
				this->matx[i][j] = rand() % max;

			}
		}
	}

	void fillComplex() {
		double x;
		double y;
		for (int i = 0; i < this->row; i++) {
			for (int j = 0; j < this->col; j++) {
				x = rand();
				y = rand();
				matx[i][j] = complex<double>(x, y);

			}
		}

	}

	Matrix operator+(const Matrix& a) const {
		Matrix m(a);
		for (int i = 0; i < a.GetR(); i++) {
			for (int j = 0; j < a.GetC(); j++) {
				m.matx[i][j] = this->matx[i][j] + a.matx[i][j];
			}
			//cout << endl;
		}
		return m;
	}





	template <typename P> friend ostream& operator<<(ostream& out, Matrix<P>& m);
};

template <typename P> ostream& operator<<(ostream& out, Matrix<P>& m) {
	for (int i = 0; i < m.matx.size(); i++) {
		for (int j = 0; j < m.matx[i].size(); j++) {
			out << m.matx[i][j] << " ";
		}

		printf("\n");
	}

	return out;
}

int main() {
	srand((unsigned)time(NULL));

	vector<Matrix<complex<double>>> mymatx;
	vector<Matrix<complex<double>>>::iterator it;

	Matrix<complex<double>> matx1(3, 3), matx2(3, 3), matx3(3, 3), sum(3, 3);


	matx1.fillComplex();
	matx2.fillComplex();
	matx3.fillComplex();

	cout << matx1 << endl;
	cout << matx2 << endl;
	cout << matx3 << endl;

	mymatx.push_back(matx1);
	mymatx.push_back(matx2);
	mymatx.push_back(matx3);

	for (it = mymatx.begin(); it != mymatx.end(); it++)
	{
		cout << *it << endl;
		sum = sum + *it;
	}

	cout << sum;

};