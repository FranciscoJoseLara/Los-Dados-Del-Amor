//Código desarrollado por Francisco José Lara

#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

const int DIM=6;

typedef string TDadoAccion[DIM];
typedef string TDadoZona[DIM];
typedef int TCont[DIM];

void DadoAccion(TDadoAccion& da);
void DadoZonaChica(TDadoZona& dz);
void DadoZonaChico(TDadoZona& dz);
void Tirada(unsigned num, unsigned& nda, unsigned& ndz);

int main ()
{
    TDadoAccion da;
    TDadoZona dz;
    string genero;
    char x, y='p';
    unsigned num,nda,ndz;

    do
    {

        do
        {
            system("CLS");
            cout<<"\n\n  |----------- LOS DADOS DEL AMOR -----------|\n\n";
            cout<<"\n\tQuien lanza los dados?\n\t'a' -> La chica \n\t'o' -> El chico: \n\t\t\tOpcion: ";
            getline(cin, genero);
            if(int(genero[1]) != 0)
            {
                genero[0]=y;
            }
        }
        while((genero[0]!='a') && (genero[0]!='o'));
        system("CLS");

        DadoAccion(da);
        if(genero[0]!='o')
        {
            DadoZonaChico(dz);
        }
        else
        {
            DadoZonaChica(dz);
        }
        cout<<"\n\n  |----------- LOS DADOS DEL AMOR -----------|";
        cout<<"\n\n\n\tTU TIRADA! (Escribe un numero) \n\n\t\t";
        cin>>num;
        Tirada(num,nda,ndz);
        system("CLS");
        cout<<"\n\n  |----------- LOS DADOS DEL AMOR -----------|";
        cout<<"\n\n\n\tDebes "<<da[nda]<<" a tu pareja en "<<dz[ndz]<<endl<<endl<<endl<<endl;

        cout<<"\tOtro lanzamiento? (s/n)\n\t\t";
        cin>>x;
        system("CLS");
    }
    while(x!='n');

    return 0;
}

void DadoAccion(TDadoAccion& da)
{
    da[0]="BESAR";
    da[1]="LAMER";
    da[2]="ACARICIAR";
    da[3]="MORDER";
    da[4]="ESTRUJAR";
    da[5]="SOPLAR";
}

void DadoZonaChica(TDadoZona& dz)
{
    dz[0]="MUSLOS";
    dz[1]="PECHOS";
    dz[2]="LABIOS";
    dz[3]="CULO";
    dz[4]="CUELLO";
    dz[5]="CHOCHO";
}

void DadoZonaChico(TDadoZona& dz)
{
    dz[0]="MUSLOS";
    dz[1]="PECHO";
    dz[2]="LABIOS";
    dz[3]="CULO";
    dz[4]="CUELLO";
    dz[5]="PENE";
}

void Tirada(unsigned num, unsigned& nda, unsigned& ndz)
{
    TCont cont;
    unsigned aux,i=0,j;

    cont[0]=2;
    cont[1]=5;
    cont[2]=3;
    cont[3]=4;
    cont[4]=0;
    cont[5]=1;

    nda=num%6;

    if(num>5)
    {
        nda=(num+int('A'))%6;
    }
    else if(num>10)
    {
        nda=(num+int('p'))%6;
    }
    else if(num>100)
    {
        nda=(num+int('Q'))%6;
    }
    else if(num>1000)
    {
        nda=(num+int('z'))%6;
    }

    ndz=cont[nda];
}
