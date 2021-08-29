#include <iostream>
#include <map> //stl map
#include <iterator> //an object that enables to traverse a container

/*
Get full information of STL map below:
https://www.cplusplus.com/reference/map/map/
*/
using namespace std;

int main()
{
    //how to declare a map variable?
    map<string, int> scores;
    //map<key, value>

    //how to add data inside a map?
    scores.insert(pair<string,int>("ST00001", 100));
    scores.insert(pair<string,int>("ST00002", 99));
    scores.insert(pair<string,int>("ST00003", 88));
    scores.insert(pair<string,int>("ST00004", 77));
    scores.insert({"ST00005", 66});

    //how to find data inside a map?
    //use iterator to find data inside a map
    if(scores.find("ST00005") != scores.end()) //if data is not found, the iterator returns map.end()
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" <<endl;
    }

    //how to iterate data inside a map?
    //1. for loop (using iterator)
    for(auto iter = scores.begin(); iter!= scores.end(); ++iter)
    {
        cout << "Key(" << iter->first << ") Value(" <<iter->second << ")\n";
    }
    cout<<"\n";

    //2. for each loop (using iterator)
    for(auto sc : scores)
        cout << "Key(" << sc.first << ") Value(" << sc.second << ")\n";
    cout<<"\n";

    //How to access element inside a map?
    //using operator[] for at
    cout << scores["ST00001"] << endl;
    cout << scores.at("ST00002") <<endl;
    scores["ST00001"] = 1;
    scores.at("ST00002") = 2;
    cout << scores["ST00001"] << endl;
    cout << scores.at("ST00002") <<endl;

    //how to get capacity of a map?
    cout << "\nMap size: " << scores.size() <<"\n";

    //how to delete data from a map?
    //type1. at a particular position using iterator
    scores.erase(scores.begin());
    //type2. using key
    scores.erase("ST00005");

    for(auto sc : scores)
        cout << "Key(" << sc.first << ") Value(" << sc.second << ")\n";
    cout<<"\n";

    //type3. all elements
    scores.erase(scores.begin(), scores.end());
    scores.clear();

    //below will note be printed
    for(auto sc : scores)
        cout << "Key(" << sc.first << ") Value(" << sc.second << ")\n";
    cout<<"\n";

    return 0;
}
