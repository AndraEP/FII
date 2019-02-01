CREATE TABLE studenti
(
  nr_matricol CHAR(6) NOT NULL,
  nume VARCHAR2(10) NOT NULL,
  prenume VARCHAR2(10) NOT NULL,
  an NUMBER(1,0),
  grupa CHAR(2),
  bursa NUMBER(4,2),
  data_nastere DATE
 );


CREATE TABLE cursuri
(
  id_curs CHAR(4) NOT NULL,
  titlu_curs VARCHAR2(10) NOT NULL,
  an NUMBER(1,0),
  semestru NUMBER(1,0),
  credite NUMBER(2,0)
 );


CREATE TABLE note
(
  nr_matricol CHAR(6) NOT NULL,
  id_curs CHAR(4) NOT NULL,
  valoare NUMBER(2,0),
  data_notare DATE
 );


CREATE TABLE profesori
(
  id_prof CHAR(4) NOT NULL,
  nume VARCHAR2(10) NOT NULL,
  prenume VARCHAR2(10),
  grup_didactic VARCHAR2(5)
 );


CREATE TABLE didactic
(
  id_prof CHAR(4) NOT NULL,
  id_curs CHAR(4) NOT NULL
);





INSERT INTO studenti VALUES ('111', 'Popescu', 'Bogdan',3, 'A2',NULL, TO_DATE('17/02/1995', 'dd/mm/yyyy'));
INSERT INTO studenti VALUES ('112', 'Prelipcean', 'Radu',3, 'A2',NULL, TO_DATE('26/05/1995', 'dd/mm/yyyy'));
INSERT INTO studenti VALUES ('113', 'Antonie', 'Ioana',3, 'A2',450, TO_DATE('3/01/1995', 'dd/mm/yyyy'));
INSERT INTO studenti VALUES ('114', 'Arhire', 'Raluca',3, 'A4',NULL, TO_DATE('26/12/1995', 'dd/mm/yyyy'));
INSERT INTO studenti VALUES ('115', 'Panaite', 'Alexandru',3, 'B3',NULL, TO_DATE('13/04/1995', 'dd/mm/yyyy'));
INSERT ALL
INTO studenti (nr_matricol, nume, prenume, an, grupa, bursa, data_nasterii) VALUES ('118', 'Ciobotariu', 'Ciprian',2, 'A1',35, TO_DATE('03/04/1996', 'dd/mm/yyyy'))
INTO studenti (nr_matricol, nume, prenume, an, grupa, bursa, data_nasterii) VALUES ('119', 'Bodnar', 'Ioana',2, 'B2',NULL, TO_DATE('10/06/1996', 'dd/mm/yyyy'))
SELECT * FROM dual;
INSERT ALL
INTO studenti (nr_matricol, nume, prenume, an, grupa, bursa, data_nasterii) VALUES ('120', 'Pintescu', 'Andrei',1, 'B1',25, TO_DATE('26/08/1997', 'dd/mm/yyyy'))
INTO studenti (nr_matricol, nume, prenume, an, grupa, bursa, data_nasterii) VALUES ('121', 'Arhire', 'Alexandra',1, 'B1',NULL, TO_DATE('02/07/1997', 'dd/mm/yyyy'))
INTO studenti (nr_matricol, nume, prenume, an, grupa, bursa, data_nasterii) VALUES ('122', 'Cobzaru', 'George',1, 'B1',35, TO_DATE('29/04/1997', 'dd/mm/yyyy'))
INTO studenti (nr_matricol, nume, prenume, an, grupa, bursa, data_nasterii) VALUES ('123', 'Bucur', 'Andreea',1, 'B2',NULL, TO_DATE('10/05/1997', 'dd/mm/yyyy'))
SELECT * FROM dual;



INSERT ALL
INTO cursuri (id_curs, titlu_curs, an, semestru, credite) VALUES
('21', 'Logica', 1, 1, 5)
INTO cursuri (id_curs, titlu_curs, an, semestru, credite) VALUES ('22', 'Matematica', 1, 1, 4)
INTO cursuri (id_curs, titlu_curs, an, semestru, credite) VALUES ('23', 'OOP', 1, 2, 5)
INTO cursuri (id_curs, titlu_curs, an, semestru, credite) VALUES ('24', 'BD', 2, 1, 8)
INTO cursuri (id_curs, titlu_curs, an, semestru, credite) VALUES ('25', 'Java', 2, 2, 5)
INTO cursuri (id_curs, titlu_curs, an, semestru, credite) VALUES ('26', 'Tehnologii', 2, 2, 5)
INTO cursuri (id_curs, titlu_curs, an, semestru, credite) VALUES ('27', 'Sec. Info.', 3, 1, 5)
INTO cursuri (id_curs, titlu_curs, an, semestru, credite) VALUES ('28', 'DSFUM', 3, 1, 6)
INTO cursuri (id_curs, titlu_curs, an, semestru, credite) VALUES ('29', 'Limbaje', 2, 1, 5)
INTO cursuri (id_curs, titlu_curs, an, semestru, credite) VALUES ('30', 'Machine', 3, 1, 5)
SELECT * FROM dual;



