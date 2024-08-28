set terminal png size 1920,1080
set output "image/graphics/quickSort.png"

set datafile separator ","
set title "Gŕafico de tempo de execução para número de entradas"
set xlabel "Número de entradas"
set ylabel "T(n) em segundos"
set grid

f(x) = x * log(x) / log(2) / 10e7

plot "../practice_1/results/quickSort.csv" using 1:2 with linespoints title "Tempo de execução", \
    f(x) with lines title "f(n) = n log n"
