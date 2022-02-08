#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

#define TEST_ARR_SIZE       (5)


auto printVector = [](const int& element)
{
    cout << element << endl;
};

int main()
{
    srand(time(0));

    // Вариант 1.
    // 1.	Создать лямбда-выражение для вывода элементов вектора.
    // 2.	Создать лямбда-выражение для подсчета количества перестановок при выполнении сортировки элементов вектора.
    int exchangesCount = 0;

    vector<int> inputVector;
    for (int i = 0; i < TEST_ARR_SIZE; i++)
        inputVector.push_back(rand()%100);

    std::for_each(inputVector.begin(), inputVector.end(), printVector);

    std::sort(inputVector.begin(), inputVector.end(), [&exchangesCount](int a, int b) {
        exchangesCount++;
        return a < b;
    });

    cout << "\nExchangesCount: " << exchangesCount << endl;

    std::for_each(inputVector.begin(), inputVector.end(), printVector);

    return 0;
}
