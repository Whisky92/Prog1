#include "../std_lib_facilities.h"

void fill(map<string, int>& msi){

    msi["Seb"]=7;
    msi["Haleema"]=3;
    msi["Ted"]=0;
    msi["Bobbie"]=4;
    msi["Rheanna"]=1;
    msi["Khadeeja"]=9;
    msi["Haris"]=2;
    msi["Dawid"]=6;
    msi["Abdallah"]=8;
    msi["Anis"]=5;

}

void fill_from_input(map<string, int>& msi, int n)
{
    for(int i=0; i<n; ++i)
    {
        string temp_str;
        int temp_int;
        cin >> temp_str >> temp_int;
        msi.insert({temp_str, temp_int});
    }
}

void msi_to_mis(map<string,int> msi, map<int,string>& mis)
{
    for(auto m : msi)
    {
        mis.insert({m.second, m.first});
    }
}

int main(){

    map <string, int> msi;

    cout << "Original:" << endl;
    fill(msi);
    for(auto m : msi)
    {
        cout << m.first << " " << m.second << endl;
    }


    cout << endl << "Erased:" << endl;
    msi.erase(msi.begin(), msi.end());

    for(auto m : msi)
    {
        cout << m.first << " " << m.second << endl;
    }

    int number_of_elements=10;

    cout << endl << "Type new elements: string, int" << endl;
    fill_from_input(msi, 10);
    
    cout << endl << "New:" << endl;
    for(auto m : msi)
    {
        cout << m.first << " " << m.second << endl;
    }

    int sum= 0;


    for(auto m : msi)
    {
        sum+=m.second;
    }
    cout << endl << "Sum of ints: " << sum << endl;

    map<int, string> mis;
    msi_to_mis(msi,mis);
    cout << endl << "mis: "<< endl;
    for(auto m : mis)
    {
        cout << m.first << " " << m.second << endl;
    }

}