/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/30 17:31:27 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/01/30 17:31:27 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "libft.h"

unsigned int	g_signals = 0;

void	perform_highly_sophisticated_acknowledgement_mechanism(int signal, \
											siginfo_t *info, void *context)
{
	(void) signal;
	(void) info;
	(void) context;
	g_signals++;
}

void	broadcast_character(char c, pid_t pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		usleep(50);
		i++;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	act;
	pid_t				pid;
	char				*str;

	if (ac != 3)
		exit_message("Incorrect number of arguments");
	pid = ft_atoi(av[1]);
	if (pid == 0)
		exit_message("Invalid process ID to send signal to");
	act.sa_sigaction = perform_highly_sophisticated_acknowledgement_mechanism;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	str = av[2];
	while (*str)
	{
		broadcast_character(*str, pid);
		str++;
	}
	ft_printf("Acknowledged broadcasts: %u\nExpected: %d\n", g_signals, \
				ft_strlen(av[2]) * 8);
	return (0);
}
