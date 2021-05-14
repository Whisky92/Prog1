#include "std_lib_facilities.h"

template<typename Container>
void print(const Container &cont)
{
	for( auto const &i : cont)
	{
		std::cout << i << " ";
	}
	std:: cout << std::endl;
}

template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	while(f1 != e1)
	{
		*f2 = *f1;
		++f1;
		++f2;
	}
	return f2;
}

int main()
{
	array<int, 10> arr={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> v {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	list<int> l {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	array<int, 10> arr2 = arr;
	vector<int> v2 = v;
	list<int> l2 = l;

	for (auto p = arr2.begin(); p!=arr2.end(); ++p)
	{
		*p += 2;
	}
    print(arr2);

    for (auto p = v2.begin(); p!=v2.end(); ++p)
    {
        *p += 3;
    }
    print(v2);

    for (auto p = l2.begin(); p!=l2.end(); ++p)
    {
        *p += 5;
    }
    print(l2);

    cout << endl;
    my_copy(arr2.begin(), arr2.end(), v2.begin());
    print(v2);

    my_copy(l2.begin(), l2.end(), arr2.begin());
    print(arr2);

    auto v_iter = std::find(v2.begin(), v2.end(), 3);
    if (v_iter != v2.end())
    {
        auto v_beg=v2.begin();
        int position=1;
        while(v_beg!=v_iter){
        	++position;
        	++v_beg;
        }
        cout << "Position of 3: " << position << endl;
    } else {
    	cout << "The vector doesn't contain 3" << endl;
    }

    auto l_iter = std::find(l2.begin(), l2.end(), 27);
    if (l_iter != l2.end())
    {
        auto l_beg=l2.begin();
        int position=1;
        while(l_beg!=l_iter){
        	++position;
        	++l_beg;
        }
        cout << "Position of 3: " << position << endl;
    } else {
    	cout << "The list doesn't contain 27" << endl;
    }

	return 0;
}