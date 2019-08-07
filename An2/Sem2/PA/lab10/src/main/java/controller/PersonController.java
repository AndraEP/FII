package controller;

import entity.Person;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Query;
import java.util.List;

public class PersonController {
    private EntityManagerFactory entityManagerFactory;

    public PersonController(EntityManagerFactory entityManagerFactory) {
        this.entityManagerFactory = entityManagerFactory;
    }

    public void create(Person person) {
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        entityManager.getTransaction().begin();
        entityManager.persist(person);
        entityManager.getTransaction().commit();
        entityManager.close();
    }

    public Person findByName(String personName) {
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        Query query = entityManager.createQuery("select t from Person t where t.name like :name");

        List<Person> persons =query.setParameter("name",personName).getResultList();
        entityManager.close();

        return persons.isEmpty()? null : persons.get(0);
    }
}
