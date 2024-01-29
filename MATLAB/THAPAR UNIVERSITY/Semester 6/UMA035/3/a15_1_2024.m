v = 4
w = 7
v = 9
a = [2 -1 0 3 9]
a = [1 2 3 4 5 6 7]
a = [1:7]
a = [1:1:7]
a = [1:7.5]
a = [1:0.5:7]
a = [-5:-1]
a = [-1:-5]
a = [-1:-1:-5]

sqrt(9)
length(a)

A = [1 2; 3 4]
A = [1 2 3; 4 5 6]

A = zeros(2,2)
A = zeros(2)
A = zeros(2,3)
A = ones(3)
A = eye(3)

help

size(A)
size(A, 1)
size(A,2)

clear a
clear v w
clear clear all

clc

M = [2 3 4 5; 7 -1 0 9; 0 4 -1 -2]
M(1,2)
M(1:2, 1:4)
M(2,2:4)
M(2:3, [1 4])
M([1 3], [1 4])
size(M)
size(M,1)
size(M,2)

x = 0
y = (12-((2)*(x)))/(4 ) 
plot(x,y)

x = 0:12
y = (12-((2)*(x)))/4
plot(x,y)

A = [2 4; 3 2]
b = [12; 12]
x = ((inv(A))*b)

A = [4 1 3; 2 6 7; 3 1 8]

sort(A)
sort(A,2)
sort(A,'descend')
sort(A,2 ,"descend")