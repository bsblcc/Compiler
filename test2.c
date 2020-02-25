






int main()
{

	struct T
	{
		int a, b, c;

	};

	int d;
	struct T tmp;
	struct T *p;
	p = &tmp;


	p->a = 1;
	p->b = 10;
	p->c = 1;

	while (p->a != p->b)
	{
		p->c = (p->a) * (p->c);

		p->a = (p->a) + 1;
	}









	@(p->c);

	return 0;

}