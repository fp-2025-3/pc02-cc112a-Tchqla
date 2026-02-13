#include <iostream>
#include <cmath>
using namespace std;

struct polinomio
{
    int grado;
    int* coefi;
}p1,p2,p3;

void sumar(){
    int temp[]={p1.grado,p2.grado,p3.grado};int max=p1.grado;int i=0;
    while (i<3)
    {
        if (max<temp[i])
        {
            max=temp[i];
        }
        i++;
    }

    polinomio psuma;psuma.grado=max;
    psuma.coefi=new int[max+1];
    if (p1.grado>p2.grado)
    {
        for (int i = p1.grado; i >=0; i--)
        {
            if (i<=p2.grado)
            {
                psuma.coefi[i]=p1.coefi[i]+p2.coefi[i];
            }else{
                psuma.coefi[i]=p1.coefi[i];
            }
        }
        
    }
    
    for (int i = max; i >=0 ; i--)
    {
        if (i<=p3.grado)
        {
            psuma.coefi[i]+=p3.coefi[i];
        }else{
            psuma.coefi[i]=p3.coefi[i];
        }
        
    }
    
    for (int i = 0; i < psuma.grado; i++)
    {
        cout <<psuma.coefi[i]<<"x^"<<abs(i-psuma.grado)<<" + ";
    }cout<<psuma.coefi[psuma.grado]<<endl;
    
}

void multiplicacion(){
    polinomio pmulti;pmulti.grado=p1.grado+p2.grado+p3.grado;
    pmulti.coefi=new int[pmulti.grado+1];

    for (int i = 0; i <= p1.grado; i++)
    {
        for (int j = 0; j <= p2.grado; j++)
        {
            pmulti.coefi[i+j]=p1.coefi[i]*p2.coefi[j];
            
        }
        
    }
    
    for (int i = 0; i <= pmulti.grado; i++)
    {
        for (int j = 0; j <= p3.grado; i++)
        {
            /* code */
        }
        
    }
    
}

int main(){
    int a[]={1,0,3},b[]={-4,5},c[]={3,0,1};

    p1.grado=2;p2.grado=1;p3.grado=2;
    p1.coefi=new int[p1.grado+1];p1.coefi=a;
    p2.coefi=new int[p2.grado+1];p2.coefi=b;
    p3.coefi=new int[p3.grado+1];p3.coefi=c;
    cout<<"polinomio 1: ";
    for (int i = 0; i < p1.grado+1; i++)
    {
        cout<<p1.coefi[i]<<"x^"<<abs(i-p1.grado)<<" + ";
    }cout<<p1.coefi[p1.grado]<<endl;cout<<"polinomio 2: ";
    for (int i = 0; i < p2.grado+1; i++)
    {
        cout<<p2.coefi[i]<<"x^"<<abs(i-p2.grado)<<" + ";
    }cout<<p2.coefi[p2.grado]<<endl;cout<<"polinomio 3: ";
    for (int i = 0; i < p3.grado+1; i++)
    {
        cout<<p3.coefi[i]<<"x^"<<abs(i-p3.grado)<<" + ";
    }cout<<p3.coefi[p3.grado]<<endl;

    sumar();

    return 0;
}