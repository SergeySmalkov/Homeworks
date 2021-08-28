// Online C++ compiler to run C++ program online
#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>

template <typename T>
class Point;

template <typename T>
std::ostream &operator << (std::ostream &out, Point<T> &pnt){
    std::cout << pnt.Get_x() << " " << pnt.Get_y() <<std::endl;
}

template <typename T>
std::istream &operator >> (std::istream &is, Point<T> &pnt){
    T x;
    T y;
    std::cin >> x;
    std::cin >> y;
    pnt.Set_x(x);
    pnt.Set_y(y);
}

template <class T>
class Point{

private:
    T x;
    T y;

public:
    friend std::ostream &operator << <> (std::ostream &out, Point &pnt);
    friend std::istream &operator >> <> (std::istream &, Point &);

    Point(){}

    Point(T X, T Y):x(X),y(Y){}

    Point (const Point &POINT):x(POINT.x), y(POINT.y){}

    ~Point(){}

    Point & operator = (const Point &other){
        if (this == &other){
            return *this;
        }
        x=other.x;
        y=other.y;
        return *this;
    }

    T Get_x(){return x;}

    T Get_y(){return y;}

    void Set_x(T X) {x = X;}

    void Set_y(T Y) {y = Y;}

    void print(){
        std::cout << std::setprecision(5) << std::fixed << x << " " << y << std::endl;
    }
    void read(){
        std::cin >> x;
        std::cin >> y;
    }
    void Spin (double degree, const Point<T> pnt){
        double old_x=x;
        x=cos(degree)*(x-pnt.x)-sin(degree)*(y-pnt.y)+pnt.x;
        y=sin(degree)*(old_x-pnt.x)+cos(degree)*(y-pnt.y)+pnt.y;
        std::cout << std::setprecision(3) << std::fixed << x << std::endl;
        std::cout << y << std::endl<< std::endl;
    }
    void Move_pnt(const Point<T> pnt){
        x=x+pnt.x;
        y=y+pnt.y;
    }
};

template <class T>
class Polygon{
public:
    size_t Num_Vertex;
    Point<T> *Array_of_points;
    Polygon():Num_Vertex(0){}
    Polygon(size_t n):Num_Vertex(n),Array_of_points(new Point<T>[n]){
        for (size_t i=0; i<n; ++i){
            std::cin >> Array_of_points[i];
        }
    }
    ~Polygon(){}
    T Perimiter(){
        T perim = 0;
        if(Num_Vertex>1){
            for(size_t i =0;i<Num_Vertex;++i){
                perim += length(Array_of_points[i],Array_of_points[(i+1)%Num_Vertex]);
            }
        }
        return (perim);
    }
    T SQ(){
        T sq = 0;
        if(Num_Vertex>1){
            for(size_t i =0;i<Num_Vertex-2;++i){
                sq += Triangle_square(Array_of_points[0], Array_of_points[i+1], Array_of_points[i+2]);
            }
        }
        return (sq);
    }
    void Spinner(double degree, const Point<T> pnt){
        for(size_t i =0;i<Num_Vertex;++i){
            Array_of_points[i].Spin(degree, pnt);
        }
    }
    void Parallel_move(const Point<T> pnt){
        for(size_t i =0;i<Num_Vertex;++i){
            Array_of_points[i].Move_pnt(pnt);
        }
    }
    void Print(){
        for(size_t i =0;i<Num_Vertex;++i){
            std::cout <<i << " : " <<  Array_of_points[i].Get_x() << " " << Array_of_points[i].Get_y() << std::endl;
        }
    }
};

template <class T>
class Segment: public Polygon<T>{
public:
    Segment():Polygon<T>(2){}
    ~Segment(){}
};

template <class T>
class Triangle: public Polygon<T>{
public:
    Triangle():Polygon<T>(3){}
    ~Triangle(){}
};

template <class T>
class Quadrilateral: public Polygon<T>{
public:
    Quadrilateral():Polygon<T>(4){}
    ~Quadrilateral(){}
};


template <class T>
class Square: public Quadrilateral<T>{

public:
    Square(): Quadrilateral<T>(){}
    ~Square(){}
    T SQ(){
        return(pow(length(Polygon<T>::Array_of_points[0],Polygon<T>::Array_of_points[1]),2));
    }
};

template <class T>
class Pentagon: public Polygon<T>{
public:
    Pentagon():Polygon<T>(5){}
    ~Pentagon(){}
};

template <class T>
class Hexagon: public Polygon<T>{
public:
    Hexagon():Polygon<T>(6){}
    ~Hexagon(){}
};


template <class T>
T length(Point<T> p1, Point<T> p2){
    return(sqrt(pow(p2.Get_x()-p1.Get_x(),2)+pow(p2.Get_y()-p1.Get_y(),2)));
};

template <class T>
T Triangle_square(Point<T> p1, Point<T> p2, Point<T> p3){
    return(0.5* fabs((p2.Get_x()-p1.Get_x())*(p3.Get_y()-p1.Get_y())-(p3.Get_x()-p1.Get_x())*(p2.Get_y()-p1.Get_y())));
};

int main() {
    const double PI = atan(1) * 4;
    Point<double> w;
    //std::cin >> w;

    Point<double> q;
    std::cin >> q;
    Point<double> e;
    //std::cin >> e;
    //w.Spin(PI/2, q);

    //Polygon<double> pol = Polygon<double>(4);
    //std::cout << pol.Perimiter();

    Square<double> square = Square<double>();
    square.Parallel_move(q);
    square.Print();
    std::cout << square.SQ();
    return 0;
}
