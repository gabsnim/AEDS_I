PROG = teste
INPUT = input.txt
OUTPUT = output.txt
RESULT = result.txt

CFLAGS = -g

LDLIBS = -lm

default:
	@echo "Compile: "$(PROG)
	gcc $(CFLAGS) -o $(PROG) $(PROG).c $(LDLIBS)
	@echo ""
	@echo "---"
	@echo "Run: "$(PROG)
	./$(PROG) <$(INPUT) >$(RESULT)
	@echo ""
	@echo "---"
	cat $(RESULT)
	diff $(OUTPUT) $(RESULT)
	