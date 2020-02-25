#include <iostream>
using namespace std;

class A
{

};


class B: public A
{
public:
	int n;
};

#include <map>



map<A*, int> m;


int main()
{

	A *p = new B();

	A *d = p;



	m[d] = 1;



	cout << (d == static_cast<B*>(d));
	







	return 0;
}