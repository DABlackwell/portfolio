/**
 * Author:		Daniel Brooks
 * ID: 			269416
 * 
 * Description: This program allows the user to enter a list of characters;
 * 				the program then displays the number of uppercase letters
 * 				in the list.	
 */

/**
 * PSEUDOCODE:
 * 1)	Create a BorderPane interface which contains a text field with
 * 		a label, a submit button, and a text with a label.
 * 2)	Create a listener which accepts user input in the text field.
 * 3)	Process the user input by:
 * 			a)	converting the string to a char array;
 * 			b)	counting the uppercase characters in the entered text
 * 				using a recursive helper method. The helper method will
 * 				determine how many characters remain to be searched.
 */

package brooks18;

import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ContentDisplay;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.StackPane;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class Exercise18_16 extends Application {
	public static int uppercaseCount = 0; 
	@Override // Overrides the start method in the Application class
	public void start(Stage primaryStage) {
		// Create a text field with a label & a submit button
		TextField tfUserInput = new TextField();
		tfUserInput.setPrefWidth(250);
		Label lblUserInput = new Label("Enter a list of characters: ",
			tfUserInput);
		lblUserInput.setContentDisplay(ContentDisplay.RIGHT);
		lblUserInput.setPadding(new Insets(10));
		Button btSubmit = new Button("Submit");

		// Create an HBox for the text field & button
		HBox hBox = new HBox();
		hBox.getChildren().addAll(lblUserInput, btSubmit);
		hBox.setAlignment(Pos.CENTER);
		
		// Create a text with a label in a pane
		StackPane charCountPane = new StackPane();
		charCountPane.setPadding(new Insets(5, 0, 15, 0));
		Text charCountText = new Text("0");
		Label lblCharCount = new Label(
			"Number of uppercase characters in this string:", charCountText);
		lblCharCount.setContentDisplay(ContentDisplay.RIGHT);
		charCountPane.getChildren().add(lblCharCount);
		
		// Create a BorderPane & place nodes in the pane
		BorderPane borderPane = new BorderPane();
		borderPane.setCenter(hBox);
		borderPane.setBottom(charCountPane);
		
		// Create a scene and add it to the stage
		Scene scene = new Scene(borderPane, 540, 80);
		primaryStage.setScene(scene);
		primaryStage.setTitle("Brooks_Exercise18_16"); // Set the stage title
		primaryStage.show(); // Display the stage
		
		// Create a listener for the text field calling the count method
		btSubmit.setOnAction(e -> {
			uppercaseCount = 0;
			char[] chars = tfUserInput.getText().toCharArray();
			charCountText.setText(String.valueOf(count(chars)));
		});
	}
	
	/** Main method */
	public static void main(String[] args) {
		Application.launch(args);
	}
	
	public static int count(char[] chars) {
		int high = chars.length;
		return count(chars, high);
	}
	
	/** recursive helper method */
	public static int count(char[] chars, int high) {
		if (high == 0) {
			return uppercaseCount;
		}
		else {
			// Check for uppercase char at chars[high]
			if (chars[high - 1] >= 'A' && (chars[high - 1]) <= 'Z')
				uppercaseCount++;
				high -= 1;
			return count(chars, high);
		}
	}
}
