
hello32: hello32.o
	ld -macosx_version_min 10.7.0 -lSystem -o hello32 hello32.o 

hello64: hello64.o
	ld -macosx_version_min 10.7.0 -lSystem -o hello64 hello64.o 

hello32.o: hello32.asm
	nasm -f macho hello32.asm 

hello64.o: hello64.asm
	nasm -f macho64 hello64.asm 

