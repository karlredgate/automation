
default:
	@echo " ====== use mingw32-make ====="
	@echo " ====== use mingw32-make ====="
	mingw32-make all

all: hello.exe file.exe window.exe ps.exe sh.exe svc.exe

hello.exe: hello.o
	$(CC) -o $@ $^

file.exe: file.o
	$(CC) -o $@ $^

window.exe: window.o
	$(CC) -o $@ $^

ps.exe: ps.o
	$(CC) -o $@ $^ -lsigar

sh.exe: sh.o process.o
	$(CC) -o $@ $^ -ltcl

svc.exe: svc.o process.o
	$(CC) -o $@ $^ -ltcl -lws2_32

clean:
	rm -f *.o *.exe
