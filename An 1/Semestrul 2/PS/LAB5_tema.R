#D2

t_conf_interval = function (n, sample_mean, alfa, s)
{
  critical_t = qt (1 - alfa/2, n - 1);
  a = sample_mean - critical_t*(s/sqrt(n));
  b = sample_mean + critical_t*(s/sqrt(n));
  interval = c (a, b);
  print (interval);
}

t_conf_interval (144, 20, 0.1, sqrt(18))


#D3

test_proportion = function (alfa, n, succese, p0)
{
  p_prim = succese / n;
  z = (p_prim - p0) / sqrt (p0 * (1 - p0) / n);
  print (z);
  if (p_prim > p0)
  {
    critical_z = qnorm (1 - alfa, 0, 1);
    print (critical_z);
    print ("asimetrica la dreapta");
    if (z > critical_z)
    {
      print ("ipoteza nula respinsa");
    }
    else
    {
      print ("nu exista suficiente dovezi");
    }
  }
  if (p_prim < p0)
  {
    critical_z = qnorm (alfa, 0, 1);
    print (critical_z);
    print ("asimetrica la stanga");
    if (z < critical_z)
    {
      print ("ipoteza nula respinsa");
    }
    else
    {
      print ("nu exista suficiente dovezi");
    }
  }
  if (p_prim == p0)
  {
    critical_z = qnorm (1 - alfa/2, 0, 1);
    print (critical_z);
    print ("simetrica");
    if (abs (z) > abs (critical_z))
    {
      print ("ipoteza nula respinsa");
    }
    else
    {
      print ("nu exista suficiente dovezi");
    }
  }
}

test_proportion (0.01, 112, 14, 0.1)
test_proportion (0.05, 112, 14, 0.1)
