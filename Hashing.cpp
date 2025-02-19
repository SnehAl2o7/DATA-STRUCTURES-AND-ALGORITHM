#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, double> umap = {
        {"one", 1}, {"Two", 2}, {"Three", 3}};
    // inserting value by using [] operator
    umap["PI"] = 3.14;
    umap["root2"] = 1.414;
    umap["root3"] = 1.732;
    umap["log10"] = 2.302;
    umap["loge"] = 1.0;

    // inserting value using insert function
    umap.insert(make_pair("e", 2.718));

    string key = "PI";

    // if key not found in map
    //  to end is returned
    if (umap.find(key) == umap.end())
    {
        cout << key << "not found\n";
    }
    else
    {
        cout << "Found " << key << "\n";
    }

    key = "lambda";
    if (umap.find(key) == umap.end())
    {
        cout << key << " not found\n";
    }
    else
    {
        cout << key << " Found" << endl;
    }
    // iterating over all the values of map
    unordered_map<string, double>::iterator itr;
    cout << "All Elements"
         << endl;
    for (itr = umap.begin(); itr != umap.end(); itr++)
    {
        cout << itr->first << " : " << itr->second << endl;
    }
    return 0;
}
