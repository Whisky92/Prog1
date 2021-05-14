#include "../std_lib_facilities.h"

template <typename T1, typename T2>
void my_copy(vector<T1> v1, vector<T2>& v2)
{
    for(auto val : v1)
    {
        v2.push_back((T2) val);
    }
}

template<typename T>
T sum (vector<T> v)
{
    T sum=0;
    for(T val : v)
    {
        sum+=val;
    }

    return sum;
}

int main()
{
    vector<double> vd;

    ifstream f ("input2.txt");
    double temp;
    while(!f.eof())
    {
        f>>temp;
        vd.push_back(temp);
    }
    cout<<"Vector vd: ";
    for(auto v : vd)
        cout<< v << (v==vd[vd.size()-1] ? "" : ", ");

    vector<int> vi;
    my_copy(vd, vi);
    cout<<"\nVector vi: ";
    for(auto v : vi)
        cout<< v << (v==vi[vi.size()-1] ? "" : ", ");

    cout<<"Pairs:"<<endl;
    for(int i=0; i<vi.size(); i++)
    {
        cout<<"<"<< vd[i] <<","<< vi[i] <<">"<<endl;
    }

    double vd_sum = sum(vd);
    cout<<"Sum of vd: "<< vd_sum <<endl;

    cout<<"Difference between sum of vd and vi: ";
    cout<<vd_sum - (sum(vi)) <<endl;

    reverse(vd.begin(), vd.end());
    cout<<"Reversed vd: ";
    for(auto v : vd)
        cout<< v << (v==vd[vd.size()-1] ? "" : ", ");

    double mean = vd_sum/vd.size();
    cout<<"\nMean value: "<<mean<<endl;

    vector<double> vd2 (vd.size());
    copy_if(vd.begin(), vd.end(), vd2.begin(), [&] (const double a) {return a<mean;});
    cout<<"vd2 values: ";
    for(auto v : vd)
        cout<< v << (v==vd[vd.size()-1] ? "" : ", ");

    cout<<"\nvd values sorted: ";
    sort(vd.begin(), vd.end());
    for(auto v : vd)
        cout<< v << (v==vd[vd.size()-1] ? "" : ", ");
    cout << endl;


    return 0;
}