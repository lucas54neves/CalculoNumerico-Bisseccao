#include "Util.h"
#include "BisseccaoMetodo.h"


void calculoInicial(double& a, double& b){
    int i =0;
    while(true){
       double arg1 = myFunctionBisseccao(i);
       double arg2 = myFunctionBisseccao(i+1);
        if( (arg1 < 0) && (arg2 > 0) ){
            a = i;
            b = i+1;
            break;
        }
    i++;
   }
}

int main()
{
    float valor_parada;
    valor_parada = 0.00001;
    double a,b;

    cout << "Iniciando Metodo da Bisscecao..." << endl;

   calculoInicial(a,b);
   cout << "I = ["<<a<<","<<b<<"]"<<endl;

   cout << "X: " << bisseccao(myFunctionBisseccao,a,b,valor_parada) << endl << endl;


    return 0;
}
