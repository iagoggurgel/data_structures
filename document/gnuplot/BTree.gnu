set terminal png size 1920,1080
set output "image/graphics/btree.png"

set datafile separator ","
set title "Gŕafico de tempo de execução para número de entradas"
set xlabel "Número de entradas"
set ylabel "T(n) em segundos"
set grid

f(x) = x / 10e6

plot "../practice_2/results/btree.csv" using 1:2 with linespoints title "Tempo de execução", \
    f(x) with lines title "f(n) = n"