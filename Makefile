# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/04 16:34:49 by lscheupl          #+#    #+#              #
#    Updated: 2024/08/20 19:38:49 by lscheupl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_LIBFT:= libft.a
NAME := push_swap

#Source#####################################
#PATH_SRCS = Libft/

SOURCES_LIBFT += Libft2/ft_atoi.c
SOURCES_LIBFT += Libft2/ft_bzero.c
SOURCES_LIBFT += Libft2/ft_calloc.c
SOURCES_LIBFT += Libft2/ft_isalnum.c
SOURCES_LIBFT += Libft2/ft_isalpha.c
SOURCES_LIBFT += Libft2/ft_isascii.c
SOURCES_LIBFT += Libft2/ft_isdigit.c
SOURCES_LIBFT += Libft2/ft_isprint.c
SOURCES_LIBFT += Libft2/ft_itoa.c
SOURCES_LIBFT += Libft2/ft_memchr.c
SOURCES_LIBFT += Libft2/ft_memcmp.c
SOURCES_LIBFT += Libft2/ft_memcpy.c
SOURCES_LIBFT += Libft2/ft_memmove.c
SOURCES_LIBFT += Libft2/ft_memset.c
SOURCES_LIBFT += Libft2/ft_putchar_fd.c
SOURCES_LIBFT += Libft2/ft_putendl_fd.c
SOURCES_LIBFT += Libft2/ft_putnbr_fd.c
SOURCES_LIBFT += Libft2/ft_putstr_fd.c
SOURCES_LIBFT += Libft2/ft_split.c
SOURCES_LIBFT += Libft2/ft_strchr.c
SOURCES_LIBFT += Libft2/ft_strdup.c
SOURCES_LIBFT += Libft2/ft_striteri.c
SOURCES_LIBFT += Libft2/ft_strjoin.c
SOURCES_LIBFT += Libft2/ft_strlcat.c
SOURCES_LIBFT += Libft2/ft_strlcpy.c
SOURCES_LIBFT += Libft2/ft_strlen.c
SOURCES_LIBFT += Libft2/ft_strmapi.c
SOURCES_LIBFT += Libft2/ft_strncmp.c
SOURCES_LIBFT += Libft2/ft_strnstr.c
SOURCES_LIBFT += Libft2/ft_strrchr.c
SOURCES_LIBFT += Libft2/ft_strtrim.c
SOURCES_LIBFT += Libft2/ft_substr.c
SOURCES_LIBFT += Libft2/ft_tolower.c
SOURCES_LIBFT += Libft2/ft_toupper.c
SOURCES_LIBFT += Libft2/ft_printf.c
SOURCES_LIBFT += Libft2/ft_printf_dependancy.c
SOURCES_LIBFT += Libft2/ft_putnbr_base_fd.c
SOURCES_LIBFT += Libft2/ft_lstadd_back.c
SOURCES_LIBFT += Libft2/ft_lstadd_front.c
SOURCES_LIBFT += Libft2/ft_lstclear.c
SOURCES_LIBFT += Libft2/ft_lstdelone.c
SOURCES_LIBFT += Libft2/ft_lstiter.c
SOURCES_LIBFT += Libft2/ft_lstlast.c
SOURCES_LIBFT += Libft2/ft_lstmap.c
SOURCES_LIBFT += Libft2/ft_lstnew.c
SOURCES_LIBFT += Libft2/ft_lstsize.c
SOURCES_LIBFT += Libft2/ft_count_words.c
SOURCES_LIBFT += Libft2/ft_atoll.c
SOURCES_LIBFT += Libft2/ft_strcat.c
SOURCES_LIBFT += Libft2/ft_strcpy.c
SOURCES_LIBFT += Libft2/ft_free_tab.c
SOURCES_LIBFT += Libft2/ft_pileadd_back.c
SOURCES_LIBFT += Libft2/ft_pileadd_front.c
SOURCES_LIBFT += Libft2/ft_pileclear.c
SOURCES_LIBFT += Libft2/ft_piledelone.c
SOURCES_LIBFT += Libft2/ft_pileiter.c
SOURCES_LIBFT += Libft2/ft_pilelast.c
SOURCES_LIBFT += Libft2/ft_pilemap.c
SOURCES_LIBFT += Libft2/ft_pilenew.c
SOURCES_LIBFT += Libft2/ft_pilesize.c
SOURCES_LIBFT += Libft2/ft_pilefirst.c


SOURCES_PUSH_SWAP = *.c

#Objets#####################################
#PATH = obj/
#OBJ = $(SOURCES: .c= .o)

OBJ = *.o

#Includes###################################
INCLUDES_LIBFT =
# Libft/libft.h
INCLUDES =
# Push_Swap.h

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

$(NAME):
	$(CC) $(CFLAGS) $(SOURCES_PUSH_SWAP) $(INCLUDES) $(INCLUDES_LIBFT) $(NAME_LIBFT) -o $(NAME)

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
	$(CC) $(CFLAGS) -c $(SOURCES_LIBFT) $(INCLUDES_LIBFT)
	mv *.o obj/
	ar rcs $(NAME_LIBFT) ./obj/$(OBJ)

clean_libft:
	rm -rf obj

fclean_libft: clean_libft
	rm -rf $(NAME_LIBFT)

relibft: fclean_libft
	$(MAKE) all_libft

.PHONY : all re clean fclean fclean_libft clean_libft relibft all_libft

