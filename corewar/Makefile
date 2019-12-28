#
#	Debug compiler variables
#

DG_CC_FLAGS= -g -O0

#
#	Compiler variables
#

CC= gcc
CC_FLAGS= -Wall -Wextra -Werror

#
#	Release variables
#

NAME= corewar
LIBDIR= libftprintf
LIB= libftprintf.a
LIBHEADER=libftprintf.h
LIBHEADERDIR=libftprintf/includes 
GNLHEADER=get_next_line.h
AVLTHEADER=avlt.h
LIBSHORT= ftprintf
LIBNCURSES= ncurses
HEADERDIR= includes
SRCSDIR= srcs
HEADER= corewar.h
OBJSDIR= objs
OBJS= $(patsubst $(SRCSDIR)/%.c, $(OBJSDIR)/%.o, $(wildcard $(SRCSDIR)/*.c))
SRCS= $(OBJS:.o=.c);

.PHONY: all debug clean fclean re

all: lib $(NAME)

#
#	Debug mode settings
#

debug: CC_FLAGS += $(DG_CC_FLAGS)
debug: $(NAME)

#
#	Release
#

$(NAME): $(LIBDIR)/$(LIB) $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) -o $@ -I$(HEADERDIR) -I$(LIBHEADERDIR) -L$(LIBDIR) -l$(LIBSHORT) -l$(LIBNCURSES)

$(LIBDIR)/$(LIB):
	cd $(LIBDIR) && $(MAKE) -s

lib:
	$(MAKE) -C $(LIBDIR)

$(OBJS): $(OBJSDIR)/%.o : $(SRCSDIR)/%.c $(HEADERDIR)/$(HEADER)
	mkdir -p $(OBJSDIR)
	$(CC) $(CC_FLAGS) -I$(HEADERDIR) -I$(LIBHEADERDIR) -c $< -o $@

#
#	Clean
#

clean:
	rm -rf $(OBJSDIR)/*.o
	$(MAKE) clean -C $(LIBDIR)

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C $(LIBDIR)

re: fclean all