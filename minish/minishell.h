/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 23:10:04 by amben-ha          #+#    #+#             */
/*   Updated: 2024/02/16 17:34:30 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define _POSIX_C_SOURCE 1
# define _GNU_SOURCE

# define PIPE_LINE 1
# define SYNTAX_ERROR 2
# define MALLOC_ERROR 4
# define FREE_ALL 8
# define REDIRECT 16
# define EMPTY_LINE 32
# define SIMPLE_COMMAND 64
# define EXIT 128
# define CMD_PATH 256
# define AMBIGUOUS_REDIRECT 512
# define WARNING_EOF 1024
# define FD_ERROR 2048
# define FILE_NOT_EXIST 4096
# define FORK_ERROR 8192
# define DUP_ERROR 16384
# define PERMISSION_DENIED 32768
# define COMMAND_NOT_EXIST 65536
# define PIPE_ERROR 131072
# define EXEC_ERROR 262144
# define IS_DIR 524288
# define ERNO 1048576
# define PWD_ERROR 2097152

# define TRUE 1
# define FALSE 0

# define PARENT 1
# define CHILD 0

# define EXPAND 4
# define CHAR_NULL 3
# define QUOTE 2
# define SQUOTE 1
# define NOT_QUOTE 0

# define START 1

# define PIPE_PRESENT 1
# define PIPE_PROMPT ">"
# define PROMPT "prompt:"

# define STDIN 0
# define STDOUT 1
# define STDERROR 2

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>

extern int	g_signum;

typedef struct s_env
{
	char			*key;
	char			*str;
	struct s_env	*next;
}		t_env;

typedef struct s_char_flag
{
	char	c;
	int		flag;
}		t_char_flag;

typedef struct s_list_word
{
	t_char_flag			*str;
	struct s_list_word	*next;
}	t_list_word;

typedef struct s_pipe
{
	int	prev[2];
	int	next[2];
}		t_pipe;

typedef struct s_here_doc
{
	int	fd[2];
	int	rank;
}		t_here_doc;

typedef struct s_save_fd
{
	int	fd_stdin;
	int	fd_stdout;
}		t_save_fd;

typedef struct s_numb_child
{
	int		number;
	pid_t	last_child_pid;
}		t_numb_child;

typedef struct s_commands
{
	t_here_doc	*fd_heredoc;
	t_char_flag	*command;
	t_char_flag	*redirect;
	t_env		*env;
	int			(*handle_error)(int, struct s_commands *, t_pipe *);
	t_list_word	*parsed_command;
	t_list_word	*parsed_redirect;
	t_save_fd	fd_saved;
	int			exit_status;
}		t_commands;

int			ft_export(char **command, t_env **env, int *error,
				t_save_fd *standard);
int			ft_unset(char **name, t_env **env);
int			ft_cd(char **args, t_env *env, int *error, t_save_fd *standard);
int			ft_echo(char **args);
int			ft_env(t_env *env, int *error);
int			ft_pwd(int *error);
int			ft_exit(char **argv, t_commands *all);
int			call_builtins(char **cmd, t_commands *all, int *error);

int			ft_realloc(char **p, int size);
int			calloc_str(t_commands *command, t_char_flag *str,
				int *error);
int			calloc_redirection(t_commands *command, int *error);
int			check_cmd_path(char **cmd, t_env *env, char **cmd_path, int *error);
int			check_syntax(t_commands *all, t_char_flag *str, int *error);
int			clean_env(t_env *envp);
void		close_fd_norme(int fd, int *file);
int			count_command(t_char_flag *str);
int			count_redirection(t_char_flag *str);
int			count_str(t_char_flag *str);
int			err_t_command(int err, t_commands *p, t_pipe *pipefd);
int			err_exec(int err, char *str, t_save_fd *standard);
int			execute(t_pipe *pipefd, t_commands *all, int *error, t_env *env);
int			execute_command(char **cmd, char *cmd_path,
				t_commands *all, int *error);
int			expand(t_commands *all, t_env *env, int *error);
int			expand_here_doc(char *to_write, int *i, t_env *env, int fd);
int			expand_str(t_list_word *list, int *exit_status, int *error,
				t_env *env);
int			fill_redirection(t_char_flag *str, t_char_flag *redirect,
				int *error);
void		find_norme(char *key, t_char_flag *str, int *size, int nb_null);
int			ft_atoi(const char *str);
char		*ft_itoa(int number);
int			ft_isalnum(int a);
int			ft_isalpha(char c);
int			ft_lstsize(t_list_word *list);
int			ft_lstsplit(t_list_word **list, t_char_flag *str, int *error);
int			ft_memcmp(void *s1, void *s2, unsigned int n);
int			ft_realloc_char(char **str, int size);
int			ft_split_command(t_char_flag *str, t_commands *all, t_pipe *pipefd,
				pid_t *last_child);
int			ft_split_expand(t_list_word **list, t_env *env, int *error);
int			ft_split_word(t_commands *all, int *error);
int			ft_strlen(char *str);
int			normal_write(int fd, char *to_write, int *error);
int			quote_in_del(t_char_flag *str);
int			split_not_finished(int rank);

char		*ft_substr(char *s, int start, int len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strchr_sign(const char *s, int c);
char		**ft_split(char *s, char c);
char		*ft_strchr(const char *s, int c);
int			ft_arrlen(char **arr);

int			check_file_exist(char *str, t_save_fd *standard);
int			check_builtins(char *str);
int			handle_error(int *error);
int			is_space(char c);
int			is_num(char c);
void		init_refill_t(int *size, int *size2, int n, t_char_flag *str);
int			line_read(int *error, t_char_flag **str);
int			make_here_doc(t_commands *all, t_char_flag *str, int *error);
int			make_here_doc_pipe(t_commands *all, t_char_flag *str, int *error);
int			make_redirection(t_commands *all, t_pipe *pipefd, int *error);
int			parse(t_char_flag *str, t_commands *all,
				t_pipe *pipefd, int *error);

int			replace_in(t_char_flag **str, t_env *env, int *i, int *error);
int			restore_fd(t_save_fd *standard, int *error);
int			saved_standard_fd(t_save_fd *standard, int fd);
int			struct_to_char(char **str, t_char_flag *to_transform);

char		*ft_strdup(char *s);
char		**ft_lstsplit_path(char *str, char *sep,
				int size_to_add, int *error);
char		**env_to_char(t_env *env);
void		malloc_err(t_commands *p);
void		redirect_err(t_commands *p);
void		exit_d(t_commands *p);
void		erno_d(t_commands *p);
void		dup_d(t_commands *p);

void		check_quote(t_char_flag *str);
void		close_all_fd(t_here_doc **fd_heredoc, t_pipe *pipefd);
void		close_t_pipe(t_pipe *pipefd);
void		delete_char(t_char_flag *line);
int			free_char(char **to_free);
void		ft_strcat(char *dest, char *src);
void		ft_strcpy(char *dest, char *to_copy);
void		ft_trim_null(t_char_flag *line, int (separator)(char));
void		ft_trim_space(t_char_flag *line);
void		ft_trim(t_commands *all);

void		handle_signal(int signum);
void		command_handler(void);
void		make_signal(void);
void		default_handler(void);
void		builtins_handler(void);

void		*ft_calloc(size_t nb, size_t size);

char		*key_find(char *str);
int			is_expendable(char c);
void		print_str(t_char_flag *str);
char		*get_str_env(char *key, t_env *env);
int			in_env(char *key, t_env *env);
t_env		*ft_lstnew_env(char *str);
t_env		*ft_lst_env(char *key, char *str);
void		make_env(t_env **final_env, char **envp);

t_list_word	*ft_lstnew_word(t_char_flag *str, int size);
#endif
