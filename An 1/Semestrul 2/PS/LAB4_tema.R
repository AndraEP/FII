# C1
elipsoid_de_revolutie_volume=function(N)
{
  N_C=0;
  for(i in 1:N)
  {
    x=runif(1,-2,2);
    y=runif(1,-3,3);
    z=runif(1,-4,4);
    if((x*x/4)+(y*y/9)+(z*z/16)<=1)
      N_C=N_C+1;
  }
  return (8*6*4*N_C/N);
}

err=function(value_MC,value_actual)
{
  err_abs=abs(value_MC-value_actual);
  err_rel=err_abs/abs(value_actual);
  print(value_actual);
  print(value_MC);
  print(err_abs);
  print(err_rel);
}

volum_elipsoid_de_revolutie=3.14159265358*24*4/3;

err(elipsoid_de_revolutie_volume(50000),volum_elipsoid_de_revolutie);

# C3
#(a)

MC_integration_aC3=function(N)
{
  s=0;
  for(i in 1:N)
  {
    u=runif(1,0,1);
    si=sin(20*u);
    co=cos(50*u);
    s=s+(co+si)*(co+si);
  }
  return (s/N);
}

margin_of_error = function (MC_value, actual_value)
{
  abs_error = abs (MC_value - actual_value);
  rel_error = abs (abs_error / actual_value);
  print (MC_value);
  print (actual_value);
  print (abs_error);
  print (rel_error);
}

actual_result = function()
{
  return (0.9652); #wolfram alpha
}

margin_of_error (MC_integration (50000), actual_result());

#(b)

MC_integration_bC3=function(N)
{
  s=0;
  for(i in 1:N)
  {
    x=runif(1,0,3);
    s=s+(x^3)/(x^4+1);
  }
  return (3*s/N);
}

margin_of_error = function (MC_value, actual_value)
{
  abs_error = abs (MC_value - actual_value);
  rel_error = abs (abs_error / actual_value);
  print (MC_value);
  print (actual_value);
  print (abs_error);
  print (rel_error);
}

actual_result = function()
{
  return (1.01168); #enuntul e gresit, wolfram alpha spune 1.10
}

margin_of_error (MC_integration (50000), actual_result());

# C4

MC_retea=function(N)
{
  s=0;
  for(i in 1:N)
  {
    x=rexp(1,1);
    g1=rgamma(1,shape=5,scale=3);
    g2=rgamma(1,shape=7,scale=5);
    g3=rgamma(1,shape=5,scale=2);
    u=runif(1,0,1);
    if(u<0.5)
    {
      s=s+g1;
    }
    else
    {
      if(u>=0.8)
      {
        s=s+g3;
      }
      else
      {
        s=s+g2;
      }
    }
    s=s+x;
  }
  return (s/N);
}

print (MC_web (10000));

# C7
#a

simulate = function()
{
  infected = vector (, 20);
  viz = vector (, 20);
  first = sample (1:20, 1);
  infected[first] = 1;
  count = 1;
  nr_days = 1;
  while (count != 0)
  {
    if (count > 0)
    {
      for (j in 1:count)
      {
        for (i in 1:20)
        {
          if (infected[i] == 0)
          {
            u = runif (1, 0, 1);
            if (u <= 0.25)
            {
              infected[i] = 1;
              count = count + 1;
              viz[i] = 1;
            }
          }
        }
      }
    }
    if (sum (viz) == 20) return (1);
    for (j in 1:5)
    {
      if (count > 0)
      {
        u = sample (1:20, 1);
        while (infected[u] == 0) u = sample (1:20, 1);
        infected[u] = 0; count = count - 1;
      } 
    }
    nr_days = nr_days + 1;
  }
  return (0);
}

MC_simulate = function (N)
{
  occ = 0;
  for (i in 1:N)
  {
    if (simulate() > 0)
    {
      occ = occ + 1;
    }
  }
  return (occ / N);
}

print (MC_simulate (1000));

#b

simulate = function()
{
  infected = vector (, 20);
  viz = vector (, 20);
  first = sample (1:20, 1);
  infected[first] = 1;
  count = 1;
  nr_days = 1;
  while (count != 0)
  {
    if (count > 0)
    {
      for (j in 1:count)
      {
        for (i in 1:20)
        {
          if (infected[i] == 0)
          {
            u = runif (1, 0, 1);
            if (u <= 0.25)
            {
              infected[i] = 1;
              count = count + 1;
              viz[i] = 1;
            }
          }
        }
      }
    }
    if (count == 20) return (1);
    for (j in 1:5)
    {
      if (count > 0)
      {
        u = sample (1:20, 1);
        while (infected[u] == 0) u = sample (1:20, 1);
        infected[u] = 0; count = count - 1;
      } 
    }
    nr_days = nr_days + 1;
  }
  return (0);
}

MC_simulate = function (N)
{
  occ = 0;
  for (i in 1:N)
  {
    if (simulate() > 0)
    {
      occ = occ + 1;
    }
  }
  return (occ / N);
}

print (MC_simulate (1000));

#c

simulate = function()
{
  infected = vector (, 20);
  viz = vector (, 20);
  first = sample (1:20, 1);
  infected[first] = 1;
  count = 1;
  nr_days = 1;
  while (count != 0)
  {
    if (count > 0)
    {
      for (j in 1:count)
      {
        for (i in 1:20)
        {
          if (infected[i] == 0)
          {
            u = runif (1, 0, 1);
            if (u <= 0.25)
            {
              infected[i] = 1;
              count = count + 1;
              viz[i] = 1;
            }
          }
        }
      }
    }
    if (sum (viz) == 20) return (1);
    for (j in 1:5)
    {
      if (count > 0)
      {
        u = sample (1:20, 1);
        while (infected[u] == 0) u = sample (1:20, 1);
        infected[u] = 0; count = count - 1;
      } 
    }
    nr_days = nr_days + 1;
  }
  return (0);
}

MC_simulate = function (N)
{
  occ = 0;
  for (i in 1:N)
  {
    if (simulate() > 0)
    {
      occ = occ + 1;
    }
  }
  return (occ / N);
}

N_min = function()
{
  alfa = 1 - 0.99;
  z = qnorm (alfa / 2);
  epsilon = 0.01;
  p = 0.4; #presumed beforehand
  return (p * (1 - p) * ((z / epsilon) ^ 2));
}

print (N_min());
print (MC_simulate (N_min() + 1));
