

struct Pair
{
	int x;
	int y;
	int n;
	struct Pair* next;
};


int fb(int i)
{
	if (i == 1)
	{
		return 1;
	}
	else 
	{
		if (i == 2)
		{
			return 2;
		}
	}

	return fb(i - 1) + fb(i - 2);
}

/*
int cal(struct Pair *p)
{


	
	if ((p->y) * fb(p->x) > 1000)
	{
		return p->n;
	}
	else
	{
		p->n = (p->x) * (p->y);
		(p->x)++;
		(p->y)++;
		
	}
	return cal(p);

}
*/
int main()
{
	



	struct Pair array[10];

	struct Pair a;

	int sum = 0;

	array[6].x = 2;
	array[6].y = 7;
	array[6].n = 0;


	a = array[6];
	a.x = 7;
	
	array[6].n = fb(a.x);

	//int d = sum;
	@(array[6].n);
	//array[5].y = a.x;



	//array[5].y = getSum(a.x, a.y);
	return 0;
}