#	MAKEFILE

FILES=-IheaderFiles	Source/main.c	Source/lista.c	Source/pilha.c	Source/iteradores.c	Source/cartas.c	Source/graficos.c	
OPTS=-Wall
OUTPUT=blackJack

all:	compile	exec


compile:

	@	echo	"Compilando	o	arquivo	$(OUTPUT)..."

	gcc	$(OPTS)	-o	$(OUTPUT)	$(FILES)


exec:	
	
	@	echo	"Execucao	do	arquivo	$(OUTPUT)..."
	
	./$(OUTPUT)
	

clean:
	
	rm		-rf	*.o	$(OUTPUT)
