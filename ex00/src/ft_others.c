int	ft_numdigits(int nb)
{
	int	count;

	count = 0;
	while (nb != 0)
	{
		nb /= 10;
		++count;
	}
	return (count);
}