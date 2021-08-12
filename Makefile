all: windows

windows:
	@make -j4 -f ./engine/Makefile
	@make -j4 -f ./src/Makefile

linux:
	@echo "Emiriusu currently does not support Linux"

clean:
	@make -f ./engine/Makefile clean
	@make -f ./src/Makefile clean
