#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(){
int N=5;
    int numeros[5] = {-1,-2,-3,-4,-5};
    int x = VerificarOrdem(numeros, N);
    printf("%d", x);
    return 0;
}
int VerificarOrdem(int v[], int N){
    bool aumenta = false;
    bool diminui = false;

    for(int i=0; i<N-1; i++){
        if(v[i]<v[i+1]){
            aumenta = true;
            diminui = false;

        }else if(v[i]>v[i+1]){
            aumenta=false;
            diminui=true;
        }else{
            return 99;
        }
    }
    if(aumenta==true){
        return 1;
    }else{
        return -1;

    }

}
