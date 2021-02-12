/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <floblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:33:07 by judumay           #+#    #+#             */
/*   Updated: 2021/02/12 11:14:09 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <unistd.h>
# include <sys/mman.h>
# include <pthread.h>

# define ALLOC
# define TINY 100
# define SMALL 4096

typedef struct			s_block{
	struct s_block		*prev;
	size_t				size;
	int					free;
	struct s_block		*next;
}						t_block;

typedef struct			s_heap {
	size_t				size;
	t_block				*block;
	struct s_heap		*next;
}						t_heap;

t_heap					*g_heap;
extern pthread_mutex_t	g_mutex;

/*
** malloc.c
*/

void	*malloc(size_t size);

/*
** free.c
*/

void	free(void *ptr);

/*
** realloc.c
*/

void	*realloc(void *ptr, size_t size);

/*
** heap.c
*/

t_heap		*create_heap(size_t size);
t_heap		*find_memory(void *allocation);
size_t		get_size(size_t size);

/*
** show_alloc_mem.c
*/

void		show_alloc_mem(void);

/*
** utils.c
*/

size_t		ft_strlen(const char *str);
void		ft_putnbr(size_t nb);
void		ft_puthexa(size_t nb);

#endif
