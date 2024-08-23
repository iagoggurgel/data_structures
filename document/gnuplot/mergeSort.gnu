set terminal svg size 1920,1080
set output "image/graphics/mergeSort.svg"

set datafile separator ","
set title "Gŕafico de tempo de execução para número de entradas"
set xlabel "Número de entradas"
set ylabel "T(n)"
set grid

plot "../practice_1/results/mergeSort.csv" using 1:2 with linespoints title "Tempo de execução"
