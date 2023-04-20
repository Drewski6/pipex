/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:06:00 by dpentlan          #+#    #+#             */
/*   Updated: 2022/11/19 20:06:02 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  *** count_words (count words) ***
 *
 *  Takes a string 's' and a character 'c'.
 *  Returns the number of strings that would result from splitting string 's'
 *  every time character 'c' is encountered.
 */

static int	count_words(char *s, char c)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			word_count++;
		if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)
			word_count++;
		i++;
	}
	return (word_count);
}

/*  *** empty_table (empty table) ***
 *
 *  Takes an address to a table of strings (pointer to pointer to pointer).
 *  Each element in 'split_table' (each element is a string) is freed.
 *  Finally the memory space for 'split_table' is reset to 0 with ft_bzero.
 *  Returns nothing.
 */

static void	empty_table(char ***split_table)
{
	int	i;

	i = 0;
	while ((*split_table)[i])
	{
		free((*split_table)[i]);
		i++;
	}
	ft_bzero(*split_table, i);
	free(*split_table);
	*split_table = 0;
}

/*  *** add_word (add word) ***
 *
 *  Takes a table of strings (pointer to pointer), a word to add to
 *  the table 'str' and size_t 'len'.
 *  Seeks for the first empty element in the string table, then assigns
 *  that table element to adds a newly allocated memory space (via substr)
 *  which contains 'str' of size 'len'.
 *  Returns number of bytes copied on success.
 *  Returns 0 if malloc fails.
 */

static int	add_word(char **split_table, char *src, size_t len)
{
	int	j;

	j = 0;
	while (split_table[j])
		j++;
	split_table[j] = ft_substr(src, 0, len);
	if (!split_table[j])
	{
		empty_table(&split_table);
		return (0);
	}
	return (len);
}

/*  *** fill_table (fill table) ***
 *
 *  Takes a table of strings 'split_table', a string 's', and a character 'c'.
 *  Iterates over string 's' looking for character separator 'c', when one
 *  is found, that word is coppied (via add_word) to the 'split_table'.
 *  Returns a table of individually malloced strings.
 *  Returns 0 if error with memory allocation.
 */

static char	**fill_table(char **split_table, char *s, char c)
{
	size_t	start;
	size_t	i;

	start = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i])
			start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			if (!add_word(split_table, (s + start), (i - start)))
				return (0);
		}
		while (s[i] && s[i] == c)
			i++;
	}
	return (split_table);
}

/*  *** ft_split (42 split) ***
 *
 *  Takes a string 's' and a character 'c'.
 *  Returns a table of pointers that point to strings derived from splitting
 *  string 's' into smaller strings every time a character 'c' is found.
 *  Returns 0 if memory allocations fail or 's' is null.
 */

char	**ft_split(char const *s, char c)
{
	int		word_count;	
	char	**split_table;

	split_table = 0;
	word_count = 0;
	if (s == 0)
		return (0);
	word_count = count_words((char *)s, c);
	split_table = (char **)ft_calloc((word_count + 1), sizeof(char *));
	if (!split_table)
		return (0);
	if (!fill_table(split_table, (char *)s, c))
	{
		empty_table(&split_table);
		return (0);
	}
	return (split_table);
}
