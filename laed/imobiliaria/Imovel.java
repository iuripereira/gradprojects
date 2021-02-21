public class Imovel
{
	String end;
	double ivalor;
	String owner;
	Condominio condominio;
	boolean pAlugar;

	public Imovel()
	{
		end="";
		ivalor=0.0;
		owner="";
		condominio=null;
		pAlugar=true;
	}
	
	public Imovel(String adr, double iv, String own, Condominio cond, boolean simounao)
	{
		end=adr;
		ivalor=iv;
		owner=own;
		condominio=cond;
		pAlugar=simounao;
	}

	void setEnd(String address)
	{
		end = address;		
	}

	void setIValor(double value)
	{
		ivalor=value;
	}

	void setOwner(String prop)
	{	
		owner=prop;	
	}

	void setCond(Condominio cd)
	{
		condominio=cd;
	}

	void setBoolean(boolean tf)
	{
		pAlugar=tf;	
	}

	String getEnd()
	{
		return end;
	}

	double getIValor()
	{
		return ivalor;
	}
	
	String getProp()
	{
		return owner;
	}
	
	boolean isPalugar()
	{
		return pAlugar;
	}
}
		

	
