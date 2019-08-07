package app;

import controller.MovieController;
import controller.PersonController;
import entity.Movie;
import entity.Person;

import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;
import java.util.List;
import java.util.Scanner;

public class MovieManager {
    static final EntityManagerFactory emf = Persistence.createEntityManagerFactory("MoviesPU");
    static final PersonController personController = new PersonController(emf);
    static final MovieController movieController = new MovieController(emf);

    public void run() {

        Scanner scanner = new Scanner(System.in);

        while (true) {
        System.out.print("Input command:");
        String command = scanner.nextLine();
        if (command.equals("exit")) break;
        String[] params = command.trim().split("\\s+");

        switch (params[0]) {
        case "create-person":
        createPerson(params[1]); //the person name
        break;
        case "create-movie":
        createMovie(params[1], params[2]); //the movie name and the director
        break;
        case "list-movies":
        listMovies(params[1]); //the director name
        break;
        }
        }

    }

    private void createPerson(String personName) {
        Person person = new Person();
        person.setName(personName);

        personController.create(person);
    }

    private void createMovie(String movieName, String directorName) {
        Person director = personController.findByName(directorName);

        if (director == null)
            return;

        Movie movie = new Movie();
        movie.setName(movieName);
        movie.setDirectorId(director.getId());

        movieController.create(movie);
    }

    private void listMovies(String directorName) {
        Person director = personController.findByName(directorName);

        if (director == null)
            return;

        List<Movie> movies = movieController.findByDirectorId(director.getId());

        for (Movie movie : movies) {
            System.out.println(movie.getName());
        }
    }

    public static void main(String args[]) {
        new MovieManager().run();
    }
}
