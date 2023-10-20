#ifndef SHELL_H_
#define SHELL_H_

#include "LIBs_Macros.h"
#include "structs.h"

char *read_line(void);
char *starts_with(const char *haystack, const char *needle)
char **tokenizer(char *line);
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
/*end list functions*/

#endif
