clear all 
close all 
clc 

x = linspace(-pi, pi, 15)

Y = cos(pi*x)

answ = fft(cos(pi*x), 15)

%plot(x, ans')

ans_ = ifft(answ)

plot(x, answ)
hold on
plot(x, ans_)

x = x'
Y = Y'

