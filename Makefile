questoes:=questao_1 questao_2 questao_3

.PHONY: all $(questoes)

all: $(questoes)
${questoes}:
	$(MAKE) -C $@
