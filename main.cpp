#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>

using namespace std;

int main()
{
    ifstream infile;
    infile.open("C:\\student.dat");

    if (!infile.is_open())
    {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    int totalBoys = 0, totalGirls = 0, totalStudents = 0;
    int sumAgeBoys = 0, sumAgeGirls = 0, sumAgeAll = 0;
    string gender;
    int age;

    while (infile >> gender >> age)
    {
        if (gender == "B")
        {
            totalBoys++;
            sumAgeBoys += age;
        } else if (gender == "G")
        {
            totalGirls++;
            sumAgeGirls += age;
        }
        totalStudents++;
        sumAgeAll += age;
    }

    infile.close();

    double avgAgeBoys = totalBoys ? float(sumAgeBoys) / totalBoys : 0;
    double avgAgeGirls = totalGirls ? float(sumAgeGirls) / totalGirls : 0;
    double avgAgeAll = totalStudents ? float(sumAgeAll) / totalStudents : 0;

    cout << "Average age of Boys: " <<fixed<<setprecision(1)<< avgAgeBoys << endl;
    cout << "Average age of Girls: " <<fixed<<setprecision(1)<< avgAgeGirls << endl;
    cout << "Average age of All Students: " <<fixed<<setprecision(1)<< avgAgeAll << endl;

    return 0;
}
