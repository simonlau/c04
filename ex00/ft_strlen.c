int	ft_strlen(char *str)
{
	int		count;
	char	*letter_ptr;

	count = 0;
	letter_ptr = str;
	while (*letter_ptr != '\0')
	{
		count++;
		letter_ptr++;
	}
	return (count);
}
