public class InvalidFileFormatException extends Exception
{
    public InvalidFileFormatException(String ext)
    {
        super("Invalid extension: " + ext);
    }
}
