drop table persons cascade constraints
/
drop table movies cascade constraints
/
drop sequence persons_sequence
/
drop sequence movies_sequence
/

create table persons
(
    id      integer       not null,
    name    varchar2(100) not null,

    constraint persons_pk primary key (id)
);
/

create table movies
(
    id          integer       not null,
    name        varchar2(100) not null,
    director_id integer       not null,

    constraint movies_pk primary key (id),
    CONSTRAINT fk_movies_director_id FOREIGN KEY (director_id) REFERENCES persons (id)
);
/

CREATE SEQUENCE persons_sequence;
/

CREATE OR REPLACE TRIGGER persons_on_insert
    BEFORE INSERT
    ON persons
    FOR EACH ROW
BEGIN
    SELECT persons_sequence.nextval INTO :new.id
    FROM dual;
END;
/

CREATE SEQUENCE movies_sequence;
/

CREATE OR REPLACE TRIGGER movies_on_insert
    BEFORE INSERT
    ON movies
    FOR EACH ROW
BEGIN
    SELECT movies_sequence.nextval INTO :new.id
    FROM dual;
END;
/