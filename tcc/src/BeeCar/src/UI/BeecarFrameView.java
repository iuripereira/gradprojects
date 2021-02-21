/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * BeecarFrameView.java
 *
 * Created on 06/12/2010, 18:14:17
 */
package UI;

import classes.CheckVaga;
import classes.Connection;
import com.rapplogic.xbee.api.XBee;
import com.rapplogic.xbee.api.XBeeException;
import java.awt.Color;
import javax.swing.JOptionPane;

/**
 *
 * @author Iuri
 */
public class BeecarFrameView extends javax.swing.JFrame {

    private Connection con = new Connection();
    private XBee xb;
    private CheckVaga cv;

    /** Creates new form BeecarFrameView */
    public BeecarFrameView() {
        initComponents();
    }

    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        MainPanel = new javax.swing.JPanel();
        jScrollPane1 = new javax.swing.JScrollPane();
        Logger = new javax.swing.JTextArea();
        jbConnect = new javax.swing.JButton();
        jpMain = new javax.swing.JPanel();
        jpVaga1 = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        jLStatus = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        jLIDvaga = new javax.swing.JLabel();
        jpVaga2 = new javax.swing.JPanel();
        jLabel2 = new javax.swing.JLabel();
        jLStatus1 = new javax.swing.JLabel();
        jLabel8 = new javax.swing.JLabel();
        jLvaga1 = new javax.swing.JLabel();
        jpVaga3 = new javax.swing.JPanel();
        jLabel3 = new javax.swing.JLabel();
        jLStatus2 = new javax.swing.JLabel();
        jLabel9 = new javax.swing.JLabel();
        jLvaga2 = new javax.swing.JLabel();
        jbDisconnect = new javax.swing.JButton();
        jbRequest = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        Logger.setColumns(20);
        Logger.setRows(5);
        jScrollPane1.setViewportView(Logger);

