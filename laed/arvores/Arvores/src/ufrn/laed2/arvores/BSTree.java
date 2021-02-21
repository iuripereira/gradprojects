package ufrn.laed2.arvores;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Comparator;
import ufrn.laed2.arvores.excessoes.ElementAlreadyExistException;
import ufrn.laed2.arvores.excessoes.ElementNotFoundException;

/** Arvore binaria de busca */
public class BSTree<T> 
{
	
	/** Noh da arvore binaria de busca */
	protected class BSNode 
        {
		protected boolean terminal;
		protected T data;
		protected BSNode left;
		protected BSNode right;
                protected BSNode pai;
		
                public BSNode()
                {
			this(null);
		}
		public BSNode(T data){
			this.data = data;
			this.terminal = true;
			this.left = this.right = this.pai = null;
		}
              
                /** Retorna o dado do Noh*/
		public T getData() {    
                    return this.data;
                }
              
                /** Seta o valor do dado do Noh*/
		public void setData(T elm){
                    this.data = elm;
		}
              
                /** Retorna o Noh esquerdo*/
		public BSNode getLeft(){
                    return this.left;
                }
              
                /** Retorna o Noh direito*/
		public BSNode getRight(){
                    return this.right;
                }
                
                /**Retorna o pai do Noh*/
                public BSNode getPai(){
                    return this.pai;
                }
              
                /** Retorna true se o Noh eh terminal e false caso contrario*/
		public boolean isTerminal() {
                       if(this.left.data == null && this.right.data == null)
                       {
                           return true;
                       }
                       else
                       {
                           return false;
                       }
		}
              
                /** Copia setando o dado do Noh com o valor do Noh passado como parametro*/
		public void copyDataFrom(BSNode source){
                    T elm = source.data;
                    this.data = elm;
                }
              
                /** Copia e seta todos os atributos do Noh com os valores do Noh passado como parametro*/
		public void copyAllFrom(BSNode source){
                    this.data = source.data;
                    this.left = source.left;
                    this.right = source.right;
                    this.pai = source.pai;
                    this.terminal = source.terminal;
                }
              
                /** Retorna o Noh sucessor*/
		protected BSNode getSuccessor()
                {
			BSNode obj = this;
			if(obj.getRight().data != null)
			{
				obj = obj.getRight();
				if(obj.isTerminal())
				{
					return obj;
				}
				else
                                {
                                    while(obj.getLeft().data != null)
                                    {
                                            obj = obj.getLeft();
                                    }
                                    return obj;
                                }
			}                    
			else
                            return null;
		}
              
                /** Retorna o menor Noh antes desse*/
		protected BSNode getSmallest()
                {
                    BSNode aux = this;
                    if(aux.getLeft().data != null)
                    {
                        aux = aux.getLeft();
                        if(aux.isTerminal() == true)
                        {
                            return aux;
                        }
                        else
                        {
                            while(aux.getRight().data != null)
                            {
                                aux = aux.getRight();
                            }
                            return aux;
                        }
                    }
                    else
                        return null;
                }
        }

	// --- fim da classe BSNode
	
	Comparator<T> comp;
        	
	protected BSNode root;
        
        public BSTree(Comparator<T> comp) {
		this.root = new BSNode();
		this.comp = comp;                
	}
        /** Procura um elemento na arvore e o retorna, se nao for encontrado 
        *   a excecao ElementNotFoundException eh lancada */
	public BSNode find(T elm) throws ElementNotFoundException 
        {
                BSNode obj;
		if(elm != null)
                {
                    obj = find(root, elm);
                    if(obj != null)
                    {
                        if(obj.data != elm) 
                            throw new ElementNotFoundException();
                        else 
                            return obj;
                    }
                } 
                throw new ElementNotFoundException();
        }
        
        /** Adiciona um novo elemento na arvore, caso esse elemento ja exista 
        * a execao ElementAlreadyExistException eh lancada*/
	public void add(T elm) throws ElementAlreadyExistException 
        {
            BSNode obj = new BSNode(elm);
            BSNode obj2;
            if(elm != null) 
            {
                obj2 = find(root, elm);
                BSNode esq = new BSNode();
                BSNode dir = new BSNode();
                BSNode painulo = new BSNode();
		if(obj2 != null)
                {
                    if(this.comp.compare(elm, obj2.data) > 0 )
                    {	                        
                        obj2.right = obj;
                        obj.pai = obj2;
                        obj.left = esq;
                        obj.right = dir;
                        esq.pai = obj;
                        dir.pai = obj;
                    }
                    else if(this.comp.compare(elm, obj2.data) < 0 )
                    {
                        obj2.left = obj;
                        obj.pai = obj2;
                        obj.left = esq;
                        obj.right = dir;
                        esq.pai = obj;
                        dir.pai = obj;
                    }
                    else throw new ElementAlreadyExistException();
		}
		else
                {
                    this.root = obj;
                    obj.left = esq;
                    obj.right = dir;
                    obj.pai = painulo;
                    esq.pai = obj;
                    dir.pai = obj;
		}
            }
	}
	
