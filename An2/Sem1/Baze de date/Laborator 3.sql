1. select current_date as "Astazi" from dual;
2. select nume, data_nasterii, months_between(current_date, data_nasterii) as "Numar de luni" from studenti;
3. select to_char(data_nasterii, 'Dy') as "Day" from studenti; //poate fi dy, Dy, DY, day, Day sau DAY
4. select concat(concat(concat('Elevul ', prenume), ' este in grupa '), grupa) from studenti;
5. select rpad(bursa, 10,'$') from studenti;
6. select concat(lower(substr(nume, 1, 1)), upper(substr(nume, 2))) as "Name changed", length(nume) as "Name lenght" from profesori where nume like 'B%';
7. select nume, data_nastere, add_months(data_nasterii, ceil(months_between(current_date, data_nastere) / 12) * 12) as "Next bday", next_day(add_months(data_nasterii, ceil(months_between(current_date, data_nasterii) / 12) * 12), 'SUNDAY') as "Next sunday" FROM studenti;
8. select nume, prenume, extract(month from data_nasterii) as "Month of birth" from studenti where bursa is null order by extract(month from data_nasterii);
9. select nume, bursa, decode(bursa, 450, 'premiul 1', 350, 'premiul 2', 250, 'premiul 3', null, 'mentiune') as "Premiu" from studenti;
10. select initcap(translate(lower(nume), 'ia', 'ai')) as "Nume modificat" from studenti;
11. select ''||trunc(months_between(current_date, data_nasterii)/12)||' ani '||mod(trunc(months_between(current_date, data_nasterii)),12)||' luni si '||trunc(current_date - add_months(data_nasterii, trunc(months_between(current_date, data_nasterii))))||' zile' as "Varsta", ceil(add_months(data_nasterii, ceil(months_between(current_date, data_nasterii) / 12) * 12) - current_date) as "Days left" from studenti; 
12. select nume, trunc (add_months (current_date, 1), 'Month') as "Next first day", decode (bursa, 450, 11/10*450, 350, 115/100*350, 250, 12/10*250, 0) as "Bursa modificata" from studenti;
13. select nume, lpad (rpad ('*', bursa/50, '*'), 10, ' ') as "Bursa" from studenti where bursa is not null;
