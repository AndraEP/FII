#1.1

z_test = function (alfa, population_mean, sample_mean, n, sigma)
{
  z = (sample_mean - population_mean) / (sigma / sqrt (n));

  #formulare ipoteza alternativa
  if (population_mean > sample_mean)
  {
    print ("ipoteza asimetrica la dreapta");
    val_critica_z = qnorm (1-alfa);

    #verificare ipoteza nula
    if(z > val_critica_z)
    {
      print ("ipoteza nula este respinsa");
    }
    else
    {
      print ("nu sunt suficiente dovezi pentru a respinge ipoteza nula");
    }
  }
  else if (population_mean < sample_mean)
  {
    print ("ipoteza asimetrica la stanga");
    val_critica_z = qnorm (alfa);
    
    #verificare ipoteza nula
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
    val_critica_z = qnorm ((1-alfa)/2);
    
    #verificare ipoteza nula
    if ( (abs (z)) > (abs (val_critica_z)))
    {
      print ("ipoteza nula este respinsa");
    }
    else
    {
      print ("nu sunt suficiente dovezi pentru a respinge ipoteza nula");
    }
  }
}

z_test (0.05, 810, 816, 200, 50)


#1.2

z_test = function (alfa, population_mean, sample_mean, n, sigma)
{
  z = (sample_mean - population_mean) / (sigma / sqrt (n));

  #formulare ipoteza alternativa
  if (population_mean > sample_mean)
  {
    print ("ipoteza asimetrica la dreapta");
    val_critica_z = qnorm (1-alfa);

    #verificare ipoteza nula
    if(z > val_critica_z)
    {
      print ("ipoteza nula este respinsa");
    }
    else
    {
      print ("nu sunt suficiente dovezi pentru a respinge ipoteza nula");
    }
  }
  else if (population_mean < sample_mean)
  {
    print ("ipoteza asimetrica la stanga");
    val_critica_z = qnorm (alfa);
    
    #verificare ipoteza nula
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
    val_critica_z = qnorm ((1-alfa)/2);
    
    #verificare ipoteza nula
    if ( (abs (z)) > (abs (val_critica_z)))
    {
      print ("ipoteza nula este respinsa");
    }
    else
    {
      print ("nu sunt suficiente dovezi pentru a respinge ipoteza nula");
    }
  }
}

z_test (0.05, 90, 88, 49, sqrt (144))


#1.3

z_test = function (alfa, population_mean, sample_mean, n, sigma)
{
  z = (sample_mean - population_mean) / (sigma / sqrt (n));
  
  #formulare ipoteza alternativa
  if (population_mean > sample_mean)
  {
    print ("ipoteza asimetrica la dreapta");
    val_critica_z = qnorm (1-alfa);
    
    #verificare ipoteza nula
    if(z > val_critica_z)
    {
      print ("ipoteza nula este respinsa");
    }
    else
    {
      print ("nu sunt suficiente dovezi pentru a respinge ipoteza nula");
    }
  }
  else if (population_mean < sample_mean)
  {
    print ("ipoteza asimetrica la stanga");
    val_critica_z = qnorm (alfa);
    
    #verificare ipoteza nula
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
    val_critica_z = qnorm ((1-alfa)/2);
    
    #verificare ipoteza nula
    if ( (abs (z)) > (abs (val_critica_z)))
    {
      print ("ipoteza nula este respinsa");
    }
    else
    {
      print ("nu sunt suficiente dovezi pentru a respinge ipoteza nula");
    }
  }
}

z_test (0.01, 75, 85, 36, 17)


#2.1

t_test  =  function  (alfa, population_mean, sample)
{
  media_sample = mean (sample);
  n = length (sample);
  s = sd (sample);
  se = s / sqrt (n);
  t = (media_sample - population_mean) / se;

  #formulare ipoteza alternativa
  if (population_mean > media_sample)
  {
    print ("ipoteza asimetrica la dreapta");
    val_critica_t = qt (1 - alfa, n - 1);
    if (t > val_critica_t)
    {
      print ("ipoteza nula este respinsa");
    }
    else
    {
      print ("nu sunt suficiente dovezi pentru a respinge ipoteza nula");
    }
  }

  else if (population_mean < media_sample)
  {
    print ("ipoteza asimetrica la stanga");
    val_critica_t = qt (alfa, n - 1);
    if (t < val_critica_t)
    {
      print ("ipoteza nula este respinsa");
    }
    else
    {
      print ("nu sunt suficiente dovezi pentru a respinge ipoteza nula")
    }
  }

  else
  {
    print ("ipoteza simetrica");
    val_critica_t = qt ( (1-alfa) / 2, n - 1);
    if ( (abs (t)) > (abs (val_critica_t)))
    {
      print ("ipoteza nula este respinsa");
    }
    else
    {
      print ("nu sunt suficiente dovezi pentru a respinge ipoteza nula")
    }
  }
}

