/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mananton <telesmanuel@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:50:12 by mananton          #+#    #+#             */
/*   Updated: 2025/02/19 13:17:18 by mananton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk_bonus.h"

void    ft_bin_to_char(int signal, char *c)
{
        if (signal == SIGUSR1)
                *c = (*c << 1) | 1;
        else if (signal == SIGUSR2)
                *c <<= 1;
}

void    sig_handler(int signal, siginfo_t *info, void *context)
{
        static int              pid;
        static char             c;
        static int              bits;

        (void)context;
        if (pid != 0 && pid != info->si_pid)
                return ;
        if (pid == 0)
                pid = info->si_pid;
        ft_bin_to_char(signal, &c);
        if (++bits == 8)
        {
                bits = 0;
                if (c == '\0')
                {
                        kill(pid, SIGUSR1);
                        pid = 0;
                        return ;
                }
                write (1, &c, 1);
                c = 0;
        }
        kill(pid, SIGUSR2);
}

int     main(void)
{
        struct sigaction        sa;

        ft_printf("Server PID is: %d\n", getpid());
        sigemptyset(&sa.sa_mask);
        sa.sa_flags = SA_SIGINFO;
        sa.sa_sigaction = sig_handler;
        if (sigaction(SIGUSR1, &sa, NULL) == -1 \
                || sigaction(SIGUSR2, &sa, NULL) == -1)
                return (ft_putstr_fd("Error sigaction\n", 1), 1);
        while (true)
                pause();
        return (0);
}
