set serveroutput on;

CREATE OR REPLACE PROCEDURE populare
  IS
    lista_tmp lista_cursuri := lista_cursuri();
  BEGIN
    FOR student in (SELECT * FROM studenti) LOOP
      FOR nota in (SELECT * FROM note WHERE student.id = id_student) LOOP
        IF (nota.valoare=9 OR nota.valoare=10) THEN
          lista_tmp.EXTEND();
          lista_tmp(lista_tmp.count) := nota.id_curs;
        END IF;
      END LOOP;
      UPDATE studenti set note_mari=lista_tmp WHERE studenti.id=student.id;
      lista_tmp.delete;
    END LOOP;
  END populare;
    
CREATE OR REPLACE FUNCTION nr_note_mari(input_id int)
RETURN INT AS
  lista_tmp lista_cursuri;
BEGIN
  SELECT note_mari into lista_tmp FROM studenti WHERE id=input_id;
  return lista_tmp.count;
END;
    
DECLARE

BEGIN
  populare();
END;
--CREATE OR REPLACE TYPE lista_cursuri IS TABLE OF INT;
--ALTER TABLE studenti ADD note_mari lista_cursuri NESTED TABLE note_mari STORE AS lista;
--SELECT note_mari FROM studenti;
--SELECT id, note_mari, nr_note_mari(id) FROM studenti;
