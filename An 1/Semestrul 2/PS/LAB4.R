############################################## I.1

sfera_area = function(N)
{
  M_C = 0;
  for(i in 1:N)
  {
    x = runif(1, -1, 1);
    y = runif(1, -1, 1);
    z = runif(1, -1, 1);
    if(x*x + y*y + z*z <= 1)
      M_C = M_C + 1;
  }
  return(8*M_C/N);
}

erori_calc = function(value_MC,value_actual)
{
  eroare_abs=abs(value_MC-value_actual);
  eroare_rel=abs(eroare_abs/value_actual);
  print(value_MC);
  print(value_actual);
  print(eroare_abs);
  print(eroare_rel);
}

pi = 3.14159265358;
volum_sferei_unitate = 4 * pi / 3; 

erori_calc(sfera_area(50000),volum_sferei_unitate)

############################################## I.2

elipse_area = function(N)
{
  M_C = 0
  for(i in 1:N)
  {
    x=runif(1,-2,2);
    y=runif(1,-1,1);
    if(x*x+4*y*y<=4)
      M_C = M_C+1;
  }
  return (8*M_C/N);
}

erori_calc = function(value_MC,value_actual)
{
  eroare_abs=abs(value_MC-value_actual);
  eroare_rel=abs(eroare_abs/value_actual);
  eroare_procent=eroare_rel*100;
  print(value_MC);
  print(value_actual);
  print(eroare_abs);
  print(eroare_rel);
  print(eroare_procent);
}

aria_eclipsa = 2*3.1415;

erori_calc(elipse_area(50000),aria_eclipsa)

############################################## I.3

parabola_area = function (N)
{
  N_C = 0;
  for (i in 1:N)
  {
    x = runif (1, -1, 3);
    y = runif (1, 0, 4);
    if (y <= -(x*x) + 2*x + 3)
      N_C = N_C + 1;
  }
  return (16 * N_C / N);
}

erori_calc = function(value_MC,value_actual)
{
  eroare_abs=abs(value_MC-value_actual);
  eroare_rel=abs(eroare_abs/value_actual);
  print(value_MC);
  print(value_actual);
  print(eroare_rel);
}

integrate = function (x)
{
  return (-(x*x*x)/3 + x*x + 3*x); #integrated equation on paper first
}

actual_area = function()
{
  return (integrate (3) - integrate (-1));
}

erori_calc (parabola_area (50000), actual_area());

############################################## II.1

#a

II_1_a = function(N)
{
  sum = 0;
  for(i in 1:N)
  {
    u = runif(1,0,pi);
    c = cos(u);
    sum = sum + c*c;
  }
  return (pi * sum / N);
}

erori_calc = function(value_MC,value_actual)
{
  eroare_abs=abs(value_MC-value_actual);
  eroare_rel=abs(eroare_abs/value_actual);
  print(value_MC);
  print(value_actual);
  print(eroare_abs);
  print(eroare_rel);
}

resultat_actual=3.1415/2;
erori_calc (II_1_a (50000), resultat_actual);

#c

II_1_c = function(N)
{
  sum = 0;
  for(i in 1:N)
  {
    u = runif(1,0,3);
    sum = sum + exp(u);
  }
  return (3 * sum / N);
}

erori_calc = function(value_MC,value_actual)
{
  eroare_abs=abs(value_MC-value_actual);
  eroare_rel=abs(eroare_abs/value_actual);
  print(value_MC);
  print(value_actual);
  print(eroare_rel);
}

erori_calc (II_1_b (50000), 19.08554);

############################################## II.2

#a

II_2_a = function(N)
{
  sum = 0;
  for(i in 1:N)
  {
    u = runif(1,0,100);
    sum = sum + 1 / (u*u + 1);
  }
  return (100 * sum / N);
}

erori_calc = function(value_MC,value_actual)
{
  eroare_abs=abs(value_MC-value_actual);
  eroare_rel=abs(eroare_abs/value_actual);
  print(value_MC);
  print(value_actual);
  print(eroare_abs);
  print(eroare_rel);
}

resultat_actual=3.1415/2;
erori_calc (II_2_a (50000), resultat_actual);

#b

II_2_b = function(N)
{
  sum = 0;
  for(i in 1:N)
  {
    u = runif(1,2,100);
    sum = sum + 1 / (u*u - 1);
  }
  return (100*sum / N);
}

erori_calc = function(value_MC,value_actual)
{
  eroare_abs=abs(value_MC-value_actual);
  eroare_rel=abs(eroare_abs/value_actual);
  print(value_MC);
  print(value_actual);
  print(eroare_abs);
  print(eroare_rel);
}

actual_result = function()
{
  return (log (2) / 2); #enuntul e gresit, nu asta e rezultatul
}

erori_calc (II_2_b (50000), actual_result());

############################################## II.3

Integrala_improved = function (N)
{
  sum = 0;
  for (i in 1:N)
  {
    u = rexp (1, 1);
    sum = sum + exp (-(u * u) / 2) / exp (-u);
  }
  return (sum / N);
}

Integrala_improved_average = function (k, N)
{
  estimates = vector();
  for (i in 1:k)
  {
    estimates[i] = Integrala_improved (N);
  }
  print (mean (estimates));
  print (sd (estimates));
  return (mean (estimates));
}

erori_calc = function(value_MC,value_actual)
{
  eroare_abs=abs(value_MC-value_actual);
  eroare_rel=abs(eroare_abs/value_actual);
  print(value_MC);
  print(value_actual);
  print(eroare_abs);
  print(eroare_rel);
}

actual_result = function()
{
  return (sqrt (pi / 2));
}

erori_calc (Integrala_improved_average (30, 40000), actual_result());

############################################## III.1

