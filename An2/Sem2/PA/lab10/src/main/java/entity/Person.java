package entity;

import javax.persistence.*;
import java.util.Objects;

@Entity
@Table(name = "PERSONS", schema = "STUDENT", catalog = "")
public class Person {
    private long id;
    private String name;

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

    @Override
    public boolean equals(Object o) {

        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Person that = (Person) o;
        return id == that.id &&
                Objects.equals(name, that.name);

    }

    @Override
    public int hashCode() {
        return Objects.hash(id, name);
    }
}
