# Super Trunfo de Países em C

Este é um projeto exemplo do desafio final de estruturas de decisão em C, integrando menus dinâmicos, tratamento de entradas, comparação de múltiplos atributos e exibição estruturada do resultado.

## Como compilar

```bash
gcc supertrunfo.c -o supertrunfo
```

## Como executar

```bash
./supertrunfo
```

## Atributos disponíveis para comparação

1. População (milhões)
2. Área (mil km²)
3. PIB (bi USD)
4. IDH (x1000)
5. Densidade Demográfica

> **Regra especial:** Para Densidade Demográfica (5), vence o MENOR valor. Nos demais, vence o MAIOR valor.

## Exemplo de uso

```
=== SUPER TRUNFO DE PAISES ===

Cartas disponíveis:
1. Brasil
2. Alemanha
3. Austrália

Escolha o número da primeira carta: 1
Escolha o número da segunda carta: 2

Escolha o atributo:
1. População
2. Área
3. PIB
4. IDH
5. Densidade Demográfica
Selecione o primeiro atributo (1-5): 1

Escolha o atributo:
2. Área
3. PIB
4. IDH
5. Densidade Demográfica
Selecione o segundo atributo (1-5), diferente do primeiro: 5

--- Comparação ---
Carta 1: Brasil
Carta 2: Alemanha

Atributo                 | Brasil     | Alemanha  
População (milhões)      | 214        | 83        
Densidade Demográfica    | 25         | 232       

Resultado por atributo:
População (milhões): Brasil
Densidade Demográfica: Brasil

Soma dos atributos:
Brasil: 239
Alemanha: 315

*** Resultado final: Alemanha venceu a rodada! ***
```

## Sobre

- O programa trata entradas inválidas, impede escolhas repetidas de atributos ou cartas e exibe sempre mensagens claras ao usuário.
- Código organizado e comentado, fácil de manter e expandir.
