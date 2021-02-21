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
public class Espaco {

    private ArrayList<Poligono> poligonos;
    private Ponto inicio;
    private Ponto fim;
    private Celula[][] plano;
    private int resolucaoX;
    private int resolucaoY;

    public boolean getVizinhos(int x, int y){
        boolean inseriuVizinhos = false;
        ArrayList<Ponto> pVizinhos= new ArrayList<Ponto>();
        if (plano[x][y].getQ() != 1000000000){
        if (x == 0 && y == 0){
            if (plano[x + 1][y].getQ() == -1000000000){
                plano[x + 1][y].setQ(plano[x][y].getQ() + 1);
                pVizinhos.add(new Ponto(x + 1, y));

                inseriuVizinhos = true;
            }
            if (plano[x][y + 1].getQ() == -1000000000){
                plano[x][y + 1].setQ(plano[x][y].getQ() + 1);
                pVizinhos.add(new Ponto(x, y + 1));
                inseriuVizinhos = true;
            }
        }
        else if(x == resolucaoX - 1 && y == 0){
            if (plano[x - 1][y].getQ() == -1000000000){
                plano[x - 1][y].setQ(plano[x][y].getQ() + 1);
                pVizinhos.add(new Ponto(x - 1, y));
                inseriuVizinhos = true;
            }
            if (plano[x][y + 1].getQ() == -1000000000){
                plano[x][y + 1].setQ(plano[x][y].getQ() + 1);
                pVizinhos.add(new Ponto(x, y + 1));
                inseriuVizinhos = true;
            }
        }
        else if(x == 0 && y == resolucaoY - 1){
            if (plano[x][y - 1].getQ() == -1000000000){
                plano[x][y - 1].setQ(plano[x][y].getQ() + 1);
                pVizinhos.add(new Ponto(x, y - 1));
                inseriuVizinhos = true;
            }
            if (plano[x + 1][y].getQ() == -1000000000){
                plano[x + 1][y].setQ(plano[x][y].getQ() + 1);
                pVizinhos.add(new Ponto(x + 1, y));
                inseriuVizinhos = true;
            }
        }
        else if (x == resolucaoX - 1 && y == resolucaoY - 1){
            if (plano[x][y - 1].getQ() == -1000000000){
                plano[x][y - 1].setQ(plano[x][y].getQ() + 1);
                pVizinhos.add(new Ponto(x, y - 1));
                inseriuVizinhos = true;
            }
            if (plano[x - 1][y].getQ() == -1000000000){
                plano[x - 1][y].setQ(plano[x][y].getQ() + 1);
                pVizinhos.add(new Ponto(x - 1, y));
                inseriuVizinhos = true;
            }
        }
        else if (y == 0 && (x > 0 || x < resolucaoX - 1)){
            if (plano[x + 1][y].getQ() == -1000000000){
                plano[x + 1][y].setQ(plano[x][y].getQ() + 1);
                pVizinhos.add(new Ponto(x + 1, y));
                inseriuVizinhos = true;
            }
            if (plano[x][y + 1].getQ() == -1000000000){
                plano[x][y + 1].setQ(plano[x][y].getQ() + 1);
                pVizinhos.add(new Ponto(x, y + 1));
                inseriuVizinhos = true;
            }
            if (plano[x - 1][y].getQ() == -1000000000){
                plano[x - 1][y].setQ(plano[x][y].getQ() + 1);
                pVizinhos.add(new Ponto(x - 1, y));
                inseriuVizinhos = true;
            }
        }
        else if (y == resolucaoY - 1 && (x > 0 || x < resolucaoX - 1)){
            if (plano[x][y - 1].getQ() == -1000000000){
                plano[x][y - 1].setQ(plano[x][y].getQ() + 1);
                pVizinhos.add(new Ponto(x, y - 1));
                inseriuVizinhos = true;
            }
            if (plano[x + 1][y].getQ() == -1000000000){
                plano[x + 1][y].setQ(plano[x][y].getQ() + 1);
                pVizinhos.add(new Ponto(x + 1, y));
                inseriuVizinhos = true;
            }
            if (plano[x - 1][y].getQ() == -1000000000){
                plano[x - 1][y].setQ(plano[x][y].getQ() + 1);
                pVizinhos.add(new Ponto(x - 1, y));
                inseriuVizinhos = true;
            }
        }
        else if (x == 0 && (y > 0 || y < resolucaoY - 1)){
            if (plano[x][y - 1].getQ() == -1000000000){
                plano[x][y - 1].setQ(plano[x][y].getQ() + 1);
                pVizinhos.add(new Ponto(x, y - 1));
                inseriuVizinhos = true;
            }
            if (plano[x + 1][y].getQ() == -1000000000){
                plano[x + 1][y].setQ(plano[x][y].getQ() + 1);
                pVizinhos.add(new Ponto(x + 1, y));
                inseriuVizinhos = true;
            }
            if (plano[x][y + 1].getQ() == -1000000000){
                plano[x][y + 1].setQ(plano[x][y].getQ() + 1);
                pVizinhos.add(new Ponto(x, y + 1));
                inseriuVizinhos = true;
            }
        }
        else if (x == resolucaoX - 1 && (y > 0 || y < resolucaoY - 1)){
            if (plano[x][y - 1].getQ() == -1000000000){
                plano[x][y - 1].setQ(plano[x][y].getQ() + 1);
                pVizinhos.add(new Ponto(x, y - 1));
                inseriuVizinhos = true;
            }
            if (plano[x][y + 1].getQ() == -1000000000){
                plano[x][y + 1].setQ(plano[x][y].getQ() + 1);
                pVizinhos.add(new Ponto(x, y + 1));
                inseriuVizinhos = true;
            }
            if (plano[x - 1][y].getQ() == -1000000000){
                plano[x - 1][y].setQ(plano[x][y].getQ() + 1);
                pVizinhos.add(new Ponto(x - 1, y));
                inseriuVizinhos = true;
            }
        }
        else {
            if (plano[x][y - 1].getQ() == -1000000000){
                plano[x][y - 1].setQ(plano[x][y].getQ() + 1);
                pVizinhos.add(new Ponto(x, y - 1));
                inseriuVizinhos = true;
            }
            if (plano[x + 1][y].getQ() == -1000000000){
                plano[x + 1][y].setQ(plano[x][y].getQ() + 1);
                pVizinhos.add(new Ponto(x + 1, y));
                inseriuVizinhos = true;
            }
            if (plano[x][y + 1].getQ() == -1000000000){
                plano[x][y + 1].setQ(plano[x][y].getQ() + 1);
                pVizinhos.add(new Ponto(x, y + 1));
                inseriuVizinhos = true;
            }
            if (plano[x - 1][y].getQ() == -1000000000){
                plano[x - 1][y].setQ(plano[x][y].getQ() + 1);
                pVizinhos.add(new Ponto(x - 1, y));
                inseriuVizinhos = true;
            }
        }
        }
        plano[x][y].setVizinhos(pVizinhos);
        return inseriuVizinhos;
    }

