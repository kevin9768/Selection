#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# create time1.xlsx containing formatted execution time

import xlsxwriter

QS = []
PS = []

for i in range(10000, 30001, 1000):
    qs = []
    ps = []
    for j in range(1,4,1):
        s_qs = "./data/" + str(i) + "/QS_" + str(j) + ".txt"
        f_qs = open(s_qs, "r")
        s_ps = "./data/" + str(i) + "/PS_" + str(j) + ".txt"
        f_ps = open(s_ps, "r")
        
        f_qs.readline()
        f_ps.readline()
        
        t_qs = f_qs.readline()
        t_ps = f_ps.readline()
        
        t_qs = t_qs[:-1]
        t_ps = t_ps[:-1]
        
        qs.append(t_qs)
        ps.append(t_ps)
    
    QS.append(qs)
    PS.append(ps)
    
with xlsxwriter.Workbook('time1.xlsx') as workbook:
    worksheet = workbook.add_worksheet()
    

    for i in range(0, len(QS)):
        for j in range(0, 3):
            worksheet.write(2+j, 2+i, QS[i][j])
            worksheet.write(15+j, 2+i, PS[i][j])
        
