/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shellmini.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmisfit <nmisfit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:02:39 by stune             #+#    #+#             */
/*   Updated: 2021/06/25 19:35:23 by nmisfit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELLMINI_H
# define SHELLMINI_H

# include "const_value.h"
# include "const_error.h"
# include <unistd.h>
# include <stdio.h>
# include "libft.h"
# include <stdlib.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <errno.h>
# include <dirent.h>
# include <fcntl.h>

typedef struct s_list_operation
{
	int		l_size;
	t_list	*lst_all;
	t_list	*list;
	t_list	*tmp_list;
}	t_list_operation;

typedef struct s_node
{
	char			*data;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_dlist
{
	t_node			*head;
	t_node			*last;
	t_node			*current;
	char			*old_str;
}					t_dlist;

typedef struct s_term
{
	char			*ptr;
	int				position;
	int				length;
}					t_term;

typedef struct s_all
{
	char			*buf;
	t_dlist			*history;
	t_term			*term;
	char			**my_envp;
	unsigned int	flag;
}	t_all;

typedef struct s_cmd
{
	t_list_operation	lst_s;
	char				*tmp;
	char				**my_av;
	int					pipe_flag;
	int					du_p0;
	int					du_p1;
	int					i;
}						t_cmd;

t_all	*g_all;

void	check_count_of_argv(int argc, char **argv);
void	_exitn(int status);
void	ft_strjchr(char **str, char c);
int		ft_strcmp(const char *s1, const char *s2);
void	update_exit_status(char ***envp, int status);
char	*getenvp(char *key, char **envp);
char	*new_envparams(char *key, char *value);
int		check_key(char *argv);
int		check_value(char *argv);
void	add_envp(char *value, char ***envp);
char	*get_key(char *str);
char	*get_value(char *str);
void	get_path_up(char **path);
void	run_cd(char **argv);
void	run_exit(char **argv);
void	run_unset(char **argv, char ***envp);
void	run_export(char **argv, char ***envp);
void	run_echo(char **argv);
int		check_command(char **argv, char ***envp);
char	*pathjoin(char *dirname, char *name, DIR **dir);
char	*getfntpath(char *name, char **envp);
void	get_utils(char **argv, char ***envp);
void	cmd_loop(char *buf, char ***envp);
char	**make_my_envp(char *envp[]);
void	errors_output(int my_errno, char *arg0);
void	pipe_check(int *pipe_flag, char *tmp);
void	pipe_maker(char *argv[], char *envp[]);
char	**check_redirect(char **argv, int *fd);
void	strzero(char **str, int n);
int		putchr(int c);
void	term_remote_with_signal(void);
void	term_init(void);
void	term_remote(void);
void	sgnl(int a);
t_dlist	*attend(t_dlist *lst, char *str);
int		insert_on_position(t_term *term);
void	term_previous(t_term *term, t_dlist *term_history);
void	term_next(t_term *term, t_dlist *term_history);
void	term_delete(t_term *term, int length);
void	term_left(t_term *term);
void	term_right(t_term *term);
void	check_flagc(void);
void	sig_handler(int sig);
int		check_errors(char *buf, char **my_av, int i);
t_cmd	*cmd_init(char *buf);
void	make_key(char *buf, char **envp, int *i, char **tmp);
int		if_redirect_in_buf(char *buf, int *i, char **tmp);
void	if_quote(char *buf, char **envp, char **tmp, int *i);
void	dollar_sign_processing(char **envp, char *buf, int *i, char **tmp);
void	if_apostrophe(char *buf, char **tmp, int *i);
void	if_quo_back_apos_pip(char *buf, char **tmp, char **envp, int *i);
void	norm_correct(char *buf, char **tmp, int *i);
void	dup_and_close(t_cmd *cmd);

#endif