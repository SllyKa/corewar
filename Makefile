NAME_asm= asm
DIR_asm= asm
NAME_cw= corewar
DIR_cw=corewar

.PHONY: all clean fclean re

all: NAME_asm NAME_cw

NAME_asm:
	cd $(DIR_asm) && $(MAKE)

NAME_cw:
	cd $(DIR_cw) && $(MAKE)

clean:
	cd $(DIR_asm) && $(MAKE) clean
	cd $(DIR_cw) && $(MAKE) clean

fclean: clean
	cd $(DIR_asm) && $(MAKE) fclean
	cd $(DIR_cw) && $(MAKE) fclean

re: fclean all
