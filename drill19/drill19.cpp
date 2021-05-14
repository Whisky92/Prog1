#include "std_lib_facilities.h"

template<typename T> 
struct S{
private:
	T val;
public:
	S() : val(T()) {}
	S(T d) : val(d) {}

	T& get();
	const T& get() const;  

	T& operator=(const T& value){
		val=value;
		return val;
	} 
};

template<typename T> 
T& S<T>::get(){
	return val;
}

template<typename T> 
const T& S<T>::get() const{ 
	return val; 
}


template<typename T> 
istream& operator>>(istream& is, S<T>& ss) {
    T v;
    cin >> v;
    ss = v;
    return is;
}


template<typename T> 
void read_val(T& v){
    cin >> v;
}


int main(){
	S<int> s_int(11);
	S<char> s_char('k');
	S<double> s_double(23.32);
	S<string> s_str("str");
	S<vector<int>> s_vector({1,2,3});

	cout << s_int.get() << endl;
	cout << s_char.get() << endl;
	cout << s_double.get() << endl;
	cout << s_str.get() << endl;
	for (int i=0; i<s_vector.get().size(); ++i)
        cout << s_vector.get()[i] << " ";
    cout << endl;

    s_int=22;
    s_char='K';
    s_double=40.12;
    s_str="STR";
    s_vector={11,22,33};
    cout << endl << s_int.get() << endl;
	cout << s_char.get() << endl;
	cout << s_double.get() << endl;
	cout << s_str.get() << endl;
	for (int i=0; i<s_vector.get().size(); ++i)
        cout << s_vector.get()[i] << " ";
    cout << endl << endl;

    read_val(s_int);
    read_val(s_char);
    read_val(s_double);
    read_val(s_str);
    cout << endl << s_int.get() << endl;
    cout << s_char.get() << endl;
    cout << s_double.get() << endl;
    cout << s_str.get() << endl << endl;

	return 0;
}