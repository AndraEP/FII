set serveroutput on;
DECLARE
   v_id NUMBER := &i;
   v_nota_maxima NUMBER;
   v_nume_nota_maxima VARCHAR2(30);
   v_prenume_nota_maxima VARCHAR2(30);
BEGIN
    FOR v_linie IN (SELECT nume, prenume, titlu_curs, valoare, id_curs FROM studenti s JOIN note n ON s.id=n.id_student JOIN cursuri c on n.id_curs=c.id WHERE s.id=v_id) LOOP     
        DBMS_OUTPUT.PUT_LINE(v_linie.nume || ' ' || v_linie.prenume || ' a luat nota ' || v_linie.valoare || ' la materia ' || v_linie.titlu_curs);
        v_nota_maxima := v_linie.valoare;
        FOR v_linie_prieteni IN (SELECT nume, prenume, id_student2 FROM prieteni p JOIN studenti s ON s.id=p.id_student2 WHERE p.id_student1=v_id) LOOP
            FOR v_linie_materii_prieteni IN (SELECT titlu_curs, valoare FROM note n JOIN cursuri c on n.id_curs=c.id WHERE v_linie_prieteni.id_student2=n.id_student AND v_linie.titlu_curs=titlu_curs) LOOP
                IF (v_linie_materii_prieteni.valoare > v_nota_maxima)
                THEN
                  v_nota_maxima := v_linie_materii_prieteni.valoare;
                  v_nume_nota_maxima := v_linie_prieteni.nume;
                  v_prenume_nota_maxima := v_linie_prieteni.prenume;
                  END IF;
                DBMS_OUTPUT.PUT_LINE('Prietenul ' || v_linie_prieteni.nume || ' ' || v_linie_prieteni.prenume || ' a luat nota ' || v_linie_materii_prieteni.valoare || ' la materia ' || v_linie_materii_prieteni.titlu_curs);
            END LOOP;
        END LOOP;
        IF (v_nota_maxima > v_linie.valoare)
        THEN
          DBMS_OUTPUT.PUT_LINE('Nota maxima este a lui ' || v_nume_nota_maxima || ' ' || v_prenume_nota_maxima || ' cu valoarea ' || v_nota_maxima);
          UPDATE note SET valoare=v_nota_maxima WHERE id_student=v_id AND id_curs=v_linie.id_curs;
        ELSE
          DBMS_OUTPUT.PUT_LINE('Niciunul din prieteni nu are o nota mai mare.');
        END IF;
        DBMS_OUTPUT.PUT_LINE('');
    END LOOP;
END;
