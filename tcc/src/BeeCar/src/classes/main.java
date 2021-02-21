/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package classes;

import com.rapplogic.xbee.api.ApiId;
import com.rapplogic.xbee.api.AtCommand;
import com.rapplogic.xbee.api.AtCommandResponse;
import com.rapplogic.xbee.api.RemoteAtRequest;
import com.rapplogic.xbee.api.RemoteAtResponse;
import com.rapplogic.xbee.api.XBee;
import com.rapplogic.xbee.api.XBeeAddress16;
import com.rapplogic.xbee.api.XBeeAddress64;
import com.rapplogic.xbee.api.XBeeException;
import com.rapplogic.xbee.api.XBeeResponse;
import com.rapplogic.xbee.api.XBeeTimeoutException;
import com.rapplogic.xbee.api.zigbee.ZNetRxIoSampleResponse;
import com.rapplogic.xbee.util.ByteUtils;

/**
 *
 * @author Iuri
 */
public class main {

    public static void main(String Args[]) throws XBeeException, InterruptedException {
        Connection con = new Connection();
        con.abrir("COM3", 9600);
        XBee xb = con.getXb();
        XBeeAddress64 end64 = null;


        while (true) {
            System.out.println("Esperando...");
            try {
                XBeeResponse resposta = xb.getResponse(30000);
                if (resposta.getApiId() == ApiId.ZNET_IO_SAMPLE_RESPONSE) {
                    ZNetRxIoSampleResponse ioSample = (ZNetRxIoSampleResponse) resposta;

                    if (ioSample.isD4On()) {
                        System.out.println("CHECANDO - VAGA OCUPADA!");
                    } else {
                        System.out.println("CHECANDO - VAGA LIVRE!");
                    }
                    end64 = ioSample.getRemoteAddress64();
                }
                xb.sendAsynchronous(new RemoteAtRequest(end64, "D3", new int[]{4}));
                if (resposta.getApiId() == ApiId.REMOTE_AT_RESPONSE) {
                    AtCommandResponse response = (AtCommandResponse) resposta;
                    if (response.isOk()) {
                        System.out.println("Successfully turned on DI30");
                    }
                }
            } catch (XBeeTimeoutException e) {
                System.out.println("Tempo limite esgotado");
            }
            Thread.sleep(1000);
        }
    }
}
