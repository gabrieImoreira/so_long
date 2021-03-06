#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define GNL_LINEBREAK 1
# define GNL_EOF 0
# define GNL_ERROR -1

int		get_next_line(int fd, char **line);
int		ft_is_new_line(const char *str);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
size_t	ft_strlen_gnl(const char *str);
void	*ft_memmove_gnl(void *dst, const void *src, size_t len);

#endif