Exerciții cu fișiere de comenzi (partea a 2-a)

1. Să se scrie un script care să efectueze calculul iterativ al factorialului (i.e. n! = 1 * 2 * ... * n, pentru n > 0). 
(Indicație: valoarea pentru n se va prelua ca argument din linia de comandă prin care se lansează scriptul, sau se va citi cu comanda read, în caz că nu este dată în linia de comandă.)

2. Să se scrie un script care să efectueze calculul recursiv al factorialului (i.e. n! = n * (n-1)!, pentru n > 0, respectiv 0! = 1). 
(Indicație: valoarea pentru n se va prelua ca argument din linia de comandă prin care se lansează scriptul, sau se va citi cu comanda read, în caz că nu este dată în linia de comandă.)

3. Să se scrie un script care primește ca parametru la linia de comandă un director și care compilează toate fișierele sursă C++ aflate doar în acest director (nu și cele din subdirectoarele lui). Compilarea se realizează în felul următor:   g++ fisier.cpp -o fisier 
(Indicație: folosind comanda basename se poate obține numele fișierului fără extensie: basename fisier.cpp .cpp afișează pe stdout doar 'fisier'.)

4. i) Să se scrie un script care să efectueze calculul produsului n * m prin adunări repetate (i.e. n * m = n + n + ... + n, de m ori). 
(Indicație: valorile pentru n și m se vor prelua ca argumente din linia de comandă prin care se lansează scriptul, sau se vor citi cu comanda read, în caz că nu sunt date în linia de comandă.) 
ii) Să se scrie un script care să efectueze calculul puterii n la m prin înmulțiri repetate. 
(Indicație: valorile pentru n și m se vor prelua ca argumente din linia de comandă prin care se lansează scriptul, sau se vor citi cu comanda read, în caz că nu sunt date în linia de comandă.)

5. Să se scrie un script care să calculeze media aritmetică a n numere. 
(Indicație: valorile pentru n și pentru cele n numere vor fi preluate ca argumente la linia de comandă prin care se lansează scriptul, sau se vor citi cu comanda read, în caz că nu sunt date în linia de comandă.)

6. Să se scrie un script care să calculeze valorile minime și maxime ale argumentelor date la linia de comandă. 
(Indicație: valorile numerice se vor citi prin comanda read, dacă nu sunt date în linia de comandă.)

7. Să se scrie un script care să calculeze valoarea de rang n din șirul lui Fibonacci. 
(Indicație: valoarea pentru n va fi preluată ca argument la linia de comandă prin care se lansează scriptul, sau se va citi prin comanda read, în caz că nu este dată în linia de comandă.)

8. Să se scrie un script care să calculeze valoarea numerică ce apare de cele mai multe ori, precum și numărul ei de apariții, în șirul de valori numerice date ca argumente în linia de comandă. 
(Indicație: valorile numerice se vor citi prin comanda read, dacă nu sunt date în linia de comandă.)

9. Să se scrie un script care să calculeze C(n,k) (i.e. combinări de n luate câte k). 
(Indicație: valorile n și k se vor da ca argumente în linia de comandă prin care se lansează script-ul, sau se vor citi prin comanda read, în caz că nu sunt date în linia de comandă.)

10. Să se scrie un script care va fi lansat cu 1+N*k+p argumente, unde k și p sunt variabile și necunoscute apriori. Scriptul preia primul argument într-o variabilă N și calculează suma următoarelor argumente luate câte N (deci suma primelor N argumente, apoi a următoarelor N numere ș.a.m.d., iar dacă la sfârșit rămâne un număr mai mic decât N de argumente, va calcula doar suma acestora), afișând valorile sumelor pe ecran și scriindu-le în același timp într-un fișier output.txt. 
Dacă este lansat fără nici un parametru, atunci va cere introducerea unei valori numerice N și apoi a altor N valori numerice (presupunem numere întregi), afișând ca rezultat doar această primă sumă. 
(Indicație: man expr și help shift.)

11. Să se scrie un script care, pentru un utilizator specificat prin UID-ul acestuia dat ca parametru în linia de comandă, să afișeze numele lui real (și nu numele de utilizator), precum și denumirea tuturor grupurilor din care face parte. 
(Indicație: pentru a obține informațiile cerute, puteți folosi comanda id și/sau prelucrați fișierele /etc/passwd și /etc/group.)

12. Să se scrie un script care să afișeze care dintre utilizatorii ce sunt studenți și al căror nume de cont începe cu o literă dată, au pagini web pe serverul fenrir. 
(Indicație: testați existența și vizibilitatea pentru toată lumea a unuia dintre fișierele index.htm sau index.html sau index.php, ce ar trebui să se afle în subdirectorul html din directorul home al utilizatorului ce are pagină web.)




