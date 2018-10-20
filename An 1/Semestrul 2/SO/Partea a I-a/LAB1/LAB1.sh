Exerciții cu comenzile cut și grep :

1. Să se scrie comanda care afișează numele de cont și UID-urile tuturor utilizatorilor sistemului. 
(Indicație: folosiți comanda cut și informațiile din fișierul /etc/passwd.)

2. Să se scrie comanda care selectează din fișierul /etc/passwd doar informațiile despre un utilizator specificat ca argument al comenzii. 
(Indicație: folosiți comanda grep.)

3. Să se scrie comanda care afișează numele și GID-urile tuturor grupurilor de utilizatori ai sistemului. 
Suplimentar: înlocuiți ":" cu " - " în rezultatele afișate de comandă. 
(Indicație: folosiți comanda cut și informațiile din fișierul /etc/group ; căutați opțiunea comenzii cut pentru înlocuirea delimitatorului.)

4. Să se scrie comanda care afișează lista tuturor utilizatorilor care sunt membri ai grupului studs. 
(Indicație: folosiți comanda grep și informațiile din fișierul /etc/passwd.)




1) cat /etc/passwd | cut -f 1,3 -d ':'
2) cat /etc/passwd | grep rares.vlaiduc
3) cat /etc/group | cut -f 1,3 -d ':' --output-delimiter '-'
4) cat /etc/passwd | grep studs | cut -f 1 -d ':'
