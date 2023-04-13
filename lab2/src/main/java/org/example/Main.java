package org.example;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        Place.list = new ArrayList<>();
        new District("Brestskaya", 3000);
        new City("Brest", 300000);
        new Megapolis("Minsk", 2000000);
        Place.displayList();
    }
}
abstract class Place {
    protected String name;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public static List<Place> getList() {
        return list;
    }

    public static void setList(List<Place> list) {
        Place.list = list;
    }

    public Place() {
        this.name = "default";
    }
    public Place(String name) {
        this.name = name;
    }
    public static List<Place> list;
    public static void displayList() {
        for (var cur : list) {
            cur.show();
        }
    }
    public abstract void show();
    public abstract void add();
}
class District extends Place {
    protected int budget;
    public int getBudget() {
        return budget;
    }
    public void setBudget(int budget) {
        this.budget = budget;
    }
    public District() {
        super();
        this.budget = 0;
        this.add();
    }
    public District(String name, int budget) {
        super(name);
        this.budget = budget;
        this.add();
    }
    @Override
    public void show() {
        System.out.println("District " + name + ", budget: " + Integer.toString(budget));
    }
    @Override
    public void add() {
        Place.list.add(this);
    }
}
class City extends Place {
    int population;
    public int getPopulation() {
        return population;
    }
    public void setPopulation(int population) {
        this.population = population;
    }
    public City() {
        super();
        this.population = 0;
        this.add();
    }

    public City(String name, int population) {
        super(name);
        this.population = population;
        this.add();
    }
    @Override
    public void show() {
        System.out.println("City " + name + ", population: " + Integer.toString(population));
    }
    @Override
    public void add() {
        Place.list.add(this);
    }
}
class Megapolis extends City {
    public Megapolis() {
        super();
    }
    public Megapolis(String name, int population) {
        super(name, population);
    }
    @Override
    public void show() {
        System.out.println("Megapolis " + name + ", population: " + Integer.toString(population));
    }
}