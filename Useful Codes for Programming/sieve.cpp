void sieve(int n)
{
	for(int i=2;i<=n;++i)
	{
		if(primes[i] == 0)
		{
			int current = 2*i;

			while(current <= n)
			{
				primes[current] = i;
				current += i;
			}
		}
	}
}