#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

//las posiciones empiezan desde 1

const int MAX = 100;
const int MIN = 12;

int EsContrasenaSegura(char* p);
bool estaEnSignos(char c, char* signos);

int main(){
    char password[MAX];
    cout<<"Ingrese una contrasena: ";
    cin.getline(password,MAX,'\n');
    cout<<"Posicion "<<EsContrasenaSegura(password);

    return 0;
}

bool estaEnSignos(char c, char* signos){
    for (int i = 0; i<strlen(signos);i++){
        if (c == *(signos+i)) return true;
    }
    return false;
}

int EsContrasenaSegura(char* p){
    int index = 0;
    char signos[]={'!','@','$','%','^','&','(',')','_','-','+','='};
    //1ra cond
    if (strlen(p) < MIN){
        cout<<"No tiene suficientes caracteres\t";
        return 1;
    }
    else{
        int Mays = 0, mins = 0, nums = 0, sign = 0;
        for (int i = 0; i<strlen(p);i++){
            //2da cond
            if (!isalnum(*(p+i)) && !estaEnSignos(*(p+i), signos)){
                index = i+1;
                cout<<"Caracter no permitido\t";
                return index;
            }
            //3ra cond (despues)
            if (isupper(*(p+i))){
                Mays++;
            } else if(islower(*(p+i))){
                mins++;
            } else if(isdigit(*(p+i))){
                nums++;
            } else if(estaEnSignos(*(p+i), signos)){
                sign++;
            }

            //4ta cond
            if (i>=1 && *(p+i-1) == *(p+i)){
                index = i+1;
                cout<<"Se repite el caracter "<<*(p+i)<<"\t";
                return index;
            }

            //5ta cond
            if (isspace(*(p+i))){
                index = i+1;
                cout<<"Tiene espacio\t";
                return index;
            }

        }
        //cont. 3ra cond
        if (Mays == 0 || mins == 0 || nums == 0 || sign == 0){
            cout<<"No tiene todos los caracteres necesarios\t";
            return 1;
        }
    }
    cout<<"Cumple todas las condiciones\t";
    return index;
}