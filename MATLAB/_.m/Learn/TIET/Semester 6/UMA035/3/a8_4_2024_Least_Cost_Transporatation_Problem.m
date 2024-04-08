clc
clear all
c = [2 10 4 5; 6 12 8 11; 3 9 5 7]
a = [12 25 20]
b = [25 10 15 5]
m = size(c,1)
n = size(c,2)
if sum(a) == sum (b)
    fprintf('Balanced Transportation problem')
else
    fprintf('Unbalanced Transportation Problem')
    if sum(a)<sum(b)
        a(end+1) = sum(b) - sum(a)
        c(end+1,:) = zeros(1,n)
        m = m+1
    else
        b(end+1) = sum(a) - sum(b)
        c(:, end+1) = zeros(m,1)
        n = n+1
    end
end
OrigC = c
X = zeros(m,n)
for i = 1:m
    for j = 1:n
        cpq = min(min(c))
        % or
        % cpq = min(c(:))
        if cpq == Inf
            break
        end
        [p1, q1] = find(cpq==c)
        p = p1(1)
        q = q1(1)
        X(p,q) = min(a(p), b(q))
        if min(a(p), b(q)) == a(p)
            b(q) = b(q) - a(p)
            a(p) = a(p) - X(p,q)
            c(p,:) = Inf
        else
            a(p) = a(p) - b(q)
            b(q) = b(q) - X(p,q)
            c(:,q) = Inf
        end
    end
end
X
z = 0;
for i = 1:m
    for j = 1:n
        z = z + OrigC(i,j)*X(i,j);
    end
end
z