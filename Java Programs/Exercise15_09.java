package brooks15;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Line;
import javafx.stage.Stage;

public class Exercise15_09 extends Application {
	// Daniel Brooks 269416
	
	/** PSEUDOCODE
	1) Create an Application class
	2) Create a pane
	3) Set a cursor point variable
	4) Create or extend the line when an arrow key is pressed
		in the direction of the arrow key
	5) Create a scene and place it in the stage
	6) Request focus on pane
	7) Create a main method to launch the Application class
	*/

	@Override // Override the start method in the Application class
	public void start(Stage primaryStage) {
		// Create a pane
		Pane pane = new Pane();

		// Set control line for beginning x & y coordinates
		Line control = new Line();
		control.setStartX(250);
		control.setStartY(175);

		// Draw a line when an arrow key is pressed
		pane.setOnKeyPressed(e -> {
			Line line = new Line(control.getStartX(), control.getStartY(), 0, 0);
			line.setStrokeWidth(3);
			switch (e.getCode()) {
				case RIGHT:
					if (line.getStartX() >= pane.getWidth() - 10)
						line.setEndX(control.getStartX());
					else
						line.setEndX(control.getStartX() + 3);
					line.setEndY(control.getStartY());
					line.setStroke(Color.RED);
					pane.getChildren().add(line);
					control.setStartX(line.getEndX());
					break;
				case LEFT:
					if (line.getStartX() <= 10)
						line.setEndX(control.getStartX());
					else
						line.setEndX(control.getStartX() - 3);
					line.setEndY(control.getStartY());
					line.setStroke(Color.GREEN);
					pane.getChildren().add(line);
					control.setStartX(line.getEndX());
					break;
				case UP:
					if (line.getStartY() <= 10)
						line.setEndY(control.getStartY());
					else
						line.setEndY(control.getStartY() - 3);
					line.setEndX(control.getStartX());
					line.setStroke(Color.BLACK);
					pane.getChildren().add(line);
					control.setStartY(line.getEndY());
					break;
				case DOWN:
					if (line.getStartY() >= pane.getHeight() - 10)
						line.setEndY(control.getStartY());
					else
						line.setEndY(control.getStartY() + 3);
					line.setEndX(control.getStartX());
					line.setStroke(Color.BLUE);
					pane.getChildren().add(line);
					control.setStartY(line.getEndY());
					break;
				case Q: System.exit(0);
				default: System.out.println("Invalid key");; break;
			}
		});
		
		// Create a scene and place it in the stage
		Scene scene = new Scene(pane, 500, 350);
		primaryStage.setTitle("Exercise15_09"); // Set the stage title
		primaryStage.setScene(scene); // Place the scene in the stage
		primaryStage.show(); // Display the stage
		
		pane.requestFocus(); // Request focus on pane
	}
	
	// Main method
	public static void main(String[] args) {
		Application.launch(args);
	}
}
