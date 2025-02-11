all:
	gcc main.c linked_list.c -o main

clean:
	-rm -f main