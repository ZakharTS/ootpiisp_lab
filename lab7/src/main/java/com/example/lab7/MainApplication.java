package com.example.lab7;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.*;
import javafx.stage.Stage;

import java.io.IOException;
import java.util.Random;

/*Напишите программу, которая находит в массиве 10х10 числа делимые на 2, 3, 4, 5 и 6.
Создайте интерфейс программы: в таблице 10х10 числа получить случайным образом; создать кнопки выполняемых действий;
результат действий подсвечивать цветом; в поле надписи выводить количество найденных чисел.*/

public class MainApplication extends Application {
    static Stage primaryStage;
    static BorderPane rootLayout;
    static Pane panes[][];
    static Label labels[][];
    static Button buttons[];
    static Label counter;
    static String WHITE_STYLE = "-fx-background-color: rgb(255,255,255);";
    static String SELECTED_STYLE = "-fx-background-color: rgb(232, 229, 132);";

    @Override
    public void start(Stage stage) throws IOException, InterruptedException {
        stage.setTitle("App");
        primaryStage = stage;
        Random rand = new Random();

        initRootLayout();
        panes = new Pane[10][10];
        labels = new Label[10][10];
        FXMLLoader fxmlLoader = new FXMLLoader(MainApplication.class.getResource("main-view.fxml"));
        GridPane boardGrid = fxmlLoader.load();
        for (Node node : boardGrid.getChildren()) {
            Integer rowObj = GridPane.getRowIndex(node);
            Integer colObj = GridPane.getColumnIndex(node);

            int row = rowObj == null ? 0 : rowObj;
            int col = colObj == null ? 0 : colObj;
            if (node instanceof Pane) {
                panes[row][col] = (Pane) node;
                labels[row][col] = new Label("123");
                labels[row][col].setText(Integer.toString(rand.nextInt(200)));
                labels[row][col].setStyle("-fx-font-size: 20px");
                panes[row][col].getChildren().add(labels[row][col]);
            }
        }
        rootLayout.setCenter(boardGrid);
    }

    public void initRootLayout() throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(MainApplication.class.getResource("root-layout-view.fxml"));
        rootLayout = fxmlLoader.load();
        primaryStage.setScene(new Scene(rootLayout));
        primaryStage.show();

        HBox header = new HBox();

        var handler = new EventHandler<ActionEvent>() {

            @Override
            public void handle(ActionEvent actionEvent) {
                if (actionEvent.getSource() instanceof Button) {
                    Button cur = (Button) actionEvent.getSource();
                    switch (cur.getText()) {
                        case "2", "3", "4", "5", "6" -> {
                            for (int i = 0; i < 10; i++) {
                                for (int j = 0; j < 10; j++) {
                                    if (Integer.parseInt(labels[i][j].getText()) % Integer.parseInt(cur.getText()) == 0) {
                                        panes[i][j].setStyle(SELECTED_STYLE);
                                    } else {
                                        panes[i][j].setStyle(WHITE_STYLE);
                                    }
                                }
                            }
                        }
                        case "Update" -> {

                        }
                    }
                }

            }
        };

        counter = new Label("");
        buttons = new Button[6];
        buttons[0] = new Button("2");
        buttons[0].setOnAction(handler);
        buttons[1] = new Button("3");
        buttons[1].setOnAction(handler);
        buttons[2] = new Button("4");
        buttons[2].setOnAction(handler);
        buttons[3] = new Button("5");
        buttons[3].setOnAction(handler);
        buttons[4] = new Button("6");
        buttons[4].setOnAction(handler);
//        buttons[5] = new Button("Update");
//        buttons[5].setOnAction(handler);

        header.getChildren().addAll(counter, buttons[0], buttons[1], buttons[2], buttons[3], buttons[4]);

        rootLayout.setTop(header);
    }

    public static void main(String[] args) {
        launch();
    }
}