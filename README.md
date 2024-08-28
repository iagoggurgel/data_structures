# DATA STRUCTURES

This repository has the purpose to study the data structures presented at DCT0008 and Algoritmos: Teoria e Prática.

Para entender o projeto, siga as intruções:

# Onde encontrar a pasta gráficos

O caminho da pasta com os gráficos está em document/image/graphics/

# Diretórios

## Document

OBS: é necessário ter o pdflatex e o gnuplot-qt.

Comporta todo o LaTeX do projeto, para compilar apenas execute:

```
make gnu
```

```
make all
```

# CUIDADO

Rodar os testes pode tomar uma quantidade considerável de tempo!!

## Practice 1

Contém todo o código do trabalho da primeira unidade sobre algoritmos de ordenação.

É importante notar que, foram utilizadas flags de otimização de compilador do gcc, se necessário, remova as mesmas em OPT_FLAGS

Para executar, apenas compile usando a função all do Makefile e limpe a pasta de build usando a função clean do Makefile.

Para executar o binário, apenas execute a main em build/main com a flag --HELP e ela indicará o funcionamento.

## Practice 2

Contém todo o código do trabalho da segunda unidade sobre busca em árvores e tabelas de dispersão.

Para executar, apenas compile usando a função all do Makefile e limpe a pasta de build usando a função clean do Makefile.

Para executar o binário, deve ser executado teste por teste nos arquivos build/hash build/bst build/btree, isso já gerará os arquivos .csv na pasta results/
que o projeto utiliza para plotar.

Você também pode optar por utilizar a função test do Makefile para rodar o binário nos arquivos build/hash build/bst build/btree.