        jbConnect.setText("Conectar");
        jbConnect.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jbConnectActionPerformed(evt);
            }
        });

        jpMain.setBorder(javax.swing.BorderFactory.createEtchedBorder());

        jpVaga1.setBackground(new java.awt.Color(102, 102, 102));
        jpVaga1.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));

        jLabel1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/img/car.jpg"))); // NOI18N

        jLStatus.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLStatus.setText("ESPERANDO...");

        jLabel7.setText("ID VAGA:");

        javax.swing.GroupLayout jpVaga1Layout = new javax.swing.GroupLayout(jpVaga1);
        jpVaga1.setLayout(jpVaga1Layout);
        jpVaga1Layout.setHorizontalGroup(
            jpVaga1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jpVaga1Layout.createSequentialGroup()
                .addGroup(jpVaga1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jpVaga1Layout.createSequentialGroup()
                        .addGap(44, 44, 44)
                        .addComponent(jLabel1))
                    .addGroup(jpVaga1Layout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(jLabel7)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jLIDvaga, javax.swing.GroupLayout.PREFERRED_SIZE, 59, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jpVaga1Layout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(jLStatus, javax.swing.GroupLayout.PREFERRED_SIZE, 100, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        jpVaga1Layout.setVerticalGroup(
            jpVaga1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jpVaga1Layout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addGroup(jpVaga1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(jLabel7)
                    .addComponent(jLIDvaga, javax.swing.GroupLayout.PREFERRED_SIZE, 14, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jLabel1)
                .addGap(11, 11, 11)
                .addComponent(jLStatus)
                .addContainerGap())
        );

        jpVaga2.setBackground(new java.awt.Color(102, 102, 102));
        jpVaga2.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));

        jLabel2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/img/car.jpg"))); // NOI18N

        jLStatus1.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLStatus1.setText("ESPERANDO...");

        jLabel8.setText("ID VAGA:");

        javax.swing.GroupLayout jpVaga2Layout = new javax.swing.GroupLayout(jpVaga2);
        jpVaga2.setLayout(jpVaga2Layout);
        jpVaga2Layout.setHorizontalGroup(
            jpVaga2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jpVaga2Layout.createSequentialGroup()
                .addGroup(jpVaga2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jpVaga2Layout.createSequentialGroup()
                        .addGap(44, 44, 44)
                        .addComponent(jLabel2))
                    .addGroup(jpVaga2Layout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(jLabel8)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jLvaga1, javax.swing.GroupLayout.PREFERRED_SIZE, 59, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jpVaga2Layout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(jLStatus1, javax.swing.GroupLayout.DEFAULT_SIZE, 110, Short.MAX_VALUE)))
                .addContainerGap())
        );
        jpVaga2Layout.setVerticalGroup(
            jpVaga2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jpVaga2Layout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addGroup(jpVaga2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(jLabel8)
                    .addComponent(jLvaga1, javax.swing.GroupLayout.PREFERRED_SIZE, 14, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jLabel2)
                .addGap(11, 11, 11)
                .addComponent(jLStatus1)
                .addContainerGap())
        );

        jpVaga3.setBackground(new java.awt.Color(102, 102, 102));
        jpVaga3.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));

        jLabel3.setIcon(new javax.swing.ImageIcon(getClass().getResource("/img/car.jpg"))); // NOI18N

        jLStatus2.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLStatus2.setText("ESPERANDO...");

        jLabel9.setText("ID VAGA:");

        javax.swing.GroupLayout jpVaga3Layout = new javax.swing.GroupLayout(jpVaga3);
        jpVaga3.setLayout(jpVaga3Layout);
        jpVaga3Layout.setHorizontalGroup(
            jpVaga3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jpVaga3Layout.createSequentialGroup()
                .addGroup(jpVaga3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jpVaga3Layout.createSequentialGroup()
                        .addGap(44, 44, 44)
                        .addComponent(jLabel3))
                    .addGroup(jpVaga3Layout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(jLabel9)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jLvaga2, javax.swing.GroupLayout.PREFERRED_SIZE, 59, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jpVaga3Layout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(jLStatus2, javax.swing.GroupLayout.DEFAULT_SIZE, 110, Short.MAX_VALUE)))
                .addContainerGap())
        );
        jpVaga3Layout.setVerticalGroup(
            jpVaga3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jpVaga3Layout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addGroup(jpVaga3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(jLabel9)
                    .addComponent(jLvaga2, javax.swing.GroupLayout.PREFERRED_SIZE, 14, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jLabel3)
                .addGap(11, 11, 11)
                .addComponent(jLStatus2)
                .addContainerGap())
        );

        javax.swing.GroupLayout jpMainLayout = new javax.swing.GroupLayout(jpMain);
        jpMain.setLayout(jpMainLayout);
        jpMainLayout.setHorizontalGroup(
            jpMainLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jpMainLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jpVaga1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jpVaga2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jpVaga3, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        jpMainLayout.setVerticalGroup(
            jpMainLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jpMainLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jpMainLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jpVaga3, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jpVaga2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jpVaga1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        jbDisconnect.setText("Desconectar");
        jbDisconnect.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jbDisconnectActionPerformed(evt);
            }
        });

        jbRequest.setText("Solicitar Vaga");
        jbRequest.setEnabled(false);
        jbRequest.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jbRequestActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout MainPanelLayout = new javax.swing.GroupLayout(MainPanel);
        MainPanel.setLayout(MainPanelLayout);
        MainPanelLayout.setHorizontalGroup(
            MainPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, MainPanelLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(MainPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, 432, Short.MAX_VALUE)
                    .addComponent(jpMain, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(javax.swing.GroupLayout.Alignment.LEADING, MainPanelLayout.createSequentialGroup()
                        .addComponent(jbConnect)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jbDisconnect)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 159, Short.MAX_VALUE)
                        .addComponent(jbRequest)))
                .addContainerGap())
        );
        MainPanelLayout.setVerticalGroup(
            MainPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(MainPanelLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(MainPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jbConnect)
                    .addComponent(jbDisconnect)
                    .addComponent(jbRequest))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jpMain, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 106, Short.MAX_VALUE)
                .addContainerGap())
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(MainPanel, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(MainPanel, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jbConnectActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jbConnectActionPerformed
        try {
            con.abrir("COM3", 9600);
            Logger.setText("Conectado!");
            jbRequest.setEnabled(true);
            xb = con.getXb();

            cv = new CheckVaga(jLStatus, jLIDvaga, jpVaga1, xb, Logger);
            cv.start();


        } catch (XBeeException ex) {
            Logger.setText("Problemas na conexao!");
        }
    }//GEN-LAST:event_jbConnectActionPerformed

    private void jbDisconnectActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jbDisconnectActionPerformed
        if (xb.isConnected()) {
            cv.setActive(false);
            jpVaga1.setBackground(Color.GRAY);
            jLIDvaga.setText("");
            jLStatus.setText("ESPERANDO...");
            con.fechar();
            Logger.setText("Descontectado!");
        }
    }//GEN-LAST:event_jbDisconnectActionPerformed

    private void jbRequestActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jbRequestActionPerformed
        if (cv.isVerde()) {
            cv.setInicio(System.currentTimeMillis());
            cv.setESTADO_NORMAL(false);
        } else {
            JOptionPane.showMessageDialog(jpMain, "A VAGA JA ESTA OCUPADA!", "ALERTA", JOptionPane.ERROR_MESSAGE);
        }
    }//GEN-LAST:event_jbRequestActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {

            public void run() {
                new BeecarFrameView().setVisible(true);
            }
        });
    }
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTextArea Logger;
    private javax.swing.JPanel MainPanel;
    private javax.swing.JLabel jLIDvaga;
    private javax.swing.JLabel jLStatus;
    private javax.swing.JLabel jLStatus1;
    private javax.swing.JLabel jLStatus2;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JLabel jLvaga1;
    private javax.swing.JLabel jLvaga2;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JButton jbConnect;
    private javax.swing.JButton jbDisconnect;
    private javax.swing.JButton jbRequest;
    private javax.swing.JPanel jpMain;
    private javax.swing.JPanel jpVaga1;
    private javax.swing.JPanel jpVaga2;
    private javax.swing.JPanel jpVaga3;
    // End of variables declaration//GEN-END:variables
}