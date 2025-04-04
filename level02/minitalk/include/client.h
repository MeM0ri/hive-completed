/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:55:45 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/24 16:24:58 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# define _POSIX_C_SOURCE 200809L

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/types.h>
# include "ft_printf.h"
# include "libft.h"

int		main(int argc, char **argv);
void	send_length(int pid, long length);
void	send_string(int pid, char *string);
void	confirm_signal(int signum, siginfo_t *info, void *context);

#endif
