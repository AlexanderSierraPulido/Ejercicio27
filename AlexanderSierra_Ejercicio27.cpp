#include <iostream>
#include <fstream>
using namespace std;


int main()
    {
    int N = 101;
    float delta_y = 1/100;
    float delta_x = 1/100;
    float U_presente[N][N];
    float U_futuro[N][N];
    
    //Condiciones iniciales
    for(int i=0;i<N;i++)
        {
        for(int j=0;j<N;j++)
            {
            U_presente[i][j]=0;
            if(20<i<80)
                {
                if(j=40)
                    {
                    U_presente[i][j]=100;
                    }
                if(j=60)
                    {
                    U_presente[i][j]=-100;
                    }   
                }
            cout<<U_presente[i][j]<<endl;
            }
        }
    
    
    //Avance en el tiempo
        float error=0;
        while(error>0.01)
        {
        for(int i=1;i<N-1;i++)
            {
            for(int j=1;j<N-1;j++)
                {
                U_futuro[i][j]=1/4*(U_presente[i+1][j]+U_presente[i-1][j]+U_presente[i][j+1]+U_presente[i][j-1]);
                if(j=40)
                    {
                    U_futuro[i][j]=100;
                    }
                if(j=60)
                    {
                    U_futuro[i][j]=-100;
                    }   
                error += U_futuro[i][j] - U_presente[i][j];
                U_presente[i][j]=U_futuro[i][j];
                }
            }
        error = error/(99*99);
        }
        for(int i=1;i<N-1;i++)
            {
            for(int j=1;j<N-1;j++)
                {
                cout<<U_presente[i][j]<<endl;
                }
            }
    }