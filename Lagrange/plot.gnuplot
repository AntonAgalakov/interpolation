set terminal pngcairo
set output 'plot.png'

plot 'data.txt' using 1:2 with lines
