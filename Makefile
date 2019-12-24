NAME_asm= asm
DIR_asm= asm
NAME_cw= corewar
DIR_cw=corewar

.PHONY: all clean fclean re

all: $(DIR_asm)/$(NAME_asm) $(DIR_cw)/$(NAME_cw)

$(DIR_asm)/$(NAME_asm):
	cd $(DIR_asm) && $(MAKE)

$(DIR_cw)/$(NAME_cw):
	cd $(DIR_cw) && $(MAKE)

clean:
	cd $(DIR_asm) && $(MAKE) clean
	cd $(DIR_cw) && $(MAKE) clean

fclean: clean
	cd $(DIR_asm) && $(MAKE) fclean
	cd $(DIR_cw) && $(MAKE) fclean

re: fclean all
