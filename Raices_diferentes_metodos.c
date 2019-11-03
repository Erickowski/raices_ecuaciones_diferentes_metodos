#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include <time.h>
#define pf printf
#define sf scanf
#define MAX 10
#define EULER 2.718281828

void BisEcuVar(int);
float Con[MAX];
int i,opc;
float j=0;
char Porciento='%';
time_t rawtime;

int menu(void)
{
    int opc;
    time (&rawtime);
    pf("\t\t\t\t\t %s",ctime (&rawtime));
    pf("\t\tBienvenido\n");
    pf("\t\tMetodos Numericos\n");
    pf("\t\tISC F-33\n");
    pf("\t\tHecho por:\n");
    pf("\t\tErick Daniel Perez Mata\n");
    pf("\tEscoja un metodo:\n");
    pf("\t1) Biseccion\n");
    pf("\t2) Newton-Rhapson\n");
    pf("\t3) Regla falsa\n");
    pf("\t4) Salir\n\t");
    sf("%i",&opc);
    if(opc<1||opc>4)
    {
        pf("\tOpcion no valida\n");
        system("pause");
    }
    return opc;
}

int menu2(void)
{
    int x;
    system("cls");
    pf("\n\tFuncion:\n");
    pf("\t1) Algebraica\n");
    pf("\t2) Trigonometrica\n");
    pf("\t3) Exponencial\n");
    pf("\t4) Logaritmica\n\t");
    sf("%i",&x);
    if(x<1||x>4)
    {
        pf("\tOpcion no valida\n");
        system("pause");
    }
}

int menu3(void)
{
    int x;
    system("cls");
    pf("\n\tFuncion trigonometrica:\n");
    pf("\t1) Seno\n");
    pf("\t2) Coseno\n");
    pf("\t3) Tangente\n\t");
    sf("%i",&x);
    if(x<1||x>3)
    {
        pf("\tOpcion no valida\n");
        system("pause");
    }
}

int menu4(void)
{
    int x;
    system("cls");
    pf("\n\tFuncion exponencial:\n");
    pf("\t1) Constante euler\n");
    pf("\t2) Constante exponencial\n");
    sf("%i",&x);
    if(x<1||x>2)
    {
        pf("\tOpcion no valida\n");
        system("pause");
    }
}

int menu5(void)
{
    int x;
    system("cls");
    pf("\n\tFuncion logaritmica:\n");
    pf("\t1) Logaritmo natural\n");
    pf("\t2) Logaritmo base 10\n");
    sf("%i",&x);
    if(x<1||x>2)
    {
        pf("\tOpcion no valida\n");
        system("pause");
    }
}

void mapa(int opc,int opd,int opb, int ope,int opf)
{
    switch(opc)
    {
    case 1:
        pf("\tMetodo de biseccion\n");
        break;
    case 2:
        pf("\tMetodo de Newton-Rhapson\n");
        break;
    case 3:
        pf("\tMetodo de la regla falsa\n");
        break;
    }
    switch(opb)
    {
    case 1:
        pf("\tFuncion algebraica\n\n");
        break;
    case 2:
        pf("\tFuncion trigonometrica\n");
        break;
    case 3:
        pf("\tFuncion exponencial \n");
        break;
    case 4:
        pf("\tFuncion logaritmica\n");
        break;
    }
    switch(opd)
    {
    case 1:
        pf("\tFuncion seno\n\n");
        break;
    case 2:
        pf("\tFuncion coseno\n\n");
        break;
    case 3:
        pf("\tFuncion tangente\n\n");
        break;
    }
    switch(ope)
    {
    case 1:
        pf("\tFuncion e exponencial\n\n");
        break;
    case 2:
        pf("\tFuncion constante exponencial\n\n");
        break;
    }
    switch(opf)
    {
    case 1:
        pf("\tFuncion logaritmica natural\n\n");
        break;
    case 2:
        pf("\tFuncion logaritmica base 10\n\n");
        break;
    }

}

int biseccion(void)
{
    int pot;
    pf("\tGrado mayor de la expresion: \n\t");
    sf("%i",&pot);
    return pot;
}

void BisEcuVar(int x)
{
    for(i=0; i<x; i++)
    {
        pf("\tConstante de X^%i: ",x-i);
        sf("%f",&Con[x-i]);
    }
}

void BisEcuCon(void)
{
    pf("\tValor de la constante: ");
    sf("%f",&Con[0]);
}

void ecuacion(int x)
{
    pf("\tSu ecuacion es:\n \tf(x) = ");
    for(i=0; i<x; i++)
    {
        if(Con[x-i]>1||Con[x-i]<0) pf("%.2fX^%i",Con[x-i],x-i);
        else
        {
            if(Con[x-i]==1) pf("X^%i",x-i);
            else
            {
                if(Con[x-i]==0)
                {
                    pf("");
                }
                else pf("%.2fX^%i",Con[x-i],x-i);
            }
        }
        if(Con[x-i-1]>0&&Con[x-i]!=0) pf("+");
    }
    if(Con[0]>=1) pf("+%.2f\n",Con[0]);
    else
    {
        if(Con[0]==0) pf("\n");
        else pf("%.2f\n",Con[0]);
    }
}

void EcuTri (int opd)
{
    switch(opd)
    {
    case 1:
        pf("\tSu ecuacion es:\n");
        pf("\t f(x) = %.3f sen (x)",Con[2]);
        if(Con[1]>=0) pf("+");
        pf("%.3f x",Con[1]);
        if(Con[0]>=0) pf("+");
        pf("%.3f \n",Con[0]);
        break;
    case 2:
        pf("\tSu ecuacion es:\n");
        pf("\t f(x) = %.3f cos (x)",Con[2]);
        if(Con[1]>=0) pf("+");
        pf("%.3f x",Con[1]);
        if(Con[0]>=0) pf("+");
        pf("%.3f \n",Con[0]);
        break;
    case 3:
        pf("\tSu ecuacion es:\n");
        pf("\t f(x) = %.3f tan (x)",Con[2]);
        if(Con[1]>=0) pf("+");
        pf("%.3f x",Con[1]);
        if(Con[0]>=0) pf("+");
        pf("%.3f \n",Con[0]);
        break;
    default:
        break;
    }
}

void EcuTriDer (int opd)
{
    switch(opd)
    {
    case 1:
        pf("\tSu derivada es:\n");
        pf("\t f'(x) = %.3f cos (x)",Con[2]);
        if(Con[1]>=0) pf("+");
        pf("%.3f \n",Con[1]);
        break;
    case 2:
        pf("\tSu derivada es:\n");
        pf("\t f'(x) = %.3f sen (x)",(-1)*Con[2]);
        if(Con[1]>=0) pf("+");
        pf("%.3f \n",Con[1]);
        break;
    case 3:
        pf("\tSu derivada es:\n");
        pf("\t f'(x) = %.3f sec^2 (x)",Con[2]);
        if(Con[1]>=0) pf("+");
        pf("%.3f \n",Con[1]);
        break;
    default:
        break;
    }
}

