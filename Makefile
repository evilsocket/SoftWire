CC = c++
OBJEXT = .o
SRCDIR = src/
INCDIR = include/
SOURCES = $(SRCDIR)Assembler.cpp $(SRCDIR)CodeGenerator.cpp $(SRCDIR)Encoding.cpp $(SRCDIR)Error.cpp $(SRCDIR)Instruction.cpp $(SRCDIR)InstructionSet.cpp $(SRCDIR)Loader.cpp $(SRCDIR)Operand.cpp $(SRCDIR)Synthesizer.cpp $(SRCDIR)Linker.cpp $(SRCDIR)RegisterAllocator.cpp $(SRCDIR)Optimizer.cpp $(SRCDIR)Emulator.cpp
TESTSOURCE = $(SRCDIR)Test.cpp
OBJECTS = $(addsuffix $(OBJEXT), $(basename $(SOURCES)))
TESTOBJECTS = $(addsuffix $(OBJEXT), $(basename $(TESTSOURCE)))
OUTPUT = libsoftwire.a
TESTAPP = SoftWire
CFLAGS = -fexceptions -fno-operator-names -I$(INCDIR)
LIBDIR = ./
DEPFLAGS = -M

ifdef OPTIMIZED
 CFLAGS += -O3 -DNDEBUG
else
 CFLAGS += -g
endif

all: $(OUTPUT) $(TESTAPP)

$(OUTPUT): $(OBJECTS)
	ar rcs $@ *.o

$(TESTAPP): Test.o
	$(CC) $(CFLAGS) $(SRCDIR)Test.cpp -L$(LIBDIR) -o $@ *.o -lsoftwire

-include Makefile.dep

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

.PHONY: clean

depend:
	rm -f Makefile.dep;
	$(CXX) $(CFLAGS) $(DEPFLAGS) $(SOURCES) $(TESTSOURCE) > Makefile.dep

clean:
	rm -f $(OUTPUT)
	rm -f $(TESTAPP)
	rm -f *$(OBJEXT)
