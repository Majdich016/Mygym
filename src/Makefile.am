## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = gym

gym_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	verifier.c verifier.h \
	ajout.c ajout.h \
	affichage.c affichage.h \
	afichage_fenetre.c afichage_fenetre.h

gym_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

