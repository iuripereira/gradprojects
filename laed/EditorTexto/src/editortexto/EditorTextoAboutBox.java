/*
 * EditorTextoAboutBox.java
 */

package editortexto;

import application.Action;
import application.Application;
import application.ResourceMap;
import java.awt.Desktop.Action;

public class EditorTextoAboutBox extends javax.swing.JDialog {

    public EditorTextoAboutBox(java.awt.Frame parent) {
        super(parent);
        initComponents();
        getRootPane().setDefaultButton(closeButton);
    }

    @Action public void closeAboutBox() {
        setVisible(false);
    }

    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    // <editor-fold defaultstate="collapsed" desc=" Generated Code ">//GEN-BEGIN:initComponents
    private void initComponents() {

        aboutLabel = new javax.swing.JLabel();
        closeButton = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        setTitle(application.ApplicationContext.getInstance().getResourceMap(editortexto.EditorTextoAboutBox.class).getString("title")); // NOI18N
        setName("aboutBox"); // NOI18N
        setResizable(false);

        aboutLabel.setHorizontalAlignment(javax.swing.SwingConstants.LEFT);
        aboutLabel.setIcon(application.ApplicationContext.getInstance().getResourceMap(editortexto.EditorTextoAboutBox.class).getIcon("aboutLabel.icon")); // NOI18N
        aboutLabel.setVerticalAlignment(javax.swing.SwingConstants.TOP);

        closeButton.setAction(application.ApplicationContext.getInstance().getActionMap(editortexto.EditorTextoAboutBox.class, this).get("closeAboutBox"));

        org.jdesktop.layout.GroupLayout layout = new org.jdesktop.layout.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(aboutLabel, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, 375, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE)
            .add(org.jdesktop.layout.GroupLayout.TRAILING, layout.createSequentialGroup()
                .addContainerGap(304, Short.MAX_VALUE)
                .add(closeButton)
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(org.jdesktop.layout.GroupLayout.LEADING)
            .add(layout.createSequentialGroup()
                .add(aboutLabel, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE, 283, org.jdesktop.layout.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(org.jdesktop.layout.LayoutStyle.RELATED, 14, Short.MAX_VALUE)
                .add(closeButton)
                .addContainerGap())
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents
    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel aboutLabel;
    private javax.swing.JButton closeButton;
    // End of variables declaration//GEN-END:variables
    
}
