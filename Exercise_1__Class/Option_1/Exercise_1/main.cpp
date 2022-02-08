/*
Вариант 1.

1. Разработать и реализовать класс Person, содержащий члены для хранения ФИО, возраста, average score on the assessment.
2. Определить массив объектов.
3. Разработать функции для сортировки массива по среднему баллу и нахождения среднего возраста всех объектов класса Person.
*/

#include <iostream>
#include <vector>
#include <time.h> // Just for random numbers generating
#include <algorithm>
#include "person.h"

using namespace std;

#define MAX_AGE     (100)

void PrintPersons(vector<Person> &persons)
{
    for (Person &person : persons)
    {
        cout << "Name: " << person.GetName() << ", Age: " << person.GetAge() << ", AvgScore: " << person.GetAverageScore() << endl;
    }
}

void SortByAverageScore(vector<Person> &persons, bool isAscendingOrder = true)
{
    std::sort(persons.begin(), persons.end(), [&isAscendingOrder](Person a, Person b) {
        if (isAscendingOrder)
            return a.GetAverageScore() > b.GetAverageScore();
        else
            return a.GetAverageScore() < b.GetAverageScore();
    });
}

double FindAverageAgeOfPersons(vector<Person> &persons)
{
    double averageAge = 0.0;
    size_t personsCount = persons.size();

    if (personsCount == 0) return 0;

    for (Person &person : persons)
    {
        averageAge += person.GetAge();
    }

    return averageAge / personsCount;
}

int main()
{
    srand(time(NULL));

    vector<Person> personsArray = {
        Person("Person_1", rand() % MAX_AGE, (rand() % 1000) / 100.0 ),
        Person("Person_2", rand() % MAX_AGE, (rand() % 1000) / 100.0),
        Person("Person_3", rand() % MAX_AGE, (rand() % 1000) / 100.0),
        Person("Person_4", rand() % MAX_AGE, (rand() % 1000) / 100.0),
        Person("Person_5", rand() % MAX_AGE, (rand() % 1000) / 100.0)
    };

    PrintPersons(personsArray);
    cout << endl;

    cout << "Average age of persons: " << FindAverageAgeOfPersons(personsArray) << endl;

    cout << endl;
    SortByAverageScore(personsArray);
    PrintPersons(personsArray);

    return 0;
}
