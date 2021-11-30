#include "push_swap.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

size_t			ft_splitstrlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	ft_putstr("DST == |");
	ft_putstr(dst);
	ft_putstr("|\n1");
	return (i);
}

size_t			ft_count_words(char const *s, char c)
{
	size_t	i;

	i = 0;
	//write(1, "P\n", 2);

	while (*s)
	{
	//	write(1, "o\n", 2);
		while (*s == c && *s)
		{
			s++;
			if (*s == '\0')
				return (i);
		}
		while (*s != c && *s)
		{
			s++;
			if (*s == '\0')
			{
				i++;
				return (i);
			}
		}
		i++;
	}
	return (i);
}

static char		**ft_free(char const **tab, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free((void *)tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

char			**ft_fill_row(char **dst, char const *src, char c)
{
	size_t	j;
	size_t	k;
	size_t	row;

	j = 0;
	k = 0;
	row = 0;
	while (src[j])
	{
		while (src[j] == c)
			j++;
		k = j;
		while (src[j] != c && src[j])
		{
			j++;
			if (!src[j] || src[j] == c)
			{
				if (!(dst[row] = (char *)malloc(sizeof(char) * (j - k + 1))))
					return (ft_free((char const **)dst, row));
				ft_splitstrlcpy(dst[row++], src + k, (j - k));
			}
		}
	}
	printf("ROW =\t|%li|\n", row);
	dst[row] = NULL;
	return (dst);
}

char			**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;

	if (s == NULL)
		return (0);
	i = ft_count_words(s, c);
	if (!(str = malloc(sizeof(char *) * (i + 1))))
		return (0);
	return (ft_fill_row(str, s, c));
}


size_t	ft_totallen(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		i++;
	}
	while (s2[j++])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	j = 0;
	k = 0;
	if (!s1 || !s2)
		return (0);
	i = ft_totallen(s1, s2);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (0);
	while (s1[k] && j < i)
	{
		str[j++] = s1[k++];
	}
	k = 0;
	while (s2[k] && j < i)
	{
		str[j++] = s2[k++];
	}
	str[j] = '\0';
	return (str);
}

int	ft_super_len(int ac, char **av)
{
	size_t	i;
	int	j;
	int	total;

	j = 0;
	i = 1;
	total = 0;
	while (i < ac)
	{
		while (av[i][j])
		{
			total++;
			j++;
		}
		i++;
		j = 0;
		total++;
	}
	return (total);
}

int		ft_check_signs(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i - 1] != ' ')
			{
				write(1, "ICI\n", 4);
				return (-1);
			}
			i++;
			if (str[i] < '0' || str[i] > '9')
			{
				write(1, "LA\n", 3);

				return (-1);

			}
		}
		i++;
	}
	return(1);
}

int		ft_check_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			if (str[i] == '-' || str[i] == '+' || str[i] == ' '|| str[i] == '\0')
			;
			else
			{
				write(1, "|", 1);

				//write(1, &str[i], 1);
				write(1, "|\n", 2);

				write(1, "PROUT\n", 6);
				return (-1);
			}
		}
		i++;
	}
	return (1);
}

int		ft_check(char	*str)
{
	if (ft_check_chars(str) < 0 || ft_check_signs(str) < 0)
	{
		ft_putstr("ERROR");
		return (-1);
	}
	return (1);

}

char	*ft_super_join(int ac, char **av)
{
	char	*str;
	char	*save;
	size_t i;
	size_t j;
	size_t k;

	k = 0;
	j= 0;
	i = ft_super_len(ac, av);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	save = str;
	i = 1;
	while(av[i] || i < ac)
	{
		while (av[i][j] != '\0')
		{
			*str = av[i][j++];
			str++;
			k++;
		}
		i++;
		*str = ' ';
		str++;
		k++;
		j = 0;
	}
	*str = '\0';
	k++;
	printf("save = |%s|\n", save);
	return (save);
}

int	ft_atoi_plus(node_t *list, char *str)
{
	long int li;
	long int	retour;
	int i;

	i = 0;
	retour = 0;

	while(str[i])
	{
		retour += str[i++] - 48;
		if (str[i++])
			retour = retour * 10;
	}
	if (retour > 2147483647 || retour < -2147483648)
		return (-1);

	else
		list->val = (int)retour;
	return (0);
}



int	*value_table_int(char **str)
{
	int	i;
	int j;
	int *table_int;

	i = 0;
	while(str[i])
	{
		i++;
	}
	j = i;

	table_int = (int *)malloc((sizeof(int)) * i + 1);
	if (!table_int)
		return (NULL);
	i = 0;
	while(i < j)
	{
		table_int[i] = ft_atoi_plus(table_int[i], str[i]);
		if (table_int == NULL)
		{
			free(table_int);
			return(NULL);
			ft_putstr("ERROR\n");
		}
		i++;
	}
	table_int[i] = 0;
	return(table_int);
}

int	ft_free_all(char **tab_split)
{
	int	i;

	i = 0;
	while (tab_split[i] != NULL)
	{
		free(tab_split[i]);
		i++;
		printf("FREE tab_split dans tableau = \t|%i|\n", i);
	}
	//free(tab_split[i]);
	free(tab_split);
	//printf("FREE tab_split = \t|%i|\n", i);

	return(0);
}

int main(int ac, char **av)
{
	char *str;
	char **tab_split;
	int i;
	int		*table_int;

	i = ft_super_len(ac, av);
	printf("TOTAL = |%i|\n", i);
	str = ft_super_join(ac, av);
	if (ft_check(str) < 0)
	{
		//ft_putstr("ERROR");
		free(str);
		return (-1);
	}
//	printf("|%s| AVANT SPLIT\n", str);

	tab_split = ft_split(str, ' ');
	if(tab_split == NULL)
		return (NULL);
//	printf("|%s| APRES SPLIT\n", str);
	i = 0;

	while(tab_split[i] != NULL)
	{
		printf("\nTABLEAU = %s\n", tab_split[i]);
		i++;
	}


	table_int = value_table_int(tab_split);
	if (table_int == NULL)
	{
		ft_putstr("ERROR\n");
		free (table_int);
	}
	ft_free_all(tab_split);
	write(1, "prout\n", 6);
	free(str);
	return (0);
}
