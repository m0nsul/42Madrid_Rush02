#include <stdio.h>
int	ft_atoi (char *str);

int	ft_checkline (char *str)
{
	int	check_Num;
	int	check_Word;
	int	check_Space1;
	int	check_Space2;
	int	check;

	if (str == NULL)
		return (0);
	else
	{
		check_Num = 0;
		while (*str != ' ' && *str != ':')
		{
			if (*str >= '0' && *str <= '9')
			{
				check_Num++;
			}
			else
				return (0);
			str++;
		}
		check_Space1 = 0;
		while (*str != ':')
		{
			if (*str == ' ')
				check_Space1++;
			else
				return (0);
			str++;
		}
		check_Space1 = 1;
		check = 0;
		if (*str == ':')
			check++;
		str++;
		check_Space2 = 0;
		while (!(*str > 32 && *str <= 126))
		{
			if (*str == ' ')
				check_Space2++;
			else
				return (0);
			str++;
		}
		check_Space2 = 1;
		check_Word = 0;
		while (*str != '\0')
		{
			if (*str >= 32 && *str <= 126)
				check_Word++;
			else
				return (0);
			str++;
		}	
	}
	if (check_Num > 0 && check_Space1 > 0 && check == 1
		&& check_Space2 > 0 && check_Word > 0)
		return (1);
	else
		return (0);
}

void	ft_getlinevalues (char *str, int *value, char *phrase)
{
	int		i;
	int		j;
	char	*str_value;

	i = 0;
	str_value = NULL;
	while (*str != ':' && *str != ' ')
		i++;
	j = 0;
	while (j < i)
	{
		*(str_value + j) = *(str + j);
		j++;
	}
	*value = ft_atoi(str_value);
	while (*str != ':')
		str++;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
			*(phrase + i) = *(str + i);
		i++;
	}
}

int	ft_atoi(char *str)
{
	int	result;

	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += (int)(*str - '0');
		str++;
	}
	return (result);
}
