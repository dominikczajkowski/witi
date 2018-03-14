#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

void witi()
{
    int N,p[21],w[21],d[21];
    fstream f("dane.txt");
    int *F=NULL;
    int cMax=0;
    int pw=0;
    while(1)
    {
    f>>N;
    if(f.eof()) break;
    for(int i=0;i<N;i++)
        f>>p[i]>>w[i]>>d[i];
    pw=pow(2,N);
    F = new int[pw];
    for(int i=1;i<pw;i++)
    {
            cMax = 0;
            F[i] = 9999999;
            for(int j=0; j<=static_cast<int>(sizeof(int)*8);j++)
                if(i>>j & 1) cMax += p[j];

            for(int s=0,b=i;s<=static_cast<int>(sizeof(int)*8);s++,b/=2)
                if(b & 1) F[i] = min(F[i],F[i-(1<<s)] + max(0,(cMax-d[s])*w[s]));
    }
    cout << F[pw-1] << endl;
    delete F;
    }
    f.close();
}

int main()
{

    witi();
    return 0;
}

