Exerciții cu comenzile find și sort :

1. Să se scrie comanda care să parcurgă recursiv directorul dat ca argument și să afișeze permisiunile tuturor fișierelor și subdirectoarelor întâlnite. 
(Indicație: folosiți comanda find și cu acțiunea de apelare a comenzii stat, sau acțiunea echivalentă de afișare cu format.)

2. Să se scrie comanda ce afișează pentru toate fișierele găsite în directorul dat ca argument în linia de comandă, parcurs recursiv, fișiere ale căror nume încep sau se termină cu litera 'a', următoarele proprietăți: numele fișierului, data ultimei modificări și dimensiunea fișierului în Kbytes. 
(Indicație: folosiți comanda find și cu opțiunea de combinare alternativă a mai multor criterii de căutare după nume, iar la partea de acțiuni cu opțiunea -printf cu parametrii adecvați.)

3. Să se scrie comanda care să sorteze descrescător liniile de text din fișierul /etc/passwd, iar rezultatul sortării să fie salvat în fișierul output.txt. 
(Indicație: folosiți comanda sort cu cele două opțiuni corespunzătoare cerințelor din enunț.)

4. Să se scrie comanda care să sorteze crescător după UID liniile de text din fișierul /etc/passwd. 
(Indicație: folosiți comanda sort cu trei opțiuni: opțiunea pentru sortare numerică, opțiunea pentru sortare după cheia câmpul 3 și opțiunea pentru stabilirea separatorului dintre câmpuri.)

5. Să se scrie comanda ce afișează toate fișierele și directoarele, precum și drepturile de acces asociate acestora, aflate în directorul dat ca argument în linia de comandă, parcurs recursiv, pentru care grupul proprietarului are drepturi de citire și de execuție.

6. Să se scrie comanda ce afișează toate fișierele de tip normal (i.e., fișiere obișnuite) pe care le dețineți în cont și care au fost modificate în ultima săptămână, împreună cu drepturile de acces și data ultimei modificări.

7. Să se scrie comanda ce afișează toate fișierele găsite începând din directorul dat ca argument în linia de comandă, parcurs recursiv, pentru care proprietarul fișierului are drept de execuție asupra sa, precum și data ultimei accesări a fișierului și dimensiunea sa în Kbytes.

8. Să se scrie comanda care să afișeze toate programele sursă C/C++ (i.e., fișierele cu extensiile .c, .cpp și .h) pe care le dețineți în cont, împreună cu lungimile lor (i.e., dimensiunile lor în octeți) și data ultimei modificări. 
(Indicație: folosiți comanda find cu trei opțiuni -name la criteriul de căutare, iar la partea de acțiuni cu opțiunea -printf cu parametrii adecvați. Pentru a testa comanda, creați câteva fișiere C/C++ în directorul home, eventual prin copierea unor exemple de programe de la laboratoarele de programare din primul semestru.)

9. Să se scrie comanda care identifică toate programele sursă C++ (i.e., fișierele cu extensia .cpp) pe care le dețineti (doar) în directorul home și, dacă dimensiunea acestora este mai mică de 5 Kbytes, încearcă să le compileze folosind g++. Ieșirea de eroare standard pentru comanda de compilare va fi redirectată către un fișier errors.txt. 
(Indicație: folosiți comanda find cu opțiunile -name și -size la criteriul de căutare, iar la partea de acțiuni cu opțiunea -exec g++ ... 2>> errors.txt . Pentru a testa comanda, creați câteva fișiere C++ în directorul home, eventual prin copierea unor exemple de programe de la laboratoarele de programare din primul semestru.)

10. Să se scrie comanda ce afișează toate fișierele pagini web (i.e., fișierele cu extensiile .htm, .html, .php, .css) pe care le dețineți în cont, împreună cu lungimile lor (i.e., dimensiunile lor în Kbytes) și data ultimei modificări.

11. Să se scrie comanda care șterge toate fișierele temporare din contul propriu (i.e. din directorul home, și inclusiv pe cele din subdirectoarele acestuia). 
Explicație: fișierele temporare sunt cele ale căror nume se termină cu ~ sau cu .bak . Acestea sunt fișiere create de diverse editoare de text în care se salvează penultima versiune, i.e. cea de dinainea ultimei editări, a fișierului original (i.e. fișierul cu numele respectiv fără ~ sau .bak). 
(Indicație: folosiți comanda find și cu acțiunea de apelare a comenzii rm, sau acțiunea echivalentă de ștergere.)



1) a) find . -exec stat -c %n:%a {} \;
1) b) find . -printf "%p:%m\n"
2) a) find . \( -name "a*" -or -name "*a" \) -exec stat -c %n:%y:%s {} \;
2) b) find . \( -name "a*" -or -name "*a" \) -printf "%p:%t:%k\n"
3) sort /etc/passwd -r -o file.txt
4) sort /etc/passwd -n -k 3 -t ':'

5) find . -perm -500 -exec stat -c %n:%a {} \;
6) find . -type f -mtime -7 -exec stat -c %n:%a:%y {} \;
7) find . -type f -perm -100 -exec stat -c %n:%z:%s {} \;
8) find . -type f -name "*.c" -exec stat -c %n:%s:%y {} \; -or -name "*.cpp" -exec stat -c %n:%s:%y {} \; -or -name "*.h" -exec stat -c %n:%s:%y {} \;
9) find . -type f -name "*.cpp" -exec g++ 2> errors.txt {} \;
10) find . -type f -name "*.htm" -exec stat -c %n:%s:%y {} \; -or -name "*.html" -exec stat -c %n:%s:%y {} \; -or -name "*.php" -exec stat -c %n:%s:%y {} \; -or -name "*.css" -exec stat -c %n:%s:%y {} \;
11) find -type f -name "*.bak" -exec rm {} \; -or -name "*~" -exec rm {} \;

INTERCHANGEABLE:
-exec stat -c %n:%y:%s {} \;
-exec ls -l --block-size=KB {} \;
