#include "vector.h"
#include <iostream>
template<class T>
Vector<T>::Vector(){
	m_pElements = NULL;
	m_nSize = 0;
	m_nCapacity = 0;
}

template<class T>
Vector<T>::Vector(int size){
	m_pElements = new T[size];
	m_nSize = 0;
	m_nCapacity = size;
}

template<class T>
Vector<T>::Vector(const Vector & r){
	m_nSize = r.m_nSize;
	m_nCapacity = r.m_nCapacity;
	m_pElements = new T[m_nCapacity];
    memcpy(m_pElements, r.m_pElements, sizeof(T) * m_nSize);
}

template<class T>
Vector<T>::~Vector(){
	delete[] m_pElements;
	m_pElements = NULL;
	m_nSize = 0;
	m_nCapacity = 0;
}

template<class T>
T & Vector<T>::operator[](int index){   
	return m_pElements[index];
}

template<class T>
T & Vector<T>::at(int index){
	if(index<0||index>=m_nSize){
        throw std::out_of_range("Vector.at():index is out of range!");
    }else{
        return m_pElements[index];
    }
}

template<class T>
int Vector<T>::size() const{
	return m_nSize;
}

template<class T>
void Vector<T>::push_back(const T & x){
	if (m_nSize>=m_nCapacity)
	{
		throw std::out_of_range("Vector is full!");
	}
	else{
        m_pElements[m_nSize++] = x;
    }

}

template<class T>
void Vector<T>::clear(){
	m_nSize = 0;
	m_pElements = NULL;
}

template<class T>
bool Vector<T>::empty() const{
	if (m_nSize == 0)
		return true;
	else return false;
}

template<class T>
void Vector<T>::inflate()
{
	T* cur=m_pElements;
    m_pElements = new T[m_nCapacity*2];
    memcpy(m_pElements, cur, sizeof(T) * m_nSize);
    delete [] cur;
    m_nCapacity *= 2;
}

// Main function for testing the Vector class.
int main() {
    int num = 1;  // Variable to store user input for selecting test cases.

    // Display options for testing different features of the Vector class.
    std::cout << "Testing Vector class:enter 1 to test Vector();  " << std::endl;
    std::cout << "Testing Vector class:enter 2 to test Vector(int size);  " << std::endl;
    std::cout << "Testing Vector class:enter 3 to test Vector(const Vector& r);  " << std::endl;
    std::cout << "Testing Vector class:enter 4 to test ~Vector();  " << std::endl;
    std::cout << "Testing Vector class:enter 5 to test T& operator[](int index);  " << std::endl;
    std::cout << "Testing Vector class:enter 6 to test T& at(int index);  " << std::endl;
    std::cout << "Testing Vector class:enter 7 to test int size() const;  " << std::endl;
    std::cout << "Testing Vector class:enter 8 to test void push_back(const T& x);  " << std::endl;
    std::cout << "Testing Vector class:enter 9 to test void clear();  " << std::endl;
    std::cout << "Testing Vector class:enter 10 to test bool empty() const;  " << std::endl;
    std::cout << "Testing Vector class:enter 0 to exit;  " << std::endl;

    // Loop to allow multiple tests until user decides to exit.
    while(num != 0){
        std::cin >> num;  // Input selection from user

        // Execute the appropriate test based on the user input.
        if(num == 1){
            Vector<int> vec0;
            std::cout << "Vec0's initial capability: " << vec0.size() << std::endl;
            std::cout << "We try to push back 10 elements into vec0" << std::endl;
            vec0.push_back(10);
        } else if(num == 2){
            int vec1_cap;
            std::cout << "Enter initial capacity for Vec1: ";
            std::cin >> vec1_cap;
            Vector<int> vec1(vec1_cap);
            vec1.push_back(20);
            std::cout << "Size after adding elements: " << vec1.size() << std::endl;
        } else if(num == 3){
            Vector<int> vec1(5);
            vec1.push_back(20);
            Vector<int> vec2 = vec1;
            std::cout << "Size of copied vector: " << vec2.size() << std::endl;
        } else if(num == 4){
            Vector<int> vec1(5);
            vec1.push_back(20);
            vec1.~Vector();
            std::cout << "Size after destructing: " << vec1.size() << std::endl;
        } else if(num == 5){
            Vector<int> vec1(5);
            vec1.push_back(20);
            std::cout << "Element at index 0: " << vec1[0] << std::endl;
            std::cout << "Element at index 1: " << vec1[1] << std::endl;
        } else if(num == 6){
            Vector<int> vec1(5);
            vec1.push_back(20);
            std::cout << "Element at index 0: " << vec1.at(0) << std::endl;
            std::cout << "Element at index 1: " << vec1.at(1) << std::endl;
        } else if(num == 7){
            Vector<int> vec1(5);
            vec1.push_back(20);
            std::cout << "Size of vector: " << vec1.size() << std::endl;
        } else if(num == 8){
            Vector<int> vec1(5);
            vec1.push_back(20);
            vec1.push_back(30);
            std::cout << "Size of vector after pushing back: " << vec1.size() << std::endl;
        } else if(num == 9){
            Vector<int> vec1(5);
            vec1.push_back(20);
            vec1.clear();
            std::cout << "Size of vector after clearing: " << vec1.size() << std::endl;
        } else if(num == 10){
            Vector<int> vec1;
            std::cout << "Is vector empty: " << (vec1.empty() ? "Yes" : "No") << std::endl;
        }
    }
    
}
