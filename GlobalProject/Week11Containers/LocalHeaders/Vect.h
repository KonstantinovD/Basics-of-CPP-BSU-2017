#include  <iostream>
#include  <assert.h>
using namespace std;
template <class T> class Vect
{
public:
    typedef T* iterator;
    explicit Vect(int n = 100); //create a size n array
    Vect(const Vect<T>& v); //copy Vect
    Vect(const T* a, int n); //copy an array
    ~Vect() { delete[]p; }
    iterator begin(){ return p; }
    iterator end(){ return p + size; }
    //T& operator[](int i);      //range checked element
    Vect<T>& operator=(const Vect<T>& v);
    //protected:
    T* p;                      //base pointer
    int size;                  //number of elements
};

template <class T>
Vect<T>::Vect(int n = 100) : size(n)
{
    assert(n > 0);
    p = new T[size];
    assert(p != 0);
}
template <class T>
Vect<T>::Vect(const T a[], int n)
{
    assert(n > 0);
    size = n;
    p = new T[size];
    assert(p != 0);
    for (int i = 0; i < size; ++i)  p[i] = a[i];
}
template <class T>
Vect<T>::Vect(const Vect<T>& v)
{
    size = v.size;   
    p = new T[size];   
    assert(p != 0);
    for (int i = 0; i < size; ++i)
        p[i] = v.p[i];
}
template <class T>
Vect<T>& Vect<T>::operator=(const Vect<T>& v)
{
    assert(v.size == size);
    for (int i = 0; i < size; ++i)
        p[i] = v.p[i];
    return *this;
}

template <class T> class Vectex :public Vect<T>
{
public:
    Vectex(int n = 10) :Vect<T>::Vect(n)
    {
        assert(n > 0);
        size = n;
        p = new T[size];
        assert(p != 0);
        reserved = n;
    }
    T& operator[](int i)
    {
        assert(i >= 0 && i < size);
        return (p[i]);
    }
    void push_front(T obj){
        if (size == reserved){
            reserve();
        }
        for (int i = size; i > 0; i--){
            p[i] = p[i - 1];
        }
        p[0] = obj;
        size++;
    }
    int pop_front(){
        assert(size > 0);
        int res = p[0];
        for (int i = 0; i < size - 1; i++){
            p[i] = p[i + 1];
        }
        size--;
        return res;
    }

private:
    int reserved;
    void reserve(){
        T* p2 = new T[reserved * 2];
        for (int i = 0; i < size; i++){
            p2[i] = p[i];
        }
        reserved = reserved * 2;
        delete[] p;
        p = p2;
    }
};

