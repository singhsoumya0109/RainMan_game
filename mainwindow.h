#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QLabel>
#include "Raindrop.h"
#include "Umbrella.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void spawnRaindrop();
    void updateGame();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsView * view;
    Umbrella *umbrella;
    QList<Raindrop*> raindrops;
    QTimer *spawnTimer;
    QTimer *gameTimer;
    QLabel *scoreLabel; // To display the score
    int score; // Variable to track the score

    void endGame();
    void updateScore(int points); // Method to update the score
};

#endif // MAINWINDOW_H
