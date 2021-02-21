/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package introducaoRobotica.planejadorCaminhos.ulti;

/**
 *
 * @author RodrigoSwars
 */
public class Main {

    public static void main(String[] args){
        Poligono p1 = new Poligono();
        p1.addVertice(new Ponto(2,2));
        p1.addVertice(new Ponto(4,2));
        p1.addVertice(new Ponto(3,4));
        p1.addVertice(new Ponto(0,4));

        Poligono p2 = new Poligono();
        p2.addVertice(new Ponto(7,0));
        p2.addVertice(new Ponto(7,2));
        p2.addVertice(new Ponto(6,2));
        p2.addVertice(new Ponto(6,3));
        p2.addVertice(new Ponto(9,3));
        p2.addVertice(new Ponto(9,0));

        Poligono p3 = new Poligono();
        p3.addVertice(new Ponto(5,5));
        p3.addVertice(new Ponto(7,5));
        p3.addVertice(new Ponto(7,7));
        p3.addVertice(new Ponto(5,7));

        Poligono p4 = new Poligono();
        p4.addVertice(new Ponto(0,7));
        p4.addVertice(new Ponto(3,7));
        p4.addVertice(new Ponto(3,9));
        p4.addVertice(new Ponto(0,9));

        Espaco e = new Espaco(10, 10,new Ponto(9, 7), new Ponto(0, 0));
        e.criarPoligonos(p1);
        e.criarPoligonos(p2);
        e.criarPoligonos(p3);
        e.criarPoligonos(p4);

        e.manhattan();
    }

}
