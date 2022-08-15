/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 23:25:46 by sehjung           #+#    #+#             */
/*   Updated: 2022/06/08 13:35:39 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	sort;

	i = 0;
	sort = 1;
	while (i < length - 1 && sort == 1)
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
			sort = 0;
		i++;
	}
	if (sort != 1)
	{
		sort = 1;
		i = 0;
		while (i < length - 1)
		{
			if ((*f)(tab[i], tab[i + 1]) > 0)
				return (0);
			i++;
		}
	}
	return (1);
}
