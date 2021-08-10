// Online C++ compiler to run C++ program online
#include <iostream>

class Vector
{
private:
    int N;
    double *A;
public:
    Vector() {}
    Vector(int n):N(n){
        A=new double [n];
    }
    Vector (const Vector &VECTOR):N(VECTOR.N)
    {
        A=new double [VECTOR.N];
        for(int i =0; i<VECTOR.N;++i){
            A[i]=VECTOR[i];
        }
    }
    ~Vector(){
        delete []A;
    }

    Vector & operator = (const Vector &other){
        if (this == &other){
            return *this;
        }
        for(int i =0; i<other.N;++i){
            A[i]=other[i];
        }
        return *this;
    }


    double & operator[] (const int index) const
    {
        return A[index];
    }

    Vector operator + (const Vector &other){
        Vector result(other.N);
        if (N != other.N){
            std::cout <<" Нельзя складывать ";
            return result;
        }

        for(int i =0; i<other.N;++i){
            result[i]=A[i]+other[i];
        }
        return result;

    }

    Vector operator - (const Vector &other){
        Vector result(other.N);
        if (N != other.N){
            std::cout <<" Нельзя вычитать ";
            return result;
        }

        for(int i =0; i<other.N;++i){
            result.A[i]=A[i]-other[i];
        }
        return result;

    }

    Vector operator * (const double &multiplicator){
        Vector result(N);
        for(int i =0; i<N;++i){
            result.A[i]=A[i]*multiplicator;
        }
        return result;
    }



    void readVector(){
        for(int i =0; i<N;++i){
            std::cin >>A[i];
        }
    }
    void printVector(){
        for(int i =0; i<N;++i){
            std::cout <<A[i]<< " ";
        }
        std::cout << std::endl;
    }

    double Dot_Product(Vector v1){
        double result=0;
        if (N != v1.N){
            std::cout <<" Нельзя найти скалярное произведение ";
            return result;
        }
        for(int i =0; i<N;++i){
            result=result+v1[i]*A[i];
        }
        return result;
    }

    Vector Cross_Product(Vector other){
        Vector result(other.N);
        if(other.N==3){
            if(N==3){
                result.A[0]=A[1]*other[2]-A[2]*other[1];
                result.A[1]=A[2]*other[0]-A[0]*other[2];
                result.A[2]=A[0]*other[1]-A[1]*other[0];
            }
        }
        return result;
    }
};

int main() {

    int n;
    std::cin >> n ;
    Vector v=Vector(n);
    v.readVector();
    Vector t=Vector(n);
    t.readVector();

    v.printVector();
    Vector j(v);
    j.printVector();
    Vector N(n);
    N=v;
    N.printVector();
    Vector P =v+j;
    P.printVector();
    Vector S=v*5;
    S.printVector();
    double dt=v.Dot_Product(j);
    std::cout <<dt<< " ";
    Vector q=v.Cross_Product(t);
    q.printVector();
    std::cout <<q[0]<< " ";
    return 0;
}
