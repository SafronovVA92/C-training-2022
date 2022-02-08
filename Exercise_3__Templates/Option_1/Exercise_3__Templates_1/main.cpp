#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>

#define VECTOR_SIZE         (5)

using namespace std;

template <typename T>
void PrintVector(string title, vector<T> vector)
{
    cout << title << endl;
    std::for_each(vector.begin(), vector.end(), [](const T& a) {
        cout << a << endl;
    });

    cout << endl;
}

// Вариант 1.
// Напишите шаблонную функцию, складывающую векторы элементов любых типов, допускающих сложение.

template <typename T>
vector<T> AddVectors(vector<T> op1, vector<T> op2)
{
    vector<T> result;

    result.resize(op1.size());

    std::transform(op1.begin(), op1.end(), op2.begin(), result.begin(), [](const T& a, const T& b) {
        return a + b;
    });

    return result;
}

int main()
{
    srand(time(NULL));

    vector<int> firstOp, secondOp;
    for (int i = 0; i < VECTOR_SIZE; i++)
    {
        firstOp.push_back(rand()%100);
        secondOp.push_back(rand()%100);
    }

    PrintVector("First vector", firstOp);
    PrintVector("Second vector", secondOp);

    vector<int> resultVector = AddVectors(firstOp, secondOp);
    PrintVector("ResultVector", resultVector);

    return 0;
}