#!pentru creare touch nume_fisier.sh
#!pentru editare nano nume_fisier.sh
#!pentru executie chmod +x fact.sh
#!pentru apelare ./fact.sh




1.
#!/bin/bash #!un fel de include si using...

read n #citeste n

x=1 #atribuie var res valoarea 1

for ((i=1; i<=n; i++)) #se parcurge factorialul n
do
  x=$((x*i)) #sau let "x=x*i"
done

echo $x

2.
#!/bin/bash

fact()
{
    n=$1  
    if (($n > 1))  #if ((n>1))
    then
      echo $(($n * $(fact $(($n - 1))))) #/$((n * $(fact $((n - 1))))) 
    else
      echo 1
    fi
}

fact $1

# la apelare se pune parametru; ex: ./factrec.sh parametru; valoarea pentru n se va prelua ca argument din linia de comandă prin care se lansează scriptul

3.
#!/bin/bash

cd $1
n=$(find . -maxdepth 1 -type f -name "*.cpp" | wc -l)
for ((i=1; i<=$n; i++))
do
  this=$(find . -maxdepth 1 -type f -name "*.cpp" | tail -n +$i | head -n 1)
  this=$(basename $this .cpp)
  g++ $this.cpp -o $this
done

4.
a) #!/bin/bash

n=$1
m=$2
res=0

for ((i=1; i<=$m; i++))
do
  res=$(($res+$n))
done

echo $res
b) #!/bin/bash

n=$1
m=$2
res=1

for ((i=1; i<=$m; i++))
do
  res=$(($res*$n))
done

echo $res

5.
#!/bin/bash

res=0

for ((i=1; i<=$#; i++))
do
  res=$(($res+${!i}))
done

res=$(($res/$#))

echo $res

6. 
#!/bin/bash

maxi=$1
mini=$1

for ((i=1; i<=$#; i++))
do

  if ((${!i}>maxi))
  then
    maxi=${!i}
  fi

  if ((${!i}<mini))
  then
    mini=${!i}
  fi

done

echo $mini $maxi

7.
#!/bin/bash

v1=1
v2=1

for ((i=3; i<=$1; i++))
do
  v3=$(($v1+$v2))
  v1=$v2
  v2=$v3
done

echo $v3

8.
#!/bin/bash

voturi=0
candidat=0

for ((i=1; i<=$#; i++))
do
  array[${!i}]=$((${array[${!i}]}+1))
  if ((${!i}>maxi))
  then
    maxi=${!i}
  fi
done

echo ${array[9]}

for ((i=1; i<=$#; i++))
do
  if ((${array[${!i}]}>$voturi))
  then
    voturi=$((${array[${!i}]}))
    candidat=${!i}
  fi
done

echo $candidat $voturi

9. 
#!/bin/bash

res1=1
res2=1
res3=1
n=$1
k=$2

for ((i=1; i<=$n; i++))
do
  res1=$(($res1*$i))
done

for ((i=1; i<=$k; i++))
do
  res2=$(($res2*$i))
done

for ((i=1; i<=$(($n-$k)); i++))
do
  res3=$(($res3*$i))
done

res4=$(($res1/$res2))
res4=$(($res4/$res3))

echo $res4

10.
#!/bin/bash

if [ $# -eq 0 ]
then
  read n
  for ((i=1; i<=$n; i++))
  do
    read i
    sum=$(($sum+$i))
  done
  echo $sum
else
  n=$1
  k=$(( ($#-1)/$n ))
  p=$(( ($#-1)%$n ))

  for ((i=0; i<$k; i++))
  do
    sum=0
    for ((j=1; j<=$n; j++))
    do
      position=$((1+(i*n)+j))
      sum=$(( $sum+${!position} ))
    done
    echo $sum
    echo $sum >> output.txt 
  done

  if [ $p -ne 0 ]
  then
    sum=0
    for ((i=1; i<=$p; i++))
    do
      position=$((position+1))
      sum=$(( $sum+${!position} ))
    done
    echo $sum
    echo $sum >> output.txt
  fi
fi

11.
#!/bin/bash

string1=$(cat /etc/passwd | grep :$1: | cut -f 1 -d ':')
string2=$(id $string1 | cut -f 3 -d ' ' | cut -f 2 -d '=')
string1=$(echo $string1 | tr -s '.' ' ' | tr -s [:lower:] [:upper:])

echo $string1 $string2

12.
#!/bin/bash

var1=$(cat /etc/passwd | grep studs | grep "^$1" | cut -f 1 -d ':')
n=$(echo $var1 | wc -w)

for ((i=1; i<=$n; i++))
do
  current=$(echo $var1 | cut -f $i -d ' ')
  if [ -r /fenrir/studs/$current/html/index.html -o -r /fenrir/studs/$current/html/index.html -o -r /fenrir/studs/$current/html/index.php ]
  then
    echo $current
  fi
done
