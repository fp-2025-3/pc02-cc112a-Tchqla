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
    psuma.coefi=new int[max+1]();
    if (p1.grado>=p2.grado)
    {
        int dif=p1.grado-p2.grado;
        
        for (int i = 0; i <= p1.grado; i++)
        {
            if (i<dif) 
            {
                psuma.coefi[i]=p1.coefi[i];
            }
            else 
            {
                psuma.coefi[i]=p1.coefi[i]+p2.coefi[i-dif];
            }
        }
    }
    else
    {
        int dif=p2.grado-p1.grado;
        
        for (int i = 0; i <= p2.grado; i++)
        {
            if (i<dif)
            {
                psuma.coefi[i]=p2.coefi[i];
            }
            else
            {
                psuma.coefi[i]=p2.coefi[i]+p1.coefi[i-dif];
            }
        }
    }

    int dif3=psuma.grado-p3.grado;
    
    for (int i = 0; i <= psuma.grado; i++)
    {
        if (i>=dif3) 
        {
            psuma.coefi[i]+=p3.coefi[i-dif3];
        }
    }
    
    cout<<"suma de los tres polinomios: ";
    for (int i = 0; i < psuma.grado; i++)
    {
        cout <<psuma.coefi[i]<<"x^"<<abs(i-psuma.grado)<<" + ";
    }cout<<psuma.coefi[psuma.grado]<<endl;
    
    delete[] psuma.coefi;
}

void multiplicacion(){
    polinomio pmulti,ptemp;pmulti.grado=p1.grado+p2.grado+p3.grado;
    ptemp.grado=p1.grado+p2.grado;ptemp.coefi=new int[ptemp.grado+1]();
    pmulti.coefi=new int[pmulti.grado+1]();

    for (int i = 0; i <= p1.grado; i++)
    {
        for (int j = 0; j <= p2.grado; j++)
        {
            ptemp.coefi[i+j]+=p1.coefi[i]*p2.coefi[j];
            
        }
        
    }
    
    for (int i = 0; i <= ptemp.grado; i++)
    {
        for (int j = 0; j <= p3.grado; j++)
        {
            pmulti.coefi[i+j]+=ptemp.coefi[i]*p3.coefi[j];
        }
        
    }
    
    cout<<"producto de los tres polinomios: ";
    for (int i = 0; i < pmulti.grado; i++)
    {
        cout <<pmulti.coefi[i]<<"x^"<<abs(i-pmulti.grado)<<" + ";

    }cout<<pmulti.coefi[pmulti.grado]<<endl;
    
    delete[] pmulti.coefi;delete[] ptemp.coefi;
}

int main(){
    int a[]={1,0,3},b[]={-4,5},c[]={3,0,1};

    p1.grado=2;p2.grado=1;p3.grado=2;
    p1.coefi=new int[p1.grado+1];
    for (int i = 0; i <= p1.grado; i++)
    {
        p1.coefi[i]=a[i];
    }
    
    p2.coefi=new int[p2.grado+1];
    for (int i = 0; i <= p2.grado; i++)
    {
        p2.coefi[i]=b[i];
    }

    p3.coefi=new int[p3.grado+1];
    for (int i = 0; i <= p3.grado; i++)
    {
        p3.coefi[i]=c[i];
    }


    cout<<"polinomio 1: ";
    for (int i = 0; i < p1.grado; i++)
    {
        cout<<p1.coefi[i]<<"x^"<<abs(i-p1.grado)<<" + ";
    }cout<<p1.coefi[p1.grado]<<endl;cout<<"polinomio 2: ";
    for (int i = 0; i < p2.grado; i++)
    {
        cout<<p2.coefi[i]<<"x^"<<abs(i-p2.grado)<<" + ";
    }cout<<p2.coefi[p2.grado]<<endl;cout<<"polinomio 3: ";
    for (int i = 0; i < p3.grado; i++)
    {
        cout<<p3.coefi[i]<<"x^"<<abs(i-p3.grado)<<" + ";
    }cout<<p3.coefi[p3.grado]<<"\n\n";

    sumar();
    multiplicacion();

    delete[] p1.coefi;delete[] p2.coefi;delete[] p3.coefi;

    return 0;
}