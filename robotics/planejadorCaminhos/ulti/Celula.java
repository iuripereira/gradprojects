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
public class Celula {

    private int q;
    private ArrayList<Ponto> vizinhos;
    private boolean flag;

    public Celula() {
        this.vizinhos = new ArrayList<Ponto>();
        this.flag = false;
    }

    public int getQ() {
        return q;
    }

    public void setQ(int q) {
        this.q = q;
    }

    public ArrayList<Ponto> getVizinhos() {
        return vizinhos;
    }

    public void setVizinhos(ArrayList<Ponto> vizinhos) {
        this.vizinhos = vizinhos;
    }

    public boolean isFlag() {
        return flag;
    }

    public void setFlag(boolean flag) {
        this.flag = flag;
    }
    
}
