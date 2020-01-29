Python callback function given by-reference argument, is unable to modify it. This minimal test case demonstrates the issue.

## Building

```
git clone --recurse https://github.com/dmikushin/python_modarg.git
mkdir build
cd build
cmake ..
PYTHONPATH=$(pwd) python3 ../src/frontend.py 
```

The output shows the actual result vs the expected result:

```
0 vs 0
0 vs 10
0 vs 20
0 vs 30
0 vs 40
0 vs 50
0 vs 60
0 vs 70
0 vs 80
0 vs 90
```
