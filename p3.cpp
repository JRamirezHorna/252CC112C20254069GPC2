#include <iostream>
using namespace std;

void MostrarNotas(float* N, int size);
void ModificarNotas(float* N, int size, float desv, float vcentral);

int main(){
    float Notas[]={20,8,13,19,17,16,12,0,19,20};
    float promedio;
    float desvestandar;
    float vcentral;

    float size = sizeof(Notas)/sizeof(Notas[0]);
    
    //1. Calcular el promedio y el valor central
    float suma = 0;
    for (int i = 0; i<size;i++){
        suma += *(Notas+i);
    }
    promedio = suma/size;
        //buscar el valor central:
        float minProx = abs(*Notas - promedio);
        vcentral = *Notas;
        for (int i = 0; i<size; i++){
            if (abs(*(Notas+i) - promedio) < minProx){
                minProx = abs(*(Notas+i) - promedio);
                vcentral = *(Notas+i);
            }
        }
    
    //2. Calcular la desviacion estandar:
    float sumac = 0;
    for (int i = 0; i<size;i++){
        sumac += (promedio - *(Notas+i))*(promedio - *(Notas+i));
    }
    desvestandar = sqrt(sumac/(size-1));

    cout<<"Desviacion estandar: "<<desvestandar<<"\t"<<"Valor central: "<<vcentral<<endl;
    cout<<"Notas originales:\n";
    MostrarNotas(Notas,size);
    
    //3. Modificar el arreglo
    ModificarNotas(Notas,size,desvestandar,vcentral);
    cout<<endl<<"Las notas modificadas:\n";
    MostrarNotas(Notas,size);
    return 0;
}

void MostrarNotas(float* N, int size){
    for (int i = 0; i<size; i++){
        cout<<*(N+i)<<"\t";
    }
}

void ModificarNotas(float* N, int size, float desv, float vcentral){
    float delta = desv / 2;
    float max, min;
    max = vcentral + delta;
    min = vcentral - delta;
    for (int i = 0; i<size; i++){
        if (*(N+i) > max || *(N+i) < min){
            *(N+i) = vcentral;
        }
    }
}
