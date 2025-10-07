#include <iostream>
#include <iomanip>
using namespace std;


void Multiplicar(int** p, int* q, int* r, int filp, int colp, int n);
void SumarModq(int* a, int* b, int* r, int q, int n);
void MostrarColumna(int* columna, int n);
void MostrarMatrix(int** p, int fil, int col);
void ColumnaModq(int* a, int n, int q);

int main(){
    int A[4][5]={{4,8,1,5,13},{9,11,2,6,17},{7,12,3,10,15},{14,18,0,16,19}};
    int s[5] = {1, 2, 3, 4, 5};
    int e[4] = {1, 3, 2, 4};
    int b[4];
    int q = 13;
    int temp[4]; //b_i sin ruido (sin mod q);
    float E;

    int* a = &A[0][0];
    int** Aptr = &a;

    //Mostrar datos iniciales: 
    cout<<"La matriz A (4x5):\n";
    MostrarMatrix(Aptr,4,5);
    cout<<endl;
    cout<<"Clave privada s = ";
    MostrarColumna(s,5);
    cout<<endl<<"Ruiedo e = ";
    MostrarColumna(e,4);
    cout<<endl<<"Modulo q = "<<q<<endl;
    cout<<endl;

    //Inciso a)
    Multiplicar(Aptr,s,temp,4,5,5);
    SumarModq(temp,e,b,q,4);
    cout<<"El vector cifrado b = ";
    MostrarColumna(b,4);

    //Inciso b)
    cout<<endl<<"\nVerificacion (b-e)modq = (A*s)_i mod q:\n";
    for (int i = 0; i<4; i++){
        int primero = (*(b+i) - *(e+i))%q;
        int segundo = (*(temp+i))%q;
        if (primero <0) primero += q;
        if (segundo <0) segundo += q;
        cout<<"Fila "<<i<<": (b-e)modq = "<<primero<<", (A*s) = "<<segundo;
        if (primero == segundo) cout<<" Correcto\n";
        else cout<<" Error\n";
    }

    //Inciso c)
    float suma = 0;
    ColumnaModq(temp,4,q);
    for (int i = 0; i<4; i++){
        int g = *(b+i) - *(temp + i);
        if (g > 0){
            suma += g;
        } else{
            suma += (-1)*g;
        }
    }
    E = suma/4;
    cout<<"\nError promedio E = "<<E<<endl;
    return 0;
}

void Multiplicar(int** p, int* q, int* r, int filp, int colp, int n){
    for (int i = 0; i<filp;i++){
        int suma = 0;
        for (int j = 0; j<colp;j++){
            suma += *(*p+n*i+j) * *(q+j);
        }
        *(r+i) = suma;
    }
}

void SumarModq(int* a, int* b, int* r, int q, int n){
    for (int i = 0; i<n; i++){
        *(r+i) = (*(a+i) + *(b+i))%q;
    }
}

void MostrarColumna(int* columna, int n){
    cout<<'[';
    for (int i = 0; i<n; i++){
        cout<<setw(3)<<*(columna+i);
    }
    cout<<']';
}

void MostrarMatrix(int** p, int fil, int col){
    for (int i = 0; i<fil; i++){
        for (int j = 0; j<col; j++){
            cout<<*(*p+col*i+j)<<"\t";
        }
        cout<<endl;
    }
}

void ColumnaModq(int* a, int n, int q){
    for (int i = 0; i<n; i++){
        *(a+i) = (*(a+i) % q);
    }
}