package ufrn.laed2.arvores.excessoes;
public class ElementAlreadyExistException extends Exception
{
    public ElementAlreadyExistException()
    {  
        super("O elemento já existe");
    }
}
