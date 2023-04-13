package pkg;

public class Main {
    public static double stringToDouble(String inputString) throws EmptyStringException,
            NotANumberException, NegativeNumberException {
        if (inputString.isEmpty()) {
            throw new EmptyStringException();
        }
        double result = 0;
        try {
            result = Double.parseDouble(inputString);
        } catch (NumberFormatException e) {
            throw new NotANumberException();
        }
        if (result < 0) {
            throw new NegativeNumberException();
        }
        return result;
    }

    public static void getType(double cur) throws DoubleException {
        throw new DoubleException();
    }

    public static void getType(int cur) throws IntegerException {
        throw new IntegerException();
    }



    public static void main(String[] args) {
        // 1
        try {
            double db = stringToDouble("-10");
            System.out.println(db);
        } catch (Exception e) {
            e.printStackTrace();
        }

        // 2
        boolean isInt = true;
        int a = 0;
        double b = 0;
        try {
            getType(b);
        } catch (DoubleException e) {
            e.printStackTrace();
        } catch (IntegerException e) {
            e.printStackTrace();
        }
    }


}

class DoubleException extends Exception {
    public DoubleException() {
        super("Double.");
    }
}

class IntegerException extends Exception {
    public IntegerException() {
        super("Integer.");
    }
}