float EvaEcuTri (int opd,float I1)
{
    switch(opd)
    {
    case 1:
        return (Con[2]*sin(I1))+(Con[1]*I1)+Con[0];
        break;
    case 2:
        return (Con[2]*cos(I1))+(Con[1]*I1)+Con[0];
        break;
    case 3:
        return (Con[2]*tan(I1))+(Con[1]*I1)+Con[0];
        break;
    default:
        break;
    }
}

float EvaEcuTriDer (int opd,float I1)
{
    switch(opd)
    {
    case 1:
        return (Con[2]*cos(I1))+Con[1];
        break;
    case 2:
        return ((((-1)*Con[2]))*sin(I1))+Con[1];
        break;
    case 3:
        return (Con[2]*pow((1/cos(I1)),2))+Con[1];
        break;
    default:
        break;
    }
}

float FXactual(float I1,float I2)
{
    return (I1+I2)/2;
}

float ErrorPor(float Xr,float I1)
{
    return ((Xr-I1)/Xr)*100;
}

float EvaEcu(float Xr,int x)
{
    float z=0,w=0,a=0;
    for(i=0; i<x; i++)
    {
        w=pow(Xr,x-i);
        a=Con[x-i]*w;
        z+=a;
    }
    z+=Con[0];
    return z;
}

void EcuExp (int ope)
{
    switch(ope)
    {
    case 1:
        pf("Su ecuacion es: ");
        pf("\t f(x) = %.3f e^x",Con[2]);
        if(Con[1]>=0) pf("+");
        pf("%.3f x",Con[1]);
        if(Con[0]>=0) pf("+");
        pf("%.3f \n",Con[0]);
        break;
    case 2:
        pf("Su ecuacion es: ");
        pf("\t f(x) = %.3f (%.3f^x)",Con[2],j);
        if(Con[1]>=0) pf("+");
        pf("%.3f x",Con[1]);
        if(Con[0]>=0) pf("+");
        pf("%.3f \n",Con[0]);
        break;
    }
}

void EcuExpDer (int ope)
{
    switch(ope)
    {
    case 1:
        pf("Su derivada es: ");
        pf("\t f'(x) = %.3f e^x",Con[2]);
        if(Con[1]>=0) pf("+");
        pf("%.3f \n",Con[1]);
        break;
    case 2:
        pf("Su derivada es: ");
        pf("\t f'(x) = %.3f (ln %.3f) %.3f^x",Con[2],Con[2],j);
        if(Con[1]>=0) pf("+");
        pf("%.3f \n",Con[1]);
        break;
    }
}

float EvaEcuExp (int ope,float x2,float j)
{
    switch(ope)
    {
    case 1:
        return Con[2]*(pow(EULER,x2))+(Con[1]*x2)+Con[0];
        break;
    case 2:
        return Con[2]*pow(j,x2)+(Con[1]*x2)+Con[0];
        break;
    }
}

float EvaEcuExpDer (int ope,float x2,float j)
{
    switch(ope)
    {
    case 1:
        return (Con[2]*pow(EULER,x2))+Con[1];
        break;
    case 2:
        return (Con[2]*pow(j,x2))+Con[1];
        break;
    }
}

void EcuLog (int opf)
{
    switch(opf)
    {
    case 1:
        pf("Su ecuacion es: ");
        pf("\t f(x) = %.3f ln(x)",Con[1]);
        if(Con[0]>=0) pf("+");
        pf("%.3f x\n",Con[0]);
        break;
    case 2:
        pf("Su ecuacion es: ");
        pf("\t f(x) = %.3f log(x)",Con[1]);
        if(Con[0]>=0) pf("+");
        pf("%.3f x\n",Con[0]);
        break;
    }
}

float EvaEcuLog (int opf,float x)
{
    switch(opf)
    {
    case 1:
        return (Con[1]*log(x))+Con[0]*x;
    case 2:
        return (Con[1]*log10(x))+Con[0]*x;
        break;
    }
}

void EcuAlgDer(int x)
{
    pf("\tSu derivada es:\n \tf'(x) = ");
    for(i=0; i<x-1; i++)
    {
        if((Con[x-i]*(x-i))>1||(Con[x-i]*(x-i))<0) pf("%.2fX^%i",Con[x-i]*(x-i),(x-i)-1);
        else
        {
            if((Con[x-i]*(x-i))==1) pf("X^%i",x-i);
            else
            {
                if((Con[x-i]*(x-i))==0)
                {
                    pf(" ");
                }
                else pf("%.2fX^%i",Con[x-i],x-i);
            }
        }
        if(Con[x-i-1]>0&&Con[x-i]!=0) pf("+");
    }
    if(Con[1]>=1) pf("+%.2f\n",Con[1]);
    else
    {
        if(Con[1]==0) pf("\n");
        else pf("%.2f\n",Con[1]);
    }
}

float EvaEcuAlg(float I1,int x)
{
    float z=0,w=0,a=0;
    for(i=0; i<x; i++)
    {
        w=pow(I1,x-i);
        a=Con[x-i]*w;
        z+=a;
    }
    z+=Con[0];
    return z;
}

float EvaEcuAlgDer(float I1,int x)
{
    float z=0,w=0,a=0,b=0;
    for(i=0; i<x-1; i++)
    {
        time_t rawtime;
        z=pow(I1,x-i-1);
        b=(Con[x-i])*(x-i);
        w=b*z;
        a+=w;
    }
    time_t rawtime;
    a+=Con[1];
    return a;
}

