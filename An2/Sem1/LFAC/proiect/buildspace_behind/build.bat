@echo off
flex project.l && bison -d project.y && gcc lex.yy.c project.tab.c -ly && a.exe project.txt