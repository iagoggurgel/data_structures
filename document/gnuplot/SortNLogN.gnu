set terminal png size 1920,1080
set output "image/graphics/Combined.png"

set datafile separator ","
set title "Gŕafico de tempo de execução para número de entradas"
set xlabel "Número de entradas"
set ylabel "T(n)"
set grid

f(x) = x * log(x) / log(2) / 10e7

# Plotando os dois gráficos sobrepostos
plot "../practice_1/results/quickSort.csv" using 1:2 with linespoints title "Quick Sort", \
     "../practice_1/results/heapSort.csv" using 1:2 with linespoints title "Heap Sort", \
     "../practice_1/results/mergeSort.csv" using 1:2 with linespoints title "Merge Sort", \
    f(x) with lines title "N log N"