package entity;

import javax.persistence.*;
import java.util.Objects;

@Entity
@Table(name = "MOVIES", schema = "STUDENT", catalog = "")
public class Movie {
    private long id;
    private String name;
    private long directorId;

    @Id
    @Column(name = "ID")
    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    @Basic
    @Column(name = "NAME")
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Basic
    @Column(name = "DIRECTOR_ID")
    public long getDirectorId() {
        return directorId;
    }

    public void setDirectorId(long directorId) {
        this.directorId = directorId;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Movie that = (Movie) o;
        return id == that.id &&
                directorId == that.directorId &&
                Objects.equals(name, that.name);

    }

    @Override
    public int hashCode() {
        return Objects.hash(id, name, directorId);
    }
}
