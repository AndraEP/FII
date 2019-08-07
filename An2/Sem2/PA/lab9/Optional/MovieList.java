import java.util.ArrayList;
import java.util.List;

public class MovieList {
    private String title;
    private List<Movie> movies;

    public MovieList(String title) {
        this.title = title;
        movies = new ArrayList();
    }

    public void addMovie(Movie movie) {
        movies.add(movie);
    }

    public List<Movie> getMovies() {
        return movies;
    }

    public void setMovies(List<Movie> movies) {
        this.movies = movies;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.title+"\n");
        for (Movie m:movies) {
            sb.append(m).append("   ");
        }
        return sb.toString();
    }
}
