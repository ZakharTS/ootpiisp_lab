package org.example;

import java.util.HashSet;

/*
1. Создать шаблон заданного класса. Определить конструкторы, деструктор и операции, заданные в варианте задания.
2. Написать программу тестирования, в которой проверяется использование шаблона для стандартных типов данных.
3. Выполнить тестирование.
4. Определить пользовательский класс, который будет использоваться в качестве параметра шаблона.
Определить в классе необходимые функции и перегруженные операции.
5. Написать программу тестирования, в которой проверяется использование шаблона для пользовательского типа.
6. Выполнить тестирование.
*/
public class Main {
    public static void main(String[] args) {
        CustomSet<Integer> set = new CustomSet<Integer>() ;
        //{12, 33, 45, 9, 25, 37}
        set.addElement(12);
        set.addElement(33);
        set.addElement(45);
        set.addElement(9);
        set.addElement(25);
        set.addElement(37);

        CustomSet<Integer> set1 = new CustomSet<>();
        set1.addElement(33);
        set1.addElement(32);
        set1.addElement(48);
        set1.addElement(9);

        System.out.println(set.intersection(set1)); // пересечение двух множеств
        System.out.println(set.power()); // можность множества

        CustomSet<City> citySet = new CustomSet<City>(); // множество пользовательского класса
        citySet.addElement(new City("Brest", 300000));
        citySet.addElement(new City("Minsk", 2000000));
        citySet.addElement(new City("Pinsk", 100000));
        System.out.println(citySet);
    }
}