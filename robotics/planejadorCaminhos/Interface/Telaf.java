/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * Telaf.java
 *
 * Created on 30/11/2010, 10:40:42
 */

package introducaoRobotica.planejadorCaminhos.Interface;

import introducaoRobotica.planejadorCaminhos.ulti.Espaco;
import introducaoRobotica.planejadorCaminhos.ulti.Poligono;
import introducaoRobotica.planejadorCaminhos.ulti.Ponto;
import java.util.ArrayList;

/**
 *
 * @author cynthia
 */
public class Telaf extends javax.swing.JFrame {

    /** Creates new form Telaf */
    public Telaf() {
        initComponents();
        iniFlag();        
    }

    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jToggleButton1 = new javax.swing.JToggleButton();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        nVertices = new javax.swing.JTextField();
        bVertices = new javax.swing.JButton();
        jSeparator2 = new javax.swing.JSeparator();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        pX = new javax.swing.JTextField();
        jLabel5 = new javax.swing.JLabel();
        pY = new javax.swing.JTextField();
        bPontos = new javax.swing.JButton();
        flag = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        jLabel8 = new javax.swing.JLabel();
        jLabel9 = new javax.swing.JLabel();
        iniX = new javax.swing.JTextField();
        jLabel10 = new javax.swing.JLabel();
        iniY = new javax.swing.JTextField();
        jLabel11 = new javax.swing.JLabel();
        jLabel12 = new javax.swing.JLabel();
        fimX = new javax.swing.JTextField();
        fimY = new javax.swing.JTextField();
        jSeparator1 = new javax.swing.JSeparator();
        jSeparator3 = new javax.swing.JSeparator();
        jSeparator4 = new javax.swing.JSeparator();
        bIF = new javax.swing.JToggleButton();
        bMan = new javax.swing.JButton();

        jToggleButton1.setText("jToggleButton1");

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jLabel1.setText("Gerador de trajetória");

        jLabel2.setText("Digite o número de vértices:");

