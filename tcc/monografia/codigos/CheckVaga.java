/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package classes;

import com.rapplogic.xbee.api.ApiId;
import com.rapplogic.xbee.api.RemoteAtRequest;
import com.rapplogic.xbee.api.RemoteAtResponse;
import com.rapplogic.xbee.api.XBee;
import com.rapplogic.xbee.api.XBeeAddress64;
import com.rapplogic.xbee.api.XBeeException;
import com.rapplogic.xbee.api.XBeeResponse;
import com.rapplogic.xbee.api.zigbee.ZNetRxIoSampleResponse;
import com.rapplogic.xbee.util.ByteUtils;
import java.awt.Color;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;

/**
 *
 * @author Iuri
 */
public class CheckVaga extends Thread {


    private static int MEIO_SEGUNDO = 500;
    private static int UM_MINUTO = 60000;
    private static int UM_SEGUNDO = 500;
    private static int CINCO_MINUTOS = 60000 * 5;
    
    private boolean ESTADO_NORMAL;
    private boolean active;
    private JLabel status;
    private JLabel idvaga;
    private JPanel vaga;
    private boolean verde;
    private XBee xb;
    private XBeeAddress64 end64;
    private StringBuilder textLog;
    private JTextArea log;
    private XBeeResponse resposta;
    private long inicio, fim;

    public CheckVaga(JLabel status, JLabel idvaga, JPanel vaga, XBee xb, JTextArea log) {
        this.ESTADO_NORMAL = true;
        this.active = true;
        this.status = status;
        this.idvaga = idvaga;
        this.vaga = vaga;
        this.verde = true;
        this.xb = xb;
        this.log = log;
    }

    public boolean isVerde() {
        return verde;
    }

    public void setVerde(boolean verde) {
        this.verde = verde;
    }

    public long getFim() {
        return fim;
    }

    public void setFim(long fim) {
        this.fim = fim;
    }

    public long getInicio() {
        return inicio;
    }

    public void setInicio(long inicio) {
        this.inicio = inicio;
    }

    public boolean isESTADO_NORMAL() {
        return ESTADO_NORMAL;
    }

    public void setESTADO_NORMAL(boolean ESTADO_NORMAL) {
        this.ESTADO_NORMAL = ESTADO_NORMAL;
    }

    public JTextArea getLog() {
        return log;
    }

    public void setLog(JTextArea log) {
        this.log = log;
    }

    public boolean isActive() {
        return active;
    }

    public void setActive(boolean active) {
        this.active = active;
    }

    @Override
    public void run() {

        while (active) {
            try {
                if (ESTADO_NORMAL) {
                    resposta = xb.getResponse(15000);

                    if (resposta.getApiId() == ApiId.ZNET_IO_SAMPLE_RESPONSE) {
                        ZNetRxIoSampleResponse ioSample = (ZNetRxIoSampleResponse) resposta;

                        if (ioSample.isD2On()) {
                            vaga.setBackground(Color.RED);
                            status.setText("VAGA OCUPADA");
                            verde = false;
                        } else {
                            vaga.setBackground(Color.GREEN);
                            status.setText("VAGA LIVRE");
                            verde = true;
                        }
                        //pegar o endereco de 16bits do sensor - saber qual eh a vaga
                        end64 = ioSample.getRemoteAddress64();

                    }
                    xb.sendAsynchronous(new RemoteAtRequest(end64, "NI"));
                    resposta = xb.getResponse(15000);
                    if (resposta.getApiId() == ApiId.REMOTE_AT_RESPONSE) {
                        RemoteAtResponse atResponse = (RemoteAtResponse) resposta;
                        if (atResponse.isOk()) {
                            idvaga.setText(ByteUtils.toString(atResponse.getValue()));
                            System.out.println(ByteUtils.toBase16(atResponse.getValue()));
                        }
                    }
                } else {
                    resposta = xb.getResponse(15000);

                    if (resposta.getApiId() == ApiId.ZNET_IO_SAMPLE_RESPONSE) {
                        ZNetRxIoSampleResponse ioSample = (ZNetRxIoSampleResponse) resposta;

                        if (ioSample.isD2On()) {
                            vaga.setBackground(Color.RED);
                            status.setText("VAGA OCUPADA");

                            //enviar um bit low para o microcontrolador
                            xb.sendAsynchronous(new RemoteAtRequest(end64, "D3", new int[]{4}));
                            resposta = xb.getResponse(15000);
                            if (resposta.getApiId() == ApiId.REMOTE_AT_RESPONSE) {
                                RemoteAtResponse response =  (RemoteAtResponse) resposta;
                                if (response.isOk()) {
                                    System.out.println("Bit enviado!");
                                } else {
                                    System.out.println("Problema no envio do bit!");
                                }
                            }
                            ESTADO_NORMAL = true;
                        } else {
                            fim = System.currentTimeMillis();
                            if ((fim - inicio) <= UM_MINUTO) {
                                vaga.setBackground(Color.ORANGE);
                                status.setText("VAGA RESERVADA");

                                //enviar um bit ativo para o microcontrolador
                                xb.sendAsynchronous(new RemoteAtRequest(end64, "D3", new int[]{5}));
                                resposta = xb.getResponse(15000);
                                if (resposta.getApiId() == ApiId.REMOTE_AT_RESPONSE) {
                                    RemoteAtResponse response =  (RemoteAtResponse) resposta;
                                    if (response.isOk()) {
                                        System.out.println("Bit enviado!");
                                    } else {
                                        System.out.println("Problema no envio do bit!");
                                    }
                                }
                            } else {
                                xb.sendAsynchronous(new RemoteAtRequest(end64, "D3", new int[]{4}));
                                resposta = xb.getResponse(15000);
                                if (resposta.getApiId() == ApiId.REMOTE_AT_RESPONSE) {
                                    RemoteAtResponse response =  (RemoteAtResponse) resposta;
                                    if (response.isOk()) {
                                        System.out.println("Bit enviado!");
                                    } else {
                                        System.out.println("Problema no envio do bit!");
                                    }
                                }
                                vaga.setBackground(Color.GREEN);
                                status.setText("VAGA LIVRE");
                                ESTADO_NORMAL = true;
                            }
                        }
                    }
                }

            } catch (XBeeException ex) {
                System.out.println(ex.getCause());
            }
            try {
                sleep(100);
            } catch (InterruptedException ex) {
                Logger.getLogger(CheckVaga.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
}
