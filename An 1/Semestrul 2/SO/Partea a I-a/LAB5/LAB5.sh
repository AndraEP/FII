I) Exerciții cu fișiere de comenzi (partea a 3-a):

1. Să se scrie un script care calculează și afișează numărul total de fișiere de tip obișnuit ce sunt "ascunse" 
(i.e. numele lor începe cu caracterul '.'), numărul total de fișiere de tip alias (numărați doar link-urile simbolice) 
și numărul total de subdirectoare aflate într-un director dat, parcurgand acel director în manieră recursivă.
Numele directorului de pornire se transmite ca parametru în linia de comandă, sau se va citi prin comanda read în caz contrar.
(Indicație: parcurgeți cu un for directorul curent și calculați informațiile solicitate, iar pentru fiecare intrare din 
director care este de tipul (sub)director apelați recursiv scriptul.) 
Suplimentar: să se afișeze acele informații totale pentru fiecare subdirector parcurs.

2. Să se scrie un script care calculează numărul total de cuvinte și respectiv lungimea cea mai mare a liniilor de text, 
din toate fișierele ce conțin text obișnuit (i.e. fișierele pentru care comanda file raportează "ASCII text") 
aflate într-un director dat, parcurgand acel director în manieră recursivă. Numele directorului se transmite ca parametru în
linia de comandă, sau se va citi prin comanda read în caz contrar. 
(Indicație: parcurgeți cu un for directorul curent și calculați informațiile solicitate, iar pentru fiecare intrare 
din director care este de tipul (sub)director apelați recursiv scriptul.) 
Suplimentar: să se afișeze acele informații totale pentru fiecare subdirector parcurs.

3. Să se scrie un script care să efectueze într-o buclă pașii următori:

citește de la tastatură două numere și un operator + , - , * sau /
efectuează operația respectivă
scrie rezultatul, pe o nouă linie, în cadrul unui fișier, sub forma:   nr_operatie: operand1 operator operand2 = rezultat
reia bucla
Din bucla respectivă se va ieși la introducerea caracterului q pe poziția operatorului. 
Înainte de terminare, se va scrie în fișier și numărul total de operații efectuate. 
Numele fișierului în care se face scrierea se primește ca parametru în linia de comandă, sau se va citi prin comanda
read în caz contrar.

Exerciții suplimentare:

Alte câteva exerciții cu scripturi:

4. Să se scrie un script care calculează și afișează numărul total de fișiere de tip fifo și numărul total de subdirectoare
aflate într-un director dat, parcurgand directorul recursiv. Numele directorului de pornire se transmite ca parametru în
linia de comandă, sau se va citi prin comanda read în caz contrar. 
(Indicație: parcurgeți cu un for directorul curent și calculați informațiile solicitate, 
iar pentru fiecare intrare din director care este de tipul (sub)director apelați recursiv scriptul.) 
Suplimentar: să se afișeze acele informații totale pentru fiecare subdirector parcurs.

5. Să se scrie un script care calculează numărul total de linii de text și respectiv de caractere din toate fișierele
dintr-un director, prin parcurgerea recursivă a directorului dat. Numele directorului se transmite ca parametru în linia de
comandă, sau se va citi prin comanda read în caz contrar. 
(Indicație: parcurgeți cu un for directorul curent și calculați informațiile solicitate, iar pentru fiecare intrare
din director care este de tipul (sub)director apelați recursiv scriptul.) 
Suplimentar: să se afișeze acele informații totale pentru fiecare subdirector parcurs.

6. Să se scrie un script care să afișeze un arbore cu structura directoarelor din contul personal.

7. Să se scrie un script care să afișeze toate comentariile din scripturile aflate într-un director specificat ca argument
(scripturile vor avea o extensie .sh pentru a le putea deosebi de alte genuri de fișiere text).

8. Să se scrie un script care primește ca parametri d (un nume de director) și n (un număr). 
Pentru fiecare fișier pentru care utilizatorul curent are drepturi de citire și execuție, aflat în directorul dat ca
parametru sau în subdirectoarele acestuia, să se afișeze primele n linii de text.

9. Să se scrie un script care primește ca parametru un nume de director. Scriptul va compila fiecare fișier sursă C 
din directorul respectiv și va tipări (i.e., afișa pe ecran) conținutul fiecărui fișier text din acest director.

10. Să se scrie un script care va redenumi toate fișierele ".txt" aflate în directorul curent și în toate subdirectoarele 
acestuia, dându-le extensia ".ascii".

