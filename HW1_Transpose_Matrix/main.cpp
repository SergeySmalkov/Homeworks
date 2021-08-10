#include <stdio.h>

#include <iostream>

void read_matrix(int **a, int n, int m){
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            std::cin >> a[i][j];

        }
    }

}

int **transpose(int **a, int n, int m){
    int **b=new int*[m];
    for (int i=0; i<m; i++){
        b[i]= new int [n];
    }
    for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                b[j][i]=a[i][j];

            }
            std::cout << std::endl;
        }
    return b;
}


int main()
{
	int n,m;

    std::cin >> n;
    std::cin >> m;
    int **a=new int * [n];
    for (int i=0; i<n; i++){
        a[i]= new int [m];
    }
    read_matrix(a, n, m);

    for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                std::cout << a[i][j];

            }
            std::cout << std::endl;
        }

    int **b=transpose(a, n, m);

    for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                std::cout << b[i][j];

            }
            std::cout << std::endl;
        }



    for(int i=0;i<n;++i){
        delete [] a[i];
        }
    delete [] a;

    for(int i=0;i<m;++i){
        delete [] b[i];
        }
    delete [] b;

	return 0;
}
