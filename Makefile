# Makefile criado por Gustavo Bacagine <gustavo.bacagine@protonmail.com>
# 
# bank é um caixa eletronico escrito em C que faz cadastro e listagem de contas,
# cadastro e listagem de movimentações de saque e de deposito.
# 
# Data de criação: 29/06/2020
# Data da última modificação: 11/02/2021 
#
# Aqui deve vir uma breve esplicação sobre a aplicação
#
# Git Hub: https://github.com/Bacagine/LP-Trab02-2020-1/

# Variaveis
TARGET  = bank
SRCDIR  = ./src
INCDIR  = ./include
OBJDIR  = ./obj
BINDIR  = ./bin
ICONDIR = ./icons
ICON    = $(ICONDIR)/$(TARGET).png
SRC     = $(wildcard $(SRCDIR)/*.c)
INC     = -I $(INCDIR)
OBJ     = $(addprefix $(OBJDIR)/,main.o bank.o conta.o movimentacao.o progressbar.o statusbar.o sl.o)
BIN     = $(BINDIR)/$(TARGET)
DAT     = $(wildcard ./*.dat)
RM      = rm -rf
LINK    = ln -s
CC      = gcc
CFLAGS  = -W -Wall -g -lm -lncurses -lfatec

# Cria os diretorios ./bin, ./obj 
# e o executavel
all: $(OBJDIR) $(BINDIR) $(BIN)

$(OBJDIR):
	mkdir $(OBJDIR)
$(BINDIR):
	mkdir $(BINDIR)

$(BIN): $(OBJ)
	$(CC) -o $@ $(OBJ) $(CFLAGS)
$(OBJDIR)/main.o: $(SRCDIR)/main.c $(INCDIR)/bank.h
	$(CC) -c $< $(INC) -o $@
$(OBJDIR)/bank.o: $(SRCDIR)/bank.c $(INCDIR)/bank.h $(INCDIR)/conta.h \
                  $(INCDIR)/movimentacao.h $(INCDIR)/progressbar.h \
				  $(INCDIR)/statusbar.h $(INCDIR)/sl.h
	$(CC) -c $< $(INC) -o $@
$(OBJDIR)/conta.o: $(SRCDIR)/conta.c $(INCDIR)/conta.h $(INCDIR)/bank.h
	$(CC) -c $< $(INC) -o $@
$(OBJDIR)/movimentacao.o: $(SRCDIR)/movimentacao.c $(INCDIR)/movimentacao.h \
                          $(INCDIR)/conta.h $(INCDIR)/bank.h
	$(CC) -c $< $(INC) -o $@
#$(OBJDIR)/clear_buffer.o: $(SRCDIR)/clear_buffer.c
#	$(CC) -c $< $(INC) -o $@
#$(OBJDIR)/developers.o: $(SRCDIR)/developers.c
#	$(CC) -c $< $(INC) -o $@
$(OBJDIR)/progressbar.o: $(SRCDIR)/progressbar.c $(INCDIR)/progressbar.h
	$(CC) -c $< $(INC) -o $@
$(OBJDIR)/statusbar.o: $(SRCDIR)/statusbar.c $(INCDIR)/statusbar.h
	$(CC) -c $< $(INC) -o $@
$(OBJDIR)/sl.o: $(SRCDIR)/sl.c $(INCDIR)/sl.h
	$(CC) -c $< $(INC) -o $@
run: all
	@$(BIN)
clean:
	$(RM) $(OBJ)
mrproper: clean
	$(RM) $(BINDIR)
	$(RM) $(OBJDIR)
	$(RM) $(DAT)
# Para instalar a aplicação use o terminal
# como super usuario ou como usuario root
# e digite o comando make install
install:
	cp -v $(BIN) /usr/bin
	mkdir /usr/share/$(TARGET)
	cp -rv $(BIN) /usr/share/$(TARGET)
	cp -rv $(ICON) /usr/share/pixmaps
	cp -v $(TARGET).desktop /usr/share/applications
	desktop-file-install /usr/share/applications/$(TARGET).desktop
uninstall:
	$(RM) /bin/$(TARGET)
	$(RM) /usr/share/$(TARGET)
	$(RM) /usr/share/pixmaps/$(TARGET).png
	$(RM) /usr/share/applications/$(TARGET).desktop

.PHONY: all run clean mrproper install uninstall
