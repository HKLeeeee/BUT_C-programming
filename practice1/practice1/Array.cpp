#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;


template <typename T> void swap(T& a, T& b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}


template <typename T> class Array {
private:
    int leng;
    T* arr;
public:
    Array(int leng) {
        this->leng = leng;
        arr = new T[leng];
    }

    Array(const Array& a) { //copy constructor
        this->leng = a.leng;
        arr = new T[leng];

        for (int i = 0; i < leng; i++) {
            arr[i] = a.arr[i];
        }
    }
    ~Array() {
        delete[] arr;
    }
    int GetL() {
        return this->leng;
    }
    void inputData(int idx, T data) {
        try {
            if (idx > leng || idx < 0) throw("wrong index");
            this->arr[idx] = data;
        }

        catch (char* error) {
            cout << error;
        }
    }

    Array& operator=(const Array& a) {

        if (arr != NULL) delete[] arr;
        this->leng = a.leng;
        arr = new T[leng];

        for (int i = 0; i < leng; i++) {
            arr[i] = a.arr[i];
        }

        return *this;
    }

    T operator[](int i) {
        return this->arr[i];
    }

    //assignment operator
    bool operator==(const Array& a) {
        int cnt = 0;
        if (this->leng == a.leng) {
            for (int i = 0; i < leng; i++) {
                if (this->arr[i] == a.arr[i]) cnt++;
                else cnt--;
            }
            if (cnt == this->leng) return true;
            else return false;
        }
        else {
            return false;
        }
    }
    bool operator!=(const Array& a) {
        int cnt = 0;
        if (this->leng == a.leng) {
            for (int i = 0; i < leng; i++) {
                if (this->arr[i] == a.arr[i]) cnt++;
                else cnt--;
            }
            if (cnt == this->leng) return false;
            else return true;
        }
        else {
            return true;
        }
    }

    //binary operator
    Array operator+(Array& a) const {
        Array t(a);
        if (this->leng == a.leng) {
            for (int i = 0; i < a.leng; i++) {
                t.arr[i] = this->arr[i] + a.arr[i];
            }
            return t;
        }

        else {
            cout << "The lengths of Arrays should be same. ";
            return *this;
        }
    }
    Array operator-(Array& a) const {
        Array t(a);

        if (this->leng == a.leng) {
            for (int i = 0; i < a.leng; i++) {
                t.arr[i] = this->arr[i] - a.arr[i];
            }
            return t;
        }

        else {
            cout << "The lengths of Arrays should be same. ";
            return *this;
        }
    }
    Array operator*(Array& a) const {
        Array t(a);

        if (this->leng == a.leng) {
            for (int i = 0; i < a.leng; i++) {
                t.arr[i] = this->arr[i] / a.arr[i];
            }
            return t;
        }

        else {
            cout << "The lengths of Arrays should be same. ";
            return *this;
        }
    }
    Array operator/(Array& a) const {
        Array t(a);

        if (this->leng == a.leng) {
            for (int i = 0; i < a.leng; i++) {
                t.arr[i] = this->arr[i] - a.arr[i];
            }
            return t;
        }

        else {
            cout << "The lengths of Arrays should be same. ";
            return *this;
        }
    }

    Array& operator+=(Array& a) {
        try {
            if (this->leng != a.leng) throw("the length should be same");
            for (int i = 0; i < a.leng; i++) {
                this->arr[i] = this->arr[i] + a.arr[i];
            }
            return *this;
        }
        catch (char* error) {
            cout << error;
        }
    }
    Array& operator-=(Array& a) {
        try {
            if (this->leng != a.leng) throw("the length should be same");
            for (int i = 0; i < a.leng; i++) {
                this->arr[i] = this->arr[i] - a.arr[i];
            }
            return *this;
        }
        catch (char* error) {
            cout << error;
        }
    }
    Array& operator*=(Array& a) {
        try {
            if (this->leng != a.leng) throw("the length should be same");
            for (int i = 0; i < a.leng; i++) {
                this->arr[i] = this->arr[i] * a.arr[i];
            }
            return *this;
        }
        catch (char* error) {
            cout << error;
        }
    }
    Array& operator/=(Array& a) {
        try {
            if (this->leng != a.leng) throw("the length should be same");
            for (int i = 0; i < a.leng; i++) {
                this->arr[i] = this->arr[i] / a.arr[i];
            }
            return *this;
        }
        catch (char* error) {
            cout << error;
        }
    }

    //unary operator
    Array& operator-() {
        for (int i = 0; i < this->leng; i++) {
            this->arr[i] = (-1) * this->arr[i];
        }
        return *this;
    }

    //calculation function
    T sum() {
        T s = 0;
        for (int i = 0; i < this->leng; i++) {
            s += this->arr[i];
        }
        return s;
    }
    T average() {
        T s = 0;
        for (int i = 0; i < this->leng; i++) {
            s += this->arr[i];
        }
        return s / this->leng;
    }
    T standard_deviation() {
        T aver = this->average();

        T s = 0;
        for (int i = 0; i < this->leng; i++) {
            s += pow((aver - this->arr[i]), 2);
        }
        return sqrt(s / this->leng);

    }

    //sorting
    Array ascending() {
        Array asc(*this);
        for (int i = 0; i < this->leng; i++) {
            for (int j = i + 1; j < this->leng; j++) {
                if (asc.arr[i] > asc.arr[j]) {
                    ::swap(asc.arr[i], asc.arr[j]);
                }
            }
        }
        return asc;
    }
    Array desending() {
        Array des(*this);
        for (int i = 0; i < this->leng; i++) {
            for (int j = i + 1; j < this->leng; j++) {
                if (des.arr[i] < des.arr[j]) {
                    ::swap(des.arr[i], des.arr[j]);
                }
            }
        }
        return des;
    }

    template <typename P> friend ostream& operator<<(ostream& out, Array < P>& a);
    template <typename P> friend void readF(string address, Array<P>& a);
    template <typename P> friend void writeF(string address, Array<P>& a);
};

template <typename P> ostream& operator<<(ostream& out, Array<P>& a) {
    for (int i = 0; i < a.leng; i++) {
        out << a.arr[i] << " ";
    }
    printf("\n");
    return out;
}
template <typename P> void readF(string address, Array<P>& a) {
    ifstream file;
    file.open(address);
    for (int i = 0; i < a.GetL(); i++) {
        file >> a.arr[i];
    }
    file.close();
}
template <typename P> void writeF(string address, Array<P>& a) {
    ofstream file;
    file.open(address);
    for (int i = 0; i < a.GetL(); i++) {
        file << a.arr[i] << " ";
    }
    file << "\n";
    file.close();
}