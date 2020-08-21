%% ���ı��ļ��е�������
% ���ڴ��ı��ļ��е������ݵĽű�:
%
%   
%
% �� MATLAB �� 2020-06-24 10:10:00 �Զ�����

%% ���õ���ѡ���������
opts = delimitedTextImportOptions("NumVariables", 27);

% ָ����Χ�ͷָ���
opts.DataLines = [1, Inf];
opts.Delimiter = " ";

% ָ�������ƺ�����
opts.VariableNames = ["time_bms", "ASOC", "RSOC", "SOH", "Average_Time_To_empty", "Cell_Volt_0", "Cell_Volt_1", "Cell_Volt_2", "Cell_Volt_3", "Cell_Volt_4", "Cell_Volt_5", "Cycle_Count", "Design_Cap", "Design_Volt", "FCC", "FW_Version", "Manufacture_Date", "Other_Status", "Rem_Cap", "Run_Time_TO_Empty", "Safty_Status", "Serial_Num", "Temperature", "Total_Cycles", "Voltage", "Now_Current", "Average_Current"];
opts.VariableTypes = ["double", "double", "double", "double", "double", "double", "double", "double", "double", "double", "double", "double", "double", "double", "double", "double", "double", "double", "double", "double", "double", "double", "double", "double", "double", "double", "double"];

% ָ���ļ�������
opts.ExtraColumnsRule = "ignore";
opts.EmptyLineRule = "read";
opts.ConsecutiveDelimitersRule = "join";
opts.LeadingDelimitersRule = "ignore";

% ��������
read_data = readtable("E:\��������\V1000\�½��ļ���\ģʽ�л�\2020-04-22 07-36-45.binV1000_bms.dat", opts);


%% �����ʱ����
clear opts
%%��ͼ
hold on
plot(read_data.time_bms,read_data.Average_Current)
plot(read_data.time_bms,read_data.Voltage)

