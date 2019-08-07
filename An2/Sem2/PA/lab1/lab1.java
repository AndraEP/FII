import java.util.Scanner;

public class HelloWorld{

    public static void main(String []args){

        final long startTime = System.nanoTime();
        System.out.println("Hello World");
        System.out.println();

        String[] languages = {"C", "C++", "C#", "Go", "JavaScript", "Perl", "PHP", "Python", "Swift", "Java"};
        int n = (int) (Math.random() * 1_000_000);

        n = n * 3;
        n = n + 0b10101;
        n = n + 0xFF;
        n = n * 6;

        int result = 0;
        int ok = 0;

        while ((n / 10) > 0)
        {
            int sum = 0;
            while (n != 0) {
                sum = n % 10;
                n = n / 10;
            }
            result = sum;
        }

        System.out.println("Willy-nilly, this semester i will learn " + languages[result] + ".");
        System.out.println();

        Scanner sc = new Scanner (System.in);
        int m = sc.nextInt();

        while (ok == 0)
        {
            if (m % 2 == 0)
            {
                System.out.println("Numarul nu este impar.");
                m = sc.nextInt();
            }
            else
            {
                ok = 1;
                System.out.println("Numarul este impar.");
            }
        }
        System.out.println();

        int[][] v = new int[m][m] ;
        int edges, sumMin, sumMax, sum;
        String maxDegreeSymbol = "\u0394";
        String minDegreeSymbol = "\u03B4";

        //complete graph
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                if (i != j)
                    v[i][j] = 1;
        if (m < 30_000) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++)
                    System.out.print(v[i][j]);
                System.out.println();
            }
            System.out.println();
        }
        //edges complete graph
        edges = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++)
                edges = edges + v[i][j];
        }
        System.out.println("Number of edges in the complete graph: " + edges);

        //vertex degree
        sumMax = 0; sumMin = m+1;
        for (int i = 0; i < m; i++) {
            sum = 0;
            for (int j = 0; j < m; j++) {
                sum = sum + v[i][j];
            }
            if (sumMax < sum)
                sumMax = sum;
            if (sumMin > sum)
                sumMin = sum;
        }
        System.out.println("Minimum degree of vertex: " + minDegreeSymbol + "(G) = " + sumMin);
        System.out.println("Maximum degree of vertex: " + maxDegreeSymbol + "(G) = " + sumMax);

        //regular graph
        if (sumMax == sumMin)
            System.out.println("This is a regular graph.");
        else System.out.println("This is not a regular graph.");

        //degree sum eguals 2*m
        if (edges == 2*m)
            System.out.println("Sum of degrees equals the value 2*m.");
        else System.out.println("Sum of degrees does not equals the value 2*m.");

        //cycle graph
        System.out.println();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                v[i][j]=0;
        for (int i = 0; i < m-1; i++)
            v[i][i+1] = 1;
        v[m-1][0] = 1;
        if (m < 30_000) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++)
                    System.out.print(v[i][j]);
                System.out.println();
            }
            System.out.println();
        }

        //edges cycle graph
        edges = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++)
                edges = edges + v[i][j];
        }
        System.out.println("Number of edges in the cyclic graph: " + edges);

        //vertex degree
        sumMax = 0; sumMin = m+1;
        for (int i = 0; i < m; i++) {
            sum = 0;
            for (int j = 0; j < m; j++) {
                sum = sum + v[i][j];
            }
            if (sumMax < sum)
                sumMax = sum;
            if (sumMin > sum)
                sumMin = sum;
        }
        System.out.println("Minimum degree of vertex: " + minDegreeSymbol + "(G) = " + sumMin);
        System.out.println("Maximum degree of vertex: " + maxDegreeSymbol + "(G) = " + sumMax);

        //regular graph
        if (sumMax == sumMin)
            System.out.println("This is a regular graph.");
        else System.out.println("This is not a regular graph.");

        //degree sum eguals 2*m
        if (edges == 2*m)
            System.out.println("Sum of degrees equals the value 2*m.");
        else System.out.println("Sum of degrees does not equals the value 2*m.");

        //random graph
        System.out.println();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                v[i][j]=0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++)
                if (i != j)
                    v[i][j] = ((int) (Math.random() * 1_000_000)) % 2;
            }
        if (m < 30_000) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++)
                    System.out.print(v[i][j]);
                System.out.println();
            }
            System.out.println();
        }
        //edges random graph
        edges = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++)
                edges = edges + v[i][j];
        }
        System.out.println("Number of edges in the random graph: " + edges);

        //vertex degree
        sumMax = 0; sumMin = m+1;
        for (int i = 0; i < m; i++) {
            sum = 0;
            for (int j = 0; j < m; j++) {
                sum = sum + v[i][j];
            }
            if (sumMax < sum)
                sumMax = sum;
            if (sumMin > sum)
                sumMin = sum;
        }
        System.out.println("Minimum degree of vertex: " + minDegreeSymbol + "(G) = " + sumMin);
        System.out.println("Maximum degree of vertex: " + maxDegreeSymbol + "(G) = " + sumMax);

        //regular graph
        if (sumMax == sumMin)
            System.out.println("This is a regular graph.");
        else System.out.println("This is not a regular graph.");

        //degree sum eguals 2*m
        if (edges == 2*m)
            System.out.println("Sum of degrees equals the value 2*m.");
        else System.out.println("Sum of degrees does not equals the value 2*m.");

        final long duration = System.nanoTime() - startTime;
        System.out.println((double)duration / 1000000000);

    }
}
