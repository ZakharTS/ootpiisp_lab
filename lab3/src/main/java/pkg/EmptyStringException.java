package pkg;

public class EmptyStringException extends Exception{
    public EmptyStringException() {
        super("String is empty.");
    }
}