    public Espaco(int resolucaoX, int resolucaoY, Ponto incio, Ponto fim){
        this.poligonos = new ArrayList<Poligono>();
        this.resolucaoX = resolucaoX;
        this.resolucaoY = resolucaoY;
        this.plano = new Celula[resolucaoX][resolucaoY];

        for (int i = 0 ; i < resolucaoY ; i++){
            for (int j = 0 ; j < resolucaoX ; j++){
                this.plano[i][j] = new Celula();
            }
        }

        this.inicio = incio;
        this.fim = fim;
    }

    public Espaco(ArrayList<Poligono> poligonos, int resolucaoX, int resolucaoY, Ponto inicio, Ponto fim){
        this.poligonos = poligonos;
        this.resolucaoX = resolucaoX;
        this.resolucaoY = resolucaoY;
        this.plano = new Celula[resolucaoX][resolucaoY];

        for (int i = 0 ; i < resolucaoY ; i++){
            for (int j = 0 ; j < resolucaoX ; j++){
                this.plano[i][j] = new Celula();
            }
        }

        this.inicio = inicio;
        this.fim = fim;
    }

    public boolean temInterseccao(Poligono p1, Poligono p2){
        boolean flag = false;
        for (Ponto p : p1.getVertices()){
            if (p2.estaDentro(p)){
                flag = true;
            }
        }
        return flag;
    }

