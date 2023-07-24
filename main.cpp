//FEITO POR LUCAS HARADA

#include <iostream>
#include <complex>

using namespace std;




int main()
{   //CRIACAO DAS VARIAVEIS
    complex<double> Zcarga[3][3] = {0};
    complex<double>Zlinha[3][3] = {0};
    complex<double> Ymatriz[3][3] = {0};
    complex<double> Vmatriz[3][1] = {0};
    complex<double> Imatriz[3][1] = {0};
    complex<double> Temp[3][3] = {0};
    complex<double> Inverso[3][3] = {0};
    complex<double> M1[3][3] = {0};
    complex<double> M2[3][3] = {0};
    complex<double> Za,Zb,Zc, Ya, Yb, Yc, Ytotal;
    complex<double> var1(1,0);






    cout << "Digite os valores z Carga, Za Zb e Zc em ordem-se tiver parte imaginaria escreva em (real,imag)" << endl;

    cin >> Za>>Zb>>Zc;
    //VALORES DA MATRIZ ZCARGA E DE Y DEFINIDOS
    Zcarga[0][0] = Za;
    Zcarga[1][1] = Zb;
    Zcarga[2][2] = Zc;

    Ya = var1/Za;
    Yb = var1/Zb;
    Yc = var1/Zc;

    Ytotal = Ya +Yb +Yc;
    //CRIACAO MATRIZ Yt
    for(int i =0; i <= 2; i++){
        Ymatriz[i][0] = -Ya/Ytotal;
        Ymatriz[i][1] = -Yb/Ytotal;
        Ymatriz[i][2] = -Yc/Ytotal;
        Ymatriz[i][i] = Ymatriz[i][i] + var1; // Ytotal/Ytotal = 1

    }


    cout<< "Digite os valores Z das linhas, Zpa Zpb e Zpc em ordem- Se tiver parte imaginaria escreva em (real,imag) " << endl;

    for(int i = 0; i<= 2; i++)
        cin>> Zlinha[i][i];  //Valores Zp implementados


cout<< "Digite os valores Z das Mutuas, ZMab ZMca e ZMbc em ordem- Se tiver parte imaginaria escreva em (real,imag))" << endl;
    cin>> Zlinha[0][1];
    Zlinha[1][0]= Zlinha[0][1];

    cin>> Zlinha[0][2];
    Zlinha[2][0]= Zlinha[0][2];

    cin>> Zlinha[1][2];
    Zlinha[2][1]= Zlinha[1][2];




    //MATRIZ INTERMEDIARIA PRA FAZER CONTA DE INVERSÃO:
       for(int i = 0; i<=2;i++){
     for(int j = 0; j<= 2; j++){
        for (int k = 0; k<= 2; k++)
            M1[i][j] = M1[i][j]+ Ymatriz[i][k] * Zlinha[k][j];
     }}



    for(int i = 0; i<= 2; i++){
        for(int j = 0; j<= 2; j++)
            Temp[i][j] = Zcarga[i][j] +M1[i][j];
    }

//======================================================================================================================




   // Calculo de matriz inversa
complex<double> det = Temp[0][0] * (Temp[1][1] * Temp[2][2] - Temp[2][1] * Temp[1][2]) -
             Temp[0][1] * (Temp[1][0] * Temp[2][2] - Temp[1][2] * Temp[2][0]) +
             Temp[0][2] * (Temp[1][0] * Temp[2][1] - Temp[1][1] * Temp[2][0]) ;

complex<double> invdet = var1 / det;


Inverso[0][0] = (Temp[1][1] * Temp[2][2] - Temp[2][1] * Temp[1][2]) * invdet;
Inverso[0][1] = (Temp[0][2] * Temp[2][1] - Temp[0][1] * Temp[2][2]) * invdet;
Inverso[0][2] = (Temp[0][1] * Temp[1][2] - Temp[0][2] * Temp[1][1]) * invdet;
Inverso[1][0] = (Temp[1][2] * Temp[2][0] - Temp[1][0] * Temp[2][2]) * invdet;
Inverso[1][1] = (Temp[0][0] * Temp[2][2] - Temp[0][2] * Temp[2][0]) * invdet;
Inverso[1][2] = (Temp[1][0] * Temp[0][2] - Temp[0][0] * Temp[1][2]) * invdet;
Inverso[2][0] = (Temp[1][0] * Temp[2][1] - Temp[2][0] * Temp[1][1]) * invdet;
Inverso[2][1] = (Temp[2][0] * Temp[0][1] - Temp[0][0] * Temp[2][1]) * invdet;
Inverso[2][2] = (Temp[0][0] * Temp[1][1] - Temp[1][0] * Temp[0][1]) * invdet;




// Calculo da inversa *Ytotal

for(int i = 0; i<=2;i++){
    for(int j = 0; j<= 2; j++){
        for (int k = 0; k<= 2; k++)
            M2[i][j] = M2[i][j]+ Inverso[i][k] * Ymatriz[k][j];
}}

cout<<  "Digite os valores das V de fase dos geradores Van, Vbn e Vcn em ordem- Se tiver parte imaginaria escreva em (real,imag) : "<<endl;
cin>> Vmatriz[0][0]>>Vmatriz[1][0]>>Vmatriz[2][0];


//Calculo de I = M2*Vn
   for(int i = 0; i<=2;i++){
        for (int k = 0; k<= 2; k++)
            Imatriz[i][0] = Imatriz[i][0]+ M2[i][k] * Vmatriz[k][0];
     }


//Print de Zcarga
  cout<<endl;
  cout<<"Print de Zcarga:"<<endl;
  for (int i =0; i<=2;i++){
    for(int j=0; j<=2;j++)
        cout<<Zcarga[i][j]<<" ";
    cout<<endl;
  }
cout<<endl;
//=======================================================================================================================
  cout<<"Print de Zlinha:"<<endl;
  for (int i =0; i<=2;i++){
    for(int j=0; j<=2;j++)
        cout<<Zlinha[i][j]<<" ";
    cout<<endl;
  }
cout<<endl;
//=======================================================================================================================
cout<<"MODULO DAS TENSOES INSERIDAS"<<endl;
for(int i =0; i<=2; i++)
    cout<<"V"<<i+1<<" = "<<abs(Vmatriz[i][0])<<", ";
    cout<<endl;
//=======================================================================================================================
cout<<endl;
 cout<<"PRINT DAS CORRENTES "<<endl;
  for(int i = 0 ; i<= 2; i++){
    cout<< "I"<<i+1<< " = " << Imatriz[i][0]<<endl;
  }
    return 0;
}
