public class Condominio
{
	double valor;
	String nome;

	public Condominio()
	{
		valor=0.0;
		nome="";
	}

	public Condominio(double vl, String nm)
	{
		valor=vl;
		nome=nm;
	}

	void setNome(String nme)
	{
		nome=nme;
	}

	void setValor(double vlue)
	{
		valor=vlue;
	}
	
	double getValor()
	{
		return valor;
	}
	
	String getNome()
	{
		return nome;
	}
}		
