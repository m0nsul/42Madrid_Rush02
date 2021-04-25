#include "ft_dictionary.h"
#include "ft_str.h"
#include "ft_others.h"

#include <stdio.h>

void	ft_num2words(unsigned int nb, t_dict *dict, char *words, int pow)
{
	int	i;
	int	div;
	int	mod;

	i = 0;
	while (i < dict->size_max)
	{
		if (dict->words[i]->is_valid && dict->words[i]->value != 0)
		{
			printf("\nNb: %u, pow: %d, value: %u", nb, pow, dict->words[i]->value);
			div = nb / dict->words[i]->value;
			mod = nb % dict->words[i]->value;
			printf(", Div: %d\tMod: %d", div, mod);
			if (div == 1 && mod == 0)
			{

				ft_strcat(words, dict->words[i]->word);
				ft_strcat(words, " ");
				break ;
			}
			else if (div >= 1)
			{				
				if (pow > 3)
					ft_num2words(div, dict, words, pow);
				ft_strcat(words, dict->words[i]->word);
				if (pow == 4)
					ft_strcat(words, " and ");
				else
					ft_strcat(words, " ");
				ft_num2words(mod, dict, words, ft_numdigits(dict->words[i]->value));
				break ;
			}
		}
		i++;
	}
}