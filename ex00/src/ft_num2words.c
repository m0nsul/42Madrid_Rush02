#include "ft_dictionary.h"
#include "ft_str.h"
#include <stdio.h>

void	ft_num2words(unsigned int nb, t_dict *dict, char *words)
{
	int	i;
	int	div;
	int	mod;

	i = 0;
	while (i < dict->size_max)
	{
		if (dict->words[i]->is_valid && dict->words[i]->value != 0)
		{
			printf("\n__");
			printf("\nNb: %u, value: %u", nb, dict->words[i]->value);
			div = nb / dict->words[i]->value;
			mod = nb % dict->words[i]->value;
			printf(", Div: %d\tMod: %d", div, mod);
			if (div == 1 && mod == 0)
			{
				ft_strcat(words, dict->words[i]->word);
				ft_strcat(words, " ");
				printf ("\n----> %s\n", words);
				break ;
			}
			else if (div >= 1)
			{				
				ft_num2words(div, dict, words);
				ft_strcat(words, dict->words[i]->word);
				ft_strcat(words, " ");
				ft_num2words(mod, dict, words);
				break ;
			}
		}
		i++;
	}
}