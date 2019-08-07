public class Director extends Person {
    public Director() {
        this.job = "director";
    }
    public Director(int id, String name) {
        this.id = id;
        this.name = name;
        this.job = "director";
    }

    public int getId() {
        return this.id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getJob() {
        return this.job;
    }
}
