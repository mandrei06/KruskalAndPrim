#include <iostream>
#include<fstream>
#define DIM 15
using namespace std;
int n, A[DIM][DIM],i,j,m,B[3][100],k;
int viz[30]={0}, c;
void citire()
{
    m=0;
    k=1;
    ifstream fin("input.txt");
    fin>>n;
    for (int i=1; i<=n; i++)
        for(int j=i; j<=n; j++)
        {
            fin>>A[i][j];
            if(A[i][j]!=0)
            {
                m++;
                B[k][1]=A[i][j];
                B[k][2]=i;
                B[k][3]=j;
                k++;
            }
        }

}
void sortareMuchii()
{
    int aux,ok;
    do
    {
        ok=0;
        for(i=1; i<m; i++)
        {
            if(B[i][1]>B[i+1][1])
            {
                aux=B[i][1];
                B[i][1]=B[i+1][1];
                B[i+1][1]=aux;
                aux=B[i][2];
                B[i][2]=B[i+1][2];
                B[i+1][2]=aux;
                aux=B[i][3];
                B[i][3]=B[i+1][3];
                B[i+1][3]=aux;
                ok=1;
            }
        }



    }
    while(ok==1);
    for(i=1;i<=m;i++)
        cout<<B[i][1]<<" "<<B[i][2]<<" "<<B[i][3]<<endl;


}
void Kruskal()
{ int i,j,k;
i=1;
for(k=1;k<=n-1;k++)
{ while(viz[B[i][2]]==viz[B[i][3]]&&viz[B[i][2]]!=0)
        i++;
    c+=B[i][1];
    cout<<B[i][2]<<" "<<B[i][3]<<"\n";
    if(viz[B[i][2]]+viz[B[i][3]]==0)
        {viz[B[i][2]]=B[i][2];
        viz[B[i][3]]=B[i][2];}
    else
        if(viz[B[i][2]]*viz[B[i][3]]==0)
               {viz[B[i][2]]=viz[B[i][2]]+viz[B[i][3]];
                viz[B[i][3]]=viz[B[i][2]]+viz[B[i][3]];}
            else
            {
                for(j=1; j<=n; j++)
                    if(viz[j]==viz[B[i][2]]&&j!=B[i][2])
                        viz[j]=viz[B[i][3]];

                viz[B[i][2]]=viz[B[i][3]];
            }
        i++;
    }
    cout<<"Valoarea optima este: "<<c;
}





int main()
{
    citire();
    sortareMuchii();
    Kruskal();
    return 0;
}
