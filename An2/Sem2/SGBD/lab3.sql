set serveroutput on;
CREATE OR REPLACE PACKAGE manager_facultate IS
     PROCEDURE adauga_student (nume studenti.nume%type, prenume studenti.prenume%type);
     PROCEDURE sterge_student (nr_matr studenti.nr_matricol%type);
     FUNCTION afiseaza_medie (v_id studenti.id%type) return NUMBER;
END manager_facultate;
/
CREATE OR REPLACE PACKAGE BODY manager_facultate IS

      v_matr studenti.nr_matricol%TYPE;
      v_temp int;
      v_max_id studenti.id%TYPE;
      v_id studenti.id%TYPE;
      v_medie NUMBER;
    PROCEDURE adauga_student (nume studenti.nume%type, prenume studenti.prenume%type) 
       IS BEGIN
       SELECT MAX(id) INTO v_max_id FROM studenti;
       v_max_id := v_max_id + 1;
         -- begin cod preluat din scriptul de creare
         LOOP
            v_matr := FLOOR(DBMS_RANDOM.VALUE(100,999)) || CHR(FLOOR(DBMS_RANDOM.VALUE(65,91))) || CHR(FLOOR(DBMS_RANDOM.VALUE(65,91))) || FLOOR(DBMS_RANDOM.VALUE(0,9));
            select count(*) into v_temp from studenti where nr_matricol = v_matr;
            exit when v_temp=0;
         END LOOP;
         -- end cod preluat din scriptul de creare
        insert into studenti (id, nr_matricol, nume, prenume) values(v_max_id, v_matr, nume, prenume);
    END adauga_student;
    
    PROCEDURE sterge_student (nr_matr studenti.nr_matricol%type) IS
    BEGIN
       select id into v_id from studenti where nr_matricol=nr_matr;
       delete from note where id_student=v_id;
       delete from prieteni where id_student1=v_id or id_student2=v_id;
       delete from studenti where id=v_id;
    END sterge_student;
        
    FUNCTION afiseaza_medie(v_id studenti.id%type) RETURN NUMBER AS
    BEGIN
      select avg(valoare) into v_medie from studenti join note on studenti.id=note.id_student group by id_student having id_student=v_id;
      return v_medie;
    END afiseaza_medie;
    
END manager_facultate;
/
DECLARE

BEGIN
   -- manager_facultate.adauga_student('Ionescu', 'Mihai');
   -- manager_facultate.sterge_student('575UD1');
   DBMS_OUTPUT.PUT_LINE(manager_facultate.afiseaza_medie(976));
END;
--SELECT manager_facultate.afiseaza_medie(id) FROM studenti;
