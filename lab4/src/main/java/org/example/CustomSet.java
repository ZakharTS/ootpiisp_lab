package org.example;

import java.util.HashSet;

/* добавить элемент в множество;
   пересечение множеств;
   мощность множества. */

public class CustomSet<T> extends HashSet<T> {
    public CustomSet () {
        super();
    }
    public CustomSet (CustomSet<T> customSet) {
        super(customSet);
    }


    public void addElement (T toAdd) {
        this.add(toAdd);
    }
    public CustomSet<T> intersection(CustomSet<T> second) {
        CustomSet<T> result = new CustomSet<>();
        for (T itr : this) {
            if (second.contains(itr)) {
                result.add(itr);
            }
        }
        return result;
    }
    public int power() {
        return this.size();
    }
}
