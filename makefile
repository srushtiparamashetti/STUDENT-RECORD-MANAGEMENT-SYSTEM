CC = gcc

final: main.o stud_add.o std_del.o std_mod.o std_rev.o std_show.o
        $(CC) main.o stud_add.o std_del.o std_mod.o std_rev.o std_show.o -o final

main.o: main.c header.h
        $(CC) -c main.c

stud_add.o: stud_add.c header.h
        $(CC) -c stud_add.c

std_del.o: std_del.c header.h
        $(CC)  -c std_del.c

std_mod.o: std_mod.c header.h
        $(CC) -c std_mod.c

std_rev.o: std_rev.c header.h
        $(CC)  -c std_rev.c

std_show.o: std_show.c header.h
        $(CC)  -c std_show.c

clean:
        rm -f *.o final
