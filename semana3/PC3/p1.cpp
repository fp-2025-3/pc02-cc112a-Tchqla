#include <iostream>
using namespace std;

void identificar(char* texto,int k){
    int p[50], i=0;
    char* temp= texto;

    while (*temp!='\0')
    {
        if (*temp<='9' && *temp>='0')
        {
            int num=0;

            while (*temp<='9' && *temp>='0')
            {
                num=num*10+(*temp-'0');temp++;
            }

            *(p+i)=num;i++;
        }else{
            temp++;
        }
    }
    
    int* ini=p;int* fin=p+i-1;

    while (ini<fin)
    {
        int sum=*ini+*fin;

        if (sum==k)
        {
            cout<<"si existen 2 numeros con suma "<<k<<endl;
            return;
        }else if (sum<k)
        {
            ini++;
        }else{
            fin--;
        }
    }
    
    cout<<"no existen 2 numeros con suma "<<k<<endl;
    
}

int main(){
    char texto[]="1, 2, 4, 7, 11";
    int k;
    char* p=texto;

    while (*p!='\0')
    {
        cout<<*p;
        p++;
    }cout<<endl;

    cout<<"k = ";cin>>k;
    
    identificar(texto,k);

    return 0;
}