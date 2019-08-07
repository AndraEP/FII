DROP TABLE persons CASCADE CONSTRAINTS
/
DROP TABLE movies CASCADE CONSTRAINTS
/
DROP TABLE movie_actors CASCADE CONSTRAINTS
/
CREATE TABLE persons(
  id INT NOT NULL PRIMARY KEY,
  name VARCHAR2(256) NOT NULL
)
/
CREATE TABLE movies(
  id INT NOT NULL PRIMARY KEY,
  name VARCHAR2(256) NOT NULL,
  director_id INT NOT NULL,
  CONSTRAINT fk_director_id FOREIGN KEY(director_id) REFERENCES persons(id)
)
/
CREATE TABLE movie_actors(
  movie_id INT NOT NULL,
  actor_id INT NOT NULL,
  CONSTRAINT fk_movie_id FOREIGN KEY(movie_id) REFERENCES movies(id),
  CONSTRAINT fk_actor_id FOREIGN KEY(actor_id) REFERENCES persons(id)
)
/