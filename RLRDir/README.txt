To build
+ make
  compiles RLR and a couple os resource intensive test programs

Example runs ...
+ ./RLR -h 
  explains the usage and options
+ ./RLR -x 
  explains the magic
+ ./RLR -W 10 Fibonacci 44   
  computes the 44th Fibonacci number within 10s limit
+ ./RLR -W 10 Fibonacci 100   
  does not compute the 100th Fibonacci number within 10s limit
