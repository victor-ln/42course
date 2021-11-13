/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 03:10:27 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/08 03:10:27 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

/*
	Converts the initial portion of the string
	pointed to by nptr to int.
*/
int		ft_atoi(const char *nptr);

/*
	Compares both strings s1 and s2 and returns the difference
	between them or zero if they're equal.
*/
int		ft_strcmp(char *s1, char *s2);

/*
	It is similar to strcmp() function, except it only compares
	the first (at most) n bytes of s1 and s2.
*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*
	Compares the first n bytes (each interpreted as unsigned char)
	of the memory areas s1 and s2.
*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/*
	Returns a string representing the integer received as an argument.
*/
char	*ft_itoa(int n);

/*
	Returns a string representing the unsigned integer received as an argument.
*/
char	*ft_utoa(unsigned int nbr);

/*
	Returns a pointer to a new string which is
	a duplicate of the string s.
*/
char	*ft_strdup(const char *s);

/*
	Appends the src string to the dest string,
	overwriting the terminating null byte ('\0') at the end of dest,
	and then adds a terminating null byte.
*/
char	*ft_strcat(char *s1, char *s2);

/*
	Returns an array of strings obtained by splitting ’s’ using the
	character ’c’ as a delimiter. The array is ended by a NULL pointer.
*/
char	**ft_split(char const *s, char c);

/*
	Returns a pointer to the first occurrence of the character c
	in the string src or NULL if the character is not found.
*/
char	*ft_strchr(const char *str, int lt);

/*
	Returns a pointer to the last occurrence of the character c in the string s.
*/
char	*ft_strrchr(const char *str, int lt);

/*
	Allocates with malloc() and returns a new
	string, which is the result of the concatenation
	of ’s1’ and ’s2’.
*/
char	*ft_strjoin(char const *s1, char const *s2);

/*
	Allocates with malloc() and returns a copy of
	’s1’ with the characters specified in ’set’ removed
	from the beginning and the end of the string.
*/
char	*ft_strtrim(char const *s1, char const *set);

/*
	Allocates with malloc() and returns a substring
	from the string ’s’.
	The substring begins at index ’start’ and is of
	maximum size ’len’.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*
	Locates the first occurrence of the null-terminated string little
	in the string big, where not more than len characters are searched.
	Characters that appear after a `\0' character are not searched.
	If little is an empty string, big is returned; if little occurs nowhere
	in big, NULL is returned; otherwise a pointer to the first character of
	the first occurrence of little is returned.
*/
char	*ft_strnstr(const char *str, const char *to_find, size_t len);

/*
	Applies the function ’f’ to each character of the
	string ’s’ to create a new string with malloc()
	resulting from successive applications of ’f’.
	Returns the string created from the successive applications
	of ’f’ or NULL if the allocation fails
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
	Returns how many characters are in the given string excluding the '\0'.
*/
size_t	ft_strlen(const char *str);

/*
	Appends the NUL-terminated string src to the end of dst. 
	It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the result.
	Returns the initial length of dst plus the length of src
*/
size_t	ft_strlcat(char *dest, const char *src, size_t size);

/*
	Copies up to size - 1 characters
	from the NUL-terminated string src to dst, NUL-terminating the result.
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

/*
	Copies n bytes from memory area src to memory area dest.
*/
void	*ft_memmove(void *dest, const void *src, int n);

/*
	Copies n bytes from memory area src to memory area dest. 
	The memory areas must not overlap.
*/
void	*ft_memcpy(void *dest, const void *src, size_t len);

/*
	Copies no more than n bytes from memory area src to
	memory area dest, stopping when the character c is found.
*/
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);

/*
	Scans the initial n bytes of the memory area pointed to by s
	for the first instance of c.  Both c and the bytes of the memory 
	area pointed to by s are interpreted as unsigned char.
*/
void	*ft_memchr(const void *s, int c, size_t n);

/*
	Allocates memory for an array of nmemb elements of size bytes
	each and returns a pointer to the allocated memory.
	The memory is set to zero. If nmemb or size is 0, then returns NULL.
*/
void	*ft_calloc(size_t nmemb, size_t size);

/*
	Fills the first n bytes of the memory area
	pointed to by s with the constant byte c.
*/
void	*ft_memset(void *s, int c, size_t n);

/*
	Applies the function f to each character of the
	string passed as argument, and passing its index
	as first argument. Each character is passed by
	address to f to be modified if necessary.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/*
	Outputs the string ’s’ to the given file
	descriptor, followed by a newline.
*/
void	ft_putendl_fd(char *s, int fd);

/*
	Outputs the string ’s’ to the given file
	descriptor.
*/
void	ft_putstr_fd(char *s, int fd);

/*
	Outputs the character ’c’ to the given file descriptor.
*/
void	ft_putchar_fd(char c, int fd);

/*
	Outputs the integer ’n’ to the given file descriptor.
*/
void	ft_putnbr_fd(int nb, int fd);

/*
	Erases the data in the n bytes of the memory
	starting at the location pointed to by s, by writing zeros (bytes
	containing '\0') to that area.
*/
void	ft_bzero(void *s, size_t n);

/*
	Iterates the list ’lst’ and applies the function
	’f’ to the content of each element. Creates a new
	list resulting of the successive applications of
	the function ’f’. The ’del’ function is used to
	delete the content of an element if needed.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*
	Returns a new element. The variable ’content’ is initialized
	with the value of the parameter ’content’. The
	variable ’next’ is initialized to NULL.
*/
t_list	*ft_lstnew(void *content);

/*
	Returns the last element of the list.
*/
t_list	*ft_lstlast(t_list *lst);

/*
	Takes as a parameter an element and frees the
	memory of the element’s content using the function
	’del’ given as a parameter and free the element.
	The memory of ’next’ is not freed.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void*));

/*
	Deletes and frees the given element and every
	successor of that element, using the function ’del’ and free().
	Finally, the pointer to the list is set to NULL.
*/
void	ft_lstclear(t_list **lst, void (*del)(void*));

/*
	Iterates the list ’lst’ and applies the function
	’f’ to the content of each element.
*/
void	ft_lstiter(t_list *lst, void (*f)(void *));

/*
	Adds the element ’new’ at the beginning of the list.
*/
void	ft_lstadd_front(t_list **lst, t_list *new);

/*
	Adds the element ’new’ at the end of the list.
*/
void	ft_lstadd_back(t_list **lst, t_list *new);

/*
	Counts the number of elements in a list.
*/
int		ft_lstsize(t_list *lst);

#endif
