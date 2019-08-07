package com.company;

abstract class Membru
{
    String institutie = "Facultatea de informatica";
    private String name;
    private int an;
    abstract String getType();
    String getName()
    {
        return this.name;
    }
    int getAn()
    {
        return this.an;
    }
    void setProperties(String name)
    {
        this.name = name;
    }
    void setProperties(String name, int an)
    {
        this.name = name;
        this.an = an;
    }
}

class Personal extends Membru
{
    String getType()
    {
        return "Personal";
    }
}

class PersonalAcademic extends Personal
{
    String getType()
    {
        return "Personal academic";
    }
}

class PersonalAsociat extends Personal
{
    String getType()
    {
        return "Personal asociat";
    }
}

class Profesor extends PersonalAcademic
{
    String getType()
    {
        return "Profesor";
    }
    String getType(int an)
    {
        return "Profesor in anul " + Integer.toString(an);
    }
}

class Student extends Membru
{
    String getType()
    {
        return "Student";
    }
    String getType(int an)
    {
        return "Student in anul " + Integer.toString(an);
    }
}

interface Car
{
    int numberOfWheels = 4;
    public void honk();
    public String getEngineType();

}

abstract class Dacia implements Car
{
    public void honk()
    {
        System.out.println("Beep!");
    }
}

class Sandero extends Dacia
{
    public String getEngineType()
    {
        return "4 cylinder";
    }
}

public class Main
{
    public static void main(String[] args)
    {
        Student student = new Student();
        System.out.println(student.getType());
        System.out.println(student.getType(3));
        System.out.println(student.institutie);
        student.setProperties("Cristi");
        System.out.println(student.getName());
        student.setProperties("Rares", 2);
        System.out.println(student.getName());
        System.out.println(student.getAn());
        Profesor profesor = new Profesor();
        System.out.println(profesor.getType());
        System.out.println(profesor.getType(1));
        Membru profesor_2 = new Profesor();
        profesor_2.setProperties("Radulescu");
        System.out.println(profesor_2.getName());
        //Car car_1 = new Dacia();
        //car_1.honk();
        System.out.println(Car.numberOfWheels);
        Car car_2 = new Sandero();
        car_2.honk();
        System.out.println(car_2.getEngineType());
    }

}
