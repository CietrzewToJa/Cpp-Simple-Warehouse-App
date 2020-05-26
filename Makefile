#Rozszerzenia.
.SUFFIXES: .c .cpp .x .h

#Nazwa katalogu.
DIR = 'basename $(CURDIR)'

#Rdzenie nazw plików.
NAME1 = main
NAME2 = App
NAME3 = Base
NAME4 = BaseState
NAME5 = Item
NAME6 = OpenState
NAME7 = Person
NAME8 = States

#Analogicznie
EXEC1s = $(NAME1)s.x
EXEC1s = $(NAME1)d.x
OBJS1 = $(NAME1).o
OBJS2 = $(NAME2).o
OBJS3 = $(NAME3).o
OBJS4 = $(NAME4).o
OBJS5 = $(NAME5).o
OBJS6 = $(NAME6).o
OBJS7 = $(NAME7).o
OBJS8 = $(NAME8).o

#Biblioteka statyczna oraz dzielona
LIB_NAME = MojeFunkcje
#Katalog dla bibliotek
LIB_DIR = ./lib
#Static library.
LIB_STAT = lib$(LIB_NAME).a
#Shared library.
LIB_SHAR = lib$(LIB_NAME).so

#Pliki objektowe wchodzące do biblioteki
LIB_OBJS = $(OBJS2) $(OBJS3) $(OBJS4) $(OBJS5) $(OBJS6) $(OBJS7) $(OBJS8)

#Pliki nagłówkowe
HEADS2 = $(NAME2).h
HEADS3 = $(NAME3).h
HEADS4 = $(NAME4).h
HEADS5 = $(NAME5).h
HEADS6 = $(NAME6).h
HEADS7 = $(NAME7).h
HEADS8 = $(NAME8).h

#Opcje kompilatora i linkera
CFLAGS = -Wall -O -fPIC
LFLAGS = -Wall -O

#Biblioteki linkera zainstalowane w systemie
LDLIBS = -lm -pthread -lrt --debug

#Kompilator i linker
CO = g++
LD = $(CO)

#Program archiwizer do tworzenia bibliotek statycznych
AR = ar

#Opcje archiwizera
ARFLAGS = rsv

#====================================
#Tworzenie biblioteki statycznej.
$(LIB_STAT): $(LIB_OBJS)
	$(AR) $(ARFLAGS) $@ $?
	mkdir -p $(LIB_DIR)
	mv $(LIB_STAT) $(LIB_DIR)

#Twprzenie biblioteki dzielonej.
$(LIB_SHAR): $(LIB_OBJS) 
	$(LD) -shared -o $@ $(LFLAGS) $(LIB_OBJS)
#====================================

#Reguła zależności dla pliku wykonawczego - biblioteka statyczna.
$(EXEC1s): $(OBJS1) $(LIB_STAT) 
	$(LD) -o $@ $(LFLAGS) $(OBJS1) -L$(LIB_DIR) -l$(LIB_NAME) $(LDLIBS)

#Reguła zależności dla pliku wykonawczego - biblioteka dzielona.
$(EXEC1d): $(OBJS2) $(LIB_SHAR)
	$(LD) -o $@ $(LFLAGS) $(OBJS1) -L$(LIB_DIR) -l$(LIB_NAME) $(LDLIBS) -Wl,-R $(LIB_DIR)

#Dodatkowe zależności.
$(OBJS1) : $(HEADS2) 
$(OBJS1) : $(HEADS3)
$(OBJS1) : $(HEADS4) 
$(OBJS1) : $(HEADS5) 
$(OBJS1) : $(HEADS6) 
$(OBJS1) : $(HEADS7)
$(OBJS1) : $(HEADS8) 


.PHONY: run1s run1d

#Uruchamianie z biblioteką statyczną
run1s: $(EXEC1s)
	./$(EXEC1s)

#Uruchamianie z biblioteką dynamiczną
run1d: $(EXEC1d)
	./$(EXEC1d)

#Sprzatanie
.PHONY: clean tar
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}