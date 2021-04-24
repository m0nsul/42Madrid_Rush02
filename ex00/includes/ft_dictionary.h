#ifndef FT_DICTIONARY_H
# define	FT_DICTIONARY_H
# define	DEFAULT_DICT "numbers.dict"
typedef struct s_dict_word
{
	unsigned int	value;
	unsigned int	size;
	char			*str;

}	t_dict_word;
typedef struct s_dict
{
	int				size;
	t_dict_word		**words;
}	t_dict;
t_dict 		*ft_dictcreate(void);
t_dict_word	*ft_dictaddword(t_dict 	*dict);
#endif