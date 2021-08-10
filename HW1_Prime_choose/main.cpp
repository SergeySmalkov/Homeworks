#include <stdio.h>

#include <iostream>

int prime_check(int a){
    int counter =0;

    for(int i=1;i<1+a;++i)
    {
        if(a%i==0){
            ++counter;
        }

    }

    if(counter>2){
        return(0);
    }

    else{
        return(1);
    }
}

int *prime(int *a, int n, int &array_size){

    int *array=new int [array_size];

    for(int i=0; i<n;++i){
        if(prime_check(a[i]) == 1){

            int *New_array=new int [array_size+1];

            for(int i=0;i<array_size;++i){
                New_array[i]=array[i];
            }
            ++array_size;
            delete[] array;
            array=New_array;

            array[array_size-1]=a[i];

        }
    }
    return array;
}

int main()

{
    int n;
    int array_size=0;

    std::cin >> n;

    int *a=new int [n];

    for(int i=0;i<n;++i){
        std::cin >> a[i];
    }

    int *b=new int [1];
    b=prime(a,n, array_size);
    for(int i=0; i<array_size;++i)
    {
        std::cout << b[i] <<" ";
    }

    delete [] a;
    delete [] b;

    return 0;
}
