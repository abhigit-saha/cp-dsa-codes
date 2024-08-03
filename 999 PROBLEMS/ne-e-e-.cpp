include<iostream>
#include <vector>
#include <map>

    using namespace std;

int main()
{
    int numElements, numQueries;
    vector<int> elements, queries;
    map<int, int> gcdMap;

    // Read the number of elements
    if (!(cin >> numElements))
    {
        cerr << "Error reading the number of elements" << endl;
        return 1; // or handle the error in another appropriate way
    }

    // Read the elements
    for (int i = 0; i < numElements; i++)
    {
        int element;
        if (!(cin >> element))
        {
            cerr << "Error reading element " << i << endl;
            return 1; // or handle the error in another appropriate way
        }
        elements.push_back(element);
    }

    // Read the number of queries
    if (!(cin >> numQueries))
    {
        cerr << "Error reading the number of queries" << endl;
        return 1; // or handle the error in another appropriate way
    }

    // Read the queries
    for (int i = 0; i < numQueries; i++)
    {
        int query;
        if (!(cin >> query))
        {
            cerr << "Error reading query " << i << endl;
            return 1; // or handle the error in another appropriate way
        }
        queries.push_back(query);
    }

    // Continue with your logic...
    for (int i = 0; i < numElements; i++)
    {
        // ...
    }

    return 0;
}