Nr_zile = function()
{
  nr_zile = 1;
  last_errors = c(11, 16, 18);
  nr_errors = 11;
  while(nr_errors > 0)
  {
    lambda = sum(last_errors)/3;
    nr_errors = rpois(1, lambda);
    last_errors = c(nr_errors, last_errors[1], last_errors[2]) ;
    nr_zile = nr_zile + 1;
  }
  return(nr_zile);
}

MC_nr_zile = function(N)
{
  s = 0;
  for(i in 1:N)
    s = s + Nr_zile();
  return (s/N);
}

print (MC_nr_zile(10000));

############################################## III.2

Numar_ore = function()
{
  u = runif (1, 0, 1);
  x = rexp (1, 20);
  y = rexp (1, 5);
  if (u >= 0.8)
  {
    return (x);
  }
  else
  {
    return (y);
  }
}

MC_Numar_ore = function (N)
{
  s = 0;
  for (i in 1:N)
  {
    s = s + Numar_ore();
  }
  return (s / N);
}

print (MC_Numar_ore (10000));

############################################## IV.1

generate = function()
{
  x = rpois (1, 3);
  y = rpois (1, 5);
  return (x > y);
}

MC_generate = function (N)
{
  apx = 0;
  for (i in 1:N)
  {
    if (generate() > 0)
    {
      apx = apx + 1;
    }
  }
  return (apx / N);
}

N_min = function()
{
  alfa = 1 - 0.95;
  z = qnorm (alfa / 2);
  epsilon = 0.01;
  p = 0.185;
  return (p * (1 - p) * ((z / epsilon) ^ 2));
}

print (N_min());
print (MC_generate (N_min() + 1));

############################################## IV.2

simulate_a = function()
{
  infectate = vector (, 20);
  first = sample (1:20, 1);
  infectate[first] = 1;
  contor = 1;
  nr_zile = 1;
  while (contor != 0)
  {
    if (contor > 0)
    {
      for (j in 1:contor)
      {
        for (i in 1:20)
        {
          if (infectate[i] == 0)
          {
            u = runif (1, 0, 1);
            if (u <= 0.1)
            {
              infectate[i] = 1;
              contor = contor + 1;
            }
          }
        }
      }
    }
    if (contor == 20) return (1);
    if (contor > 0)
    {
      u = sample (1:20, 1);
      while (infectate[u] == 0) u = sample (1:20, 1);
      infectate[u] = 0; contor = contor - 1;
    }
    if (contor > 0)
    {
      u = sample (1:20, 1);
      while (infectate[u] == 0) u = sample (1:20, 1);
      infectate[u] = 0; contor = contor - 1;
    }
    nr_zile = nr_zile + 1;
  }
  return (0);
}

IV_2_a = function (N)
{
  occ = 0;
  for (i in 1:N)
  {
    if (simulate_a() > 0)
    {
      occ = occ + 1;
    }
  }
  return (occ / N);
}



simulate_b = function()
{
  infectate = vector (, 20);
  first = sample (1:20, 1);
  infectate[first] = 1;
  contor = 1;
  nr_zile = 1;
  while (contor != 0)
  {
    if (contor > 0)
    {
      for (j in 1:contor)
      {
        for (i in 1:20)
        {
          if (infectate[i] == 0)
          {
            u = runif (1, 0, 1);
            if (u <= 0.1)
            {
              infectate[i] = 1;
              contor = contor + 1;
            }
          }
        }
      }
    }
    if (contor >= 8) return (1);
    if (contor > 0)
    {
      u = sample (1:20, 1);
      while (infectate[u] == 0) u = sample (1:20, 1);
      infectate[u] = 0; contor = contor - 1;
    }
    if (contor > 0)
    {
      u = sample (1:20, 1);
      while (infectate[u] == 0) u = sample (1:20, 1);
      infectate[u] = 0; contor = contor - 1;
    }
    nr_zile = nr_zile + 1;
  }
  return (0);
}

IV_2_b = function (N)
{
  occ = 0;
  for (i in 1:N)
  {
    if (simulate_b() > 0)
    {
      occ = occ + 1;
    }
  }
  return (occ / N);
}



simulate_c = function()
{
  infectate = vector (, 20);
  first = sample (1:20, 1);
  infectate[first] = 1;
  contor = 1;
  nr_zile = 1;
  while (contor != 0)
  {
    if (contor > 0)
    {
      for (j in 1:contor)
      {
        for (i in 1:20)
        {
          if (infectate[i] == 0)
          {
            u = runif (1, 0, 1);
            if (u <= 0.1)
            {
              infectate[i] = 1;
              contor = contor + 1;
            }
          }
        }
      }
    }
    if (contor >= 8) return (1);
    if (contor > 0)
    {
      u = sample (1:20, 1);
      while (infectate[u] == 0) u = sample (1:20, 1);
      infectate[u] = 0; contor = contor - 1;
    }
    if (contor > 0)
    {
      u = sample (1:20, 1);
      while (infectate[u] == 0) u = sample (1:20, 1);
      infectate[u] = 0; contor = contor - 1;
    }
    nr_zile = nr_zile + 1;
  }
  return (0);
}

IV_2_c = function (N)
{
  occ = 0;
  for (i in 1:N)
  {
    if (simulate_c() > 0)
    {
      occ = occ + 1;
    }
  }
  return (occ / N);
}

Nr_min_c = function()
{
  alfa = 1 - 0.95;
  z = qnorm (alfa / 2);
  epsilon = 0.01;
  p = 0.38;
  return (p * (1 - p) * ((z / epsilon) ^ 2));
}



print (IV_2_a (1000));
print (IV_2_b (1000));
print (Nr_min_c());
print (IV_2_c (Nr_min_c() + 1));
