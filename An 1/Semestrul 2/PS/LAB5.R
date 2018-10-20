#1.1

# dispersia = sigma
# media = micro
# valoarea critica = Z*
# nivelul de incredere = alfa

# Scrieti o functie care sa reprezinte grafic densitatea legii normale
# N(micro,sigma^2)
# N(0,1) = normala standard.

normal_density = function (limit, miu, sigmap)
{
  t = seq (-limit, limit, length = 400);
  f = (1/(sqrt(sigmap)*sqrt(2*pi)))*exp(-((t-miu)^2/(2*sigmap)));
  plot (t, f, type = "l", lwd = 1);
}

normal_density (6, 0, 1)


#2.1

selection_mean = function (filename)
{
  x = scan (filename);
  m = mean (x);
  print (m);
}

selection_mean ("history.txt")


#3.1

zconfidence_interval = function (n, sample_mean, alfa, sigmap)
{
  critical_z = qnorm (1 - alfa/2, mean = 0, sd = 1);
  a = sample_mean - critical_z*(sqrt(sigmap)/sqrt(n));
  b = sample_mean + critical_z*(sqrt(sigmap)/sqrt(n));
  interval = c (a, b);
  print (interval);
}

zconfidence_interval (100, 20, 0.1, 9)


#3.2

zconfidence_interval(0.1, 67.53, 25, 100)


#3.4

zconfidence_interval(0.01, 1280, 100, 140^2)


#4.1

t_conf_interval = function (n, sample_mean, alfa, s)
{
  critical_t = qt (1 - alfa/2, n - 1);
  a = sample_mean - critical_t*(s/sqrt(n));
  b = sample_mean + critical_t*(s/sqrt(n));
  interval = c (a, b);
  print (interval);
}

t_conf_interval (60, 3.3, 0.05, 0.4)


#4.2

t_conf_interval (196, 44.65, 0.01, sqrt (2.25))


#4.5

date_esantion = c (12, 11, 12, 10, 11, 12, 13, 12, 11, 11, 13, 14, 10);
t_conf_interval (length (date_esantion), mean (date_esantion), 0.1, sd (date_esantion))
t_conf_interval (length (date_esantion), mean (date_esantion), 0.05, sd (date_esantion))
t_conf_interval (length (date_esantion), mean (date_esantion), 0.01, sd (date_esantion))


#5.1

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

test_proportion (0.01, 100, 63, 0.6)


#5.2

test_proportion (0.05, 150, 20, 0.1)


#5.3

test_proportion (0.01, 42, 17, 0.25)