        bVertices.setText("OK");
        bVertices.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        bVertices.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                bVerticesActionPerformed(evt);
            }
        });

        jLabel3.setText("Insira os pontos dos vértices (entre 0 e 500)");

        jLabel4.setText("Ponto x:");

        jLabel5.setText("Ponto y:");

        bPontos.setText("GO!");
        bPontos.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        bPontos.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                bPontosActionPerformed(evt);
            }
        });

        flag.setText("Os pontos deste poligonos já foram inseridos!");

        jLabel6.setText("Defina as coordenadas de inicio e fim:");

        jLabel7.setText("Início");

        jLabel8.setText("Ponto  x:");

        jLabel9.setText("Fim");

        jLabel10.setText("Ponto  y:");

        iniY.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                iniYActionPerformed(evt);
            }
        });

        jLabel11.setText("Ponto  x:");

        jLabel12.setText("Ponto  y:");

        fimX.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                fimXActionPerformed(evt);
            }
        });

        fimY.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                fimYActionPerformed(evt);
            }
        });

        bIF.setText("OK");
        bIF.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                bIFActionPerformed(evt);
            }
        });

        bMan.setText("MANHATTAN");
        bMan.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                bManActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jSeparator2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(0, 0, 0)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 285, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jLabel6)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 157, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(jLabel7)
                                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                                        .addGroup(javax.swing.GroupLayout.Alignment.LEADING, layout.createSequentialGroup()
                                            .addComponent(jLabel8)
                                            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                            .addComponent(iniX))
                                        .addGroup(javax.swing.GroupLayout.Alignment.LEADING, layout.createSequentialGroup()
                                            .addComponent(jLabel10)
                                            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                            .addComponent(iniY, javax.swing.GroupLayout.PREFERRED_SIZE, 61, javax.swing.GroupLayout.PREFERRED_SIZE))))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 32, Short.MAX_VALUE)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(layout.createSequentialGroup()
                                        .addComponent(jLabel11)
                                        .addGap(18, 18, 18)
                                        .addComponent(fimX, javax.swing.GroupLayout.PREFERRED_SIZE, 64, javax.swing.GroupLayout.PREFERRED_SIZE))
                                    .addGroup(layout.createSequentialGroup()
                                        .addComponent(jLabel12)
                                        .addGap(18, 18, 18)
                                        .addComponent(fimY, javax.swing.GroupLayout.PREFERRED_SIZE, 64, javax.swing.GroupLayout.PREFERRED_SIZE))
                                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                                        .addComponent(jLabel9, javax.swing.GroupLayout.PREFERRED_SIZE, 31, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addGap(150, 150, 150)))
                                .addGap(48, 48, 48))
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                                .addGroup(layout.createSequentialGroup()
                                    .addComponent(jLabel2, javax.swing.GroupLayout.PREFERRED_SIZE, 202, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                    .addComponent(nVertices, javax.swing.GroupLayout.PREFERRED_SIZE, 54, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                    .addComponent(bVertices))
                                .addComponent(jSeparator3, javax.swing.GroupLayout.Alignment.LEADING)
                                .addComponent(jSeparator1, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, 338, Short.MAX_VALUE)
                                .addComponent(bIF))))
                    .addComponent(jSeparator4, javax.swing.GroupLayout.PREFERRED_SIZE, 350, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel3)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabel4)
                        .addGap(4, 4, 4)
                        .addComponent(pX, javax.swing.GroupLayout.PREFERRED_SIZE, 59, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(40, 40, 40)
                        .addComponent(jLabel5)
                        .addGap(3, 3, 3)
                        .addComponent(pY, javax.swing.GroupLayout.PREFERRED_SIZE, 65, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(31, 31, 31)
                        .addComponent(bPontos))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(40, 40, 40)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(bMan, javax.swing.GroupLayout.PREFERRED_SIZE, 256, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(flag))))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(77, 77, 77)
                        .addComponent(jSeparator2, javax.swing.GroupLayout.PREFERRED_SIZE, 10, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addContainerGap()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addGap(19, 19, 19)
                                .addComponent(jSeparator1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jLabel1)
                                .addGap(18, 18, 18)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                    .addComponent(jLabel2)
                                    .addComponent(bVertices, javax.swing.GroupLayout.PREFERRED_SIZE, 23, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(nVertices, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))))
                        .addGap(11, 11, 11)
                        .addComponent(jSeparator3, javax.swing.GroupLayout.PREFERRED_SIZE, 10, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jLabel6)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jLabel7)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                    .addComponent(jLabel8)
                                    .addComponent(iniX, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jLabel9)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                    .addComponent(jLabel11)
                                    .addComponent(fimX, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel10)
                            .addComponent(iniY, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel12)
                            .addComponent(fimY, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(bIF)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(jSeparator4, javax.swing.GroupLayout.PREFERRED_SIZE, 12, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(jLabel3)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel4)
                            .addComponent(pX, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel5)
                            .addComponent(pY, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(bPontos))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(flag)))
                .addGap(18, 18, 18)
                .addComponent(bMan, javax.swing.GroupLayout.DEFAULT_SIZE, 43, Short.MAX_VALUE)
                .addContainerGap())
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    int nVerticesI = 0;
    ArrayList<Poligono> poligonos = new ArrayList<Poligono>();
    Ponto ini = new Ponto(0,0);
    Ponto fim = new Ponto(0,0);
    Poligono def;
    Ponto defP;
    int i = 0;
    int j = -1;

    private void iniFlag ()
    {
        flag.setVisible(false);
    }

    private void bVerticesActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bVerticesActionPerformed
        def = new Poligono();
        nVerticesI = Integer.parseInt(nVertices.getText());
        i = 0;
        flag.setVisible(false);
        bPontos.setVisible(true);
        poligonos.add(def);
}//GEN-LAST:event_bVerticesActionPerformed

    private void bPontosActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bPontosActionPerformed
        if(i<nVerticesI)
            {
                int x = (Integer.parseInt(pX.getText()));
                int y = (Integer.parseInt(pY.getText()));
                if(x<0 || x>500)
                {
                    Alerta al = new Alerta();
                    al.setLocation(300, 300);
                    al.setVisible(true);

                }
                else if(y<0 || y>500)
                {
                    Alerta al = new Alerta();
                    al.setLocation(300, 300);
                    al.setVisible(true);
                }
                else if(x == ini.getX()&& y ==ini.getY())
                {
                    Repetido rep = new Repetido();
                    rep.setLocation(300, 300);
                    rep.setVisible(true);
                }
                else if(x == fim.getX()&& y == fim.getY())
                {
                    Repetido rep = new Repetido();
                    rep.setLocation(300, 300);
                    rep.setVisible(true);
                }
                else
                {
                    defP = new Ponto(x,y);
                    def.addVertice(defP);
                    i++;
                }
                if(i == nVerticesI)
                {
                bPontos.setVisible(false);
                flag.setVisible(true);
              //  teste();
                }
            }
}//GEN-LAST:event_bPontosActionPerformed

    private void iniYActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_iniYActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_iniYActionPerformed

    private void fimYActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_fimYActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_fimYActionPerformed

    private void fimXActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_fimXActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_fimXActionPerformed

    private void bIFActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bIFActionPerformed
        int inix = Integer.parseInt(iniX.getText());
        int iniy = Integer.parseInt(iniY.getText());
        ini.setY(inix);
        ini.setX(iniy);
        if((inix == Integer.parseInt(fimX.getText()))&&(iniy == Integer.parseInt(fimY.getText()))) {
            Repetido rep = new Repetido();
            rep.setLocation(300, 300);
            rep.setVisible(true);
        } else {
            fim.setY(Integer.parseInt(fimX.getText()));
            fim.setX(Integer.parseInt(fimY.getText()));
        }
    }//GEN-LAST:event_bIFActionPerformed

    private void bManActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bManActionPerformed

        Espaco esp = new Espaco(500, 500, ini, fim);

        for(int i=0; i< poligonos.size(); i++){
            esp.criarPoligonos(poligonos.get(i));
        }

        esp.manhattan();

        for (int i = 0 ; i < esp.getPlano().length ; i++){
            //System.out.print(i + " ");
            for (int j = 0 ; j < esp.getPlano().length ; j++){
                System.out.print(esp.getPlano()[i][j].getQ() + " ");
            }
            System.out.println();
        }
    }//GEN-LAST:event_bManActionPerformed
   private void teste()
{
    for(int i = 0; i<poligonos.size(); i++)
    {
        System.out.println("Poligonos x: "+poligonos.get(i).getVertices().get(0).getX());
        System.out.println("Poligonos y: "+poligonos.get(i).getVertices().get(0).getY());
    }
    

}
    /**
    * @param args the command line arguments
    */
    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                Telaf tel = new Telaf();
                tel.setLocation(200,200);
                tel.setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JToggleButton bIF;
    private javax.swing.JButton bMan;
    private javax.swing.JButton bPontos;
    private javax.swing.JButton bVertices;
    private javax.swing.JTextField fimX;
    private javax.swing.JTextField fimY;
    private javax.swing.JLabel flag;
    private javax.swing.JTextField iniX;
    private javax.swing.JTextField iniY;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel11;
    private javax.swing.JLabel jLabel12;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JSeparator jSeparator1;
    private javax.swing.JSeparator jSeparator2;
    private javax.swing.JSeparator jSeparator3;
    private javax.swing.JSeparator jSeparator4;
    private javax.swing.JToggleButton jToggleButton1;
    private javax.swing.JTextField nVertices;
    private javax.swing.JTextField pX;
    private javax.swing.JTextField pY;
    // End of variables declaration//GEN-END:variables

}