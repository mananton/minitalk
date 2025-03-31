/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mananton <telesmanuel@hotmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:23:12 by mananton          #+#    #+#             */
/*   Updated: 2025/03/31 12:13:21 by mananton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void    append_to_str(char **str, char c)
{
        char *temp;
        int  i;
        size_t  str_size;
        
        str_size = ft_strlen(*str);
        temp = ft_calloc(str_size + 2, sizeof(char));
        if (!temp)
                return ;
        if (*str)
        {
                i = -1;
                while ((*str)[++i])
                        temp[i] = (*str)[i];
        }
        temp[str_size] = c;
        free(*str);
        *str = temp; 
}

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
        static char             *master;

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
                        ft_putstr_fd(master, 1);
                        free(master);
                        master = NULL;
                        return ;
                }
                append_to_str(&master, c);
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
        while (1)
                pause();
        return (0);
}
