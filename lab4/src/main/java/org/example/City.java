package org.example;

public class City {
    String name;
    int population;
    public int getPopulation() {
        return population;
    }
    public void setPopulation(int population) {
        this.population = population;
    }
    public City() {
        this.name = "default";
        this.population = 0;
    }

    public City(String name, int population) {
        this.name = name;
        this.population = population;
    }

    public String toString() {
        return ("City " + name + " population=" + Integer.toString(population));
    }

}