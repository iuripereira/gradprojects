/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package introducaoRobotica.planejadorCaminhos.ulti;

import java.util.ArrayList;

/**
 *
 * @author RodrigoSwars
 */
public class Poligono {

    private ArrayList<Ponto> vertices;

    public Poligono(ArrayList<Ponto> vertices){
        this.vertices = vertices;
    }

    public Poligono(){
        this.vertices = new ArrayList<Ponto>();
    }

    public void clear(){
        this.vertices.clear();
    }

    public Poligono clone(){
        return new Poligono();
    }

    public void addVertice(Ponto p){
        this.vertices.add(p);
    }
    public int getTam(){
        int tam = this.vertices.size();
        return tam;
    }
    public int[] getValoresX(){
        int[] valoresX = new int[vertices.size()];
        for (int i = 0 ; i < vertices.size() ; i++){
            valoresX[i] = vertices.get(i).getX();
        }
        return valoresX;
    }

    public int[] getValoresY(){
        int[] valoresY = new int[vertices.size()];
        for (int i = 0 ; i < vertices.size() ; i++){
            valoresY[i] = vertices.get(i).getY();
        }
        return valoresY;
    }

    public boolean estaDentro(Ponto p){
        double d0 = 100000000;
        double d;
        int k = 1;
        while (k <= vertices.size()){
            if (k == vertices.size()){
                int k1 = vertices.size() - 1;
                int k2 = vertices.size() - vertices.size();
                int a = vertices.get(k1).getY() - vertices.get(k2).getY();
                int b = vertices.get(k2).getX() - vertices.get(k1).getX();
                int c = (vertices.get(k1).getX() * vertices.get(k2).getY()) - (vertices.get(k2).getX() * vertices.get(k1).getY());
                double fator1 = a * p.getX();
                double fator2 = b * p.getY();
                double fator3 = c;
                double fator4 = Math.sqrt(Math.pow(a, 2) + Math.pow(b, 2));
                d = (fator1 + fator2 + fator3) / fator4;
            }
            else{
                int a = vertices.get(k - 1).getY() - vertices.get(k).getY();
                int b = vertices.get(k).getX() - vertices.get(k - 1).getX();
                int c = (vertices.get(k - 1).getX() * vertices.get(k).getY()) - (vertices.get(k).getX() * vertices.get(k - 1).getY());
                double fator1 = a * p.getX();
                double fator2 = b * p.getY();
                double fator3 = c;
                double fator4 = Math.sqrt(Math.pow(a, 2) + Math.pow(b, 2));
                d = (fator1 + fator2 + fator3) / fator4;
            }
            

            if (d < d0){
                d0 = d;
            }
            k += 1;
        }

        if (d0 >= 0){
            return true;
        }
        else {
            return false;
        }
    }

    public Ponto getVertice(int index){
        return vertices.get(index);
    }

    public ArrayList<Ponto> getVertices() {
        return vertices;
    }

}
