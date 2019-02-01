1. select s.nume, s.prenume, n.valoare, p.nume from studenti s join note n on s.nr_matricol = n.nr_matricol join didactic d on n.id_curs = d.id_curs join profesori p on d.id_prof = p.id_prof;

2. select s.nume, s.prenume from studenti s join note n on s.nr_matricol = n.nr_matricol join cursuri c on n.id_curs = c.id_curs where n.valoare = '10' and c.titlu_curs = 'BD';

3. select p.nume, p.prenume, c.titlu_curs from profesori p join didactic d on d.id_prof = p.id_prof join cursuri c on d.id_curs = c.id_curs;

4. select p.nume, p.prenume, c.titlu_curs from profesori p left outer join didactic d on d.id_prof = p.id_prof left outer join cursuri c on d.id_curs = c.id_curs;

5. select p.nume, p.prenume, c.titlu_curs from profesori p right outer join didactic d on d.id_prof = p.id_prof right outer join cursuri c on d.id_curs = c.id_curs;

6. select p.nume, p.prenume, c.titlu_curs from profesori p full outer join didactic d on d.id_prof = p.id_prof full outer join cursuri c on d.id_curs = c.id_curs;

7. select s.nume ||'-'|| s1.nume, to_char (s.data_nastere, 'day') from studenti s join studenti s1 on to_char (s.data_nastere, 'day') = to_char (s1.data_nastere,'day') and s1.nr_matricol = s2.nr_matricol and s.nume <= s1.nume order by to_char (s.data_nastere, 'day'), s.nume asc;

8. select s.nume ||' '|| s.prenume ||' a luat nota mai mare ca '|| s1.nume ||' '|| s1.prenume ||' la materia '|| c.titlu_curs from cursuri c join note n1 on 
n1.id_curs = c.id_curs join note n2 on n2.id_curs = c.id_curs join studenti s on s.nr_matricol = n1.nr_matricol join studenti s1 on s1.nr_matricol = n2.nr_matricol where n1.valoare > n2.valoare;
