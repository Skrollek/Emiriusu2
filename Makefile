all: windows

windows:
	make -j2 -f ./engine/Makefile
	make -j2 -f ./src/Makefile

linux:
	echo "Emiriusu currently does not support Linux"

clean:
	make -f ./engine/Makefile clean
	make -f ./src/Makefile clean
