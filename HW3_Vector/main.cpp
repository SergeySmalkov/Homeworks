#include <iostream>

template <typename T>
class Vector;

template <typename T>
std::ostream& operator << (std::ostream &out, Vector<T> &vect)
{
    for(int i =0; i<vect.Get_N(); ++i){
        std::cout << (vect.Get_A())[i] << " ";
    }
    std::cout << std::endl;
    return out;
}

template< typename T>
std::istream & operator >> (std::istream&  is, Vector<T> & vect)
{
    for(int i =0; i < vect.Get_N(); ++i){
        T x;
        std::cin >> x;
        vect.Set(i,x);
    }
    return is;
}

template <class T>
class Vector{
private:
    size_t N;
    T *A;
public:
    Vector() {}
    Vector(size_t n): N(n), A(new T[n]) {
    }
    Vector (const Vector &VECTOR): N(VECTOR.N), A(new T[VECTOR.N])
    {
        for(int i =0; i<VECTOR.N; ++i){
            A[i] = VECTOR[i];
        }
    }
    ~Vector(){
        delete []A;
    }

    friend std::ostream &operator << <> (std::ostream &out, Vector &vect);
    friend  std::istream &operator >> <> (std::istream &, Vector &);

    Vector & operator = (const Vector &other){

        if (this == &other){
            return *this;
        }
            N = other.N;
            A = new T[other.N];
            for(int i=0; i<other.N; ++i){
                A[i] = other[i];
            }
            return *this;
    }

    T& operator[] (const int index) const
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
            result.A[i]= A[i]- other[i];
        }
        return result;

    }

    Vector operator * (const double &multiplicator){
        Vector result(N);
        for(int i =0; i<N;++i){
            result.A[i]= A[i] * multiplicator;
        }
        return result;
    }
    void Set(int i, T x){
        A[i]=x;
    }
    void readVector(){
        for(int i =0; i<N; ++i){
            std::cin >> A[i];
        }
    }
    void printVector(){
        for(int i =0; i<N; ++i){
            std::cout << A[i] << " ";
        }
        std::cout << std::endl;
    }

    double Dot_Product(Vector v1){
        double result=0;
        if (N != v1.N){
            std::cout << " Нельзя найти скалярное произведение ";
            return result;
        }
        for(int i =0; i<N; ++i){
            result+= v1[i] * A[i];
        }
        return result;
    }
    size_t Get_N(){
        return N;
    }

    T* Get_A(){
        return A;
    }
    Vector Cross_Product(Vector other){
        Vector result(other.N);
        if(other.N == 3){
            if(N == 3){
                result.A[0] = A[1]* other[2] - A[2] * other[1];
                result.A[1] = A[2]* other[0]- A[0] * other[2];
                result.A[2] = A[0] * other[1] - A[1] * other[0];
            }
        }
        return result;
    }
};



int main() {

    size_t n;
    std::cin >> n ;
    Vector<int> v = Vector<int>(n);
    std::cin >> v ;
    Vector<int> t = Vector<int>(n);
    std::cin >> t ;

    Vector<int> j(v);

    Vector<int> N(5);
    N=v;
    std::cout << N;

    Vector<int> P = v + j;
    std::cout << P;
    Vector<int> S = v*5;
    std::cout << S;
    double dt = v.Dot_Product(j);
    std::cout << dt << " ";
    Vector<int>q = v.Cross_Product(t);
    std::cout << q;
    std::cout << q[0] << " ";
    return 0;
}
