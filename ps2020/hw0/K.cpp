//bibliotecas
#include <bits/stdc++.h>

//definindo std como a biblioteca padrão, isso é só para não escrever std:: antes de toda função
using namespace std;

//definindo minha struct
struct Student{
    int age;
    string first_name;
    string last_name;
    int standard;

};

int main(){
    //declaração de variáveis
    Student stu;
    //leitura
    cin >> stu.age >> stu.first_name >> stu.last_name >> stu.standard;
    //saída
    cout << stu.age << " " << stu.first_name << " " << stu.last_name << " " << stu.standard << "\n";
    return 0;
}