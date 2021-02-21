package ufrn.laed2.arvores.testes;
import java.util.Comparator;
import ufrn.laed2.arvores.BSTree;
import ufrn.laed2.arvores.excessoes.ElementAlreadyExistException;
import ufrn.laed2.arvores.excessoes.ElementNotFoundException;

public class SilvioBSTreeTest1<T> {
  
	public SilvioBSTreeTest1(){}
        
        public void print(BSTree<T> b, int qtd, boolean inorder){
            String[] strs = {""};
            System.out.println();
            if(inorder){
              strs = b.inOrder().toArray(strs);
              System.out.println("SILVIO: ====== Arvore in order =====");
            }else{
              strs = b.preOrder().toArray(strs);
              System.out.println("SILVIO: ====== Arvore Preorder =====");
            }
            for(int i=0; i<qtd; i++){
                System.out.println("SILVIO: "+strs[i]);
            }
            System.out.println("SILVIO: =============================");
            System.out.println();
        }
      
      
        public static void main(String[] args){
          BSTree<String> bt;
          SilvioBSTreeTest1<String> teste = new SilvioBSTreeTest1<String>();
          int adicionados=0;
          
          bt = new BSTree<String>(new Comparator<String>() {
                  public int compare(String o1, String o2) {
                          return o1.compareTo(o2);
                  }
          });
          String[] data = {"Ana", "Bruna", "Carla", "Daniele", "Emanuele", "Fabiana"};
        
          try{
            System.out.println("SILVIO: Procurando "+data[0]+" na arvore vazia");
            bt.find(data[0]);
            
          }catch(ElementNotFoundException e){
            System.out.println("SILVIO: "+data[0]+" nao foi encontrado, entao sera adicionado");
            try{
                bt.add(data[0]);
                adicionados++;
                teste.print(bt, adicionados, true);
                
                System.out.println("SILVIO: Tentando adiconar "+data[0]+" novamente");
                bt.add(data[0]);
                adicionados++;
            }catch(ElementAlreadyExistException ea){
                System.out.println("SILVIO: Como "+data[0]+" ja existe, vamos adicionar os outros");
                for(int i=1; i<6; i++){
                  try{
                      bt.add(data[i]);
                      adicionados++;
                  }catch(ElementAlreadyExistException ea2){
                      System.out.println("SILVIO: a arvore ERRADAMENTE informa que o elemento "+data[i]+" ja existe");
                  }
                }
            }
          }
          System.out.println("SILVIO: apos as insercoes:");
          teste.print(bt, adicionados, true);
          teste.print(bt, adicionados, false);
        
          
          System.out.println("SILVIO: tentando remover "+data[3]);
          try{
              bt.remove(data[3]);
              adicionados--;
              System.out.println("SILVIO: o elemento foi removido e arvore ficou assim:");
              teste.print(bt, adicionados, true);
          }catch(ElementNotFoundException e){
              System.out.println("SILVIO: a arvore ERRADAMENTE informa que o elemento "+data[3]+" nao foi encontrado");
          }
        
          try{
            System.out.println("SILVIO: procurando o elemento "+data[3]+" novamente");
            bt.find(data[3]);
          }catch(ElementNotFoundException e){
            System.out.println("SILVIO: o elemente nao se encontra mais na arvore, entao vamos remover os outros");
            int qtd = adicionados;
            for(int i=qtd; i>=0; i--){
              if(i != 3){
                try{
                  bt.remove(data[i]);
                  adicionados--;
                }catch(ElementNotFoundException en){
                  System.out.println("SILVIO: a arvore ERRADAMENTE informa que o elemento "+data[i]+" nao foi encontrado");
                }
              }
            }
          }
        
          System.out.println("SILVIO: apos as remocoes:");
          teste.print(bt, adicionados, true);
          teste.print(bt, adicionados, false);
        
          
          
        }
}