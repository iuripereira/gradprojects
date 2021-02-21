/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * Configuracao.java
 *
 * Created on 09/12/2010, 09:15:34
 */

package introducaoRobotica.planejadorCaminhos.Interface;

import introducaoRobotica.planejadorCaminhos.ulti.Espaco;
import introducaoRobotica.planejadorCaminhos.ulti.Poligono;
import introducaoRobotica.planejadorCaminhos.ulti.Ponto;
import java.awt.Color;
import java.awt.Graphics;
import java.util.ArrayList;
import java.util.Collection;
import javax.swing.JFrame;

/**
 *
 * @author RodrigoSwars
 */
public class Configuracao extends javax.swing.JFrame {

    private int numeroDePoligonos;
    private int numeroDeVertices;
    private Poligono poligono = new Poligono();
    public Espaco espaco;
    private ArrayList<Poligono> aPoligonos = new ArrayList<Poligono>();
    private Ponto vertice;

    /** Creates new form Configuracao */
    public Configuracao() {
        initComponents();
        desabilitar();
    }

    public void paintComponent(Graphics g){
        super.paintComponents(g);
    }

    private void desabilitar(){
        this.numeroVertices.setEnabled(false);
        this.valorX.setEnabled(false);
        this.valorY.setEnabled(false);
        this.jLabel2.setEnabled(false);
        this.jLabel3.setEnabled(false);
        this.jLabel4.setEnabled(false);
        this.nVerticesButton.setEnabled(false);
        this.xyButton.setEnabled(false);
    }

