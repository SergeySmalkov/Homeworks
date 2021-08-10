# -*- coding: utf-8 -*-
"""

@author: Sergey
"""

class Matrix:
    def __init__(self, *args):
        if len(args)==0:
            rows=0
            columns=0
        elif len(args)==1:
            rows=args[0]
            columns=args[0]
            print(args[0])
        elif len(args)==2:
            rows=args[0]
            columns=args[1]
        else:
            rows=args[0]
            columns=args[1]
        self.Rows=rows
        self.Columns=columns
        self.Table=[[int(0) for i in range(self.Columns)] for j in range(self.Rows)]
        
    def matrix_read(self):
        for i in range(self.Rows):
            for j in range(self.Columns):                
                self.Table[i][j]=int(input()) 
    def printer(self):
        print(self.Table)         
    def transpose(self):
        Table_new=Matrix(self.Columns,self.Rows)
        for i in range(Table_new.Rows):
            for j in range(Table_new.Columns):
                Table_new.Table[i][j]=self.Table[j][i]
        return Table_new
    def multiply(self, Second_Matrix):
        Table_new=Matrix(self.Rows,Second_Matrix.Columns)
        if self.Columns!=Second_Matrix.Rows:
            print("Нельзя перемножить")
        else:
            for i in range(self.Rows):
                for j in range(Second_Matrix.Columns):
                    for s in range (self.Columns):
                        Table_new.Table[i][j]=Table_new.Table[i][j]+self.Table[i][s]*Second_Matrix.Table[s][j]
        return(Table_new)
    def sum_matrix(self, Second_Matrix):
        Table_new=Matrix(self.Rows,Second_Matrix.Columns)
        if self.Columns!=Second_Matrix.Columns:
            if self.Rows!=Second_Matrix.Rows:
                print("Нельзя просуммировать")
        
        else:
            for i in range(self.Rows):
                for j in range(Second_Matrix.Columns):
                        Table_new.Table[i][j]=self.Table[i][j]+Second_Matrix.Table[i][j]
        return(Table_new)
    def diff_matrix(self, Second_Matrix):
        Table_new=Matrix(self.Rows,Second_Matrix.Columns)
        if self.Columns!=Second_Matrix.Columns:
            if self.Rows!=Second_Matrix.Rows:
                print("Нельзя вычесть")
        
        else:
            for i in range(self.Rows):
                for j in range(Second_Matrix.Columns):
                        Table_new.Table[i][j]=self.Table[i][j]-Second_Matrix.Table[i][j]
        return(Table_new)
        
        
a=Matrix()
a.matrix_read()
a.printer()

b=a.transpose()
b.printer()

c=a.diff_matrix(b)
c.printer()
