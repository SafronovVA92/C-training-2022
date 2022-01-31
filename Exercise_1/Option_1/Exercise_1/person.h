#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
private:
    std::string m_sName;
    unsigned int m_iAge;
    double m_fAverageScore;

public:
    Person(std::string sName, unsigned int iAge, double fAverageScore);

    std::string GetName() { return m_sName; }
    void SetName(std::string& sName) { m_sName = sName; }

    unsigned int GetAge() { return m_iAge; }
    void SetAge(unsigned int& iAge) { m_iAge = iAge; }

    double GetAverageScore() { return m_fAverageScore; }
    void SetAverageScore(double& fAverageScore) { m_fAverageScore = fAverageScore; }
};

#endif // PERSON_H
