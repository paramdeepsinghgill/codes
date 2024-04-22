clc
clear all
syms x1 x2
% Define objective function
%f1 = @(x1,x2) x1-x2 +2*x1^2+2*x1*x2+x2^2
f = x1-x2 +2*x1^2+2*x1*x2+x2^2
% f1(0,0)
fx = inline(f)
fobj = @(X) fx(X(1), X(2))
% Find gradient of f
grad = gradient(f)
G = inline(grad)
Gx = @(X) G(X(1), X(2))
% Hessian matrix
H = hessian(f)
% Hx = inline(H1)
X0 = [0 0]
maxiter = 6
iter = 0
tol = 10^(-3)
X = []
while norm(Gx(X0))>tol && iter<maxiter
    X = [X, X0]
    S = -Gx(X0)
    lambda = S'*S/(S'*H*S)
    X1 = X0 + lambda*S'
    X0 = X1
    iter = iter + 1
end

X
fprintf("Optimal solution is: (%f, %f).\n", X0(1), X0(2));
fprintf("Optimal value is: %f.\n", fobj(X0));