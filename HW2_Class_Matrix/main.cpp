// Online C++ compiler to run C++ program online
#include <iostream>
class Matrix
{
private:
    int rows,columns;
    int **a;

public:
    Matrix() {}
    Matrix(int n, int m){
        rows= n;
        columns=m;
        a=new int * [n];
        for (int i=0; i<n; i++){
            a[i]= new int [m];
        }
    }
    Matrix(int n){
        rows=n;
        columns=n;
        a=new int * [n];
        for (int i=0; i<n; i++){
            a[i]= new int [n];
        }
    }

    void readMatrix(){
        for(int i =0; i<rows;++i){
            for(int j=0; j<columns; ++j){
                std::cin >>a[i][j];
            }
        }
    }
    void printMatrix(){
        for(int i =0; i<rows;++i){
            for(int j=0; j<columns; ++j){
                std::cout << a[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    Matrix multiply(Matrix b){
        if(columns!=b.rows){
            Matrix c = Matrix(0, 0);
            std::cout << "Нельзя перемножить";
            return c;
        }
        Matrix c = Matrix(rows, b.columns);

        for(int i=0;i<c.rows;++i){
            for(int j=0;j<c.columns;++j){
                for(int s=0;s<columns;++s){
                    c.a[i][j]=c.a[i][j]+a[i][s]*b.a[s][j];
                }
            }
        }
        return c;
    }

    Matrix sum(Matrix b){
        if((columns!=b.columns)&(rows!=b.rows)){
            Matrix c = Matrix(0, 0);
            std::cout << "Нельзя просуммировать";
            return c;
        }
        Matrix c = Matrix(rows, b.columns);

        for(int i=0;i<c.rows;++i){
            for(int j=0;j<c.columns;++j){

                c.a[i][j]=a[i][j]+b.a[i][j];

            }
        }
        return c;
    }

    Matrix difference(Matrix b){
        if((columns!=b.columns)&(rows!=b.rows)){
            Matrix c = Matrix(0, 0);
            std::cout << "Нельзя вычесть";
            return c;
        }
        Matrix c = Matrix(rows, b.columns);

        for(int i=0;i<c.rows;++i){
            for(int j=0;j<c.columns;++j){

                c.a[i][j]=a[i][j]-b.a[i][j];

            }
        }
        return c;
    }

    Matrix transpose(){

        Matrix c = Matrix(columns, rows);

        for(int i=0;i<c.rows;++i){
            for(int j=0;j<c.columns;++j){

                c.a[i][j]=a[j][i];

            }
        }
        return c;
    }


};

int main() {
    // Write C++ code here
    int n,m, k,l;
    std::cin >> n;
    std::cin >> m;
    std::cin >> k;
    std::cin >> l;
    Matrix a = Matrix(n, m);
    Matrix b = Matrix(k, l);
    a.readMatrix();
    a.printMatrix();
    std::cout << std::endl;
    b.readMatrix();
    b.printMatrix();
    std::cout << std::endl;
    Matrix c = a.transpose();
    c.printMatrix();

    return 0;
}
