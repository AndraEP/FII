#E1

t_test = function (alfa, media_populatie, sample)
{
  media_sample = mean (sample);
  n = length (sample);
  s = sd (sample);
  se = s / sqrt (n);
  t = (media_sample - media_populatie) / se;


if (media_sample > media_populatie)
  {
    print ("ipoteza asimetrica la dreapta");
    val_critica_t = qt (1 - alfa, n - 1);
    if (t > val_critica_t)
    {
      print ("ipoteza nula este respinsa");
    }
    else
    {
      print ("nu sunt suficiente doveti pentru a respinge ipoteza nula");
    }
  }
  else if (media_sample < media_populatie)
  {
    print ("ipoteza asimetrica la stanga");
    val_critica_t = qt (alfa, n - 1);
    if (t < val_critica_t)
    {
      print ("ipoteza nula este respinsa");
    }
    else
    {
      print ("nu sunt suficiente doveti pentru a respinge ipoteza nula");
    }
  }
  else 
  {
    print ("ipoteza simetrica");
    val_critica_t = qt (1 - alfa / 2, n - 1);
    if ( (abs (t)) > (abs (val_critica_t)))
    {
      print ("ipoteza este respinsa");
    }
    else
    {
      print ("nu sunt suficiente doveti pentru a respinge ipoteza nula");
    }
  }
}

x = c (1.64, 1.54, 1.56, 1.57, 1.44, 1.48, 1.56);
t_test (0.01, 1.6, x)


#E4

z_test_means = function (alfa, m0, media_sample1, media_sample2, n1, n2, sigma1, sigma2)
{
  combined_sigma = sqrt (sigma1 ^ 2 / n1 + sigma2 ^ 2 / n2);
  z = (media_sample1 - media_sample2 - m0) / combined_sigma;
  media_sample = media_sample1 - media_sample2;


  if (media_sample > m0)
  {
    print ("ipoteza asimetrica la dreapta");
    val_critica_z = qnorm (1 - alfa);
    if (z > val_critica_z)
    {
      print ("ipoteza nula este respinsa");
    }
    else
    {
      print ("nu sunt suficiente dovezi pentru a respinge ipoteza nula");
    }
  }
  else if (media_sample < m0)
  {
    print ("ipoteza asimetrica la stanga");
    val_critica_z = qnorm (alfa);
    if (z < val_critica_z)
    {
      print ("ipoteza nula este respinsa");
    }
    else
    {
      print ("nu sunt suficiente dovezi pentru a respinge ipoteza nula");
    }
  }
  else 
  {
    print ("ipoteza simetrica");
    val_critica_z = qnorm (1 - alfa / 2);
    if ( (abs (z)) > (abs (val_critica_z)))
    {
      print ("ipoteza este respinsa");
    }
    else
    {
      print ("nu sunt suficiente dovezi pentru a respinge ipoteza nula");
    }
  }
}

z_test_means (0.01, 0, 15, 14.5, 155, 150, 0.75, 0.78)


#E5

T_test_means = function (alfa, media_sample1, media_sample2, n1, n2, s1, s2)
{
  m0 = 0;
  critical_F_s =  qf (alfa / 2,  n1 - 1,  n2 - 1);
  critical_F_d =  qf (1 - alfa / 2,  n1 - 1,  n2 - 1);
  F_score  =  s1 ^ 2 / s2 ^ 2;

  if (F_score < critical_F_s | F_score > critical_F_d)
  {
    print ("dispersiile sunt diferite");
    df = min (n1 - 1,  n2 - 1);
    combined_sigma = sqrt (s1 ^ 2 / n1 + s2 ^ 2 / n2);
  }
  else
  {
    print ("dispersiile nu sunt diferite");
    df  =  n1 + n2 - 2;
    combined_sigma  =  sqrt (((n1 - 1) * s1 ^ 2 + (n2 - 1) * s2 ^ 2) / df) * sqrt (1 / n1 + 1 / n2)
  }

  media_sample = media_sample1 - media_sample2;
  val_critica_t = qt (1 - alfa / 2,  df);
  t = (media_sample - m0) / combined_sigma;

  if (media_sample > m0)
  {
    print ("ipoteza asimetrica la dreapta");
    if (t > val_critica_t)
    {
      print ("ipoteza nula este respinsa");
    }
    else
    {
      print ("nu sunt suficiente doveti pentru a respinge ipoteza nula");
    }
  }
  else if (media_sample < m0)
  {
    print ("ipoteza asimetrica la stanga");
    if (t < val_critica_t)
    {
      print ("ipoteza nula este respinsa");
    }
    else
    {
      print ("nu sunt suficiente doveti pentru a respinge ipoteza nula");
    }
  }
  else 
  {
    print ("ipoteza simetrica");
    if ( (abs (t)) > (abs (val_critica_t)))
    {
      print ("ipoteza este respinsa");
    }
    else
    {
      print ("nu sunt suficiente doveti pentru a respinge ipoteza nula");
    }
  }
  print (val_critica_t);
  print (t);
}

T_test_means (0.01, 21, 20, 66, 68, 1.2, 1.1)
