package controller;

import entity.Movie;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Query;
import java.util.List;

public class MovieController {
    private EntityManagerFactory entityManagerFactory;

    public MovieController(EntityManagerFactory entityManagerFactory) {
        this.entityManagerFactory = entityManagerFactory;
    }

    public void create(Movie movie) {
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        entityManager.getTransaction().begin();
        entityManager.persist(movie);
        entityManager.getTransaction().commit();
        entityManager.close();
    }

    public Movie findByName(String movieName) {
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        Query query = entityManager.createQuery("select m from Movie m where m.name like :name");

        List<Movie> movies = query.setParameter("name", movieName).getResultList();
        entityManager.close();

        return movies.isEmpty() ? null : movies.get(0);
    }

    public List<Movie> findByDirectorId(long directorId) {
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        Query query = entityManager.createQuery("select m from Movie m where m.directorId = :directorId");

        List<Movie> movies = query.setParameter("directorId", directorId).getResultList();
        entityManager.close();

        return movies.isEmpty() ? null : movies;
    }
}
