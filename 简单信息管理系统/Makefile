CC=gcc
CFLAGS="-Wall"

debug:clean
	$(CC) $(CFLAGS) -g -o simos main.c
stable:clean
	$(CC) $(CFLAGS) -o simos main.c
clean:
	rm -vfr *~ simos
run:
	./simos
