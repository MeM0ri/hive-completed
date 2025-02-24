/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:55:45 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/24 16:07:23 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"
# include "libft.h"

int		main(int argc, char **argv);
void	send_bit(int pid, char c);
void	confirm_signal(int signum);

#endif
