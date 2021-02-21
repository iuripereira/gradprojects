package classes;

import com.rapplogic.xbee.api.XBee;
import com.rapplogic.xbee.api.XBeeException;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author Iuri
 */
public class Connection {

    private XBee xb = new XBee();

    public Connection() {
    }

    public XBee getXb() {
        return xb;
    }

    public void setXb(XBee xb) {
        this.xb = xb;
    }

    public void abrir(String porta, int velocidade) throws XBeeException {
        this.xb.open(porta, velocidade);
        if (xb.isConnected()) {
            System.out.println("Conectado!");
        }
    }

    public void fechar() {
        if(xb.isConnected()){
            this.xb.close();
            System.out.println("Conexao encerrada!");
        }
    }
}
