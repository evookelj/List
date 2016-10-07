compile: linkedList.c
	gcc linkedList.c -o linkedList

clean:
	rm *~

run: linkedList
	./linkedList