        /** Remove um elemento da arvore, caso esse elemento na exista
        * a execao ElementNotFoundException eh lancada*/
	public void remove(T elm) throws ElementNotFoundException 
        {
            BSNode obj = find(elm);
            if(obj != null)
            {
                if(obj.data != elm) 
                    throw new ElementNotFoundException();
                else 
                    remove(obj);
            }
        }

        /** Retorna uma colecao com os Nohs da arvore de forma pre-ordenada, ou seja,
        * a partir da raiz incluir o Noh, em seguido o filho esquerdo depois o direito*/
	public Collection<T> preOrder()
        {
            ArrayList<T> col = new ArrayList<T>();
            BSNode raiz = this.root;
            preOrder(raiz, col);
            return col;
	}
	
        /** Retorna uma colecao com os Nohs da arvore de forma ordenada, ou seja,
        * do menor valor ate o maior valor armazenado na arvore*/
	public Collection<T> inOrder()
        {
            ArrayList<T> col = new ArrayList<T>();
            BSNode raiz = this.root;
            inOrder(raiz, col);
            return col;
        }
	
        //////////////////////////////////////////////////////////////////////
	// --- A partir daqui, os metodos nao sao publicos
        // --- Esses metodos auxiliam o trabalho dos metodos publicos
        //////////////////////////////////////////////////////////////////////
	
        /** Procura um elemento na arvore e o retorna apartir de um Noh especifico
        * caso o elemento nao esteja na arvore essa funcao deve retornar a posicao que ele ocuparia */
	protected BSNode find(BSNode node, T elm)
        {
            if(node.data == null)
            {
                return null;
            }
            else if(this.comp.compare(elm, node.data) > 0)
            {
                if(node.getRight().data == null)
                        return node;
                else
                        return find(node.getRight(), elm);
            }
            else if(this.comp.compare(elm, node.data) < 0)
            {
                if(node.getLeft().data == null)
                    return node;
                else
                    return find(node.getLeft(), elm);
            }
            else
            {
                return node;
            }
        }

        /** Remove um Noh da arvore e liga os filhos esquerdos e direto aos novos pais*/
	protected void remove(BSNode node)
        {
            BSNode obj = new BSNode();
            BSNode pai;
            if(node.isTerminal())
            {
                pai = node.getPai();
                if(pai == null)
                {
                    node.copyAllFrom(obj);                    
                }
                else
                {
                    node.copyDataFrom(obj);
                }
                
            }
            else
            {
                BSNode obj2 = new BSNode(), 
                       obj3 = new BSNode();
                BSNode ptDir = node.right,
                       ptEsq = node.left;
                
                if(ptDir.data == null)
                {
                    obj2 = node.getSmallest();
                    if(obj2 != null)
                    {
                        node.copyDataFrom(obj2);
                        if(!obj2.isTerminal())
                        {
                            obj3 = obj2.getPai();
                            obj3.right = obj2.getLeft();
                            obj2.copyAllFrom(obj);
                        }
                        else
                        {
                            obj2.copyDataFrom(obj);
                        }
                    }
                }
                else
                {
                    obj2 = node.getSuccessor();
                    if(obj2.getRight().data != null)
                    {
                        node.copyAllFrom(obj2);
                    }
                    else
                    {
                        node.copyDataFrom(obj2);
                    }
                    if(!obj2.isTerminal())
                    {
                        obj3 = node.getPai();
                        obj3.left = obj2.getRight();
                        obj2.right = new BSNode();
                    }                        
                }
                obj2.copyAllFrom(obj);
            }
        }
	
        /** Faz a pre-ordenacao da arvore a partir de um Noh especifico e armazena os elementos pre-ordenados
        * na colecao passada como parametro*/
	protected void preOrder(BSNode node, Collection<T> col)
        {
            if(node != null && node.data  != null)
            {
		col.add(node.data);
                preOrder(node.getLeft(), col);
                preOrder(node.getRight(), col);
            }
	}

        /** Faz a ordenacao da arvore a partir de um Noh especifico e armazena os elemenentos ordenados
        * na colcecao passada como parametro*/
	protected void inOrder(BSNode node, Collection<T> col)
        {
            if(node != null && node.data  != null)
            {
		inOrder(node.getLeft(), col);
                col.add(node.data);
                inOrder(node.getRight(), col);
            }
        }
}