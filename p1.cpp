#include <iostream>
using namespace std;

const int MAX = 5;


void menu(int** p, int n);
bool esPrimo(int k);
int ContarParesDiagonal(int** p, int n);
int ContarPrimosDiagonal(int** p, int n);
int SumarDebajoDS(int** p, int n);

int main(){
    int n;
    int M[5][5];

    int* p = &M[0][0];
    int** q = &p;

    cout<<"Ingrese el tamano de la matriz cuadrada: ";
    cin>>n;
    while(n <= 0 || n>5){ //verifica que n sea positivo y menor o igual que 5
        cout<<"Error, el tamano debe ser un entero positivo menor o igual a 5.\n";
        cout<<"Ingrese n: ";
        cin>>n;
    }

    cout<<"Ingrese los elementos de la matriz:\n"; //Usuario ingresa los datos
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            cout<<"Elemento M["<<i<<"]["<<j<<"]: ";
            cin>>*(*M + n*i + j);
        }
    }

    //Mostrar la Matriz y las direcciones:
    cout<<"Matriz ingresada y direcciones:\n";
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            cout<<*(*M+n*i+j)<<" ("<<*M+n*i+j<<")"<<"\t";
        }
        cout<<endl;
    }
    menu(q,n);
    return 0;
}

bool esPrimo(int k){
    bool Primo = true;
    if (k==1) return false;
    else{
    for (int i = 2; i<=k/2; i++){
        if (k % i == 0){
            Primo = false;
        }
    }
    return Primo;
    }
}

int ContarPrimosDiagonal(int** p, int n){
    int counter = 0;
    for (int i = 0; i<n; i++){
        if (esPrimo(*(*p+n*i+i))){
            counter++;
        }
    }
    return counter;
}

int ContarParesDiagonal(int** p, int n){
    int counter = 0;
    for (int i = 0; i<n; i++){
        if (*(*p+n*i+i) % 2 == 0){
            counter++;
        }
    }
    return counter;
}

int SumarDebajoDS(int** p, int n){
    int suma = 0;
    for (int i = 0; i<n; i++){
        int j = n-1;
        while(j>(n-i-1)){
            suma += *(*p+n*i+j);
            j--;
        }
    }
    return suma;
}

void menu(int** p, int n){
    int opcion;
    cout<<"Seleccione una operacion:\n";
    cout<<"1. Contar primos\n2. Contar pares en la diagonal principal\n3. Sumar debajo de la diagonal secundaria\n";
    cout<<"Opcion: ";
    cin>>opcion;
    while(opcion <1 || opcion > 3){
        cout<<"Error, intente de nuevo: ";
        cin>>opcion;
    }
    switch(opcion){
        case 1: {
            cout<<"Se encontraron "<<ContarPrimosDiagonal(p,n)<<" primos en la diagonal principal.";
            break;
        }
        case 2:{
            cout<<"Se encontraron "<<ContarParesDiagonal(p,n)<<" numeros pares en la diagonal principal.";
            break;
        }
        case 3:{
            cout<<"La suma de numeros debajo de la diagonal secundaria es "<<SumarDebajoDS(p,n)<<".";
            break;
        }
        default:{
            break;
        }
    }

}