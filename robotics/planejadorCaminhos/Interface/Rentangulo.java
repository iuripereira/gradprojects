package introducaoRobotica.planejadorCaminhos.Interface;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */



import introducaoRobotica.planejadorCaminhos.ulti.Espaco;
import introducaoRobotica.planejadorCaminhos.ulti.Poligono;
import introducaoRobotica.planejadorCaminhos.ulti.Ponto;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Polygon;
import java.util.ArrayList;
import javax.swing.JFrame;
import javax.swing.JPanel;

/**
 *
 * @author RodrigoSwars
 */
public class Rentangulo extends JPanel{

    Espaco e ;
    Poligono p1;
    Poligono p2;
    Poligono p3;
    Poligono p4;

    public void criarEspaco(){
        p1 = new Poligono();
        p1.addVertice(new Ponto(2,2));
        p1.addVertice(new Ponto(4,2));
        p1.addVertice(new Ponto(3,4));
        p1.addVertice(new Ponto(0,4));

        p2 = new Poligono();
        p2.addVertice(new Ponto(7,0));
        p2.addVertice(new Ponto(7,2));
        p2.addVertice(new Ponto(6,2));
        p2.addVertice(new Ponto(6,3));
        p2.addVertice(new Ponto(9,3));
        p2.addVertice(new Ponto(9,0));

        p3 = new Poligono();
        p3.addVertice(new Ponto(5,5));
        p3.addVertice(new Ponto(7,5));
        p3.addVertice(new Ponto(7,7));
        p3.addVertice(new Ponto(5,7));

        p4 = new Poligono();
        p4.addVertice(new Ponto(0,7));
        p4.addVertice(new Ponto(3,7));
        p4.addVertice(new Ponto(3,9));
        p4.addVertice(new Ponto(0,9));

        e = new Espaco(10, 10,new Ponto(9, 7), new Ponto(0, 0) );
        e.criarPoligonos(p1);
        e.criarPoligonos(p2);
        e.criarPoligonos(p3);
        e.criarPoligonos(p4);

        e.manhattan();

    }
   

    public void paintComponent(Graphics g){
        super.paintComponent(g);

        this.setBackground(Color.WHITE);

        criarEspaco();

        g.setColor(Color.RED);

        /* int q = e.getPlano()[e.getInicio().getX()][e.getInicio().getY()].getQ();
        ArrayList<Ponto> caminho = new ArrayList<Ponto>();


       Ponto p = e.getInicio();
        caminho.add(p);
        while (q >= 0){
            if (e.getVizinhos(p.getX(), p.getY())){
                for (int i = 0 ; i < e.getPlano()[p.getX()][p.getY()].getVizinhos().size() ; i++){
                    if (e.getPlano()[e.getPlano()[p.getX()][p.getY()].getVizinhos().get(i).getX()][e.getPlano()[p.getX()][p.getY()].getVizinhos().get(i).getY()].getQ() == q - 1){
                        p = new Ponto((e.getPlano()[p.getX()][p.getY()].getVizinhos().get(i).getX()),(e.getPlano()[p.getX()][p.getY()].getVizinhos().get(i).getY()));
                        caminho.add(p);
                        i = e.getPlano()[p.getX()][p.getY()].getVizinhos().size();
                    }
                }
                q--;
            }
        }*/

        //g.drawLine(e.getInicio().getX(), e.getInicio().getY(), e.getInicio().getX(), e.getInicio().getY());
        //g.drawLine(e.getFim().getX(), e.getFim().getY(), e.getFim().getX(), e.getFim().getY());

        Polygon poly1 = new Polygon(p1.getValoresX(), p1.getValoresY(), p1.getTam());
        g.fillPolygon(poly1);
        Polygon poly2 = new Polygon(p2.getValoresX(), p2.getValoresY(), p2.getTam());
        g.fillPolygon(poly2);
        Polygon poly3 = new Polygon(p3.getValoresX(), p3.getValoresY(), p3.getTam());
        g.fillPolygon(poly3);

        /*for (int i = 0 ; i < 10 ; i++){
            for (int j = 0 ; j < 10 ; j++){
                g.drawLine(j, i, j, i);
            }
        }*/

        /*for (int i = 0; i < e.getPlano().length ; i++){
            for (int j = 0 ; j < e.getPlano().length ; j++){
                if (e.getPlano()[j][i].getQ() == 1000000000)
                    g.setColor(Color.RED);
                    g.drawLine(j,i,j,i);
            }
        }*/
        //g.drawLine(x,y,x,y);

        //xValues = {0, 100, 100, 0};
        //int[] yValues = {0, 0, 100, 100};

        //Ponto p1 = new Ponto(0, 0);
        //Ponto p2 = new Ponto(100, 0);
        //Ponto p3 = new Ponto(100, 100);
        //Ponto p4 = new Ponto(0, 100);
        //Poligono p = new Poligono();
     
        //p.addVertice(p1);
        //p.addVertice(p2);
        //p.addVertice(p3);
        //p.addVertice(p4);
        //Polygon poly = new Polygon(xValues, yValues, xValues.length);
        //g.fillPolygon(poly);
    }

  //  public void criarTela(ArrayList<Poligono> poli, Ponto ini, Ponto fim, Graphics g){
    //    for(int i=0; i<poli.size(); i++){

      //      Polygon poly = new Polygon(poli.get(i).getValoresX(), poli.get(i).getValoresY(),poli.get(i).getTam());
        //    g.fillPolygon(poly);
        //}
//    }
    public static void main(String[] args){
        JFrame frame = new JFrame("EXEMPLO");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Rentangulo rect = new Rentangulo();
        rect.setBackground(Color.WHITE);
        frame.add(rect);
        frame.setSize(110, 110);
        frame.setVisible(true);
       }
    
}
