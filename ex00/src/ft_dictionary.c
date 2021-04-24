#include <stdlib.h>
#include <stdio.h>
#include "ft_dictionary.h"
#include "ft_split.h"

t_dict 	*ft_dictcreate(int nlines)
{
	t_dict	*dict_new;
	dict_new = (t_dict	*) malloc(sizeof(t_dict));
	if (!(dict_new))
		return (NULL);
	dict_new->size_max = nlines;
	dict_new->size = 0;
	dict_new->words = (t_dict_word **) malloc(nlines * sizeof(t_dict_word *));
	return (dict_new);
}

void	ft_destroydict(t_dict *dict)
{
	free(dict);
}


t_dict_word	*ft_dictaddword(t_dict 	*dict, char *word, int value)
{
	t_dict_word	*word_new;

	word_new = (t_dict_word	*) malloc(sizeof(t_dict_word));
	if (word || value || dict)
		;
	if (!(word_new))
		return (NULL);
	word_new->size = 0;
	word_new->word = ft_strdup(word);
	word_new->value = value;
	dict->words[dict->size++] = word_new;
	return (word_new);
}

void	ft_dictsort(t_dict 	*dict)
{
	int	i;
	int	j;
	t_dict_word *swap;
	i = 0;
	while (i < dict->size - 2)
	{
		j = 0;
		while (j < dict->size - i - 1)
		{
			if (dict->words[j]->value < dict->words[j + 1]->value)
			{
				swap = dict->words[j];
				dict->words[j] = dict->words[j + 1];
				dict->words[j + 1] = swap;
			}
			j++;
		}
		i++;
	}
}


void	ft_dictprint(t_dict 	*dict)
{
	int	i;
	printf("\n\n_______DICT\t");
	printf("Dict size: %d\t", dict->size);
	printf("Dict size_max: %d\n", dict->size_max);
	i = 0;
	while (i < dict->size)
	{
		printf("\n\t______WORD %d\t", i);
		printf("Word size: %d\t", dict->words[i]->size);
		printf("Word value: %d\t", dict->words[i]->value);
		printf("Word word: %s\t", dict->words[i]->word);
		i++;
	}
}