INSERT ALL
INTO profesori (id_prof, nume, prenume, grad_didactic) VALUES ('p1', 'Masalagiu', 'Cristian', 'Prof')
INTO profesori (id_prof, nume, prenume, grad_didactic) VALUES ('p2', 'Buraga', 'Sabin', 'Conf')
INTO profesori (id_prof, nume, prenume, grad_didactic) VALUES ('p3', 'Lucanu', 'Dorel', 'Prof')
INTO profesori (id_prof, nume, prenume, grad_didactic) VALUES ('p4', 'Tiplea', 'Laurentiu', 'Prof')
INTO profesori (id_prof, nume, prenume, grad_didactic) VALUES ('p5', 'Iacob', 'Florin', 'Lect')
INTO profesori (id_prof, nume, prenume, grad_didactic) VALUES ('p6', 'Breaban', 'Mihaela', 'Conf')
INTO profesori (id_prof, nume, prenume, grad_didactic) VALUES ('p7', 'Varlan', 'Cosmin', 'Lect')
INTO profesori (id_prof, nume, prenume, grad_didactic) VALUES ('p8', 'Frasinaru', 'Cristian', 'Prof')
INTO profesori (id_prof, nume, prenume, grad_didactic) VALUES ('p9', 'Ciobaca', 'Stefan', 'Conf')
INTO profesori (id_prof, nume, prenume, grad_didactic) VALUES ('p10', 'Captarencu', 'Oana', 'Lect')
INTO profesori (id_prof, nume, prenume, grad_didactic) VALUES ('p11', 'Moruz', 'Alexandru', 'Lect')
SELECT * FROM dual;
INSERT INTO profesori VALUES('p20', 'PASCARIU', 'GEORGIANA', null);
INSERT INTO profesori VALUES('p21', 'LAZAR', 'LUCIAN', null);
INSERT INTO profesori VALUES('p22', 'Kristo', 'ROBERT', null);
INSERT INTO profesori VALUES('p20', 'Nastasa', 'Laura', null);



INSERT ALL
INTO didactic (id_prof, id_curs) VALUES ('p1','21')
INTO didactic (id_prof, id_curs) VALUES ('p9','21')
INTO didactic (id_prof, id_curs) VALUES ('p5','22')
INTO didactic (id_prof, id_curs) VALUES ('p3','23')
INTO didactic (id_prof, id_curs) VALUES ('p6','24')
INTO didactic (id_prof, id_curs) VALUES ('p7','24')
INTO didactic (id_prof, id_curs) VALUES ('p8','25')
INTO didactic (id_prof, id_curs) VALUES ('p2','26')
INTO didactic (id_prof, id_curs) VALUES ('p4','27')
INTO didactic (id_prof, id_curs) VALUES ('p7','28')
SELECT * FROM dual;



INSERT ALL
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('111', '21',  8, TO_DATE('17/02/2014', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('111', '22',  9, TO_DATE('19/02/2014', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('111', '23', 10, TO_DATE('24/06/2014', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('111', '24',  9, TO_DATE('17/02/2015', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('111', '25',  7, TO_DATE('20/06/2015', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('111', '26',  8, TO_DATE('21/06/2015', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES  ('112', '21',  7, TO_DATE('25/02/2014', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('112', '22',  6, TO_DATE('19/02/2014', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES  ('112', '23',  5, TO_DATE('24/06/2014', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES  ('112', '24',  6, TO_DATE('17/02/2015', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES  ('112', '25',  7, TO_DATE('20/06/2015', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES  ('112', '26',  4, TO_DATE('21/06/2015', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('113', '21',  9, TO_DATE('17/02/2014', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('113', '22',  9, TO_DATE('19/02/2014', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('113', '23',  7, TO_DATE('24/06/2014', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('113', '24', 10, TO_DATE('17/02/2015', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('113', '25',  4, TO_DATE('20/06/2015', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('113', '26',  7, TO_DATE('21/06/2015', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('114', '21',  6, TO_DATE('17/02/2014', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('114', '22',  9, TO_DATE('19/02/2014', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('114', '23', 10, TO_DATE('24/06/2014', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('114', '24',  4, TO_DATE('17/02/2015', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('114', '25',  5, TO_DATE('20/06/2015', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('114', '26',  4, TO_DATE('21/06/2015', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('115', '21', 10, TO_DATE('17/02/2014', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('115', '22',  7, TO_DATE('19/02/2014', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('115', '23', 10, TO_DATE('24/06/2014', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('115', '24', 10, TO_DATE('17/02/2015', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('115', '25',  8, TO_DATE('20/06/2015', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('115', '26',  9, TO_DATE('21/06/2015', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('116', '21', 10, TO_DATE('18/02/2015', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('116', '22', 10, TO_DATE('20/02/2015', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('116', '23',  9, TO_DATE('21/06/2015', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('117', '21',  7, TO_DATE('18/02/2015', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('117', '22',  6, TO_DATE('20/02/2015', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('117', '23',  4, TO_DATE('25/06/2015', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES  ('118', '21',  7, TO_DATE('22/02/2015', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('118', '22',  7, TO_DATE('24/02/2015', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('118', '23',  7, TO_DATE('21/06/2015', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('119', '21',  7, TO_DATE('18/02/2015', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('119', '22',  8, TO_DATE('20/02/2015', 'dd/mm/yyyy'))
INTO note (nr_matricol, id_curs, valoare, data_notare) VALUES ('119', '23',  9, TO_DATE('21/06/2015', 'dd/mm/yyyy'))
SELECT * FROM dual;
