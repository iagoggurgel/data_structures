set terminal png size 1920,1080
set output "image/graphics/selectionSort.png"

set datafile separator ","
set title "Gŕafico de tempo de execução para número de entradas"
set xlabel "Número de entradas"
set ylabel "T(n) em segundos"
set grid

f(x) = x**2  / 50e7 

plot "../practice_1/results/selectionSort.csv" using 1:2 with linespoints title "Tempo de execução", \
    f(x) with lines title "f(n) = n^2"
