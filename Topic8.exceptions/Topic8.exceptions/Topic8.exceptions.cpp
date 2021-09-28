// Topic8.exceptions.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>
using namespace std;

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
            return string("Stack is Empty");
            break;
        case 2:
            return string("Stack is Full");
            break;
        }
    }
};

template <typename T> class LIPO {
private:
    int depth;
    int po;
    T* stack;
public:
    LIPO(int dep) {
        this->depth = dep;
        stack = new T[this->depth];
        po = 0;
    }
    ~LIPO() {
        delete[] stack;
    }
    LIPO(const LIPO& lipo) {
        depth = lipo.depth;
        po = lipo.po;
        stack = new T[depth];
        for (int i = 0; i < depth; i++) stack[i] = lipo.stack[i];
    }

    void show() {
        for (int i = 0; i < po; i++) {
            cout << stack[i] << " ";
        }
        printf("\n");
    }

    void pop() {
        if (po <= 0 ) {
            throw (Exception(1));
        }
        
        else {
            cout << "Remove " << stack[po - 1] << endl;
            po--;
        }
        
        
    }
    void push(T data) {
        if (po < depth) {
            stack[po] = data;
            po++;
            
        }
        else {
            throw (Exception(2));
        }
    }
};

template <typename G>
void RunStack(LIPO<G> mystack) {
    while (true) {
        int m;
        G data;
        cout << "\n" << "-----menu-----\n" << "     0.exit\n" << "     1.push\n" << "     2.pop\n" << "     3.show" << endl;
        cout << "Select menu : ";
        cin >> m;

        switch (m) {
        case 0:
            break;
        case  1:
            cout << "Input data : ";
            cin >> data;
            try {
             mystack.push(data);
            }
            catch (Exception & e) {
                cout << "Exception caught: " << e.Message_CS() << endl;
            }
            break;
        case 2:
            try {
             mystack.pop();
            }
            catch (Exception &e) {
                cout << "Exception caught: "<< e.Message_CS() << endl;
            }
            break;
        case 3:
            mystack.show();
            break;
        }

        if (m == 0) break;
    }

}


int main()
{
    int datatype;
    int dep;

    cout << "Input the stack depth : ";
    cin >> dep;
    cout << endl;

    cout << "Choose the data type \n" << "1.int\n" << "2.char\n" << "3.double" << endl;
    cin >> datatype;
    cout << endl;

    switch (datatype) {
    case 1:
    {LIPO <int> mstack(dep);
    RunStack(mstack);
    break; }
    case 2:
    { LIPO <char> mstack(dep);
    RunStack(mstack);
    break; }
    case 3:
    { LIPO <double> mstack(dep);
    RunStack(mstack);
    break; }

    }

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