11. Să se scrie un script care "scanează" directorul primit ca parametru (dacă nu este apelat cu parametru, atunci folosește
implicit directorul home ~) pentru fișiere mp3. Pentru fișierele găsite se vor crea link-uri hard .
(Indicație: vezi comanda ln) în directorul ~/html/muzica/. 
Se va genera deasemenea un "playlist" în format html simplu, plasat în directorul ~/html, și care va conține numele 
fișierelor mp3 găsite (Indicație: eventual doar numele fără extensie, vezi comanda basename), 
precum și link-uri HTML spre acestea.
(Indicație: e suficient <a href="muzica/nume fisier mp3 pe disc">nume mp3 fara extensie</a>). 
În plus, scriptul va verifica permisiunile pentru directoare și fișiere în așa fel încât în final playlistul să poată fi 
accesat din exterior pe web.
(Indicație: trebuie setate drepturi de execuție pentru toți (sau măcar pentru others) pe directoarele ~ , ~/html și
~/html/muzica , precum și drept de citire pentru toți (sau măcar pentru others) pe fișierul playlist).

12. Să se scrie un script care să construiască o pagină web cu link-uri HTML către toate fișierele imagini 
(i.e. cele cu extensiile .jpg, .gif, .png, ș.a.) din contul personal, ordonate după data ultimei modificări a fișierelor. 
(Indicație: aveți grijă la drepturi pentru vizibilitatea pe web a paginii construite, similar ca la exercitiul precedent .)

13. Să se scrie un script care citește nume de utilizatori de la intrarea standard (folosind comanda read) și,
pentru fiecare utilizator introdus, va afișa ultimele 3 conectări (logări) ale acestuia (în luna curentă),
iar daca acesta nu s-a conectat deloc în luna curentă va afișa mesajul "Utilizatorul X nu s-a conectat niciodată!". 
(Indicație: vezi comanda last.)

II) Script pentru automatizarea procesului de dezvoltare de programe C :

Să se scrie un script care să vă ajute la scrierea programelor în C, prin care să se automatizeze ciclul de dezvoltare: 
modificare sursă -> compilare -> testare (execuție). 

Cerințe: scriptul va lansa editorul preferat pentru fișierul filename.c specificat ca parametru în linia de comandă 
(sau citit de la tastatură, în caz contrar), apoi va interoga utilizatorul dacă dorește să lanseze compilatorul și 
în caz afirmativ o va face (fișierul executabil să aibă numele filename , deci fără sufixul .c). 
Apoi, dacă sunt erori de compilare (lucru observabil prin erorile de compilare afișate de compilator), 
va relua ciclul de la editare (bineînțeles cu o pauză pentru ca utilizatorul să aibă timp să citească erorile afișate pe ecran),
iar dacă nu sunt erori la compilare, va interoga utilizatorul dacă dorește să testeze (i.e., să execute) 
acel program și în caz afirmativ va executa acel fișier executabil rezultat prin compilare. 
În concluzie, la fiecare pas să se facă o interogare a utilizatorului dacă dorește să continue cu următorul pas.

1. 
#!/bin/bash

directoare=0
fisiere_ascunse=0
symlinks=0

