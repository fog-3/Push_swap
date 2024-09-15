#include <unistd.h>

int atoi(const char *nptr)
{
	int	res;
	int	neg;
	int	i;

	neg = 1;
	res = 0;
	i = 0;
	while (nptr[i] == '\n' || nptr[i] == ' ' || nptr[i] == '\t'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-')
		neg *= -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return (res * neg);
}

int	main(int argc, char **argv)
{
	char	*stack_a;
	char	*stack_b;
	int	tam;

	if (argc == 2)
		tam = parse_1(argv[1]);
	else if (argc > 2)
		tam = parse_2(argv);	
	return (0);
}
