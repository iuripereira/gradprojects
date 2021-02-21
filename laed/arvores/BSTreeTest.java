import java.util.Comparator;

public class BSTreeTest {

	final String[] data = {"maria", "ze", "ana carolina", "joao", "carlos"};
	BSTree<String> bt;
      
        public BSTreeTest(){
        }

	protected void setUp() throws Exception {
		bt = new BSTree<String>(new Comparator<String>() {
			public int compare(String o1, String o2) {
				return o1.compareTo(o2);
			}
		});
	}

	public void testAdd() {
		String[] strs = {""};
		try {
			bt.add(data[0]);
			bt.add(data[1]);
			strs = bt.inOrder().toArray(strs);
			bt.add(data[2]);
			strs = bt.inOrder().toArray(strs);
			bt.add(data[3]);
			strs = bt.inOrder().toArray(strs);
			bt.add(data[4]);
			strs = bt.inOrder().toArray(strs);
		}
		catch (ElementAlreadyExistException e){
                      System.err.println(e);
		}
              /*
		try {
			bt.add(data[1]);
			// se nao gerar excecao, esta errado
		}
		catch (ElementAlreadyExistException e){
			// Se entrar nessa excecao, entao esta correto
                      System.err.println(e);
		}
              */
	}
	
	public void testRemove() {
		String[] strs = {""};
		try {
			bt.remove(data[0]);
			strs = bt.inOrder().toArray(strs);
			bt.remove(data[1]);
			strs = bt.inOrder().toArray(strs);
			bt.remove(data[4]);
			strs = bt.inOrder().toArray(strs);
			bt.remove(data[3]);
			strs = bt.inOrder().toArray(strs);
		}
		catch (Exception e){
                      System.err.println(e);
		}
             /*
		try {
			bt.remove(data[1]);
			// se nao gerar excecao, esta errado
			//fail();
		}
		catch (ElementNotFoundException e){
			// Se entrar nessa excecao, entao esta correto
                      System.err.println(e);
		}
            */  
	}
      
        public static void main(String[] args){
          BSTreeTest bst = new BSTreeTest();
        
          try{
            bst.setUp();
          }catch(Exception e){
            System.err.println(e);
          }
          
          System.out.println("Testando add");
          bst.testAdd();
          System.out.println("Testando remove");
          bst.testRemove();
        }
}
