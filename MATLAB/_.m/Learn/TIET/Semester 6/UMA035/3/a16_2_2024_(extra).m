clc
clear all
c  = [2 3 4 7]
A = [2 3 -1 4; 1 -2 6 -7]
b = [8; -3]

m = size(A,1)
n = size(A,2)
% You can reverse the values of m and n to check if the error is printing properly or not.
if (n>=m)
    sol = []
    nCm = nchoosek(n,m)
    p = nchoosek(1:n,m)
    for i = 1:nCm
        y = zeros(n,1)
        A1 = A(:,p(i,:))
        x = inv(A1)*b
        if all (x>=0 & x~=Inf & x~=-Inf)
            y(p(i,:)) = x
            sol = [sol y]
        end
    end
    z = c*sol
    [bfs,index] = max(z)
    % Optimal value is ___ and Optimal solution is (x1,x2,x3,x4) = ( , , , )
    fprintf('Optimal value is %f and optimal solution is (%f, %f, %f, %f).', bfs, sol(:, index))
    % x1 = sol(1, index)
    % x2 = sol(2, index)
    % x3 = sol(3, index)
    % x4 = sol(4, index)
    % fprintf('Optimal value is %f and optimal solution is (%f, %f, %f, %f).', bfs, x1, x2, x3, x4)
else
    error('No. of unknowns are less than constraints.')
end