# bfcompiler
This is a small Brainfuck compiler that i wrote in C, it uses 8 bit cells. It's unfinished because I need to add support for nested loops, I also plan on using dynamic memory allocation down the road.
# Usage
You can compile the program with gcc and run it with:
```
gcc bf.c && ./a.out test.txt
```
Your BF code goes into test.txt, any characters besides ``` [ ] < > . , + - ``` will be ignored.
