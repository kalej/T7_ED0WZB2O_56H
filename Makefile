CC=m68k-coff-gcc
NM=m68k-coff-nm
OBJDUMP=m68k-coff-objdump

#coff-m68k versados ieee srec symbolsrec tekhex binary ihex
FORMAT=coff-m68k
EXT=coff

INCDIR=include
SRCDIR=src
OUTDIR=out
TSTDIR=test
OBJDIR=$(OUTDIR)/obj
COFFDIR=$(OUTDIR)/coff
ASMDIR=$(OUTDIR)/asm

T7_FLAGS=-mcpu32 -nostdlib -finline-functions -Wall

NAME=ign/ignloff

$(OBJDIR)/$(NAME).o: $(SRCDIR)/$(NAME).c
	$(CC) -c -I${INCDIR} -O2 $(T7_FLAGS) -o $(OBJDIR)/$(NAME).o -fomit-frame-pointer $(SRCDIR)/$(NAME).c
	
$(COFFDIR)/$(NAME).$(EXT): $(OBJDIR)/$(NAME).o T7_56H.ld 
	$(CC) $(OBJDIR)/$(NAME).o -o $(COFFDIR)/$(NAME).$(EXT) -Wl,-TT7_56H.ld,--format=$(FORMAT) $(T7_FLAGS) -fno-align-functions
	
ignloff: $(SRCDIR)/ign/ignloff.c
	$(CC) -S -I${INCDIR} -O2 $(T7_FLAGS) -o $(ASMDIR)/ignloff.asm -fomit-frame-pointer $(SRCDIR)/ign/ignloff.c	
	
	
maf: $(SRCDIR)/maf.c
#	$(CC) -S -I${INCDIR} -O2 $(T7_FLAGS) -o $(ASMDIR)/maf.asm -fomit-frame-pointer $(SRCDIR)/maf.c
	$(CC) -c -I${INCDIR} -O2 $(T7_FLAGS) -o $(OBJDIR)/mafless.o -fomit-frame-pointer $(SRCDIR)/mafless2.c
	$(CC) $(OBJDIR)/mafless.o -o $(COFFDIR)/mafless.$(EXT) -Wl,-TT7_56H.ld,--format=$(FORMAT) $(T7_FLAGS) -fno-align-functions
	$(NM) $(COFFDIR)/mafless.coff
	$(OBJDUMP) -D $(COFFDIR)/mafless.$(EXT) > $(ASMDIR)/mafless.asm
#	$(CC) -S -I${INCDIR} -O2 $(T7_FLAGS) -o $(ASMDIR)/mafless.asm -fomit-frame-pointer $(SRCDIR)/mafless.c
	
#all: $(COFFDIR)/$(NAME).$(EXT)
#	$(NM) $(COFFDIR)/$(NAME).coff
#	$(OBJDUMP) -D $(COFFDIR)/$(NAME).$(EXT) > $(ASMDIR)/$(NAME).asm
all:
	echo DONE


clean:
	rm -rf $(OBJDIR)/*
	rm -rf $(ASMDIR)/*
	rm -rf $(COFFDIR)/* 