/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mananton <telesmanuel@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:58:21 by mananton          #+#    #+#             */
/*   Updated: 2025/01/27 12:17:30 by mananton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static void	free_strings(char **strings, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free (strings[i]);
		i ++;
	}
	free (strings);
}

static int	words(char **strings, const char **s, char c, size_t *i)
{
	const char	*word_start;

	word_start = *s;
	while (**s != c && **s)
		(*s)++;
	strings[*i] = ft_substr(word_start, 0, *s - word_start);
	if (!strings[*i])
	{
		free_strings(strings, *i);
		return (0);
	}
	(*i)++;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	size_t	i;

	strings = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!s || !strings)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			if (!words(strings, &s, c, &i))
				return (NULL);
		}
	}
	strings[i] = NULL;
	return (strings);
}

/*
void print_split(char **split_result)
        {
                int     i;

                i = 0;
                if (!split_result)
                {
                        printf("NULL\n");
                        return;
                }
                while (split_result[i])
                {
                        printf("Segment %d: '%s'\n", i, split_result[i]);
                        free(split_result[i]);
                        i++;
                }
                free (split_result);
        }
int	main()
{
	char	**result;

	printf("Test case 1: Basic split\n");
	result = ft_split("Hello World This is a test", ' ');
	print_split(result);

	printf("\nTest case 2: Multiple delimiters in a row\n");
	result = ft_split("Hello  World   This   is   a  test", ' ');
	print_split(result);

	printf("\nTest case 3: String starts and ends with delimiters\n");
	result = ft_split("  Hello World  ", ' ');
	print_split(result);

	printf("\nTest case 4: Only delimiters\n");
	result = ft_split("     ", ' ');
	print_split(result);

	printf("\nTest case 5: Empty string\n");
	result = ft_split("", ' ');
	print_split(result);

	printf("\nTest case 6: Delimiter not found in string\n");
	result = ft_split("HelloWorld", ' ');
	print_split(result);

	return 0;
}*/
