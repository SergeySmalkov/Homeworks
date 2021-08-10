#include <stdio.h>

#include <iostream>

int **read_matrix(int **a, int n, int m){
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            std::cin >> a[i][j];

        }
    }
    return a;
}

int **multiply(int **a, int n, int m,  int **b, int k, int l){

    int **c=new int * [n];
    for (int i=0; i<n; i++){
        c[i]= new int [l];
    }

    if (m != k){
        return nullptr;
    }



    else{
        for(int i=0;i<n;++i){
            for(int j=0;j<l;++j){
                for(int s=0;s<m;++s){
                    c[i][j]=c[i][j]+a[i][s]*b[s][j];
                }
            }
        }
    }
    return c;

}

int main()
{
    int n,m,k,l;

    std::cin >> n;
    std::cin >> m;
    std::cin >> k;
    std::cin >> l;

    int **a=new int * [n];
    for (int i=0; i<n; i++){
        a[i]= new int [m];
    }
    int **b=new int * [k];
    for (int i=0; i<k; i++){
        b[i]= new int [l];
    }


    read_matrix(a, n, m);
    read_matrix(b, k, l);
    int **c=multiply(a, n, m, b, k, l);

    if(c!=nullptr){


        for(int i=0;i<n;++i){
            for(int j=0;j<l;++j){
                std::cout << c[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    else{
        std::cout << "Нельзя переменожить" <<std::endl;
    }


    for(int i=0;i<n;++i){
        delete [] a[i];
    }
    delete [] a;

    for(int i=0;i<m;++i){
        delete [] b[i];
    }
    delete [] b;

    for(int i=0;i<n;++i){
        delete [] c[i];
    }
    delete [] c;

    return 0;
}