int main(void)
{
    int x,y=1,opz,opb,opd,ope,opf;
    float I1=0,I2=0,Xr,ErrPor;
    float u,v,p,x2;
    do
    {
        opc=menu();
        system("cls");
        switch(opc)
        {
        case 1:
            //Biseccion
            do
            {
                opb=menu2();
            }
            while(opb<1||opb>4);
            switch(opb)
            {
            case 1:
                system("cls");
                mapa(opc,opd,opb,ope,opf);
                x=biseccion();
                BisEcuVar(x);
                BisEcuCon();
                system("cls");
                ecuacion(x);
                pf("\tIntervalo inferior: \n\t");
                sf("%f",&I1);
                pf("\tIntervalo superior: \n\t");
                sf("%f",&I2);
                pf("\t%i Iteracion\n",y);
                pf("\tXa = %.3f \n\tXb = %.3f \n",I1,I2);
                Xr=FXactual(I1,I2);
                pf("\tXr = %.3f\n",Xr);
                v=EvaEcu(I1,x);
                u=EvaEcu(Xr,x);
                pf("\tf(Xr)*f(Xa) = %.3f\n",u*v);
                if(u*v>0) I1=Xr;
                else I2=Xr;
                y++;
                system("pause");
                do
                {
                    pf("\t%i Iteracion\n",y);
                    pf("\tXa = %.3f \n \tXb = %.3f \n",I1,I2);
                    Xr=FXactual(I1,I2);
                    pf("\tXr = %.3f\n",Xr);
                    ErrPor=ErrorPor(Xr,I1);
                    pf("\tEP = %.3f %c \n",ErrPor,Porciento);
                    v=EvaEcu(I1,x);
                    u=EvaEcu(Xr,x);
                    pf("\tf(Xr)*f(Xa) = %.3f\n",u*v);
                    if(u*v>0) I1=Xr;
                    else I2=Xr;
                    y++;
                    pf("\t �Seguir iterando? 1=Si 0=No");
                    sf("%i",&opz);
                }
                while(opz==1);
                system("cls");
                break;
            case 2:
            {
                opd=menu3();
            }
            while(opd<1||opd>3);
            switch(opd)
            {
            case 1:
                system("cls");
                mapa(opc,opd,opb,ope,opf);
                pf("\tConstante de sen: ");
                sf("%f",&Con[2]);
                pf("\tConstante de x: ");
                sf("%f",&Con[1]);
                pf("\tValor de la constante: ");
                sf("%f",&Con[0]);
                system("cls");
                EcuTri(opd);
                pf("\tIntervalo inferior: \n\t");
                sf("%f",&I1);
                pf("\tIntervalo superior: \n\t");
                sf("%f",&I2);
                pf("\t%i Iteracion\n",y);
                pf("\tXa = %.3f \n\tXb = %.3f \n",I1,I2);
                Xr=FXactual(I1,I2);
                pf("\tXr = %.3f\n",Xr);
                v=EvaEcuTri(opd,I1);
                u=EvaEcuTri(opd,Xr);
                pf("\tf(Xr)*f(Xa) = %f\n",u*v);
                if(u*v>0) I1=Xr;
                else I2=Xr;
                y++;
                system("pause");
                do
                {
                    pf("\t%i Iteracion\n",y);
                    pf("\tXa = %.3f \n \tXb = %.3f \n",I1,I2);
                    Xr=FXactual(I1,I2);
                    pf("\tXr = %.3f\n",Xr);
                    ErrPor=ErrorPor(Xr,I1);
                    pf("\tEP = %.3f %c \n",ErrPor,Porciento);
                    v=EvaEcuTri(opd,I1);
                    u=EvaEcuTri(opd,Xr);
                    pf("\tf(Xr)*f(Xa) = %f\n",u*v);
                    if(u*v>0) I1=Xr;
                    else I2=Xr;
                    y++;
                    pf("\t�Seguir iterando? 1=Si 0=No");
                    sf("%i",&opz);
                }
                while(opz==1);
                system("cls");
                break;
            case 2:
                system("cls");
                mapa(opc,opd,opb,ope,opf);
                pf("\tConstante de cos: ");
                sf("%f",&Con[2]);
                pf("\tConstante de x: ");
                sf("%f",&Con[1]);
                pf("\tValor de la constante: ");
                sf("%f",&Con[0]);
                system("cls");
                EcuTri(opd);
                pf("\tIntervalo inferior: \n\t");
                sf("%f",&I1);
                pf("\tIntervalo superior: \n\t");
                sf("%f",&I2);
                pf("\t%i Iteracion\n",y);
                pf("\tXa = %.3f \n\tXb = %.3f \n",I1,I2);
                Xr=FXactual(I1,I2);
                pf("\tXr = %.3f\n",Xr);
                v=EvaEcuTri(opd,I1);
                u=EvaEcuTri(opd,Xr);
                pf("\tf(Xr)*f(Xa) = %f\n",u*v);
                if(u*v>0) I1=Xr;
                else I2=Xr;
                y++;
                system("pause");
                do
                {
                    pf("\t%i Iteracion\n",y);
                    pf("\tXa = %.3f \n \tXb = %.3f \n",I1,I2);
                    Xr=FXactual(I1,I2);
                    pf("\tXr = %.3f\n",Xr);
                    ErrPor=ErrorPor(Xr,I1);
                    pf("\tEP = %.3f %c \n",ErrPor,Porciento);
                    v=EvaEcuTri(opd,I1);
                    u=EvaEcuTri(opd,Xr);
                    pf("\tf(Xr)*f(Xa) = %f\n",u*v);
                    if(u*v>0) I1=Xr;
                    else I2=Xr;
                    y++;
                    pf("\t�Seguir iterando? 1=Si 0=No");
                    sf("%i",&opz);
                }
                while(opz==1);
                system("cls");
                break;
            case 3:
                system("cls");
                mapa(opc,opd,opb,ope,opf);
                pf("\tConstante de tan: ");
                sf("%f",&Con[2]);
                pf("\tConstante de x: ");
                sf("%f",&Con[1]);
                pf("\tValor de la constante: ");
                sf("%f",&Con[0]);
                system("cls");
                EcuTri(opd);
                pf("\tIntervalo inferior: \n\t");
                sf("%f",&I1);
                pf("\tIntervalo superior: \n\t");
                sf("%f",&I2);
                pf("\t%i Iteracion\n",y);
                pf("\tXa = %.3f \n\tXb = %.3f \n",I1,I2);
                Xr=FXactual(I1,I2);
                pf("\tXr = %.3f\n",Xr);
                v=EvaEcuTri(opd,I1);
                u=EvaEcuTri(opd,Xr);
                pf("\tf(Xr)*f(Xa) = %f\n",u*v);
                if(u*v>0) I1=Xr;
                else I2=Xr;
                y++;
                system("pause");
                do
                {
                    pf("\t%i Iteracion\n",y);
                    pf("\tXa = %.3f \n \tXb = %.3f \n",I1,I2);
                    Xr=FXactual(I1,I2);
                    pf("\tXr = %.3f\n",Xr);
                    ErrPor=ErrorPor(Xr,I1);
                    pf("\tEP = %.3f %c \n",ErrPor,Porciento);
                    v=EvaEcuTri(opd,I1);
                    u=EvaEcuTri(opd,Xr);
                    pf("\tf(Xr)*f(Xa) = %f\n",u*v);
                    if(u*v>0) I1=Xr;
                    else I2=Xr;
                    y++;
                    pf("\t�Seguir iterando? 1=Si 0=No");
                    sf("%i",&opz);
                }
                while(opz==1);
                system("cls");
                break;
            default:
                break;
            }
            break;
            case 3:
                do
                {
                    ope=menu4();
                }
                while(ope<1||ope>2);
                switch(ope)
                {
                case 1:
                    system("cls");
                    mapa(opc,opd,opb,ope,opf);
                    pf("Constante de e: ");
                    sf("%f",&Con[2]);
                    pf("Constante de x: ");
                    sf("%f",&Con[1]);
                    pf("\tValor de la constante: ");
                    sf("%f",&Con[0]);
                    system("cls");
                    EcuExp(ope);
                    pf("\tIntervalo inferior: \n\t");
                    sf("%f",&I1);
                    pf("\tIntervalo superior: \n\t");
                    sf("%f",&I2);
                    pf("\t%i Iteracion\n",y);
                    pf("\tXa = %.3f \n\tXb = %.3f \n",I1,I2);
                    Xr=FXactual(I1,I2);
                    pf("\tXr = %.3f\n",Xr);
                    v=EvaEcuExp(ope,I1,j);
                    u=EvaEcuExp(ope,Xr,j);
                    pf("\tf(Xr)*f(Xa) = %.3f\n",u*v);
                    if(u*v>0) I1=Xr;
                    else I2=Xr;
                    y++;
                    system("pause");
                    do
                    {
                        pf("\t%i Iteracion\n",y);
                        pf("\tXa = %.3f \n \tXb = %.3f \n",I1,I2);
                        Xr=FXactual(I1,I2);
                        pf("\tXr = %.3f\n",Xr);
                        ErrPor=ErrorPor(Xr,I1);
                        pf("\tEP = %.3f %c \n",ErrPor,Porciento);
                        v=EvaEcuExp(ope,I1,j);
                        u=EvaEcuExp(ope,Xr,j);
                        pf("\tf(Xr)*f(Xa) = %.3f\n",u*v);
                        if(u*v>0) I1=Xr;
                        else I2=Xr;
                        y++;
                        pf("\t�Seguir iterando? 1=Si 0=No");
                        sf("%i",&opz);
                    }
                    while(opz==1);
                    break;
                case 2:
                    system("cls");
                    mapa(opc,opd,opb,ope,opf);
                    pf("Constante exponencial: ");
                    sf("%f",&j);
                    pf("Constante de %.3f: ",j);
                    sf("%f",&Con[2]);
                    pf("Constante de x: ");
                    sf("%f",&Con[1]);
                    pf("\tValor de la constante: ");
                    sf("%f",&Con[0]);
                    system("cls");
                    EcuExp(ope);
                    pf("\tIntervalo inferior: \n\t");
                    sf("%f",&I1);
                    pf("\tIntervalo superior: \n\t");
                    sf("%f",&I2);
                    pf("\t%i Iteracion\n",y);
                    pf("\tXa = %.3f \n\tXb = %.3f \n",I1,I2);
                    Xr=FXactual(I1,I2);
                    pf("\tXr = %.3f\n",Xr);
                    v=EvaEcuExp(ope,I1,j);
                    u=EvaEcuExp(ope,Xr,j);
                    pf("\tf(Xr)*f(Xa) = %.3f\n",u*v);
                    if(u*v>0) I1=Xr;
                    else I2=Xr;
                    y++;
                    system("pause");
                    do
                    {
                        pf("\t%i Iteracion\n",y);
                        pf("\tXa = %.3f \n \tXb = %.3f \n",I1,I2);
                        Xr=FXactual(I1,I2);
                        pf("\tXr = %.3f\n",Xr);
                        ErrPor=ErrorPor(Xr,I1);
                        pf("\tEP = %.3f %c \n",ErrPor,Porciento);
                        v=EvaEcuExp(ope,I1,j);
                        u=EvaEcuExp(ope,Xr,j);
                        pf("\tf(Xr)*f(Xa) = %.3f\n",u*v);
                        if(u*v>0) I1=Xr;
                        else I2=Xr;
                        y++;
                        pf("\t�Seguir iterando? 1=Si 0=No");
                        sf("%i",&opz);
                    }
                    while(opz==1);
                    break;
                }
                break;
            case 4:
            {
                opf=menu5();
            }
            while(opf<1||opf>2);
            switch(opf)
            {
            case 1:
                system("cls");
                mapa(opc,opd,opb,ope,opf);
                pf("\tConstante de ln: ");
                sf("%f",&Con[1]);
                pf("\tConstante de x: ");
                sf("%f",&Con[0]);
                system("cls");
                EcuLog(opf);
                pf("\tIntervalo inferior: \n\t");
                sf("%f",&I1);
                pf("\tIntervalo superior: \n\t");
                sf("%f",&I2);
                pf("\t%i Iteracion\n",y);
                pf("\tXa = %.3f \n\tXb = %.3f \n",I1,I2);
                Xr=FXactual(I1,I2);
                pf("\tXr = %.3f\n",Xr);
                v=EvaEcuLog(opf,I1);
                u=EvaEcuLog(opf,Xr);
                pf("\tf(Xr)*f(Xa) = %f\n",u*v);
                if(u*v>0) I1=Xr;
                else I2=Xr;
                y++;
                system("pause");
                do
                {
                    pf("\t%i Iteracion\n",y);
                    pf("\tXa = %.3f \n \tXb = %.3f \n",I1,I2);
                    Xr=FXactual(I1,I2);
                    pf("\tXr = %.3f\n",Xr);
                    ErrPor=ErrorPor(Xr,I1);
                    pf("\tEP = %.3f %c \n",ErrPor,Porciento);
                    v=EvaEcuLog(opf,I1);
                    u=EvaEcuLog(opf,Xr);
                    pf("\tf(Xr)*f(Xa) = %.3f\n",u*v);
                    if(u*v>0) I1=Xr;
                    else I2=Xr;
                    y++;
                    pf("\t�Seguir iterando? 1=Si 0=No");
                    sf("%i",&opz);
                }
                while(opz==1);
                system("cls");
                break;
            case 2:
                system("cls");
                mapa(opc,opd,opb,ope,opf);
                pf("\tConstante de log: ");
                sf("%f",&Con[1]);
                pf("\tConstante de x: ");
                sf("%f",&Con[0]);
                system("cls");
                EcuLog(opf);
                pf("\tIntervalo inferior: \n\t");
                sf("%f",&I1);
                pf("\tIntervalo superior: \n\t");
                sf("%f",&I2);
                pf("\t%i Iteracion\n",y);
                pf("\tXa = %.3f \n\tXb = %.3f \n",I1,I2);
                Xr=FXactual(I1,I2);
                pf("\tXr = %.3f\n",Xr);
                v=EvaEcuLog(opf,I1);
                u=EvaEcuLog(opf,Xr);
                pf("\tf(Xr)*f(Xa) = %f\n",u*v);
                if(u*v>0) I1=Xr;
                else I2=Xr;
                y++;
                system("pause");
                do
                {
                    pf("\t%i Iteracion\n",y);
                    pf("\tXa = %.3f \n \tXb = %.3f \n",I1,I2);
                    Xr=FXactual(I1,I2);
                    pf("\tXr = %.3f\n",Xr);
                    ErrPor=ErrorPor(Xr,I1);
                    pf("\tEP = %.3f %c \n",ErrPor,Porciento);
                    v=EvaEcuLog(opf,I1);
                    u=EvaEcuLog(opf,Xr);
                    pf("\tf(Xr)*f(Xa) = %.3f\n",u*v);
                    if(u*v>0) I1=Xr;
                    else I2=Xr;
                    y++;
                    pf("\tSeguir iterando? 1=Si 0=No");
                    sf("%i",&opz);
                }
                while(opz==1);
                system("cls");
                break;
            }
            break;
            default:
                break;
            }
        case 2:
            //Newton-rhapson
            do
            {
                opb=menu2();
            }
            while(opb<1||opb>3);
            switch(opb)
            {
            case 1:
                system("cls");
                mapa(opc,opd,opb,ope,opf);
                x=biseccion();
                BisEcuVar(x);
                BisEcuCon();
                system("cls");
                ecuacion(x);
                EcuAlgDer(x);
                pf("Punto inicial:");
                sf("%f",&I1);
                u=EvaEcuAlg(I1,x);
                v=EvaEcuAlgDer(I1,x);
                p=I1-(u/v);
                I1=p;
                pf("P %i = %f\n",y,p);
                y++;
                system("pause");
                do
                {
                    u=EvaEcuAlg(I1,x);
                    v=EvaEcuAlgDer(I1,x);
                    p=I1-(u/v);
                    I1=p;
                    pf("P %i = %f\n",y,p);
                    y++;
                    pf("\t�Seguir iterando? 1=Si 0=No");
                    sf("%i",&opz);
                }
                while(opz==1);
                break;
            case 2:
            {
                opd=menu3();
            }
            while(opd<1||opd>3);
            switch(opd)
            {
            case 1:
                system("cls");
                mapa(opc,opd,opb,ope,opf);
                pf("\tConstante de sen: ");
                sf("%f",&Con[2]);
                pf("\tConstante de x: ");
                sf("%f",&Con[1]);
                pf("\tValor de la constante: ");
                sf("%f",&Con[0]);
                system("cls");
                EcuTri(opd);
                EcuTriDer(opd);
                pf("Punto inicial:");
                sf("%f",&I1);
                u=EvaEcuTri(opd,I1);
                v=EvaEcuTriDer(opd,I1);
                p=I1-(u/v);
                I1=p;
                pf("P %i = %f\n",y,p);
                y++;
                system("pause");
                do
                {
                    u=EvaEcuTri(opd,I1);
                    v=EvaEcuTriDer(opd,I1);
                    p=I1-(u/v);
                    I1=p;
                    pf("P %i = %f\n",y,p);
                    y++;
                    pf("\t�Seguir iterando? 1=Si 0=No");
                    sf("%i",&opz);
                }
                while(opz==1);
                break;
            case 2:
                system("cls");
                mapa(opc,opd,opb,ope,opf);
                pf("\tConstante de cos: ");
                sf("%f",&Con[2]);
                pf("\tConstante de x: ");
                sf("%f",&Con[1]);
                pf("\tValor de la constante: ");
                sf("%f",&Con[0]);
                system("cls");
                EcuTri(opd);
                EcuTriDer(opd);
                pf("Punto inicial:");
                sf("%f",&I1);
                u=EvaEcuTri(opd,I1);
                v=EvaEcuTriDer(opd,I1);
                p=I1-(u/v);
                I1=p;
                pf("P %i = %f\n",y,p);
                y++;
                system("pause");
                do
                {
                    u=EvaEcuTri(opd,I1);
                    v=EvaEcuTriDer(opd,I1);
                    p=I1-(u/v);
                    I1=p;
                    pf("P %i = %f\n",y,p);
                    y++;
                    pf("\tSeguir iterando? 1=Si 0=No");
                    sf("%i",&opz);
                }
                while(opz==1);
                break;
            case 3:
                system("cls");
                mapa(opc,opd,opb,ope,opf);
                pf("\tConstante de tan: ");
                sf("%f",&Con[2]);
                pf("\tConstante de x: ");
                sf("%f",&Con[1]);
                pf("\tValor de la constante: ");
                sf("%f",&Con[0]);
                system("cls");
                EcuTri(opd);
                EcuTriDer(opd);
                pf("Punto inicial:");
                sf("%f",&x);
                u=EvaEcuTri(opd,I1);
                v=EvaEcuTriDer(opd,I1);
                p=x2-(u/v);
                x2=p;
                pf("P %i = %f\n",y,p);
                y++;
                system("pause");
                do
                {
                    u=EvaEcuTri(opd,I1);
                    v=EvaEcuTriDer(opd,I1);
                    p=I1-(u/v);
                    I1=p;
                    pf("P %i = %f\n",y,p);
                    y++;
                    pf("\t�Seguir iterando? 1=Si 0=No");
                    sf("%i",&opz);
                }
                while(opz==1);
                break;
            }
            break;
            case 3:
                do
                {
                    ope=menu4();
                }
                while(ope<1||ope>2);
                switch(ope)
                {
                case 1:
                    j=0;
                    system("cls");
                    mapa(opc,opd,opb,ope,opf);
                    pf("Constante de e: ");
                    sf("%f",&Con[2]);
                    pf("Constante de x: ");
                    sf("%f",&Con[1]);
                    pf("\tValor de la constante: ");
                    sf("%f",&Con[0]);
                    system("cls");
                    EcuExp(ope);
                    EcuExpDer(ope);
                    pf("Punto inicial:");
                    sf("%f",&x2);
                    u=EvaEcuExp(ope,x2,j);
                    v=EvaEcuExpDer(ope,x2,j);
                    p=x2-(u/v);
                    x2=p;
                    pf("P %i = %f\n",y,p);
                    y++;
                    system("pause");
                    do
                    {
                        u=EvaEcuExp(ope,x2,j);
                        v=EvaEcuExpDer(ope,x2,j);
                        p=x2-(u/v);
                        x2=p;
                        pf("P %i = %f\n",y,p);
                        y++;
                        pf("\t�Seguir iterando? 1=Si 0=No");
                        sf("%i",&opz);
                    }
                    while(opz==1);
                    break;
                case 2:
                    system("cls");
                    mapa(opc,opd,opb,ope,opf);
                    pf("Constante exponencial: ");
                    sf("%f",&j);
                    pf("Constante de %.3f: ",j);
                    sf("%f",&Con[1]);
                    pf("Constante de x: ");
                    sf("%f",&Con[0]);
                    system("cls");
                    EcuExp(ope);
                    pf("\tIntervalo inferior: \n\t");
                    sf("%f",&I1);
                    pf("\tIntervalo superior: \n\t");
                    sf("%f",&I2);
                    pf("\t%i Iteracion\n",y);
                    pf("\tXa = %.3f \n\tXb = %.3f \n",I1,I2);
                    Xr=FXactual(I1,I2);
                    pf("\tXr = %.3f\n",Xr);
                    v=EvaEcuExp(ope,I1,j);
                    u=EvaEcuExp(ope,Xr,j);
                    pf("\tf(Xr)*f(Xa) = %.3f\n",u*v);
                    if(u*v>0) I1=Xr;
                    else I2=Xr;
                    y++;
                    system("pause");
                    do
                    {
                        pf("\t%i Iteracion\n",y);
                        pf("\tXa = %.3f \n \tXb = %.3f \n",I1,I2);
                        Xr=FXactual(I1,I2);
                        pf("\tXr = %.3f\n",Xr);
                        ErrPor=ErrorPor(Xr,I1);
                        pf("\tEP = %.3f %c \n",ErrPor,Porciento);
                        v=EvaEcuExp(ope,I1,j);
                        u=EvaEcuExp(ope,Xr,j);
                        pf("\tf(Xr)*f(Xa) = %.3f\n",u*v);
                        if(u*v>0) I1=Xr;
                        else I2=Xr;
                        y++;
                        pf("\t�Seguir iterando? 1=Si 0=No");
                        sf("%i",&opz);
                    }
                    while(opz==1);
                    break;
                }
                break;
            case 4:
            {
                opf=menu5();
            }
            while(opf<1||opf>2);
            switch(opf)
            {
            case 1:
                system("cls");
                mapa(opc,opd,opb,ope,opf);
                pf("\tConstante de ln: ");
                sf("%f",&Con[1]);
                pf("\tConstante de x: ");
                sf("%f",&Con[0]);
                system("cls");
                EcuLog(opf);
                pf("\tIntervalo inferior: \n\t");
                sf("%f",&I1);
                pf("\tIntervalo superior: \n\t");
                sf("%f",&I2);
                pf("\t%i Iteracion\n",y);
                pf("\tXa = %.3f \n\tXb = %.3f \n",I1,I2);
                Xr=FXactual(I1,I2);
                pf("\tXr = %.3f\n",Xr);
                v=EvaEcuLog(opf,I1);
                u=EvaEcuLog(opf,Xr);
                pf("\tf(Xr)*f(Xa) = %f\n",u*v);
                if(u*v>0) I1=Xr;
                else I2=Xr;
                y++;
                system("pause");
                do
                {
                    pf("\t%i Iteracion\n",y);
                    pf("\tXa = %.3f \n \tXb = %.3f \n",I1,I2);
                    Xr=FXactual(I1,I2);
                    pf("\tXr = %.3f\n",Xr);
                    ErrPor=ErrorPor(Xr,I1);
                    pf("\tEP = %.3f %c \n",ErrPor,Porciento);
                    v=EvaEcuLog(opf,I1);
                    u=EvaEcuLog(opf,Xr);
                    pf("\tf(Xr)*f(Xa) = %.3f\n",u*v);
                    if(u*v>0) I1=Xr;
                    else I2=Xr;
                    y++;
                    pf("\t�Seguir iterando? 1=Si 0=No");
                    sf("%i",&opz);
                }
                while(opz==1);
                system("cls");
                break;
            case 2:
                system("cls");
                mapa(opc,opd,opb,ope,opf);
                pf("\tConstante de log: ");
                sf("%f",&Con[1]);
                pf("\tConstante de x: ");
                sf("%f",&Con[0]);
                system("cls");
                EcuLog(opf);
                pf("\tIntervalo inferior: \n\t");
                sf("%f",&I1);
                pf("\tIntervalo superior: \n\t");
                sf("%f",&I2);
                pf("\t%i Iteracion\n",y);
                pf("\tXa = %.3f \n\tXb = %.3f \n",I1,I2);
                Xr=FXactual(I1,I2);
                pf("\tXr = %.3f\n",Xr);
                v=EvaEcuLog(opf,I1);
                u=EvaEcuLog(opf,Xr);
                pf("\tf(Xr)*f(Xa) = %f\n",u*v);
                if(u*v>0) I1=Xr;
                else I2=Xr;
                y++;
                system("pause");
                do
                {
                    pf("\t%i Iteracion\n",y);
                    pf("\tXa = %.3f \n \tXb = %.3f \n",I1,I2);
                    Xr=FXactual(I1,I2);
                    pf("\tXr = %.3f\n",Xr);
                    ErrPor=ErrorPor(Xr,I1);
                    pf("\tEP = %.3f %c \n",ErrPor,Porciento);
                    v=EvaEcuLog(opf,I1);
                    u=EvaEcuLog(opf,Xr);
                    pf("\tf(Xr)*f(Xa) = %.3f\n",u*v);
                    if(u*v>0) I1=Xr;
                    else I2=Xr;
                    y++;
                    pf("\tSeguir iterando? 1=Si 0=No");
                    sf("%i",&opz);
                }
                while(opz==1);
                system("cls");
                break;
            }
            break;
            default:
                break;
            }
            break;
            break;
        case 3:
            //Regla falsa
            do
            {
                opb=menu2();
            }
            while(opb<1||opb>4);
            switch(opb)
            {
            case 1:
                system("cls");
                mapa(opc,opd,opb,ope,opf);
                x=biseccion();
                BisEcuVar(x);
                BisEcuCon();
                system("cls");
                ecuacion(x);
                pf("\tIntervalo inferior: \n\t");
                sf("%f",&I1);
                pf("\tIntervalo superior: \n\t");
                sf("%f",&I2);
                pf("\t%i Iteracion\n",y);
                pf("\tXa = %.3f \n\tXb = %.3f \n",I1,I2);
                v=EvaEcu(I1,x);
                u=EvaEcu(I2,x);
                Xr=I1-(((v*(I2-I1)))/(u-v));
                p=EvaEcu(Xr,x);
                pf("\tXr = %.3f\n",Xr);
                pf("\tf(Xr)*f(Xa) = %.3f\n",p*v);
                if(p*v>0) I1=Xr;
                else I2=Xr;
                y++;
                system("pause");
                do
                {
                    pf("\t%i Iteracion\n",y);
                    pf("\tXa = %.3f \n \tXb = %.3f \n",I1,I2);
                    v=EvaEcu(I1,x);
                    u=EvaEcu(I2,x);
                    Xr=I1-(((v*(I2-I1)))/(u-v));
                    p=EvaEcu(Xr,x);
                    pf("\tXr = %.3f\n",Xr);
                    ErrPor=ErrorPor(Xr,I1);
                    pf("\tEP = %.3f %c \n",ErrPor,Porciento);
                    pf("\tf(Xr)*f(Xa) = %.3f\n",p*v);
                    if(p*v>0) I1=Xr;
                    else I2=Xr;
                    y++;
                    pf("\t�Seguir iterando? 1=Si 0=No");
                    sf("%i",&opz);
                }
                while(opz==1);
                system("cls");
                break;
            case 2:
            {
                opd=menu3();
            }
            while(opd<1||opd>3);
            switch(opd)
            {
            case 1:
                system("cls");
                mapa(opc,opd,opb,ope,opf);
                pf("\tConstante de sen: ");
                sf("%f",&Con[2]);
                pf("\tConstante de x: ");
                sf("%f",&Con[1]);
                pf("\tValor de la constante: ");
                sf("%f",&Con[0]);
                system("cls");
                EcuTri(opd);
                pf("\tIntervalo inferior: \n\t");
                sf("%f",&I1);
                pf("\tIntervalo superior: \n\t");
                sf("%f",&I2);
                pf("\t%i Iteracion\n",y);
                pf("\tXa = %.3f \n\tXb = %.3f \n",I1,I2);
                Xr=FXactual(I1,I2);
                pf("\tXr = %.3f\n",Xr);
                v=EvaEcuTri(opd,I1);
                u=EvaEcuTri(opd,Xr);
                pf("\tf(Xr)*f(Xa) = %f\n",u*v);
                if(u*v>0) I1=Xr;
                else I2=Xr;
                y++;
                system("pause");
                do
                {
                    pf("\t%i Iteracion\n",y);
                    pf("\tXa = %.3f \n \tXb = %.3f \n",I1,I2);
                    Xr=FXactual(I1,I2);
                    pf("\tXr = %.3f\n",Xr);
                    ErrPor=ErrorPor(Xr,I1);
                    pf("\tEP = %.3f %c \n",ErrPor,Porciento);
                    v=EvaEcuTri(opd,I1);
                    u=EvaEcuTri(opd,Xr);
                    pf("\tf(Xr)*f(Xa) = %f\n",u*v);
                    if(u*v>0) I1=Xr;
                    else I2=Xr;
                    y++;
                    pf("\t�Seguir iterando? 1=Si 0=No");
                    sf("%i",&opz);
                }
                while(opz==1);
                system("cls");
                break;
            case 2:
                system("cls");
                mapa(opc,opd,opb,ope,opf);
                pf("\tConstante de cos: ");
                sf("%f",&Con[2]);
                pf("\tConstante de x: ");
                sf("%f",&Con[1]);
                pf("\tValor de la constante: ");
                sf("%f",&Con[0]);
                system("cls");
                EcuTri(opd);
                pf("\tIntervalo inferior: \n\t");
                sf("%f",&I1);
                pf("\tIntervalo superior: \n\t");
                sf("%f",&I2);
                pf("\t%i Iteracion\n",y);
                pf("\tXa = %.3f \n\tXb = %.3f \n",I1,I2);
                Xr=FXactual(I1,I2);
                pf("\tXr = %.3f\n",Xr);
                v=EvaEcuTri(opd,I1);
                u=EvaEcuTri(opd,Xr);
                pf("\tf(Xr)*f(Xa) = %f\n",u*v);
                if(u*v>0) I1=Xr;
                else I2=Xr;
                y++;
                system("pause");
                do
                {
                    pf("\t%i Iteracion\n",y);
                    pf("\tXa = %.3f \n \tXb = %.3f \n",I1,I2);
                    Xr=FXactual(I1,I2);
                    pf("\tXr = %.3f\n",Xr);
                    ErrPor=ErrorPor(Xr,I1);
                    pf("\tEP = %.3f %c \n",ErrPor,Porciento);
                    v=EvaEcuTri(opd,I1);
                    u=EvaEcuTri(opd,Xr);
                    pf("\tf(Xr)*f(Xa) = %f\n",u*v);
                    if(u*v>0) I1=Xr;
                    else I2=Xr;
                    y++;
                    pf("\t�Seguir iterando? 1=Si 0=No");
                    sf("%i",&opz);
                }
                while(opz==1);
                system("cls");
                break;
            case 3:
                system("cls");
                mapa(opc,opd,opb,ope,opf);
                pf("\tConstante de tan: ");
                sf("%f",&Con[2]);
                pf("\tConstante de x: ");
                sf("%f",&Con[1]);
                pf("\tValor de la constante: ");
                sf("%f",&Con[0]);
                system("cls");
                EcuTri(opd);
                pf("\tIntervalo inferior: \n\t");
                sf("%f",&I1);
                pf("\tIntervalo superior: \n\t");
                sf("%f",&I2);
                pf("\t%i Iteracion\n",y);
                pf("\tXa = %.3f \n\tXb = %.3f \n",I1,I2);
                Xr=FXactual(I1,I2);
                pf("\tXr = %.3f\n",Xr);
                v=EvaEcuTri(opd,I1);
                u=EvaEcuTri(opd,Xr);
                pf("\tf(Xr)*f(Xa) = %f\n",u*v);
                if(u*v>0) I1=Xr;
                else I2=Xr;
                y++;
                system("pause");
                do
                {
                    pf("\t%i Iteracion\n",y);
                    pf("\tXa = %.3f \n \tXb = %.3f \n",I1,I2);
                    Xr=FXactual(I1,I2);
                    pf("\tXr = %.3f\n",Xr);
                    ErrPor=ErrorPor(Xr,I1);
                    pf("\tEP = %.3f %c \n",ErrPor,Porciento);
                    v=EvaEcuTri(opd,I1);
                    u=EvaEcuTri(opd,Xr);
                    pf("\tf(Xr)*f(Xa) = %f\n",u*v);
                    if(u*v>0) I1=Xr;
                    else I2=Xr;
                    y++;
                    pf("\t�Seguir iterando? 1=Si 0=No");
                    sf("%i",&opz);
                }
                while(opz==1);
                system("cls");
                break;
            default:
                break;
            }
            break;
            case 3:
                do
                {
                    ope=menu4();
                }
                while(ope<1||ope>2);
                switch(ope)
                {
                case 1:
                    system("cls");
                    mapa(opc,opd,opb,ope,opf);
                    pf("Constante de e: ");
                    sf("%f",&Con[2]);
                    pf("Constante de x: ");
                    sf("%f",&Con[1]);
                    pf("\tValor de la constante: ");
                    sf("%f",&Con[0]);
                    system("cls");
                    EcuExp(ope);
                    pf("\tIntervalo inferior: \n\t");
                    sf("%f",&I1);
                    pf("\tIntervalo superior: \n\t");
                    sf("%f",&I2);
                    pf("\t%i Iteracion\n",y);
                    pf("\tXa = %.3f \n\tXb = %.3f \n",I1,I2);
                    Xr=FXactual(I1,I2);
                    pf("\tXr = %.3f\n",Xr);
                    v=EvaEcuExp(ope,I1,j);
                    u=EvaEcuExp(ope,Xr,j);
                    pf("\tf(Xr)*f(Xa) = %.3f\n",u*v);
                    if(u*v>0) I1=Xr;
                    else I2=Xr;
                    y++;
                    system("pause");
                    do
                    {
                        pf("\t%i Iteracion\n",y);
                        pf("\tXa = %.3f \n \tXb = %.3f \n",I1,I2);
                        Xr=FXactual(I1,I2);
                        pf("\tXr = %.3f\n",Xr);
                        ErrPor=ErrorPor(Xr,I1);
                        pf("\tEP = %.3f %c \n",ErrPor,Porciento);
                        v=EvaEcuExp(ope,I1,j);
                        u=EvaEcuExp(ope,Xr,j);
                        pf("\tf(Xr)*f(Xa) = %.3f\n",u*v);
                        if(u*v>0) I1=Xr;
                        else I2=Xr;
                        y++;
                        pf("\t�Seguir iterando? 1=Si 0=No");
                        sf("%i",&opz);
                    }
                    while(opz==1);
                    break;
                case 2:
                    system("cls");
                    mapa(opc,opd,opb,ope,opf);
                    pf("Constante exponencial: ");
                    sf("%f",&j);
                    pf("Constante de %.3f: ",j);
                    sf("%f",&Con[2]);
                    pf("Constante de x: ");
                    sf("%f",&Con[1]);
                    pf("\tValor de la constante: ");
                    sf("%f",&Con[0]);
                    system("cls");
                    EcuExp(ope);
                    pf("\tIntervalo inferior: \n\t");
                    sf("%f",&I1);
                    pf("\tIntervalo superior: \n\t");
                    sf("%f",&I2);
                    pf("\t%i Iteracion\n",y);
                    pf("\tXa = %.3f \n\tXb = %.3f \n",I1,I2);
                    Xr=FXactual(I1,I2);
                    pf("\tXr = %.3f\n",Xr);
                    v=EvaEcuExp(ope,I1,j);
                    u=EvaEcuExp(ope,Xr,j);
                    pf("\tf(Xr)*f(Xa) = %.3f\n",u*v);
                    if(u*v>0) I1=Xr;
                    else I2=Xr;
                    y++;
                    system("pause");
                    do
                    {
                        pf("\t%i Iteracion\n",y);
                        pf("\tXa = %.3f \n \tXb = %.3f \n",I1,I2);
                        Xr=FXactual(I1,I2);
                        pf("\tXr = %.3f\n",Xr);
                        ErrPor=ErrorPor(Xr,I1);
                        pf("\tEP = %.3f %c \n",ErrPor,Porciento);
                        v=EvaEcuExp(ope,I1,j);
                        u=EvaEcuExp(ope,Xr,j);
                        pf("\tf(Xr)*f(Xa) = %.3f\n",u*v);
                        if(u*v>0) I1=Xr;
                        else I2=Xr;
                        y++;
                        pf("\t�Seguir iterando? 1=Si 0=No");
                        sf("%i",&opz);
                    }
                    while(opz==1);
                    break;
                }
                break;
            case 4:
            {
                opf=menu5();
            }
            while(opf<1||opf>2);
            switch(opf)
            {
            case 1:
                system("cls");
                mapa(opc,opd,opb,ope,opf);
                pf("\tConstante de ln: ");
                sf("%f",&Con[1]);
                pf("\tConstante de x: ");
                sf("%f",&Con[0]);
                system("cls");
                EcuLog(opf);
                pf("\tIntervalo inferior: \n\t");
                sf("%f",&I1);
                pf("\tIntervalo superior: \n\t");
                sf("%f",&I2);
                pf("\t%i Iteracion\n",y);
                pf("\tXa = %.3f \n\tXb = %.3f \n",I1,I2);
                Xr=FXactual(I1,I2);
                pf("\tXr = %.3f\n",Xr);
                v=EvaEcuLog(opf,I1);
                u=EvaEcuLog(opf,Xr);
                pf("\tf(Xr)*f(Xa) = %f\n",u*v);
                if(u*v>0) I1=Xr;
                else I2=Xr;
                y++;
                system("pause");
                do
                {
                    pf("\t%i Iteracion\n",y);
                    pf("\tXa = %.3f \n \tXb = %.3f \n",I1,I2);
                    Xr=FXactual(I1,I2);
                    pf("\tXr = %.3f\n",Xr);
                    ErrPor=ErrorPor(Xr,I1);
                    pf("\tEP = %.3f %c \n",ErrPor,Porciento);
                    v=EvaEcuLog(opf,I1);
                    u=EvaEcuLog(opf,Xr);
                    pf("\tf(Xr)*f(Xa) = %.3f\n",u*v);
                    if(u*v>0) I1=Xr;
                    else I2=Xr;
                    y++;
                    pf("\t�Seguir iterando? 1=Si 0=No");
                    sf("%i",&opz);
                }
                while(opz==1);
                system("cls");
                break;
            case 2:
                system("cls");
                mapa(opc,opd,opb,ope,opf);
                pf("\tConstante de log: ");
                sf("%f",&Con[1]);
                pf("\tConstante de x: ");
                sf("%f",&Con[0]);
                system("cls");
                EcuLog(opf);
                pf("\tIntervalo inferior: \n\t");
                sf("%f",&I1);
                pf("\tIntervalo superior: \n\t");
                sf("%f",&I2);
                pf("\t%i Iteracion\n",y);
                pf("\tXa = %.3f \n\tXb = %.3f \n",I1,I2);
                Xr=FXactual(I1,I2);
                pf("\tXr = %.3f\n",Xr);
                v=EvaEcuLog(opf,I1);
                u=EvaEcuLog(opf,Xr);
                pf("\tf(Xr)*f(Xa) = %f\n",u*v);
                if(u*v>0) I1=Xr;
                else I2=Xr;
                y++;
                system("pause");
                do
                {
                    pf("\t%i Iteracion\n",y);
                    pf("\tXa = %.3f \n \tXb = %.3f \n",I1,I2);
                    Xr=FXactual(I1,I2);
                    pf("\tXr = %.3f\n",Xr);
                    ErrPor=ErrorPor(Xr,I1);
                    pf("\tEP = %.3f %c \n",ErrPor,Porciento);
                    v=EvaEcuLog(opf,I1);
                    u=EvaEcuLog(opf,Xr);
                    pf("\tf(Xr)*f(Xa) = %.3f\n",u*v);
                    if(u*v>0) I1=Xr;
                    else I2=Xr;
                    y++;
                    pf("\tSeguir iterando? 1=Si 0=No");
                    sf("%i",&opz);
                }
                while(opz==1);
                system("cls");
                break;
            }
            break;
            default:
                break;
                break;
            }
        default:
            break;
        }
    }
    while(opc!=4);
    return 0;
}
