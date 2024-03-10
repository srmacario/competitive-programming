#include <bits/stdc++.h>

using namespace std;
class Avo{
    public:
        virtual ~Avo(){
            cout << "avo morreu :(\n";
        }
};

class MyException{};

class Pai : Avo{
    public:
    virtual ~Pai(){
        throw MyException();
        cout << "pai morreu :(\n";
    }
};

class Filho : Pai{
    public:
    virtual ~Filho(){
        cout << "filho morreu :(\n";
    }
};

void func(){
    Filho A;
    throw MyException();
}

int main(){
    try{
        func();
    }
    catch(MyException e){
        cout << "tratei!\n";
    }
    return 0;
}