t_test_file  =  function  (alfa, population_mean, file)
{
  sample = scan (file);
  media_sample = mean (sample);
  n = length (sample);
  s = sd (sample);
  se = s / sqrt (n);
  t = (media_sample - population_mean) / se;

  #formulare ipoteza alternativa
  if (population_mean > media_sample)
  {
    print ("ipoteza asimetrica la dreapta");
    val_critica_t = qt (1 - alfa, n - 1);
    if (t > val_critica_t)
    {
      print ("ipoteza nula este respinsa");
    }
    else
    {
      print ("nu sunt suficiente dovezi pentru a respinge ipoteza nula");
    }
  }

  else if (population_mean < media_sample)
  {
    print ("ipoteza asimetrica la stanga");
    val_critica_t = qt (alfa, n - 1);
    if (t < val_critica_t)
    {
      print ("ipoteza nula este respinsa");
    }
    else
    {
      print ("nu sunt suficiente dovezi pentru a respinge ipoteza nula")
    }
  }

  else
  {
    print ("ipoteza simetrica");
    val_critica_t = qt ( (1-alfa) / 2, n - 1);
    if ( (abs (t)) > (abs (val_critica_t)))
    {
      print ("ipoteza nula este respinsa");
    }
    else
    {
      print ("nu sunt suficiente dovezi pentru a respinge ipoteza nula")
    }
  }
}

x = c (55.95, 68.24, 52.73, 21.5, 23.78);
t_test (0.05, 40, x)


#2.2

t_test = function (alfa, population_mean, sample)
{
  media_sample = mean (sample);
  n = length (sample);
  s = sd (sample);
  se = s / sqrt (n);
  t = (media_sample - population_mean) / se;

  #formulare ipoteza alternativa
  if (population_mean > media_sample)
  {
    print ("ipoteza asimetrica la dreapta");
    val_critica_t = qt (1 - alfa, n - 1);
    if (t > val_critica_t)
    {
      print ("ipoteza nula este respinsa");
    }
    else
    {
      print ("nu sunt suficiente dovezi pentru a respinge ipoteza nula");
    }
  }

  else if (population_mean < media_sample)
  {
    print ("ipoteza asimetrica la stanga");
    val_critica_t = qt (alfa, n - 1);
    if (t < val_critica_t)
    {
      print ("ipoteza nula este respinsa");
    }
    else
    {
      print ("nu sunt suficiente dovezi pentru a respinge ipoteza nula")
    }
  }

  else
  {
    print ("ipoteza simetrica");
    val_critica_t = qt ( (1-alfa) / 2, n - 1);
    if ( (abs (t)) > (abs (val_critica_t)))
    {
      print ("ipoteza nula este respinsa");
    }
    else
    {
      print ("nu sunt suficiente dovezi pentru a respinge ipoteza nula")
    }
  }
}

x = c (36, 32, 28, 33, 41, 28, 31, 26, 29, 34);
t_test (0.01, 34, x)


#2.4

t_test_file = function (alfa, population_mean, file)
{
  sample = scan (file);
  media_sample = mean (sample);
  n = length (sample);
  s = sd (sample);
  se = s / sqrt (n);
  t = (media_sample - population_mean) / se;

  #formulare ipoteza alternativa
  if (population_mean > media_sample)
  {
    print ("ipoteza asimetrica la dreapta");
    val_critica_t = qt (1 - alfa, n - 1);
    if (t > val_critica_t)
    {
      print ("ipoteza nula este respinsa");
    }
    else
    {
      print ("nu sunt suficiente dovezi pentru a respinge ipoteza nula");
    }
  }

  else if (population_mean < media_sample)
  {
    print ("ipoteza asimetrica la stanga");
    val_critica_t = qt (alfa, n - 1);
    if (t < val_critica_t)
    {
      print ("ipoteza nula este respinsa");
    }
    else
    {
      print ("nu sunt suficiente dovezi pentru a respinge ipoteza nula")
    }
  }

  else
  {
    print ("ipoteza simetrica");
    val_critica_t = qt ( (1-alfa) / 2, n - 1);
    if ( (abs (t)) > (abs (val_critica_t)))
    {
      print ("ipoteza nula este respinsa");
    }
    else
    {
      print ("nu sunt suficiente dovezi pentru a respinge ipoteza nula")
    }
  }
}

