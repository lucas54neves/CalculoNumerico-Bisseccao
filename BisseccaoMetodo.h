#ifndef BISSECCAOMETODO_H_INCLUDED
#define BISSECCAOMETODO_H_INCLUDED

#include "Util.h"

double myFunctionBisseccao(double x);
void intervensao(double& a, double& b);
double bisseccao(function<double(double)> Funcao, double& a, double& b, double err);
bool criterioParada(double xk, double xk_1, double err);
double bissceccaoValorXk(double a, double b);
double calculaErro(double xk, double xk_1);


double myFunctionBisseccao(double x){

    return (0.9-(1+x+(pow(x,2)/2))*calcEuler(x));

}


void intervensaoBi(double& a, double& b){
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

double bissceccaoValorXk(double a, double b){

    return (a+b)/2.0;
}

double calculaErro(double xk, double xk_1){
    double mErro;
    mErro = (xk - xk_1) / xk;
    if(mErro > 0){
        return mErro;
    }
    else {
        return ((xk - xk_1) / xk) * -1;
    }
}

bool criterioParada(double xk, double xk_1, double err){
    if(xk == 0){
        return false;
    }
return calculaErro(xk,xk_1) < err;
}


double bisseccao(function<double(double)> Funcao, double& a, double& b, double err){
    double xk;
    double xk_1 = 0;
    int k = 0;

    ofstream file;
    file.open("dadosBisscQuestao_1_a.csv");
    file << "Valores do Metodo da Bisseccao. Questao 1-a\n";
    file << "Valor K:,Valor A,Valor B,Valor Xk:,Valor F(Xk):,Erro:\n";


    do{
        xk_1 = xk;
        xk = bissceccaoValorXk(a,b);
        cout <<"-------------------------------------\n";
        cout <<"valor de K:  " << k << endl;
        cout << "valor a:    " << a << endl;
        cout << "valor b:    " << b << endl;
        cout << "valor XK:   " << xk << endl;
        cout << "valor f(xk) " << Funcao(xk) << endl;
        cout << "erro :      "<<calculaErro(xk,xk_1) << endl;

        double res = Funcao(a) * Funcao(xk);
        if(res < 0) {
            b = xk;
        } else if(res > 0){
            a = xk;
        }
        else return xk;

        //GRAVA EM UM ARQUIVO CSV DENTRO DA PASTA DO PROJETO !
        file << k << "," << a << "," << b << "," << xk << "," << Funcao(xk)  << ","
             << calculaErro(xk,xk_1) << "\n";



    k++;
    }while(!criterioParada(xk,xk_1,err));

    cout << "--------------------------" <<endl;

    file << "\n\n" << "VALOR DE X:" << xk;
    file.close();


    return xk;
}






#endif // BISSECCAOMETODO_H_INCLUDED
