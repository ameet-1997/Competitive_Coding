void do_union(int x,int y)
{
	int find_parent(int);

	int x_p,y_p;

	x_p = find_parent(x);
	y_p = find_parent(y);

	if(x_p == y_p)
	{
		return;
	}

	if(-a[x_p] > -a[y_p])
	{
		a[y_p] = x_p;
	}
	else if(-a[x_p] < -a[y_p])
	{
		a[x_p] = y_p;
	}
	else
	{
		a[y_p] = x_p;
		a[x_p]--;
	}
}


int find_parent(int x)
{
	if(a[x] < 0)
	{
		return x;
	}
	else
	{
		a[x] = find_parent(a[x]);	//Doing path compression
		return a[x];
	}
} 
