#include "std_lib_facilities.h"

struct Person
{
private:
	string first_name;
	string second_name;
	int age;
public:
	Person() {}
	Person(string fn, string sn, int a) : first_name(fn),second_name(sn), age(a) //; : " ' [ ] * & ^ % $ #
	{
		for (int i = 0; i < first_name.length(); ++i)
			if (first_name[i] == ';' or first_name[i] == ':' or first_name[i] == '"' or first_name[i] == '\'' or first_name[i] == '*' or 
				first_name[i] == '&' or first_name[i] == '^' or first_name[i] == '%' or first_name[i] == '$' or first_name[i] == '#' or
				first_name[i]=='@' or first_name[i]=='!')
					error("Invalid character found in first name");
		for (int i = 0; i < second_name.length(); ++i)
			if (second_name[i] == ';' or second_name[i] == ':' or second_name[i] == '"' or second_name[i] == '\'' or second_name[i] == '*' or
				second_name[i] == '&' or second_name[i] == '^' or second_name[i] == '%' or second_name[i] == '$' or second_name[i] == '#' or
				second_name[i] == '@' or second_name[i] == '!')
				error("Invalid character found in second name");
		if (age < 0 || age > 150)
			error("Invalid age!");
		for (int i = 0; i < second_name.length(); i++)
		{
			if (!isalpha(second_name[i]))
				error("Name forgotten");
		}
	}

	string getfirstname() const { return first_name; }
	string getsecondname() const { return second_name; }
	int getage() const { return age; }
	void setfirstname(string n) 
	{
		for (int i = 0; i < n.length(); ++i)
			if (n[i] == ';' or n[i] == ':' or n[i] == '"' or n[i] == '\'' or n[i] == '*' or
				n[i] == '&' or n[i] == '^' or n[i] == '%' or n[i] == '$' or n[i] == '#' or
				n[i] == '@' or n[i] == '!')
				error("Invalid character found");
		first_name = n;
	}
	void setsecondname(string n)
	{
		for (int i = 0; i < n.length(); ++i)
			if (n[i] == ';' or n[i] == ':' or n[i] == '"' or n[i] == '\'' or n[i] == '*' or
				n[i] == '&' or n[i] == '^' or n[i] == '%' or n[i] == '$' or n[i] == '#' or
				n[i] == '@' or n[i] == '!')
				error("Invalid character found");

		for (int i = 0; i < n.length(); i++)
		{
			if (!isalpha(n[i]))
				error("Name forgotten");
		}

		second_name = n;
	}
	void setage(int a) { 
		if (a < 0 || a > 150)
			error("Invalid age!"); 
		age = a; }

	friend ostream& operator << (ostream& os, Person& p);
	friend istream& operator >>(istream& is, Person& p);
};


ostream& operator <<(ostream& os, Person& p)
{
	os << "first name: " << p.getfirstname() <<", second name: " <<p.getsecondname()<< ", age:" << p.getage();
	return os;
}

istream& operator >>(istream& is, Person& p)
{
	string personfirstname, personsecondname;
	int personage;

	is >> personfirstname>> personsecondname >> personage;
	p.setfirstname(personfirstname);
	p.setsecondname(personsecondname);
	p.setage(personage);

	return is;

}

int main()
{
	Person Goofy{ "Kis","Goofy",63 };
	cout << "The person's name: " << Goofy.getfirstname() <<" " << Goofy.getsecondname() << endl;
	cout << "The person's age: " << Goofy.getage() << endl;
	Person p2;
	cout << "Enter the name and the age of the person" << endl;
	cin >> p2;
	cout << p2 << endl;
	vector <Person> v;
	for (Person p; cin >> p;)
	{
		if (p.getfirstname() == "end")
			break;
		else v.push_back(p);
	}
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << endl;
	}
	return 0;
}