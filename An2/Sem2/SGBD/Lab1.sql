set serveroutput on;
DECLARE
    a NUMBER := &i;
    b NUMBER := &j;
    v_id_1 studenti.id%TYPE;
    v_nume_1 studenti.nume%TYPE;
    v_prenume_1 studenti.prenume%TYPE;
    v_medie_1 FLOAT;
    v_id_2 studenti.id%TYPE;
    v_nume_2 studenti.nume%TYPE;
    v_prenume_2 studenti.prenume%TYPE;
    v_medie_2 FLOAT;
BEGIN

  SELECT id, nume, prenume INTO v_id_1, v_nume_1, v_prenume_1 FROM(
  SELECT id, nume, prenume FROM (SELECT id, nume, prenume FROM studenti ORDER BY nume, prenume) WHERE ROWNUM <= a
  MINUS
  SELECT id, nume, prenume FROM (SELECT id, nume, prenume FROM studenti ORDER BY nume, prenume) WHERE ROWNUM < a);
  SELECT AVG(valoare) INTO v_medie_1 FROM (SELECT id_student, valoare FROM studenti s JOIN note n on s.id = n.id_student WHERE id_student = a) GROUP BY id_student;
  
  SELECT id, nume, prenume INTO v_id_2, v_nume_2, v_prenume_2 FROM(
  SELECT id, nume, prenume FROM (SELECT id, nume, prenume FROM studenti ORDER BY nume, prenume) WHERE ROWNUM <= b
  MINUS
  SELECT id, nume, prenume FROM (SELECT id, nume, prenume FROM studenti ORDER BY nume, prenume) WHERE ROWNUM < b); 
  SELECT AVG(valoare) INTO v_medie_2 FROM (SELECT id_student, valoare FROM studenti s JOIN note n on s.id = n.id_student WHERE id_student = b) GROUP BY id_student;

  DBMS_OUTPUT.PUT_LINE(v_nume_1 || ' ' || v_prenume_1 || ' ' || v_medie_1);
  DBMS_OUTPUT.PUT_LINE(v_nume_2 || ' ' || v_prenume_2 || ' ' || v_medie_2);
  IF (v_medie_1 > v_medie_2)
  THEN
    DBMS_OUTPUT.PUT_LINE(v_nume_1 || ' ' || v_prenume_1 || ' are media mai mare');
  ELSE
    DBMS_OUTPUT.PUT_LINE(v_nume_2 || ' ' || v_prenume_2 || ' are media mai mare');
  END IF;
END;
