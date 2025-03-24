/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:55:33 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/24 16:28:54 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# define _POSIX_C_SOURCE 200809L

# include <signal.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/types.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct s_server
{
	int				bit;
	bool			is_length;
	char			*string;
	unsigned char	byte;
	unsigned long	index;
	unsigned long	length;
}			t_server;

int			main(void);
void		signal_handler(int signum, siginfo_t *info, void *context);
static void	handle_length(int signum, siginfo_t *info);
static void	handle_message(int signum, siginfo_t *info);

#endif
