#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;


template <typename T> void swap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

class Exception {
    int n_error;
    string s_error;

public:
    Exception(int error) {
        n_error = error;
    }

    string Message_CS(void) {
        switch (n_error)
        {
        case 1:
            return string("wrong index");
            break;
        case 2:
            return string("The lengths of Arrays should be same.");
            break;
        default:
            return string("unknown exception.");
        } 
    }
};

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
        if (arr!=NULL) delete[] arr;
    }

    int GetL() {
        return this->leng;
    }
    void inputData(int idx, T data) {
        if (idx > leng || idx < 0) throw(Exception(1));
        else this->arr[idx] = data;
    }

    T& operator[](int i) {
        return arr[i];
    }

    //assignment operator
    Array& operator=(const Array& a) {

        if (arr != NULL) delete[] arr;
        this->leng = a.leng;
        arr = new T[leng];

        for (int i = 0; i < leng; i++) {
            arr[i] = a.arr[i];
        }

        return *this;
    }
    
    //comparison operator
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
            throw(Exception(2));
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
            throw(Exception(2));
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
            throw(Exception(2));
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
            throw(Exception(2));
        }
    }

    Array& operator+=(Array& a) {
        if (this->leng != a.leng) throw(Exception(2));
        else {
            for (int i = 0; i < a.leng; i++) {
                this->arr[i] = this->arr[i] + a.arr[i];
            }
            return *this;
        }
    }
    Array& operator-=(Array& a) {
        if (this->leng != a.leng) throw(Exception(2));
        else {
            for (int i = 0; i < a.leng; i++) {
                this->arr[i] = this->arr[i]-a.arr[i];
            }
            return *this;
        }
    }
    Array& operator*=(Array& a) {
        if (this->leng != a.leng) throw(Exception(2));
        else {
            for (int i = 0; i < a.leng; i++) {
                this->arr[i] = this->arr[i] * a.arr[i];
            }
            return *this;
        }
    }
    Array& operator/=(Array& a) {
        if (this->leng != a.leng) throw(Exception(2));
        else {
            for (int i = 0; i < a.leng; i++) {
                this->arr[i] = this->arr[i] / a.arr[i];
            }
            return *this;
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

    double average() {
        T s = 0; 
        for (int i = 0; i < this->leng; i++) {
            s += this->arr[i];
        }
        double aver = s / this->leng;
        return aver;
    }

    double standard_deviation() {
        T s = 0;
        for (int i = 0; i < this->leng; i++) {
            s += this->arr[i];
        }
        double aver = s / this->leng;
        double v=0;
        for (int i = 0; i < this->leng; i++) {
            v += pow((aver - this->arr[i]), 2);
        }
        return sqrt(v / this->leng);

    }


    //sorting
    Array ascending() {
        Array asc(*this);
        for (int i = 0; i < this->leng; i++) {
            for (int j = i+1; j < this->leng; j++) {
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

    void resize(int leng_2) {
        this->leng = leng_2;
        if (arr != NULL) delete[] arr;
        arr = new T[leng_2];
    }

    Array() { //default constructor
        leng = 0;
        arr = new T[leng];

    }

    Array(int leng, int leng_2) {
        this->leng = leng;
        arr = new T[leng];
        for (int i = 0; i < this->leng; i++) {
            arr[i].resize(leng_2);


        }
    }

    template <typename P> friend ostream& operator<<(ostream& out, Array < P>&a);
    template <typename P> friend void readF(string address, Array<P>& a);
    template <typename P> friend void writeF(string address, Array<P>& a);
};

template <typename P> ostream& operator<<(ostream& out, Array<P>& a){
    for (int i = 0; i < a.leng; i++) {
        out << a.arr[i] << " ";
    }
    out << "\n";
    return out;
}
template <typename P> void readF(string address,Array<P>& a) {
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

int main()
{
    Array<int> A(10);
    for (int i = 0; i < 10; i++) {
        A.inputData(i, i);
    }
    Array<int> B(A);

    cout << "A array : " << A<< endl;
    cout << "B array : " << B << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "The sum of A is " << A.sum() << endl;
    cout << "The average of A is " << A.average() << endl;
    cout << "The standard deviation of A is " << A.standard_deviation() << endl;

    Array<int> C(10),D(A);
    C = A + B;
    cout << "C array, C=A+B : "<<C<<endl;
    D += A;
    cout << "D array, D+=A : " << D << endl;

    cout << "--------------------------------------------------------" << endl;
    cout << "<Stream>" << endl;

    string a = "C:/Users/ilove/OneDrive/desktop/arrTest1";
  
    writeF(a, A);
    Array<int> F(10);
    readF(a, F);
    if (A == F) {
        cout << "array A is same with array F"<<endl;
    }
    else {
        cout << "array A is not same with array F"<<endl;
    }
    cout << "--------------------------------------------------------" << endl;
    cout << "<Exception>" << endl;
    Array<int> E_1(11);
    for (int i = 0; i < E_1.GetL(); i++) {
        E_1.inputData(i, i);
    }
    
    Array<int>E_2(10);    

    try {
        E_2 = E_1 + A;   
    }
    catch (Exception &e) {
        cout << "Exception caught: " << e.Message_CS() << endl;
    }


    cout << "--------------------------------------------------------" << endl;
    cout << "<2D Array>" << endl;
    Array<Array<int>> aai(10,10);
   for (int i = 0; i < 10; i++) {
       for (int j = 0; j < 10; j++) {
           aai[i].inputData(j, j);
       }
   }
   

    cout << aai;
   
     
    return 0;
}


