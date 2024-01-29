%% Phase1: Input parameters
c = [2 1]
A = [1 2; 1 1; 1 -2]
b = [10; 6; 1]

%% Phase2: Plot the lines
x1 = 0:max(b)
x21 = (b(1)-A(1,1)*x1)/A(1,2)
x22 = (b(2)-A(2,1)*x1)/A(2,2)
x23 = (b(3)-A(3,1)*x1)/A(3,2)

plot(x1,x21,'r', x1,x22,'b', x1, x23, 'k')
% or
% plot(x1,x21,'r')
% hold on
% plot(x1,x22, 'b')
% plot(x1,x23, 'k')