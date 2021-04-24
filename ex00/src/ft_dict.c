#include <stdlib.h>
#include "ft_dictionary.h"

t_dict 	*ft_dictcreate(void)
{
	t_dict	*dict_new;

	dict_new = (t_dict	*) malloc(sizeof(t_dict));
	if (!(dict_new))
		return (NULL);
	dict_new->size = 0;
	return (dict_new);
}

void	ft_destroydict(t_dict *dict)
{
	free(dict);
}


t_dict_word	*ft_dictaddword(t_dict 	*dict)
{
	t_dict_word	*word_new;

	word_new = (t_dict_word	*) malloc(sizeof(t_dict_word));
	if (!(word_new))
		return (NULL);
	word_new->size = 0;
	// dict->words = (t_dict_word	**) malloc
	dict->words[dict->size + 1] = word_new;
	return (word_new);
}
