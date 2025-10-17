SRCDIR := src
INCDIR := include
BUILDDIR := build
ASSETSDIR := assets

all: $(BUILDDIR)/main.out

# Build the final executable
$(BUILDDIR)/main.out: $(BUILDDIR)/main.o $(BUILDDIR)/Vehicule.o $(BUILDDIR)/Voiture.o $(BUILDDIR)/Bateau.o
	g++ -o $@ $^

# Build main.o
$(BUILDDIR)/main.o: $(SRCDIR)/main.cpp $(SRCDIR)/Vehicule.cpp $(INCDIR)/Vehicule.hpp $(SRCDIR)/Voiture.cpp $(INCDIR)/Voiture.hpp $(SRCDIR)/Bateau.cpp $(INCDIR)/Bateau.hpp | $(BUILDDIR)
	g++ -I$(INCDIR) -c $(SRCDIR)/main.cpp -o $(BUILDDIR)/main.o

# Build Vehicule.o
$(BUILDDIR)/Vehicule.o: $(SRCDIR)/Vehicule.cpp $(INCDIR)/Vehicule.hpp | $(BUILDDIR)
	g++ -I$(INCDIR) -c $(SRCDIR)/Vehicule.cpp -o $(BUILDDIR)/Vehicule.o

# Build Voiture.o
$(BUILDDIR)/Voiture.o: $(SRCDIR)/Voiture.cpp $(INCDIR)/Voiture.hpp | $(BUILDDIR)
	g++ -I$(INCDIR) -c $(SRCDIR)/Voiture.cpp -o $(BUILDDIR)/Voiture.o

# Build Bateau.o
$(BUILDDIR)/Bateau.o: $(SRCDIR)/Bateau.cpp $(INCDIR)/Bateau.hpp | $(BUILDDIR)
	g++ -I$(INCDIR) -c $(SRCDIR)/Bateau.cpp -o $(BUILDDIR)/Bateau.o

# Create build directory
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

clean:
	rm -rfv $(BUILDDIR) && rm -rfv $(ASSETSDIR)/lexique*