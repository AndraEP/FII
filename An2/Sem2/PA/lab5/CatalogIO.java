import java.awt.*;
import java.io.*;

public class CatalogIO {
    private String path;
    private Desktop desktop;

    public CatalogIO(String path) {
        this.path = path;
        this.desktop = Desktop.getDesktop();
    }

    public void open(String inputPath) {
        File file;
        File tmp = new File(inputPath);
        if (tmp.isFile()) {
            file = tmp;
        } else {
            file = new File(path + "/" + inputPath);
        }
        try {
            desktop.open(file);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void save(Catalog c, String path) {
        try {
            FileOutputStream file = new FileOutputStream(path);
            ObjectOutputStream out = new ObjectOutputStream(file);
            out.writeObject(c);
            out.close();
            file.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void load(Catalog c, String path) {
        try {
            FileInputStream file = new FileInputStream(path);
            ObjectInputStream in = new ObjectInputStream(file);
            c = (Catalog) in.readObject();
            in.close();
            file.close();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            System.out.println("Catalog class not found");
            e.printStackTrace();
        }
    }
}
