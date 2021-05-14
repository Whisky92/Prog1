  
#include "../std_lib_facilities.h"

using namespace std;

struct Item 
{
    string name;
    int iid;
    double value;
};

template <typename T>
void print(T v)
{
    for( auto val : v)
        {
            cout<<val.name << " " << val.iid<< " " << val.value<<endl;
        }
}

bool by_name(const Item a, const Item b)
{
    return a.name < b.name;
}

bool by_iid (const Item a, const Item b)
{
    return a.iid < b.iid;
}

struct find_by_name
{
    string nm;
    find_by_name(string n) : nm{n} {}
    bool operator() (const Item it){return it.name == nm;}
};

struct find_by_iid
{
    int id;
    find_by_iid(int i) : id{i} {};
    bool operator() (const Item it){return it.iid == id;}
};



int main()
{
    list<Item> li;
    ifstream f;
    f.open("input.txt");
    Item temp;
    string val;
    while(!f.eof())
    {
        getline(f, temp.name, ';');
        getline (f, val, ';');
        temp.iid = stoi(val);
        getline(f, val);
        temp.value = stod(val);
        li.push_back(temp);
    }
    
    cout<<"Original:"<<endl;
    print(li);

    cout<<"\nBy name:"<<endl;
    li.sort(by_name);
    print(li);

    cout<<"\nBy iid:"<<endl;
    li.sort(by_iid);
    print(li);

    cout<<"\nBy value decrease:"<<endl;
    li.sort(
        [] (const Item a, const Item b){return a.value>b.value;}
        );
    print(li);

    Item insert1 = {"Horse shoe", 99, 12.34};
    Item insert2 = {"Canon S400", 9988, 499.95};

    cout<<"\nAfter insert:"<<endl;
    li.insert(li.begin(), insert1);
    li.insert(li.begin(), insert2);
    print(li);
    li.erase(find_if(li.begin(), li.end(), find_by_name("Khadeeja")));
    li.erase(find_if(li.begin(), li.end(), find_by_name("Haleema")));

    li.erase(find_if(li.begin(), li.end(), find_by_iid(99)));
    li.erase(find_if(li.begin(), li.end(), find_by_iid(9988)));

    cout<<"\nAfter insert and erase:"<<endl;
    print(li);

    return 0;