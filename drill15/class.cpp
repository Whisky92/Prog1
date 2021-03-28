#include "std_lib_facilities.h"

struct Person{
	Person(){}
	Person(string f, string l, int a); //first name - last name - age
	string get_first_name() const {return first;}
	string get_last_name() const {return last;}
	int get_age() const {return age;}

private:
	string first, last;
	int age;
};

Person::Person(string f, string l, int a) : first{f}, last{l}, age{a}
{
	if (a < 0 || a > 150) error("Invalid age!"); //initializing age

	//checking first name
	for (int i = 0; i < f.size(); ++i)
	{
		if (!isalpha(f[i]))
		{
			error("Not allowed character in first name");
		}
	}
	//checking last name
	for (int i = 0; i < l.size(); ++i)
	{
		if (!isalpha(l[i]))
		{
			error("Not allowed character in last name");
		}
	}
}

ostream& operator<<(ostream& os, Person& p)
{
	return os << p.get_first_name() << ' ' << p.get_last_name() << ' ' << p.get_age();
}
istream& operator>>(istream& is, Person& p)
{
	string i_first, i_last;
	int i_age;

	cout << "Enter your first name, last name and age!" << endl;
	is >> i_first >> i_last >> i_age;
	if (!is) /* amennyiben hianyzik egy argumentum -> hiba */ error("Unable to read into Person");
															//nem igazan mukodik ugy ahogy kene
	p = Person(i_first, i_last, i_age);
	return is;
}

vector<Person> vector_persons;
bool is_terminated = false;

int main()
try {
	Person p1 {"Goofy", "", 63};
	cout << p1 << endl;
	cout << endl;

	Person p2;
	cin >> p2;
	cout << p2 << endl;
	cout << endl;
	
	cout << "Enter some data of persons" << endl;
	cout << "Termintate with typing in: quit - at the first name argument" << endl;
	
	for(Person p; cin >> p;)
	{
		if (p.get_first_name() == "quit") {
			is_terminated = true;
			break;}
		else vector_persons.push_back(p);
	}
	cout << endl;
	for (int i = 0; i < vector_persons.size(); ++i)
	{
		cout << vector_persons[i] << endl;
	}
	if (is_terminated) cout << "Successfully terminated..." << endl;

	return 0;
}
catch (std::exception& e) {
	std::cerr << "Exception: " << e.what() << endl;
	return 1;
}