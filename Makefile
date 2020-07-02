# Makefile criado por Gustavo Bacagine <gustavo.bacagine@protonmail.com>
#
# Data de criação: 29/06/2020
# Data da última modificação: 30/06/2020 
#
# Aqui deve vir uma breve esplicação sobre a aplicação
#
# Git Hub: https://github.com/Bacagine/LP-Trab02-2020-1/

TARGET  = bank
SRCDIR  = ./src
INCDIR  = ./include
OBJDIR  = ./obj
BINDIR  = ./bin
ICONDIR = ./icons
ICON    = $(ICONDIR)/$(TARGET).png
SRC     = $(wildcard $(SRCDIR)/*.c)
INC     = -I $(INCDIR)
OBJ     = $(addprefix $(OBJDIR)/,main.o bank.o conta.o movimentacao.o progressbar.o statusbar.o clear_buffer.o developers.o)
BIN     = $(BINDIR)/$(TARGET)
DAT     = $(wildcard ./*.dat)
RM      = rm -rf
LINK    = ln -s
CC      = gcc
CFLAGS  = -W -Wall -g -lm -lncurses

all: $(OBJDIR) $(BINDIR) $(BIN)

$(OBJDIR):
	mkdir $(OBJDIR)
$(BINDIR):
	mkdir $(BINDIR)
	
$(BIN): $(OBJ)
	$(CC) -o $@ $(OBJ) $(CFLAGS)
$(OBJDIR)/main.o: $(SRCDIR)/main.c
	$(CC) -c $< $(INC) -o $@ #$(CFLAGS)
$(OBJDIR)/bank.o: $(SRCDIR)/bank.c
	$(CC) -c $< $(INC) -o $@ #$(CFLAGS)
$(OBJDIR)/conta.o: $(SRCDIR)/conta.c
	$(CC) -c $< $(INC) -o $@ #$(CFLAGS)
$(OBJDIR)/movimentacao.o: $(SRCDIR)/movimentacao.c
	$(CC) -c $< $(INC) -o $@ #$(CFLAGS)
$(OBJDIR)/clear_buffer.o: $(SRCDIR)/clear_buffer.c
	$(CC) -c $< $(INC) -o $@ #$(CFLAGS)
$(OBJDIR)/developers.o: $(SRCDIR)/developers.c
	$(CC) -c $< $(INC) -o $@ #$(CFLAGS)
$(OBJDIR)/progressbar.o: $(SRCDIR)/progressbar.c
	$(CC) -c $< $(INC) -o $@ #$(CFLAGS)
$(OBJDIR)/statusbar.o: $(SRCDIR)/statusbar.c
	$(CC) -c $< $(INC) -o $@ #$(CFLAGS)
run: all
	@$(BIN)
clean:
	$(RM) $(OBJ)
mrproper: clean
	$(RM) $(BINDIR)
	$(RM) $(OBJDIR)
	$(RM) $(DAT)
# Para instalar a aplicação use o terminal \
  como super usuario ou como usuario root \
  e digite o comando make install
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
