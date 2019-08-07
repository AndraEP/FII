import javax.xml.crypto.Data;
import java.sql.SQLException;
import java.util.*;

public class Main {

    public static int verificare(Movie a, Movie b) {
        for(int i = 1; i<= a.nrOfActors; i++) {
            for(int j=1;j<=b.nrOfActors;j++) {
                if(a.actori[i] == b.actori[j]) {
                    return 0;
                }
            }
        }
        return 1;
    }

    public static List<MovieList> getMovieLists() {
        MovieController movies = new MovieController();
        List<Person> actori = null;
        List<Movie> listaFilme = movies.findAll();
        List<MovieList> finalList = new ArrayList();
        int viz[][] = new int[listaFilme.size()+1][listaFilme.size()+1];
        int luat[] = new int[listaFilme.size()+1];
        int cnt = listaFilme.size();
        for(int i=0;i<=listaFilme.size();i++) {
            luat[i] = 0;
        }

        for (Movie film : listaFilme) {
            actori = film.getActors();
            for (Person actor : actori) {
                film.actori[++film.nrOfActors] = actor.getId();
            }
        }
        for( int i = 0; i < listaFilme.size(); i++ ) {
            for ( int j = 0; j < listaFilme.size(); j++) {
                viz[i][j] = verificare(listaFilme.get(i),listaFilme.get(j));
            }
        }

        while(cnt != 0) {
            int found=0;
            for(int i = 0;i<listaFilme.size();i++) {
                if(luat[i]==0) {
                    found = i;
                    break;
                }
            }
            MovieList auxiliarList = new MovieList("Lista");
            auxiliarList.addMovie(listaFilme.get(found));
            luat[found] = 1;
            cnt--;
            for(int i=found+1;i<listaFilme.size();i++) {
                int ok = 1;
                for(int j=0;j<auxiliarList.getMovies().size();j++) {

                    if(viz[i][auxiliarList.getMovies().get(j).getId()-1]==0) {
                        ok=0;
                        break;
                    }
                }
                if(ok==1&&luat[i]==0) {
                    auxiliarList.addMovie(listaFilme.get(i));
                    luat[i]=1;
                    cnt--;
                }
            }
            finalList.add(auxiliarList);
        }

        return finalList;
    }

    public static void main(String[] args) {

        try {
            PersonController persons = new PersonController();
            MovieController movies = new MovieController();
            //persons.create("James Cameron","director");
            //persons.create("Leonardi DiCaprio","actor");
            //persons.create("Brad Pitt","actor");
           // Database.commit();
            //Actor a = new Actor(6,"Brad Pitt");
            //Movie m = new Movie(1,"The Godfather",1);
            //m.addActor(a);
            //movies.create("Avatar", persons.findByName("Cameron"));
            //List<Person> lista = persons.findAll();
            //for (Person persoana : lista ) {
            //    System.out.println(persoana);
            //}

            List<MovieList> listeMaximale = getMovieLists();
            for(MovieList movieList: listeMaximale) {
                System.out.println(movieList);
            }

            //Add other movies to the database
            //Database.commit();

            Database.closeConnection();

        } /*catch (java.sql.SQLException e) {
            System.err.println(e);
            Database.rollback();
        } */catch (Exception e){
            System.err.println(e);
        }
    }
}
