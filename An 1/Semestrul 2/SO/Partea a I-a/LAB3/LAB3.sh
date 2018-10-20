Exerciții cu comenzi înlănțuite :

1. Să se scrie comanda care calculează câte conturi de utilizatori (umani) există în sistem. 
Suplimentar: filtrați conturile asociate la programe de sistem (i.e., cele care nu au /bin/bash ca shell de login). 
(Indicație: folosiți comanda wc și informațiile din fișierul /etc/passwd ; pentru partea suplimentară, folosiți comanda grep pentru filtrarea cerută și înlănțuiți-o cu comanda wc.)

2. Să se scrie comanda care afișează numărul total al utilizatorilor care sunt membri ai grupului studs. 
(Indicație: folosiți comanda dintr-un exercițiu din laboratorul precedent, înlănțuită cu comenzile cut și wc, fiecare apelată cu opțiunile adecvate.)

3. Să se scrie comanda care va scrie, în fișierul utilizatori-logati.txt, numele de cont ale tuturor utilizatorilor prezenți în sistem la momentul execuției comenzii, în ordine alfabetică (și unică). 
(Indicație: folosiți oricare dintre comenzile who sau finger, înlănțuită cu comanda cut și apoi cu comanda sort, fiecare apelată cu opțiunile adecvate. Alternativ, puteți începe lanțul cu comanda users, caz în care veți avea nevoie și de comanda tr.)

4. Să se scrie comanda care afișează (în mod unic) toate shell-urile folosite de utilizatorii sistemului. 
(Indicație: folosiți înlănțuiri de comenzi simple și informațiile din fișierul /etc/passwd.)

5. Să se scrie comanda care afișează câți dintre utilizatorii sistemului conțin "ana" în numele de cont, dar nu în contextul "diana". 
(Indicație: folosiți înlănțuiri de comenzi simple și informațiile din fișierul /etc/passwd.)

6. Să se scrie comanda care afișează numărul total de procese (rulate în toate sesiunile deschise) ale utilizatorului cu numele de cont specificat ca parametru al comenzii. 
(Indicație: prelucrați rezultatele afișate de comanda ps, apelată cu opțiunile adecvate.)

7. Să se scrie comanda care afișează numele real, UID-ul și GID-ul pentru toți utilizatorii sistemului, în formatul "UID->GID->Nume Prenume" , sortați crescător după UID. 
(Indicație: folosiți înlănțuiri de comenzi simple și informațiile din fișierul /etc/passwd.)

8. Să se scrie comanda care afișează data și ora logării și calculatorul de pe care s-a făcut logarea, pentru toate sesiunile deschise, la momentul execuției comenzii, de un utilizator specificat ca argument al comenzii. 
(Indicație: folosiți înlănțuiri de comenzi simple, prelucrând informațiile despre utilizatorii conectați la sistem în acel moment.)

9. Să se scrie comanda care afișează ultimii 15 utilizatori conectați la sistem, în funcție de ora conectării, precum și data, ora și stația de la care s-au conectat. 
(Indicație: folosiți înlănțuiri de comenzi simple, prelucrând informațiile despre utilizatorii conectați la sistem în acel moment.)

10. Să se scrie comanda care afișează pentru fiecare utilizator conectat la sistem, numele de cont, stația de la care s-a conectat și procesul rulat în foreground, în ordinea alfabetică a numelor de cont. 
(Indicație: folosiți înlănțuiri de comenzi simple, prelucrând informațiile despre utilizatorii conectați la sistem în acel moment.)

11. Să se scrie comanda care afișează numele de cont și numele real al utilizatorilor conectați la sistem, al căror prenume se termină cu litera 'a'. 
(Indicație: folosiți înlănțuiri de comenzi simple, prelucrând informațiile despre utilizatorii conectați la sistem în acel moment. Pentru comanda grep folosiți expresia regulată care exprimă faptul că linia de text se termină cu un anumit șablon.)

12. Să se scrie comanda care scrie în fișierul a.txt numele de cont ale tuturor utilizatorilor conectați la sistem, al căror nume de cont începe cu litera 'a'. 
(Indicație: rezolvarea este asemănătoare cu cea a exercițiului precedent.)

13. Să se scrie comanda care afișează toți utilizatorii sistemului care au UID-ul mai mare decât (sau egal cu) 5000. 
(Indicație: folosiți înlănțuiri de comenzi simple și informațiile din fișierul /etc/passwd. Pentru a descrie numere mai mari sau egale cu 5000, se poate folosi comanda grep cu un șablon de tip expresie regulată.)





1) cat /etc/passwd | grep /bin/bash | wc -l // wc numara liniile
2) cat /etc/passwd | grep studs | wc -l
   SAU
   cut -f 4 -d: | grep -w 202 | wc -l // 4 = field 40
3) a) who | cut -f 1 -d ' ' | sort -u > utilizatori-logati.txt
   b) finger | tail -n +2 | cut -f 1 -d ' ' | sort -u > utilizatori-logati.txt
   c) users | tr -s ' ' '\n' | sort -u > utilizatori-logati.txt
4) cat /etc/passwd | cut -f 7 -d ':' | sort -u //d de la delimitator, f numarul field-ului si u de la unic
5) cat /etc/passwd | grep ana | grep -v diana | wc -l
6) ps -U andra.paduraru | tail -n +2 | wc -l

7) sort /etc/passwd -n -k 3 -t ':' | cut -f 1,3,4 -d ':' --output-delimiter=" -> " | cut -s -f 1,2 -d '.' | tr -s '.' ' ' | tr -s ':' ' ' | tr -s [:lower:] [:upper:]

SORT
-n //numeric sort in ord cresc
-k //numarul fieldului
-t //separator pentru field

CUT
-f //select numai anumite fisiere
-d //delimitator
-s //nu afiseaza pe cei care nu au delimitatorul

tr //is an utility for translating, or deleting, or squeezing repeated characters. It will read from STDIN and write to STDOUT
tr -s "caract1" "caract2" //inlocuieste caract 1 cu 2


8) who | grep andra.paduraru | tr -s '  ' ' ' | cut -f 3,4,5 -d ' '
9) who | tr -s '  ' ' ' | cut -f 1,3,4,5 -d ' ' | sort -k 3 -t ' ' | tail -n 15

tail [option]… [file]… //printeaza ultima parte, 10 linii by default pt fiec fisier

10) w | grep -v -i user | tr -s '  ' ' ' | cut -f 1,3,8 -d ' ' | sort

-v //scap de ce voi spune ulterior
-i //inclusiv lw and upp

11) who | cut -f 1 -d ' ' | cut -f 1,2 -d '.' -s | grep -F 'a.' | tr -s '.' ' ' | tr -s [:lower:] [:upper:]
12) who | cut -f 1 -d ' ' | cut -f 1,2 -d '.' -s | grep '^a' > a.txt

^a //incepe cu a
a$ //se termina cu a

13) cat /etc/passwd | cut -f 1,3 -d ':' | sort -k 2 -t ':' -n | grep -E [1-9][0-9][0-9][0-9][0-9]\|[5-9][0-9][0-9][0-9] | cut -f 1 -d ':'







Să se scrie un script care să listeze toți parametrii din linia de apel sub forma: param_i = valoarea parametrului al i-lea , cu i luând valori de la 1 la numărul total de parametri.

#!/bin/bash

for ((i=1; i<=$#; i++))
do
  echo "param_$i = ${!i}"
done
