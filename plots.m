clear all; 
close all; 
clc 

%% Build C++ MEX File
% Build a single C program |main.cpp| into a MEX file. 
%% 
% Build the MEX file. The output displays information specific to your compiler.
mex main.cpp
%% 
main()