if [ $# -eq 0 ]
then
  read path
else
  path=$1
fi

parcurge()
{
    for f in `ls -A $1`
    do
      if [ -d $1/$f ]
      then
        let directoare++
        parcurge $1/$f
      elif [[ -f $1/$f && $f = .* ]]
      then
        let fisiere_ascunse++
      elif [ -L $1/$f ]
      then
        let symlinks++
      fi
    done
}

parcurge $path

echo $directoare $fisiere_ascunse $symlinks

2.
#!/bin/bash

if [ $# -eq 0 ]
then
  read path
else
  path=$1
fi

parcurge()
{
    for f in `ls -A $1`
    do
      if [ -d $1/$f ]
      then
        parcurge $1/$f
      elif [[ -f $1/$f && $(file $1/$f | grep "ASCII text" | wc -c) != 0 ]]
      then
        echo -n "$f: "
        echo -n "$(cat $1/$f | wc -w) "
        echo "$(cat $1/$f | wc -L) "
      fi
     done
}

parcurge $path

3.
#!/bin/bash

if [ $# = 0 ]
then
  read file
else
  file=$1
fi

echo > $file

op=0

until [[ $op = "q" ]]
do
  read x
  read y
  read op
  let nr++
  echo -n "$nr: $x $op $y = " >> $file

  if [[ $op = "+" ]]
  then
    echo $((x+y)) >> $file
  elif [[ $op = "-" ]]
  then
    echo $((x-y)) >> $file
  elif [[ $op = "*" ]]
  then
    echo $((x*y)) >> $file
  elif [[ $op = "/" ]]
  then
    echo $((x/y)) >> $file
  fi
done

4.
#!/bin/bash

directoare=0
fisiere_fifo=0

if [ $# -eq 0 ]
then
  read path
else
  path=$1
fi

parcurge()
{
    for f in `ls -A $1`
    do
      if [ -d $1/$f ]
      then
        let directoare++
        parcurge $1/$f
      elif [ -p $1/$f ]
      then
        let fisiere_fifo++
      fi
    done
}

parcurge $path

echo $directoare $fisiere_fifo

5.
#!/bin/bash

lines=0
characters=0

if [ $# -eq 0 ]
then
  read path
else
  path=$1
fi

parcurge()
{
    for f in `ls -A $1`
    do
      if [ -d $1/$f ]
      then
        parcurge $1/$f
      elif [ -f $1/$f ]
      then
        let lines+=$(cat $1/$f | wc -l)
        let characters+=$(cat $1/$f | wc -m)
      fi
    done
}

parcurge $path

echo $lines $characters

6.
#!/bin/bash

parcurge()
{
    for f in `ls -A $1`
    do
      if [ -d $1/$f ]
      then
        for ((i=1; i<=$2; i++))
        do
          echo -n -----
        done
        echo $f
        parcurge $1/$f $(($2+1))
      elif [ -f $1/$f ]
      then
        for ((i=1; i<=$2; i++))
        do
          echo -n -----
        done
        echo $f
      fi
    done
}

parcurge ~ 0

7.
#!/bin/bash

cd $1

for f in *.sh
do
  echo $f
  echo $(cat $f | grep '#')
done

8.
#!/bin/bash

for f in `find $1 -type f`
do
  if [[ -r $f && -x $f ]]
  then
    cat $f | head -n $2
  fi
done

9.
#!/bin/bash

for f in `find $1 -type f`
do
  if [[ $f = *.c ]]
  then
    gcc $f -o $(basename $f .c)
  fi
  if [[ $f = *.txt ]]
  then
    cat $f
  fi
done

10.
#!/bin/bash

for f in `find $1 -type f`
do
  if [[ $f = *.txt ]]
  then
    path=$(dirname $f)
    mv $f $path/$(basename $f .txt).ascii
  fi
done

11.
#!/bin/bash

if [ $# -eq 0 ]
then
  path=~
else
  path=$1
fi

if [ ! -d ~/html ]
then
  mkdir ~/html
fi

if [ ! -d ~/html/muzica ]
then
  mkdir ~/html/muzica
fi

echo > ~/html/muzica.html

for f in `find $path -name "*.mp3" | grep -v ~/html/muzica`
do
  ln -s $f ~/html/muzica/$(basename $f)
  echo "<a href="muzica/$(basename $f)">$(basename $f .mp3)</a><br>" >> ~/html/muzica.html
done

chmod 775 ~
chmod 775 ~/html
chmod 775 ~/html/muzica
chmod 774 ~/html/muzica.html

12.
#!/bin/bash

if [ ! -d ~/html ]
then
  mkdir ~/html
fi

echo > ~/html/imagini.html

for f in `find ~/html \( -name "*.jpg" -or -name "*.gif" -or -name "*.png" \) -printf "%p:%t\n" | sort -k 2 -t ':' | cut -f 1 -d ':'`
do
  echo "<a href="${f#/fenrir/studs/vlad.bujoreanu/html/}">$(basename $f)</a><br>" >> ~/html/imagini.html
done

chmod 774 ~/html/imagini.html

13.
#!/bin/bash

while read user
do
  ok=$(last -w | grep "^$user " | head -n 3 | wc -c)
  if [[ $ok = 0 ]]
  then
    echo "Utilizatorul $user nu s-a conectat niciodata!"
  else
    last -w | grep "^$user " | head -n 3
  fi
done

COMPILE
#!/bin/bash

if [ $# -eq 0 ]
then
  read filename
else
  filename=$1
fi

ok=1

while [ $ok -eq 1 ]
do
  vim $filename
  echo "Compilare? y/n"
  read ans
  if [ $ans = "y" ]
  then
    gcc $filename -o $(basename $filename .c)
    if [ $? -eq 0 ]
    then
      echo "Rulare? y/n"
      read ans
      if [ $ans = "y" ]
      then
        ./$(basename $filename .c)
        ok=0
      else
        exit 0
      fi
    else
      echo "Apasa ENTER pentru a reveni la editor..."
      read pauza
    fi
  else
    ok=0
  fi
done
