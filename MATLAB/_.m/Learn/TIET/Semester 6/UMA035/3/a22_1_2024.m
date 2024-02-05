clc
clear all
%% Phase1: Input parameters
c = [2 1]
A = [1 2; 1 1; 1 -2]
b = [10; 6; 1]

%% Phase2: Plot the lines
x1 = 0:max(b)
x21 = (b(1)-A(1,1)*x1)/A(1,2)
x22 = (b(2)-A(2,1)*x1)/A(2,2)
x23 = (b(3)-A(3,1)*x1)/A(3,2)
x21 = max(0,x21)
x22 = max(0,x22)
x23 = max(0,x23)

plot(x1,x21,'r', x1,x22,'b', x1, x23, 'k')
% or
% plot(x1,x21)
% hold on
% plot(x1,x22)
% plot(x1,x23)
% plot(x1,x21,'r')
% hold on
% plot(x1,x22, 'b')
% plot(x1,x23, 'k')
title('Graphical Method')
xlabel('x1')
ylabel('x2')
legend('x1+x2=10','x1+x2=6', 'x1-x2=1')

%% Phase 3: Find corner point with axes
c1 = find(x1==0)
c2 = find(x21==0)
line1 = [x1([c1 c2]); x21([c1 c2])]'
c3 = find(x22==0)
line2 = [x1([c1 c3]); x22([c1 c3])]'
c4 = find(x23==0)
line3 = [x1([c1 c4]); x23([c1 c4])]'
lines = [line1; line2; line3]
corpt = unique(lines, 'rows')

%% Phase 4: Intersecting points b/w lines
sol = [0;0]
for i = 1:size(A,1)
    for j = i+1:size(A,1)
        A1=A([i j], :)
        b1= b([i j])
        x = inv(A1)*b1
        sol = [sol x]
    end
end
pt = sol'
%% Phase 5: All points.
allpt = [corpt; pt]
points = unique(allpt, 'rows')
%% Phase 6: Feasible region
for i = 1:size(points,1)
    const1(i) = A(1,1)*points(i,1) + A(1,2)*points(i,2)-b(1)
    const2(i) = A(2,1)*points(i,1) + A(2,2)*points(i,2)-b(2)
    const3(i) = A(3,1)*points(i,1) + A(3,2)*points(i,2)-b(3)
end
s1 = find(const1>0)
s2 = find(const2>0)
s3 = find(const3>0)
s = unique([s1 s2 s3])
points(s, :)= []
%% Phase 7: Find optimal solution
value = c*points
[obj,index]= max(value)
X1=points(index,1)
X2=points(index,2)