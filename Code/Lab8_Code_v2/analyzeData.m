
clc; clear; close all;

data = table2array(readtable('ServoData3.txt','Delimiter',','));

%%
% Define start and end data because there are outliers
sID = 10; eID = length(data)-10;

% Find the distance data points
for ii = sID:eID
    distance(ii-sID+1) = str2num(data{ii,1}(7:end));
    angle(ii-sID+1) = str2num(data{ii,2}(10:end));
end


%%

figure(1); clf;
subplot(211);
plot(angle, 'LineWidth',1.5);
xlabel('Sample');
ylabel('Angle [deg]');
grid on; grid minor;
subplot(212);
plot(distance, 'LineWidth',1.5);
xlabel('Sample');
ylabel('Distance [mm]');
grid on; grid minor;


figure(2); clf;
scatter(angle, distance, '.', 'LineWidth',1.5);
xlabel('Angle [deg]');
ylabel('Distance [mm]');
grid on; grid minor;

