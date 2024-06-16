PLAT ?= none
PLATS = linux freebsd macosx


default :
	$(MAKE) $(PLAT)

none :
	@echo "Please do 'make PLATFORM' where PLATFORM is one of these:"
	@echo "   $(PLATS)"

linux : PLAT = linux

linux :
	echo "Building for Linux"
	$(MAKE) all