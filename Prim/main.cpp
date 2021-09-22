#include <iostream>
#include<fstream>
#define DIM 15
using namespace std;
int a[50][50], viz[100], oo=4000, n;
void citire()
{
    ifstream fin("input.txt");
    fin>>n;
    for (int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            {fin>>a[i][j];
            if(a[i][j]==0)
                a[i][j]=oo;
            }


}
bool verificarenod()
{
    for(int i=1; i<=n; i++)
        if(viz[i]==0)
            return true;
    return false;
}
void Prim(int x)
{
    int i, j, p, minim, k, c=0,u,al,b,v,valoare=0;
    viz[x]=1;
    while(verificarenod())
    {
        for(i=1; i<=n; i++)
           {minim=oo;
            for(j=1; j<=n; j++)
                if(a[i][j]<minim)
                    if(viz[i]!=0)
                    {
                    minim=a[i][j];
                    al=u=i;
                    b=v=j;
                    }}
            if(viz[u]==0||viz[v]==0)
            {
                cout<<"\n"<<al<<" "<<b;
                valoare+=a[al][b];
                viz[b]=1;
            }
            a[al][b]=a[b][al]=oo;
    }
    cout<<endl<<"Valoarea drumului minim este:"<<valoare;
}


int main()
{
    citire();
    Prim(1);
    return 0;
}
