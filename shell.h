#ifndef SHELL_H_
#define SHELL_H_

#include "LIBs_Macros.h"
#include "structs.h"

int _putchar(char c);
char *read_line(void);
char *starts_with(const char *haystack, const char *needle);
char **tokenizer(char *line);
char **strtow(char *str, char *d);
char **strtow2(char *str, char d);
char *_strdup(char *str);
int _execute(char **command, char **argv, int idx);
void free2DArray(char **array2d);

char *_getpath(char *command);
void reverse_string(char *str, int len);
void printerror(char *name, char *cmd, int idx);
char *_itoa(int num);
int is_builtin(char *command);
void handle_builtin(char **command, char **argv, int *status, int idx);
void exit_shell(char **command, char **argv, int *status, int idx);
void print_env(char **command, int *status);
int is_positive_number(char *str);

/*start error functions*/
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);
int _erratoi(char *s);
void print_error(info_t *info, char *estr);
int print_d(int input, int fd);
int print_d(int input, int fd);
char *convert_number(long int num, int base, int flags);
void remove_comments(char *buf);
/*end error functions*/

/*start environmemt functions*/
char *_getenv(info_t *, const char *);
void _env(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int _env_list(info_t *);
char **get_environ(info_t *info);
int _unsetenv(info_t *info, char *var);
int _setenv(info_t *info, char *var, char *value);
/*end environmemt functions*/

/*Start history functions*/
char *get_history_file(info_t *info);
int write_history(info_t *info)
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info)
/*end history functions*/

/*start list functions*/
list_t *push_front(list_t **head, const char *str, int num);
list_t *push_back(list_t **head, const char *str, int num)
size_t print_list_str(const list_t *h)
int delete_node_at_index(list_t **head, unsigned int index);
void free_list(list_t **head_ptr);
size_t list_len(const list_t *h);
char **list_to_strings(list_t *head);
size_t print_list(const list_t *h);
list_t *node_starts_with(list_t *node, char *prefix, char c);
ssize_t get_node_index(list_t *head, list_t *node);
/*end list functions*/

/*Start Shell functions*/
int my_shell(info_t *info, char **av);
int history(info_t *info);
int unset_alias(info_t *info, char *str);
int set_alias(info_t *info, char *str);
int print_alias(list_t *node);
int alias(info_t *info);
int exit(info_t *info);
int cd(info_t *info);
int help(info_t *info);
/*End Shell functions*/

/*Start utils functions*/
int interactive(info_t *info);
int is_delim(char c, char *delim);
int _isalpha(int c);
int _atoi(char *s);
char *_memset(char *s, char b, unsigned int n);
void ffree(char **pp);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int bfree(void **ptr)
/*End utils functions*/

/*Start Chaining and variables*/
int is_chain(info_t *info, char *buf, size_t *p);
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len);
int replace_alias(info_t *info);
int replace_string(char **old, char *new);
int replace_vars(info_t *info);
/*End Chaining and variables*/


#endif
