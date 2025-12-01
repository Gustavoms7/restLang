SET sistema.preco_kilo 20
SET sistema.preco_rodizio 50
SET sistema.preco_bebida 5
SET sistema.hora_atual 12
SET cliente.nome "Bruno"
SET cliente.tipo "RODIZIO"
SET cliente.peso 0
SET cliente.bebidas 1
SET cliente.sobremesas 1
SET cliente.total 0
SET desconto 10
SET taxa_servico 5
PRINT "Variaveis definidas"
# === FECHAR_CONTA: Calculando total ===
# Verificar tipo e calcular base
IF cliente.tipo == "RODIZIO" GOTO CALC_RODIZIO_0
JMP CALC_BEBIDAS_0
LABEL CALC_RODIZIO_0
GET sistema.preco_rodizio temp.base
ADD cliente.total temp.base
LABEL CALC_BEBIDAS_0
GET cliente.bebidas temp.bebidas
GET sistema.preco_bebida temp.preco_beb
MUL temp.bebidas temp.preco_beb
ADD cliente.total temp.bebidas
GET cliente.sobremesas temp.sobremesas
GET sistema.preco_bebida temp.preco_sob
MUL temp.sobremesas temp.preco_sob
ADD cliente.total temp.sobremesas
# === Exibindo conta final ===
PRINT "========================================"
PRINT "           CONTA DO CLIENTE            "
PRINT "========================================"
PRINT cliente.nome
PRINT cliente.tipo
PRINT "----------------------------------------"
PRINT "Total: "
PRINT cliente.total
PRINT "========================================"
HALT
