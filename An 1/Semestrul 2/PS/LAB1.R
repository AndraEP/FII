//ex1
Ex1 = function (file)
{
  b = scan (file);
  max = b[1];
  min = b[1];
  sum = 0;
  l40 = 0;
  l35 = 0;
  for (i in 1 : length (b))
  {
    if (b[i] > max) max = b[i];
    if (b[i] < min) min = b[i];
    sum = sum + b[i];
    if (b[i] > 40) l40 = l40 + 1;
    if (b[i] < 35) l35 = l35 + 1;
  }
  print (max);
  print (min);
  print (sum);
  print (l40);
  print (l35 / length (b) * 100);
}

//ex2
Ex2 = function (file)
{
  x = scan (file);
  v1 = vector();
  v2 = vector();
  for (i in 1 : length (x))
  {
    v1[i] = log (x[i]);
    v2[i] = (x[i] - max (x)) / min (x);
  }
  print (v1);
  print (v2);
}

//ex3
Ex3 = function (file)
{
  v = scan (n = 3);
  write (v, "vector.txt", , ,"\n");
}

//ex4
Ex4 = function (n, p)
{
  x = seq (0, n, 1);
  y = dbinom (x, n, p);
  barplot (y, space = 0, main = "Distributie Binomiala", sub = "Exercitiul 4", xlab = "Axa X", ylab = "Axa Y");
}

//ex5
Ex5 = function (n, p)
{
  x = seq (0, n, 1);
  y = dbinom (x, n, p);
  z = max (y);
  print (z);
}

//ex6
Ex6 = function (n, lambda)
{
  x = seq (0, n, 1);
  y = dpois (x, lambda);
  print (y);
}

//ex7
Ex7 = function ()
{
  y = read.table ("test.txt", header = TRUE);
  x1 = y [["AA"]];
  x2 = y [["BB"]];
  plot (x1, x2);
}
