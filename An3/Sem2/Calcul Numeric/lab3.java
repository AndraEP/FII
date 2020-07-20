import java.io.*;
import java.util.*;

public class lab3 
{
    public static void main(String[] args) 
    {
        Matrix A = new Matrix();
        Matrix B = new Matrix();
        A.buildMatrix("src/a.txt",11 );
        B.buildMatrix("src/b.txt",11 );
        aorib(A,B);
        aplusb(A,B);
    }

    private static void aorib(Matrix A,Matrix B)
    {
        Matrix aorib = new Matrix();
        aorib.buildMatrix("src/aorib.txt",100 );

        System.out.print("A ori B: ");
        if(Operations.eqMatrix(aorib.getMatrix(),Operations.inmMatrix(A.getMatrix(),B.getMatrix())))
            System.out.println("ok");
        else
            System.out.println("not ok");
        System.out.println();
    }

    private static void aplusb(Matrix A,Matrix B)
    {
        Matrix aplusb = new Matrix();
        aplusb.buildMatrix("src/aplusb.txt",21 );

        System.out.print("A plus B: ");
        if(Operations.eqMatrix(aplusb.getMatrix(), Operations.sumMatrix(A.getMatrix(),B.getMatrix())))
            System.out.println("ok");
        else
            System.out.println("not ok");
        System.out.println();
    }
}

class Matrix 
{
    public static final double eps = Math.pow(10, -7);
    private final List<Map<Integer, Double>> matrix;

    Matrix()
    {
        this.matrix = new ArrayList<>();
    }

    void buildMatrix(String path, int limit)
    {
        BufferedReader br = null;
        try
        {
            String sCurrentLine;
            br = new BufferedReader(new FileReader(path));
            int n = Integer.parseInt(br.readLine());

            for (int i = 0; i < n; i++)
                this.matrix.add(new TreeMap<>());

            while ((sCurrentLine = br.readLine()) != null) 
            {
                if (sCurrentLine.compareTo("") == 0)
                    break;

                String[] data = sCurrentLine.split(", ");
                double value = Double.parseDouble(data[0]);
                int ln = Integer.parseInt(data[1]);
                int cl = Integer.parseInt(data[2]);

                if (this.matrix.get(ln).size() == limit)
                    throw new IllegalArgumentException("Dimension exceeded at line " + ln);
                if (this.matrix.get(ln).size() > 0) 
                {
                    if (this.matrix.get(ln).get(cl) != null) 
                    {
                        double aux = this.matrix.get(ln).get(cl) + value;
                        this.matrix.get(ln).put(cl, aux);
                    }
                    else this.matrix.get(ln).put(cl, value);
                }
                else this.matrix.get(ln).put(cl, value);
            }
        } 
        catch (IOException e) 
        {
            throw new IllegalArgumentException("Error " + e);
        } 
        finally 
        {
            if (br != null) 
            {
                try 
                {
                    br.close();
                } 
                catch (IOException e)
                {
                    throw new IllegalArgumentException("Error " + e);
                }
            }
        }
    }

    public List<Map<Integer, Double>> getMatrix() 
    {
        return matrix;
    }
}

class Operations {

    static List<Map<Integer, Double>> inmMatrix(List<Map<Integer, Double>> A,List<Map<Integer, Double>>  B)
    {
        int n = A.size();
        List<Map<Integer, Double>> newMatrix = resMatrix(n);

        for(int i=0; i<n; i++)
        {
            for(int j=0;j<n;j++)
            {
                double total =0.0;

                for (int columnOfA:A.get(i).keySet())
                    if(B.get(columnOfA).get(j)!=null)
                        total += A.get(i).get(columnOfA) * B.get(columnOfA).get(j);
                if(checkCondition(total))
                    newMatrix.get(i).put(j,total);
            }
        }
        return newMatrix;
    }

    static List<Map<Integer, Double>> sumMatrix(List<Map<Integer, Double>> A,List<Map<Integer, Double>> B)
    {
        int n = A.size();
        List<Map<Integer, Double>> newMatrix = resMatrix(n);

        for(int i=0; i<n; i++)
        {
            Map<Integer, Double> aux = new HashMap<>(B.get(i));

            for (int index:A.get(i).keySet()) 
            {
                if(B.get(i).containsKey(index)) 
                {
                    double suma = A.get(i).get(index) + B.get(i).get(index);
                    newMatrix.get(i).put(index, suma);
                    aux.remove(index);
                }
                else newMatrix.get(i).put(index, A.get(i).get(index));
            }
            for(int index:aux.keySet())
                newMatrix.get(i).put(index,aux.get(index));
        }
        return newMatrix;
    }

    static boolean eqMatrix(List<Map<Integer, Double>> A,List<Map<Integer, Double>>  B)
    {
        int n = B.size();

        for(int i=0; i<n; i++)
        {
            for(int auxBIndex:B.get(i).keySet())
            {
                if(!A.get(i).containsKey(auxBIndex))
                    return false;
                if(checkCondition(A.get(i).get(auxBIndex) - B.get(i).get(auxBIndex)))
                    return false;
            }
        }
        return true;
    }

    private static List<Map<Integer, Double>> resMatrix(int n)
    {
        List<Map<Integer, Double>> newMatrix = new ArrayList<>();

        for(int i=0; i<n; i++)
            newMatrix.add(new HashMap<>());
        return newMatrix;
    }

    private static boolean checkCondition(double value) 
    {
        return !(Math.abs(value) < Matrix.eps);
    }
}
