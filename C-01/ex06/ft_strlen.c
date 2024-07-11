int	ft_strlen(char *str)
{
	int		size;
	char	c;

	size = 0;
	c = *str;
	while (c != '\0')
	{
		c = *str;
		size++;
		str++;
	}
	return (size - 1);
}
