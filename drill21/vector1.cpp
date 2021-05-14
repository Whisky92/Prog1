#include "../std_lib_facilities.h"

struct Item
{
    string name;
    int iid;
    double value;

    Item(){};
    Item(string n, int id, double val):name (n), iid(id), value(val){}

    
};

void sort_by_name(vector<Item>& v){
    sort(v.begin(), v.end(), [](const Item& a, const Item& b){return a.name < b.name;}
        );
}

void sort_by_iid(vector<Item>& v){
    sort(v.begin(), v.end(), [](const Item& a, const Item& b){return a.iid < b.iid;}
        );
}

void sort_by_value(vector<Item>& v){
    sort(v.begin(), v.end(), [](const Item& a, const Item& b){return a.value > b.value;}
        );
}

struct find_by_name{
    string nm;
    find_by_name(string n): nm(n) {};
    bool operator() (const Item it){return it.name == nm;}

};

struct find_by_iid{
    int id;
    find_by_iid(int d): id(d) {};
    bool operator() (const Item it){return it.iid == id;}

};



int main(){

vector<Item> vi;
Item item;
ifstream in;
string val;
in.open("input.txt");
while (!in.eof())
{
    getline(in,item.name,';');
    getline(in,val,';');
    item.iid= stoi(val);
    getline(in,val);
    item.value=stod(val);
    vi.push_back(item);
    
}

cout<<"original:"<<endl;
for (auto i :vi)
    cout<<i.name<<' '<<i.iid<<' '<<i.value<<' '<<endl;
cout<<endl;


sort_by_name(vi);

cout<<"sort by name:"<<endl;
for (auto i :vi)
    cout<<i.name<<' '<<i.iid<<' '<<i.value<<' '<<endl;
cout<<endl;


sort_by_iid(vi);

cout<<"sort by iid:"<<endl;
for (auto i :vi)
    cout<<i.name<<' '<<i.iid<<' '<<i.value<<' '<<endl;
cout<<endl;


sort_by_value(vi);

cout<<"sort by value in order of decreasing:"<<endl;
for (auto i :vi)
    cout<<i.name<<' '<<i.iid<<' '<<i.value<<' '<<endl;
cout<<endl;


item.name="horse shoe";
item.iid=99;
item.value=12.34;
vi.push_back(item);

item.name="Canon S400";
item.iid=9988;
item.value=499.95;
vi.push_back(item);

cout<<"after inserting:"<<endl;
for (auto i :vi)
    cout<<i.name<<' '<<i.iid<<' '<<i.value<<' '<<endl;
cout<<endl;


vi.erase(find_if(vi.begin(), vi.end(), find_by_name("Khadeeja")));
vi.erase(find_if(vi.begin(), vi.end(), find_by_name("Haleema")));

cout<<"after erase by name:"<<endl;
for (auto i :vi)
    cout<<i.name<<' '<<i.iid<<' '<<i.value<<' '<<endl;
cout<<endl;


vi.erase(find_if(vi.begin(), vi.end(), find_by_iid(5)));
vi.erase(find_if(vi.begin(), vi.end(), find_by_iid(7)));

cout<<"after erase by iid:"<<endl;
for (auto i :vi)
    cout<<i.name<<' '<<i.iid<<' '<<i.value<<' '<<endl;
cout<<endl;

in.close();


return 0;
}