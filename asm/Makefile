#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsinged <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/02 13:23:02 by fsinged           #+#    #+#              #
#    Updated: 2019/12/28 16:01:25 by fsinged          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
OBJDIR = OBJ/

ASM = asm
DISASM = disasm
ASMLIBFT = src/asm/libft/
ASMLNAM = $(addprefix $(ASMLIBFT), libft.a)

ASMINC = includes/
ASMHEADERS = $(ASMINC)asm.h $(ASMINC)commands.h $(ASMINC)op.h $(ASMLIBFT)libft.h
ASM_INC = -I $(ASMINC) -I $(ASMLIBFT)

ASMSRCDIR = src/asm/
ASMSRC = asm.c ft_error.c

ASM_DISASSEMBLER_SRC = cw_vm_parsing_read.c cw_vm_parsing.c disassembler.c op.c \
cw_vm_core_check_ops.c

ASM_ASSEMBLER_SRCDIR = $(ASMSRCDIR)assembler/
ASM_ASSEMBLER_SRC = assembler.c chk_arguments.c chk_commands.c chk_lables.c cmnd_size.c \
is_command.c is_label.c read_arguments.c read_file.c skip_space.c validation.c \
rewrite_code.c rewrite_content.c

ASMOBJDIR = $(OBJDIR)asm/
ASMOBJ = $(ASMSRC:.c=.o)
ASMOBJS = $(addprefix $(ASMOBJDIR), $(ASMOBJ))

ASM_ASSEMBLER_OBJDIR = $(ASMOBJDIR)assembler/
ASM_DISASSEMBLER_OBJDIR = $(ASMOBJDIR)disassembler/
ASM_ASSEMBLER_OBJ = $(ASM_ASSEMBLER_SRC:.c=.o)
ASM_DISASSEMBLER_OBJ = $(ASM_DISASSEMBLER_SRC:.c=.o)
ASM_ASSEMBLER_OBJS = $(addprefix $(ASM_ASSEMBLER_OBJDIR), $(ASM_ASSEMBLER_OBJ))
ASM_DISASSEMBLER_OBJS = $(addprefix $(ASM_DISASSEMBLER_OBJDIR), $(ASM_DISASSEMBLER_OBJ))

all:$(OBJ) $(ASM)

$(OBJ):
	@mkdir -p $(OBJ)

$(ASM):$(ASMLNAM) $(ASMOBJDIR) $(ASM_ASSEMBLER_OBJDIR) $(ASM_DISASSEMBLER_OBJDIR) $(ASMOBJS) $(ASM_ASSEMBLER_OBJS) $(ASM_DISASSEMBLER_OBJS)
	@$(CC) $(CFLAGS) $(ASMLNAM) $(ASM_INC) $(ASMOBJS) $(ASM_ASSEMBLER_OBJS) $(ASM_DISASSEMBLER_OBJS) -o $(ASM)

$(ASMLNAM):
	@make -C $(ASMLIBFT)

$(ASMOBJDIR):
	@mkdir -p $(ASMOBJDIR)

$(ASM_ASSEMBLER_OBJDIR):
	@mkdir -p $(ASM_ASSEMBLER_OBJDIR)

$(ASM_DISASSEMBLER_OBJDIR):
	@mkdir -p $(ASM_DISASSEMBLER_OBJDIR)

$(ASMOBJDIR)%.o:$(ASMSRCDIR)%.c $(ASMHEADERS)
	@$(CC) $(CFLAGS) -c $(ASM_INC) $< -o $@

clean:
	@make -C $(ASMLIBFT) fclean
	@/bin/rm -rf $(OBJDIR)

fclean:clean
	@rm -f $(ASM)

re:fclean all