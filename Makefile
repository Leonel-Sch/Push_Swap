# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/04 16:34:49 by lscheupl          #+#    #+#              #
#    Updated: 2024/08/07 15:12:04 by lscheupl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_LIBFT:= libft.a
NAME := push_swap

#Source#####################################
#PATH_SRCS = Libft/

SOURCES_LIBFT += Libft/ft_atoi.c
SOURCES_LIBFT += Libft/ft_bzero.c
SOURCES_LIBFT += Libft/ft_calloc.c
SOURCES_LIBFT += Libft/ft_isalnum.c
SOURCES_LIBFT += Libft/ft_isalpha.c
SOURCES_LIBFT += Libft/ft_isascii.c
SOURCES_LIBFT += Libft/ft_isdigit.c
SOURCES_LIBFT += Libft/ft_isprint.c
SOURCES_LIBFT += Libft/ft_itoa.c
SOURCES_LIBFT += Libft/ft_memchr.c
SOURCES_LIBFT += Libft/ft_memcmp.c
SOURCES_LIBFT += Libft/ft_memcpy.c
SOURCES_LIBFT += Libft/ft_memmove.c
SOURCES_LIBFT += Libft/ft_memset.c
SOURCES_LIBFT += Libft/ft_putchar_fd.c
SOURCES_LIBFT += Libft/ft_putendl_fd.c
SOURCES_LIBFT += Libft/ft_putnbr_fd.c
SOURCES_LIBFT += Libft/ft_putstr_fd.c
SOURCES_LIBFT += Libft/ft_split.c
SOURCES_LIBFT += Libft/ft_strchr.c
SOURCES_LIBFT += Libft/ft_strdup.c
SOURCES_LIBFT += Libft/ft_striteri.c
SOURCES_LIBFT += Libft/ft_strjoin.c
SOURCES_LIBFT += Libft/ft_strlcat.c
SOURCES_LIBFT += Libft/ft_strlcpy.c
SOURCES_LIBFT += Libft/ft_strlen.c
SOURCES_LIBFT += Libft/ft_strmapi.c
SOURCES_LIBFT += Libft/ft_strncmp.c
SOURCES_LIBFT += Libft/ft_strnstr.c
SOURCES_LIBFT += Libft/ft_strrchr.c
SOURCES_LIBFT += Libft/ft_strtrim.c
SOURCES_LIBFT += Libft/ft_substr.c
SOURCES_LIBFT += Libft/ft_tolower.c
SOURCES_LIBFT += Libft/ft_toupper.c
SOURCES_LIBFT += Libft/ft_printf.c
SOURCES_LIBFT += Libft/ft_printf_dependancy.c
SOURCES_LIBFT += Libft/ft_putnbr_base_fd.c
SOURCES_LIBFT += Libft/ft_lstadd_back.c
SOURCES_LIBFT += Libft/ft_lstadd_front.c
SOURCES_LIBFT += Libft/ft_lstclear.c
SOURCES_LIBFT += Libft/ft_lstdelone.c
SOURCES_LIBFT += Libft/ft_lstiter.c
SOURCES_LIBFT += Libft/ft_lstlast.c
SOURCES_LIBFT += Libft/ft_lstmap.c
SOURCES_LIBFT += Libft/ft_lstnew.c
SOURCES_LIBFT += Libft/ft_lstsize.c
SOURCES_LIBFT += Libft/ft_count_words.c
SOURCES_LIBFT += Libft/ft_atoll.c
SOURCES_LIBFT += Libft/ft_strcat.c
SOURCES_LIBFT += Libft/ft_strcpy.c
SOURCES_LIBFT += Libft/ft_free_tab.c
SOURCES_LIBFT += Libft/ft_pileadd_back.c
SOURCES_LIBFT += Libft/ft_pileadd_front.c
SOURCES_LIBFT += Libft/ft_pileclear.c
SOURCES_LIBFT += Libft/ft_piledelone.c
SOURCES_LIBFT += Libft/ft_pileiter.c
SOURCES_LIBFT += Libft/ft_pilelast.c
SOURCES_LIBFT += Libft/ft_pilemap.c
SOURCES_LIBFT += Libft/ft_pilenew.c
SOURCES_LIBFT += Libft/ft_pilesize.c

SOURCES_PUSH_SWAP = *.c

#Objets#####################################
#PATH = obj/
#OBJ = $(SOURCES: .c= .o)

OBJ = *.o

#Includes###################################
INCLUDES_LIBFT = Libft/libft.h
INCLUDES = Push_Swap.h

#Compilation################################
CC = cc

CFLAGS += -Werror
CFLAGS += -Wextra
CFLAGS += -Wall
CFLAGS += -g3
#Rules######################################

all:
	$(MAKE) all_libft
	$(MAKE) $(NAME)

$(NAME): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES_PUSH_SWAP) -I $(INCLUDES) -I $(INCLUDES_LIBFT) $(NAME_LIBFT) -o $(NAME)

clean: fclean_libft

fclean: clean
	rm -rf $(NAME)

re: fclean
	$(MAKE) all
	

all_libft: $(NAME_LIBFT)
 
#$(OBJ):
#	mkdir $(PATH)
#	$(CC) $(CFLAGS) -c $(SOURCES) -I $(INCLUDES) -o $(PATH)

$(NAME_LIBFT): $(SOURCES_LIBFT)
	mkdir ./obj/
	$(CC) $(CFLAGS) -c $(SOURCES_LIBFT) -I $(INCLUDES_LIBFT)
	mv *.o obj/
	ar rcs $(NAME_LIBFT) ./obj/$(OBJ)

clean_libft:
	rm -rf obj

fclean_libft: clean_libft
	rm -rf $(NAME_LIBFT)

relibft: fclean_libft
	$(MAKE) all_libft

