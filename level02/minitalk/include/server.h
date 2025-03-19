/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:55:33 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/19 13:55:49 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# define _POSIX_C_SOURCE 200809L

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/types.h>
# include "ft_printf.h"
# include "libft.h"

int		main(void);
void	signal_handler(int signum, siginfo_t *info, void *context);

#endif