    public void criarPoligonos(Poligono p){
        if (poligonos.isEmpty()){
            poligonos.add(p);
        }
        else {
            int tamanhoPoligonos = poligonos.size();
            for (int i = 0 ; i < tamanhoPoligonos ; i++){
                if (!temInterseccao(p, poligonos.get(i))){
                    this.poligonos.add(p);
                }
            }
        }
    }

    //define-se primeiro o GR e depois o CB
    public void preencherPlanoGR(){
        for (int i = 0 ; i < getResolucaoY() ; i++){
            for (int j = 0 ; j < getResolucaoX() ; j++){
                this.plano[j][i].setQ(-1000000000);
            }
        }
    }

    //define-se primeiro o GR e depois o CB
    public void preencherPlanoCB(){
        for (int i = 0 ; i < getResolucaoY() ; i++){
            for (int j = 0 ; j < getResolucaoX() ; j++){
                for (Poligono p : this.poligonos){
                    Ponto pAux = new Ponto(j, i);
                    if (p.estaDentro(pAux)){
                        this.plano[i][j].setQ(1000000000);
                    }
                }
            }
        }
    }

    public void manhattan(){
        preencherPlanoGR();
        preencherPlanoCB();
        ArrayList<Ponto> l = new ArrayList<Ponto>();
        plano[fim.getX()][fim.getY()].setQ(0);
        plano[fim.getX()][fim.getY()].setFlag(true);
        l.add(fim);
        while (!l.isEmpty()){
            //for (Ponto p : l){ //for (int j = 0 ; j < l.size() ; j++)
            Ponto p = l.get(0);
            l.remove(0);
                if (getVizinhos(p.getX(), p.getY())){
                    
                    for (int i = 0 ; i < plano[p.getX()][p.getY()].getVizinhos().size() ; i++){
                        if (!plano[plano[p.getX()][p.getY()].getVizinhos().get(i).getX()][plano[p.getX()][p.getY()].getVizinhos().get(i).getY()].isFlag()){
                            l.add(plano[p.getX()][p.getY()].getVizinhos().get(i));
                            plano[plano[p.getX()][p.getY()].getVizinhos().get(i).getX()][plano[p.getX()][p.getY()].getVizinhos().get(i).getY()].setFlag(true);
                        }
                    }
                }
        }
        printMatriz();
    }

    public void printMatriz(){
        for (int i = 0 ; i < getPlano().length ; i++){
            //System.out.print(i + " ");
            for (int j = 0 ; j < getPlano().length ; j++){

                if (getPlano()[i][j].getQ() == 1000000000)
                    System.out.print("xx ");
                else if (getPlano()[i][j].getQ() < 10){
                    if (getPlano()[i][j].getQ() == 0)
                        System.out.print("QF ");
                    else
                        System.out.print("0" + getPlano()[i][j].getQ() + " ");
                }
                else {
                    if (i == inicio.getX() && j == inicio.getY())//getPlano()[i][j].getQ() == 18)]
                        System.out.print("QI ");
                    else
                        System.out.print(getPlano()[i][j].getQ() + " ");
                }
            }
            System.out.println();
        }
    }

    public int getResolucaoX() {
        return resolucaoX;
    }

    public void setResolucaoX(int resolucaoX) {
        this.resolucaoX = resolucaoX;
    }

    public int getResolucaoY() {
        return resolucaoY;
    }

    public void setResolucaoY(int resolucaoY) {
        this.resolucaoY = resolucaoY;
    }

    public Celula[][] getPlano() {
        return plano;
    }

    public Celula getCelulaPlano(int x, int y){
        return plano[x][y];
    }

    public Ponto getFim() {
        return fim;
    }

    public void setFim(Ponto fim) {
        this.fim = fim;
    }

    public Ponto getInicio() {
        return inicio;
    }

    public void setInicio(Ponto inicio) {
        this.inicio = inicio;
    }

    public ArrayList<Poligono> getPoligonos() {
        return poligonos;
    }

    public void setPoligonos(ArrayList<Poligono> poligonos) {
        this.poligonos = poligonos;
    }

}
