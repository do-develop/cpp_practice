#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool descending(int a, int b)
{
    return a > b;
}

class Student
{
public:
    string name;
    int score;
    Student(string name, int score)
    {
        this->name = name;
        this->score = score;
    }
    //in the ascending order of the student's score
    bool operator < (Student& student)
    {
        return this->score < student.score;
    }
};

bool compare(pair<string, pair<int, int>> a,
             pair<string, pair<int, int>> b)
             {
                 if(a.second.first == b.second.first)
                    return a.second.second > b.second.second;
                 else
                    a.second.first > b.second.first;
             }

int main(void)
{
    //simple array example
    int a[10] = {9, 3, 5, 4, 1, 10, 8, 6, 7, 2};
    sort(a, a+10, descending);
    for(int i=0; i<10; i++)
    {
        cout << a[i] << ' ';
    }

    //class type data example
    Student students[] =
    {
      Student("Juno", 99),
      Student("Magie", 30),
      Student("Clarence", 50),
      Student("Jeff", 78),
      Student("Sumo", 52)
    };
    cout << "\nStudents: ";
    sort(students, students+5);
    for(int i=0; i<5; i++)
    {
        cout << students[i].name << ' ';
    }

    //vector example 1
    vector<pair<int, string>> v;
    v.push_back(pair<int, string>(90, "Juno"));
    v.push_back(pair<int, string>(85, "Magie"));
    v.push_back(pair<int, string>(82, "Jeff"));
    v.push_back(pair<int, string>(98, "Clarence"));
    v.push_back(pair<int, string>(79, "Sumo"));

    sort(v.begin(), v.end());
    cout << "\nStudents: ";
    for(int i=0; i<v.size(); ++i)
    {
        cout << v[i].second << ' ';
    }

    //vector example 2
    vector<pair<string, pair<int, int>>> idols;
    idols.push_back(pair<string, pair<int, int>>("Juno", pair<int, int>(90, 19991031)));
    idols.push_back(pair<string, pair<int, int>>("Maya", pair<int, int>(90, 20021031)));
    idols.push_back(pair<string, pair<int, int>>("Yujin", pair<int, int>(90, 20000231)));
    idols.push_back(pair<string, pair<int, int>>("Mashiro", pair<int, int>(95, 20011031)));
    idols.push_back(pair<string, pair<int, int>>("Hikaru", pair<int, int>(80, 19901031)));

    sort(idols.begin(), idols.end(), compare);
    cout << "\nIdols: ";
    for(int i=0; i<idols.size(); ++i)
    {
        cout << idols[i].first << ' ';
    }
    return 0;
}