    private void criarVertices(){

    }

    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {
        java.awt.GridBagConstraints gridBagConstraints;

        jPanel1 = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        numeroPoligonos = new javax.swing.JTextField();
        poligonosButton = new javax.swing.JButton();
        jLabel2 = new javax.swing.JLabel();
        valorX = new javax.swing.JTextField();
        jLabel3 = new javax.swing.JLabel();
        valorY = new javax.swing.JTextField();
        xyButton = new javax.swing.JButton();
        jSeparator1 = new javax.swing.JSeparator();
        jLabel4 = new javax.swing.JLabel();
        numeroVertices = new javax.swing.JTextField();
        nVerticesButton = new javax.swing.JButton();
        jLabel5 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        jLabel8 = new javax.swing.JLabel();
        jLabel9 = new javax.swing.JLabel();
        jLabel10 = new javax.swing.JLabel();
        pIYText = new javax.swing.JTextField();
        pFYText = new javax.swing.JTextField();
        pIXText = new javax.swing.JTextField();
        pFXText = new javax.swing.JTextField();
        jSeparator2 = new javax.swing.JSeparator();
        manhattanButton = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jPanel1.setLayout(new java.awt.GridBagLayout());

        jLabel1.setText("Número de Polígonos:");
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.anchor = java.awt.GridBagConstraints.WEST;
        gridBagConstraints.insets = new java.awt.Insets(5, 5, 5, 5);
        jPanel1.add(jLabel1, gridBagConstraints);
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.fill = java.awt.GridBagConstraints.HORIZONTAL;
        gridBagConstraints.ipadx = 50;
        gridBagConstraints.weightx = 20.0;
        gridBagConstraints.insets = new java.awt.Insets(5, 5, 5, 5);
        jPanel1.add(numeroPoligonos, gridBagConstraints);

        poligonosButton.setText("OK");
        poligonosButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                poligonosButtonActionPerformed(evt);
            }
        });
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.fill = java.awt.GridBagConstraints.HORIZONTAL;
        gridBagConstraints.ipadx = 5;
        gridBagConstraints.insets = new java.awt.Insets(5, 5, 5, 5);
        jPanel1.add(poligonosButton, gridBagConstraints);

        jLabel2.setText("Valor X:");
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 0;
        gridBagConstraints.gridy = 3;
        gridBagConstraints.anchor = java.awt.GridBagConstraints.WEST;
        gridBagConstraints.insets = new java.awt.Insets(5, 5, 5, 5);
        jPanel1.add(jLabel2, gridBagConstraints);
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 1;
        gridBagConstraints.gridy = 3;
        gridBagConstraints.ipadx = 50;
        gridBagConstraints.insets = new java.awt.Insets(5, 5, 5, 5);
        jPanel1.add(valorX, gridBagConstraints);

        jLabel3.setText("Valor Y:");
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 0;
        gridBagConstraints.gridy = 4;
        gridBagConstraints.anchor = java.awt.GridBagConstraints.WEST;
        gridBagConstraints.insets = new java.awt.Insets(5, 5, 5, 5);
        jPanel1.add(jLabel3, gridBagConstraints);
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 1;
        gridBagConstraints.gridy = 4;
        gridBagConstraints.ipadx = 50;
        gridBagConstraints.insets = new java.awt.Insets(5, 5, 5, 5);
        jPanel1.add(valorY, gridBagConstraints);

        xyButton.setText("OK");
        xyButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                xyButtonActionPerformed(evt);
            }
        });
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 2;
        gridBagConstraints.gridy = 3;
        gridBagConstraints.gridheight = 2;
        gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
        gridBagConstraints.ipadx = 5;
        gridBagConstraints.insets = new java.awt.Insets(5, 5, 5, 5);
        jPanel1.add(xyButton, gridBagConstraints);
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 0;
        gridBagConstraints.gridy = 1;
        gridBagConstraints.gridwidth = 3;
        gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
        gridBagConstraints.insets = new java.awt.Insets(5, 5, 5, 5);
        jPanel1.add(jSeparator1, gridBagConstraints);

        jLabel4.setText("Número de Vertices:");
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 0;
        gridBagConstraints.gridy = 2;
        gridBagConstraints.anchor = java.awt.GridBagConstraints.WEST;
        gridBagConstraints.insets = new java.awt.Insets(5, 5, 5, 5);
        jPanel1.add(jLabel4, gridBagConstraints);
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 1;
        gridBagConstraints.gridy = 2;
        gridBagConstraints.ipadx = 50;
        gridBagConstraints.insets = new java.awt.Insets(5, 5, 5, 5);
        jPanel1.add(numeroVertices, gridBagConstraints);

        nVerticesButton.setText("OK");
        nVerticesButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                nVerticesButtonActionPerformed(evt);
            }
        });
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 2;
        gridBagConstraints.gridy = 2;
        gridBagConstraints.insets = new java.awt.Insets(5, 5, 5, 5);
        jPanel1.add(nVerticesButton, gridBagConstraints);

        jLabel5.setText("Ponto Inicial");
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 4;
        gridBagConstraints.gridy = 0;
        gridBagConstraints.gridwidth = 2;
        gridBagConstraints.insets = new java.awt.Insets(5, 5, 5, 5);
        jPanel1.add(jLabel5, gridBagConstraints);

        jLabel6.setText("X:");
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 4;
        gridBagConstraints.gridy = 1;
        gridBagConstraints.anchor = java.awt.GridBagConstraints.EAST;
        gridBagConstraints.insets = new java.awt.Insets(5, 5, 5, 5);
        jPanel1.add(jLabel6, gridBagConstraints);

        jLabel7.setText("Y:");
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 4;
        gridBagConstraints.gridy = 2;
        gridBagConstraints.anchor = java.awt.GridBagConstraints.EAST;
        gridBagConstraints.insets = new java.awt.Insets(5, 5, 5, 5);
        jPanel1.add(jLabel7, gridBagConstraints);

        jLabel8.setText("Ponto Final");
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 6;
        gridBagConstraints.gridy = 0;
        gridBagConstraints.gridwidth = 2;
        gridBagConstraints.insets = new java.awt.Insets(5, 5, 5, 5);
        jPanel1.add(jLabel8, gridBagConstraints);

        jLabel9.setText("X:");
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 6;
        gridBagConstraints.gridy = 1;
        gridBagConstraints.anchor = java.awt.GridBagConstraints.EAST;
        gridBagConstraints.insets = new java.awt.Insets(5, 5, 5, 5);
        jPanel1.add(jLabel9, gridBagConstraints);

        jLabel10.setText("Y:");
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 6;
        gridBagConstraints.gridy = 2;
        gridBagConstraints.anchor = java.awt.GridBagConstraints.EAST;
        gridBagConstraints.insets = new java.awt.Insets(5, 5, 5, 5);
        jPanel1.add(jLabel10, gridBagConstraints);
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 5;
        gridBagConstraints.gridy = 1;
        gridBagConstraints.ipadx = 50;
        gridBagConstraints.anchor = java.awt.GridBagConstraints.WEST;
        gridBagConstraints.insets = new java.awt.Insets(5, 5, 5, 5);
        jPanel1.add(pIYText, gridBagConstraints);
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 7;
        gridBagConstraints.gridy = 1;
        gridBagConstraints.ipadx = 50;
        gridBagConstraints.insets = new java.awt.Insets(5, 5, 5, 5);
        jPanel1.add(pFYText, gridBagConstraints);
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 5;
        gridBagConstraints.gridy = 2;
        gridBagConstraints.ipadx = 50;
        gridBagConstraints.anchor = java.awt.GridBagConstraints.WEST;
        gridBagConstraints.insets = new java.awt.Insets(5, 5, 5, 5);
        jPanel1.add(pIXText, gridBagConstraints);
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 7;
        gridBagConstraints.gridy = 2;
        gridBagConstraints.ipadx = 50;
        gridBagConstraints.insets = new java.awt.Insets(5, 5, 5, 5);
        jPanel1.add(pFXText, gridBagConstraints);
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 3;
        gridBagConstraints.gridy = 0;
        gridBagConstraints.gridheight = 5;
        gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
        gridBagConstraints.insets = new java.awt.Insets(10, 10, 10, 10);
        jPanel1.add(jSeparator2, gridBagConstraints);

        manhattanButton.setText("Manhattan");
        manhattanButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                manhattanButtonActionPerformed(evt);
            }
        });
        gridBagConstraints = new java.awt.GridBagConstraints();
        gridBagConstraints.gridx = 4;
        gridBagConstraints.gridy = 3;
        gridBagConstraints.gridwidth = 4;
        gridBagConstraints.gridheight = 2;
        gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
        gridBagConstraints.insets = new java.awt.Insets(5, 5, 5, 5);
        jPanel1.add(manhattanButton, gridBagConstraints);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 507, Short.MAX_VALUE)
            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(layout.createSequentialGroup()
                    .addGap(0, 36, Short.MAX_VALUE)
                    .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGap(0, 37, Short.MAX_VALUE)))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 308, Short.MAX_VALUE)
            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                .addGroup(layout.createSequentialGroup()
                    .addGap(0, 76, Short.MAX_VALUE)
                    .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGap(0, 76, Short.MAX_VALUE)))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void poligonosButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_poligonosButtonActionPerformed
        // TODO add your handling code here:
        if (numeroPoligonos.getText().isEmpty()){

        }
        else {
            this.numeroDePoligonos = Integer.parseInt(numeroPoligonos.getText());
            this.numeroVertices.setEnabled(true);
            this.jLabel4.setEnabled(true);
            this.nVerticesButton.setEnabled(true);
        }
    }//GEN-LAST:event_poligonosButtonActionPerformed

    private void nVerticesButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_nVerticesButtonActionPerformed
        // TODO add your handling code here:
        if (numeroVertices.getText().isEmpty()){

        }
        else {
            this.numeroDeVertices = Integer.parseInt(numeroVertices.getText());
            this.valorX.setEnabled(true);
            this.valorY.setEnabled(true);
            this.jLabel2.setEnabled(true);
            this.jLabel3.setEnabled(true);
            this.xyButton.setEnabled(true);
        }
    }//GEN-LAST:event_nVerticesButtonActionPerformed

    private void xyButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_xyButtonActionPerformed

        if (numeroDeVertices > 0) {
            Ponto v = new Ponto(Integer.parseInt(valorX.getText()), Integer.parseInt(valorY.getText()));
            this.poligono.addVertice(v);
            valorX.setText(null);
            valorY.setText(null);
            numeroDeVertices--;
            if (numeroDeVertices == 0) {
                this.valorX.setEnabled(false);
                this.valorY.setEnabled(false);
                this.jLabel2.setEnabled(false);
                this.jLabel3.setEnabled(false);
                this.xyButton.setEnabled(false);
                Poligono aux = new Poligono();
                for (int i = 0 ; i < poligono.getVertices().size() ; i++){
                    aux.addVertice(poligono.getVertice(i));
                }
                this.aPoligonos.add(aux);
                poligono.clear();
                numeroDePoligonos--;
                if (numeroDePoligonos == 0){
                    this.jLabel1.setEnabled(false);
                    this.numeroPoligonos.setEnabled(false);
                    this.poligonosButton.setEnabled(false);
                    this.numeroVertices.setEnabled(false);
                    this.jLabel4.setEnabled(false);
                    this.nVerticesButton.setEnabled(false);
                }
            }
        }
    }//GEN-LAST:event_xyButtonActionPerformed

    private void manhattanButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_manhattanButtonActionPerformed
        // TODO add your handling code here:
        if (pIXText.getText().isEmpty() || pIYText.getText().isEmpty() || pFXText.getText().isEmpty() || pFYText.getText().isEmpty()){

        }
        else {
            this.espaco = new Espaco(500, 500, new Ponto(Integer.parseInt(pIXText.getText()), Integer.parseInt(pIYText.getText())), new Ponto(Integer.parseInt(pFXText.getText()), Integer.parseInt(pFYText.getText())));
            for (int i = 0 ; i < aPoligonos.size() ; i++){
                espaco.criarPoligonos(aPoligonos.get(i));
            }
            espaco.manhattan();
        }

        JFrame frame = new JFrame("ESPAÇO DE CONFIGURAÇÃO");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        //Rentangulo rect = null;
        for (int i = 0 ; i < espaco.getPlano().length ; i++){
            for (int j = 0 ; j < espaco.getPlano().length ; j++ ){
                //if (espaco.getPlano()[i][j])
                Rentangulo rect = new Rentangulo();
                frame.add(rect);
            }
        }
        frame.setSize(500, 500);
        frame.setVisible(true);
    }//GEN-LAST:event_manhattanButtonActionPerformed

    /**
    * @param args the command line arguments
    */
    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Configuracao().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JSeparator jSeparator1;
    private javax.swing.JSeparator jSeparator2;
    private javax.swing.JButton manhattanButton;
    private javax.swing.JButton nVerticesButton;
    private javax.swing.JTextField numeroPoligonos;
    private javax.swing.JTextField numeroVertices;
    private javax.swing.JTextField pFXText;
    private javax.swing.JTextField pFYText;
    private javax.swing.JTextField pIXText;
    private javax.swing.JTextField pIYText;
    private javax.swing.JButton poligonosButton;
    private javax.swing.JTextField valorX;
    private javax.swing.JTextField valorY;
    private javax.swing.JButton xyButton;
    // End of variables declaration//GEN-END:variables

}