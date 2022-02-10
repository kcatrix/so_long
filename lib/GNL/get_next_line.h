#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

char	*ft_next(char *buffer);
char	*ft_free(char *buffer, char *buf);
char	*read_file(int fd, char *res);
char	*ft_line(char *buffer);
char	*get_next_line(int fd, char **line);
char	*gnl_strjoin(char const *s1, char const *s2);
char	*gnl_strchr(const char *s, int c);
void	*gnl_calloc(size_t count, size_t size);
void	gnl_bzero(void *s, size_t n);
size_t	gnl_strlen(const char *s);

#endif
