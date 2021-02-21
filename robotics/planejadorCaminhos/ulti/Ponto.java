/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package introducaoRobotica.planejadorCaminhos.ulti;

/**
 *
 * @author RodrigoSwars
 */
public class Ponto {

    private int x;
    private int y;

    public Ponto(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public Ponto getYmais1(){

        return null;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    public Ponto clone(){
        return new Ponto(x, y);
    }

}
