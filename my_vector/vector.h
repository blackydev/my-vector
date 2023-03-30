#ifndef JIPP_PROJECT_VECTOR_H
#define JIPP_PROJECT_VECTOR_H
#include <iostream>
#include <fstream>
#include "findOne.h"
#include "messages.h"
using namespace std;

template<typename T> class Vector {
public:
    size_t last = 0;  // first "free" index

    Vector(const size_t& size_); // allocates memory for the data array
    ~Vector(); // free memory

    void push(const T& obj); // push object to 'data' array and increment the 'last' property
    T* pop();   // pop last element of 'data' array and decrement the 'last' property
    void clearAll(); // remove all elements of 'data' array
    void find(const T& key);

    void erase(const T* obj); // remove passed object from 'data' array. Shifts other elements to be arranged continuously
    T& operator[](int i) const {
        if (i >= last || i < 0 || !data) {
            throwErr(static_cast<unsigned short>(errors::indexOut));
            return data[0];
        }
        return data[i];
    };


    friend ostream& operator<<(ostream& stream, const Vector<T>& v) {
        for (size_t i = 0; i < v.last; i++) {
            stream << v.data[i];
            cout << v.data[i];
        }
        return stream;
    };

    friend ofstream& operator<<(ofstream& stream, const Vector<T>& v) {
        ios::pos_type beginPos = stream.tellp();
        unsigned long long offset;

        stream.write(reinterpret_cast<const char*>(&v.last), static_cast<streamsize>(sizeof(size_t)));

        for(size_t i = 0; i<v.last; ++i)
         stream << v.data[i];

        offset = stream.tellp() - beginPos;
        if (stream.bad() || stream.fail() || offset != sizeof(size_t) + sizeof(T) * v.last)
            throwErr(static_cast<unsigned short>(errors::fileProblem));

        return stream;
    };

    friend ifstream& operator>>(ifstream& stream, Vector<T>& v) {
        delete[] v.data;
        size_t last;
        stream.read(reinterpret_cast<char*>(&last), static_cast<streamsize>(sizeof(size_t)));
        v.malloc(last);
        v.last = last;

        for (size_t i = 0; i < last; i++)
            stream >> v.data[i];

        if (stream.bad() || stream.fail())
            throwErr(static_cast<unsigned short>(errors::fileProblem));

        return stream;
    };


    T* getBegin() { return data; }   // returns pointer to first element
    T* getEnd() { return &data[last]; } // returns pointer to last element

private:
    T* data;      // pointer to array of T type=
    size_t size;  // the number of elements for which the memory was allocated

    void malloc(size_t size);
    void realloc(size_t size_);   // if last >= size, it's increment size, and reallocates memory
};

#endif //JIPP_PROJECT_VECTOR_H

// METHODS IMPLEMENTATION
template<typename T>
Vector<T>::Vector(const size_t& size_) {
    last = 0;
    malloc(size_);
}

template<typename T>
Vector<T>::~Vector() {
    delete[] data;
}

template<typename T>
void Vector<T>::push(const T& obj) {
    if (last >= size)
        realloc(size*2);
    data[last++] = obj;
}

template<typename T>
T* Vector<T>::pop() { if (last > 0) return &data[--last]; return nullptr; }

template<typename T>
void Vector<T>::clearAll() {
    last = 0;
    delete[] data;
    malloc(8);
}

template<typename T>
void Vector<T>::find(const T& key) {
    bool isFound = false;
    auto ptr = getBegin();
    auto endPtr = getEnd();

    while (ptr)
    {
        ptr = findOne(ptr, endPtr, key);
        if (ptr)
        {
            size_t i = ptr - getBegin();
            cout << "index = " << i << endl << *ptr << endl;
            ptr++;
            isFound = true;
        }
    }
    if (!isFound) throwMess(static_cast<unsigned short>(mess::objNotFound));

}

template<typename T>
void Vector<T>::erase(const T* obj) {
    const T* src = obj + 1;
    std::memcpy((void*)obj, src, (&data[last] - src) * sizeof(T));
    --last;
}


// MEMORY ALLOCATION METHODS

template<typename T>
void Vector<T>::malloc(size_t size_) { 
    size = size_;
    try {
       //bad_alloc a;
       //throw a;
        data = new T[size];
    }
    catch (bad_alloc& error) {
        throwErr(static_cast<unsigned short>(errors::badAlloc));
        cerr << "Caught bad_alloc: " << error.what() << endl;
        exit(1);
    }
} 

template<typename T>
void Vector<T>::realloc(size_t size_) {
    T* tmp = data;

    try {
        data = new T[size_];
    }
    catch (bad_alloc& error) {
        throwErr(static_cast<unsigned short>(errors::badAlloc));
        cerr << "Caught bad_alloc: " << error.what() << endl;
        exit(1);
    }

    memcpy(data, tmp, last * sizeof(T));
    size = size_;
    delete[] tmp;
}