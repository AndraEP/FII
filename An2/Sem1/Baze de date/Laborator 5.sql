1.select s1.nume||' '|| s1.prenume, s2.nume||' '||s2.prenume, floor(months_between(s1.data_nastere,s2.data_nastere)/12) from studenti s1,studenti s2 where s1.nr_matricol<>s2.nr_matricol and s2.data_nastere<=s1.data_nastere order by s1.data_nastere-s2.data_nastere
/
2.select s.nume|| '- '|| p.nume from studenti s cross join profesori p where length(trim(s.nume))=length(trim(p.nume))
/
3.select c.titlu_curs from cursuri c join note n on c.id_curs=n.id_curs where n.valoare<=8 minus select c.titlu_curs from note n,cursuri c where c.id_curs=n.id_curs and n.valoare>8
/
4.select s.nume from studenti s join note n on s.nr_matricol=n.nr_matricol where n.valoare>=7 minus select s.nume from studenti s,note n where s.nr_matricol=n.nr_matricol and n.valoare<7
/
5.select s.nume, n.valoare, c.titlu_curs,to_char(n.data_notare,'day') from studenti s join note n on s.nr_matricol=n.nr_matricol join cursuri c on n.id_curs=c.id_curs and c.titlu_curs like'OOP%'and n.valoare=ANY(7,10) and to_char(n.data_notare,'day') like 'mar%'
/
6.select nume, prenume, valoare, trim(to_char(data_notare,'month'))||' '|| to_char(data_notare,'yyyy') as "sesiune", decode(to_char(data_notare,'MONTH'),'FEBRUARY','+',null) from studenti s, note n where s.nr_matricol=n.nr_matricol and valoare>=5 order by "sesiune"
/
