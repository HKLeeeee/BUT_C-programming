// Topic7.templates.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdlib.h>
#include<stdio.h>
#include <time.h>
using namespace std;

template <typename T> class Array {
private:
    int length;
    T* arr;

public:
    Array(int len) {
        this->length = len;
        arr = new T[len];
    }
    ~Array() {
        delete[] arr;
    }

    void setArr(int idx, T data) {
        this->arr[idx] = data;
    }

    T& operator[](int i) const {
        return arr[i];
    }


    Array operator=(Array Arr) {
        if (length > 0) delete[] arr;
        this->length = Arr.length;
        arr = new T[length];
        for (int i = 0; i < length; i++) arr[i] = Arr.arr[i];
    }


    template <typename P> friend ostream& operator<<(ostream& out, Array<P>& a);

};


template <typename P> ostream& operator<<(ostream& out, Array<P>& a) {
    for (int i = 0; i < a.length; i++) {
        out << a.arr[i] << " ";
    }
    return out;
}

class Person {
private:
    int ID;
    string name;
    string surname;
    int phone;

public:

    Person() {
        ID = 0;
        name = "";
        surname = "";
        phone = 0;
    }

    void setID(int i) {
        this->ID = i;
    }
    void setName(string s) {
        this->name = s;
    }
    void setSurname(string s) {
        this->surname = s;
    }
    void setPhone(int i) {
        this->phone = i;
    }

    friend ostream& operator<<(ostream& out, Person& p);


};

ostream& operator<<(ostream& out, Person& p) {
    out << "ID : " << p.ID << endl;
    out << "Name : " << p.name << endl;
    out << "Surname : " << p.surname << endl;
    out << "Phone : " << p.phone << endl;

    return out;
}



int main() {
    Array<int> A(8);
    Array<Person> B(8);
    string names[8] = { "John","Oliver","Jack","Jacob", "William","James","Daniel","Charlie" };
    string surnames[8] = { "Smith","Jones", "Brown", "Taylor", "Murphy", "Walsh","Ryan", "Anderson" };


    for (int i = 0; i < 8; i++) {
        A[i] = i + 1; // A.setArr(i, i + 1); 
        B[i].setID(i + 1);
        B[i].setName(names[rand() % 8]);
        B[i].setSurname(surnames[rand() % 8]); //there is a error on task file. rand() % 10 should be corrected like this. because array name and surname has only 8 elements.
        B[i].setPhone(1000 + rand() % 9000);
    }

    cout << A << endl << B << endl;


    return 0;
};

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