t_test_file (0.01, 80, "history.txt")
t_test_file (0.05, 80, "history.txt")


#3.1

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

z_test_means (0.05, 0, 48, 47, 100, 100, 4, 3)


#3.2

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

z_test_means (0.01, 0, 160, 155, 80, 70, 3.24, 2.25)


#3.3

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

z_test_means (0.01, 0, 22.8, 23.3, 100, 100, 1.3, 1.9)


#4.1

F_test = function (alfa)
{
  print ("ipoteza simetrica; test two-tailed");

  #x1 = read.table ("program.txt", header = TRUE)[['A']];
  #x2 = read.table ("program.txt", header = TRUE)[['B']];
  n1 = 120;
  n2 = 135;
  s1 = 5.05;
  s2 = 5.44;

  F_score = s1 ^ 2 / s2 ^ 2;
  critical_F_s = qf (alfa / 2, n1 - 1, n2 - 1);
  critical_F_d = qf (1 - alfa / 2, n1 - 1, n2 - 1);
  print (F_score);
  print (critical_F_s);
  print (critical_F_d);

  if (F_score < critical_F_s | F_score > critical_F_d)
  {
    print ("ipoteza nula este respinsa");
  }
  else
  {
    print ("nu exista suficiente dovezi pentru a respinge ipoteza");
  }
}

F_test (0.01)


#4.2

F_test = function (alfa)
{
  print ("ipoteza simetrica; test two-tailed");

  x1 = read.table ("program.txt", header = TRUE)[['A']];
  x2 = read.table ("program.txt", header = TRUE)[['B']];
  n1 = length (x1);
  n2 = length (x2);
  s1 = sd (x1);
  s2 = sd (x2);

  F_score = s1 ^ 2 / s2 ^ 2;
  critical_F_s = qf (alfa / 2, n1 - 1, n2 - 1);
  critical_F_d = qf (1 - alfa / 2, n1 - 1, n2 - 1);
  print (F_score);
  print (critical_F_s);
  print (critical_F_d);

  if (F_score < critical_F_s | F_score > critical_F_d)
  {
    print ("ipoteza nula este respinsa");
  }
  else
  {
    print ("nu exista suficiente dovezi pentru a respinge ipoteza");
  }
}

F_test (0.01)
F_test (0.05)


#4.3

F_test = function (alfa)
{
  print ("ipoteza simetrica; test two-tailed");

  x1 = c (12.512, 12.869, 19.098, 15.350, 13.297, 15.589);
  x2 = c (11.074, 9.686, 12.164, 8.351, 12.182, 11.489);
  n1 = length (x1);
  n2 = length (x2);
  s1 = sd (x1);
  s2 = sd (x2);

  F_score = s1 ^ 2 / s2 ^ 2;
  critical_F_s = qf (alfa / 2, n1 - 1, n2 - 1);
  critical_F_d = qf (1 - alfa / 2, n1 - 1, n2 - 1);
  print (F_score);
  print (critical_F_s);
  print (critical_F_d);

  if (F_score < critical_F_s | F_score > critical_F_d)
  {
    print ("ipoteza nula este respinsa");
  }
  else
  {
    print ("nu exista suficiente dovezi pentru a respinge ipoteza");
  }
}

F_test (0.05)


#5.1

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

T_test_means (0.01, 25.84, 21.53, 110, 105, 4.25, 3.85)


#5.2

T_test_means = function (alfa)
{
  m0 = 0;
  x1 = read.table ("program.txt", header = T)[['A']];
  x2 = read.table ("program.txt", header = T)[['B']];
  media_sample1 = mean (x1);
  n1 = length (x1);
  s1 = sd (x1);
  media_sample2 = mean (x2);
  n2 = length (x2);
  s2 = sd (x2);

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

T_test_means(0.01)
T_test_means(0.05)


#5.3

T_test_means = function (alfa)
{
  m0 = 0;
  x1 = c (12.512, 12.869, 19.098, 15.350, 13.297, 15.589);
  x2 = c (11.074, 9.686, 12.164, 8.351, 12.182, 11.489);
  media_sample1 = mean (x1);
  n1 = length (x1);
  s1 = sd (x1);
  media_sample2 = mean (x2);
  n2 = length (x2);
  s2 = sd (x2);

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

T_test_means(0.01)
