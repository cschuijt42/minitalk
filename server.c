/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/30 16:54:37 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/01/30 16:54:37 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "libft.h"

void	receive(int signal, siginfo_t *info, void *context)
{
	static int	pos = 0;
	static char	character = 0;
	pid_t		origin;

	(void) context;
	origin = info->si_pid;
	if (signal == SIGUSR1)
		character |= 1 << pos;
	pos++;
	if (pos == 8)
	{
		write(1, &character, 1);
		character = 0;
		pos = 0;
	}
	kill(origin, SIGUSR1);
}

int	main(void)
{
	struct sigaction	action;
	pid_t				pid;

	pid = getpid();
	action.sa_sigaction = receive;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	ft_printf("Process ID is %d\n", pid);
	while (1)
		pause();
	return (0);
}
