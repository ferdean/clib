clc; close all; clear all;

FEuler = dlmread('ForwardEuler.dat', ' ', 1, 0);
RK4   = dlmread('RK4.dat', ' ', 1, 0);

time  = FEuler(:, 1);
exact = FEuler(:, 2);
euler = FEuler(:, 3);
RK    = RK4(:, 3);

colors = ["#AA4E2F", "k", "#474875", "#3f6795", "#8F8FA3", "#DADAE2"];
set(groot,'defaultAxesTickLabelInterpreter','latex');  

fig = figure(1);

set(fig, 'Units', 'centimeters')
pos = get(fig,'Position');
set(fig,'PaperPositionMode','Auto','PaperUnits','centimeters','PaperSize',[pos(3), pos(4)])

plot(time, exact, "Color", colors(2), "LineStyle", "-", "LineWidth", 1.5)
hold on 
plot(time, euler, "Color", colors(1), "LineStyle", "--", "LineWidth", 1.5)
hold on 
plot(time, RK, "Color", colors(3), "LineStyle", "-.", "LineWidth", 1.5)

hold off
grid on

xlabel('time [s]', 'Interpreter','latex')
ylabel('y(t) [-]', 'Interpreter','latex')

legend('exact', 'F. Euler', 'RK4', 'Interpreter','latex', 'Location', 'best')

title('C++ implementation of ODE solvers', 'Interpreter','latex')

print(fig, 'result','-dpdf','-r0')