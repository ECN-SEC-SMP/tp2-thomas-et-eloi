SRCDIR := src
INCDIR := include
BUILDDIR := build
ASSETSDIR := assets

all: $(BUILDDIR)/main.out

# Build the final executable
$(BUILDDIR)/main.out: $(BUILDDIR)/main.o $(BUILDDIR)/Vehicule.o
	g++ -o $@ $^

# Build main.o
$(BUILDDIR)/main.o: $(SRCDIR)/main.cpp $(SRCDIR)/Vehicule.cpp $(INCDIR)/Vehicule.hpp | $(BUILDDIR)
	g++ -I$(INCDIR) -c $(SRCDIR)/main.cpp -o $(BUILDDIR)/main.o

# Build Vehicule.o
$(BUILDDIR)/Vehicule.o: $(SRCDIR)/Vehicule.cpp $(INCDIR)/Vehicule.hpp | $(BUILDDIR)
	g++ -I$(INCDIR) -c $(SRCDIR)/Vehicule.cpp -o $(BUILDDIR)/Vehicule.o

# Create build directory
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

clean:
	rm -rfv $(BUILDDIR) && rm -rfv $(ASSETSDIR)/lexique*