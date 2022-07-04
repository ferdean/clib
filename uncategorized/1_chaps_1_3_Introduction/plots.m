M = dlmread('xy.dat', ' ', 1, 0);

plot(M(:, 1), M(:, 2));
hold on
plot(M(:, 1), M(:, 3));
grid on
legend('exact', 'euler')