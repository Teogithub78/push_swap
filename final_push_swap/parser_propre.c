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

int	check_size(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(str[i])
	{
		if (str[i] > '0' && str[i] < '9')
			while (str[i] && str[i] >= '0' && str[i] <= '9')
			{
				i++;
				j++;
				if (j > 10)
					return (-1);
			}
	}
	return (0);
}

int		ft_check_chars(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			if (str[i] == '-' || str[i] == '+' || str[i] == ' '|| str[i] == '\0')
			;
			else
				return (-1);
		}
		i++;
	}
	return (1);
}



int		ft_check(char	*str)
{
	if (ft_check_chars(str) < 0 || ft_check_signs(str) < 0 || check_size(str < 0))
	{
		ft_putstr("ERROR");
		return (-1);
	}

	return (1);

}
