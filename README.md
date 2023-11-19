# Data Communication & Networking PA3
## Build Instructions

My PA3 implementation is built using CMake. Run these from the top
level of the project.

```
mkdir build
cd build
cmake ..
make
```

## Running

Running the executable will run a full simulation for each backoff
algorithm. Each algorithm has its own file. The format is a csv file
with the numbers of devices in one column and the average latency in
the second.

Run from the build directory.

'''
./pa3
'''

## Plotting

 My implemention is plotted uing gnuplot. The script used to plot it
 is in the _plot.gpi_ located in the root of the project.
 
 A plot is already provided in the _backoff-plots.png_ file.
