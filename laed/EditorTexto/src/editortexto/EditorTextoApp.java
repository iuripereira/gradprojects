/*
 * EditorTextoApp.java
 */

package editortexto;

import org.jdesktop.application.ApplicationContext;
import org.jdesktop.application.SingleFrameApplication;
import java.awt.Window;
import org.jdesktop.application.ApplicationContext;
import org.jdesktop.application.SingleFrameApplication;

/**
 * The main class of the application.
 */
public class EditorTextoApp extends SingleFrameApplication {

    /**
     * At startup create and show the main frame of the application.
     */
    @Override protected void startup() {
       setMainFrame(new EditorTextoFrame());
       show(getMainFrame());
    }

    /**
     * This method is to initialize the specified window by injecting resources.
     * Windows shown in our application come fully initialized from the GUI
     * builder, so this additional configuration is not needed.
     */
    @Override protected void configureWindow(Window root) {
    }

    /**
     * A convenient static getter for the application instance.
     * @return the instance of EditorTextoApp
     */
    public static EditorTextoApp getApplication() {
        return (EditorTextoApp) ApplicationContext.getInstance().getApplication();
    }

    /**
     * Main method launching the application.
     */
    public static void main(String[] args) {
        launch(EditorTextoApp.class, args);
    }
}
