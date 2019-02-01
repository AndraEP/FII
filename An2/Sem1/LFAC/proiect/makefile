TARGET = project

CC = gcc
INCLUDES = -I $(INCDIR)
CFLAGS = -w -c $(INCLUDES) -g

LINKER = gcc
LFLAGS = -ll -ly

SRCDIR = src
OBJDIR = obj
INTDIR = intermediary
INCDIR = include
BINDIR = bin

SOURCES = $(SRCDIR)/$(TARGET).l $(SRCDIR)/$(TARGET).y
INTERMEDIARIES = $(INTDIR)/$(TARGET).yacc.c $(INTDIR)/$(TARGET).lex.c
OBJECTS = $(INTERMEDIARIES:$(INTDIR)/%.c=$(OBJDIR)/%.o)
BINARY = $(BINDIR)/$(TARGET)

$(BINARY): $(OBJECTS)
	$(LINKER) $^ $(LFLAGS) -o $@

$(OBJECTS): $(OBJDIR)/%.o: $(INTDIR)/%.c $(INTERMEDIARIES)
	$(CC) $< $(CFLAGS) -o $@

$(INTERMEDIARIES): $(SOURCES)
	yacc --defines=$(INCDIR)/$(TARGET).yacc.h --output=$(INTDIR)/$(TARGET).yacc.c $(SRCDIR)/$(TARGET).y
	lex --outfile=$(INTDIR)/$(TARGET).lex.c $(SRCDIR)/$(TARGET).l

run: $(BINARY)
	cd $(BINDIR) && ./$(TARGET) $(TARGET).txt

.PHONY: clean

clean:
	-rm -f $(INTDIR)/*.c
	-rm -f $(OBJDIR)/*.o
	-rm -f $(INCDIR)/$(TARGET).yacc.h
	-rm -f $(BINARY)
