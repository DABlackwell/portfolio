 /** 
 * Author:		Daniel Brooks
 * ID: 			269416
 * 
 * Description: This program asks the user to enter a state and then
 * 				returns both the state's capital and the state flag.
 * 				The program uses a map for the states and capitals.
 */

/**
 * PSEUDOCODE:
 * 1)	Create a user interface using a BorderPane containing:
 * 			a) an ComboBox for selecting a state;
 * 			b) a Text with the capital name of the selected state;
 * 			c) an ImageView for the state flag.
 * 2)	Create a listener for the ComboBox which retrieves the
 * 		capital from the map using the user-selected state as a key.
 * 3)	Create a map of the states and capitals from an array
		and a method that for-each loops through the map to look for
		the state and return the capital. 
 */

package brooks21;

import java.util.*;
import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.scene.text.TextAlignment;
import javafx.stage.Stage;

public class Exercise21_09 extends Application {
	@Override // Overrides the start method in the Application class
	public void start(Stage primaryStage) {
		// State capital array
		String[][] capitalArray = {
			{"Alabama", "Alaska", "Arizona", "Arkansas", "California",
				"Colorado", "Connecticut", "Delaware", "Florida", "Georgia",
				"Hawaii", "Idaho", "Illinois", "Indiana", "Iowa", "Kansas",
				"Kentucky", "Louisiana", "Maine", "Maryland", "Massachusetts",
				"Michigan", "Minnesota", "Mississippi", "Missouri", "Montana",
				"Nebraska", "Nevada", "New Hampshire", "New Jersey",
				"New Mexico", "New York", "North Carolina", "North Dakota",
				"Ohio", "Oklahoma", "Oregon", "Pennsylvania", "Rhode Island",
				"South Carolina", "South Dakota", "Tennessee", "Texas",
				"Utah", "Vermont", "Virginia", "Washington", "West Virginia",
				"Wisconsin", "Wyoming"},
			{"Montgomery", "Juneau", "Phoenix", "Little Rock", "Sacramento",
				"Denver", "Hartford", "Dover", "Tallahassee", "Atlanta",
				"Honolulu", "Boise", "Springfield", "Indianapolis",
				"Des Moines", "Topeka", "Frankfort", "Baton Rouge", "Augusta",
				"Annapolis", "Boston", "Lansing", "Saint Paul", "Jackson",
				"Jefferson City", "Helena", "Lincoln", "Carson City", "Concord",
				"Trenton", "Santa Fe", "Albany", "Raleigh", "Bismarck",
				"Columbus", "Oklahoma City", "Salem", "Harrisburg",
				"Providence", "Columbia", "Pierre", "Nashville", "Austin",
				"Salt Lake City", "Montpelier", "Richmond", "Olympia",
				"Charleston", "Madison", "Cheyenne"}
		};
		
		// Create a HashMap & ComboBox & enter fields from array
		Map<String, String> stateHash = new HashMap<>();
		ComboBox<String> cboStates = new ComboBox<>();
		for (int i = 0; i < capitalArray[0].length; i++) {
			stateHash.put(capitalArray[0][i], capitalArray[1][i]);
			cboStates.getItems().add(capitalArray[0][i]);
		}
		
		
		/** USER INTERFACE */
		// Text and ComboBox in HBox
		Text txt = new Text("Select a state: ");
		HBox hBox = new HBox();
		hBox.setPadding(new Insets(15));
		hBox.setSpacing(5);
		hBox.setAlignment(Pos.CENTER);
		hBox.getChildren().addAll(txt, cboStates);

		// Text for capital
		Text capital = new Text(""); // Placeholder text; no input yet
		capital.setFont(Font.font("serif", 18));
		capital.setTextAlignment(TextAlignment.CENTER);
		
		// Label for flag image
		Label flag = new Label();
		flag.setPadding(new Insets(5, 5, 25, 5));

		// Border pane to hold it all
		BorderPane borderPane = new BorderPane();
		borderPane.setTop(hBox);
		borderPane.setCenter(capital);
		borderPane.setBottom(flag);
		BorderPane.setAlignment(flag, Pos.CENTER);

		
		// Listener for ComboBox
		cboStates.setOnAction(e -> {
			String state = cboStates.getValue();
			capital.setText("The capital of " + state + " is " +
				stateHash.get(state) + "\nand this is the state flag:");
			flag.setGraphic(new ImageView(
					new Image("flags/" + state + ".png")));
		});
		
		// Set the scene and place it in the stage
		Scene scene = new Scene(borderPane, 360, 240);
		primaryStage.setScene(scene);
		primaryStage.setTitle("Exercise21_09"); // Set the stage title
		primaryStage.show(); // Display the stage
	}
	
	/** Main method */
	public static void main(String[] args) {
		Application.launch(args);
	}
}
