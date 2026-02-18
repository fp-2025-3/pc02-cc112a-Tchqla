#include <iostream>
#include <cmath>
using namespace std;

struct 
{
    int grado;
    int* coef;
}p1,p2,psuma,pmulti;

void leerMostrar(){
    cout<<"ingrese el grado del primer polinomio: ";cin>>p1.grado;
    p1.coef=new int[p1.grado+1];

    for (int* i = p1.coef+p1.grado; i >= p1.coef; i--)
    {
        int g=i-p1.coef;
        cout<<"ingrese el coeficiente de x^"<<g<<": ";cin>>*i;
    }
    
    cout<<"\ningrese el grado del segundo polinomio: ";cin>>p2.grado;
    p2.coef=new int[p2.grado+1];

    for (int* i = p2.coef+p2.grado; i >= p2.coef; i--)
    {
        int g=i-p2.coef;
        cout<<"ingrese el coeficiente de x^"<<g<<": ";cin>>*i;
    }

    cout<<"\nprimer polinomio: ";
    for (int i = p1.grado; i> 0; i--)
    {
        cout<<p1.coef[i]<<"x^"<<i<<" + ";
    }cout<<p1.coef[0]<<endl;
    
    cout<<"segundo polinomio: ";
    for (int i = p2.grado; i> 0; i--)
    {
        cout<<p2.coef[i]<<"x^"<<i<<" + ";
    }cout<<p2.coef[0]<<endl;
}

void sumarMultiplicar(){
    if (p1.grado<p2.grado)
    {
        psuma.grado=p2.grado;
        psuma.coef=new int[p2.grado+1];
        for (int i = p2.grado; i >= 0; i--)
        {
            if (i<=p1.grado)
            {
                psuma.coef[i]=p1.coef[i]+p2.coef[i];
            }else{
                psuma.coef[i]=p2.coef[i];
            }
        }
        
    }else{
        psuma.grado=p1.grado;
        psuma.coef=new int[p1.grado+1];
        for (int i = p1.grado; i >= 0; i--)
        {
            if (i<=p2.grado)
            {
                psuma.coef[i]=p1.coef[i]+p2.coef[i];
            }else{
                psuma.coef[i]=p1.coef[i];
            }
        }
    }
    
    cout<<"la suma de los polinomios es: ";
    for (int i = psuma.grado; i> 0; i--)
    {
        cout<<psuma.coef[i]<<"x^"<<i<<" + ";
    }cout<<psuma.coef[0]<<endl;


    pmulti.grado=p2.grado+p1.grado;
    pmulti.coef=new int[pmulti.grado+1]();
    for (int i = 0; i <= p1.grado; i++)
    {
        for (int j = 0; j <= p2.grado; j++)
        {
            pmulti.coef[i+j]+=p1.coef[i]*p2.coef[j];
        }
        
    }
    
    cout<<"el producto de los polinomios es: ";
    for (int i = pmulti.grado; i> 0; i--)
    {
        cout<<pmulti.coef[i]<<"x^"<<i<<" + ";
    }cout<<pmulti.coef[0]<<endl;
}

int evaluar(int n){
    int temp=0;

    for (int i = 0; i <= p1.grado; i++)
    {
        temp+=p1.coef[i]*pow(n,i);
    }
    
    return temp;
}

int main(){
    leerMostrar();
    sumarMultiplicar();

    int n;
    cout<<"\ningrese el valor de x para evaluar en el polinomio: ",cin>>n;

    int eva=evaluar(n);
    cout<<"el primer polinomio evaluado en x = "<<n<<" es: "<<eva<<endl;

    delete[] p1.coef;delete[] p2.coef;
    delete[] psuma.coef;delete[] pmulti.coef;

    return 0;
}